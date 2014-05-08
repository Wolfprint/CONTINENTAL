/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        ledDrivers.h
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014  
*=============================================================================*/
/* DESCRIPTION :This file contains the prototyping of lamps drivers           */                     
/*============================================================================*/

#ifndef LEDDRIVERS_H_
#define LEDDRIVERS_H_

/* Includes */
/* -------- */
#include "derivative.h"

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
#define PL_ON   (1<<1)
#define PL_OFF    0
#define HL_ON   (1<<2)
#define HL_OFF   PL_OFF

void ParkLamps_ON();
void ParkLamps_OFF();
void HeadLamps_ON();
void HeadLamps_OFF();
void LightsOff();
void HalfLight();
void LightsOn();

#endif /* LEDDRIVERS_H_ */
