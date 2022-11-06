#Main application file name
MAIN_APP = test-keypad
#Main hex file path in windows format
MAIN_HEX_PATH = D:\WinAVR\Script\lcd\src\$(MAIN_APP).hex
WORKSPACE = lcd
#config
ATMEGA_VER = atmega16
MICRO_TYPE = arduino
DEVICE = COM3
BAUDRATE = 19200

# Compiler and other Section
CC = avr-gcc -std=c99
OBJCOPY = avr-objcopy.exe
AVRDUDE := avrdude

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=$(ATMEGA_VER) -o

#Options for HEX file generation
HFLAGS = -j .text -j .data -O ihex

#Options for avrdude to burn the hex file
#MMCU model here according to avrdude options
DUDEFLAGS = -c
DUDEFLAGS += $(MICRO_TYPE) 
DUDEFLAGS += -p
DUDEFLAGS += m8  
DUDEFLAGS += -P 
DUDEFLAGS += $(DEVICE) 
DUDEFLAGS += -b 
DUDEFLAGS += $(BAUDRATE) 
DUDEFLAGS += -U flash:w:$(MAIN_HEX_PATH):i

# Sources files needed for building the application 
SRC = $(MAIN_APP).c
SRC += 

# The headers files needed for building the application
INCLUDE = -I. 
# INCLUDE += 

# commands Section
Burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

Build : $(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< $(MAIN_APP).hex
	
$(MAIN_APP).elf: $(MAIN_APP).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@
	
$(MAIN_APP).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@