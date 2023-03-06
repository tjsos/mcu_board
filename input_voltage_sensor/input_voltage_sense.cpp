/*
Source file for Input Voltage module of the thruster interface board.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"
#include "input_voltage_sense.h"

int main(){
    InputV input(gpio, adc);
    while(1)
    {
        input.readVoltage();
        sleep_ms(500);
    }
}