/*
 * actuatorApp.c
 *
 *  Created on: May 5, 2014
 *      Author: FlatBlock
 */

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
	switch (re_selStatus) {
	case SEL_OFF:
		LightsOff();
		put("lights: OFF \r\n");
		break;
	case SEL_AUTO:
		put("Auto mode\r\n");
	case SEL_PL:
		HalfLight();
		put("Parklights: ON \r\n");
		break;
	case SEL_HL:
		LightsOn();
		put("HeadLights: ON \r\n");
	default:
		break;
	}

	switch (re_sensorStatus) {
	case LS_INV: //invalid
		put("Invalid \r\n");
		break;
	case LS_LOW:
		LightsOn();
		put("HeadLights: ON \r\n");
		break;
	case LS_MED:
		HalfLight();
		put("Parklights: ON \r\n");
		break;
	case LS_HIGH:
		LightsOff();
		put("lights: OFF \r\n");
	default:
		break;
	}

	T_ULONG lub_sb;
	switch (re_sbStatus) {
	case TxRx: //transmitter receiver
		break;
	case STOP:
		put("TxRx: Disabled \r\n");
		for (lub_sb = 0; lub_sb <= 10000000; lub_sb++) {
			//wait until the loop ends
		}
		put("TxRx: Enabled \r\n");
		break;
	default:
		break;
	}
}


