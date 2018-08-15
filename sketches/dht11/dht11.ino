#include <DHT.h>
#include <DHT_U.h>

#include <TheThingsNetwork.h>

// Set your AppEUI and AppKey
const char *appEui = "ENTER_YOUR_APPEUI_HERE";
const char *appKey = "ENTER_YOUR_APPKEY_HERE";

#define loraSerial Serial1
#define debugSerial Serial

#define DHTPIN 2
// DHT11 or DHT22
#define DHTTYPE DHT11

// Replace REPLACE_ME with TTN_FP_EU868 or TTN_FP_US915
#define freqPlan REPLACE_ME

DHT dht(DHTPIN, DHTTYPE);

TheThingsNetwork ttn(loraSerial, debugSerial, freqPlan);

void setup() {
    loraSerial.begin(57600);
    debugSerial.begin(9600);

    // Wait a maximum of 10s for Serial Monitor
    while (!debugSerial && millis() < 10000)
    ;

    debugSerial.println("-- STATUS");
    ttn.showStatus();

    debugSerial.println("-- JOIN");
    ttn.join(appEui, appKey);

    dht.begin();
}

void loop() {
    debugSerial.println("-- LOOP");

    uint32_t humidity = dht.readHumidity(false) * 100;
    uint32_t temperature = dht.readTemperature(false) * 100;

    debugSerial.println("Humidity: " + String(humidity));
    debugSerial.println("Temperature: " + String(temperature));

    byte payload[4];
    payload[0] = highByte(humidity);
    payload[1] = lowByte(humidity);
    payload[2] = highByte(temperature);
    payload[3] = lowByte(temperature);

    ttn.sendBytes(payload, sizeof(payload));

    delay(10000);
}
