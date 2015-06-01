# ----------------------------------------------------------------------------------------------------------------------
# Copyright (c) 2015 Petr Vepřek
# File: makefile
# ----------------------------------------------------------------------------------------------------------------------

TARGET   = main.                                           # executable
HEADERS  = $(wildcard include/*.h include/*.cfg)           # application
SOURCES  = $(wildcard source/*.c)                          #    -//-
HEADERS += $(wildcard ../../include/*.h)                   # scribo
SOURCES += $(wildcard ../../source/*.c)                    #  -//-
OBJECTS  = $(addprefix object/,$(notdir $(SOURCES:.c=.o))) # objects

default : $(TARGET)

$(TARGET) : $(OBJECTS)
	gcc -o $@ $^

object/%.o : source/%.c $(HEADERS)
	gcc -I include -I ../../include -c -o $@ $<

object/%.o : ../../source/%.c $(HEADERS)
	gcc -I include -I ../../include -c -o $@ $<

clean :
	rm -f $(OBJECTS)
	rm -f $(TARGET)

# End of file ----------------------------------------------------------------------------------------------------------