/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        CharCtrlFnc.h
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014  
*=============================================================================*/
/* DESCRIPTION :This file contains the prototyping of character processing    */                     
/*============================================================================*/

#ifndef CHARCTRLFNC_H_
#define CHARCTRLFNC_H_

#include "io_char.h"
//#include "variables.h"

typedef struct {
	T_UBYTE bit0 :1;
	T_UBYTE bit1 :1;
	T_UBYTE bit2 :1;
	T_UBYTE bit3 :1;
	T_UBYTE bit4 :1;
	T_UBYTE bit5 :1;
	T_UBYTE bit6 :1;
	T_UBYTE bit7 :1;
} rs_controlvar;


//ignition status enum 
typedef enum {
	IS_OFF = 0, IS_ACC, IS_RUN, IS_START,
} re_ignitionStatus;


//selector status enum 
typedef enum {
	SEL_OFF, SEL_AUTO, SEL_PL, SEL_HL,
} re_selectorStatus;


//light sensor status enum 
typedef enum {
	LS_INV, LS_LOW, LS_MED, LS_HIGH,
} re_lightSensorStatus;


//stop bit status enum 
typedef enum {
	TxRx=0,
	STOP,
}re_stopBitStatus;

//checksum status enum 
typedef enum{
	ODD=0,
	EVEN,
}re_checksumStatus;

rs_controlvar rs_charVal;
// enum ignition status variable
re_ignitionStatus re_ignStatus;
// enum selector status variable
re_selectorStatus re_selStatus;
// enum light sensor status variable
re_lightSensorStatus re_sensorStatus;
// enum stop bit status variable
re_stopBitStatus re_sbStatus;
// enum checksum status variable
re_checksumStatus re_checksum;

void str_ctrl();
void char_comp(T_UBYTE lub_char, T_UBYTE lub_charNumber);
void ignition();
void selector();
void lightSensor();
void stopBit();
void checksum();
void actuator();
void print_str();

#endif /* CHARCTRLFNC_H_ */
