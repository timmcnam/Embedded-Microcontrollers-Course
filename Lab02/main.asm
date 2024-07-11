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
;Date: 08/31/2023
;Class: ECET 20900 Fall 2023
;Section: Thursday Lab
;Assignment: Lab 02 Assembler Directives
;Due Date; 09/06/2023
;Description: provide a brief description of the program. Make sure your comment
;             lines do not exceed the 80 Col count. If you need more than 80
;             characters for a comment. Then go to the next line like this example.
;****************


; constants section,
MY_CONSTANTS: SECTION
;Insert your constants with assigned values

;warm-up
   ;FirstOffset  equ 25
   
;Part I
   ;const1:    dc.b  $33
   ;const2:    equ   $55
   
;Part II
   ;value1:    equ   25
   ;value2:    dc.b  $11,$33

;Part III
   local1:     dc.b  $3B
   local2:     dc.b  $1D
   local3:     dc.b  $12     
   
; variable/data section
MY_EXTENDED_RAM: SECTION
; Insert here your data definition.

;warm-up
   ;MyOffset:     ds.b  1
   
;Part I
   ;var1:       ds.b  1
   ;var2:       ds.b  2
   
;Part II
   ;var3:        ds.b  1

;Part III
   result:     ds.b  1
   
; code section
MyCode:     SECTION
;always leave the next three labels in the program
main:
_Startup:
Entry:
;insert your program code here

       ;warm-up  
         ;ldaa #FirstOffset
         ;staa MyOffset
         ;nop
         
       ;Part I
         ;ldaa    const1   ;Instruction 1
         ;staa    var1     ;Instruction 2
         ;ldaa    #const2  ;Instruction 3
         ;staa    var2     ;Instruction 4
         ;ldaa    #$22     ;Instruction 5
         ;staa    var2+1   ;Instruction 6
          ;the    next instructions helps determine the program end when debugging
         ;nop
 
       ;Part II
         ;ldaa  #value1  ; 1
         ;staa  var3     ; 2
         ;adda  value2   ; 3
         ;staa  var3     ; 4
         ;adda  value2+1 ; 5
         ;staa  var3     ; 6
         ;nop            ; 7
         ;bra Entry      ; 8 
         
       ;Part III
            ldaa  local1     ;1
            adda  local2     ;2
            adda  local3     ;3
            staa  result      ;4
            nop               ;5
            BRA   Entry       ;6