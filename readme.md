# Project to demo cloud-iot
The major technical components and platfomrs that the project requires are: Twilio-Sync, Audiuno, dht11 temperature/humidity sensor and ESP32 (reference board: esp-wrover-kit), Node.js, Express and Chart.js. As the result of project, you could get any information updated by an iot device (temperature/humidity sensor at your home, for example) from a browser client running at cell-phone, laptop... anywhere.

## Setup & Run

### To run web app

* git clone https://github.com/huaxiaozhong1/twilio-sync-esp32-wrover-kit-express-chartjs-demo.git

* cd twilio-sync-esp32-wrover-kit-express-chartjs-demo

* sudo npm install --save

* Apply for account information from Twilio-Sync, fill them into .env. There are 3 parameters: accountSid, authToken, serviceSid. 

* npm start

* Open a browser client, type: http://localhost:3000. You will see a chart, which updates, every minute, to display temperature and humidity values. These values are collected from a remote place that the sensor is put at.
* Delete the Sync doc: http://localhost:3000/delete-document
* Create the Sync doc again: http://localhost:3000/create-document



### To run esp-wrover-kit board and dht11 sensor

* Connect the sensor to esp-wrover-kit board, then connect the board to a 5V power.
* If you want to flash the board, connect it to laptop through a USB cable. The best, both board and laptop are connected to a active USB hub.
* Install Audiuno. Open Audiuno IDE, select "Board" as "ESP Dev Module". 
* cd twilio-sync-esp32-wrover-kit-express-chartjs-demo/esp32-wrover-kit/MQTT_ESP32_Sync, edit MQTT_ESP32_Sync.ino, fill out "ssid" and "password" for "wifi" into the file. 
* On Audiuno IDE, select "Sketch -> Verify & Compile", then "Sketch -> Upload" to flash the new sketch into esp-wrover-kit board. 
* Power the board again.


### Notes
- The current project is just a "very beginning" version for review. More detailed "readme" is coming. And some known issues are traced internally. 
