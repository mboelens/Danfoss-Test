




#ifndef __INFOBLOCKS_H__
#define __INFOBLOCKS_H__

#include "datatypes.h"
#include "UnitInfo.h"
#include "UnitInfo_HW.h"


#define _id_ApplicationFileType (0U)
#define _id_PLGFileType (1U)
#define _id_ParameterFileType (2U)
#define _id_AppLogFileType (3U)
#define _id_HistLogFileType (4U)
#define _id_RopFileType (5U)


//// This struct describes parameters that the diagnostic tool needs to fill in RequestDownload and TransferData command
//typedef struct ff1s
//{
//  U16 RequestDownloadParameterType : 2; // 0 = TargetDescriptionInfo, 1 .. 3 is reserved
//  U16 TargetLocatonDefMode         : 2; // 0 = ByLocalId, 1 = ByAddress, 2=ByName, 3 is  reserved
//  U16 TransferDataFrameFormat      : 2; // 0 = Undefined, 1 = StandardFrameFormat, 2..3 is reserved
//  U16 TransferDataFormat           : 2; // 0 = Binary, 1 = Binary Intel Hex, 2 .. 3 is reserved
//  U16 TargetType_Application       : 1; // 0 = not supported, 1 = supported
//  U16 TargetType_Parameter         : 1; // 0 = not supported, 1 = supported
//  U16 reserved                     : 6; // 0 = Reserved
//} FUCTION_FIELD1_STRUCT;

#define REQDOWNLOADPARATYPE_TARGET     0x0000U

#define LOCALDEFMODE_BYLOCALID         0x0000U
#define LOCALDEFMODE_BYADDRESS         0x0004U
#define LOCALDEFMODE_BYNAME            0x0008U

#define TRANSFERDATAFRAMEFMT_UNDEF     0x0000U
#define TRANSFERDATAFRAMEFMT_STD       0x0010U

#define TRANSFERDATAFMT_UNDEF          0x0000U
#define TRANSFERDATAFMT_STD            0x0040U

#define TARGETTYPEAPP_NOTSUPPORTED     0x0000U
#define TARGETTYPEAPP_SUPPORTED        0x0100U
#define TARGETTYPEPARAM_NOTSUPPORTED   0x0000U
#define TARGETTYPEPARAM_SUPPORTED      0x0200U

/* No naming convention changes to the info block - interface with GUIDE */
typedef struct Id5
{
 U16  InfoBlockTyp : 8 ;      // LB = BlockType, HB = key 0
 U16  key0 : 8;
 U16  Key[4];                 // key 1 - key 8
 U16  Key9: 8;                // LB = key 9, HB = filetype
 U16  FileType : 8;
 U16  AppCmplTime[4];         // Tidstämpel från kompileringstillfället
 U16  File[23];               // ID.File
 U16  Type[23];               // ID.Type
 U16  Version[23];            // ID.Version
 U16  AddrMode[23];           // ID.AddressMode
 U16  Size[2];                // Storlek av hela filen inkl detta infoblock
 U16  CRCA[2];                 // CRC
 U16  FileP[4];               // Pekare till fil;
 U16  dummy : 8;
 U16  CheckSum : 8;           // LB = dummy, HB =Checksumma för infiblock 4
 U16  Status;                 // Status, FFFF ej OK, 0000 OK
} id_INFOBLOCKTYP5;

typedef struct Id6
{
   U16 InfoBlockTyp_FileType; // LB = BlockType, HB = FileType
   U16 FileAttr;              // File Attribute
   U32 FreeSpace;             // Free Space on  Drive/Path (bytes)
   U16 FileSysType;           // Type of File system ,bit 0 Erase all, bit 1 Single File
   U16 Path[3];               // Pointer to name of the Drive/Path
   U16 FileP[3];              // Pointer to the File
   U16 ExpP[3];               // Pointer to more info blocks
   U16 CheckSum;              // LB = dummy, HB =Checksumma for infoblock 4
} id_INFOBLOCKTYP6;


typedef struct Id10
{
    U16 InfoBlockTyp;              // type definition (set to 10)
    U8  ProtocolType;     // ProtocolType
    U8 ProtocolVersion;   // Protocol version
    U16 RxBufferLength;            // Receive buffer length
    U16 TxBufferLength;            // Transmit buffer length
    U8 NrOfDynLID;         // No of dynamic local ID:s
    U8 NrOfPosInDynLID;    // No of positions in dynamic local ID
    U16 ExpP[3];                   // Pointer to more info blocks
    U16 CheckSum;                  // Checksum of info block
}id_INFOBLOCKTYP10;


typedef struct// Id11
{
	   U16 InfoBlockTyp;   // type definition (set to 9)
	   U16 uiNodeIDLo;     // node identifier
	   U16 uiNodeIDHi;     // node identifier
	   U8  OS[42];         // OS Description
	   U16  AppCmplTime[4]; // Time Stamp of the compilation
	   U8  Plus1Ver[8];    // PLUS1 version used by the compiler
	   U16  PNr2[3];        // EAN code 40 bit Integer + Checksum
	   U16  SerNr0[3];      // Serial Number 40 bits integer
	   U16  BDate[4];       // Birth Date of HW
	   U16  PNr0[6];       // HW Part Number 0 (Basic)
	   U16  PRev0[2];       // HW Part Revision 0 (Basic)
	   U16  PNr1[6];       // HW Part Number 1 (Customer)
	   U16  PRev1[2];       // HW Part Revision 1 (Customer)
	   U16  AppId[26];      // Program identity
	   U16  AppType[16];    // Program Type
	   U16  AppVer[11];     // Program Version
	   U16 ExpP[3];        // Extended Info Blockpointer
	   U16 BootVer0;       // version of the bootloader
//	   FUCTION_FIELD1_UNION uFunctionField1; // functionality field 1
//	   FUCTION_FIELD2_UNION uFunctionField2; // functionality field 2
	   U16 FunctionField1; // functionality field 1, based on the following bitfield definitions:
	                         //  U16 RequestDownloadParameterType : 2; // 0 = TargetDescriptionInfo, 1 .. 3 is reserved
	                         //  U16 TargetLocatonDefMode         : 2; // 0 = ByLocalId, 1 = ByAddress, 2=ByName, 3 is  reserved
	                         //  U16 TransferDataFrameFormat      : 2; // 0 = Undefined, 1 = StandardFrameFormat, 2..3 is reserved
	                         //  U16 TransferDataFormat           : 2; // 0 = Binary, 1 = Binary Intel Hex, 2 .. 3 is reserved
	                         //  U16 TargetType_Application       : 1; // 0 = not supported, 1 = supported
	                         //  U16 TargetType_Parameter         : 1; // 0 = not supported, 1 = supported
	                         //  U16 reserved                     : 6; // 0 = Reserved
	   U16 FunctionField2; // functionality field 2, based on the following bitfield definitions:
	                         //  U16 ApplicationDefinedBaudRate   : 1; // 0 = not supported, 1 = supported
	                         //  U16 SerialFlash                  : 1; // 0 = not supported, 1 = supported
	                         //  U16 SequentialBlockDownload 	  : 1; // 0 = not supported, 1 = supported
	                         //	 U16 ExtParallelFLash			  : 1; // 0 = not supported, 1 = supported
	                         //	 U16 ExtDiagData				  : 1; // 0 = not supported, 1 = supported
	                         //	 U16 ExecutionMode				  : 2; // 0 = Unknown, 1 = bootloader, 2 = application, 3 = reserved
	                         //	 U16 reserved                     : 9;	// 0 = Reserved
	   U16 CheckSum;   // Checksum of info block
}id_INFOBLOCKTYP11;


typedef struct{
  S8              S8A_All[42];
}S_OS_STRUCT_t;

#define id_InfoBlock11 ECUInfoPacked
extern id_INFOBLOCKTYP11 id_InfoBlock11;
//extern id_INFOBLOCKTYP11 ECUInfoPacked;

extern void KC_V_InitInfoBlock11(id_INFOBLOCKTYP11   *InfoBlock11);

extern void KC_V_LoadAppInfo(id_INFOBLOCKTYP11   *InfoBlock11,
                        const U8                   OS_str[],
                        const U8                   TimeKey[],
                        const U8                   Plus1Ver[],
                        const U8                   AppID[],
                        const U8                   AppType[],
                        const U8                   AppVer[]);

extern void KC_V_LoadHWInfo(id_INFOBLOCKTYP11                    *InfoBlock11,
                            const S_CONFIGURATION_BASE_STRUCT_t  *HWInfo);

extern void KC_V_LoadProductionInfo(id_INFOBLOCKTYP11             *InfoBlock11,
                                    const S_OTP_BASE_STRUCT_t     *ProductionInfo);

extern void KC_V_UpdateNodeId(id_INFOBLOCKTYP11   *InfoBlock11,
                              U8                  Net,
                              U8                  Node);

extern void KC_V_InitAndAddInfoBlock6(id_INFOBLOCKTYP11   *InfoBlock11,
                                      id_INFOBLOCKTYP6    *InfoBlock6,
                                      U32                  PlgFile,
                                      U16                  PlgSize);

extern void KC_V_InitAndAddInfoBlock10(id_INFOBLOCKTYP6   *InfoBlock6,
                                       id_INFOBLOCKTYP10  *InfoBlock10,
                                       U16                 KWP2kRxBufferSize,
                                       U16                 KWP2kTxBufferSize);

extern void KC_V_UpdateAllInfoBlockChecksums(id_INFOBLOCKTYP11   *InfoBlock11);

extern void KC_V_GetAppInfo(S_UNIT_INFORMATION_STRUCT_t   *AppInfo,
                            const id_INFOBLOCKTYP11   *InfoBlock11);

extern void KC_V_GetHWInfo(S_CONFIGURATION_BASE_STRUCT_t   *HWInfo,
                           const id_INFOBLOCKTYP11     *InfoBlock11);





#endif

