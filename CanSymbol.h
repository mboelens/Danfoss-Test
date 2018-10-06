/*****************************************************************************
   Filename : _cansymbol_public.h   Library:

   Vers:  Date:     Name:      Comment:
   -----  -------   -------    ------------------------------------------------
   02.01  28Feb05   fbjorn     Initial start

   Description :     This file is the public part of cansymbol.h
            It will be visible for the GUIDE Code generator and
            therefore also readable for the GUIDE user


*****************************************************************************/

#ifndef CANSYMBOL_H
#define CANSYMBOL_H

/*-------------------------------------------------------
   include files
   -------------------------------------------------------*/

#include "datatypes.h"

/*-------------------------------------------------------
   Definitions
   -------------------------------------------------------*/

/*-------------------------------------------------------
   Type definitions
   -------------------------------------------------------*/

/* the following structure is interfaced with GUIDE, do not change names */
typedef struct _cansym_tx_struct
{
   // Public
   U32    id;        // Input
   BOOL   ext;       // Input
   BOOL   rtr;       // Input
   U8     dlc;       // Input
   U8    *data;      // Input
   BOOL   tx;        // Input
   PORT   port;      // Input
   BOOL   override;  // Output
   BOOL   pending;   // Output
   // Private
   struct _cansym_tx_struct  *Next;
   U32                        last_id;
   U8   last_data[8];
   U8   last_dlc;
}_CANSYM_TX_T;


typedef struct _cansym_rx_struct
{
   // Public
   U32    idfilter;   // Input
   U32    idmask;     // Input
   BOOL   ext;        // Input
   BOOL   rtr;        // Input
   U32    id;         // Output
   U8     dlc;        // Output
   U8     data[8];    // Output
   BOOL   rx;         // Output
   BOOL   overflow;   // Output
   U8    *datafilter; // Input
   U8    *datamask;   // Input
   U8     masklen;    // Input
   BOOL protected;    // Input
   PORT   port;       // Input
   // Private
   struct _cansym_rx_struct  *Next;
}_CANSYM_RX_T;

/*-------------------------------------------------------
   Variables
   -------------------------------------------------------*/


/*-------------------------------------------------------
   prototype functions
   -------------------------------------------------------*/


/*-------------------------------------------------------
   functions
   -------------------------------------------------------*/

extern void _CANSYM_TX_ADD(_CANSYM_TX_T *CanSymTx);

/********************************************************
   Parameters :   CanSymTx
   Returns    :   nothing
   Description:   Resets and adds the CanSymTx symbol to
                a list with all symbols
 *********************************************************/

extern void _CANSYM_RX_ADD(_CANSYM_RX_T *CanSymRx);

/********************************************************
   Parameters :   CanSymTx
   Returns    :   nothing
   Description:   This function resets a can rx symbol structure
            and includes it in the list of receive symbols
 *********************************************************/
#if NUMBER_CANMESSAGES

extern void _CANSYM_TX_REMOVE(const _CANSYM_TX_T *CanSym);

extern void _CANSYM_RX_REMOVE(const _CANSYM_RX_T *CanSym);

#endif

extern void AC_V_ProcessCanRxSymbols(void);

extern void AC_V_ProcessCanTxSymbols(void);

extern void AC_V_DisableCanSymbols(void);

extern void AC_V_EnableCanSymbols(void);

#endif /* ifndef CANSYMBOL_H */

