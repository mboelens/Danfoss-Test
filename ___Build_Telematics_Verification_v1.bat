@ECHO OFF
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\conmsg" Batch job BEGIN
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\make.exe" "TELEMATICS_VERIFICATION_V1" LONGNAME:ON
if errorlevel 1 goto out1
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\sdm.exe" -r %1 -f MKFILE11.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errclr" "TELEMATICS_VERIFICATION_V1" err
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\sdm.exe" -r %1 -f MKFILE12.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errclr" "TELEMATICS_VERIFICATION_V1" err
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\sdm.exe" -r %1 -f MKFILE2.mak
if errorlevel 1 goto out3
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errset" "TELEMATICS_VERIFICATION_V1" err
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\conmsg" 
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\writescreentime.exe"
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\conmsg" Batch job END
ECHO TELEMATICS_VERIFICATION_V1 successfully compiled
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" T "TELEMATICS_VERIFICATION_V1 successfully compiled"
goto end
:out1
ECHO Not able to build Initialization data for TELEMATICS_VERIFICATION_V1
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" F "Not able to build Initialization data for TELEMATICS_VERIFICATION_V1"
goto end
:out2
ECHO Graphical Compilation and Linking of TELEMATICS_VERIFICATION_V1 aborted with errors
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" F "Graphical Compilation and Linking of TELEMATICS_VERIFICATION_V1 aborted with errors"
goto end
:out3
ECHO C Compilation, Linking or LHX create of TELEMATICS_VERIFICATION_V1 aborted with errors
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" F "C Compilation, Linking or LHX create of TELEMATICS_VERIFICATION_V1 aborted with errors"
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errset" "TELEMATICS_VERIFICATION_V1" err
:end

