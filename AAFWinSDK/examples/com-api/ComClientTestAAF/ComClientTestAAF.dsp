# Microsoft Developer Studio Project File - Name="ComClientTestAAF" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ComClientTestAAF - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ComClientTestAAF.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ComClientTestAAF.mak" CFG="ComClientTestAAF - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ComClientTestAAF - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ComClientTestAAF - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ComClientTestAAF - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../../../ref-impl/src/impl" /I "../../../../ref-impl/src/OM" /I "..\..\..\aafsdk\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 ole32.lib uuid.lib /nologo /subsystem:console /machine:I386 /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /nodefaultlib:"msvcrtd.lib" /out:"../../../Release/Examples/Com/COMCLIENTAAF.EXE" /libpath:"..\..\..\aafsdk\lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "ComClientTestAAF - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MDd /W3 /GR /GX /ZI /Od /I "..\..\..\aafsdk\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_UNICODE" /D "UNICODE" /D "OM_ENABLE_DEBUG" /YX /FD /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /o "NUL" /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ole32.lib uuid.lib /nologo /subsystem:console /pdb:none /debug /debugtype:both /machine:I386 /nodefaultlib:"libc.lib libcmt.lib msvcrt.lib libcd.lib libcmtd.lib" /nodefaultlib:"libc.lib" /nodefaultlib:"libcmt.lib" /nodefaultlib:"msvcrt.lib" /nodefaultlib:"libcd.lib" /nodefaultlib:"libcmtd.lib" /out:"../../../Debug/Examples/Com/COMClientAAF.exe" /libpath:"..\..\..\aafsdk\lib"
# SUBTRACT LINK32 /map

!ENDIF 

# Begin Target

# Name "ComClientTestAAF - Win32 Release"
# Name "ComClientTestAAF - Win32 Debug"
# Begin Group "Libraries"

# PROP Default_Filter "lib"
# Begin Source File

SOURCE=..\..\..\aafsdk\lib\AAF.lib

!IF  "$(CFG)" == "ComClientTestAAF - Win32 Release"

!ELSEIF  "$(CFG)" == "ComClientTestAAF - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\aafsdk\lib\AAFD.lib

!IF  "$(CFG)" == "ComClientTestAAF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ComClientTestAAF - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\aafsdk\lib\AAFIID.lib

!IF  "$(CFG)" == "ComClientTestAAF - Win32 Release"

!ELSEIF  "$(CFG)" == "ComClientTestAAF - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\aafsdk\lib\AAFIIDD.lib

!IF  "$(CFG)" == "ComClientTestAAF - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "ComClientTestAAF - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Source File

SOURCE="..\..\..\..\examples\com-api\comClientTest\ComClientTestAAF.cpp"
# End Source File
# End Target
# End Project
