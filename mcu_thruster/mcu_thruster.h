/* Header for MCU board.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/
#define OUTPUT_PIN 20 //6B //J3

int command = 50;
/////Global Variables
//Clock divider value
float clk_div = 64.f;

//Wrap value
float wrap_value = 39062.f;

//Time Period
float time_period = 20000.f;

/////Functions
//MINMAX for input
long in_min = -100;
long in_max = 100;

//MINMAX for Servo
long out_min_servo = 400;
long out_max_servo = 2400;

//MINMAX for thruster
long out_min_thruster = 1000;
long out_max_thruster = 2000;