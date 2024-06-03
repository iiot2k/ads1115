/*
 * example reads single adc input on interval and prints value
 *
 * build:
 * > make
 *
  * run:
 * > ./read_loop_ads115
 *
 * read_loop_ads1115.cpp
 */

#include <stdio.h>
#include <csignal>

#include "ads1115_lib.h"

#define PORT 1
#define LOOP_MS 2000

int32_t interval_id = -1;

// signal handler
void onCtrlC(int signum)
{
	// stop any adc conversion
	ads1115::stop_convert(PORT);

	// stop interval
	ads1115::clear_interval(interval_id);
}

void interval_callback()
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
    {
        printf("%s\n", ads1115::error_text());

        // stop interval
        ads1115::clear_interval(interval_id);
    }
}

int main()
{
    signal(SIGINT, onCtrlC);

    puts("stop program with Ctrl+C");

    // start interval
    ads1115::set_interval(interval_callback, LOOP_MS, &interval_id);

    puts("\nprogram stopped");

    return 0;
}


