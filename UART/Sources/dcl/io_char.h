/*============================================================================*/
/*                               CUCEI UdG                                    */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        io_chars.h
* version:         1.0 
* created_by:      Antonio Altamirano  
* date_created:    April 26 2014  
*=============================================================================*/
/* DESCRIPTION :This file contains the prototyping of the character Rx and TX */                     
/*============================================================================*/

#ifndef IO_CHAR_H_
#define IO_CHAR_H_

#include "derivative.h"
#include "stdtypedef.h"


T_UBYTE uart0_getchar();
void uart0_putchar(T_UBYTE lub_ch);
extern void put(T_UBYTE *lubp_ptr_str);


#endif /* IO_CHAR_H_ */
