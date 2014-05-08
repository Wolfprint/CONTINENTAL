/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
 * C Source:        appChar.c
 * version:         1.0 
 * created_by:      Antonio Altamirano  
 * date_created:    April 26 2014 
 *=============================================================================*/
/* DESCRIPTION : C source for uart0 processing charater driver.               */
/*============================================================================*/

/* Includes */
/* -------- */
#include "appChar.h"
#include "RxFormat.h"

/**************************************************************
 *  Name                 : str_ctrl
 *  Description          : main character processing routine.                      .                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void str_ctrl() {
    rs_ctrlFlag.checksum = 0;
	if (!rs_ctrlFlag.sbf) {
		
		if(FORMAT==BINARY){		
		CharProcess();		
		} else {
		NibbleProcess();
		}
		checksum();
		if (!rs_ctrlFlag.checksum) {
			stopBit();
			Output_selection();
			infoBits();
		} else {
			//assign the right error value to print the error message!
			infoBits();			
		}
	} else {
		//do nothing

	}
}

/**************************************************************
 *  Name                 : print_str
 *  Description          : prints the current values of the 
 *                         string typed                                
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void print_str() {
	if (!rs_ctrlFlag.sbf) {
		put("\r\n| ");
		out_char(rs_charVal.bit7 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit6 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit5 | 0x30);
		out_char(rs_charVal.bit4 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit3 | 0x30);
		out_char(rs_charVal.bit2 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit1 | 0x30);
		out_char(rs_charVal.bit0 | 0x30);
		put(" | \r\n");
	} else {
		//do nothing
	}
}

/**************************************************************
 *  Name                 : print_response
 *  Description          : prints the result of the character
 *                         process                                 
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void print_response() {
	if (!rs_ctrlFlag.sbf) {
		put("\r\n| IF | SE | IS | LS |");
		put("\r\n| ");
		out_char(rs_ctrlFlag.inf1 | 0x30);
		out_char(rs_ctrlFlag.inf0 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit3 | 0x30);
		out_char(rs_charVal.bit2 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit1 | 0x30);
		out_char(rs_charVal.bit0 | 0x30);
		put(" | ");
		out_char(rs_charVal.bit5 | 0x30);
		out_char(rs_charVal.bit4 | 0x30);
		put(" |\r\n");
	} else {
		//do nothing
	}
}
