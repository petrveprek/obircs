# ----------------------------------------------------------------------------------------------------------------------
# Copyright (c) 2015, 2017 Petr Vepřek
# File: makefile
# ----------------------------------------------------------------------------------------------------------------------

TARGET   = main.                                           # executable
HEADERS  = $(wildcard include/*.h include/*.cfg)           # application
SOURCES  = $(wildcard source/*.c)                          #    -//-
HEADERS += $(wildcard ../../include/*.h)                   # scribo
OBJECTS  = $(addprefix object/,$(notdir $(SOURCES:.c=.o))) # objects
CC       = gcc#                                            # C compiler
CPPFLAGS = #                                               # preprocessor flags
CFLAGS   = -std=c99#                                       # C flags

default : production

production : CPPFLAGS += -D PRODUCTION
production : $(TARGET)

development : CPPFLAGS += -D DEVELOPMENT
development : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^

object/%.o : source/%.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I include -I ../../include -c -o $@ $<

object/%.o : ../../source/%.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -I include -I ../../include -c -o $@ $<

clean :
	rm -f $(OBJECTS)
	rm -f $(TARGET)

# End of file ----------------------------------------------------------------------------------------------------------