# MAKEFILE 2
# ----------------------------------------------------------------------------
# HOST INFO
MAKEDIR = 
BINDIR  = C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2\bin
COMPDIR = C:\ProgramData\Danfoss\PLUS1\10.1\Data\ExtCompiler\ARM\v4.7-2013q2
P1DIR   = C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler
LIBDIR1 = $(COMPDIR)\lib\gcc\arm-none-eabi\4.7.4\armv7-m
LIBDIR2 = $(COMPDIR)\arm-none-eabi\lib\armv7-m
#----------------------------------------------------------------------------
#APP INFO BEFORE SYS INFO
ROP = DISABLE
DUALBOOT = NOFILE
# -------------------------------------------------------------------------
# SOCKETS
# external plugin
!if ("$(DUALBOOT)"!=NOFILE)
DUALBOOTH = $(DUALBOOT).h
DUALBOOTLIB = $(DUALBOOT).lib
DUALBOOTIDL = $(DUALBOOT).idl
DUALBOOTHEX = $(DUALBOOT).hex
APPLINK = STM32F205ZET7wpwb.ld
APPWOPLINK = STM32F205ZET7wb.ld
!else
DUALBOOTH =
DUALBOOTLIB = stubbootfunc.o
DUALBOOTIDL =
DUALBOOTHEX = 
APPLINK = STM32F205ZET7wp.ld
APPWOPLINK = STM32F205ZET7.ld
!endif
# ----------------------------------------------------------------------------
# SYS INFO
OS_COMPVER = 474
OS_LIB     = 70097978v170.XML
OS_EXR     = 70097978v170.EXR
# ----------------------------------------------------------------------------
# APP INFO
PROJ = TELEMATICS_VERIFICATION_V1
PROJQ = "TELEMATICS_VERIFICATION_V1"
OBJ_FILES =  "TELEMATICS_VERIFICATION_V1.OBJ" "MC024_110_LG_112T.OBJ"
C_FILES =  "TELEMATICS_VERIFICATION_V1.C" "MC024_110_LG_112T.C"
CUSTOM_INTERFACE = 
CUSTOM_LIB =  $(CUSTOM_INTERFACE:=.LIB)
EXR_FILES =  "TELEMATICS_VERIFICATION_V1.EXR" "MC024_110_LG_112T.EXR"
BMP_FILES = 
TEXTDBF_FILES = 
REGFIL = NOFILE
REGFILEXT = NOFILE
BINFILEEXT	  = "NOFILE"
BINFILE   	  = NOFILE
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
# Compiler/Linker Options
SYS_DEFS = -DNUMBER_CANMESSAGES=0 -DEEpromSize=0
OPT_CC  = $(SYS_DEFS) -c -fno-inline-small-functions -mthumb -mcpu=cortex-m3 -O2 -I"$(LIBDIR2)" -fwrapv -fsigned-char -mlittle-endian -w
# ----------------------------------------------------------------------------
# Link List
COMMONLIB = $(OBJ_FILES) $(CUSTOM_LIB) stubextfunc.o $(DUALBOOTLIB)
LINK_LIST = _TIMEKEY.o _NVDATA.o diagdata.o _DynamicDiagnostic.o $(COMMONLIB)
LINK_PATHS2 = -L "$(LIBDIR1)" -L "$(LIBDIR2)" cstart.o HexRangeCrcTables.o AppLayer.a "$(LIBDIR2)\libm.a" "$(LIBDIR1)\libgcc.a" "$(LIBDIR2)\libg.a" "$(LIBDIR2)\libc.a"
LINK_PATHS = $(LINK_PATHS2:\=/)
COMPILE1  = "$(BINDIR)\sdcc.exe"
LINKLOC  = "$(BINDIR)\arm-none-eabi-ld.exe"
HEXOUT  = "$(BINDIR)\arm-none-eabi-objcopy"
# ----------------------------------------------------------------------------
# MAKE JOB
# Create LHX file
"TELEMATICS_VERIFICATION_V1.plg" : "TELEMATICS_VERIFICATION_V1.hex"
	@"$(P1DIR)\MEMCalc.exe" "PROJECT=TELEMATICS_VERIFICATION_V1,APPLICATION=TELEMATICS_VERIFICATION_V1,MAPFILE=TELEMATICS_VERIFICATION_V1.MAP,ELFFILE=TELEMATICS_VERIFICATION_V1"
	@"$(P1DIR)\conmsg" Creating diagnostic info for $*
	@"$(P1DIR)\conmsg" Creating lhx $*.lhx
!if ("$(DUALBOOT)"!=NOFILE)
	@"$(P1DIR)\p1insdoit.exe" CODE="TELEMATICS_VERIFICATION_V1.hex",OUT="TELEMATICS_VERIFICATION_V1.lhx",INTYPE=0,KEYTYPE=2,PROJECT="TELEMATICS_VERIFICATION_V1.p1x",ADRLEN=1,KEEPHEX=TRUE
	@"$(P1DIR)\conmsg" Swap bak data in hex-file
	srec_cat "$(PROJ).hex" -intel -exclude 0x0800C040 0x0800C042 -o RawDataHex.hex -intel -line-length=44
!if exists(DualBootOpt.bat)
	@"DualBootOpt.bat" $(PROJ)
!endif  
	copy RawDataHex.hex "$(PROJ).hex"
	-del RawDataHex.hex
!else
	@"$(P1DIR)\p1insdoit.exe" CODE="TELEMATICS_VERIFICATION_V1.hex",OUT="TELEMATICS_VERIFICATION_V1.lhx",INTYPE=0,KEYTYPE=2,PROJECT="TELEMATICS_VERIFICATION_V1.p1x",ADRLEN=1
!endif
	@"$(P1DIR)\conmsg" MAKEJOB2 END
	@"$(P1DIR)\conmsg"
# Create and convert HEX file
"TELEMATICS_VERIFICATION_V1.hex" : "TELEMATICS_VERIFICATION_V1.out"
	@"$(P1DIR)\conmsg" Creating Intel Hex Records file $*.hex
	$(HEXOUT) -O ihex "TELEMATICS_VERIFICATION_V1.out" "_hex.hex"
	$(HEXOUT) -O elf32-littlearm "TELEMATICS_VERIFICATION_V1.out" "TELEMATICS_VERIFICATION_V1.elf"
	@"$(P1DIR)\conmsg" Extern C-compiler End
	@"$(P1DIR)\conmsg" _____________________
!if ("$(DUALBOOT)"!=NOFILE)
	srec_cat "_hex.hex" -intel -exclude 0x08004000 0x08008000 -o _hex.hex -intel -line-length=44
	srec_cat $(DUALBOOTHEX) -intel _hex.hex -intel -exclude 0x0800C040 0x0800C042 -o dummy.hex -intel -line-length=44
    srec_cat dummy.hex -intel -fill 0x5a 0x0800C040 0x0800C042 -o "$(PROJ).he1" -intel -line-length=44
    @-del dummy.hex
    @-del "$(DUALBOOT).H"
	@-del "$(DUALBOOT).EXR" 
!else
	@copy _hex.hex "$(PROJ).he1"
!endif
	@copy "$(PROJ).he1" "$(PROJ).hex"
	@-del _hex.hex
	@-del "$(PROJ).he1"
# Create OUT-file, LINKLOC
"TELEMATICS_VERIFICATION_V1.out" :  "TELEMATICS_VERIFICATION_V1.cmf"
	@"$(P1DIR)\conmsg" Linking/Locate to $*.out
	@del "TELEMATICS_VERIFICATION_V1.out"
!if ("$(ROP)"=="ENABLE")
	@$(LINKLOC) @"$(PROJ).cmf" $(LINK_PATHS) -nostartfiles --gc-sections -Map="$(PROJ).map" -o"$(PROJ).out" -T $(APPLINK)
!else
	@$(LINKLOC) @"$(PROJ).cmf" $(LINK_PATHS) -nostartfiles --gc-sections -Map="$(PROJ).map" -o"$(PROJ).out" -T $(APPWOPLINK)
!endif
# Build Link cmf file
"TELEMATICS_VERIFICATION_V1.cmf" : $(LINK_LIST)
	@"$(P1DIR)\conmsg" Build $(PROJ).cmf 
	@"$(P1DIR)\MAKECMF" "$(PROJ).cmf" FORMAT:0 $(LINK_LIST)
_NVDATA.o : _NVDATA.c _NVAllocation.h
	@"$(P1DIR)\conmsg" Compiling  $**
        @del _NVDATA.o
	@$(COMPILE1) _NVDATA.c $(OPT_CC)
# New Diagnostic
_DynamicDiagnostic.o : _DynamicDiagnostic.c
	@"$(P1DIR)\conmsg" Compiling  $**
	@del _DynamicDiagnostic.o
	@$(COMPILE1) _DynamicDiagnostic.c $(OPT_CC)
# Generate H file for DUAL BOOT
!if ( "$(DUALBOOT)"!=NOFILE ) 
$(DUALBOOTH) : $(DUALBOOTIDL)
    @"$(P1DIR)\conmsg" Generate $(DUALBOOTH)
    @"$(P1DIR)\RatatoskT3.exe" "input=$(DUALBOOTIDL), silent=yes, h=yes"   
!endif
!if ( "$(BINFILE)"!="NOFILE" )
$(BINFILEOBJ) : $(BINFILEC)
	@"$(P1DIR)\conmsg" Compiling  $**
	@$(COMPILE1) $(BINFILEC) $(OPT_CC)
!endif
# Timekey
_TIMEKEY.o : _TIMEKEY.c
	@"$(P1DIR)\conmsg" Compiling  $**
	@del _TIMEKEY.o
	@$(COMPILE1) _TIMEKEY.c $(OPT_CC)
_TIMEKEY.c :
	@"$(P1DIR)\conmsg" MAKEJOB2 BEGIN
   	@"$(P1DIR)\conmsg" Create timekey
	@"$(P1DIR)\mtimekey.exe" "_TIMEKEY_T" "P:__TIMEKEY_" "N:_TIMEKEY"
	@"$(P1DIR)\conmsg" _____________________
	@"$(P1DIR)\conmsg" Extern C-compiler Begin
# PLUS+1 project files

"TELEMATICS_VERIFICATION_V1.obj" : "TELEMATICS_VERIFICATION_V1.c"
	@"$(P1DIR)\conmsg" Compiling $** 
        @del "TELEMATICS_VERIFICATION_V1.obj"
	@$(COMPILE1) "TELEMATICS_VERIFICATION_V1.c" $(OPT_CC) -o "TELEMATICS_VERIFICATION_V1.obj"

# Application		 
	 

"MC024_110_lg_112T.obj" : "MC024_110_lg_112T.c" $(DUALBOOTH)
    @"$(P1DIR)\conmsg" Compiling  $**
        @del "MC024_110_lg_112T.obj"
	@$(COMPILE1) "MC024_110_lg_112T.c" $(OPT_CC) -o "MC024_110_lg_112T.obj"

# Text definition files

