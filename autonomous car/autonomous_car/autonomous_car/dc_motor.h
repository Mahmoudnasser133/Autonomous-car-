/*
 * dc_motor.h
 *
 * Created: 15-Dec-22 7:54:03 PM
 *  Author: nasser
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

void dc_motor_vInit(unsigned char port);
void dc_motor_vEnable(unsigned char portname,unsigned char pinnumber);
void dc_motor_vstart(unsigned char portname,unsigned char direction);
void dc_motor_vstop(unsigned char portname);




#endif /* DC_MOTOR_H_ */