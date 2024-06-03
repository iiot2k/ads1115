// example reads multiply adc inputs promised
// run:
// > node read_multi_promise.js

"use strict";

const adc = require("../ads1115");

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
        console.log(adc.error_text());
    });
})();
