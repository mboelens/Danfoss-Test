/*****************************************************************************
Filename : _nvdata_public.h       Library:

Vers:  Date:     Name:     Comment:
-----  -------   -------   ------------------------------------------------
02.01  05Jan2   fbjorn     Initial start
03.42  21Apr09  fbjorn     U8 -> S8, P1McX00000220


Description :  
*****************************************************************************/

#ifndef ___NVDATA_PUBLIC_H__								    
#define ___NVDATA_PUBLIC_H__

/*-------------------------------------------------------
   include files
-------------------------------------------------------*/


#include "_nvallocation.h"

/*-------------------------------------------------------
   Definitions
-------------------------------------------------------*/

#if _NVSize
#else
#undef _NVSize
#define _NVSize	1
#endif

/* No name change, this interfaces with GUIDe directly and shall not be renamed */
#undef bool /*lint !e960 */ /* MISRA Requires no usage of undef; but in this case we need to align compiler with GUIDE interface */

/*-------------------------------------------------------
   Type definitions
-------------------------------------------------------*/
/*lint -esym(960,18.4) */ /* MISRA Requires no declaration of union type, which is not possible to achieve for this low level driver */
typedef union {
	struct {
		BOOL bool;
#if (CHAR_BIT == 8)
		U8 align;
#endif
	} al16bool[_NVSize];
	struct {
		U8 u8;
#if (CHAR_BIT == 8)
		U8 align;
#endif
	} al16u8[_NVSize];
	struct {
		S8 s8;
#if (CHAR_BIT == 8)
		U8 align;
#endif
	} al16s8[_NVSize];
	U16 u16[_NVSize];
	S16 s16[_NVSize];
	U32	u32[(_NVSize+1) / 2];
	S32	s32[(_NVSize+1) / 2];
}_NVOUTU_T;

/*-------------------------------------------------------
   Variables
-------------------------------------------------------*/

extern _NVOUTU_T _NVOUTU;
extern U16 _NVINT[];		
extern U16 _NVPND[];	 	

/*-------------------------------------------------------
   functions
-------------------------------------------------------*/

#endif // __NVDATA_PUBLIC_H__
