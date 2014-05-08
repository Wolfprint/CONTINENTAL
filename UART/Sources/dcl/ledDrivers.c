/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        ledDrivers.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION : C source for lamps driver.                                   */                            
/*============================================================================*/

/* Includes */
/* -------- */
#include "ledDrivers.h"

/**************************************************************
 *  Name                 : ParkLamps_ON
 *  Description          : ParkLamps Port logic level 1                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void ParkLamps_ON() {
	GPIOB_PCOR |= PL;
}

/**************************************************************
 *  Name                 : ParkLamps_OFF
 *  Description          : ParkLamps Port logic level 0                           
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void ParkLamps_OFF() {
	GPIOB_PSOR |= PL;
}

/**************************************************************
 *  Name                 : HeadLamps_ON
 *  Description          : HeadLamps logic level 1                        
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void HeadLamps_ON() {
	GPIOB_PCOR |= HL;
}

/**************************************************************
 *  Name                 : HeadLamps_OFF
 *  Description          : HeadLamps logic level 0                           
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void HeadLamps_OFF() {
	GPIOB_PSOR |= HL;
}

/**************************************************************
 *  Name                 : LightsOff
 *  Description          : Both lamps off                       
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void LightsOff() {
	ParkLamps_OFF();
	HeadLamps_OFF();
}

/**************************************************************
 *  Name                 : HalfLight
 *  Description          : Park Lamps ON                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void HalfLight() {
	ParkLamps_ON();
	HeadLamps_OFF();
}

/**************************************************************
 *  Name                 : LightsOn
 *  Description          : Both lamps on                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void LightsOn() {
	ParkLamps_ON();
	HeadLamps_ON();
}

