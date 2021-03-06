#INCLUDE <P16F887.INC>
    LIST P=16F887
; CONFIG1
; __config 0xFFE1
 __CONFIG _CONFIG1, _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_ON & _FCMEN_ON & _LVP_ON
; CONFIG2
; __config 0xFFFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF
 
 udata
 
 CBLOCK 0x20
 ENDC
 
 ORG 0
 SETUP:
    BSF STATUS,RP0
    BCF STATUS,RP1	;BANCO 1.
    BCF TRISC,6 
    BSF TRISC,7
    CLRF TRISD
    MOVLW D'25'
    MOVWF SPBRG
    MOVLW B'00100000'
    MOVWF TXSTA
    BCF STATUS,RP0	;BANCO 0.
    MOVLW B'10010000'
    MOVWF RCSTA
    MOVLW D'00110000'
    MOVWF T1CON
    CLRF PORTD
  PROGRAMA:
    MOVFW RCREG
    SUBLW 0x00
    BTFSC STATUS,Z
    GOTO PROGRAMA
    MOVFW RCREG
    MOVWF PORTD
    GOTO PROGRAMA
    END


