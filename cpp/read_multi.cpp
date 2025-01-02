/*
 * example reads single adc input and prints value
 *
 * build:
 * > make
 *
  * run:
 * > ./read_multi
 *
 * read_multi.cpp
 *
 */

#include <stdio.h>

#include "ads1115_lib.h"

#define PORT 1
#define RAWDATA false

uint8_t mux_arr[] = { ads1115::MUX_I0_GND, ads1115::MUX_I1_GND, ads1115::MUX_I2_GND, ads1115::MUX_I3_GND };

int main()
{
    double value;

    for(uint32_t i=0; i < 4; i++)
    {
        bool ret = ads1115::read(
            PORT,
            ads1115::ADR_48,
            mux_arr[i],
            ads1115::GAIN_4096,
            ads1115::RATE_128,
            RAWDATA,
            value);

        if (ret)
            printf("ch: %d %.0fmV\n", i, value);
        else
        {
            printf("%s\n", ads1115::error_text());
            break;
        }
    }

    return 0;
}


