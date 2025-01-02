// example reads single adc input
// run:
// > node read.js

"use strict";

const PORT = 1; // i2c-1
const RAWDATA = false;

const adc = require("../ads1115");

adc.read(
    PORT,
    adc.ADR_48, // address 0x48
    adc.MUX_I0_GND, // AIN0 - GND
    adc.GAIN_4096, // 4096 mV
    adc.RATE_128, // 128 SPS
    RAWDATA, // rawdata ?
    function(data) {
        if (data === undefined)
            console.log(adc.error_text());
        else
            console.log(data, "mV");
    });
