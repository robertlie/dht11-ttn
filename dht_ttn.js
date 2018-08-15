/*
Author: Robert Lie (mobilefish.com)

A DHT11 sensor module is connected to the Things Uno.
The sketch dht11.ino is uploaded to the Things Uno.
The dht_ttn.js file reads DHT11 sensor data (temperature and humidity) from the Things Network server and displays it on the console.

Usage:
1) Enter your appID and accessKey (see https://www.mobilefish.com/developer/iota/iota_quickguide_ttn_mam.html for more information)
2) Do not forget to type: npm install
3) Start the app: node dht_ttn.js

More information:
https://www.mobilefish.com/developer/iota/iota_quickguide_ttn_mam.html
https://www.thethingsnetwork.org/docs/devices/uno/
*/

const ttn = require('ttn');

const appID = "ENTER_YOUR_APP_ID_HERE";
const accessKey = "ENTER_YOUR_ACCESSKEY_HERE";

ttn.data(appID, accessKey)
    .then(function (client) {
        client.on("uplink", function (devID, payload) {
            console.log("Received uplink from ", devID)
            console.log(payload)
        })
    })
    .catch(function (error) {
        console.error("Error", error)
        process.exit(1)
    })
