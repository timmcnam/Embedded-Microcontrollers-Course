#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
/**************************************************************************************
Commented Header
Author: Timothy McNamara
Date: 10/31/20232
Class: ECET 20900 Fall 2023
Section: Thursday Lab
Assignment: Lab 10-11 Reading the Analog to Digital Converter in C
Due Date; 11/04/2023
Description: In this lab, we utilize the capabilities the MC9S12XEP100 chip 
             has to offer. One of those capabilities the chip comes with is the
             ability to convert Analog to Digital aka ATD converter. Using this
             allows us to convert a changing voltage waves to digital values the
             computer can read. Analog input => digital quantization out.
             We have to make use of the architecture inside our chip to get our
             desired result to our LEDs. We have theoretical formulas to compare the
             results our ATD converter actually gets and displays to the LEDs in
             binary. 
**************************************************************************************/

// For now, put your Function Prototypes here

/*
  The function prototypes helps determine the return type of data the function returns,
  helps tell us the number of arguments passed, helps tell the order in which the
  arguments are passed to the function, and helps tell the data types of each of the
  passed arguments. We also use function prototypes to follow ACII standardization.
*/

void aToDInitializationFunction(void);
/*
  This function returns nothing and nothing is passed to the function.
  Also this function prototype is used to start up the ATD converter.
*/

unsigned char conversionAndReadFunction(void);
/*
  This function prototype is used for the function that actually converts the 
  potentiometer value and reads it. It returns an 8 bit unsigned char variable 
*/

//Uninitialized Global Variables here.

//Initialized Global Variables here.

void main(void) 
{
 
  DDRC = 0xFF;   //Setting all the LEDs as outputs in the DDR
  
  aToDInitializationFunction();  //Calling the function to start up the converter

  for(;;) 
  {
     /*
       Here in the continous for loop, we repeat the process of converting the
       reading on the potentiometer. If we were to call this outside of the for loop,
       the binary value displayed on the LEDs would not update according to the
       direction of the knob on the potentiometer.
     */
     
     unsigned char ledValue;    //Uninitialized variable being assigned.  
     
     ledValue = conversionAndReadFunction();    
     /*
       Setting the variable we just made equal to the function we just called
       allows us to easily transfer the returned value of the function and
       oputput it to the LEDs.
     */
     
     PORTC = ledValue;    //Displaying output to LEDs 
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void aToDInitializationFunction()
{

 int count;
 /*
   Setting up a variable to be used in a for loop. This could have easily been done
   in the top of the program where we declare unitialized global variables.
 */ 
 
 ATD0CTL2 &= ~0x60;
 /*
   Setting bits 6:5 to zero allows us to be in 8 bit mode in the ATD converter.
   The rest of the register we can leave alone. They have default setting we
   don't need to tamper with.
 */
 
 for(count=0;count<800;count++)
 {
            ;     
 }
 //In the for loop above, we are letting time pass for the capacitors to charge. 
 
 ATD0CTL4 = 0x40;
 /*
   Here we are writing to the register that controls the sample times. Here
   we want the sample times to match the bit mode we have selected. We also
   want it to be slow enough so that our hardware can keep up with the
   software.  
 */
 
}

unsigned char conversionAndReadFunction()
{

 ATD0CTL5=2;
 /*
   Writes to this register has us select which channel we are starting our
   conversion at. Here we set it to "2" since our potentiometer is tied
   to channel 2. 
 */
 
 while(!(ATD0STAT0 & 0x80))
 {
            ;   //Waiting for the highest bit in the register to be 1. 
 }
 
 return ATD0DR2H;
 /*
   The Register now holds our converted digital value. We want the
   MSBytes of channel 2 so we use "ATD0DR2H". 
 */
}

