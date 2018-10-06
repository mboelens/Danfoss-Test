/*!
   @file   unitinfo_hw.h

   <hr>
   <h2> File Creation </h2>
   @author jbendixen

   @date   10.09.2010 - 18:29:32

   @caliberrm ME Modular SIL Kernel TASK38420

   @brief Contains the declaration to the ID information block


  ********************************************************/
#ifndef UNITINFO_HW_H
#define UNITINFO_HW_H



typedef struct
{
   S_OTP_BASE_STRUCT_t       S_Base;
   S_BOARD_REVISION_STRUCT_t S_Revision;
   S_END_STRUCT_t            S_End;
   U16                   U16_CheckSum; 
}S_OTP_STRUCT_t;

#endif


