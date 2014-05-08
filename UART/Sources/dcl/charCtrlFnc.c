/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        charCtrlFnc.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION : C source for uart0 processing charater driver.               */                            
/*============================================================================*/

/* Includes */
/* -------- */
#include "charCtrlFnc.h"

/**************************************************************
 *  Name                 : char_comp
 *  Description          : Wait for a character to be received 
 *                         on the specified UART and process it.                      .                         
 *  Parameters           : lub_char, lub_charNumber
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void char_comp(T_UBYTE lub_char, T_UBYTE lub_charNumber) {
	T_UBYTE lub_charVal = 0; // contains the future value of the current char

	if (lub_char == '1') {
		lub_charVal = 1;
	} else {
		lub_charVal = 0;
	}

	switch (lub_charNumber) {
	case 1:
		rs_charVal.bit6 = lub_charVal;
		break;
	case 2:
		rs_charVal.bit5 = lub_charVal;
		break;
	case 3:
		rs_charVal.bit4 = lub_charVal;
		break;
	case 4:
		rs_charVal.bit3 = lub_charVal;
		break;
	case 5:
		rs_charVal.bit2 = lub_charVal;
		break;
	case 6:
		rs_charVal.bit1 = lub_charVal;
		break;
	case 7:
		rs_charVal.bit0 = lub_charVal;
		break;
	default:
		break;
	}
}

/**************************************************************
 *  Name                 : ignition
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void ignition() {
	if (!rs_charVal.bit1 && !rs_charVal.bit0) {
		// 00 Off
		re_ignStatus = IS_OFF;
	} else if (!rs_charVal.bit1 && rs_charVal.bit0) {
		// 01 ACC
		re_ignStatus = IS_ACC;
	} else if (rs_charVal.bit1 && !rs_charVal.bit0) {
		// 10 Run
		re_ignStatus = IS_RUN;
	} else {
		// 11 Start
		re_ignStatus = IS_START;
	}
}

/**************************************************************
 *  Name                 : selector
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void selector() {
	if ((!rs_charVal.bit3 && !rs_charVal.bit2) & (re_ignStatus==IS_OFF || re_ignStatus==IS_ACC || re_ignStatus==IS_RUN || re_ignStatus==IS_START)) {
		// 00 Off
		re_selStatus = SEL_OFF;
	} else if ((!rs_charVal.bit3 && rs_charVal.bit2) & (re_ignStatus==IS_OFF || re_ignStatus==IS_ACC || re_ignStatus==IS_RUN || re_ignStatus==IS_START)) {
		// 01 Auto
		re_selStatus = SEL_AUTO;
	} else if ((rs_charVal.bit3 && !rs_charVal.bit2) & (re_ignStatus==IS_OFF || re_ignStatus==IS_ACC || re_ignStatus==IS_RUN || re_ignStatus==IS_START)) {
		// 10 ParkLamps
		re_selStatus = SEL_PL;
	} else if ((rs_charVal.bit3 && rs_charVal.bit2) & (re_ignStatus==IS_RUN || re_ignStatus==IS_START)){
		// 11 HeadLamps
		re_selStatus = SEL_HL;
	} else {
		//do nothing
		//re_selStatus= SEL_OFF;
	}
}

/**************************************************************
 *  Name                 : light_sensor
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void lightSensor() {
	if (re_selStatus == SEL_OFF){
		re_sensorStatus=LS_HIGH;
		es_ctrlFlag.errAdc=0;
	} else if (re_selStatus == SEL_AUTO) {
	
		if ((!rs_charVal.bit5 && !rs_charVal.bit4)
				& (re_ignStatus ==IS_OFF || re_ignStatus ==IS_ACC || re_ignStatus ==IS_RUN || re_ignStatus ==IS_START)) {
			// 00 invalid
			es_ctrlFlag.errAdc=1;
			re_sensorStatus = LS_INV;
		} else if ((!rs_charVal.bit5 && rs_charVal.bit4)
				& (re_ignStatus ==IS_OFF || re_ignStatus ==IS_ACC || re_ignStatus ==IS_RUN || re_ignStatus ==IS_START)) {
			// 01 >0% sensor <40%
			re_sensorStatus = LS_LOW;
		} else if ((rs_charVal.bit5 && !rs_charVal.bit4)
				& (re_ignStatus ==IS_RUN || re_ignStatus ==IS_START)) {
			// 10 >40% sensor <80%
			re_sensorStatus = LS_MED;
		} else if ((rs_charVal.bit5 && rs_charVal.bit4)
				& (re_ignStatus ==IS_RUN || re_ignStatus ==IS_START)) {
			// 11 80% < sensor
			re_sensorStatus = LS_HIGH;
		} else {
			//do nothing
		}
	} else if (re_selStatus == SEL_PL){
		re_sensorStatus = LS_MED;
		es_ctrlFlag.errAdc=0;
	}   else if (re_selStatus == SEL_HL){
		re_sensorStatus = LS_LOW;
		es_ctrlFlag.errAdc=0;
	}  else {
		//do nothing
	}
}

void stopBit() {
	if (rs_charVal.bit6) {
		re_sbStatus = STOP;
		es_ctrlFlag.sbest=0;

	} else {
		re_sbStatus = TxRx;
		es_ctrlFlag.sbest=1;

	}
}

/**************************************************************
 *  Name                 : checksum
 *  Description          : process the add of the bits from the 
 *                         uart0  and check if the add its odd
 *                         or even.                        
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void checksum() {
	T_UBYTE lub_checksum = 0;
	lub_checksum = (rs_charVal.bit0 + rs_charVal.bit1 + rs_charVal.bit2
			+ rs_charVal.bit3 + rs_charVal.bit4 + rs_charVal.bit5
			+ rs_charVal.bit6);
	lub_checksum = lub_checksum & 1;
	if (lub_checksum) {
		rs_charVal.bit7 = 0;
	} else {
		rs_charVal.bit7 = 1;
	}
}

/**************************************************************
 *  Name                 : infoBits
 *  Description          : assigns binary value for information
 *                         status                                 
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void infoBits() {
	if (!es_ctrlFlag.errCh & !es_ctrlFlag.errAdc) {
		es_ctrlFlag.inf1 = 0;
		es_ctrlFlag.inf0 = 0;
		
	} else if ((rs_charVal.bit7 != 0) | (rs_charVal.bit7 != 1)) {
		es_ctrlFlag.inf1 = 0;
		es_ctrlFlag.inf0 = 1;
		es_ctrlFlag.errCh=0;
		es_ctrlFlag.errAdc=0;
	} else if (es_ctrlFlag.sbest) {
		es_ctrlFlag.inf1 = 1;
		es_ctrlFlag.inf0 = 0;
	} else {
		//do nothing
	}
}


/**************************************************************
 *  Name                 : 
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void actuator(){
	ignition();
	switch(re_ignStatus){
	case IS_OFF: selector();
	             lightSensor();
	break;
	case IS_ACC: selector();
	             lightSensor();
	break;
	case IS_RUN: selector();
	             lightSensor();
	break;
	case IS_START: selector();
	             lightSensor();
	break;
	default: break;
	}
}






