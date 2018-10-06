
/*!
   @file _ff_FlashFile_public.h

   <hr>
   <h2> File Creation </h2>
   @author Uncrustify

   @date

   @caliberrm TODO: Link to CaliberRM in _ff_FlashFile_public.h

   @brief  TODO: Description of _ff_FlashFile_public.h


   <hr>
   <h2> Current Revision </h2>  <!-- This section will be filled by SVN at committing -->
   $Revision:$
   $Author:$
   $Date:$
   $HeadURL:$


   <hr>
   <h2> History </h2>
   @verbatim
   Vers:  Date:        Name:     Comment:
   -----  ----------   -------   ------------------------------------------------
   00.00                         Initial start
   -----  ----------   -------   ------------------------------------------------
   @endverbatim

   &copy; Danfoss, 2013. All rights reserved.
 */

/********************************************************
 File        : 	_ff_FlashFile_public.h

Vers:   Date:      Name:     Comment:
-----  -------   -------   ------------------------------------------------
02.53  03Oct06   fbjorn    Initial start

Description :  This is the public part of the header file for ff_FlashFile.c and contains the 
               interface for the module
********************************************************/

#ifndef _FF_FLASHFILE_PUBLIC_H_
#define _FF_FLASHFILE_PUBLIC_H_
/*-------------------------------------------------------
   include files
-------------------------------------------------------*/

#include "_fh_fileh_public.h"

/*-------------------------------------------------------
   Definitions
-------------------------------------------------------*/

#ifdef _MsgAvailable
   #ifndef _WriteOnly
      #define  _ff_INIT_FLASH_FILE(info)  {_fh_T_FlashFIFO,ff_Open,ff_Close,ff_Read,ff_Write,ff_Seek,Msg,info,FALSE}
   #else
      #define  _ff_INIT_FLASH_FILE(info)  {_fh_T_FlashFIFO,ff_Open,ff_Close,ff_Write,Msg,info,FALSE}
	#endif
#else
   #ifndef _WriteOnly
      #define   _ff_INIT_FLASH_FILE(info)  {_fh_T_FlashFIFO,ff_Open,ff_Close,ff_Read,ff_Write,ff_Seek,info,FALSE}
   #else
      #define   _ff_INIT_FLASH_FILE(info)  {_fh_T_FlashFIFO,ff_Open,ff_Close,ff_Write,info,FALSE}
	#endif
#endif

#ifdef __TMS320C28XX__
#define _Bytesizeof(v) (2*sizeof(v))
#else
#define _Bytesizeof(v) (sizeof(v))
#endif

#define _ff_LinearFile TRUE
#define _ff_CircularFile FALSE
 

#define _ff_SectorHeadderType	1
#define _ff_InitSectorHeadder {_ff_SectorHeadderType,_Bytesizeof(ff_SECTOR_HEADDER_TYPE),0}

/*lint -save -e960 -e961 */	// disable warnings "Multiple use of '#' and/or '##' operators in macro definition" and "'#/##' operator used in macro"
#define _NrOfFileSectors(name) (sizeof(name##_s)/sizeof(ff_SECTOR_TYPE))
#define _ff_CREATE_FILE_START(name) static ff_SECTOR_TYPE name##_s[] = {
#define _ff_CREATE_FILE_SECTOR(addr,size)  {addr,size,0,_ff_InitSectorHeadder}
#define _ff_CREATE_FILE_END(name,filetype)  }; \
	static ff_FILE_INFO_TYPE name##_i = {0,0,0,0,0,0,0,0,filetype,0,_NrOfFileSectors(name),name##_s};  \
 	ff_FILE name = _ff_INIT_FLASH_FILE(&name##_i); 
/*lint -restore */


/* EXAMPLE OF USING THE MACROS TO CREATE A FILE 
 _ff_CREATE_FILE_START(myfile)
 _ff_CREATE_FILE_SECTOR(0x00000,0x10000),
 _ff_CREATE_FILE_SECTOR(0x10000,0x10000)
 _ff_CREATE_FILE_END(myfile)
*/
  
/*-------------------------------------------------------
   Type definitions
-------------------------------------------------------*/

typedef fh_FILE ff_FILE;

// Each Flash Sector shall start with this structure
typedef struct
{
   U16 type :8;
   U16 size :8;
   U16 status;
}  ff_SECTOR_HEADDER_TYPE;

// Info about Each sector is stored in this structure
typedef struct
{
   U32 address;
   U32 size;
   U16 spos;
   ff_SECTOR_HEADDER_TYPE headder;	// Copy of headder
} ff_SECTOR_TYPE;

// This structure holds current status of actual file
typedef struct
{
	U32 fsize;		// Saves fpos when the file is closed after append or write
   U16 status;		// File Status ( Open, Closed ...)
   U32 fpos;		// File Pos as Data length pos
   U16 soffs;		// File pos as Sector offset
   U16 roffs;		// File Pos as record offset
   U8 sect;		// Curent Flash sector
   BOOL rok;   	// Status of curent record
   U16 rlen;   	// Length of current record
	BOOL linear;	// 
   U32 p;	    	// File Pos as absolut address
	U16 nrofsect; 	// Number of sectors
   ff_SECTOR_TYPE *sectors; // List of sectors in the file
}ff_FILE_INFO_TYPE;

/*-------------------------------------------------------
   Variables
-------------------------------------------------------*/

/*-------------------------------------------------------
   prototype functions
-------------------------------------------------------*/

/*-------------------------------------------------------
   functions
-------------------------------------------------------*/

/********************************************************

 Function   :  ff_Open
 Parameters : 
 Returns    : 
 Description:
********************************************************/
/*lint -esym(757, ff_Open) */	// disable warning "global declarator not referenced"
U16 ff_Open(ff_FILE *f,
            U16      status);

/********************************************************
 Function   :  ff_Close
 Parameters : 
 Returns    : 
 Description:
********************************************************/
/*lint -esym(757, ff_Close) */	// disable warning "global declarator not referenced"
U16 ff_Close(ff_FILE *f);

/********************************************************
 Function   :  ff_Read
 Parameters : 
 Returns    : 
 Description:
********************************************************/
#ifndef  _WriteOnly
U16 ff_Read(ff_FILE *f,
            U8      *dst,
            U16      len,
            U16     *lread);

#endif

/********************************************************
 Function   :  ff_Write
 Parameters : 
 Returns    : 
 Description:
********************************************************/
/*lint -esym(757, ff_Write) */	// disable warning "global declarator not referenced"
U16 ff_Write(ff_FILE *f,
             U8      *src,
             U16      len);

/********************************************************
 Function   :  ff_Seek
 Parameters : 
 Returns    : 
 Description:
********************************************************/
#ifndef  _WriteOnly
U16 ff_Seek(ff_FILE *f,
            U32      pos);

#endif

/********************************************************
 Function   :  ff_Msg
 Parameters : 
 Returns    : 
 Description:
********************************************************/
#ifdef _MsgAvailable
static U16 ff_Msg(ff_FILE *f,
                  U8       type,
                  void    *p);

#endif

#endif /* ifndef _FF_FLASHFILE_PUBLIC_H_ */

