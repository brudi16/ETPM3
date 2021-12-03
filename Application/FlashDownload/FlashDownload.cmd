:: *****************************************************************************
:: *
:: * E M B E D D E D   W I Z A R D   P R O J E C T
:: *
:: *****************************************************************************
:: * FlashDownload.cmd
:: *
:: * This script uses the STM32CubeProgrammer to programm the internal and
:: * optionally also the external flash memory of a STM32 device.
:: *
:: * Usage:    FlashDownload.cmd <elf-file or bin-file> [options]
:: *
:: * Options:
:: *   separateConsole          -  open a separate console window
:: *   eraseFlash               -  erase the complete flash memory before programming
:: *   imageStartAddress=<addr> -  defines the start address a binary file has
:: *                               to be programmed to
:: *   reset                    -  reset target after flashing
:: *
:: *****************************************************************************


@ECHO OFF
setlocal ENABLEDELAYEDEXPANSION

:: initialize variables
set externalLoaderExtension=
set imageStartAddress=

echo.

:: Load commandline options
call :getCommadlineOptions "%*"


:: display usage, if there is no parameter
if [%1] == [] (
  echo FlashDownload.cmd
  echo.
  echo This script uses the STM32CubeProgrammer to programm the internal and
  echo optionally also the external flash memory of a STM32 device.
  echo.
  echo Usage:    FlashDownload.cmd [elf-file or bin-file] [options]
  echo.
  echo Options:
  echo   separateConsole          -  open a separate console window
  echo   eraseFlash               -  erase the complete flash memory before programming
  echo   imageStartAddress=[addr] -  defines the start address a binary file has
  echo.                              to be programmed to
  echo   reset                    -  reset target after flashing
  echo.
  call pause
  exit
)

:: change size of console
if [%separateConsole%] == [set] (
  title Programming taget using STM32CubeProgrammer ...
  mode con:cols=140 lines=50
)

:: load configuration
for /F "delims= eol=:" %%A in (%~dps0FlashDownload.cfg) do set "%%A"


:: do some checks

if not exist "%Stm32CubeProgrammerPath%\bin" (
  echo.
  echo STM32CubeProgrammer check failed:
  echo STM32CubeProgrammer not found on path:
  echo "%Stm32CubeProgrammerPath%\bin".
  echo Please install the STM32CubeProgrammer or adapt the setting for
  echo 'Stm32CubeProgrammerPath' in file '\Application\FlashDownload\STM32CubeProgrammer.cfg'.
  echo.
  echo STM32CubeProgrammer can be downloaded at:
  echo https://www.st.com/en/development-tools/stm32cubeprog.html
  echo.
  call :doPause
  exit
)

if [%ExternalLoader%] == [] (
  echo No external loader defined
  goto :startFlashing
)


if [%ExternalLoader:\=_%]==[%ExternalLoader%] (
  set STM32CUBEPROG_EXT_FLASH_LOADER=%Stm32CubeProgrammerPath%\bin\ExternalLoader\%ExternalLoader%
) else (
  set STM32CUBEPROG_EXT_FLASH_LOADER=%~dp0%ExternalLoader%
)

if not exist "%STM32CUBEPROG_EXT_FLASH_LOADER%" (
  echo.
  echo STM32CubeProgrammer external flash loader check failed:
  echo External flash loader for STM32CubeProgrammer not found on path:
  echo "%STM32CUBEPROG_EXT_FLASH_LOADER%".
  echo Please check your STM32CubeProgrammer installation or
  echo adapt setting for 'STM32CUBEPROG_EXT_FLASH_LOADER' in file
  echo '\Application\FlashDownload\STM32CubeProgrammer.cfg'.
  echo.
  call :doPause
  exit
)

echo using external loader: '%STM32CUBEPROG_EXT_FLASH_LOADER%'
set externalLoaderExtension= -el "%STM32CUBEPROG_EXT_FLASH_LOADER%"


:startFlashing
set Stm32CubeProgrammer="%Stm32CubeProgrammerPath%\bin\STM32_Programmer_CLI" %Stm32CubeProgrammerParams%

if [%eraseFlash%] == [set] (
  echo erasing internal flash ...
  %Stm32CubeProgrammer% -e all > NUL
)


echo Programming file '%~nx1' to target using STM32CubeProgrammer ...
%Stm32CubeProgrammer% -w %1 %imageStartAddress% %externalLoaderExtension% -g 0x8000000
echo.

if %ERRORLEVEL% == 0 (
  echo '%~nx1' successfully flashed !!
  if [%separateConsole%] == [set] (
    timeout /t 3 > NUL
  )
) ELSE (
  echo ERROR - flashing failed!
  echo.
  call :doPause
)
exit /B 0



:getCommadlineOptions
  :: replace equal signs by ':'
  for /f "tokens=1-10 delims==" %%a in (%1) do set list3=%%a:%%b:%%c:%%d:%%e:%%f:%%g:%%h:%%i:%%j

  for %%i in (%list3%) do (
    set var=%%i
    call :setvar !var::= !
  )
  exit /B 0

:setvar
  if x%2==x (
    set %1=set
  ) else (
    set %1=%2
  )
  exit /B 0

:doPause
  if [%separateConsole%] == [set] (
    pause
  )
  exit /B 0