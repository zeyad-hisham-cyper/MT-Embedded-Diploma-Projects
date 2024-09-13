	.file	"main.c"
__SREG__ = 0x3f
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__CCP__  = 0x34
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	TIMER1_COMP_init
	.type	TIMER1_COMP_init, @function
TIMER1_COMP_init:
/* prologue: function */
/* frame size = 0 */
	out (76)+1-32,__zero_reg__
	out 76-32,__zero_reg__
	ldi r24,lo8(13)
	out 78-32,r24
	ldi r24,lo8(15624)
	ldi r25,hi8(15624)
	out (74)+1-32,r25
	out 74-32,r24
	in r24,89-32
	ori r24,lo8(16)
	out 89-32,r24
/* epilogue start */
	ret
	.size	TIMER1_COMP_init, .-TIMER1_COMP_init
.global	__vector_7
	.type	__vector_7, @function
__vector_7:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
	push r25
/* prologue: Signal */
/* frame size = 0 */
	lds r24,mode
	tst r24
	brne .L4
	lds r24,seconds
	subi r24,lo8(-(1))
	sts seconds,r24
	cpi r24,lo8(60)
	brne .L5
	sts seconds,__zero_reg__
	lds r24,minutes
	subi r24,lo8(-(1))
	sts minutes,r24
.L5:
	lds r24,minutes
	cpi r24,lo8(60)
	brne .L6
	sts minutes,__zero_reg__
	lds r24,hours
	subi r24,lo8(-(1))
	sts hours,r24
.L6:
	lds r24,hours
	cpi r24,lo8(24)
	brne .L7
	sts hours,__zero_reg__
	rjmp .L7
.L4:
	cpi r24,lo8(1)
	brne .L7
	lds r24,seconds
	tst r24
	brne .L8
	lds r25,minutes
	tst r25
	breq .L9
	ldi r24,lo8(59)
	sts seconds,r24
	subi r25,lo8(-(-1))
	sts minutes,r25
	rjmp .L7
.L9:
	lds r25,hours
	tst r25
	breq .L7
	ldi r24,lo8(59)
	sts seconds,r24
	sts minutes,r24
	subi r25,lo8(-(-1))
	sts hours,r25
	rjmp .L7
.L8:
	subi r24,lo8(-(-1))
	sts seconds,r24
.L7:
	lds r24,hours
	tst r24
	brne .L10
	lds r24,minutes
	tst r24
	brne .L10
	lds r24,seconds
	tst r24
	brne .L10
	sbi 50-32,0
	rjmp .L12
.L10:
	cbi 50-32,0
.L12:
/* epilogue start */
	pop r25
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_7, .-__vector_7
.global	handle_parameters
	.type	handle_parameters, @function
handle_parameters:
/* prologue: function */
/* frame size = 0 */
	lds r18,seconds
	mov r24,r18
	ldi r22,lo8(10)
	call __udivmodqi4
	sts seconds_units,r25
	mov r24,r18
	call __udivmodqi4
	sts seconds_tenth,r24
	lds r18,minutes
	mov r24,r18
	call __udivmodqi4
	sts minutes_units,r25
	mov r24,r18
	call __udivmodqi4
	sts minutes_tenth,r24
	lds r18,hours
	mov r24,r18
	call __udivmodqi4
	sts hours_units,r25
	mov r24,r18
	call __udivmodqi4
	sts hours_tenth,r24
/* epilogue start */
	ret
	.size	handle_parameters, .-handle_parameters
.global	init_io
	.type	init_io, @function
init_io:
/* prologue: function */
/* frame size = 0 */
	in r24,58-32
	ori r24,lo8(63)
	out 58-32,r24
	out 55-32,__zero_reg__
	in r24,52-32
	ori r24,lo8(15)
	out 52-32,r24
	in r24,49-32
	ori r24,lo8(49)
	out 49-32,r24
	in r24,49-32
	andi r24,lo8(-13)
	out 49-32,r24
	ldi r24,lo8(-1)
	out 56-32,r24
	sbi 59-32,7
/* epilogue start */
	ret
	.size	init_io, .-init_io
.global	display_on_segment
	.type	display_on_segment, @function
display_on_segment:
/* prologue: function */
/* frame size = 0 */
	call handle_parameters
	ldi r24,lo8(32)
	out 59-32,r24
	in r25,53-32
	lds r24,seconds_units
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	ldi r18,lo8(500)
	ldi r19,hi8(500)
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(16)
	out 59-32,r24
	in r25,53-32
	lds r24,seconds_tenth
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(8)
	out 59-32,r24
	in r25,53-32
	lds r24,minutes_units
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(4)
	out 59-32,r24
	in r25,53-32
	lds r24,minutes_tenth
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(2)
	out 59-32,r24
	in r25,53-32
	lds r24,hours_units
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	ldi r24,lo8(1)
	out 59-32,r24
	in r25,53-32
	lds r24,hours_tenth
	andi r24,lo8(15)
	andi r25,lo8(-16)
	or r24,r25
	out 53-32,r24
	movw r24,r18
/* #APP */
 ;  105 "c:/winavr-20100110/lib/gcc/../../avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* epilogue start */
/* #NOAPP */
	ret
	.size	display_on_segment, .-display_on_segment
.global	check_mode
	.type	check_mode, @function
check_mode:
/* prologue: function */
/* frame size = 0 */
	lds r24,mode
	tst r24
	brne .L20
	sbi 50-32,4
	cbi 50-32,5
	rjmp .L21
.L20:
	cpi r24,lo8(1)
	brne .L21
	sbi 50-32,5
	cbi 50-32,4
.L21:
	sbic 54-32,7
	rjmp .L26
	sts mode,__zero_reg__
	tst r24
	brne .L27
	ldi r24,lo8(1)
	sts mode,r24
	rjmp .L27
.L25:
	call display_on_segment
.L27:
	sbis 54-32,7
	rjmp .L25
.L26:
	ret
	.size	check_mode, .-check_mode
.global	INT0_init
	.type	INT0_init, @function
INT0_init:
/* prologue: function */
/* frame size = 0 */
	sbi 50-32,2
	in r24,85-32
	ori r24,lo8(2)
	out 85-32,r24
	in r24,91-32
	ori r24,lo8(64)
	out 91-32,r24
/* epilogue start */
	ret
	.size	INT0_init, .-INT0_init
.global	__vector_1
	.type	__vector_1, @function
__vector_1:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
/* prologue: Signal */
/* frame size = 0 */
	cbi 50-32,0
	sts seconds,__zero_reg__
	sts minutes,__zero_reg__
	sts hours,__zero_reg__
	sts seconds_units,__zero_reg__
	sts seconds_tenth,__zero_reg__
	sts minutes_units,__zero_reg__
	sts minutes_tenth,__zero_reg__
	sts hours_units,__zero_reg__
	sts hours_tenth,__zero_reg__
/* epilogue start */
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_1, .-__vector_1
.global	INT1_init
	.type	INT1_init, @function
INT1_init:
/* prologue: function */
/* frame size = 0 */
	in r24,85-32
	ori r24,lo8(12)
	out 85-32,r24
	in r24,91-32
	ori r24,lo8(-128)
	out 91-32,r24
/* epilogue start */
	ret
	.size	INT1_init, .-INT1_init
.global	__vector_2
	.type	__vector_2, @function
__vector_2:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
/* prologue: Signal */
/* frame size = 0 */
	in r24,78-32
	andi r24,lo8(-6)
	out 78-32,r24
/* epilogue start */
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_2, .-__vector_2
.global	INT2_init
	.type	INT2_init, @function
INT2_init:
/* prologue: function */
/* frame size = 0 */
	in r24,84-32
	andi r24,lo8(-65)
	out 84-32,r24
	in r24,91-32
	ori r24,lo8(32)
	out 91-32,r24
/* epilogue start */
	ret
	.size	INT2_init, .-INT2_init
.global	__vector_3
	.type	__vector_3, @function
__vector_3:
	push __zero_reg__
	push r0
	in r0,__SREG__
	push r0
	clr __zero_reg__
	push r24
/* prologue: Signal */
/* frame size = 0 */
	in r24,78-32
	ori r24,lo8(5)
	out 78-32,r24
/* epilogue start */
	pop r24
	pop r0
	out __SREG__,r0
	pop r0
	pop __zero_reg__
	reti
	.size	__vector_3, .-__vector_3
.global	handle_adjustment_buttons
	.type	handle_adjustment_buttons, @function
handle_adjustment_buttons:
/* prologue: function */
/* frame size = 0 */
	sbic 54-32,1
	rjmp .L41
	lds r24,hours
	cpi r24,lo8(24)
	brsh .L60
	subi r24,lo8(-(1))
	sts hours,r24
	rjmp .L60
.L43:
	call display_on_segment
.L60:
	sbis 54-32,1
	rjmp .L43
.L41:
	sbic 54-32,0
	rjmp .L44
	lds r24,hours
	tst r24
	breq .L61
	subi r24,lo8(-(-1))
	sts hours,r24
	rjmp .L61
.L46:
	call display_on_segment
.L61:
	sbis 54-32,0
	rjmp .L46
.L44:
	sbic 54-32,4
	rjmp .L47
	lds r24,minutes
	cpi r24,lo8(60)
	brsh .L62
	subi r24,lo8(-(1))
	sts minutes,r24
	rjmp .L62
.L49:
	call display_on_segment
.L62:
	sbis 54-32,4
	rjmp .L49
.L47:
	sbic 54-32,3
	rjmp .L50
	lds r24,minutes
	tst r24
	breq .L63
	subi r24,lo8(-(-1))
	sts minutes,r24
	rjmp .L63
.L52:
	call display_on_segment
.L63:
	sbis 54-32,3
	rjmp .L52
.L50:
	sbic 54-32,6
	rjmp .L53
	lds r24,seconds
	cpi r24,lo8(60)
	brsh .L64
	subi r24,lo8(-(1))
	sts seconds,r24
	rjmp .L64
.L55:
	call display_on_segment
.L64:
	sbis 54-32,6
	rjmp .L55
.L53:
	sbic 54-32,5
	rjmp .L59
	lds r24,seconds
	tst r24
	breq .L65
	subi r24,lo8(-(-1))
	sts seconds,r24
	rjmp .L65
.L58:
	call display_on_segment
.L65:
	sbis 54-32,5
	rjmp .L58
.L59:
	ret
	.size	handle_adjustment_buttons, .-handle_adjustment_buttons
.global	main
	.type	main, @function
main:
/* prologue: function */
/* frame size = 0 */
	call init_io
	in r24,__SREG__
	ori r24,lo8(-128)
	out __SREG__,r24
	out (76)+1-32,__zero_reg__
	out 76-32,__zero_reg__
	ldi r24,lo8(13)
	out 78-32,r24
	ldi r24,lo8(15624)
	ldi r25,hi8(15624)
	out (74)+1-32,r25
	out 74-32,r24
	in r24,89-32
	ori r24,lo8(16)
	out 89-32,r24
	call INT0_init
	in r24,85-32
	ori r24,lo8(12)
	out 85-32,r24
	in r24,91-32
	ori r24,lo8(-128)
	out 91-32,r24
	in r24,84-32
	andi r24,lo8(-65)
	out 84-32,r24
	in r24,91-32
	ori r24,lo8(32)
	out 91-32,r24
.L67:
	call check_mode
	call display_on_segment
	call handle_adjustment_buttons
	rjmp .L67
	.size	main, .-main
.global	seconds
.global	seconds
	.section .bss
	.type	seconds, @object
	.size	seconds, 1
seconds:
	.skip 1,0
.global	minutes
.global	minutes
	.type	minutes, @object
	.size	minutes, 1
minutes:
	.skip 1,0
.global	hours
.global	hours
	.type	hours, @object
	.size	hours, 1
hours:
	.skip 1,0
.global	seconds_units
.global	seconds_units
	.type	seconds_units, @object
	.size	seconds_units, 1
seconds_units:
	.skip 1,0
.global	seconds_tenth
.global	seconds_tenth
	.type	seconds_tenth, @object
	.size	seconds_tenth, 1
seconds_tenth:
	.skip 1,0
.global	minutes_units
.global	minutes_units
	.type	minutes_units, @object
	.size	minutes_units, 1
minutes_units:
	.skip 1,0
.global	minutes_tenth
.global	minutes_tenth
	.type	minutes_tenth, @object
	.size	minutes_tenth, 1
minutes_tenth:
	.skip 1,0
.global	hours_units
.global	hours_units
	.type	hours_units, @object
	.size	hours_units, 1
hours_units:
	.skip 1,0
.global	hours_tenth
.global	hours_tenth
	.type	hours_tenth, @object
	.size	hours_tenth, 1
hours_tenth:
	.skip 1,0
.global	mode
.global	mode
	.type	mode, @object
	.size	mode, 1
mode:
	.skip 1,0
.global __do_clear_bss
