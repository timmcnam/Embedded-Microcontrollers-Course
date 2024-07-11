#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
/*********************************************************************************
Commented Header
Author: Timothy McNamara
Date: 10/04/2023
Class: ECET 20900 Fall 2023
Section: Thursday Lab
Assignment: Lab 06 Intro to C switches
Due Date; 10/04/2023
Description: provide a brief description of the program. Make sure your comment
             lines do not exceed the 80 Col count. If you need more than 80
             characters for a comment. Then go to the next line like this example.
********************************************************************************/

// For now, put your Function Prototypes here

//Uninitialized Global Variables here.

//Initialized Global Variables here.




void main(void)
{
   
   {
      //declare unintialized local variable
     volatile unsigned int count= 0xFF;
     volatile unsigned int value = 0x00;
     volatile unsigned char cherry;
     //declare and initialise local variable

     DDRC = 0xFF;
     //assign all the LEDs as outputs



     for(;;) 
     {
         //Program 1
         /*    
         cherry = PORTB;      //cherry char becomes what value the switches are holding.
         PORTC = cherry;      //LEDS become what the switches are.
         */
         
         //Program 2
         /*
         cherry = PORTB;
         PORTC |= 0x07;
         while(count > 0)     //Loops until count reaches zero
         {
            count--;          //subtracts 1 until count is zero
         }
         */
         
         //Program 3
     
        
         
        _FEED_COP(); /* feeds the dog */
     } /* loop forever */
    /* please make sure that you never leave main */
   }
}
     
     unsigned char function(unsigned char breakfast)
     {
         if (PORTB > 15)         //Seeing if dip switches are grater than 15
         {
            breakfast = 0xF0;    //Bits 7-4 of LEDS become one and bits 3-0 become zero
         }
         
         else
         {
            breakfast = 0x0F;        //Bits 3-0 of LEDS become one and bits 7-4 become one
         }
      return breakfast;          //returns the char breakfast. Can't have it hanging out alone.
     }

         