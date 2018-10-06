/*****************************************************************************
Filename : _binfilehndl_public.h    Library:

Vers:  Date:     Name:     Comment:
-----  -------   -------   ------------------------------------------------
02.57  09Feb07   fbjorn    Initial start
	   02Apr07	 fbjorn    changed after review 30Apr2007 
       04May07   fbjorn    changed so that the file and handler can be created
                           separately, required an init function
02.91  23Nov07   fbjorn    Fixed Defect P1McX157 

Description : 	header for binfilehndl.c
				this header file provides macro definitions to declare a 
				"compiled binary file", and to declare a handler for that file
				and the interface to process it.
*****************************************************************************/


#ifndef _BINFILEHNDL_PUBLIC_H
#define _BINFILEHNDL_PUBLIC_H
/*-------------------------------------------------------
   include files
-------------------------------------------------------*/

	#include "datatypes.h"
	#include "_SerFlashDrv_public.h"
#ifdef __TMS320C28XX__
    #ifndef NULL
       #define NULL (0)
    #endif
#endif

/*-------------------------------------------------------
   Definitions
-------------------------------------------------------*/

// Size in byte of each data type and sign in bit 7
#define _BFSizeBOOL 0x01
#define _BFSizeS8   0x81
#define _BFSizeU8   0x01
#define _BFSizeS16  0x82
#define _BFSizeU16  0x02
#define _BFSizeS32  0x84
#define _BFSizeU32  0x04

// Mask the byte size
#define _BFTypeSize(n) ((n) & 0xF)
// Mask the sign
#define _BFTypeIsSigned(n) ((n) & 0x80)

// _CreateBinFile must be defined before this header file
#ifdef _CreateBinFile


    #ifdef __TMS320C28XX__

        // Macro to create the binary file as a constant at the location of the
        // desiered memory
        #pragma DATA_SECTION(_BinFileSymbol, "serinformation")
        /*lint -esym(714,_BinFileSymbol) */  


        /* _CREATE_BINFILE_START
           Parameters :	Type		Data type of the File
        */
        #define _CREATE_BINFILE_START(Type) \
            static const Type _BinFileSymbol[] = {

        /* _CREATE_BINFILE_END
           Parameters : 
           FileName     Global Name of the file
		   FileSize	    Size (in byte) of the Binary File 
        */
        #define _CREATE_BINFILE_END(Name,FileSize) }; \
        _BINFILE_ENTRY_T Name = { (U32)_BinFileSymbol,FileSize };

 
    #endif  // ifdef __TMS320C28XX__

    /* Example : 
    _CREATE_BINFILE_START(U16)
    0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
    0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
    _CREATE_BINFILE_(MyFile,32)
    */

#endif	 // ifdef _CreateBinFile


/* _EXTERN_BINFILE
   Parameters : 
   FileName	Name of the binary 
*/
#define _EXTERN_BINFILE(FileName) extern _BINFILE_ENTRY_T FileName;


/* _CREATE_BINFILE_HANDLER_END
   Parameters : 
   HandlerName 	Name of the handler
   BuffSize Output buffer size
   Type		Data type of the output buffer BOOL,S8...U32
*/
#define _CREATE_BINFILE_HANDLER(HandlerName,BuffSize,Type)  \
static Type _##HandlerName##Buffer[BuffSize]; \
_BINFILE_HANDLER_T HandlerName = {      \
    /* Size */              0,          \
    /* Address */           0,          \
    /* Position */          0,          \
    /* LastPosition */      (U32)-1,    \
    /* ValidValues */       0,          \
    /* BufferSize */        BuffSize,   \
    /* Buffer */            {_##HandlerName##Buffer}, \
    /* hnd */               {NULL,NULL,0,0,FALSE,FALSE}, \
    /* Status */            0,          \
    /* BufferTypeWidth */   _BFSize##Type };


#define _BINFILE_INIT(HandlerName,FileName) gBinFileInit(&HandlerName,&FileName);
						
#define _BINFILE_PROCESS(HandlerName) gBinFileProcess(&HandlerName);
																					 
/*-------------------------------------------------------
   Type definitions
-------------------------------------------------------*/


typedef struct 
{
    U32 Address;
    U32 Size;
} _BINFILE_ENTRY_T;

typedef struct 
{
	U32 Size;	   	    // File Size is set at initialization, 		output
	U32 Address;   	    // File address is set at initialization, 	internal
	U32 Position;  		// Current start position in the file , 	input
	U32 LastPosition; 	// Position previous loop                   internal
	U32 ValidValues;  	// The number of valid values in Buffer 	output
	U32 BufferSize;	  	// Number of elements in the buffer			internal
	union {
		void *p;
		BOOL *bool;
		S8 *s8;
		U8 *u8;
		S16 *s16;
		U16 *u16;
		S32 *s32;
		U32 *u32;
	} Buffer;				// The output buffer, output
	ReadSerFlashHnd_T hnd;	// serial flash handler
	U16 Status;				// File status , output
	U8 BufferTypeWidth;		// Buffer element width in bytes 
} _BINFILE_HANDLER_T;

/*-------------------------------------------------------
   Variables
-------------------------------------------------------*/

/*-------------------------------------------------------
   prototype functions
-------------------------------------------------------*/

/*-------------------------------------------------------
   functions
-------------------------------------------------------*/

extern void gBinFileInit(_BINFILE_HANDLER_T *FileHnd,const _BINFILE_ENTRY_T *BinFile);
/********************************************************
 Parameters : 	FileHnd 	-	handler to the binary file
                BinFile     -   the bin file
 Returns    : 	Nothing 
 Description: 	Assigns the BinFile to the handler
                Initializes the handler 
*********************************************************/



extern void gBinFileProcess(_BINFILE_HANDLER_T *FileHnd);
/********************************************************
 Parameters : 	FileHnd	-	handler to the binary file
 Returns    : 	Nothing 
 Description: 	A new read task in background is started
                if the requested file position has changed 
*********************************************************/

#endif

