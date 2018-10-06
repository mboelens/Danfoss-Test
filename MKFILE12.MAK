#
# MAKEFILE 12
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
# ----------------------------------------------------------------------------
# COMPILE LINK COMMAND
UGRAPHP1_1 = "$(P1DIR)\chpargu2.exe" 
UGRAPHP1_2 = 2 $(OS_UGCPAR) $(PROJQ) $(PROJQ) CCODE
PRJTOC = "$(P1DIR)\ProjectToC.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1"
# ----------------------------------------------------------------------------
# MAKE JOB
# check application
# New Diagnostic
_DynamicDiagnostic.c : "TELEMATICS_VERIFICATION_V1.LOG"
	@"$(P1DIR)\NOBFNUTT.EXE" "APPLICATION=$(PROJ),PROJECT=$(PROJ)"
	@"$(P1DIR)\conmsg" MAKEJOB12 END
	@"$(P1DIR)\conmsg"
"TELEMATICS_VERIFICATION_V1.LOG" : $(C_FILES) $(OS_LIB) 
    @"$(P1DIR)\conmsg" Allocate NV memory for application $(PROJ)
	@"$(P1DIR)\nvallocate.exe" "PROJECT=TELEMATICS_VERIFICATION_V1,APPLICATION=TELEMATICS_VERIFICATION_V1"
    @"$(P1DIR)\conmsg" Check and Link application $(PROJ)
	@"$(P1DIR)\MergeErrorPass2.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1"
# PLUS+1 project files
"TELEMATICS_VERIFICATION_V1.C" : "TELEMATICS_VERIFICATION_V1.P1X"
	@"$(P1DIR)\conmsg" MAKEJOB12 BEGIN
    @"$(P1DIR)\conmsg" Generating code from p1x $**
	@$(PRJTOC)
# Application

"MC024_110_lg_112T.c" : "MC024_110_lg_112T.nob"
   @"$(P1DIR)\conmsg" Generating c code from $**
   @$(UGRAPHP1_1) "MC024_110_lg_112T" $(UGRAPHP1_2)

# ClassDef

