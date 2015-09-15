// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: quux.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages with automatically-filled parameters

#define SCRIBO_CATEGORY QUUX
#include <scribo.h>

void quux()
{
    SCRIBOM();
    SCRIBOT();
}

void doQuux()
{
    SCRIBO(LOG, "Quux...");
    
    SCRIBO(METHOD);
    SCRIBO(TRACE);
    
    quux();
}

// End of file ---------------------------------------------------------------------------------------------------------