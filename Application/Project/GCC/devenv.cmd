@echo off

set Title=Embedded Wizard Build Environment for %PlatformName% %BuildEnvVersion%
title %Title%

echo *******************************************************************************
echo * Welcome to %Title%
echo *******************************************************************************
echo.

IF DEFINED BuildInitialized GOTO run

GOTO setpaths

:setpaths

:: set the path to dmake and its tools
set PATH=%~dp0\..\..\..\ThirdParty\Make;%PATH%

:: compiler path
set PATH=%~dp0\..\..\..\ThirdParty\gcc-arm-none-eabi\bin;%PATH%

:: st-link utility path
set PATH=%ST-LINK_Utility_Path%;%PATH%

set BuildInitialized=1

:run

echo.
echo *******************************************************************************
echo *
echo * Getting started with Embedded Wizard and %PlatformName% board:
echo *
echo * https://doc.embedded-wizard.de/%GettingStartedLink%
echo *
echo *******************************************************************************
echo.
echo.
echo Entering Embedded Wizard template project
echo.

cd Application\Project\GCC
