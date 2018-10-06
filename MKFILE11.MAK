#
# MAKEFILE 11
# ----------------------------------------------------------------------------
# HOST INFO
MAKEDIR = 
BINDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2\bin
INCDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2\include
LIBDIR =  C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2
P1DIR =   C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler
#----------------------------------------------------------------------------
#APP INFO BEFORE SYS INFO
ROP = DISABLE
DUALBOOT = NOFILE
# -------------------------------------------------------------------------
# SOCKETS
# external plugin
!if ("$(DUALBOOT)"!=NOFILE)
DUALBOOTEXR = $(DUALBOOT).exr
DUALBOOTIDL = $(DUALBOOT).idl
!else
DUALBOOTEXR =
DUALBOOTIDL =
!endif
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
FONTFILE	  =	
BINFILEEXT	  = "NOFILE"
BINFILE   	  = NOFILE
MAINMODULE    = "MC024_110_LG_112T.SCS" 
MAINMODULEEXR = $(MAINMODULE:.SCS=.EXR)
!if ( "$(BINFILE)"!="NOFILE" )
BINFILEC = $(BINFILEEXT:.BIN=.C)
BINFILEOBJ = $(BINFILEEXT:.BIN=.OBJ)
BINFILEEXR = $(BINFILEEXT:.BIN=.EXR)
!else
BINFILEC =
BINFILEOBJ =
BINFILEEXR =
!endif
# ----------------------------------------------------------------------------
# COMPILE LINK COMMAND
UGRAPHP1_1 = "$(P1DIR)\chpargu1.exe" 
UGRAPHP1_2 = 2 $(OS_UGCPAR) $(PROJQ) $(PROJQ) 
PRJTOC = "$(P1DIR)\ProjectToC.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1,OPTION=NOCODE"
# ----------------------------------------------------------------------------
# MAKE JOB
# check application
"TELEMATICS_VERIFICATION_V1.log" : $(EXR_FILES) $(OS_LIB) $(OS_EXR) $(DUALBOOTEXR) $(TEXTDBF_FILES:.OBJ=.exr) $(FONTFILE) $(BINFILEEXR)
	@"$(P1DIR)\conmsg" Check and Link application $(PROJ)
	@"$(P1DIR)\glink.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1"
	@"$(P1DIR)\conmsg" MAKEJOB11 END
# OS Exr
$(OS_EXR) :	 MkFile11.mak
	@"$(P1DIR)\conmsg" MAKEJOB11 BEGIN
    @"$(P1DIR)\conmsg" Generating OS exr $**
	@"$(P1DIR)\conmsg" CAN and NV symbols 
!if ("$(ROP)"=="ENABLE")
	echo U__PARAM-OPEN >> $(OS_EXR)
!endif
	echo $ >> $(OS_EXR)
# EXR for dual boot
!if ( "$(DUALBOOT)"!=NOFILE ) 
$(DUALBOOTEXR) : $(DUALBOOTIDL)
    @"$(P1DIR)\conmsg" Generate $(DUALBOOTEXR)
    @"$(P1DIR)\RatatoskT3.exe" "input=$(DUALBOOTIDL), silent=yes, exr=yes"   
!endif
!if ( "$(BINFILE)"!=NOFILE )
$(BINFILEEXR) : $(BINFILEEXT)
	@"$(P1DIR)\conmsg" Generate EXR for $**
    @"$(P1DIR)\bintoc.exe" "PROJECT=TELEMATICS_VERIFICATION_V1.P1X,APPLICATION=TELEMATICS_VERIFICATION_V1,BINFILE=$(BINFILEEXT),TYPE=U16,OPTION=NOCODE"
!endif
# PLUS+1 project files
"TELEMATICS_VERIFICATION_V1.EXR" : "TELEMATICS_VERIFICATION_V1.P1X"
    @"$(P1DIR)\conmsg" Generating code from p1x $**
	@$(PRJTOC)
"TELEMATICS_VERIFICATION_V1.P1X" : "$(MAINMODULEEXR)"
# Application

"MC024_110_lg_112T.exr" : "MC024_110_lg_112T.nob"
   @"$(P1DIR)\conmsg" Generating exr from $**
   @$(UGRAPHP1_1) "MC024_110_lg_112T" $(UGRAPHP1_2)
"MC024_110_lg_112T.nob" : "MC024_110_lg_112T.scs"
   @"$(P1DIR)\conmsg" Generating nob code from $**
   @"$(P1DIR)\scstonob.exe" "MC024_110_lg_112T"

# ClassDef

# Text files

# Font files

