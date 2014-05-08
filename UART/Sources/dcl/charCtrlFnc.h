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

#include "io.h"
#include "libs.h"
#include "Variables.h"
/*
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

typedef struct {
	T_UBYTE sbf :1;
	T_UBYTE sbest :1;
	T_UBYTE flag2 :1;
	T_UBYTE flag3 :1;
	T_UBYTE errCh :1;
	T_UBYTE errAdc :1;
	T_UBYTE inf0 :1;
	T_UBYTE inf1 :1;
}es_controlFlags;

//ignition status enum 
typedef enum {
	IS_OFF = 0, IS_ACC, IS_RUN, IS_START,
} re_ignitionStatus;


//selector status enum 
typedef enum {
	SEL_OFF=0, SEL_AUTO, SEL_PL, SEL_HL,
} re_selectorStatus;


//light sensor status enum 
typedef enum {
	LS_INV=0, LS_LOW, LS_MED, LS_HIGH,
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


//character calue bit field
rs_controlvar rs_charVal;
//control flags
es_controlFlags es_ctrlFlag;
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

*/

void char_comp(T_UBYTE lub_char, T_UBYTE lub_charNumber);
void CharProcess();
void nibble_comp(T_UBYTE lub_nibble, T_UBYTE lub_nibbleNum);
void NibbleProcess();
T_UBYTE checksum_add();
void checksum();
void stopBit();
void Ignition();
void sel_lightSensor();
void ign_select();
void Output_selection();
void infoBits();

#endif /* CHARCTRLFNC_H_ */
