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
CFLAGS   = -std=c99                                        # C flags

default : production

production : CFLAGS += -D PRODUCTION
production : $(TARGET)

development : CFLAGS += -D DEVELOPMENT
development : $(TARGET)

$(TARGET) : $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

object/%.o : source/%.c $(HEADERS)
	gcc $(CFLAGS) -I include -I ../../include -c -o $@ $<

object/%.o : ../../source/%.c $(HEADERS)
	gcc $(CFLAGS) -I include -I ../../include -c -o $@ $<

clean :
	rm -f $(OBJECTS)
	rm -f $(TARGET)

# End of file ----------------------------------------------------------------------------------------------------------