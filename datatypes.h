/** @defgroup PAL PAL
 *  This is a Processor Abstraction Layer (PAL) File
 *  @{
 */


/**
   \file PAL_datatypes.h
   This header file contains basic datatype definitions

   \b History
   \verbatim
   Vers:  Date:     Name:      Comment:
   -----  -------   -------    ------------------------------------------------
   00.00  18Jan10   Byrnes     Initial start
   01.21  16Apr13   Bendixen   Added typedef PORT SDPORTTYPE;

   \endverbatim

  */


#ifndef DATATYPES_H
#define DATATYPES_H
/*lint -esym(537, datatypes.h) */

#include <limits.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>

typedef enum{
	eOk = 0,
	eBad
	// more...
}eRetVal_t;

#if CHAR_BIT > 8
typedef int16_t S8;
typedef uint16_t U8;
#else
typedef int8_t S8;
typedef uint8_t U8;
#endif

typedef char TL;

#ifndef BOOL
typedef U8 BOOL;
#endif

typedef int16_t S16;
typedef uint16_t U16;

typedef int32_t S32;
typedef uint32_t U32;

typedef int64_t S64;
typedef uint64_t U64;

typedef float_t FLOAT;

#ifdef FALSE
#undef FALSE /*lint !e960 Violates MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged: 'FALSE' */
#endif
#define FALSE ((BOOL)0U)

#ifdef TRUE
#undef TRUE /*lint !e960 Violates MISRA 2004 Required Rule 19.6, use of '#undef' is discouraged: 'TRUE' */
#endif
#define TRUE  /*lint -save -e506 -e960*/ ((BOOL)(!FALSE)) \
              /*lint -restore */

typedef   U8 PORT;
typedef   PORT SDPORTTYPE;

/* GUIDE TimeBase */
typedef   U8 T;

#define STATUS_FAIL (0U)
#define STATUS_SUCCESS /*lint -save -e506 -e960*/ (!FALSE) \
                       /*lint -restore */

#ifndef NULL
#define NULL 0U
#endif

#ifndef force_ptr_cast
#define force_ptr_cast(type, object) ((type)((void *)object))
#endif

#ifndef force_ptr_cast_w_specifier
#define force_ptr_cast_w_specifier(specifier, type, object) ((specifier type)((specifier void *)object))
#endif

typedef struct
{
  U32 AddressStart;
  U32 AddressEnd;
}ACCESS_BLOCK_T;


#define BIT00_D	0x00000001UL
#define BIT01_D	0x00000002UL
#define BIT02_D	0x00000004UL
#define BIT03_D	0x00000008UL

#define BIT04_D	0x00000010UL
#define BIT05_D	0x00000020UL
#define BIT06_D	0x00000040UL
#define BIT07_D	0x00000080UL

#define BIT08_D	0x00000100UL
#define BIT09_D	0x00000200UL
#define BIT10_D	0x00000400UL
#define BIT11_D	0x00000800UL

#define BIT12_D	0x00001000UL
#define BIT13_D	0x00002000UL
#define BIT14_D	0x00004000UL
#define BIT15_D	0x00008000UL

#define BIT16_D	0x00010000UL
#define BIT17_D	0x00020000UL
#define BIT18_D	0x00040000UL
#define BIT19_D	0x00080000UL

#define BIT20_D	0x00100000UL
#define BIT21_D	0x00200000UL
#define BIT22_D	0x00400000UL
#define BIT23_D	0x00800000UL

#define BIT24_D	0x01000000UL
#define BIT25_D	0x02000000UL
#define BIT26_D	0x04000000UL
#define BIT27_D	0x08000000UL

#define BIT28_D	0x10000000UL
#define BIT29_D	0x20000000UL
#define BIT30_D	0x40000000UL
#define BIT31_D	0x80000000UL

typedef unsigned char LANG;

#endif

/** @} */ // end of PAL

