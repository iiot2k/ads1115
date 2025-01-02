# API @iiot2k/ads1115
ads1115 analog to digital converter library

The driver is loaded on call with ```require("@iiot2k/ads1115");```<br>
On 64bit OS the driver ***ads1115_arm64.node*** is loaded.<br>

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
|RATE_32|2|32 SPS|31.25ms|
|RATE_64|3|64 SPS|15.625ms|
|RATE_128|4|128 SPS|7.81ms|
|RATE_250|5|250 SPS|4ms|
|RATE_475|6|475 SPS|2ms|
|RATE_860|7|860 SPS|1ms|

## Version function
```version()```<br>
***return:*** ```<string>``` version of addon.<br>

## Error function
```error_text()```<br>
***return:*** ```<string>``` error text after call function.<br>

## Scale function
```scale(in_min, in_max, out_min, out_max, value)```<br>
- ***in_min:*** ```<number>``` scale input min value<br>
- ***in_max:*** ```<number>``` scale input max value<br>
- ***out_min:*** ```<number>``` scale output min value<br>
- ***out_max:*** ```<number>``` scale output max value<br>
- ***value:*** ```<number>``` value to scale<br>
- ***clamp:*** ```<boolean>``` if true clamp value to in_min and in_max.<br>
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
