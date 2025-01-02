# @iiot2k/ads1115

[![platform](https://img.shields.io/badge/platform-Raspberry--Pi-ff69b4)](https://www.raspberrypi.com/)

ads1115 analog to digital converter library

<a href="https://www.buymeacoffee.com/iiot2ka" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-blue.png" height="41" width="174"></a><br>
If you like my work and find it helpful, please support me.

## Installation
This library works only on Raspberry Pi with 64bit OS.<br>
*32bit OS is no longer supported.*<br>

```
npm install @iiot2k/ads1115
```

or add in your ```package.json```:

```json
"dependencies": {
    "@iiot2k/ads1115": "latest"
},
```

[View on npm](https://www.npmjs.com/package/@iiot2k/ads1115)📌<br>
[View on GitHub](https://github.com/iiot2k/ads1115)📌<br>
[Report any issues here](https://github.com/iiot2k/ads1115/issues)📌

## [ads1115](https://www.ti.com/product/ADS1115)📌 16bit analog to digital converter
- 16bit Conversion Resolution.
- Four Analog Inputs.
- Each input can be selected Single-Ended, Differential.
- Internal Voltage Reference.
- Internal Oscillator.
- Programmable Data Rate 8 SPS to 860 SPS.
- The PGA offers input ranges from ±256 mV to ±6144 mV.
- I2C Interface with four pin-selectable addresses.

## Usage
- The output value is mV or adc raw data.
- Enable I2C with raspi-config.
- In this case i2c-1 is enabled (port=1).
- If you use i2c-0 port add<br>
  ```dtparam=i2c_vc=on```<br>
  to *config.txt*,<br>
  then Pin27=SDA, Pin28=SCK.<br>
- For other ports add this to *config.txt*.
- The default i2c speed is 100kHz, to speed up add/change this line in *config.txt*:<br>
```dtparam=i2c_arm=on,i2c_arm_baudrate=400000```

## Address Pin Connection

|I2C Address|ADDR Pin|
|:----|:---|
|48H|GND or open|
|49H|VCC|
|4AH|SDA|
|4BH|SCL|

## Node.js API
Node.js API functions are explained in document **API.md**<br>
Node.js examples are on **examples** folder.<br>

## C++ API
This library uses C++ addon modules as interface to hardware.<br>
Therefore, there is also a C++ interface to the drivers.<br>

Some C++ examples are in the **cpp** directory.<br>
The C++ API functions are described in the header file **ads1115_lib.h**



