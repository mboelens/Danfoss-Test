/*------------------------------------------------------------------------------
String type definitions
-------------------------------------------------------------------------------
Copyright (c) 2017 Danfoss

@Author  mponomarenko
@Version 10.0 2017.08.30 pliapota  plc2c-611 Header update
-------------------------------------------------------------------------------*/

#ifndef _FILE___STDLIB_ST_TYPE_STRING_H
#define _FILE___STDLIB_ST_TYPE_STRING_H

#include <stdint.h>

typedef struct PLC_STRING_IN_REF {
	uint16_t cur_len;
	unsigned char* value;
} PLC_STRING_IN_REF;

typedef struct PLC_STRING_OUT_REF {
	uint16_t max_len;
	uint16_t* cur_len;
	unsigned char* value;
} PLC_STRING_OUT_REF;

#endif /* _FILE___STDLIB_ST_TYPE_STRING_H */
