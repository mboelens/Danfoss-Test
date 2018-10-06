/*!
   @file   idapp.h

   <hr>
   <h2> File Creation </h2>
   @author jbendixen

   @date   10.09.2010 - 18:29:32

   @caliberrm ME Modular SIL Kernel TASK38420

   @brief Contains the declaration to the ID information block


  ********************************************************/

#ifndef _IDAPP_
#define _IDAPP_


// Define Constant Memory Space for AppId_T in PLUS1 Tool, not used, must be defined
#define _CMS_AppId_T
// Define Memory Space for AppId_T in PLUS1 Tool, not used, must be defined
#define _MS_AppId_T

/* do not change naming convention - interface with GUIDE */

typedef struct{
   U16 b0 : 8;
   U16 b1 : 8;
   U16 b2 : 8;
   U16 b3 : 8;
   U16 b4 : 8;
   U16 b5 : 8;
   U16 b6 : 8;
   U16 b7 : 8;
}_Plus1Ver_T;

typedef struct{
   U16 b0 : 8;
   U16 b1 : 8;
   U16 b2 : 8;
   U16 b3 : 8;
   U16 b4 : 8;
   U16 b5 : 8;
   U16 b6 : 8;
   U16 b7 : 8;
   U16 b8 : 8;
   U16 b9 : 8;
   U16 b10 : 8;
   U16 b11 : 8;
   U16 b12 : 8;
   U16 b13 : 8;
   U16 b14 : 8;
   U16 b15 : 8;
   U16 b16 : 8;
   U16 b17 : 8;
}IdByte18;

/*lint -esym(960, 18.4) */ /* disable lint warning about union declaration */
typedef union {
   IdByte18          bf;
   U16              u16[9];
}_TIMEKEY_T;


typedef struct{
   U16 b0 : 8;
   U16 b1 : 8;
   U16 b2 : 8;
   U16 b3 : 8;
   U16 b4 : 8;
   U16 b5 : 8;
   U16 b6 : 8;
   U16 b7 : 8;
   U16 b8 : 8;
   U16 b9 : 8;
   U16 b10 : 8;
   U16 b11 : 8;
   U16 b12 : 8;
   U16 b13 : 8;
   U16 b14 : 8;
   U16 b15 : 8;
   U16 b16 : 8;
   U16 b17 : 8;
   U16 b18 : 8;
   U16 b19 : 8;
   U16 b20 : 8;
   U16 b21 : 8;
   U16 b22 : 8;
   U16 b23 : 8;
   U16 b24 : 8;
   U16 b25 : 8;
   U16 b26 : 8;
   U16 b27 : 8;
   U16 b28 : 8;
   U16 b29 : 8;
   U16 b30 : 8;
   U16 b31 : 8;
   U16 b32 : 8;
   U16 b33 : 8;
   U16 b34 : 8;
   U16 b35 : 8;
   U16 b36 : 8;
   U16 b37 : 8;
   U16 b38 : 8;
   U16 b39 : 8;
   U16 b40 : 8;
   U16 b41 : 8;
   U16 b42 : 8;
   U16 b43 : 8;
   U16 b44 : 8;
   U16 b45 : 8;
   U16 b46 : 8;
   U16 b47 : 8;
   U16 b48 : 8;
   U16 b49 : 8;
   U16 b50 : 8;
   U16 b51 : 8;
   U16 b52 : 8;
   U16 b53 : 8;
   U16 b54 : 8;
   U16 b55 : 8;
   U16 b56 : 8;
   U16 b57 : 8;
   U16 b58 : 8;
   U16 b59 : 8;
   U16 b60 : 8;
   U16 b61 : 8;
}IdByte62;

/*lint -esym(960, 18.4) */ /* disable lint warning about union declaration */
typedef union {
   IdByte62         bf;
   U16              u16[31];
}_AppId1_T;



typedef struct{
   U16 b0 : 8;
   U16 b1 : 8;
   U16 b2 : 8;
   U16 b3 : 8;
   U16 b4 : 8;
   U16 b5 : 8;
   U16 b6 : 8;
   U16 b7 : 8;
   U16 b8 : 8;
   U16 b9 : 8;
   U16 b10 : 8;
   U16 b11 : 8;
   U16 b12 : 8;
   U16 b13 : 8;
   U16 b14 : 8;
   U16 b15 : 8;
   U16 b16 : 8;
   U16 b17 : 8;
   U16 b18 : 8;
   U16 b19 : 8;
   U16 b20 : 8;
   U16 b21 : 8;
   U16 b22 : 8;
   U16 b23 : 8;
   U16 b24 : 8;
   U16 b25 : 8;
   U16 b26 : 8;
   U16 b27 : 8;
   U16 b28 : 8;
   U16 b29 : 8;
   U16 b30 : 8;
   U16 b31 : 8;
   U16 b32 : 8;
   U16 b33 : 8;
   U16 b34 : 8;
   U16 b35 : 8;
   U16 b36 : 8;
   U16 b37 : 8;
   U16 b38 : 8;
   U16 b39 : 8;
   U16 b40 : 8;
   U16 b41 : 8;
}IdByte42;

/*lint -esym(960, 18.4) */ /* disable lint warning about union declaration */
typedef union {
   IdByte42          bf;
   U16              u16[21];
}_AppId2_T;



typedef struct{
   U16 b0 : 8;
   U16 b1 : 8;
   U16 b2 : 8;
   U16 b3 : 8;
   U16 b4 : 8;
   U16 b5 : 8;
   U16 b6 : 8;
   U16 b7 : 8;
   U16 b8 : 8;
   U16 b9 : 8;
   U16 b10 : 8;
   U16 b11 : 8;
   U16 b12 : 8;
   U16 b13 : 8;
   U16 b14 : 8;
   U16 b15 : 8;
   U16 b16 : 8;
   U16 b17 : 8;
   U16 b18 : 8;
   U16 b19 : 8;
   U16 b20 : 8;
   U16 b21 : 8;
   U16 b22 : 8;
   U16 b23 : 8;
   U16 b24 : 8;
   U16 b25 : 8;
   U16 b26 : 8;
   U16 b27 : 8;
   U16 b28 : 8;
   U16 b29 : 8;
   U16 b30 : 8;
   U16 b31 : 8;
}IdByte32;

/*lint -esym(960, 18.4) */ /* disable lint warning about union declaration */
typedef union {
   IdByte32          bf;
   U16              u16[16];
}_AppId3_T;



extern _TIMEKEY_T _TIMEKEY;
extern U8 *_EAsK3BsX;/*lint -esym(757, _EAsK3BsX) */ /* Lint warns that the declarator is not referenced, but it is used in the GUIDE */

#endif
