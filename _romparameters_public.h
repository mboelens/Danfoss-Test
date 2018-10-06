/**
   \file _romparameters_public.h
   This is the header file belonging to romparameters.c

   \b History
   \verbatim
   Vers:   Date:     Name:     Comment:
   -----  -------   -------   ------------------------------------------------
   02.53  03Oct06   fbjorn    Initial start
   03.05  4Apr08    fbjorn    Support for multipple rom parameters
   03.15  03Nov08   mkrebs    Changed/added comments for doxygen                          
          
   \endverbatim
  */

#ifndef _ROMPARAMETERS_PUBLIC_H
#define _ROMPARAMETERS_PUBLIC_H


/*-------------------------------------------------------
   include files
-------------------------------------------------------*/

/*-------------------------------------------------------
   Definitions
-------------------------------------------------------*/

#define _FILEMEM	

#define _MultipleFiles ///< undefine this to support single ROP File

#ifdef __TMS320C28XX__
	#ifdef _MultipleFiles
	    #define ROPPort 0x3F4000	 ///< ROP Port
	    #define _PARAFILE_ADDR(Port, ByteOffset) ((Port)+((ByteOffset)>>1))   ///< Parameter file address
	#else
	    #define _PARAFILE_ADDR(n) 0x3F4000 						 ///< Parameter file address
	#endif						
#else
	#ifdef _MultipleFiles
	    #define ROPPort 0x08008000	 ///< ROP Port
	    #define _PARAFILE_ADDR(Port, ByteOffset) ((Port)+((ByteOffset)))   ///< Parameter file address
	#else
	    #define _PARAFILE_ADDR(n) 0x08008000 						 ///< Parameter file address
	#endif						
#endif																							 
/*-------------------------------------------------------
   Type definitions
-------------------------------------------------------*/

/*-------------------------------------------------------
   Variables
-------------------------------------------------------*/

/*-------------------------------------------------------
   functions
-------------------------------------------------------*/

#ifdef _MultipleFiles
_FILEMEM void* _U__USES_PARAM(const TL *FileType,U32 CRC,BOOL *Valid,U32 Port,U32 ByteOffset);
#else
_FILEMEM void* _U__USES_PARAM(const TL *FileType,U32 CRC,BOOL *Valid);
#endif

/********************************************************
*********************************************************/

#endif
