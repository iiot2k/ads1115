# API @iiot2k/ads1115
ads1115 analog to digital converter library

The driver is loaded on call with ```require("@iiot2k/ads1115");```<br>
On 64bit OS the driver ***ads1115_arm64.node*** is loaded.<br>
On 32bit OS the driver ***ads1115_arm32.node*** is loaded.<br>

## Port Parameter
The ```port``` parameter specifies the i2c port number.<br>
For example port 1 is the port address **i2c-1**.<br>
Port addresses 0 to 9 are possible.<br>

## Address Parameter
The ```address``` parameter selects the chip i2c address.<br> 
|Constant|Value|Address (Hex)|
|:--|:--|:--|
|ADR_48|0|0x48|
|ADR_49|1|0x49|
|ADR_4A|2|0x4A|
|ADR_4B|3|0x4B|

## Mux Parameter
The ```mux``` (multiplex) parameter selects the connection of the inputs to be measured.<br>
This makes single-ended or differential measurement possible.<br>
Single ended measurements always deliver positive values.<br>
|Constant|Value|Connection|Measurement|
|:--|:--|:--|:--|
|MUX_I0_I1|0|AIN0 - AIN1|differential|
|MUX_I0_I3|1|AIN0 - AIN3|differential|
|MUX_I1_I3|2|AIN1 - AIN3|differential|
|MUX_I2_I3|3|AIN2 - AIN3|differential|
|MUX_I0_GND|4|AIN0 - GND|single-ended|
|MUX_I1_GND|5|AIN1 - GND|single-ended|
|MUX_I2_GND|6|AIN2 - GND|single-ended|
|MUX_I3_GND|7|AIN3 - GND|single-ended|
|MUX_DISABLE|8|DISABLE INPUT|no measurement|

## Gain Parameter
The ```gain``` parameter determines the maximum input voltage.<br>
|Constant|Value|Max. Input Voltage|
|:--|:--|:--|
|GAIN_6144|0|6144 mV|
|GAIN_4096|1|4096 mV|
|GAIN_2048|2|2048 mV|
|GAIN_1024|3|1024 mV|
|GAIN_512|4|512 mV|
|GAIN_256|5|256 mV|

## Rate Parameter
The ```rate``` parameter determines the conversion data rate in samples per second (SPS).<br>
|Constant|Value|Rate|Conversion Time|
|:--|:--|:--|:--|
|RATE_8|0|8 SPS|125ms|
|RATE_16|1|16 SPS|62.5ms|
|RATE_23|2|32 SPS|31.25ms|
|RATE_64|3|64 SPS|15.625ms|
|RATE_128|4|128 SPS|7.81ms|
|RATE_250|5|250 SPS|4ms|
|RATE_475|6|475 SPS|2ms|
|RATE_860|7|860 SPS|1ms|

## Error function
```error_text()```<br>
***return:*** ```<string>``` error text after call function.<br>

> ## Stop convert function
```stop_convert(port)```
- ***port:*** ```<integer>``` 0..9<br>

Stops any adc convert operation on port.<br>

> ## Scale adc value
```scale_adc(mux, gain, out_min, out_max, value)```<br>
- ***mux:*** ```<integer>``` MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***out_min:*** ```<number>``` scale output min value<br>
- ***out_max:*** ```<number>``` scale output max value<br>
- ***value:*** ```<number>``` value to scale<br>
***return:*** ```<number>``` scaled value, ```undefined``` on error.<br>

Scale adc value from adc parameter.<br>
out_min must be different to out_max.<br>

```scale(in_min, in_max, out_min, out_max, value)```<br>
- ***in_min:*** ```<number>``` scale input min value<br>
- ***in_max:*** ```<number>``` scale input max value<br>
- ***out_min:*** ```<number>``` scale output min value<br>
- ***out_max:*** ```<number>``` scale output max value<br>
- ***value:*** ```<number>``` value to scale<br>
***return:*** ```<number>``` scaled value, ```undefined``` on error.<br>

Scale adc value from given edges.<br>
in_min must be different to in_max.<br>
out_min must be different to out_max.<br>

## Read functions with callback

> ### Reads single adc input (callback)<br>
```read(port, address, mux, gain, rate, rawdata, callback)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer>``` MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***callback:*** ```<function>```<br>
    - ```data``` ```<number>``` conversion value, ```undefined``` on error.<br>

> ### Reads multiple adc inputs (callback)<br>
```read_multi(port, address, mux, gain, rate, rawdata, callback)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer array>``` array of MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***callback:*** ```<function>```<br>
    - ```data``` ```<number array>``` conversion values array, ```undefined``` on error.<br>

The mux array size must be greater than zero.

## Read functions with return promise

> ### Reads single adc input (promise)<br>
```read_promise(port, address, mux, gain, rate, rawdata)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer>``` MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***return:*** ```<promise>```<br>
    - ***Resolve*** ```(data)``` ```<number>``` conversion value
    - ***Reject*** ```()``` on error

> ### Reads multiple adc inputs (promise)<br>
```read_multi_promise(port, address, mux, gain, rate, rawdata)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer array>``` array of MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***return:*** ```<promise>```<br>
    - ***Resolve*** ```(data)``` ```<number array>``` conversion value array
    - ***Reject*** ```()``` on error

The mux array size must be greater than zero.

## Read Synchron functions

> ### Reads single adc input (synchron)<br>
```read_sync(port, address, mux, gain, rate, rawdata)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer>``` MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***return:*** ```<number>```, ```<undefined>``` on error.<br>

> ### Reads multiple adc inputs (synchron)<br>
```read_multi_sync(port, address, mux, gain, rate, rawdata)```<br>
- ***port:*** ```<integer>``` 0..9<br>
- ***address:*** ```<integer>``` ADR_..<br>
- ***mux:*** ```<integer array>``` array of MUX_..<br>
- ***gain:*** ```<integer>``` GAIN_..<br>
- ***rate:*** ```<integer>``` RATE_..<br>
- ***rawdata:*** ```<boolean>``` if ```false``` result is in mV, if ```true``` result is in adc raw data.<br>
- ***return:*** ```<number array>```, ```<undefined>``` on error.<br>

The mux array size must be greater than zero.

## Examples with callback
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

```javascript
// example reads multiple adc inputs
"use strict";

const adc = require("@iiot2k/ads1115");

var mux_arr = [adc.MUX_I0_GND, adc.MUX_I1_GND, adc.MUX_I2_GND, adc.MUX_I3_GND]; 

adc.read_multi(
    1, // i2c-1
    adc.ADR_48, // address 0x48
    mux_arr,
    adc.GAIN_4096, // 4096mV
    adc.RATE_128, // 128 SPS
    false, // no raw data
    function(data){
        if (data === undefined)
            console.log(ads1115.error_text());
        else
            console.log(data);
    });
```

## Examples with promise

```javascript
// example reads single adc input promised
"use strict";

const ads1115 = require("@iiot2k/ads1115");

(async () => {
    await ads1115.read_promise(
        1, // i2c-1
        ads1115.ADR_48, // address 0x48
        ads1115.MUX_I0_GND, // AIN0 - GND
        ads1115.GAIN_4096, // 4096 mV
        ads1115.RATE_128, // 128 SPS
        false, // no rawdata
    )
    .then((data) => {
        console.log(data, "mV");
    }).catch(() => {
        console.log(ads1115.error_text());
    });
})();
```

```javascript
// example reads multiply adc inputs promised
"use strict";

const adc = require("@iiot2k/ads1115");

var mux_arr = [adc.MUX_I0_GND, adc.MUX_I1_GND, adc.MUX_I2_GND, adc.MUX_I3_GND]; 

(async () => {
    await adc.read_multi_promise(
        1, // i2c-1
        adc.ADR_48, // address 0x48
        mux_arr,
        adc.GAIN_4096, // 4096 mV
        adc.RATE_128, // 128 SPS
        false, // no rawdata
    )
    .then((data) => {
        console.log(data, "mV");
    }).catch(() => {
        console.log(ads1115.error_text());
    });
})();
```
<div class="page"/>

## Examples with synchron call

```javascript
// example reads single adc input synchron
"use strict";

const ads1115 = require("@iiot2k/ads1115");

var data = ads1115.read_sync(
        1, // i2c-1
        ads1115.ADR_48, // address 0x48
        ads1115.MUX_I0_GND, // AIN0 - GND
        ads1115.GAIN_4096, // 4096 mV
        ads1115.RATE_128, // 128 SPS
        false, // no rawdata
    );

if (data === undefined)
    console.log(ads1115.error_text());
else
    console.log(data, "mV");
```

```javascript
// example reads multiply adc inputs synchron
"use strict";

const adc = require("@iiot2k/ads1115");

var mux_arr = [adc.MUX_I0_GND, adc.MUX_I1_GND, adc.MUX_I2_GND, adc.MUX_I3_GND]; 

var data = adc.read_multi_sync(
        1, // i2c-1
        adc.ADR_48, // address 0x48
        mux_arr,
        adc.GAIN_4096, // 4096 mV
        adc.RATE_128, // 128 SPS
        false, // no rawdata
    );

if (data === undefined)
    console.log(ads1115.error_text());
else
    console.log(data, "mV");
```

