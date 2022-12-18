/*
 * PWM.c
 *
 * Created: 16-Dec-22 7:19:08 AM
 *  Author: nasser
 */ 

#define  F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"

void PWM(unsigned char port, unsigned pin, double value)
{
	
	 
	 if (value==1)
	 {
		value=1;
		
		DIO_vsetPINDir(port,pin,1);
		DIO_write(port,pin,1);
		_delay_ms(value);
		DIO_write(port,pin,0);
		_delay_ms(20-value); 
	 }
	 
	 if (value==1.5)
	 {
		 value=1.5;
		 
		 DIO_vsetPINDir(port,pin,1);
		 DIO_write(port,pin,1);
		 _delay_ms(value);
		 DIO_write(port,pin,0);
		 _delay_ms(20-value);
	 }
	 
	 if (value==2)
	 {
		 value=2;
		 
		 DIO_vsetPINDir(port,pin,1);
		 DIO_write(port,pin,1);
		 _delay_ms(value);
		 DIO_write(port,pin,0);
		 _delay_ms(20-value);
	 }
	 
	 
	 if (value==1.25)
	 {
		 value=1.25;
		 
		 DIO_vsetPINDir(port,pin,1);
		 DIO_write(port,pin,1);
		 _delay_ms(value);
		 DIO_write(port,pin,0);
		 _delay_ms(20-value);
	 }
	 if (value==1.75)
	 {
		 value=1.75;
		 
		 DIO_vsetPINDir(port,pin,1);
		 DIO_write(port,pin,1);
		 _delay_ms(value);
		 DIO_write(port,pin,0);
		 _delay_ms(20-value);
	 }
	
	
}