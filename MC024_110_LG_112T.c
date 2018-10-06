/*Danfoss PLUS+1 GUIDE Software: [chpargu2] Version: 10.1.6*/
/*Type: Professional       */
/*Id: 444       */
/*Initials: MB       */
/*Maintenance until:  1-Jan-2020       */
/*Time limit: No limit       */
/*       */
/*       */
#include "header.h"
#ifdef R1
  //This is a workaround for HWD error: P1McX00000506:
  #undef R1
#endif
static void _FNC_123_b(void);
static _CANSYM_RX_T _CAN_MAINTASK__123_c;
static _CANSYM_RX_T _CAN_MAINTASK__123_d;
static void _FNC_123_e(void);
extern U32 _OS_MicroSec(void);
static U32 _LoopStart;
static U32 _ExecTimeOut_us;
int LoopDeadlineTimePassed(void)
{
  return (_OS_MicroSec() - _LoopStart) > _ExecTimeOut_us;
}
static uint32_t _TimeSinceStartupInMilliSeconds = 0;
uint32_t GetTimeSinceStartupInMilliSeconds(void)
{
  return _TimeSinceStartupInMilliSeconds;
}

void _INITMAINTASK(void)
{
OS.ExecTimeOut = 1;
C1p06.PinConfig = 2;
C1p07.PinConfig = 2;
C1p10.PinConfig = 2;
C1p11.PinConfig = 2;
C1p12.PinConfig = 2;
C2p01.PinConfig = 2;
C2p02.PinConfig0 = 0;
C2p02.PinConfig1 = 0;
C2p02.DigInConfigHigh = 3000;
C2p02.DigInConfigLow = 2000;
C2p02.FreqConfig = 0;
C2p03.PinConfig0 = 0;
C2p03.PinConfig1 = 0;
C2p03.DigInConfigHigh = 3000;
C2p03.DigInConfigLow = 2000;
C2p04.PinConfig0 = 0;
C2p04.PinConfig1 = 0;
C2p04.DigInConfigHigh = 3000;
C2p04.DigInConfigLow = 2000;
C2p05.PinConfig0 = 0;
C2p05.PinConfig1 = 0;
C2p05.DigInConfigHigh = 3000;
C2p05.DigInConfigLow = 2000;
C2p05.FreqConfig = 0;
C2p06.PinConfig0 = 0;
C2p06.PinConfig1 = 0;
C2p06.DigInConfigHigh = 3000;
C2p06.DigInConfigLow = 2000;
C2p07.PinConfig = 0;
C2p08.PinConfig = 0;
CAN[0].Baudrate = 250000;
ID.Net[0].Addr = 0;
ID.Node.ServerAddr = 2;
_CANSYM_RX_ADD(&_CAN_MAINTASK__123_c);
_CAN_MAINTASK__123_c.protected=0;
_CAN_MAINTASK__123_c.ext=1;
_CANSYM_RX_ADD(&_CAN_MAINTASK__123_d);
_CAN_MAINTASK__123_d.protected=0;
_CAN_MAINTASK__123_d.idfilter=0x200;
_CAN_MAINTASK__123_d.ext=0;
C2p09.PinConfig = 0;
C2p09.CurChgLim = 111;
C2p10.PinConfig = 0;
C2p11.PinConfig = 0;
C2p11.CurChgLim = 111;
C2p12.PinConfig = 0;
}
void _EndLoop_MAINTASK(void){
}
void _BeginLoop_MAINTASK(void){
}
static void _FNC_123_b(void)
{
       BOOL aUN8;
       U8 aUN11;
  S32 _ShLocTmpVar_S32_1;
       U8 aUN7;
static U8 aUN12;
       BOOL aUN9;
       BOOL aUN3;
static BOOL aUN3Old1;
static U16 aUN3Old2;
static BOOL aUN2;
       BOOL aUN1;
static BOOL aN1;
static BOOL aN1Old1;
       U8 aUN64;
       U8 aUN57;
       U8 aUN49;
       U8 aUN80;
       U8 aUN69;
       U8 aUN76;
       U8 aUN68;
       U8 aUN56;
       U16 aUN89;
       U16 aUN86;
       U16 aUN74;
       U16 aUN63;
static BOOL aUN65;
       BOOL aN182;
static BOOL aUN66;
       BOOL aN183;
static BOOL aUN87;
       BOOL aN185;
static BOOL aUN88;
       BOOL aN184;
       BOOL aUN90;
       BOOL aUN91;
       BOOL aUN48;
       BOOL aUN51;
       BOOL aN188;
       BOOL aN181;
       BOOL aN186;
       BOOL aN187;
       BOOL aUN71;
       U16 aUN85;
       BOOL aUN77;
       BOOL aUN75;
       BOOL aUN47;
       U16 aUN41;
       U16 aUN40;
       U16 aUN93;
       U32 aUN45;
       U32 aUN44;
       U32 aUN37;
       U32 aUN96;
       U32 aUN35;
       U32 aN198;
       S32 aN200;
       S32 aN201;
       U8 aN193;
       U8 aN194;
       U8 aN111;
       U8 aN175;
       U8 aN176;
       U8 aN177;
       U8 aN178;
       U8 aN179;
static BOOL aUN21;
static U8 aUN21Old1;
static U8 aUN21Old2;
       BOOL aN5;
       BOOL aUN20;
       BOOL aUN23;
       BOOL aUN22;
       BOOL aN6;
C1p06.PinConfig = 2;
C1p07.PinConfig = 2;
C1p10.PinConfig = 2;
C1p11.PinConfig = 2;
C1p12.PinConfig = 2;
C2p01.PinConfig = 2;
C2p02.PinConfig0 = 0;
C2p02.PinConfig1 = 0;
C2p02.DigInConfigHigh = 3000;
C2p02.DigInConfigLow = 2000;
C2p02.FreqConfig = 0;
C2p03.PinConfig0 = 0;
C2p03.PinConfig1 = 0;
C2p03.DigInConfigHigh = 3000;
C2p03.DigInConfigLow = 2000;
C2p04.PinConfig0 = 0;
C2p04.PinConfig1 = 0;
C2p04.DigInConfigHigh = 3000;
C2p04.DigInConfigLow = 2000;
C2p05.PinConfig0 = 0;
C2p05.PinConfig1 = 0;
C2p05.DigInConfigHigh = 3000;
C2p05.DigInConfigLow = 2000;
C2p05.FreqConfig = 0;
C2p06.PinConfig0 = 0;
C2p06.PinConfig1 = 0;
C2p06.DigInConfigHigh = 3000;
C2p06.DigInConfigLow = 2000;
C2p07.PinConfig = 0;
C2p08.PinConfig = 0;
aUN8=CAN[0].DriverError | CAN[0].BussOff;
  _ShLocTmpVar_S32_1 = !(aN1);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN11 = 1;
      break;
    default:
      aUN11 = 0;
  }
aUN7 = (aUN12)+(aUN11);
  _ShLocTmpVar_S32_1 = !(aUN8);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN12 = aUN7;
      break;
    default:
      aUN12 = 0;
  }
if ((aN1 == 0 && aUN8 == 0) || (aN1 != 0 && aUN8 != 0)) 
aUN9=0;
else
aUN9=1;
if (aUN9 && !aUN3Old1)
aUN3Old2 = 1000;
if (aUN3Old2 > _ElapsedTime[T1M])
{
aUN3Old2 = aUN3Old2 - _ElapsedTime[T1M];
aUN3=0;
}
else
{
aUN3Old2 = 0;
aUN3=aUN9;
}
aUN3Old1 = aUN9;
if (5 <= aUN12)
aUN2=0;
if ((5) > aUN12)
aUN2=1;
aUN1=aUN3 && aUN2;
if (aUN1 && !aN1Old1)
aN1=1;
else
aN1=0;
aN1Old1 = aUN1;
CAN[0].Reset=CAN[0].BussOff && aN1;
CAN[0].DriverReset=CAN[0].DriverError && aN1;
CAN[0].Baudrate = 250000;
  _CAN_MAINTASK__123_c.idmask = 0x03FFFFFF;
_CAN_MAINTASK__123_c.idfilter=0x25|0x00FEE800;
_CAN_MAINTASK__123_c.port=CAN[0].Port;
aUN64 = _CAN_MAINTASK__123_c.data[0];

aUN57 = _CAN_MAINTASK__123_c.data[1];

aUN49 = _CAN_MAINTASK__123_c.data[2];

aUN80 = _CAN_MAINTASK__123_c.data[3];

aUN69 = _CAN_MAINTASK__123_c.data[4];

aUN76 = _CAN_MAINTASK__123_c.data[5];

aUN68 = _CAN_MAINTASK__123_c.data[6];

aUN56 = _CAN_MAINTASK__123_c.data[7];

aUN89=(aUN64&(255))|(((U16)(aUN57))<<8);
aUN86=(aUN49&(255))|(((U16)(aUN80))<<8);
aUN74=(aUN69&(255))|(((U16)(aUN76))<<8);
aUN63=(aUN68&(255))|(((U16)(aUN56))<<8);
if (aUN57 >= 0xFB)
aUN65=1;
if ((aUN57) < 0xFB)
aUN65=0;
aN182 = aUN57 == 0xFF;
if (aUN80 >= 0xFB)
aUN66=1;
if ((aUN80) < 0xFB)
aUN66=0;
aN183 = aUN80 == 0xFF;
if (aUN76 >= 0xFB)
aUN87=1;
if ((aUN76) < 0xFB)
aUN87=0;
aN185 = aUN76 == 0xFF;
if (aUN56 >= 0xFB)
aUN88=1;
if ((aUN56) < 0xFB)
aUN88=0;
aN184 = aUN56 == 0xFF;
aUN90=!aN182;
aUN91=!aN183;
aUN48=!aN185;
aUN51=!aN184;
aN188=aUN90 && aUN65;
aN181=aUN91 && aUN66;
aN186=aUN48 && aUN87;
aN187=aUN51 && aUN88;
aUN71=aN182 | aN188;
  _ShLocTmpVar_S32_1 = !(aUN71);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN85 = 0;
      break;
    default:
      aUN85 = aUN89;
  }
aUN77=aN183 | aN181;
aUN75=aN185 | aN186;
aUN47=aN184 | aN187;
  _ShLocTmpVar_S32_1 = !(aUN77);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN41 = 0;
      break;
    default:
      aUN41 = aUN86;
  }
  _ShLocTmpVar_S32_1 = !(aUN75);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN40 = 0;
      break;
    default:
      aUN40 = aUN74;
  }
  _ShLocTmpVar_S32_1 = !(aUN47);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      aUN93 = 0;
      break;
    default:
      aUN93 = aUN63;
  }
aUN45=(U32)(1000)*(aUN85);
aUN44=(U32)(1000)*(aUN41);
aUN37=(U32)(1000)*(aUN40);
aUN96=(U32)(125)*(aUN93);
if (128!=0){
aUN35=(aUN37)/(128);
}else{
aUN35=0;}
if (128!=0){
aN198=(aUN45)/(128);
}else{
aN198=0;}
if (256!=0){
_TEST.CHECK.CP_SPN517_DanfossBlock=(aUN44)/(256);
}else{
_TEST.CHECK.CP_SPN517_DanfossBlock=0;}
aN200=(aUN35)-(200000);
aN201=(aUN96)-(2500000);
_CAN_MAINTASK__123_d.port=CAN[0].Port;
aN193 = _CAN_MAINTASK__123_d.data[0];

aN194 = _CAN_MAINTASK__123_d.data[1];

aN111 = _CAN_MAINTASK__123_d.data[2];

aN175 = _CAN_MAINTASK__123_d.data[3];

aN176 = _CAN_MAINTASK__123_d.data[4];

aN177 = _CAN_MAINTASK__123_d.data[5];

aN178 = _CAN_MAINTASK__123_d.data[6];

aN179 = _CAN_MAINTASK__123_d.data[7];

_TEST.CHECK.CP_SPN517_Raw=(aN193&(255))|(((U16)(aN194))<<8);
if (1==0)
{
aUN21Old1 = 0;
aUN21=0;
}
else
{
if (aUN21Old1 > _ElapsedTime[T100M])
aUN21Old1 = aUN21Old1 - _ElapsedTime[T100M];
else
{
if ((aUN21== 0) || ((1!=0)&&(aUN21Old2 == 0)) )
{if (10 > 2){
aUN21Old1 = 2;
aUN21Old2 = 10 - 2;
}else{
aUN21Old1 = 10;
aUN21Old2 = 0;}
if ((aUN21Old1 ==0) && (10 != 0))
aUN21=0;
else
aUN21=1;
}
else
{
aUN21=0;
aUN21Old1 = aUN21Old2;
}
}
}
aN5=CAN[0].BussOff | CAN[0].DriverError;
aUN20=!aUN21;
aUN23=CAN[0].BussOff && aUN21;
aUN22=CAN[0].DriverError && aUN20;
aN6=aUN22 | aUN23;
  _ShLocTmpVar_S32_1 = !(aN5);
  switch (_ShLocTmpVar_S32_1)
  {
    case 0:
      Led.Red = aN6;
      break;
    default:
      Led.Red = 0;
  }
Led.Green = 1;
C2p09.PinConfig = 0;
C2p09.CurChgLim = 111;
C2p09.DitherFreq = 0;
C2p09_C2p10.ReqFreq = 4000;
C2p09.DigOut = 0;
C2p09.OutputValue = 0;
C2p09.DitherAmp = 0;
C2p10.PinConfig = 0;
C2p10.DitherFreq = 0;
C2p10.DigOut = 0;
C2p10.OutputValue = 0;
C2p10.DitherAmp = 0;
C2p11.PinConfig = 0;
C2p11.CurChgLim = 111;
C2p11.DitherFreq = 0;
C2p11_C2p12.ReqFreq = 4000;
C2p11.DigOut = 0;
C2p11.OutputValue = 0;
C2p11.DitherAmp = 0;
C2p12.PinConfig = 0;
C2p12.DitherFreq = 0;
C2p12.DigOut = 0;
}
static void _FNC_123_e(void)
{
C2p12.OutputValue = 0;
C2p12.DitherAmp = 0;
}

static void _BeginModule_MAINTASK(void){
  _LoopStart      = _OS_MicroSec();
  _ExecTimeOut_us = OS.ExecTimeOut * 1000;
  _TimeSinceStartupInMilliSeconds = _ElapsedTime[T1M] + _TimeSinceStartupInMilliSeconds;

}

void _MAINTASK(void)
{
  _BeginModule_MAINTASK();

_FNC_123_b();
_FNC_123_e();

  _EndLoop_MAINTASK();
}
