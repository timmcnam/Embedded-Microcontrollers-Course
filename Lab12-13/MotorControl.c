#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <Protos.h>
/*
  Timothy McNamara
  ECET 20900
  Lab 12-13
  Last Revised: 11/16/2023
*/

void aToDInitializationFunction()
{

 int count;
 /*
   Setting up a variable to be used in a for loop. This could have easily 
   been done in the top of the program where we declare unitialized 
   global variables.
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
  and setting the index variable to the begging of the array 
  (depending on where the beggining is for reverse or forward). 
  Setting the index address variable as static allows us to never 
  lose where we are in our array. This reinforces smooth operation 
  of the stepper motor on the trainer board as well.
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


void delayMotoFunc(unsigned int count)
{
  //while (count !=0)
  for(;count>0;count--)
  {
   ;
  }
   /*
     This delay function allows us to use a for loop to count down
     until the condition becomes false and breaks from the loop.
     We leave a blank space for the initialized part of the for loop
     since we are passing a global variable. As for the body, we leave it 
     only with a semicolon. This performs as a nop in assembly and takes 
     up a computer cycle.  
   */ 
}
