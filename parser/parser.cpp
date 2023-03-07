/* Source for RS232 Parser of the thruster interface board.
SOSLAB
Author : Tony Jacob, tony.jacob@uri.edu
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "parser.h"

int main(){
    PiInterface rs232(UART_ID,BAUD_RATE,UART_TX_PIN, UART_RX_PIN);
    
    while(1){
        rs232.put_string(INSTRUCTION);
        for (int i = 0; i<5; i++){
            char data = rs232.read_char();
            printf("\r\n%c\r\n",data);
            sleep_ms(500);
        }
    }
}