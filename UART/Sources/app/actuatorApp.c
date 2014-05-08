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

	if (!rs_ctrlFlag.sbf) {
		switch (re_selStatus) {
		case SEL_OFF:
			LightsOff();
			break;
		case SEL_AUTO:
			break;
		case SEL_PL:
			HalfLight();
			break;
		case SEL_LON:
			LightsOn();
			break;
		default:
			break;
		}

		switch (re_sensorStatus) {
		case LS_INV:
			LightsOff();
			break;
		case LS_LOW:
			LightsOn();
			break;
		case LS_MED:
			HalfLight();
			break;
		case LS_HIGH:
			LightsOff();
			break;
		default:
			break;
		}

		switch (re_sbStatus) {
		case TxRx: //transmitter receiver
			rs_ctrlFlag.sbf = 0;
			break;
		case STOP:
			put("| ");
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
			put(" | \r\n");
			//put("TxRx: Disabled \r\n");
			UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);
			rs_ctrlFlag.sbf = 1;
			break;
		default:
			break;
		}
	} else {
		//do nothing
	}
}


