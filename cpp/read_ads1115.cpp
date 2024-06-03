/*
 * example reads single adc input and prints value
 *
 * build:
 * > make
 *
  * run:
 * > ./read_ads115
 *
 * read_ads1115.cpp
 *
 */

#include <stdio.h>

#include "ads1115_lib.h"

#define PORT 1

int main()
{
    double value;

    bool ret = ads1115::read(
        PORT,
        ads1115::ADR_48,
        ads1115::MUX_I0_GND,
        ads1115::GAIN_4096,
        ads1115::RATE_128,
        false,
        value);

    if (ret)
        printf("%.0fmV\n", value);
    else
        printf("%s\n", ads1115::error_text());

    return 0;
}


