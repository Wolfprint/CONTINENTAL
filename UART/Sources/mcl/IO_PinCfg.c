/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        IO_PinCfg.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    March 28 2014 
*=============================================================================*/
/* DESCRIPTION : C source for external component/device GPIO Initialization.  */                            
/*============================================================================*/

/* Includes */
/* -------- */
#include "IO_PinCfg.h"//includes the GPIO initialization definitions.


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/**************************************************************
 *  Name                 : IOPorts_Init
 *  Description          : IO pin registers initialization.                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void IOPorts_Init(){

	//---------------------Initialize Quarter lights (PTB1)--------------------------------	
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* Turn on clock to PortA module */		
	PORTB_PCR1 = PORT_PCR_MUX(1); /* Set the PTA1 pin multiplexer to GPIO mode */	
	GPIOB_PSOR |= PTB1_OUT; /* Set the initial output state to high */
	GPIOB_PDDR |= PTB1_OUT; /* Set the pins direction to output (1) */
	
	//---------------------Initialize Head lights (PTB2)-----------------------------------
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; /* Turn on clock to PortA module */	
	PORTB_PCR2 = PORT_PCR_MUX(1); /* Set the PTA2 pin multiplexer to GPIO mode */	
	GPIOB_PSOR |= PTB2_OUT; /* Set the initial output state to high */	
	GPIOB_PDDR |= PTB2_OUT; /* Set the pins direction to output (1) */
}
