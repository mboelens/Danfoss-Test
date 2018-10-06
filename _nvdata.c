/*****************************************************************************
   Filename : _nvdata.c         Library:

   Vers:  Date:     Name:     Comment:
   -----  -------   -------   ------------------------------------------------
   02.12  19May05   fbjorn    Initial start

   Header File :	_nvdata.h _nvdata_public.h

   Description :

*****************************************************************************/


/*-------------------------------------------------------
   include files
   -------------------------------------------------------*/

/*-------------------------------------------------------
   Definitions
   -------------------------------------------------------*/

#include "datatypes.h"
#include "_nvdata_public.h"

/*-------------------------------------------------------
   Type definitions
   -------------------------------------------------------*/

#ifndef _NVSize
 #define _NVSize   1
#endif

/*-------------------------------------------------------
   Variables
   -------------------------------------------------------*/

/* do not change the names of all the elements - used by GUIDE */

const U16   _NVSIZE    = (U16)_NVSize;                 // The number of words used by the NV symbols
const U16   _NVBITSIZE = (((U16)_NVSize + 15U) / 16U); // The number of words needed to represent _nvsize nuber of bits

/*lint -esym(759,_NVOUTU)  */ /* disable lint warning symbol declaration could be moved from header to module, which is not the case because it will be used from CODE-generator */
/*lint -esym(765, _NVOUTU) */ /* disable lint warning symbol could be made static, which is not the case because it will be used from CODE-generator */
_NVOUTU_T   _NVOUTU;

U16  *_NVOUT = _NVOUTU.u16;            // NVPROM SYMBOL VALUE OUTPUT, One extra for CS ?

/*lint -esym(714, _NVINT,_NVPND) */ /* disable lint warning symbol not referenced, which is not the case because it will be used from CODE-generator */
/*lint -esym(759,_NVINT,_NVPND)  */ /* disable lint warning symbol declaration could be moved from header to module, which is not the case because it will be used from CODE-generator */
/*lint -esym(765, _NVINT,_NVPND) */ /* disable lint warning symbol could be made static, which is not the case because it will be used from CODE-generator */
U16   _NVINT[_NVSize];                 // CURRENT NV MEMORY VALUE OR PENDING VALUE, One Extra for CS
U16   _NVPND[(_NVSize + 15) / 16];     // NV MEMORY PENDING FLAG SET BY SYMBOL AND RESET BY BIOS IN THE LOOP
U16   _NVINTPND0[(_NVSize + 15) / 16]; // NV MEMORY PENDING FLAG SET BY BIOS IN THE LOOP AND RESET BY NV MEMORY TASK
U16   _NVINTPND1[(_NVSize + 15) / 16]; // NV MEMORY PENDING FLAG SET BY BIOS IN THE LOOP AND RESET BY NV MEMORY TASK
U16   _NVDIAGPND[(_NVSize + 15) / 16]; // NV MEMORY PENDING FLAG SET BY DIAGNOSTIC ROUTINE

