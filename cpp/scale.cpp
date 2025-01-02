/*
 * example reads single adc input from temperature sensor TC1047 (Microchip) and prints scaled value
 *
 * program is without any error handling
 *
 * build:
 * > make
 *
  * run:
 * > ./scale
 *
 * scale.cpp
 *
 */

#include <cmath>
#include <stdio.h>

#include "ads1115_lib.h"

// adc parameter
#define PORT 1
#define RAWDATA false

// scale parameter
#define SCALE_IN_MIN 100.0  // mV
#define SCALE_IN_MAX 1750.0 // mV
#define SCALE_OUT_MIN -40.0 // °C
#define SCALE_OUT_MAX 125.0 // °C
#define CLAMP true

int main()
{
    double value;

    // read from adc
    bool ret = ads1115::read(
        PORT,
        ads1115::ADR_48,
        ads1115::MUX_I0_GND,
        ads1115::GAIN_2048,
        ads1115::RATE_128,
        RAWDATA,
        value);

    if (ret)
    {
        printf("%.0fmV\n", value);

        // scale adc value
        value = ads1115::scale(
            SCALE_IN_MIN,
            SCALE_IN_MAX,
            SCALE_OUT_MIN,
            SCALE_OUT_MAX,
            value,
            CLAMP); // clamp value

        if (std::isnan(value))
            printf("%s\n", ads1115::error_text());
        else
            printf("%.1f°C\n", value);
    }
    else
        printf("%s\n", ads1115::error_text());

    return 0;
}

