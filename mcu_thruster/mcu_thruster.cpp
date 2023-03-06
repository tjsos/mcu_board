/*
Source file for MCU board PWM.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "mcu_thruster.h"

/* Motor Class. Initializes with the output pin and the type of motor*/
class Motor{
    public:
        //0 for Servo, 1 for thruster.
        int motortype;

        //For Sweep
        bool direction = true;

        //Constructor
        Motor(int motorPin, int motortype){
            this->motortype = motortype;
            gpio_set_function(motorPin, GPIO_FUNC_PWM);

            uint slice = pwm_gpio_to_slice_num(motorPin);

            pwm_config config = pwm_get_default_config();
            pwm_config_set_clkdiv(&config, clk_div);
            pwm_config_set_wrap(&config, wrap_value);

            pwm_init(slice, &config, true);
        }

        void setCommand(int motorPin, int command){
            if (this->motortype == 0){
                float millis = map(command, in_min, in_max, out_min_servo, out_max_servo);
                pwm_set_gpio_level(motorPin, (millis/time_period)*wrap_value);
                sleep_ms(10);
            }
            else if (this->motortype == 1){
                float millis = map(command, in_min, in_max, out_min_thruster, out_max_thruster);
                pwm_set_gpio_level(motorPin, (millis/time_period)*wrap_value);
                sleep_ms(10);
            }
        }
        
        float map(long x, long in_min, long in_max, long out_min, long out_max){
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }

        void sweep(){
            if (this->motortype == 0){
                command += (direction)?1:-1;
                if(command >= 100) direction = false;
                if(command <= -100) direction = true;
                setCommand(OUTPUT_PIN, command);
            }    
        }
};

int main(){
    Motor servo(OUTPUT_PIN, 0);
    while(1)
    {
        // servo.setCommand(OUTPUT_PIN, command);

        servo.sweep();
    }
}