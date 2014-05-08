/*
 * libs.c
 *
 *  Created on: Jul 15, 2013
 *      Author: B34443
 */
#include "io.h"

void put(char *ptr_str)
{
	while(*ptr_str)
		out_char(*ptr_str++);
}
