/*****************************************************************************
   Filename : applogsymbol.h

   Vers:   Date:      Name:     Comment:
   -----  -------   -------   ------------------------------------------------
   02.53  03Oct06   fbjorn    Initial start
   03.14  30Oct08   fbjorn    Fix erase of multiple files
   04.10  28Jan10   Jbendixen Added #define  sprintf K_sprintf and external declaration of kernel
                           K_sprintf function, because the original one in library 5.22 does not work
                                        (uses to much stack)
   Description :  This is the public part of the header file for applogsymbol.c and contains the
               interface for the module
*****************************************************************************/

#ifndef _APPLOGSYMBOL_PUBLIC_
#define _APPLOGSYMBOL_PUBLIC_


/*-------------------------------------------------------
   include files
   -------------------------------------------------------*/

 #include "datatypes.h"
 #include "_ff_flashfile_public.h"

#ifdef __TMS320C28XX__
 #define _CODE_ACCESS
 #ifdef _lint

 #else   // #ifdef _lint
  #if __TI_COMPILER_VERSION__ == 4001003
extern _CODE_ACCESS S16 sprintf(S8       *_string,
                                const S8 *_format,
                                ...);

  #else  // __TI_COMPILER_VERSION__ == 4001003
extern _CODE_ACCESS S16 K_sprintf(S8       *_string,
                                  const S8 *_format,
                                  ...);

   #define  sprintf   K_sprintf
  #endif // __TI_COMPILER_VERSION__ == 4001003
 #endif  // #ifdef _lint
#else // #ifdef __TMS320C28XX__
 #define _CODE_ACCESS
 #ifdef _lint

 #else // #ifdef _lint
#define _CODE_ACCESS
extern _CODE_ACCESS S16 K_sprintf(S8       *_string,
                                const S8 *_format,
                                ...);
#define  sprintf   K_sprintf
 #endif  // #ifdef _lint
#endif   // #ifdef __TMS320C28XX__


/*-------------------------------------------------------
   Definitions
   -------------------------------------------------------*/
#define _TEXT_FILE_TYPE    1

#define _ApplSectorStart   0x10000UL
#define _ApplSectorSize    0x10000UL
#define _ApplAbsOffs       0x01000000UL
#define _LinearFile        _ff_LinearFile
#define _CircularFile      _ff_CircularFile

//#define _FILE_SECTOR_ADDR(nr)                           (_ApplAbsOffs + (_ApplSectorStart + nr * _ApplSectorSize) / 2)
/* TODO: figure out, if sectorsize is in byte or word mroggon 20131017 */
#define _FILE_SECTOR_ADDR(nr)                           (_ApplAbsOffs + (_ApplSectorStart + nr * _ApplSectorSize))

/*lint -save -e960 -e961 */	// disable warnings "Multiple use of '#' and/or '##' operators in macro definition" and "'#/##' operator used in macro"
#define _CREATE_APPL_FILE_START(name)                   _ff_CREATE_FILE_START(name##_al)
#define _CREATE_APPL_FILE_SECTOR(nr)                    _ff_CREATE_FILE_SECTOR((_ApplSectorStart + nr * _ApplSectorSize), _ApplSectorSize)
#define _CREATE_APPL_FILE_END(name, filetype, rtread)   _ff_CREATE_FILE_END(name##_al, filetype)      \
   MsgFile_T name = { _TEXT_FILE_TYPE, 0, FALSE, FALSE, &rtread, &name##_al, NULL, { NULL }, { NULL } \
   };
/*lint -restore */

#define _EXT_DECL_APPL_FILE(name)                       extern MsgFile_T name;

#define _APPL_ST_WRITE   0x01
#define _APPL_ST_READ    0x02
#define _APPL_ST_ERASE   0x04
#define _APPL_ST_EOF     0x08


#define _FILE_PORT_TYPE 1U
#define _INIT_FILE_PORT {_FILE_PORT_TYPE,{NULL},{NULL}}

/*-------------------------------------------------------
   Type definitions
   -------------------------------------------------------*/


typedef void (*ProcessTextMsg_T)(TL *s);

// Text message post
typedef struct _TextMsgStruct
{
   struct _TextMsgStruct  *Next;
   ProcessTextMsg_T        GetTextMsg;
   TL                     *Tag;
   volatile BOOL           Pending;
}TextMsg_T;

/*lint -save -e960 */	// disable warning "declaration of union type or object of union type"

// Text Message File
typedef struct _MsgFileSruct
{
   U16                    Type;
   U16                    Status;
   BOOL                   Enable;
   BOOL                   Erase;
   BOOL                  *RTRead;
   void                  *hnd;
   struct _MsgFileSruct  *Next;
   union
   {
      TextMsg_T  *TextMsg;
   }First;
   union
   {
      TextMsg_T  *TextMsg;
   }Last;
}MsgFile_T;

// Text Message Port
typedef struct _MsgPortStruct
{
   /*const*/ U16   Type;
   union
   {
      MsgFile_T  *File;
   }First;
   union
   {
      MsgFile_T  *File;
   }Last;
}MsgPort_T;

/*lint -restore */

/*-------------------------------------------------------
   Variables
   -------------------------------------------------------*/

/*-------------------------------------------------------
   functions
   -------------------------------------------------------*/

//void _APPL_ASSIGN_FILE(MsgPort_T *Port, MsgFile_T *File );

/********************************************************
 *********************************************************/

//void _APPL_INIT_TEXT(TextMsg_T *TextMsg, ProcessTextMsg_T Process, TL *Tag);

/********************************************************
 *********************************************************/

// Called from aplication loop
//void _APPL_SEND_TEXT(MsgFile_T *File, TextMsg_T *Msg);

/********************************************************
 *********************************************************/

#endif /* ifndef _APPLOGSYMBOL_PUBLIC_ */

