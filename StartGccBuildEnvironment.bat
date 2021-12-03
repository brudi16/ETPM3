@echo off

rem *************************************************************************************************
rem Please do NOT change the following settings
rem *************************************************************************************************
set PlatformName=STM32F429-Discovery
set BuildEnvVersion=V11.00
set GettingStartedLink=getting-started-stm32f429-discovery
cmd /K Application\Project\GCC\devenv.cmd
