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


/**************************************************************
 *  Name                 : str_ctrl
 *  Description          : main character processing routine.                      .                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void str_ctrl() {
	
	if(!es_ctrlFlag.sbf){
	//local variables initialization, when a feedback occurs, clean these variables.
	T_UBYTE lub_charNum = 0; //number of the present character
	T_UBYTE lub_char = 0; //current character
	put("C: CheckSum\r\nS: Stop Bit\r\nLS: Light sensor\r\nSE: Selector status\r\nIS: Ignition status");
		put("\r\n| C | S | LS | SE | IS |");
	/* there will be only 7 bits to process, and starts at the LSB to the MSB,
	 * due the MSB its not an input, there will be only 7 bits available to receive
	 * valid characters.
	 */
	for (lub_charNum = 1; lub_charNum <= 7; lub_charNum++) {
		lub_char = in_char();

		if (lub_char == '1' || lub_char == '0') {
			char_comp(lub_char, lub_charNum);
			es_ctrlFlag.errCh=0;
		} else {
			//prints error text
			put("\r\nInvalid character, only 0 or 1 \r\n");
			es_ctrlFlag.errCh=1;
			/*if the user types a wrong character, the current number of 
			 the char is ignored in order to continue a linearity of 
			 valid characters */
			lub_charNum--;
		}
	}
	actuator();
	stopBit();
	checksum();
	infoBits();
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
	if(!es_ctrlFlag.sbf){	
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
	if (!es_ctrlFlag.sbf) {
		put("\r\n| IF | SE | IS | LS |");
		put("\r\n| ");
		out_char(es_ctrlFlag.inf1 | 0x30);
		out_char(es_ctrlFlag.inf0 | 0x30);
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
	} else {
		//do nothing
	}
}
