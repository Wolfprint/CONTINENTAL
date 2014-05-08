/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        io_char.c
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014 
*=============================================================================*/
/* DESCRIPTION : C source for characters driver.                              */                            
/*============================================================================*/

/* Includes */
/* -------- */

#include "io_char.h"

/**************************************************************
 *  Name                 : uart0_getchar
 *  Description          : Wait for a character to be received 
 *                         on the specified UART                      .                         
 *  Parameters           : none
 *  Return               : received character
 *  Critical/explanation : no
 **************************************************************/
T_UBYTE uart0_getchar ()
{
      /* Wait until character has been received */
      //while (!(UART0_S1 & UART0_S1_RDRF_MASK));
      for(;;){
    	  if (UART0_S1 & UART0_S1_RDRF_MASK){
    		  break;
    	  } else {
    		  //do nothing
    	  }
      }
      /* Return the 8-bit data from the receiver */
      return UART0_D;
}

/**************************************************************
 *  Name                 : uart0_putchar
 *  Description          : Wait for space in the UART Tx FIFO 
                           and then send a character                       
 *  Parameters           : lub_ch
 *  Return               : character to send
 *  Critical/explanation : no
 **************************************************************/
void uart0_putchar (T_UBYTE lub_ch)
{
      /* Wait until space is available in the FIFO */
	  //while(!(UART0_S1 & UART0_S1_TDRE_MASK));
	  for(;;){
		  if(UART0_S1 & UART0_S1_TDRE_MASK){
			  break;
		  } else {
			  //do nothing
		  }
	  }
    
      /* Send the character */
	  UART0_D = (T_UBYTE)lub_ch;
}

/**************************************************************
 *  Name                 : put
 *  Description          : Send string character to the 
 *                         console.                      
 *  Parameters           : lubp_ptr_str
 *  Return               : none
 *  Critical/explanation : no
 **************************************************************/
void put(T_UBYTE *lubp_ptr_str)
 {
	//while(*lubp_ptr_str)
	for (;;) {
		if (*lubp_ptr_str) {
			uart0_putchar((T_UBYTE) *lubp_ptr_str++);
		} else {
			break;
		}
	}
	//uart0_putchar((T_UBYTE) *lubp_ptr_str++);
}

