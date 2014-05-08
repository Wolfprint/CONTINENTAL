/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
 * C Source:        uart0_init.c
 * version:         1.0 
 * created_by:      Antonio Altamirano  
 * date_created:    April 18 2014 
 *=============================================================================*/
/* DESCRIPTION : C source for UART0 module Initialization.                      */
/*=============================================================================*/

#include "uart0_init.h"

/**************************************************************
 *  Name                 : uart0_init
 *  Description          : UART0 module Initialization                      .                         
 *  Parameters           : none
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void uart0_init() {

	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1); //system integration module: multipurpose clock generator to UART clock source selector (48 MHz) 
 	SIM_SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // PLL/FLL clock select
	SIM_SCGC4 = SIM_SCGC4_UART0_MASK; // UART0 Clock Gate Control: Enabled
	SIM_SCGC5 = SIM_SCGC5_PORTA_MASK; // Port A Clock Gate Control: Enabled

	PORTA_PCR2 = PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x2); //UART0 Port A2 as Tx; Configured interrupt is detected.
	PORTA_PCR1 = PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x2); //UART0 Port A1 as Rx; Configured interrupt is detected.

	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK); //Module disabled before setting changes

	UART0_C1 = 0x00; // UART0_C1: LOOPS=0,DOZEEN=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0.               Page 727
	UART0_C3 = 0x00; // UART0_C3: R8T9=0,R9T8=0,TXDIR=0,TXINV=0,ORIE=0,NEIE=0,FEIE=0,PEIE=0.        Page 733  
	UART0_MA1 = 0x00; // UART0_MA1: MA=0 
	UART0_MA1 = 0x00; // UART0_MA2: MA=0  
	UART0_S1 |= 0x1F; // UART0_S1: IDLE=1,OR=1,NF=1,FE=1,PF=1.                                      Page 729
	UART0_S2 |= 0xC0; // UART0_S2: LBKDIF=1,RXEDGIF=1,MSBF=0,RXINV=0,RWUID=0,BRK13=0,LBKDE=0,RAF=0. Page 731  
	
	UART0_BDH = 0x00;
	UART0_BDL = 0xD;
	UART0_C4 = 0x0F;                          // Oversampling ratio                                 Page 737

	/* Enable receiver and transmitter */
	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK);
}
