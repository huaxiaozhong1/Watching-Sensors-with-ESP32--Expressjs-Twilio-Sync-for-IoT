# Project to demo cloud-iot
The major technical components and platforms that the project requires are: Twilio-Sync, Audiuno, dht11 temperature/humidity sensor and ESP32 (reference board: esp-wrover-kit), Node.js, Express and Chart.js. As the result of project, from a browser client running at cell-phone, laptop, ... you could get/send information from/to an iot device.
Twilio provides 2 individual API sets that run for Express.js environment. One is designed to run at web server side, which is called as "Twilio Sync Rest API" (https://www.twilio.com/docs/sync/api). The other is to run at web client side, which is called as "Twilio Sync JavaScript client library" (https://media.twiliocdn.com/sdk/js/sync/releases/0.8.1/docs/). The project demos both modes that are quite different from each other. You could know how to implement the 2 modes and may understand when to use which :-)

## Setup & Run

### To run web app with "server-api-mode"

* git clone https://github.com/huaxiaozhong1/Watching-Sensors-with-ESP32--Expressjs-Twilio-Sync-for-IoT.git

* cd twilio-sync-esp32-wrover-kit-express-chartjs-demo

* sudo npm install --save

* Apply for account information from Twilio-Sync, fill them into .env. There are 3 parameters: accountSid, authToken, serviceSid. Fill the paremeters into .env at the folder.

* npm start

* Open a browser client, type: http://localhost:3000. You will see a chart, which updates, every 3 seconds, to display temperature and humidity values. These values are collected from a remote place that the sensor is linked to wifi.

* When running, the screen-shot is as: ["server-api-mode"](web-app-srv-api-mode-180621.png)

### To run web app with "client-api-mode"

* At the folder twilio-sync-esp32-wrover-kit-express-chartjs-demo, cd client-api-modes

* Apply for account information from Twilio-Sync, fill them into .env. There are 4 parameters: TWILIO_ACCOUNT_SID, TWILIO_API_KEY, TWILIO_API_SECRET and TWILIO_SYNC_SERVICE_SID. Fill the parameters into .env at the folder.

* npm start

* Open 1 more browser client, type: http://localhost:3001. You will see a chart, which displays temperature and humidity values as soon as cloud receives the values updated by sensor. The chart can be updated every 3 seconds if the internet connection won't be too slow :-)

* The screen-shot is as: ["client-api-mode"](web-app-cli-mode-180622.png)

### To run esp-wrover-kit board and dht11 sensor

* Connect the sensor to esp-wrover-kit board, then connect the board to a 5V power.

* If you want to flash the board, connect it to laptop through a USB cable. The best, both board and laptop are connected to a active USB hub.

* Install Audiuno. Open Audiuno IDE, select "Board" as "ESP Dev Module".

* cd twilio-sync-esp32-wrover-kit-express-chartjs-demo/esp32-wrover-kit/MQTT_ESP32_Sync, edit MQTT_ESP32_Sync.ino, fill out "ssid" and "password" for "wifi" into the file.

* Apply for certificate for your device. Fill out 3 parameters into certificates.hpp at the same folder of MQTT_ESP32_Sync.ino. The 3 parameters are: root_cert, client_key and client_cert.

* On Audiuno IDE, select "Sketch -> Verify & Compile", then "Sketch -> Upload" to flash the new sketch into esp-wrover-kit board.

* Power the board again.

* The photo linking DHT11, esp-wrover-kit and laptop is as: [sensor-esp-others](sensor-esp-180613.png)

### Send command from web app to sensor

* Open another new browser client, type: http://localhost:3000/pause-sensor. You will see a sentence on browser saying:
  "Sensor at your home is paused... "

* If you open debug-port of esp-wrover-kit at your laptop, you could see corresponding information output as: [command from web app](Screenshot-sensor-receives-web-command-180613.png)
