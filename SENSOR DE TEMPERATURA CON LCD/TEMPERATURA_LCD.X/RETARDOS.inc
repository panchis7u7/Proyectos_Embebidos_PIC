;**************************** Librer�a "RETARDOS.INC" *********************************
;	===================================================================
;	  Del libro "MICROCONTROLADOR PIC16F84. DESARROLLO DE PROYECTOS"
;	  E. Palacios, F. Remiro y L. L�pez.
; 	  Editorial Ra-Ma.  www.ra-ma.es
;	===================================================================
;
; Librer�a con m�ltiples subrutinas de retardos, desde 4 microsegundos hasta 20 segundos. 
; Adem�s se pueden implementar otras subrutinas muy f�cilmente.
;
; Se han calculado para un sistema microcontrolador con un PIC trabajando con un cristal
; de cuarzo a 4 MHz. Como cada ciclo m�quina son 4 ciclos de reloj, resulta que cada
; ciclo m�quina tarda 4 x 1/4MHz = 1 �s.
; En los comentarios, "cm" significa "ciclos m�quina".
; ZONA DE DATOS *********************************************************************
    CBLOCK
    R_CONTA				; Contadores para los retardos.
    R_CONTB
    R_CONTC
    ENDC
; RETARDOS de 4 hasta 10 microsegundos ---------------------------------------------------
; A continuaci�n retardos peque�os teniendo en cuenta que para una frecuencia de 4 MHZ,
; la llamada a subrutina "call" tarda 2 ciclos m�quina, el retorno de subrutina
; "return" toma otros 2 ciclos m�quina y cada instrucci�n "nop" tarda 1 ciclo m�quina.
RETARDO_10MICROS				; La llamada "call" aporta 2 ciclos m�quina.
    NOP				; Aporta 1 ciclo m�quina.
    NOP				; Aporta 1 ciclo m�quina.
    NOP				; Aporta 1 ciclo m�quina.
    NOP				; Aporta 1 ciclo m�quina.
    NOP				; Aporta 1 ciclo m�quina.
RETARDO_5MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    NOP				; Aporta 1 ciclo m�quina.
RETARDO_4MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    RETURN				; El salto del retorno aporta 2 ciclos m�quina.
; RETARDOS de 20 hasta 500 microsegundos ------------------------------------------------
RETARDO_500MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    NOP					; Aporta 1 ciclo m�quina.
    MOVLW	D'164'			; Aporta 1 ciclo m�quina. Este es el valor de "K".
    GOTO	RETARDOMICROS		; Aporta 2 ciclos m�quina.
RETARDO_200MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    NOP					; Aporta 1 ciclo m�quina.
    MOVLW	D'64'			; Aporta 1 ciclo m�quina. Este es el valor de "K".
    GOTO	RETARDOMICROS		; Aporta 2 ciclos m�quina.
RETARDO_100MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'31'			; Aporta 1 ciclo m�quina. Este es el valor de "K".
    GOTO	RETARDOMICROS		; Aporta 2 ciclos m�quina.
RETARDO_50MICROS			; La llamada "call" aporta 2 ciclos m�quina.
    NOP					; Aporta 1 ciclo m�quina.
    MOVLW	D'14'			; Aporta 1 ciclo m�quina. Este es el valor de "K".
    GOTO	RETARDOMICROS		; Aporta 2 ciclos m�quina.
RETARDO_20MICROS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'5'			; Aporta 1 ciclo m�quina. Este es el valor de "K".
; El pr�ximo bloque "RetardoMicros" tarda:
; 1 + (K-1) + 2 + (K-1)x2 + 2 = (2 + 3K) ciclos m�quina.
RETARDOMICROS
    MOVWF	R_CONTA			; Aporta 1 ciclo m�quina.
RMICROS_BUCLE
    DECFSZ	R_CONTA,F		; (K-1)x1 cm (cuando no salta) + 2 cm (al saltar).
    GOTO	RMICROS_BUCLE		; Aporta (K-1)x2 ciclos m�quina.
    RETURN				; El salto del retorno aporta 2 ciclos m�quina.
;En total estas subrutinas tardan:
; - Retardo_500micros:	2 + 1 + 1 + 2 + (2 + 3K) = 500 cm = 500 �s. (para K=164 y 4 MHz).
; - Retardo_200micros:	2 + 1 + 1 + 2 + (2 + 3K) = 200 cm = 200 �s. (para K= 64 y 4 MHz).
; - Retardo_100micros:	2     + 1 + 2 + (2 + 3K) = 100 cm = 100 �s. (para K= 31 y 4 MHz).
; - Retardo_50micros :	2 + 1 + 1 + 2 + (2 + 3K) =  50 cm =  50 �s. (para K= 14 y 4 MHz).
; - Retardo_20micros :	2     + 1     + (2 + 3K) =  20 cm =  20 �s. (para K=  5 y 4 MHz).
; RETARDOS de 1 ms hasta 200 ms. --------------------------------------------------------
RETARDO_200MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'200'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_100MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'100'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_50MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'50'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_20MS				; La llamada "call" aporta 2 ciclos m�quina.	
    MOVLW	D'20'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_10MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'10'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_5MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'5'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_2MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'2'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
    GOTO	RETARDOS_MS		; Aporta 2 ciclos m�quina.
RETARDO_1MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'1'			; Aporta 1 ciclo m�quina. Este es el valor de "M".
; El pr�ximo bloque "Retardos_ms" tarda:
; 1 + M + M + KxM + (K-1)xM + Mx2 + (K-1)Mx2 + (M-1) + 2 + (M-1)x2 + 2 =
; = (2 + 4M + 4KM) ciclos m�quina. Para K=249 y M=1 supone 1002 ciclos m�quina
; que a 4 MHz son 1002 �s = 1 ms.
RETARDOS_MS
    MOVWF	R_CONTB			; Aporta 1 ciclo m�quina.
R1MS_BUCLEEXTERNO
    MOVLW	D'249'			; Aporta Mx1 ciclos m�quina. Este es el valor de "K".	
    MOVWF	R_CONTA			; Aporta Mx1 ciclos m�quina.
R1MS_BUCLEINTERNO
    NOP				; Aporta KxMx1 ciclos m�quina.
    DECFSZ	R_CONTA,F		; (K-1)xMx1 cm (cuando no salta) + Mx2 cm (al saltar).
    GOTO	R1MS_BUCLEINTERNO	; Aporta (K-1)xMx2 ciclos m�quina.
    DECFSZ	R_CONTB,F		; (M-1)x1 cm (cuando no salta) + 2 cm (al saltar).
    GOTO	R1MS_BUCLEEXTERNO	; Aporta (M-1)x2 ciclos m�quina.
    RETURN				; El salto del retorno aporta 2 ciclos m�quina.
;En total estas subrutinas tardan:
; - Retardo_200ms:	2 + 1 + 2 + (2 + 4M + 4KM) = 200007 cm = 200 ms. (M=200 y K=249).
; - Retardo_100ms:	2 + 1 + 2 + (2 + 4M + 4KM) = 100007 cm = 100 ms. (M=100 y K=249).
; - Retardo_50ms :	2 + 1 + 2 + (2 + 4M + 4KM) =  50007 cm =  50 ms. (M= 50 y K=249).
; - Retardo_20ms :	2 + 1 + 2 + (2 + 4M + 4KM) =  20007 cm =  20 ms. (M= 20 y K=249).
; - Retardo_10ms :	2 + 1 + 2 + (2 + 4M + 4KM) =  10007 cm =  10 ms. (M= 10 y K=249).
; - Retardo_5ms  :	2 + 1 + 2 + (2 + 4M + 4KM) =   5007 cm =   5 ms. (M=  5 y K=249).
; - Retardo_2ms  :	2 + 1 + 2 + (2 + 4M + 4KM) =   2007 cm =   2 ms. (M=  2 y K=249).
; - Retardo_1ms  :	2 + 1     + (2 + 4M + 4KM) =   1005 cm =   1 ms. (M=  1 y K=249).
; RETARDOS de 0.5 hasta 20 segundos ---------------------------------------------------
RETARDO_20S				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'200'			; Aporta 1 ciclo m�quina. Este es el valor de "N".
    GOTO	RETARDO_1DECIMA	    	; Aporta 2 ciclos m�quina.
RETARDO_10S				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'100'			; Aporta 1 ciclo m�quina. Este es el valor de "N".  
    GOTO	RETARDO_1DECIMA	 	; Aporta 2 ciclos m�quina.
RETARDO_5S				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'50'			; Aporta 1 ciclo m�quina. Este es el valor de "N".
    GOTO	RETARDO_1DECIMA		; Aporta 2 ciclos m�quina.
RETARDO_2S				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'20'			; Aporta 1 ciclo m�quina. Este es el valor de "N".  
    GOTO	RETARDO_1DECIMA	 	; Aporta 2 ciclos m�quina.
RETARDO_1S				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'10'			; Aporta 1 ciclo m�quina. Este es el valor de "N".
    GOTO	RETARDO_1DECIMA	 	; Aporta 2 ciclos m�quina.
RETARDO_500MS				; La llamada "call" aporta 2 ciclos m�quina.
    MOVLW	D'5'			; Aporta 1 ciclo m�quina. Este es el valor de "N".
; El pr�ximo bloque "Retardo_1Decima" tarda:
; 1 + N + N + MxN + MxN + KxMxN + (K-1)xMxN + MxNx2 + (K-1)xMxNx2 +
;   + (M-1)xN + Nx2 + (M-1)xNx2 + (N-1) + 2 + (N-1)x2 + 2 =
; = (2 + 4M + 4MN + 4KM) ciclos m�quina. Para K=249, M=100 y N=1 supone 100011
; ciclos m�quina que a 4 MHz son 100011 �s = 100 ms = 0,1 s = 1 d�cima de segundo.
RETARDO_1DECIMA
    MOVWF	R_CONTC			; Aporta 1 ciclo m�quina.
R1DECIMA_BUCLEEXTERNO2
    MOVLW	D'100'			; Aporta Nx1 ciclos m�quina. Este es el valor de "M".
    MOVWF	R_CONTB			; Aporta Nx1 ciclos m�quina.
R1DECIMA_BUCLEEXTERNO
    MOVLW	D'249'			; Aporta MxNx1 ciclos m�quina. Este es el valor de "K".
    MOVWF	R_CONTA			; Aporta MxNx1 ciclos m�quina.
R1DECIMA_BUCLEINTERNO         
    NOP					; Aporta KxMxNx1 ciclos m�quina.
    DECFSZ	R_CONTA,F		; (K-1)xMxNx1 cm (si no salta) + MxNx2 cm (al saltar).
    GOTO	R1DECIMA_BUCLEINTERNO 	; Aporta (K-1)xMxNx2 ciclos m�quina.
    DECFSZ	R_CONTB,F		; (M-1)xNx1 cm (cuando no salta) + Nx2 cm (al saltar).
    GOTO	R1DECIMA_BUCLEEXTERNO	; Aporta (M-1)xNx2 ciclos m�quina.
    DECFSZ	R_CONTC,F		; (N-1)x1 cm (cuando no salta) + 2 cm (al saltar).
    GOTO	R1DECIMA_BUCLEEXTERNO2	; Aporta (N-1)x2 ciclos m�quina.
    RETURN				; El salto del retorno aporta 2 ciclos m�quina.
;En total estas subrutinas tardan:
; - Retardo_20s:	2 + 1 + 2 + (2 + 4N + 4MN + 4KMN) = 20000807 cm = 20 s.
;			(N=200, M=100 y K=249).
; - Retardo_10s:	2 + 1 + 2 + (2 + 4N + 4MN + 4KMN) = 10000407 cm = 10 s.
;			(N=100, M=100 y K=249).
; - Retardo_5s:		2 + 1 + 2 + (2 + 4N + 4MN + 4KMN) =  5000207 cm =  5 s.
;			(N= 50, M=100 y K=249).
; - Retardo_2s:		2 + 1 + 2 + (2 + 4N + 4MN + 4KMN) =  2000087 cm =  2 s.
;			(N= 20, M=100 y K=249).
; - Retardo_1s:		2 + 1 + 2 + (2 + 4N + 4MN + 4KMN) =  1000047 cm =  1 s.
;			(N= 10, M=100 y K=249).
; - Retardo_500ms:	2 + 1     + (2 + 4N + 4MN + 4KMN) =   500025 cm = 0,5 s.
;			(N=  5, M=100 y K=249).
;	===================================================================
;	  Del libro "MICROCONTROLADOR PIC16F84. DESARROLLO DE PROYECTOS"
;	  E. Palacios, F. Remiro y L. L�pez.
; 	  Editorial Ra-Ma.  www.ra-ma.es
;	=====================================================


