#
# MAKEFILE 32
# ----------------------------------------------------------------------------
# HOST INFO
MAKEDIR = 
BINDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2\bin
INCDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2\include
LIBDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2
P1DIR =   C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler
#----------------------------------------------------------------------------
#APP INFO BEFORE SYS INFO
# ----------------------------------------------------------------------------
# SYS INFO
OS_COMPVER = 474
OS_UGCPAR  = ugp1par.txt
OS_LIB     = 70097978v170.XML
OS_EXR     = 70097978v170.EXR
					  
# ----------------------------------------------------------------------------
# APP INFO
PROJ          = TELEMATICS_VERIFICATION_V1
PROJQ         = "TELEMATICS_VERIFICATION_V1"
OBJ_FILES     =  "TELEMATICS_VERIFICATION_V1.OBJ" "MC024_110_LG_112T.OBJ"
C_FILES       =  "TELEMATICS_VERIFICATION_V1.C" "MC024_110_LG_112T.C"
CUSTOM_LIB    = 
EXR_FILES     =  "TELEMATICS_VERIFICATION_V1.EXR" "MC024_110_LG_112T.EXR"
BMP_FILES     = 
TEXTDBF_FILES = 
REGFILEXT     = NOFILE
REGFIL        = NOFILE
NOC_FILES 	  =  "TELEMATICS_VERIFICATION_V1.NOC" "MC024_110_LG_112T.NOC"
# ----------------------------------------------------------------------------
# COMPILE LINK COMMAND
UGRAPHP1_1 = "$(P1DIR)\chpargu2.exe" 
UGRAPHP1_2 = 2 $(OS_UGCPAR) $(PROJQ) $(PROJQ)
PRJTOC = "$(P1DIR)\ProjectToC.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1,OPTION=NOCODE"
# ----------------------------------------------------------------------------
# MAKE JOB
# check application
"TELEMATICS_VERIFICATION_V1.LOG" : $(NOC_FILES) $(OS_LIB) 
    @"$(P1DIR)\conmsg" Check and Link application $(PROJ)
	@"$(P1DIR)\MergeErrorPass2.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1"
	@"$(P1DIR)\conmsg" MAKEJOB32 END
	@"$(P1DIR)\conmsg"
# PLUS+1 project files
"TELEMATICS_VERIFICATION_V1.NOC" : "TELEMATICS_VERIFICATION_V1.P1X"
	@"$(P1DIR)\conmsg" MAKEJOB 32 BEGIN
    @"$(P1DIR)\conmsg" Generating dummy file $**
	copy "TELEMATICS_VERIFICATION_V1.P1X" "TELEMATICS_VERIFICATION_V1.NOC"
# Application									    

"MC024_110_lg_112T.noc" : "MC024_110_lg_112T.nob"
   @"$(P1DIR)\conmsg" Generating noc code from $**
   @$(UGRAPHP1_1) "MC024_110_lg_112T" $(UGRAPHP1_2)

# ClassDef

