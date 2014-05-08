/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        IO_PinCfg.h
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    March 28 2014 
*=============================================================================*/
/* DESCRIPTION :This file contains the InOut Pins prototypes functions        */                     
/*============================================================================*/

#ifndef IO_PINCFG_H_
#define IO_PINCFG_H_
/* Includes */
/* -------- */
#include "derivative.h" //includes the functions for hardware init.

/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */

//Constant names for output pins
#define PTA1_OUT (1<<1)
#define PTA2_OUT (1<<2)


void IOPorts_Init();


#endif /* IO_PINCFG_H_ */
