/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        Variables.h
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION :This file contains global variables an control variables      */                     
/*============================================================================*/

#ifndef VARIABLES_H_
#define VARIABLES_H_

#include "stdtypedef.h"

// byte counter to control the bit position
T_UBYTE rub_bitcounter=0;
T_UBYTE rub_checksum=0;

/*enum of the declarations of constants for status
typedef enum{
	//Checksum
	EVEN=0,
	ODD,
	//Stop bit
	STOP_END,
	STOP,
	//Light status
	
	LS_INV,
	LS_LOW,
	LS_MED,
	LS_HIGH,
	//Selector Status
	SEL_OFF,
	SEL_AUTO,
	SEL_PL,
	SEL_HL,
	//Ingnition Status
	IS_OFF,
	IS_ACC,
	IS_RUN,
	IS_START,	
}re_statusbit;

re_statusbit re_status; */

//available bits for control characters and checksum result
/*
typedef struct{
	T_UBYTE bit0:1;
	T_UBYTE bit1:1;
	T_UBYTE bit2:1;
	T_UBYTE bit3:1;
	T_UBYTE bit4:1;
	T_UBYTE bit5:1;
	T_UBYTE bit6:1;
	T_UBYTE bit7:1;
}rs_controlvar;

//variable for bitfield calling
rs_controlvar rs_controlbitfield;
*/
//available bits for flags declaration
typedef struct {
	T_UBYTE rub_checksum:1; 
	T_UBYTE rub_stopbit:1;
	T_UBYTE rub_flag2:1;
	T_UBYTE rub_flag3:1;
	T_UBYTE rub_flag4:1;
	T_UBYTE rub_flag5:1;
	T_UBYTE rub_flag6:1;
	T_UBYTE rub_flag7:1;
}rs_flags; 

//flag variable calling
rs_flags rs_flagbitfield;
#endif /* VARIABLES_H_ */
