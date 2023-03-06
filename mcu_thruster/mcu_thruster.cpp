/*
Source file for MCU board PWM.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "mcu_thruster.h"

int main(){
    Motor servo(OUTPUT_PIN, 0);
    while(1)
    {
        // servo.setCommand(OUTPUT_PIN, command);

        servo.sweep();
    }
}