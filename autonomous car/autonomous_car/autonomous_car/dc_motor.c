/*
 * dc_motor.c
 *
 * Created: 15-Dec-22 7:53:45 PM
 *  Author: nasser
 */ 

#include "DIO.h"


void dc_motor_vInit(unsigned char port)
{
	DIO_vsetPINDir(port,0,1);
	DIO_vsetPINDir(port,1,1);
	DIO_vsetPINDir(port,2,1);
	DIO_vsetPINDir(port,3,1);
	DIO_vsetPINDir(port,4,1);
	DIO_vsetPINDir(port,5,1);
	
} 

void dc_motor_vEnable(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,1);//Set the given pin in the given port to one(on)
}

void dc_motor_vstart(unsigned char portname,unsigned char direction)
{
	switch (direction)
	{
		
		case 'F':
		DIO_write(portname,0,1);
		DIO_write(portname,1,0);
		/***************** motor 2****************/
		DIO_write(portname,4,1);
		DIO_write(portname,5,0);
		break;
		
		case 'B':
		DIO_write(portname,0,0);
		DIO_write(portname,1,1);
		/***************** motor 2****************/
		DIO_write(portname,4,0);
		DIO_write(portname,5,1);
		break;
	}
	
}

void dc_motor_vstop(unsigned char portname)
{
	
		DIO_write(portname,0,0);//Set the given pin in the given port to one(on)
		DIO_write(portname,1,0);
		/***************** motor 2****************/
		DIO_write(portname,4,0);//Set the given pin in the given port to one(on)
		DIO_write(portname,5,0);
		
	
	
}


