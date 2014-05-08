/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        StopBitApp.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION : C source for uart0 stop bit delay                            */                            
/*============================================================================*/

/* Includes */
/* -------- */
#include "StopBitApp.h"



/**************************************************************
 *  Name                 : stopBitDelay
 *  Description          : wait enable, disables TxRx and enables
 *                         after 30 seconds                                
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
T_UWORD ruw_sbCounter=0;
void stopBitDelay(){
	if(es_ctrlFlag.sbf){
		ruw_sbCounter++;
		if(ruw_sbCounter==30){
			//Enable TxRx
			UART0_C2 |= (UART0_C2_TE_MASK
			                    | UART0_C2_RE_MASK );
			es_ctrlFlag.sbf=0;
			ruw_sbCounter=0;
			put("\r\n| ");
					out_char('1');
					out_char('1');
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
			//put("TxRx: Enabled \r\n\r\n");
		} else {
			//do nothing
		}
	} else {
		//do nothing
	}
}

