# Send DHT11 sensor data using The Things Uno and The Things Network to IOTA Tangle using Masked Authenticated Messaging (MAM)

This is a tutorial how to send DHT11 sensor data using The Things Uno and The Things Network to IOTA Tangle using Masked Authenticated Messaging (MAM).

## Requirements

All hardware requirements and how to wire the DHT11 sensor module to The Things Uno is explained in:  
[https://www.mobilefish.com/developer/iota/iota\_quickguide\_ttn\_mam.html][1]

![alt text](https://www.mobilefish.com/images/developer/things_uno_dht11.jpg "DHT11 sensor connected to The Things Uno")

## Documents

More information about The Things Network, The Things Gateway and The Things Uno:  
[https://www.thethingsnetwork.org][2]<br/>
[https://www.thethingsnetwork.org/docs/gateways/gateway][3]<br/>
[https://www.thethingsnetwork.org/docs/devices/uno][4]<br/>


## Features

The project consists of one Arduino sketch and 3 NodeJS files.<br/>
The most important files are:<br/>

- dht11.ino: This sketch is uploaded to the The Things Uno which reads the DHT11 sensor data and sends it to a LoRa Gateway (e.g. The Things Gateway). If the Gateway is connected to The Things Network server, this data can be seen in The Things Network console.

- dht\_ttn.js: This NodeJS file reads the DHT11 sensor data from The Things Network server.

- dht\_ttn\_mam.js: This NodeJS file reads the DHT11 sensor data from The Things Network server. This data is processed and published to the Tangle using MAM.

- mam\_receive.js: Extract the stored data from the Tangle using MAM and display the data.

## Installation

```
npm install
```

## Usage

How to use the scripts see:
[https://www.mobilefish.com/developer/iota/iota\_quickguide\_ttn\_mam.html][1]


[1]: https://www.mobilefish.com/developer/iota/iota_quickguide_ttn_mam.html "Mobilefish.com"
[2]: https://www.thethingsnetwork.org/ "The Things Network"
[3]: https://www.thethingsnetwork.org/docs/gateways/gateway "The Things Gateway"
[4]: https://www.thethingsnetwork.org/docs/devices/uno "The Things Uno"
