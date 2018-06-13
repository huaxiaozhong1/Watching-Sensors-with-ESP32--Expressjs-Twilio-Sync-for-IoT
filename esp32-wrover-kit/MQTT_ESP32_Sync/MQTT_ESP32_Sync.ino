/* License: MIT */

#include "WiFiClientSecure.h"
#include "certificates.hpp"
#include <PubSubClient.h>
#include <ArduinoJson.h>

#include <SimpleDHT.h>

/* LED Pin for your ESP32 */
#define LED_PIN 2

/* WiFi SSID and Password */
const char* ssid                        = "";
const char* password                    = "";

/*
 *  Sync Settings
 *
 *  Enter your document's unique name and a device name.
 */
const char* sync_document               = "sync/docs/dht11";
const char* sync_control                = "sync/docs/BoardLED";
const char* sync_device_name            = "ESP32_Dev_Board";

/* Sync server and MQTT setup; you probably don't have to change these. */
const char* mqtt_server                 = "mqtt-sync.us1.twilio.com";
const uint16_t mqtt_port                = 8883;
const uint16_t maxMQTTpackageSize       = 512;

WiFiClientSecure espClient;
PubSubClient client(mqtt_server, mqtt_port, espClient);


String input = "{\"temperature\":\"26\",\"humidity\":\"20\"}";

int pinDHT11 = 2;

SimpleDHT11 dht11;
byte temperature = 0;
byte humidity = 0;
int err = SimpleDHTErrSuccess;

long lastReconnectAttempt = 0;
long lastReadDHT11 = 0;
long lastSubscribe = 0;
String srv_cmd;
/*
 * Our Twilio Connected Devices message handling callback.  This is passed as a
 * callback function when we subscribe to the document, and any messages will
 * appear here.
 */
void callback(char* topic, byte* payload, unsigned int length)
{
  StaticJsonBuffer<maxMQTTpackageSize> cmdBuffer;
        
    std::unique_ptr<char []> msg(new char[length+1]());
    memcpy (msg.get(), payload, length);

    Serial.print("Message arrived on topic "); Serial.println(msg.get());

    JsonObject& cmdRoot = cmdBuffer.parseObject(msg.get());

    String command = cmdRoot["msg"];

    srv_cmd = command;

    Serial.println("srv's command:" + srv_cmd);

/*
        String led_command           = root["led"];

        if (led_command == "ON") {
                digitalWrite(LED_PIN, HIGH);
                Serial.println("LED turned on!");
        } else {
                digitalWrite(LED_PIN, LOW);
                Serial.println("LED turned off!");
        }
*/

  cmdBuffer.clear();
}


/*
 * This function connects to Sync via MQTT. We connect using the certificates and
 * device name defined as constants above, and immediately check the server's
 * certificate fingerprint.
 *
 * If everything works, we subscribe to the document topic and return.
 */
boolean connect_mqtt()
{
 Serial.println("\nAttempting to connect to Twilio Sync...");

 if(client.connect("1001", "roger", "password")) {
  Serial.println("Connected with connection: " + client.state());
   Serial.print("Connected!  Subscribing to "); Serial.println(sync_control);
   client.setCallback(callback);
   client.subscribe(sync_control);
   return client.connected();
 }else{
  Serial.println("Failure with connection: " + client.state());
 }

}


/* In setup, we configure our LED for output, turn it off, and connect to WiFi */
void setup()
{
        Serial.begin(115200);
        WiFi.begin(ssid, password);

        pinMode(LED_PIN, OUTPUT);
        digitalWrite(LED_PIN, LOW);

        while (WiFi.status() != WL_CONNECTED) {
                delay(1000);
                Serial.print(".");
        }

        randomSeed(micros());
        Serial.print("\nWiFi connected!  IP address: ");
        Serial.println(WiFi.localIP());

        // Set the root CA (to validate you are talking to Twilio) and the client key and cert
        
        espClient.setCACert(root_cert);
        espClient.setCertificate(client_cert);
        espClient.setPrivateKey(client_key);
        
}


/* Our loop constantly checks we are still connected.  On disconnects we try again. */
void loop()
{
  StaticJsonBuffer<maxMQTTpackageSize> dataBuffer;
  
  if(!client.connected()){
    long now = millis();
    if((now - lastReconnectAttempt) > 5000){    // try to connect srv in every 5 seconds.
      lastReconnectAttempt = now;
      if(connect_mqtt()){                     // the actual function to connect.
        lastReconnectAttempt = 0;
      }
    }
  }
  else{    // if connected.
    long dht11_now = millis();    // get the current seconds, to see if reading.

    if((dht11_now -lastReadDHT11) > 10000){    // read dht11 every 10 seconds.
      lastReadDHT11 = dht11_now;

      if((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) == SimpleDHTErrSuccess){

        Serial.print("Sample OK: ");
        Serial.print((int)temperature); Serial.print(" *C, ");
        Serial.print((int)humidity); Serial.println(" H");

//        lastReadDHT11 = 0;        // if succeed in reading of dht11.

        JsonObject& dataRoot = dataBuffer.parseObject(input);

        long Temperature = dataRoot[String("temperature")];
        Temperature = (long) temperature;
        dataRoot[String("temperature")] = Temperature;

        long Humidity = dataRoot[String("humidity")];
        Humidity = (long) humidity;
        dataRoot[String("humidity")] = Humidity;

        String output;
        dataRoot.printTo(output);

        char payload[512];

        strcpy(payload, output.c_str());

        long subscribe_now = millis();
        if((subscribe_now - lastSubscribe) > 12000){    // subscribe every 12 secs, according to update-rate at "server-api-mode" side.

        Serial.print("data publish time: ");
        Serial.print((long)subscribe_now); Serial.print(", ");
        Serial.print((long)lastSubscribe); Serial.println(". ");

          lastSubscribe = subscribe_now;

          if(srv_cmd == "pause"){
            client.disconnect();
            srv_cmd = "no";
          }
          else{
              if((client.publish(
                sync_document,
//                "{\"temperature\":\"26\",\"humidity\":\"20\"}"))==true){        // if success.
                 payload))==true){        // if success.
                 Serial.println("Succeed in sending T & H to Twilio.");
                for(int i=0; i<64; i++){
                  Serial.printf("%x ", payload[i]);
                }
                Serial.println();
              }else{
                Serial.println("Failure with publish: " + client.state());
              }
          }
        dataBuffer.clear();
        }
      }
    }
  }

  client.loop();    // handle msg sent from srv right after checking srv connection and reading dht11.

}    // end of function of "loop".
