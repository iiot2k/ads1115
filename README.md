# @iiot2k/ads1115

[![platform](https://img.shields.io/badge/platform-Raspberry--Pi-ff69b4)](https://www.raspberrypi.com/)

ads1115 analog to digital converter library

<a href="https://www.buymeacoffee.com/iiot2ka" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/default-red.png" height="41" width="174"></a><br>
Developing software is a hard job. Thanks for the coffee !! 😁

## Installation
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
- This library works on Raspberry Pi with 32bit or 64bit OS.
- The output value is mV or adc raw data.
- Enable I2C with raspi-config.
- In this case i2c-1 is enabled (port=1).
- If you use i2c-0 port add<br>
  **dtparam=i2c_vc=on**<br>
  to /boot/config.txt,<br>
  then Pin27=SDA, Pin28=SCK.<br>
- For other ports add this to /boot/config.txt.

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

```javascript
// example reads single adc input
"use strict";

const ads1115 = require("@iiot2k/ads1115");

ads1115.read(
    1, // i2c-1
    ads1115.ADR_48, // address 0x48
    ads1115.MUX_I0_GND, // AIN0 - GND
    ads1115.GAIN_4096, // 4096 mV
    ads1115.RATE_128, // 128 SPS
    false, // no rawdata
    function(data) {
        if (data === undefined)
            console.log(ads1115.error_text());
        else
            console.log(data, "mV");
    });
```

## C++ API
This library uses C++ addon modules as interface to hardware.<br>
Therefore, there is also a C++ interface to the drivers.<br>
Unfortunately the C++ addon modules are not open source.<br>
I provide the C++ static link libraries.<br>
But if you are interested in the sources, I can send them to you.<br>
Please send me an email with your name to iiot2k@gmail.com <br>
I can only provide limited support for the C++ addon modules sources.<br>

I have shown some C++ examples in the **cpp** directory and on [GitHub](https://github.com/iiot2k/ads1115/tree/main/cpp)📌<br>
The C++ API functions are described in the header file **ads1115_lib.h**

```C++
// example reads single adc input

#include <stdio.h>

#include "ads1115_lib.h"

#define PORT 1 // i2c-1

int main()
{
    double value;

    bool ret = ads1115::read(
        PORT,
        ads1115::ADR_48, // address 0x48
        ads1115::MUX_I0_GND, // AIN0 - GND
        ads1115::GAIN_4096, // 4096 mV
        ads1115::RATE_128, // 128 SPS
        false, // no rawdata
        value);

    if (ret)
        printf("%.0fmV\n", value);
    else
        printf("%s\n", ads1115::error_text());

    return 0;
}
```


