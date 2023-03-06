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

class InputV{
    public:

    InputV(int gpio,int adc){
        stdio_init_all();
        adc_init();

        adc_gpio_init(gpio);
        adc_select_input(adc);
    }

    void readVoltage(){
        // 12-bit conversion, assume max value == ADC_VREF == 3.3 V
        const float conversion_factor = 3.3f / (1<<12);
        uint16_t result_at_VB = adc_read();
        // 11 is from the voltage divide formula.
        printf("Raw value: 0x%03x, voltage: %f V\n", result_at_VB, result_at_VB * conversion_factor * 11);
    }
};

int main(){
    InputV input(gpio, adc);
    while(1)
    {
        input.readVoltage();
        sleep_ms(500);
    }
}