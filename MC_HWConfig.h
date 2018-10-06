/*!
 @file   MC_HWConfig.h

 <hr>
 <h2> File Creation </h2>
 @author jbendixen

 @date   18.10.2012 - 11:17:45

 @caliberrm <a href="mailto:jbendixen@sauer-danfoss.com?subject=Link%20to%20CaliberRM%20requirement%20is%20missing%20in%20HydraHWConfig.h">Link to CaliberRM requirement is missing!</a>  TODO: Link to CaliberRM in HydraHWConfig.h

 @brief This file provides constants and enumerations that are used in the applayer.


 <hr>
 <h2> Current Revision </h2>  <!-- This section will be filled by SVN at committing -->
 $Revision:$
 $Author:$
 $Date:$
 $HeadURL:$


 <hr>
 <h2> History </h2>
 @verbatim
 Vers:  Date:        Name:       Comment:
 -----  ----------   ----------  ------------------------------------------------
 00.00  18.10.2012   jmutzbauer  Initial start
 00.01  03.02.2014   jmutzbauer  Renamed some constants
 -----  ----------   ----------  -------------------------------------------------
 @endverbatim

 &copy; Danfoss Power Solutions, 2014
 */

#ifndef _MCHWCONFIG_H
#define _MCHWCONFIG_H


/*-------------------------------------------------------
   Include files
   -------------------------------------------------------*/


/*-------------------------------------------------------
   Definitions
   -------------------------------------------------------*/
#define D_R1xx  (100U)
#define D_R2xx  (133U)
#define D_R3xx (1000U)
#define D_R4xx   (93U)
#define D_R5xx  (200U)
#define OP_DEVIDER10 (143U)

#define AD_RESOLUTION ((1024U*32U)-1U)

// macro to calculate digits to mv
#define LOCAL_DIG2MV(x) ( (((U32)(x))*3000UL)/(U32)AD_RESOLUTION)
#define DIG2MV(x) ( (U16)LOCAL_DIG2MV(x)   )

// macro to calculate VLDP-Voltage
#define VLDPDIGIT2SENSMV(x) (((U32)LOCAL_DIG2MV(x)*125UL)/10UL)

// macro to calculate supply voltage digits to mv
#define SUPDIGIT2SENSMV(x) (((U32)LOCAL_DIG2MV(x)*125UL)/10UL)

// macro to calculate sensor power voltage digits to mv
#define SENPDIGIT2SENSMV(x) (((U32)LOCAL_DIG2MV(x)*125UL)/10UL)
#define LOCAL_SENS_FACTORDIG2MV(x) (((((U32)(x)*300UL*(U32)(D_R1xx+D_R2xx))/D_R2xx)*10UL)/AD_RESOLUTION)

// macro to calculate scaled digits to mv for 5,25 V range
#define SENS_FACTORDIG2MV(x) ((U16)LOCAL_SENS_FACTORDIG2MV(x))

// macro to calculate scaled digits to mv for supply Volt range
#define LOCAL_SUP_FACTORDIG2MV(x) ((((((((U32)300UL*(D_R3xx+D_R4xx))/D_R4xx))*(x))/AD_RESOLUTION))*10U)
#define SUP_FACTORDIG2MV(x) ((U16)LOCAL_SUP_FACTORDIG2MV(x))

// macro to calculate scaled digits to mv for 5,25 V range with op activ
//#define SENS_FACTORDIG2MV_OP(x)	 ((U16)(((U32)SENS_FACTORDIG2MV(x)*10UL)/OP_DEVIDER10))
#define SENS_FACTORDIG2MV_OP(x)	 ((U16)((LOCAL_SENS_FACTORDIG2MV(x)*10UL)/OP_DEVIDER10))

// macro to calculate scaled digits to mv for supply Volt range	with op activ
//#define SUP_FACTORDIG2MV_OP(x) ((U16)(((U32)SUP_FACTORDIG2MV(x)*10UL)/OP_DEVIDER10))
#define SUP_FACTORDIG2MV_OP(x) ((U16)((LOCAL_SUP_FACTORDIG2MV(x)*10UL)/OP_DEVIDER10))

#define DAC_RESOLUTION (4095U)

// Reference voltage DAC, CRIUS units
#define DAC_VREF (3U)

// macro to calculate DAC value for sensor power
#define DAC_CALC(x)        ((U16)(((U32)(x)*DAC_RESOLUTION)/15000U))

// macro to calculate DAC value for sensor power CRIUS units
#define DAC_CALC2(x)       ((U16)(((((U32)(x)*3UL)/5UL)*(U32)DAC_RESOLUTION)/((U32)(DAC_VREF * 1000U))))

/* Clamp value for the max measured resistor value */
#define RHEOSTAT_MAX_OHM (10000U)
#define RHEO_AD_LIMIT (3796U*8U)

/* value of RHEO resistor */
#define RHEO_OHM (1330U)
//#define RHEO_CALC(x)  (U16)((((((((U32)(D_R1xx+D_R2xx)*RHEO_OHM)*1000U) / ((((((((U32)5U*AD_RESOLUTION)*D_R2xx)*100U)/3U)/(x))*10U)))-RHEO_OHM)-((U32)D_R1xx*1000U))-((U32)D_R2xx*1000U)))
#define RHEO_CALC(x)  (U16)(((((U32)(D_R1xx+D_R2xx))*RHEO_OHM)*1000U) / ((((((((((U32)5U*AD_RESOLUTION)*D_R2xx)*100U)/3U)/(x))*10U)-RHEO_OHM)-((U32)D_R1xx*1000U))-((U32)D_R2xx*1000U)))

#define DIG2UA(x) ((U32)(((U32)(((U32)((U32)(((U32)((((U32)D_R1xx*100U)+((U32)D_R2xx*100U))*(U32)(x))/(U32)D_R5xx)*10U)+(U32)(x))*30U)/D_R2xx)*100U)/AD_RESOLUTION))
#define DIG2UASP(x) ((U32)((((U32)(((U32)((U32)((((U32)(((U32)D_R3xx*100U)+((U32)D_R4xx*100U))*(U32)(x))/(U32)D_R5xx)*10U)+(U32)(x))*3U)/D_R4xx)*100U)/AD_RESOLUTION)*10U))



#define CONFIG_ERROR_NOERROR  ( 0x0000U)
#define CONFIG_ERROR_GENERIC_ERROR     ( 0x0001U)  /* BIT 0 */
#define CONFIG_ERROR_BIAS     ( 0x0002U)  /* BIT 1 */
#define CONFIG_ERROR_RANGE    ( 0x0004U)  /* BIT 2 */
#define CONFIG_ERROR_MODE     ( 0x0008U)  /* BIT 3 */
#define CONFIG_OVERCURRENT    ( 0x0010U)  /* BIT 4 */


#define STATUS_ERROR_GENERIC_ERROR ( 0x0004U)     /* BIT 2 */
#define STATUS_ERROR_OVERTEMP ( 0x0008U)          /* BIT 3 */
#define STATUS_ERROR_OVERLOAD ( 0x0010U)          /* BIT 4 */
#define STATUS_ERROR_MODE_CFG ( 0x0020U)          /* BIT 5 */
#define STATUS_ERROR_SAFETY   ( 0x0040U)          /* BIT 6 */
#define STATUS_SAFE_FET_OFF   ( 0x0080U)          /* BIT 7 */

/*lint -esym(758, BIAS_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum BIAS_E
{
   NOPD_NOPU = 0,
   PU_NOPD,
   PD_NOPU,
   PD_PU
};

/*lint -esym(758, PWR_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum PWR_E
{
   NO_BATT = 0,
   BATT
};

/*lint -esym(758, PWR_RE) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum PWR_RE
{
   HIGHFREQ_NOBATT  = 0,
   LOWFREQ_NOBATT   = 1,
   HIGHFREQ_BATT    = 2,
   LOWFREQ_BATT     = 3,
   RHEOSTAT					= 4
};

/*lint -esym(758, ANA_MODE_E_) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum ANA_MODE_E_
{
	ANALOG_MODE = 0,
	RHEOSTAT_MODE
};

/*lint -esym(758, FREQ_MODE_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum FREQ_MODE_E
{
	MODE_MC_INPUT 	= 0,
	MODE_MC_QUADENC = 1,
	MODE_MC_PHASE	  = 2,
	MODE_MC_NOFREQFILTER = 0x100
};

/*lint -esym(758, STATUS_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum STATUS_E
{
	MC_STATUS_OK 			 = 0,
	MC_STATUS_ERROR_CONFIG   = 1,
	MC_STATUS_ERROR_OVERLOAD = 2
};

/*lint -esym(758, CONFIG_ERROR_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum CONFIG_ERROR_E
{
	MC_CONFIG_OK =    0U,
	MC_CONFIG_ERROR = 1U
};

/*lint -esym(758, PWM_FREQ_E) */ /* disable enum not referenced again */
/* this is because depending of the configuration of the device several enums are not used ( Output module has not inputs etc... */
enum PWM_FREQ_E
{
	MC_FIX_FREQ     = 0x01,
	MC_GROUP_FREQ1  = 0x02,
	MC_GROUP_FREQ2  = 0x04
};
/* enable enum u enum tag 'Symbol' (Location) not referenced again */
//lint -restore

#define CURRENTINPUT_RESET_TIME_MS  (5400U)
#define CURRENTINPUT_OVERCURRENT    (24000U)
#define CURRENTINPUT_STARTTIME_MS   (100U)


#define VALVE_RESET_TIME_MS (250U)
#define REDUNDANT_FETS_OFF_TIMES_MS (250U)

#define CURRENT_PWM_DEFAULT_FREQ (1000U)
#define CURRENT_PWM_FIX_FREQ (1144U)
#define CURRENT_PWM_MAX_FREQ (4000U)

/*lint -esym(758, MF_OUT_MODES) */ /* do not complain about not used enum */
enum MF_OUT_MODES{
	DIG_OUT_PP                = 0,
	DIG_OUT_SOURCE            = 1,
	DIG_OUT_SINK              = 2,
	PWM_OPEN_LOOP             = 3,
	PWM_CLOSED_LOOP           = 4,
	PWM_CLOSED_LOOP_DITHER    = 5,
	PVE_OUT                   = 6,
	EGAS_OUT                  = 7,
	PWM_CLOSED_LOOP_DITHER_BI = 8,
	PVE_PWR                   = 10
};

#define REDUNDANT_FETS_STATE_INIT  (0U)
#define REDUNDANT_FETS_STATE_OFF   (1U)
#define REDUNDANT_FETS_STATE_TRANS (2U)
#define REDUNDANT_FETS_STATE_ON    (3U)

#define DIG_SWTICH_HYST_MV      (100U)
#define DIGIN_TRESHIGH_MV       (3000U)
#define DIGIN_TRESLOW_MV        (2000U)

/*-------------------------------------------------------
   Type definitions
   -------------------------------------------------------*/


/*-------------------------------------------------------
   Variables
   -------------------------------------------------------*/


/*-------------------------------------------------------
   prototype functions
   -------------------------------------------------------*/


/*-------------------------------------------------------
   functions
   -------------------------------------------------------*/


#endif /* _MCHWCONFIG_GUIDE_H */

