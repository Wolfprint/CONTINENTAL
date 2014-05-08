/*
 * appChar.c
 *
 *  Created on: May 3, 2014
 *      Author: FlatBlock
 */

#include "appChar.h"


/**************************************************************
 *  Name                 : str_ctrl
 *  Description          : main character processing routine.                      .                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void str_ctrl() {
	//local variables initialization, when a feedback occurs, clean these variables.
	T_UBYTE lub_charNum = 0; //number of the present character
	T_UBYTE lub_char = 0; //current character

	/* there will be only 7 bits to process, and starts at the LSB to the MSB,
	 * due the MSB its not an input, there will be only 7 bits available to receive
	 * valid characters.
	 */
	for (lub_charNum = 1; lub_charNum <= 7; lub_charNum++) {
		lub_char = uart0_getchar();

		if (lub_char == '1' || lub_char == '0') {
			char_comp(lub_char, lub_charNum);
		} else {
			//prints error text
			put("\r\nInvalid character, only 0 or 1 \r\n");
			/*if the user types a wrong character, the current number of 
			 the char is ignored in order to continue a linearity of 
			 valid characters */
			lub_charNum--;
		}
	}
	actuator();
	stopBit();
	checksum();
}



/**************************************************************
 *  Name                 : print_str
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void print_str() {
	put("\r\n| ");
	uart0_putchar(rs_charVal.bit7 | 0x30);
	put(" | ");
	uart0_putchar(rs_charVal.bit6 | 0x30);
	put(" | ");
	uart0_putchar(rs_charVal.bit5 | 0x30);
	uart0_putchar(rs_charVal.bit4 | 0x30);
	put(" | ");
	uart0_putchar(rs_charVal.bit3 | 0x30);
	uart0_putchar(rs_charVal.bit2 | 0x30);
	put(" | ");
	uart0_putchar(rs_charVal.bit1 | 0x30);
	uart0_putchar(rs_charVal.bit0 | 0x30);
	put(" | \r\n");
}
