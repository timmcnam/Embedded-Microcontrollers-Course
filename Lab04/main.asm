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
;Date: 09/21/2023
;Class: ECET 20900 Fall 2023
;Section: Thursday Lab
;Assignment: Lab 05 I/O Devices, Sequential Logic vs. Index Addressing 
;Due Date; 09/27/2023
;Description: provide a brief description of the program. Make sure your comment
;             lines do not exceed the 80 Col count. If you need more than 80
;             characters for a comment. Then go to the next line like this example.
;****************




; variable/data section
MY_EXTENDED_RAM: SECTION
; Insert here your data definition.
LEDs:       equ $04
DDRc:    equ $06


; code section
MyCode:     SECTION
main:
_Startup:
Entry:
      ;PartI
                LDAA #$FF ; a value to set all 8 bits of LEDs as outputs
                STAA DDRc ;set all 8 bits of LEDs as outputs
                
        Repeat: LDAA #$03 ; loads the accumulator with hex 03
                STAA LEDs ; writes 00000011 to the led bits
                
                LDAA #$07 ; loads the accumulator with hex 07
                STAA LEDs ; writes 00000111 to the led bits
                
                LDAA #$0E ; loads the accumulator with hex 0E
                STAA LEDs ; writes 00001110 to the led bits
                
                LDAA #$1C ; loads the accumulator with hex 1C
                STAA LEDs ; writes 00011100 to the led bits
                
                LDAA #$38 ; loads the accumulator with hex 38
                STAA LEDs ; writes 00111000 to the led bits
                
                LDAA #$70 ; loads the accumulator with hex 70
                STAA LEDs ; writes 01110000 to the led bits
                
                LDAA #$E0 ; loads the accumulator with hex E0
                STAA LEDs ; writes 11100000 to the led bits
                
                LDAA #$C0 ; loads the accumulator with hex C0
                STAA LEDs ; writes 11000000 to the led bits
                
                LDAA #$E0 ; loads the accumulator with hex E0
                STAA LEDs ; writes 11100000 to the led bits
                
                LDAA #$70 ; loads the accumulator with hex 70
                STAA LEDs ; writes 01110000 to the led bits
                
                LDAA #$38 ; loads the accumulator with hex 38
                STAA LEDs ; writes 00111000 to the led bits
                
                LDAA #$1C ; loads the accumulator with hex 1C
                STAA LEDs ; writes 00011100 to the led bits
                
                LDAA #$0E ; loads the accumulator with hex 0E
                STAA LEDs ; writes 00001110 to the led bits
                
                LDAA #$07 ; loads the accumulator with hex 07
                STAA LEDs ; writes 00000111 to the led bits
                
                BRA Repeat ; repeat the code!
      ;Part II
      
      
      
      
      
      
      
      
      