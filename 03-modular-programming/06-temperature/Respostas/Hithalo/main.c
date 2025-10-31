#include <stdio.h>
#include <stdlib.h>
#include "temperature_conversor.h"

int main(void) {
    float temp;
    char curr_unit, goal_unit;
    scanf("%f %c %c", &temp, &curr_unit, &goal_unit);

    float temp_c;
    switch (curr_unit) {
        case 'c': {
            temp_c = temp;
            break;
        }
        case 'k': {
            temp_c = convert_temperature(temp, convert_kelvin_to_celsius);
            break;
        }
        case 'f': {
            temp_c = convert_temperature(temp, convert_fahrenheit_to_celsius);
            break;
        }
        default: {
            break;
        }
    }

    switch (goal_unit) {
        case 'c': {
            printf("Temperature: %.2fCº\n", temp_c);
            break;
        }
        case 'k': {
            printf("Temperature: %.2fK\n",
                   convert_temperature(temp_c, convert_celsius_to_kelvin));
            break;
        }
        case 'f': {
            printf("Temperature: %.2fFº\n",
                   convert_temperature(temp_c, convert_celsius_to_fahrenheit));
            break;
        }
        default: {
            break;
        }
    }

    return EXIT_SUCCESS;
}
