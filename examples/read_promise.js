// example reads single adc input promised
// run:
// > node read_promise.js

"use strict";

const adc = require("../ads1115");

(async () => {
    await adc.read_promise(
        1, // i2c-1
        adc.ADR_48, // address 0x48
        adc.MUX_I0_GND, // AIN0 - GND
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
