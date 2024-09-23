/*
============================================================================================
Name        : registers.h
Author      : Eng. Zeyad Hisham
Description : All ATmega32 Registers data types and defintion 
============================================================================================
*/
typedef unsigned char uint8;
typedef unsigned short uint16;


/* Register Data Types */

/*======================*/
/* Data Registers 8-Bit*/
/*======================*/
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} OCR0_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} TCNT0_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} OSCCAL_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} OCDR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} TCNT2_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} OCR2_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} EEARL_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} EEDR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} SPDR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} UDR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} UBRRL_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} TWDR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit0:1;
		uint8 Bit1:1;
		uint8 Bit2:1;
		uint8 Bit3:1;
		uint8 Bit4:1;
		uint8 Bit5:1;
		uint8 Bit6:1;
		uint8 Bit7:1;
	} Bits;
} TWBR_Type;
/*======================*/
/* Data Registers 16-Bit*/
/*======================*/
typedef union {
	uint16 TwoBytes;
	struct{
		uint16 Bit0:1;
		uint16 Bit1:1;
		uint16 Bit2:1;
		uint16 Bit3:1;
		uint16 Bit4:1;
		uint16 Bit5:1;
		uint16 Bit6:1;
		uint16 Bit7:1;
		uint16 Bit8:1;
		uint16 Bit9:1;
		uint16 Bit10:1;
		uint16 Bit11:1;
		uint16 Bit12:1;
		uint16 Bit13:1;
		uint16 Bit14:1;
		uint16 Bit15:1;
	} Bits;
} TCNT1_Type;
typedef union {
	uint16 TwoBytes;
	struct{
		uint16 Bit0:1;
		uint16 Bit1:1;
		uint16 Bit2:1;
		uint16 Bit3:1;
		uint16 Bit4:1;
		uint16 Bit5:1;
		uint16 Bit6:1;
		uint16 Bit7:1;
		uint16 Bit8:1;
		uint16 Bit9:1;
		uint16 Bit10:1;
		uint16 Bit11:1;
		uint16 Bit12:1;
		uint16 Bit13:1;
		uint16 Bit14:1;
		uint16 Bit15:1;
	} Bits;
} OCR1A_Type;
typedef union {
	uint16 TwoBytes;
	struct{
		uint16 Bit0:1;
		uint16 Bit1:1;
		uint16 Bit2:1;
		uint16 Bit3:1;
		uint16 Bit4:1;
		uint16 Bit5:1;
		uint16 Bit6:1;
		uint16 Bit7:1;
		uint16 Bit8:1;
		uint16 Bit9:1;
		uint16 Bit10:1;
		uint16 Bit11:1;
		uint16 Bit12:1;
		uint16 Bit13:1;
		uint16 Bit14:1;
		uint16 Bit15:1;
	} Bits;
} OCR1B_Type;
typedef union {
	uint16 TwoBytes;
	struct{
		uint16 Bit0:1;
		uint16 Bit1:1;
		uint16 Bit2:1;
		uint16 Bit3:1;
		uint16 Bit4:1;
		uint16 Bit5:1;
		uint16 Bit6:1;
		uint16 Bit7:1;
		uint16 Bit8:1;
		uint16 Bit9:1;
		uint16 Bit10:1;
		uint16 Bit11:1;
		uint16 Bit12:1;
		uint16 Bit13:1;
		uint16 Bit14:1;
		uint16 Bit15:1;
	} Bits;
} ICR1_Type;
typedef union {
	uint16 TwoBytes;
	struct{
		uint16 Bit0:1;
		uint16 Bit1:1;
		uint16 Bit2:1;
		uint16 Bit3:1;
		uint16 Bit4:1;
		uint16 Bit5:1;
		uint16 Bit6:1;
		uint16 Bit7:1;
		uint16 Bit8:1;
		uint16 Bit9:1;
		uint16 Bit10:1;
		uint16 Bit11:1;
		uint16 Bit12:1;
		uint16 Bit13:1;
		uint16 Bit14:1;
		uint16 Bit15:1;
	} Bits;
} ADC_Type;
/*======================*/
/*   Control Registers  */
/*======================*/
typedef union {
	uint8 Byte;
	struct{
		uint8 I_Bit:1;
		uint8 T_Bit:1;
		uint8 H_Bit:1;
		uint8 S_Bit:1;
		uint8 V_Bit:1;
		uint8 N_Bit:1;
		uint8 Z_Bit:1;
		uint8 C_Bit:1;
	} Bits;
} SREG_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 SP11_Bit:1;
		uint8 SP10_Bit:1;
		uint8 SP9_Bit:1;
		uint8 SP8_Bit:1;
	} Bits;
} SPH_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 SP7_Bit:1;
		uint8 SP6_Bit:1;
		uint8 SP5_Bit:1;
		uint8 SP4_Bit:1;
		uint8 SP3_Bit:1;
		uint8 SP2_Bit:1;
		uint8 SP1_Bit:1;
		uint8 SP0_Bit:1;
	} Bits;
} SPL_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 INT1_Bit:1;
		uint8 INT0_Bit:1;
		uint8 INT2_Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 IVSEL_Bit:1;
		uint8 IVCE_Bit:1;
	} Bits;
} GICR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 INTF1_Bit:1;
		uint8 INTF0_Bit:1;
		uint8 INTF2_Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
	} Bits;
} GIFR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 OCIE2_Bit:1;
		uint8 TOIE2_Bit:1;
		uint8 TICIE1_Bit:1;
		uint8 OCIE1A_Bit:1;
		uint8 OCIE1B_Bit:1;
		uint8 TOIE1_Bit:1;
		uint8 OCIE0_Bit:1;
		uint8 TOIE0_Bit:1;
	} Bits;
} TIMSK_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 OCF2_Bit:1;
		uint8 TOV2_Bit:1;
		uint8 ICF1_Bit:1;
		uint8 OCF1A_Bit:1;
		uint8 OCF1B_Bit:1;
		uint8 TOV1_Bit:1;
		uint8 OCF0_Bit:1;
		uint8 TOV0_Bit:1;
	} Bits;
} TIFR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 SPMIE_Bit:1;
		uint8 RWWSB_Bit:1;
		uint8 Bit:1;
		uint8 RWWSRE_Bit:1;
		uint8 BLBSET_Bit:1;
		uint8 PGWRT_Bit:1;
		uint8 PGERS_Bit:1;
		uint8 SPMEN_Bit:1;
	} Bits;
} SPMCR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 TWINT_Bit:1;
		uint8 TWEA_Bit:1;
		uint8 TWSTA_Bit:1;
		uint8 TWSTO_Bit:1;
		uint8 TWWC_Bit:1;
		uint8 TWEN_Bit:1;
		uint8 Bit:1;
		uint8 TWIE_Bit:1;
	} Bits;
} TWCR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 SE_Bit:1;
		uint8 SM2_Bit:1;
		uint8 SM1_Bit:1;
		uint8 SM0_Bit:1;
		uint8 ISC11_Bit:1;
		uint8 ISC10_Bit:1;
		uint8 ISC01_Bit:1;
		uint8 ISC00_Bit:1;
	} Bits;
} MCUCR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 JTD_Bit:1;
		uint8 ISC2_Bit:1;
		uint8 Bit:1;
		uint8 JTRF_Bit:1;
		uint8 WDRF_Bit:1;
		uint8 BORF_Bit:1;
		uint8 EXTRF_Bit:1;
		uint8 PORF_Bit:1;
	} Bits;
} MCUCSR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 FOC0_Bit:1;
		uint8 WGM00_Bit:1;
		uint8 COM01_Bit:1;
		uint8 COM00_Bit:1;
		uint8 WGM01_Bit:1;
		uint8 CS02_Bit:1;
		uint8 CS01_Bit:1;
		uint8 CS00_Bit:1;
	} Bits;
} TCCR0_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 ADTS2_Bit:1;
		uint8 ADTS1_Bit:1;
		uint8 ADTS0_Bit:1;
		uint8 Bit:1;
		uint8 ACME_Bit:1;
		uint8 PUD_Bit:1;
		uint8 PSR2_Bit:1;
		uint8 PSR10_Bit:1;
	} Bits;
} SFIOR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 COM1A1_Bit:1;
		uint8 COM1A0_Bit:1;
		uint8 COM1B1_Bit:1;
		uint8 COM1B0_Bit:1;
		uint8 FOC1A_Bit:1;
		uint8 FOC1B_Bit:1;
		uint8 WGM11_Bit:1;
		uint8 WGM10_Bit:1;
	} Bits;
} TCCR1A_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 ICNC1_Bit:1;
		uint8 ICES1_Bit:1;
		uint8 Bit:1;
		uint8 WGM13_Bit:1;
		uint8 WGM12_Bit:1;
		uint8 CS12_Bit:1;
		uint8 CS11_Bit:1;
		uint8 CS10_Bit:1;
	} Bits;
} TCCR1B_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 FOC2_Bit:1;
		uint8 WGM20_Bit:1;
		uint8 COM21_Bit:1;
		uint8 COM20_Bit:1;
		uint8 WGM21_Bit:1;
		uint8 CS22_Bit:1;
		uint8 CS21_Bit:1;
		uint8 CS20_Bit:1;
	} Bits;
} TCCR2_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 AS2_Bit:1;
		uint8 TCN2UB_Bit:1;
		uint8 OCR2UB_Bit:1;
		uint8 TCR2UB_Bit:1;
	} Bits;
} ASSR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 WDTOE_Bit:1;
		uint8 WDE_Bit:1;
		uint8 WDP2_Bit:1;
		uint8 WDP1_Bit:1;
		uint8 WDP0_Bit:1;
	} Bits;
} WDTCR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 URSEL_Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 UBRR118_Bit:1;
	} Bits;
} UBRRH_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 URSEL_Bit:1;
		uint8 UMSEL_Bit:1;
		uint8 UPM1_Bit:1;
		uint8 UPM0_Bit:1;
		uint8 USBS_Bit:1;
		uint8 UCSZ1_Bit:1;
		uint8 UCSZ0_Bit:1;
		uint8 UCPOL_Bit:1;
	} Bits;
} UCSRC_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 EEAR9_Bit:1;
		uint8 EEAR8_Bit:1;
	} Bits;
} EEARH_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 EERIE_Bit:1;
		uint8 EEMWE_Bit:1;
		uint8 EEWE_Bit:1;
		uint8 EERE_Bit:1;
	} Bits;
} EECR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PORTA7_Bit:1;
		uint8 PORTA6_Bit:1;
		uint8 PORTA5_Bit:1;
		uint8 PORTA4_Bit:1;
		uint8 PORTA3_Bit:1;
		uint8 PORTA2_Bit:1;
		uint8 PORTA1_Bit:1;
		uint8 PORTA0_Bit:1;
	} Bits;
} PORTA_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 DDA7_Bit:1;
		uint8 DDA6_Bit:1;
		uint8 DDA5_Bit:1;
		uint8 DDA4_Bit:1;
		uint8 DDA3_Bit:1;
		uint8 DDA2_Bit:1;
		uint8 DDA1_Bit:1;
		uint8 DDA0_Bit:1;
	} Bits;
} DDRA_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PINA7_Bit:1;
		uint8 PINA6_Bit:1;
		uint8 PINA5_Bit:1;
		uint8 PINA4_Bit:1;
		uint8 PINA3_Bit:1;
		uint8 PINA2_Bit:1;
		uint8 PINA1_Bit:1;
		uint8 PINA0_Bit:1;
	} Bits;
} PINA_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PORTB7_Bit:1;
		uint8 PORTB6_Bit:1;
		uint8 PORTB5_Bit:1;
		uint8 PORTB4_Bit:1;
		uint8 PORTB3_Bit:1;
		uint8 PORTB2_Bit:1;
		uint8 PORTB1_Bit:1;
		uint8 PORTB0_Bit:1;
	} Bits;
} PORTB_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 DDB7_Bit:1;
		uint8 DDB6_Bit:1;
		uint8 DDB5_Bit:1;
		uint8 DDB4_Bit:1;
		uint8 DDB3_Bit:1;
		uint8 DDB2_Bit:1;
		uint8 DDB1_Bit:1;
		uint8 DDB0_Bit:1;
	} Bits;
} DDRB_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PINB7_Bit:1;
		uint8 PINB6_Bit:1;
		uint8 PINB5_Bit:1;
		uint8 PINB4_Bit:1;
		uint8 PINB3_Bit:1;
		uint8 PINB2_Bit:1;
		uint8 PINB1_Bit:1;
		uint8 PINB0_Bit:1;
	} Bits;
} PINB_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PORTC7_Bit:1;
		uint8 PORTC6_Bit:1;
		uint8 PORTC5_Bit:1;
		uint8 PORTC4_Bit:1;
		uint8 PORTC3_Bit:1;
		uint8 PORTC2_Bit:1;
		uint8 PORTC1_Bit:1;
		uint8 PORTC0_Bit:1;
	} Bits;
} PORTC_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 DDC7_Bit:1;
		uint8 DDC6_Bit:1;
		uint8 DDC5_Bit:1;
		uint8 DDC4_Bit:1;
		uint8 DDC3_Bit:1;
		uint8 DDC2_Bit:1;
		uint8 DDC1_Bit:1;
		uint8 DDC0_Bit:1;
	} Bits;
} DDRC_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PINC7_Bit:1;
		uint8 PINC6_Bit:1;
		uint8 PINC5_Bit:1;
		uint8 PINC4_Bit:1;
		uint8 PINC3_Bit:1;
		uint8 PINC2_Bit:1;
		uint8 PINC1_Bit:1;
		uint8 PINC0_Bit:1;
	} Bits;
} PINC_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PORTD7_Bit:1;
		uint8 PORTD6_Bit:1;
		uint8 PORTD5_Bit:1;
		uint8 PORTD4_Bit:1;
		uint8 PORTD3_Bit:1;
		uint8 PORTD2_Bit:1;
		uint8 PORTD1_Bit:1;
		uint8 PORTD0_Bit:1;
	} Bits;
} PORTD_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 DDD7_Bit:1;
		uint8 DDD6_Bit:1;
		uint8 DDD5_Bit:1;
		uint8 DDD4_Bit:1;
		uint8 DDD3_Bit:1;
		uint8 DDD2_Bit:1;
		uint8 DDD1_Bit:1;
		uint8 DDD0_Bit:1;
	} Bits;
} DDRD_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 PIND7_Bit:1;
		uint8 PIND6_Bit:1;
		uint8 PIND5_Bit:1;
		uint8 PIND4_Bit:1;
		uint8 PIND3_Bit:1;
		uint8 PIND2_Bit:1;
		uint8 PIND1_Bit:1;
		uint8 PIND0_Bit:1;
	} Bits;
} PIND_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 SPIF_Bit:1;
		uint8 WCOL_Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 Bit:1;
		uint8 SPI2X_Bit:1;
	} Bits;
} SPSR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 SPIE_Bit:1;
		uint8 SPE_Bit:1;
		uint8 DORD_Bit:1;
		uint8 MSTR_Bit:1;
		uint8 CPOL_Bit:1;
		uint8 CPHA_Bit:1;
		uint8 SPR1_Bit:1;
		uint8 SPR0_Bit:1;
	} Bits;
} SPCR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 RXC_Bit:1;
		uint8 TXC_Bit:1;
		uint8 UDRE_Bit:1;
		uint8 FE_Bit:1;
		uint8 DOR_Bit:1;
		uint8 PE_Bit:1;
		uint8 U2X_Bit:1;
		uint8 MPCM_Bit:1;
	} Bits;
} UCSRA_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 RXCIE_Bit:1;
		uint8 TXCIE_Bit:1;
		uint8 UDRIE_Bit:1;
		uint8 RXEN_Bit:1;
		uint8 TXEN_Bit:1;
		uint8 UCSZ2_Bit:1;
		uint8 RXB8_Bit:1;
		uint8 TXB8_Bit:1;
	} Bits;
} UCSRB_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 ACD_Bit:1;
		uint8 ACBG_Bit:1;
		uint8 ACO_Bit:1;
		uint8 ACI_Bit:1;
		uint8 ACIE_Bit:1;
		uint8 ACIC_Bit:1;
		uint8 ACIS1_Bit:1;
		uint8 ACIS0_Bit:1;
	} Bits;
} ACSR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 REFS1_Bit:1;
		uint8 REFS0_Bit:1;
		uint8 ADLAR_Bit:1;
		uint8 MUX4_Bit:1;
		uint8 MUX3_Bit:1;
		uint8 MUX2_Bit:1;
		uint8 MUX1_Bit:1;
		uint8 MUX0_Bit:1;
	} Bits;
} ADMUX_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 ADEN_Bit:1;
		uint8 ADSC_Bit:1;
		uint8 ADATE_Bit:1;
		uint8 ADIF_Bit:1;
		uint8 ADIE_Bit:1;
		uint8 ADPS2_Bit:1;
		uint8 ADPS1_Bit:1;
		uint8 ADPS0_Bit:1;
	} Bits;
} ADCSRA_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 TWA6_Bit:1;
		uint8 TWA5_Bit:1;
		uint8 TWA4_Bit:1;
		uint8 TWA3_Bit:1;
		uint8 TWA2_Bit:1;
		uint8 TWA1_Bit:1;
		uint8 TWA0_Bit:1;
		uint8 TWGCE_Bit:1;
	} Bits;
} TWAR_Type;
typedef union {
	uint8 Byte;
	struct{
		uint8 TWS7_Bit:1;
		uint8 TWS6_Bit:1;
		uint8 TWS5_Bit:1;
		uint8 TWS4_Bit:1;
		uint8 TWS3_Bit:1;
		uint8 Bit:1;
		uint8 TWPS1_Bit:1;
		uint8 TWPS0_Bit:1;
	} Bits;
} TWSR_Type;


/* Registers Difintions */

/*====================================*/
/*====================================*/
/* Definitions of Data Registers 8-Bit*/
/*====================================*/
#define OCR0_REG (*(volatile OCR0_Type*)0x5C)
#define TCNT0_REG (*(volatile TCNT0_Type*)0x52)
#define OSCCAL_REG (*(volatile OSCCAL_Type*)0x51)
#define OCDR_REG (*(volatile OCDR_Type*)0x51)
#define TCNT2_REG (*(volatile TCNT2_Type*)0x44)
#define OCR2_REG (*(volatile OCR2_Type*)0x43)
#define EEARL_REG (*(volatile EEARL_Type*)0x3E)
#define EEDR_REG (*(volatile EEDR_Type*)0x3D)
#define SPDR_REG (*(volatile SPDR_Type*)0x2F)
#define UDR_REG (*(volatile UDR_Type*)0x2C)
#define UBRRL_REG (*(volatile UBRRL_Type*)0x29)
#define TWDR_REG (*(volatile TWDR_Type*)0x23)
#define TWBR_REG (*(volatile TWBR_Type*)0x20)
/*=====================================*/
/* Definitions of Data Registers 16-Bit*/
/*=====================================*/
#define TCNT1_REG (*(volatile TCNT1_Type*)0x4C)
#define OCR1A_REG (*(volatile OCR1A_Type*)0x4A)
#define OCR1B_REG (*(volatile OCR1B_Type*)0x48)
#define ICR1_REG (*(volatile ICR1_Type*)0x46)
#define ADC_REG (*(volatile ADC_Type*)0x24)
/*==================================*/
/* Definitions of Control Registers */
/*==================================*/
#define SREG_REG (*(volatile SREG_Type*)0x5F)
#define SPH_REG (*(volatile SPH_Type*)0x5E)
#define SPL_REG (*(volatile SPL_Type*)0x5D)
#define GICR_REG (*(volatile GICR_Type*)0x5B)
#define GIFR_REG (*(volatile GIFR_Type*)0x5A)
#define TIMSK_REG (*(volatile TIMSK_Type*)0x59)
#define TIFR_REG (*(volatile TIFR_Type*)0x58)
#define SPMCR_REG (*(volatile SPMCR_Type*)0x57)
#define TWCR_REG (*(volatile TWCR_Type*)0x56)
#define MCUCR_REG (*(volatile MCUCR_Type*)0x55)
#define MCUCSR_REG (*(volatile MCUCSR_Type*)0x54)
#define TCCR0_REG (*(volatile TCCR0_Type*)0x53)
#define SFIOR_REG (*(volatile SFIOR_Type*)0x50)
#define TCCR1A_REG (*(volatile TCCR1A_Type*)0x4F)
#define TCCR1B_REG (*(volatile TCCR1B_Type*)0x4E)
#define TCCR2_REG (*(volatile TCCR2_Type*)0x45)
#define ASSR_REG (*(volatile ASSR_Type*)0x42)
#define WDTCR_REG (*(volatile WDTCR_Type*)0x41)
#define UBRRH_REG (*(volatile UBRRH_Type*)0x40)
#define UCSRC_REG (*(volatile UCSRC_Type*)0x40)
#define EEARH_REG (*(volatile EEARH_Type*)0x3F)
#define EECR_REG (*(volatile EECR_Type*)0x3C)
#define PORTA_REG (*(volatile PORTA_Type*)0x3B)
#define DDRA_REG (*(volatile DDRA_Type*)0x3A)
#define PINA_REG (*(volatile PINA_Type*)0x39)
#define PORTB_REG (*(volatile PORTB_Type*)0x38)
#define DDRB_REG (*(volatile DDRB_Type*)0x37)
#define PINB_REG (*(volatile PINB_Type*)0x36)
#define PORTC_REG (*(volatile PORTC_Type*)0x35)
#define DDRC_REG (*(volatile DDRC_Type*)0x34)
#define PINC_REG (*(volatile PINC_Type*)0x33)
#define PORTD_REG (*(volatile PORTD_Type*)0x32)
#define DDRD_REG (*(volatile DDRD_Type*)0x31)
#define PIND_REG (*(volatile PIND_Type*)0x30)
#define SPSR_REG (*(volatile SPSR_Type*)0x2E)
#define SPCR_REG (*(volatile SPCR_Type*)0x2D)
#define UCSRA_REG (*(volatile UCSRA_Type*)0x2B)
#define UCSRB_REG (*(volatile UCSRB_Type*)0x2A)
#define ACSR_REG (*(volatile ACSR_Type*)0x28)
#define ADMUX_REG (*(volatile ADMUX_Type*)0x27)
#define ADCSRA_REG (*(volatile ADCSRA_Type*)0x26)
#define TWAR_REG (*(volatile TWAR_Type*)0x22)
#define TWSR_REG (*(volatile TWSR_Type*)0x21)
