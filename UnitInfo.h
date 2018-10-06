/*!
   @file   UnitInfo.h

   <hr>
   <h2> File Creation </h2>
   @author jbendixen

   @date   10.09.2010 - 18:29:32

   @caliberrm ME Modular SIL Kernel TASK38420

   @brief Contains the declaration to the ID information block


  ********************************************************/
#ifndef _UNITINFOH_
#define _UNITINFOH_
/*lint -esym(537, unitinfo.h) */

#define NMB_HIST_ENTRYS (20U)
/* Possible types in structure */
typedef enum{
   IDTYPE_END = 0,          /* this is the last item in the list */
   IDTYPE_BASE_TYPE,        /* U16A_PNr2 + serial */
   IDTYPE_REVISION,         /* board revision */
   IDTYPE_UNIT_INFORMATION,
   IDTYPE_SOFTWARE_ACCESS
}IDTYPE_ENUM;

#define SPACE_CHAR (0x30U)

#define DIGIT0_OF_NUMBER(number) (((number)%10U)/1U)
#define DIGIT0_OF_NUMBER_CHAR(number) (DIGIT0_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT1_OF_NUMBER(number) (((number)%100U)/10U)
#define DIGIT1_OF_NUMBER_CHAR(number) (DIGIT1_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT2_OF_NUMBER(number) (((number)%1000U)/100U)
#define DIGIT2_OF_NUMBER_CHAR(number) (DIGIT2_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT3_OF_NUMBER(number) (((number)%10000U)/1000U)
#define DIGIT3_OF_NUMBER_CHAR(number) (DIGIT3_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT4_OF_NUMBER(number) (((number)%100000UL)/10000U)
#define DIGIT4_OF_NUMBER_CHAR(number) (DIGIT4_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT5_OF_NUMBER(number) (((number)%1000000UL)/100000UL)
#define DIGIT5_OF_NUMBER_CHAR(number) (DIGIT5_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT6_OF_NUMBER(number) (((number)%10000000UL)/1000000UL)
#define DIGIT6_OF_NUMBER_CHAR(number) (DIGIT6_OF_NUMBER(number)+SPACE_CHAR)

#define DIGIT7_OF_NUMBER(number) (((number)%100000000UL)/10000000UL)
#define DIGIT7_OF_NUMBER_CHAR(number) (DIGIT7_OF_NUMBER(number)+SPACE_CHAR)


typedef enum
{
   eUPDATE_DONE = 0,
   eUPDATE_REQUEST,
   eUPDATE_BUSY,
   eUPDATE_FAULT
}E_HW_InfoUpdateStatusType_t;


typedef struct{
 U16 U16_IDType;
 U16 U16_SizeType;
}S_TypeSTRUCT_t;

typedef struct 
{
	U16 U16_StructVersion;
	U16 U16A_PNr2[3];
	U16 U16A_SerNr0[3];
	U16 U16A_BDate[4];
	U16 U16_SizeOfAll;
}S_OTP_BASE_STRUCT_t;

typedef struct 
{
	S_TypeSTRUCT_t S_Type;
	U16 U16_BoardRevNumber;
	U16 U16_BoardIdNumberLW;
	U16 U16_BoardIdNumberHW;
	U16 U16_EEPROMSizeLW;
	U16 U16_EEPROMSizeHW;
}S_BOARD_REVISION_STRUCT_t;


typedef struct 
{
   S_TypeSTRUCT_t S_Type;

}S_END_STRUCT_t;

typedef struct 
{

   U16 U16_StructVersion;
   U8  U8A_PNr0[12];
   U8  U8A_PRev0[4];
   U8  U8A_PNr1[12];
   U8  U8A_PRev1[4];
   U16 U16_SizeOfAll;
   U16 U16_CheckSum;
}S_CONFIGURATION_BASE_STRUCT_t;

typedef struct 
{
   S_TypeSTRUCT_t S_Type;
   U32   U32_NodeID;         // node identifier
   U8    U8A_OS[42];	     // OS Description
   U8    U8A_AppCmplTime[8]; // Time Stamp of the compilation
   U8    U8A_Plus1Ver[8];    // PLUS1 version used by the compiler
   U8    U8A_AppId[52];      // Program identity
   U8    U8A_AppType[32];    // Program Type
   U8    U8A_AppVer[22];     // Program Version
   U16   U8A_ExpP[3];        // Extended Info Blockpointer
   U16   U16_CheckSum;       // Checksum of info block
}S_UNIT_INFORMATION_STRUCT_t; 


typedef struct
{
   U16   U16_Format;         // should always be one 
   U16   U16_Date;           // days since 2000-01-01
   U16   U16_License;        // uilicense number
   U16   U16_User;	         // USER information
   U16   U16_Activity;       // LSB what has been done ; MSB failure or not
   U16   U16A_AppCmplTime[4];// Time Stamp of the compilation
   U16   U16A_FileName[4];   //
   U16   U16_CheckSum;       // Checksum of info block
}S_UNIT_HISTORY_STRUCT_t;

typedef struct _FLASHSTATUS
{

  U32  U32_NbmrOfExeDwnloads;
  U32  U32_FirstFailedAddress;
  U16  U16_StatusFlashloader;
  U16  U16_Timelock;
  U16  U16_LastProgError;
  U16  U16_ExpectedData;
  U16  U16_ActualData;
  U16  U16_LastHistoryRecord;

}S_FLASHSTATUS_ST_t;


/*****************************************************************************
Description: check checksum of the OTP

Parameters:  nothing

Returns:     ERROR_NO if checksum OK, else  ERROR_HARDWARE
******************************************************************************/
extern U16 K_U16_CheckOTPChecksum(void);


extern U16 K_U16_GetKernelProductionInfo(U16 *puiaPNr2, U16 *puiaSerNr0, U16 * puiaBirth);
/*****************************************************************************
Description: get the production ean ser and date

Parameters:  puiaPNr2 = destination pointer for U16A_PNr2
             puiaSerNr0 = destination pointer for U16A_SerNr0 number
             puiaBirth = destination pointer for birth information

Returns:     0= ERROR_NO, else error
******************************************************************************/

extern U16 K_U16_GetHardwareRevision(U16 *puiRevision,
                                  U32 *pulBoardIdentNumber,
                                  U32 *pulEEpromSize       );
/*****************************************************************************
Description: get the susmic hardware revision

Parameters: puiRevision pointer to ID to revision
            pulBoardIdentNumber     destination pointer to seperate board identnumber
            pulEEpromSize           destination pointer to eepromsize
Returns:     error
******************************************************************************/


extern U16 K_U16_GetKernelHWInfo(U8 * pPNr0, U8 *prev0, U8 * pPNr1, U8 *prev1);
/*****************************************************************************
Description: get the production ean ser and date

Parameters:  pPNr0  = destination pointer for Part number 0
             prev0  = destination pointer for revision number 0
             pPNr1  = destination pointer for Part number 1
             prev1  = destination pointer for revision number 1

Returns:     0= ERROR_NO, else error
******************************************************************************/



extern E_HW_InfoUpdateStatusType_t K_E_SetKernelHWInfo(const U8 * pPNr0,
                                         const  U8 *prev0,
                                         const  U8 * pPNr1,
                                         const  U8 *prev1);
/*****************************************************************************
Description: set the production ean ser and date and request a storage to eeprom

Parameters:  pPNr0  = destination pointer for Part number 0
             prev0  = destination pointer for revision number 0
             pPNr1  = destination pointer for Part number 1
             prev1  = destination pointer for revision number 1

Returns:     E_HW_InfoUpdateStatusType_t acutal status of the update process
******************************************************************************/

extern E_HW_InfoUpdateStatusType_t K_E_CheckKernelHWInfoStatus(void);
/*****************************************************************************
Description: checks the writing status to the eeprom

Parameters:  none
             
Returns:     E_HW_InfoUpdateStatusType_t acutal status of the update process
******************************************************************************/

extern void K_V_KernelHWInfoUpdate(void);
/*****************************************************************************
Description: checks the update request flag and writes the
             structure to the EEPROM

Parameters:  none
             
Returns:     void
******************************************************************************/

extern U16 K_V_ReadEEPROMUnitInfo(S_UNIT_INFORMATION_STRUCT_t   *psUnit);
/*****************************************************************************
Description: Reads the Application information from the EEPROM

Parameters:  none

Returns:     void
******************************************************************************/

extern U16 K_V_WriteEEPROMUnitInfo(const S_UNIT_INFORMATION_STRUCT_t   *psUnit);
/*****************************************************************************
Description: Writes the Application information to the EEPROM

Parameters:  none

Returns:     void
******************************************************************************/

#endif


