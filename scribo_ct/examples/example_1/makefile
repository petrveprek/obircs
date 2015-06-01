# ----------------------------------------------------------------------------------------------------------------------
# Copyright (c) 2015 Petr Vepřek
# File: makefile
# ----------------------------------------------------------------------------------------------------------------------

TARGET = main.
HEADERS = $(wildcard include/*.h include/*.cfg)
SOURCES = $(wildcard source/*.c)
OBJECTS = $(addprefix object/,$(notdir $(SOURCES:.c=.o)))

default : $(TARGET)

$(TARGET) : $(OBJECTS)
	gcc -o $@ $^

object/%.o : source/%.c $(HEADERS)
	gcc -I include -c -o $@ $<

clean :
	rm -f $(OBJECTS)
	rm -f $(TARGET)

# End of file ----------------------------------------------------------------------------------------------------------