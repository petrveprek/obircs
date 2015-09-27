// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: quux.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages with default verbosity and/or automatically-filled message text

#define SCRIBO_CATEGORY QUUX
#include <scribo.h>

void quux()
{
    SCRIBOD("Auto-fill method and trace:");
    SCRIBOM();
    SCRIBOT();
}

void doQuux()
{
    SCRIBO(LOG, "Quux...");
    
    SCRIBO(DEBUG, "Auto-fill verbosity:");
    SCRIBO();
    
    SCRIBO(DEBUG, "Auto-fill method and trace:");
    SCRIBO(METHOD);
    SCRIBO(TRACE);
    
    quux();
}

// End of file ---------------------------------------------------------------------------------------------------------