/*
 * autonomous_car.c
 *
 * Created: 15-Dec-22 7:45:23 PM
 *  Author: nasser
 */ 


#include <avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "timer.h"
#include "LED.h"
#include "dc_motor.h"
#include "ultrasonic_sensor.h"
#include "PWM.h"

int main(void)
{
	dc_motor_vInit('A');
	dc_motor_vEnable('A',2);
	dc_motor_vEnable('A',3);
	
	LED_vInit('B',0);
	LED_vInit('B',1);
	unsigned short front_dist, back_dist;


	while(1)
    {
		
		front_dist = dist('C',1);
		_delay_ms(50);
		back_dist = dist('C',0);
		_delay_ms(50);


		if (front_dist< 10 )
		{
			
			dc_motor_vstop('A');
			_delay_ms(1000);
			
			if (back_dist < 10)
			{
				dc_motor_vstop('A');
				
			}
			
			if (back_dist >= 10)
			{
				/***** Move the car backwards ***********/
				dc_motor_vstart('A','B');
				LED_vTurnOn('B',1);
				LED_vTurnOff('B',0);
				_delay_ms(1000);
				dc_motor_vstop('A');
				
				/*********** turn right ****************/
				PWM('C',3,2);
				_delay_ms(1000);
				/***** Move the car forwards then turn left  ***********/
				dc_motor_vstart('A','F');
				LED_vTurnOn('B',0);
				LED_vTurnOff('B',1);
				_delay_ms(1000);
				PWM('C',3,1.5);
				_delay_ms(500);

				
			}
			
			
			
		}		
		
		if (front_dist >= 10)
		{
				/***** Move the car forwards******/
			dc_motor_vstart('A','F');
			LED_vTurnOn('B',0);
		}
	
		

    }




}

