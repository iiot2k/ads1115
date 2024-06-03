// example reads multiply adc inputs synchron
// run:
// > node read_multi_sync.js

"use strict";

const adc = require("../ads1115");

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
    console.log(adc.error_text());
else
    console.log(data, "mV");
