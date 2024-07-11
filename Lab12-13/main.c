#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <Protos.h>

/******************************************************************************
Commented Header
Author: Timothy McNamara
Date: 11/16/2023
Class: ECET 20900 Fall 2023
Section: Thursday Lab
Assignment: Lab 12-13 Stepper Motor W/ ADC Speed C
Due Date; 11/30/2023
Description: provide a brief description of the program. Make sure your 
               comment lines do not exceed the 80 Col count. If you need 
               more than 80 characters for a comment. Then go to the next 
               line like this example.
******************************************************************************/

// For now, put your Function Prototypes here

//Uninitialized Global Variables here.

//Initialized Global Var iables here.




void main(void) 
{
  
  DDRC = 0xFF;
  DDRD = 0x0F;
  
  aToDInitializationFunction();  //Calling the function to start up the converter





  for(;;) 
  {
       volatile unsigned char ledValue;
       volatile unsigned int speedValue;
       
      stepMotoFunc();
      
      ledValue = conversionAndReadFunction();    
     /*
       Setting the variable we just made equal to the function we just called
       allows us to easily transfer the returned value of the function and
       oputput it to the LEDs.
     */
     
     PORTC = ledValue;    //Displaying output to LEDs
     
     speedValue = 65530 - (((unsigned int)ledValue) * 483);
     
     delayMotoFunc(speedValue);
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}