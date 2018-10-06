/*!
 @file   _SerFlashdrv_public.h

 <hr>
 <h2> File Creation </h2>
 @author mroggon

 @date   26.09.2013 - 13:41:05

 @caliberrm TODO: Link to CaliberRM in SerFlashdrv_public.h

 @brief  TODO: Description of SerFlashdrv_public.h
 

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
 00.00  26.09.2013   mroggon    Initial start
 -----  ----------   -------   ------------------------------------------------
 @endverbatim

 Copyright &copy; 2013 Danfoss. All rights reserved.
 */
 
#ifndef __SERFLASHDRV_PUBLIC_H__
#define __SERFLASHDRV_PUBLIC_H__


/*-------------------------------------------------------
   Include files
   -------------------------------------------------------*/


/*-------------------------------------------------------
   Definitions
   -------------------------------------------------------*/


/*-------------------------------------------------------
   Type definitions
   -------------------------------------------------------*/


typedef enum{
	UNPACKED          = 0,  // 8 bits is copied into each word, 0 in high byte
	PACKED,                 // 16 bits are copied into each word
	UNPACKED_SIGNED			// 8  bits is copied into each word,
	                        // 0 or FF in high byte depending on bit 7 low byte
}PACK_MODE_T;




// Handler for serial flash reading
typedef struct serhnd {
	  struct serhnd *Next; 	 // Is a member in a queue of rad jobs
	  U16  *Dest;			 // where to store the data
	  U32  NBytes;			 // number of bytes to read
	  U32  Addr;			 // Byte offset in serial flash
	  BOOL Pending;			 // Not ready yet
	  PACK_MODE_T Pack;	     // packing mode see enum type
}ReadSerFlashHnd_T;

typedef struct
{
   ReadSerFlashHnd_T  *First;
   ReadSerFlashHnd_T  *Last;
}ReadSerFlashHndList_T;

/*-------------------------------------------------------
   Variables
   -------------------------------------------------------*/


/*-------------------------------------------------------
   prototype functions
   -------------------------------------------------------*/


/*-------------------------------------------------------
   functions
   -------------------------------------------------------*/


#endif /* __SERFLASHDRV_PUBLIC_H__ */
