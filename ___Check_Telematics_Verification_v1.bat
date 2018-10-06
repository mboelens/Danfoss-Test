@ECHO OFF
@ECHO OFF
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\make.exe" "TELEMATICS_VERIFICATION_V1" LONGNAME:ON
if errorlevel 1 goto out1
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\sdm.exe" -r %1 -f MKFILE31.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errclr" "TELEMATICS_VERIFICATION_V1" err
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\sdm.exe" -r %1 -f MKFILE32.mak
if errorlevel 1 goto out2
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\errclr" "TELEMATICS_VERIFICATION_V1" err
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\writescreentime.exe"
ECHO TELEMATICS_VERIFICATION_V1 successfully compiled
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" T "TELEMATICS_VERIFICATION_V1 successfully Error Checked"
goto end
:out1
ECHO Not able to build Initialization data for TELEMATICS_VERIFICATION_V1
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" F "Not able to build Initialization data for TELEMATICS_VERIFICATION_V1"
goto end
:out2
ECHO Error Checking of TELEMATICS_VERIFICATION_V1 aborted with errors
"C:\Program Files (x86)\Danfoss\PLUS1\10.1\P1Tools\P1Compiler\RESULT" F "Error Checking of TELEMATICS_VERIFICATION_V1 aborted with errors"
:end

