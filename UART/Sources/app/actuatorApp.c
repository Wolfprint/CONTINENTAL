/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        actuatorApp.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION : C source for uart0 processing charater driver.               */                            
/*============================================================================*/

/* Includes */
/* -------- */
#include "actuatorApp.h"

/**************************************************************
 *  Name                 : actionSelector
 *  Description          : determine the action from the main
 *                         character routine                                               
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void actionSelector() {
	
	if(!es_ctrlFlag.sbf){
		/*
	switch (re_selStatus) {
	case SEL_OFF:
		LightsOff();
		put("lights: OFF \r\n");
		break;
	case SEL_AUTO:
		put("Auto mode\r\n");
		break;
	case SEL_PL:
		HalfLight();
		put("Parklights: ON \r\n");
		break;
	case SEL_HL:
		LightsOn();
		put("HeadLights: ON \r\n");
		break;
	default:
		break;
	}*/

	switch (re_sensorStatus) {
	case LS_INV: //invalid
		//put("Invalid \r\n\r\n");
		//es_ctrlFlag.errAdc=1;
		break;
	case LS_LOW:
		LightsOn();
		//put("HeadLights: ON \r\n\r\n");
		es_ctrlFlag.errAdc=0;
		break;
	case LS_MED:
		HalfLight();
		//put("Parklights: ON \r\n\r\n");
		es_ctrlFlag.errAdc=0;
		break;
	case LS_HIGH:
		LightsOff();
		//put("lights: OFF \r\n\r\n");
		es_ctrlFlag.errAdc=0;
		break;
	default:
		break;
	}

	switch (re_sbStatus) {
	case TxRx: //transmitter receiver
		es_ctrlFlag.sbf=0;
		break;
	case STOP:
		put("\r\n| ");
				out_char('1');
				out_char('0');
				put(" | ");
				out_char(rs_charVal.bit3 | 0x30);
				out_char(rs_charVal.bit2 | 0x30);
				put(" | ");
				out_char(rs_charVal.bit1 | 0x30);
				out_char(rs_charVal.bit0 | 0x30);
				put(" | ");
				out_char(rs_charVal.bit5 | 0x30);
				out_char(rs_charVal.bit4 | 0x30);
				put(" | \r\n\r\n");
		//put("TxRx: Disabled \r\n");
		UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
		es_ctrlFlag.sbf=1;
		break;
	default:
		break;
	}
	} else {
		//do nothing
	}
}


