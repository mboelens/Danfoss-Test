/*
 * datacontainer.h
 *
 *  Created on: Jun 10, 2010
 *      Author: mbyrnes
 */

#ifndef DATACONTAINER_H_
#define DATACONTAINER_H_

#define NUMBER_CANCONTROLLERS   MAKEDEF_NMB_CAN_CONTROLLER

#include "P1_OS.h"
#include "idapp.h"
#include "InfoBlocks.h"
#include "interface.h"

extern const S_OS_STRUCT_t   g_KS_Os;

extern U8   _ElapsedTime[NUMBER_TIME_ELEMENTS];

/** \brief Filled by code generator of the GUIDE, called every loop */
extern void _MAINTASK(void);

/** \brief Filled by code generator of the GUIDE, called once before first loop cycle */
extern void _INITTASK(void);

extern _MS_AppId_T _AppId1_T  *_AppId1;    ///< Filled by code generator of the GUIDE, contains name/description of the application
extern _MS_AppId_T _AppId2_T  *_AppId2;    ///< Filled by code generator of the GUIDE, contains type of the application
extern _MS_AppId_T _AppId3_T  *_AppId3;    ///< Filled by code generator of the GUIDE, contains version of the application

extern void ECU_V_InitDataContainer(void);


#endif /* DATACONTAINER_H_ */

