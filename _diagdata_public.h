/**
   \file _diagdata_public.h
   Header file for diagnostic data modules. <b>This header file is public!</b>	\n
   &copy; Copyright by Sauer-Danfoss GmbH & Co. OHG 2008

   \b History
   \verbatim
   Vers:  Date:     Name:     Comment:
   -----  ------   -------   ------------------------------------------------
   02.43  27Feb06  Bendixen  First steps
   02.53  20Sep06  fbjorn    added _APPL_DIAG_INFO
   03.05  07Apr08  fbjorn    added _ApplDiagReadRange
   03.15  03Nov08  mkrebs    Changed/added comments for doxygen
	 03.22  23Feb09  mkrebs    Changes for C++ on PLUS+1
   
   \endverbatim

  */
#ifndef _DIAGDATA_PUBLIC_
#define _DIAGDATA_PUBLIC_

/** Macro to introduce a new access block
*/
/*
 * Suppress Lint messages 778 and 845.  These relate to constant zeroes that
 * may occur depending on what values are passed to the macro.  Start suppressing
 * with _RANGE_START, then restore suppression with _RANGE_END.
 */
#ifdef __cplusplus
#define _RANGE_START(name) \
   /*lint -save -e778 -e845 */ \
   /*lint -esym(765,name,name##Size) */ \
   /*lint -esym(552,name,name##Size) */ \
   extern const ACCESS_BLOCK_T name[]; \
   extern const U16 name##Size; \
   const ACCESS_BLOCK_T name[] = { {(U32)name,(U32)&name##Size}
#else
#define _RANGE_START(name) \
   /*lint -save -e778 -e845 */ \
   /*lint -esym(765,name,name##Size) */ \
   /*lint -esym(552,name,name##Size) */ \
   extern const U16 name##Size; \
   const ACCESS_BLOCK_T name[] = { {(U32)name,(U32)&name##Size}
#endif
/** Add a variable to the access block that has been introduced by _RANGE_START()
*/ 
#define _RANGE_VAR(var) ,{((U32)&var),((U32)&var+((U32)sizeof(var)-1UL))}

/** Add any range to the access block
*/
#define _RANGE_ABS(Start,End) ,{(Start),(End)}

/** Finish access block declaration
*/
#define _RANGE_END(name) }; const U16 name##Size = (U16)sizeof(name)/(U16)sizeof(ACCESS_BLOCK_T); /*lint -restore */


/** Macro to introduce a new access block for application data (variable \a _ApplWriteRange)
*/
#define APPL_WRITE_RANGE_START  _RANGE_START(_ApplWriteRange)

/** Add a variable to \a _ApplWriteRange
*/ 
#define APPL_WRITE_RANGE_VAR(var) _RANGE_VAR(var)

/** Finish declaration of \a _ApplWriteRange
*/
#define APPL_WRITE_RANGE_END _RANGE_END(_ApplWriteRange)

/** Declare \a _ApplDiagInfo that contains the user diagnistic data
*/
#define _APPL_DIAG_INFO(zipped,packed) \
const DIAGINFO14_T _ApplDiagInfo =     \
{                                      \
  (U16)defDI14Size,                    \
  (U16)defDI14Size >> 8U,              \
  (U16)defDI14Size >> 16U,             \
  (U16)defDI14Size >> 24U,             \
  14U,                                 \
  (U16)zipped,                         \
  (U16)packed,                         \
   0U,                                 \
  (U32)ApplTextArray,                  \
  (U32)sizeof(ApplTextArray),          \
  (U32)ApplAddrArray,                  \
  (U32)sizeof(ApplAddrArray),          \
  0UL,                                 \
  0UL                                  \
};                                     \
_RANGE_START(_ApplDiagReadRange)       \
_RANGE_VAR(_ApplDiagInfo)              \
_RANGE_VAR(ApplTextArray)              \
_RANGE_VAR(ApplAddrArray)              \
_RANGE_END(_ApplDiagReadRange)





#define _LSBFirst             0x00       
#define _MSBFirst             0x01
#define _ZippedFormatUnzipped 0x00
#define _ZippedFormatZipped   0x01
#define _PackedFormatUnpacked 0x00
#define _PackedFormatPacked 0x01

#define defDI14Size (sizeof(DIAGINFO14_T))    ///< Size in bytes for the diagnostic tool

/** Datastructure for user diagnostic data must not comply to naming convention
*/
typedef struct
{
  U16 SizeByte0     : 8; ///< Size of this struct in bytes LSB 
  U16 SizeByte1     : 8; ///< Size of this struct in bytes 
  U16 SizeByte2     : 8; ///< Size of this struct in bytes 
  U16 SizeByte3     : 8; ///< Size of this struct in bytes MSB
  U16 Type          : 8; ///< Type of this struct 14
  U16 ZippedFormat  : 8; ///< 0 = not zipped , 1 = zipped
  U16 PackedFormat  : 8; ///< 0 = not packed , 1 = packed
  U16 dummy         : 8; ///< Dummy
  U32 DiagDataAddr;      ///< Address to diagnostic data
  U32 DiagDataLength;    ///< Length of diagnostic data
  U32 DiagAddr;          ///< Address of address vector 
  U32 DiagAddrLength;    ///< Length of address vector
  U32 ExtDiagInfoAddr;   ///< Address of extended DIAG INFO
  U32 ExtDiagInfoSize;   ///< Size of extended DIAG info
} DIAGINFO14_T;



// the following structure has to be declared in the user application here declared as extern
extern const DIAGINFO14_T _ApplDiagInfo;

#endif

