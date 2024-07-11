#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
/*********************************************************************************
Commented Header
Author: Timothy McNamara
Date: 10/05/2023
Class: ECET 20900 Fall 2023
Section: Thursday Lab
Assignment: Lab 07 C Language Assignment and Logic / C Functions
Due Date; 10/11/2023
Description: This lab utilizes 3 programs of different outcomes and processes. 
             The first program clears a bit of the LEDs without affecting the other bits.
             The second sets a bit without affecting the other bits.
             The third program utilizes a function prototype, the first in this class,
              that will pass on a pre-selected aribitrary value that is then later used 
             in a switch case statement that calls the function. At the end of this 
              called function, an if else statement is proclaimed. If the value passed
             and the value of the PORTB dip switches are one in the same, a 1 is returned;
               else a 0 is returned. This "returnedBit" is sent to another if else
             statement that will light all LEDs if a 1 is returned, and leave them all
             off if anything else is returned.
********************************************************************************/

// For now, put your Function Prototypes here
int myFunctionPrototype(unsigned int myLilPredeterminedValue); 

//Uninitialized Global Variables here.

//Initialized Global Variables here.

//Program1 & 2
//unsigned int lilCount = 0xFF;

//Program3





void main(void)
{
   
   {
      
      //Program 1 & 2 Variable
      //volatile unsigned char switchReader;
      
     



     
     
     //Program3
     unsigned int myLilPredeterminedValue = 7;
     volatile unsigned int returnedBit;
     
     DDRC = 0xFF;

     for(;;) 
     {
      //Program1
      /*switchReader = PORTB;
      switchReader &= ~0x10;
      while (lilCount != 0)
      {
        lilCount--;
      }
      
      PORTC = switchReader;
      */
      
      //Program2
      /*switchReader = PORTB;
      switchReader |= 0x04;
      while (lilCount != 0)
      {
         lilCount--;
      }
      
      PORTC = switchReader;
      */
      
      //Program3   
      returnedBit = myFunctionPrototype(myLilPredeterminedValue);
      if (returnedBit == 1)
      {
       PORTC = 0xFF;  
      }
      else
      {
       PORTC = 0x00;
      }
      
                
       _FEED_COP(); /* feeds the dog */
     } /* loop forever */
     /* please make sure that you never leave main */
   }
    
}

myFunctionPrototype(unsigned int mySmallerValue)
{
 volatile unsigned int mask;
 switch(mySmallerValue)
 { 
   case 0:
      mask = 0x00;
      break;
   case 1:
      mask = 0x01;
      break;
   case 2:
      mask = 0x02;
      break;
   case 3:
      mask = 0x04;
      break;
   case 4:
      mask = 0x08;
      break;
   case 5:
      mask = 0x10;
      break;
   case 6:
      mask = 0x40;
      break;
   case 7:
      mask = 0x80;
      break;
 }
    if (mask & PORTB)
    {
     return 1; 
    }
    else
    {
     return 0; 
    }

}






