/*
Source file for Input Voltage module of the thruster interface board.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/

#include "../include/global.h"
#include "../include/mcu_thruster.h"
#include "../include/pi_interface.h"
#include "../include/input_voltage_sense.h"

int main(){
    InputVoltageSensor input(gpio, adc);
    Motor J3_servo1(24, 0);
    Motor J3_servo2(13, 0);
    Motor J4_servo1(18, 0);
    Motor J4_servo2(16, 0);
    PiInterface rs232(UART_ID,BAUD_RATE,UART_TX_PIN, UART_RX_PIN);

    while(1)
    {   
        //PiInterface
        rs232.PutString(INSTRUCTION);
        
        //Voltage Reader
        input.ReadVoltage();
        sleep_ms(10);

        for (int i = 0; i<5; i++){
            char data = rs232.ReadChar();
            printf("\r\n%c\r\n",data);
            sleep_ms(10);
        }


        //Servo
        J3_servo1.Sweep();
        // printf("goodbye\n");
        J3_servo2.Sweep();
        // printf("here1\n");
        J4_servo1.Sweep();
        J4_servo2.Sweep();
    }
}