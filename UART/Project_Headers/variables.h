/*
 * Variables.h
 *
 *  Created on: May 7, 2014
 *      Author: FlatBlock
 */

#ifndef VARIABLES_H_
#define VARIABLES_H_

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
	T_UBYTE checksum :1;
	T_UBYTE Format :1;
	T_UBYTE errCh :1;
	T_UBYTE errAdc :1;
	T_UBYTE inf0 :1;
	T_UBYTE inf1 :1;
} rs_controlFlags;

//ignition status enum 
typedef enum {
	IS_OFF = 0, IS_ACC, IS_RUN, IS_START,
} re_ignitionStatus;

//selector status enum 
typedef enum {
	SEL_OFF = 0, SEL_AUTO, SEL_PL, SEL_LON,
} re_selectorStatus;

//light sensor status enum 
typedef enum {
	LS_INV = 0, LS_LOW, LS_MED, LS_HIGH,
} re_lightSensorStatus;

//stop bit status enum 
typedef enum {
	TxRx = 0, STOP,
} re_stopBitStatus;

//checksum status enum 
typedef enum {
	ODD = 0, EVEN,
} re_checksumStatus;

//character calue bit field
rs_controlvar rs_charVal;
//control flags
rs_controlFlags rs_ctrlFlag;
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

#endif /* VARIABLES_H_ */
