###############################################################################
# Substitutions for common used utilities and programs, exported to be valid
# for all sub-make files.
###############################################################################

# define the shell to be used
SHELL=cmd.exe

CROSS    := arm-none-eabi-
CC       := $(CROSS)gcc
CXX      := $(CROSS)g++
STRIP    := $(CROSS)strip
LD       := $(CROSS)gcc
OBJCOPY  := $(CROSS)objcopy
AR       := $(CROSS)ar
SIZE     := $(CROSS)size -A -x

RM       := rm -f
RMDIR    := rm -rf
MKDIR    := mktree.bat

STLINK        = "$(ST-LINK_Utility_Path)/ST-LINK_CLI"
STM32CUBEPROG = "$(STM32CubeProgrammer_Path)/bin/STM32_Programmer_CLI"

# Some usefull variables for string manipulation.
COMMA:= ,
EMPTY:=
SPACE:= $(EMPTY) $(EMPTY)
COLON:=:
QUOTE:=\"

# line feed definition used in error messages
define n


endef
