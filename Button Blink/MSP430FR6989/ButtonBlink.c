/*
 * ButtonBlink.c
 *
 *  Created on: Sep 19, 2017
 *      Author: tomas
 */

#include<msp430fr6989.h>
int ButtonBlink(void){
        P1DIR = 0x01; //Set P1 Direction
        P1OUT = 0x02; //Set P1.1 hi
        P1REN = 0x02; //Set pullup resistor to P1.1
        P9DIR = 0x80; //Set P9 Direction
        P9OUT = 0x00; //Set P9.7 off

        while(1){
            if(P1IN & 0x02){    //Switch states of LEDs only button is pressed
                P1OUT = 0x02;
                P9OUT = 0x00;

            }
            else{
                P1OUT=0x03;     //Toggle LEDs
                P9OUT=0x80;
            }
        }
}

