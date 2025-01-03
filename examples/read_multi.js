// example reads multiple adc inputs
// run:
// > node read_multi.js

"use strict";

const PORT = 1; // i2c-1
const RAWDATA = false;

const adc = require("../ads1115");

var mux_arr = [adc.MUX_I0_GND, adc.MUX_I1_GND, adc.MUX_I2_GND, adc.MUX_I3_GND]; 

adc.read_multi(
    PORT,
    adc.ADR_48, // address 0x48
    mux_arr,
    adc.GAIN_4096, // 4096mV
    adc.RATE_128, // 128 SPS
    RAWDATA, // raw data ?
    function(data) {
        if (data === undefined)
            console.log(adc.error_text());
        else
            console.log(data, "mV");
    });
