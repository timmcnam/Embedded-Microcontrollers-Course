;**************************************************************
;* This stationery serves as the framework for a              *
;* user application. For a more comprehensive program that    *
;* demonstrates the more advanced functionality of this       *
;* processor, please see the demonstration applications       *
;* located in the examples subdirectory of the                *
;* Freescale CodeWarrior for the HC12 Program directory       *
;**************************************************************
; Include derivative-specific definitions
            INCLUDE 'derivative.inc'

; export symbols
            XDEF Entry, _Startup, main
            ; we use export 'Entry' as symbol. This allows us to
            ; reference 'Entry' either in the linker .prm file
            ; or from C/C++ later on

            XREF __SEG_END_SSTACK      ; symbol defined by the linker for the end of the stack

;****************
;Commented Header
;Author: Timothy McNamara
;Date: 09/06/2023
;Class: ECET 20900 Fall 2023
;Section: Thursday Lab
;Assignment: Lab 03 IO
;Due Date; 09/13/2023
;Description: provide a brief description of the program. Make sure your comment
;             lines do not exceed the 80 Col count. If you need more than 80
;             characters for a comment. Then go to the next line like this example.
;****************


; constants section,
MY_CONSTANTS: SECTION
;Insert your constants with assigned values
 PortB:     equ   $01
 ddrb:      equ   $03
 PortC:     equ   $04
 ddrc:      equ   $06
 Value3:    dc.b  $3     



; variable/data section
MY_EXTENDED_RAM: SECTION
; Insert here your data definition.
ADDEND:   ds.b  1 



; code section
MyCode:     SECTION
;always leave the next three labels in the program
main:
_Startup:
Entry:
;insert your program code here
      
      ;Part I
         ;movb  #$ff,ddrc      ;assigns all LEDS as outputs
         ;movb  #$00,ddrb      ;assigns all dip switches as inputs
         ;ldaa  PortB          ;reads the dip switches
         ;adda  Value3         ;adds 3 in hex to the value read
         ;staa  PortC         ;Loads the value in accumulator and loads it to the LEDs
                           
                           
         ;ldaa  #$ff
         ;staa  PortB
         ;nop                  ;pauses for one cycle
         ;end                  ;ends program
         
      ;Part II
         movb  #$ff,ddrc
         movb  #$00,ddrb
         ldaa  PortB
         adda  ADDEND
         staa  PortC
         
         nop
         end
      
 