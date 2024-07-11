#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
/*********************************************************************************
Commented Header
Author: Timothy McNamara
Date: 10/19/2023
Class: ECET 20900 Fall 2023
Section: Thursday Lab
Assignment: Lab 08-09 Stepper Motor Instructions
Due Date; 10/19/2023
Description: This lab goes over operation of the stepper motor using two 
              seperate dip switches to control speed and direction. Within 
             the program we create and call two function that allows us to not 
             only turn the motor, but to avoid locking up the motor. The 
             MC9S12XEP100 clock speed and cycle speed is so fast that if we 
             did not add delay functions, we would lock up to motor and over-
             heat the motor.This lab covers index addressing, arrays, pointers,
             calling functions, creating functions that have to pass a value but
             not return anything. Overall, this helps the further understanding of
             the C language. 
********************************************************************************/

// For now, put your Function Prototypes here

/*declared here are the function prototypes. Writing these helps the program
determine what these functions do. What they return(if they return anything) or what
value is passed to them in order to correctly call the functions later.
*/
void delayMotoFunc(unsigned int);
void stepMotoFunc(void);
  

//Uninitialized Global Variables here.
                                  
//Initialized Global Variables here.

//Count that helps determine the speed of the motor. The bigger the -
//count, the bigger the delay. Hence, the naming of both of these initialized global
//variables.
unsigned int delaySlow = 65530;  
unsigned int delayFast = 3169;





void main(void) 
{
 //Sets the first four bits of the Data Directional Register of the
 //stepper motor as outputs.
 DDRD = 0x0F;

  for(;;) 
  {
  
   stepMotoFunc(); //Calls the stepper motor function.
  
    if(PORTB & 0x80) //Checks if bit 7 is high
    {
     delayMotoFunc(delayFast);  //Fast speed. Smaller variable is passed to delay function
    }
    else  //If bit 7 in low (not high)
    {
     delayMotoFunc(delaySlow);  //Slow speed. Bigger variable is passed to delay function.    
    }
      
      
    _FEED_COP(); /* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

/*
  This delay function allows us to use a for loop to count down
  until the condition becomes false and breaks from the loop.
  We leave a blank space for the initialized part of the for loop
  since we are passing a global variable. As for the body, we leave it 
  only with a semicolon. This performs as a nop in assembly and takes 
  up a computer cycle.  
*/
void delayMotoFunc(unsigned int count)
{
  //while (count !=0)
  for(;count>0;count--)
  {
   ;
  }
  
}

/*
  The Stepper Motor Function has a static char index variable
  that acts as a pointer in the array. The array consists of 4
  hex values that determine the position of the motor. All these 
  hex values in a sequence that repeats allows the motor to turn
  and drive. If we want to reverse the drive of the motor, we 
  simply go backwards in the array. Accomplishing this in the function,
  we simply check bit 0 of the dip switches and see whether it is 
  high or low. If it's high we go up through the array (Forward); if 
  it isn't, we step backwards (Reverse) through the array. Resetting
  the index variable so that it repeats is done with if statements 
  and setting the index variable to the begging of the array (depending
  on where the beggining is for reverse or forward). Setting the 
  index address variable as static allows us to never lose where we 
  are in our array. This reinforces smooth operation of the stepper motor 
  on the trainer board as well.
*/

void stepMotoFunc(void)
{

 static char place = 0;
 unsigned char positionOfStepMoto[]={0x05,0x09,0x0A,0x06};
 
 PORTD = positionOfStepMoto[place];
  
 if (PORTB & 0x01)  //forward
 {
  place++;

   if (place == 4)
   {
    place = 0;  //goes back to beggining
   }
 }
 else 
 {
  place--; //reverse
   
   if (place < 0)
   {
    place = 3;
   }
 }     
}