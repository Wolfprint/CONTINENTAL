/*
 * File:		io.h
 * Purpose:		Serial Input/Output routines
 *
 */

#ifndef _IO_H
#define _IO_H

#include "..\mcl\uart.h"
#include "stdtypedef.h"

/********************************************************************/

char	
in_char(void);

void
out_char(char);

int
char_present(void);


#endif
