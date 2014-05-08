/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
 * C Source:        mcg_init.c
 * version:         1.0 
 * created_by:      Antonio Altamirano  
 * date_created:    April 25 2014 
 *=============================================================================*/
/* DESCRIPTION : C source for MCG configuration routines                       */
/*=============================================================================*/

#include "mcg_init.h"

void mcg_init(){
	T_UBYTE lub_temp_reg;
	T_UWORD luw_i;
	/* first configure the oscillator settings in the MCG_C2 register */
	
	MCG_C2 = (MCG_C2_RANGE0(1) | MCG_C2_EREFS0_MASK); // high frequency (8Mhz); xtal oscillator requested     page 373

	/* 8 MHz / 256 = 31.25kHz which is the min range required by the FLL*/
	MCG_C1 = (MCG_C1_CLKS(2) | MCG_C1_FRDIV(3)); //external reference clock; RANGE 0 != 0 values, Divide Factor is 256.
	
	// When the external oscillator is used need to wait for OSCINIT to set
	for (luw_i = 0 ; luw_i < 20000 ; luw_i++)
	{
	// jump out early if OSCINIT sets before loop finishes
	if (MCG_S & MCG_S_OSCINIT0_MASK) break;
	}
	// wait for Reference clock Status bit to clear
	for (luw_i = 0 ; luw_i < 2000 ; luw_i++)
	{
	// jump out early if IREFST clears before loop finishes
	if (!(MCG_S & MCG_S_IREFST_MASK)) break;
	}
	// Wait for clock status bits to show clock source is ext ref clk
	for (luw_i = 0 ; luw_i < 2000 ; luw_i++)
	{
	// jump out early if CLKST shows EXT CLK selected before loop finishes
	if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) == 0x2) break;
	}
	// Now in FBE
	
	MCG_C6 |= MCG_C6_CME0_MASK; //External clock monitor is enabled for OSC0.
	
	// Configure MCG_C5 to set the PLL reference clock at the right frequency
	
	MCG_C5 |= MCG_C5_PRDIV0(3); //set PLL ref divider to divide by 4 (8 MHz/4 = 2 MHz.)
	
	// Configure MCG_C6 to set the PLL multiplier and enable the PLL
	// The PLLS bit is set to enable the PLL, MCGOUT still sourced from ext ref clk
	lub_temp_reg = MCG_C6; // store present C6 value (as CME0 bit was previously set)
	lub_temp_reg &= ~MCG_C6_VDIV0_MASK; // clear VDIV settings
	lub_temp_reg |= MCG_C6_PLLS_MASK | MCG_C6_VDIV0(0); // write new VDIV and enable PLL and multiply by 24
	MCG_C6 = lub_temp_reg; // update MCG_C6
	// wait for PLLST status bit to set
	for (luw_i = 0 ; luw_i < 2000 ; luw_i++)
	{
	// jump out early if PLLST sets before loop finishes
	if (MCG_S & MCG_S_PLLST_MASK) break;
	}
	// Wait for LOCK bit to set
	for (luw_i = 0 ; luw_i < 4000 ; luw_i++)
	{
	// jump out early if LOCK sets before loop finishes
	if (MCG_S & MCG_S_LOCK0_MASK) break;
	}
	
	// now in PBE
	// set the core clock divider to divide by 2
	// set the bus clock divider to divide by 2 (bus clock is sourced from core clock)
	SIM_CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(1) | SIM_CLKDIV1_OUTDIV4(1) );

	// clear CLKS to switch CLKS mux to select the PLL as MCGCLKOUT
	MCG_C1 &= ~MCG_C1_CLKS_MASK;
	// Wait for clock status bits to update
	for (luw_i = 0 ; luw_i < 2000 ; luw_i++)
	{
	// jump out early if CLKST = 3 before loop finishes
	if (((MCG_S & MCG_S_CLKST_MASK) >> MCG_S_CLKST_SHIFT) == 0x3) break;
	}
	// Now in PEE
}



