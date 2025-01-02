// example reads single adc input from temperature sensor TC1047 (Microchip) and prints scaled value
// run:
// > node scale.js

"use strict";

const PORT = 1; // i2c-1
const RAWDATA = false;

const SCALE_IN_MIN = 100  // mV
const SCALE_IN_MAX = 1750 // mV
const SCALE_OUT_MIN = -40 // °C
const SCALE_OUT_MAX = 125 // °C
const CLAMP = true;

const adc = require("../ads1115");

adc.read(
    PORT, 
    adc.ADR_48, // address 0x48
    adc.MUX_I0_GND, // AIN0 - GND
    adc.GAIN_2048, // 2048 mV
    adc.RATE_128, // 128 SPS
    RAWDATA, // rawdata ?
    function(data) {
        if (data === undefined)
            console.log(adc.error_text());
        else {
            console.log(data, "mV");

            data = adc.scale(
                SCALE_IN_MIN,
                SCALE_IN_MAX,
                SCALE_OUT_MIN,
                SCALE_OUT_MAX,
                data,
                CLAMP); // clamp value ?

            if (data === undefined)
                console.log(adc.error_text());
            else
                console.log(data.toFixed(1), "°C");
        }
    });
