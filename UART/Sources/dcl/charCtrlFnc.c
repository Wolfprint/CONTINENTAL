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
/*============================================================================*
* Modifications : case 0 on switch in char_comp
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/

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
	case 0:
		rs_charVal.bit7 = lub_charVal;
		break;
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

void CharProcess() {
	//local variables initialization, when a feedback occurs, clean these variables.
	T_UBYTE lub_charNum = 0; //number of the present character
	T_UBYTE lub_char = 0; //current character
	put("\r\n--Rx binary format--\r\nC: CheckSum\r\nS: Stop Bit\r\nLS: Light sensor\r\nSE: Selector status\r\nIS: Ignition status");
	put("\r\n| C | S | LS | SE | IS |");
	/* there will be only 7 bits to process, and starts at the LSB to the MSB,
	 * due the MSB its not an input, there will be only 7 bits available to receive
	 * valid characters.
	 */
	for (lub_charNum = 0; lub_charNum <= 7; lub_charNum++) {
		lub_char = in_char();

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
}



void nibble_comp(T_UBYTE lub_nibble, T_UBYTE lub_nibbleNum){

	if(lub_nibbleNum==0){
	switch(lub_nibble){
	case '0': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 0;
	        break;
	case '1': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 1;
	        break;
	case '2': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 0;
	        break;
	case '3': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 1;
	        break;	 
	case '4': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 0;
	        break;
	case '5': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 1;
	        break;
	case '6': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 0;
	        break;
	case '7': rs_charVal.bit7 = 0;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 1;
	        break;	
	case '8': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 0;
	        break;
	case '9': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 1;
	        break;	   
	case 'A': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 0;
	        break;
	case 'B': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 0;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 1;
	        break;
	case 'C': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 0;
	        break;
	case 'D': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 0;
	          rs_charVal.bit4 = 1;
	        break;
	case 'E': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 0;
	        break;
	case 'F': rs_charVal.bit7 = 1;
	          rs_charVal.bit6 = 1;
	          rs_charVal.bit5 = 1;
	          rs_charVal.bit4 = 1;
	        break;	        
	default: lub_nibbleNum--;
		    break;
	} 
  } else {
	  switch(lub_nibble){
	  	case '0': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case '1': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 1;
	  	        break;
	  	case '2': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case '3': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 1;
	  	        break;	 
	  	case '4': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case '5': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 1;
	  	        break;
	  	case '6': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case '7': rs_charVal.bit3 = 0;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 1;
	  	        break;	
	  	case '8': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case '9': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 1;
	  	        break;	   
	  	case 'A': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case 'B': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 0;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 1;
	  	        break;
	  	case 'C': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case 'D': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 0;
	  	          rs_charVal.bit0 = 1;
	  	        break;
	  	case 'E': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 0;
	  	        break;
	  	case 'F': rs_charVal.bit3 = 1;
	  	          rs_charVal.bit2 = 1;
	  	          rs_charVal.bit1 = 1;
	  	          rs_charVal.bit0 = 1;
	  	        break;	
	  	default: lub_nibbleNum--;
	  	        break;
    }
  }
}
void NibbleProcess() {
//local variables initialization, when a feedback occurs, clean these variables.
T_UBYTE lub_nibbleNum = 0; //number of the present character
T_UBYTE lub_nibble = 0; //current character
    put("\r\n--Rx hexadecimal format--\r\nC: CheckSum\r\nS: Stop Bit\r\nLS: Light sensor\r\nSE: Selector status\r\nIS: Ignition status");
	put("\r\n| C | S | LS | SE | IS |");

    for (lub_nibbleNum = 0; lub_nibbleNum <= 1; lub_nibbleNum++) {
		lub_nibble = in_char();
		nibble_comp(lub_nibble, lub_nibbleNum);
	}
}


/**************************************************************
 *  Name                 : checksum_add
 *  Description          : process the add of the bits from the 
 *                         uart0  and check if the add its odd
 *                         or even.                        
 *  Parameters           : none
 *  Return               : lub_checksum_add
 *  Critical/explanation : no
 **************************************************************/
T_UBYTE checksum_add() {
	T_UBYTE lub_checksum = 0;
	lub_checksum = (rs_charVal.bit0 + rs_charVal.bit1 + rs_charVal.bit2
			+ rs_charVal.bit3 + rs_charVal.bit4 + rs_charVal.bit5
			+ rs_charVal.bit6);
	lub_checksum = lub_checksum & 1;
	if (lub_checksum) {    //if lub_checksum = 1 (odd)
		lub_checksum = 0;  //asigns requeriment value to odd : 0
	} else {
		lub_checksum = 1;  //asigns requeriment value to even : 1
	}
	return lub_checksum;
}

/**************************************************************
 *  Name                 : checksum_add
 *  Description          : compare the typed checksum bit at 
 *                         hyperterminal, and the calculated
 *                         checksum
                       
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void checksum() {
	T_UBYTE lub_checksum = 0;
	lub_checksum = checksum_add();
	if (rs_charVal.bit7 == lub_checksum) {
		rs_ctrlFlag.checksum = 0;
	} else {
		rs_ctrlFlag.checksum = 1;
	}
}

/**************************************************************
 *  Name                 : stopBit
 *  Description          : determine if the stop bit its on 
 *                         and sets a stop flag.                        
 *  Parameters           : none
 *  Return               : lub_checksum_add
 *  Critical/explanation : no
 **************************************************************/
void stopBit() {
	if (rs_charVal.bit6) {
		re_sbStatus = STOP;
		rs_ctrlFlag.sbest=1;

	} else {
		re_sbStatus = TxRx;
		rs_ctrlFlag.sbest=0;

	}
}

/**************************************************************
 *  Name                 : ignition
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void Ignition() {
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
 *  Name                 : sel_driv
 *  Description          :                                  
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void ign_select() {
	if (!rs_charVal.bit3 & !rs_charVal.bit2) {
		// 00 Off
		re_selStatus = SEL_OFF;
	} else if ((!rs_charVal.bit3) & rs_charVal.bit2) {
		// 01 Auto
		re_selStatus = SEL_AUTO;
	} else if (rs_charVal.bit3 & !rs_charVal.bit2) {
		// 10 ParkLamps
		re_selStatus = SEL_PL;
	} else if (rs_charVal.bit3 & rs_charVal.bit2) {
		// 11 HeadLamps
		if ((re_ignStatus == IS_RUN) | (re_ignStatus == IS_START)) {
			re_selStatus = SEL_LON;
		} else {
			re_selStatus = SEL_PL;
		}
	} else {
		//do nothing
		//re_selStatus= SEL_OFF;
	}
}




/**************************************************************
 *  Name                 : sel_lightSensor
 *  Description          : function depend of the previous 
 *                         values given by anterior conditions                                 
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void sel_lightSensor() {
         if (re_selStatus == SEL_AUTO) {
		if (!rs_charVal.bit5 && !rs_charVal.bit4){
			// 00 invalid
			re_sensorStatus = LS_INV;
		} else if (!rs_charVal.bit5 && rs_charVal.bit4) {
			// 01 >0% sensor <40%
			if((re_ignStatus == IS_RUN) | (re_ignStatus == IS_START)){
			re_sensorStatus = LS_LOW;
			} else {
			re_sensorStatus = LS_MED;	
			}
		} else if (rs_charVal.bit5 && !rs_charVal.bit4) {
			// 10 >40% sensor <80%
			re_sensorStatus = LS_MED;
		} else if (rs_charVal.bit5 && rs_charVal.bit4) {
			// 11 80% < sensor
			re_sensorStatus = LS_HIGH;
		} else {
			//do nothing
		}
	} else if (re_selStatus == SEL_PL){
		re_sensorStatus = LS_MED;

	}   else if (re_selStatus == SEL_LON){
		re_sensorStatus = LS_LOW;

	}  else {
		//do nothing
		re_sensorStatus = LS_INV;
	}
}



void Output_selection() {
	Ignition();
	switch (re_ignStatus) {
	case IS_OFF:
		ign_select();
		sel_lightSensor();
		break;
	case IS_ACC:
		ign_select();
		sel_lightSensor();
		break;
	case IS_RUN:
		ign_select();
		sel_lightSensor();
		break;
	case IS_START:
		ign_select();
		sel_lightSensor();
		break;
	default:
		break;
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
	if (!rs_ctrlFlag.checksum) {
		rs_ctrlFlag.inf1 = 0;
		rs_ctrlFlag.inf0 = 0;		
	} else if (rs_ctrlFlag.checksum) {
		rs_ctrlFlag.inf1 = 0;
		rs_ctrlFlag.inf0 = 1;
	} else if (rs_ctrlFlag.sbest & (!rs_ctrlFlag.checksum)) {
		rs_ctrlFlag.inf1 = 1;
		rs_ctrlFlag.inf0 = 0;
	} else {
		//do nothing
	}
}






