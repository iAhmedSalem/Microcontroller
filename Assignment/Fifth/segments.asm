
_main:

;segments.c,15 :: 		void main() {
;segments.c,16 :: 		unsigned char count = 0;
	CLRF        main_count_L0+0 
;segments.c,19 :: 		TRISD = 0x00; // Set PORTD as output (all pins)
	CLRF        TRISD+0 
;segments.c,20 :: 		PORTD = 0x00; // Clear PORTD
	CLRF        PORTD+0 
;segments.c,22 :: 		while (1) {
L_main0:
;segments.c,24 :: 		PORTD = segment_map[count];
	MOVLW       _segment_map+0
	ADDWF       main_count_L0+0, 0 
	MOVWF       TBLPTR+0 
	MOVLW       hi_addr(_segment_map+0)
	MOVWF       TBLPTR+1 
	MOVLW       0
	ADDWFC      TBLPTR+1, 1 
	MOVLW       higher_addr(_segment_map+0)
	MOVWF       TBLPTR+2 
	MOVLW       0
	ADDWFC      TBLPTR+2, 1 
	TBLRD*+
	MOVFF       TABLAT+0, PORTD+0
;segments.c,27 :: 		count = (count + 1) % 10;
	MOVF        main_count_L0+0, 0 
	ADDLW       1
	MOVWF       R0 
	CLRF        R1 
	MOVLW       0
	ADDWFC      R1, 1 
	MOVLW       10
	MOVWF       R4 
	MOVLW       0
	MOVWF       R5 
	CALL        _Div_16x16_S+0, 0
	MOVF        R8, 0 
	MOVWF       R0 
	MOVF        R9, 0 
	MOVWF       R1 
	MOVF        R0, 0 
	MOVWF       main_count_L0+0 
;segments.c,30 :: 		Delay_ms(1000); // Adjust delay based on your clock frequency
	MOVLW       6
	MOVWF       R11, 0
	MOVLW       19
	MOVWF       R12, 0
	MOVLW       173
	MOVWF       R13, 0
L_main2:
	DECFSZ      R13, 1, 1
	BRA         L_main2
	DECFSZ      R12, 1, 1
	BRA         L_main2
	DECFSZ      R11, 1, 1
	BRA         L_main2
	NOP
	NOP
;segments.c,31 :: 		}
	GOTO        L_main0
;segments.c,32 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
