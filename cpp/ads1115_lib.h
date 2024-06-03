/*
 * C++ library for ads1115 analog to digital converter
 *
 * (c) Derya Y. iiot2k@gmail.com
 *
 * link libraries on build:
 * libads1115_arm32.a for 32bit OS
 * libads1115_arm64.a for 64bit OS
 *
 * ads1115_lib.h
 *
 */

#pragma once

#include <stdint.h>

namespace ads1115 {

/**
 * i2c address
 */
enum {
    ADR_48 = 0, // 0x48
    ADR_49,     // 0x49
    ADR_4A,     // 0x4A
    ADR_4B,     // 0x4B
};

/**
 * adc input selection
 */
enum {
    MUX_I0_I1 = 0, // AIN0 - AIN1
    MUX_I0_I3,     // AIN0 - AIN3
    MUX_I1_I3,     // AIN1 - AIN3
    MUX_I2_I3,     // AIN2 - AIN3
    MUX_I0_GND,    // AIN0 - GND
    MUX_I1_GND,    // AIN1 - GND
    MUX_I2_GND,    // AIN2 - GND
    MUX_I3_GND,    // AIN3 - GND
    MUX_DISABLE    // DISABLE INPUT (SKIP READ)
};

/**
 * adc input gain
 */
enum {
    GAIN_6144 = 0, // 6144 mV
    GAIN_4096,     // 4096 mV
    GAIN_2048,     // 2048 mV
    GAIN_1024,     // 1024 mV
    GAIN_512,      // 512 mV
    GAIN_256,      // 256 mV
};

/**
 * adc conversion rate
 */
enum {
    RATE_8 = 0, // 8 SPS, 125ms
    RATE_16,    // 16 SPS, 62.5ms
    RATE_23,    // 32 SPS, 31.25ms
    RATE_64,    // 64 SPS, 15.625ms
    RATE_128,   // 128 SPS, 7.81ms
    RATE_250,   // 250 SPS, 4ms
    RATE_475,   // 475 SPS, 2ms
    RATE_860,   // 860 SPS, 1ms
};

/**
 * @brief gets error text after call functions
 * @returns error text
 */
const char* error_text();

/**
 * @brief timeout callback function
 */
typedef void (*timeout_cb)();

/**
 * @brief calls callback function after timeout as thread (same as node.js setTimeout)
 * @param cb timeout callback function
 * @param timeout_ms timeout in ms
 * @param id storage of id used in clear_timeout()
 * @param wait if true waits until functions return, on false returns immediately
 */
void set_timeout(timeout_cb cb, uint32_t timeout_ms, int32_t* id = NULL, bool wait = true);

/**
 * @brief stops timeout
 * @param id - id returned by set_timeout
 */
void clear_timeout(int32_t id);

/**
 * @brief interval callback function
 */
typedef void (*interval_cb)();

/**
 * @brief calls callback function in interval as thread (same as node.js setInterval)
 * @param cb interval callback function
 * @param timeout_ms timeout in ms
 * @param id storage of id used in clear_interval()
 * @param wait if true waits until functions return, on false returns immediately
 */
void set_interval(timeout_cb cb, uint32_t timeout_ms, int32_t* id = NULL, bool wait = true);

/**
 * @brief stops interval
 * @param id returned by set_timeout
 */
void clear_interval(int32_t id);

/**
 * @brief stops any adc convert operation
 * @param port i2c port (0..9)
 */
void stop_convert(uint8_t port);

/**
 * @brief scale adc value from adc parameter
 * @param mux MUX_..
 * @param gain GAIN_..
 * @param out_min scale min value
 * @param out_max scale max value
 * @param value value from adc
 * @returns scaled value (NaN on error)
 * @note out_min must different to out_max
 */
double scale_adc(uint8_t mux, uint8_t gain, double out_min, double out_max, double value);

/**
 * @brief scale adc value from given edges
 * @param in_min input min value
 * @param in_max input max value
 * @param out_min scale min value
 * @param out_max scale max value
 * @param value value from adc
 * @returns scaled value (NaN on error)
 * @note in_min must different to in_max
 * @note out_min must different to out_max
 */
double scale(double in_min, double in_max, double out_min, double out_max, double value);

/**
 * @brief reads single ads1115 input
 * @param port i2c port (0..9)
 * @param adr i2c address (ADR_..)
 * @param mux MUX_..
 * @param gain GAIN_..
 * @param rate RATE_..
 * @param rawdata false: output mV, true: output adc raw data
 * @param value to read and store
 * @returns true: ok, false: error
 */
bool read(uint8_t port, uint8_t adr, uint8_t mux, uint8_t gain, uint8_t rate, bool rawdata, double &value);

} // namespace
