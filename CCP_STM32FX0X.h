// file:    CCP_STM32FX0X.h

// Basic GUIDE datatypes for CCP that works with ST based HWD files and GNU compiler 

// --------------------------------------------------------------------

#ifndef CCP_STM32FX0X_H
#define CCP_STM32FX0X_H

#include <stdint.h>
#include <math.h>

#ifdef CCP_STM32FX0X441 
#if CHAR_BIT > 8
typedef int16_t S8;
typedef uint16_t U8;
#else
typedef int8_t S8;
typedef uint8_t U8;
#endif


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
#undef FALSE
#endif
#define FALSE ((BOOL)0U)

#ifdef TRUE
#undef TRUE
#endif
#define TRUE  /*lint -save -e506 -e960*/ ((BOOL)(!FALSE)) \
              /*lint -restore */

#endif

#ifdef CCP_STM32FX0X462 
#if CHAR_BIT > 8
typedef int16_t S8;
typedef uint16_t U8;
#else
typedef int8_t S8;
typedef uint8_t U8;
#endif


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
#undef FALSE
#endif
#define FALSE ((BOOL)0U)

#ifdef TRUE
#undef TRUE
#endif
#define TRUE  /*lint -save -e506 -e960*/ ((BOOL)(!FALSE)) \
              /*lint -restore */

#endif

#endif
