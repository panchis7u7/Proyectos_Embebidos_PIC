#INCLUDE <P16F887.INC>
 LIST P=16F887
; CONFIG1
; __config 0xFFE1
 __CONFIG _CONFIG1, _FOSC_HS & _WDTE_OFF & _PWRTE_ON & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_ON & _FCMEN_ON & _LVP_ON
; CONFIG2
; __config 0xFFFF
 __CONFIG _CONFIG2, _BOR4V_BOR40V & _WRT_OFF
 
 CBLOCK 
 ENDC
 ORG 0x00
    CALL IRsetup
REC:
    BTFSC PORTA,4
    GOTO ACT_RLF
    GOTO REC
ACT_RLF:
    BTFSC PORTA,4
    GOTO ACT_RLF
    MOVLW 0x00
    MOVWF BYTES
    MOVLW 0xFF
    MOVWF BYTES+1
    MOVLW 0xA2
    MOVWF BYTES+2
    MOVLW 0x5D
    MOVWF BYTES+3
    MOVLW D'255'
    CALL IRcarrier  ;9ms de carrier
    MOVLW D'110'
    CALL IRcarrier
    CALL RETARDO_5MS_16
    CALL IRsend
GOTO REC
    #INCLUDE <RETARDOS_16MHZ.inc>
    #INCLUDE <IR.inc>
 END


