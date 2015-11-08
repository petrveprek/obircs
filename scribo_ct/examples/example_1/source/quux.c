// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: quux.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages with default verbosity (TRACE) and/or automatically-filled message text

#define SCRIBO_CATEGORY QUUX
#include <scribo.h>

void quux()
{
    SCRIBOD("Auto-fill fatal, error, warning, log, info, and debug:");
    SCRIBOF();
    SCRIBOE();
    SCRIBOW();
    SCRIBOL();
    SCRIBOI();
    SCRIBOD();
    
    SCRIBOD("Auto-fill method and trace:");
    SCRIBOM();
    SCRIBOT();
}

void doQuux()
{
    SCRIBO(LOG, "Quux...");
    
    SCRIBO(DEBUG, "Auto-fill default verbosity:");
    SCRIBO();
    
    SCRIBO(DEBUG, "Auto-fill fatal, error, warning, log, info, and debug:");
    SCRIBO(FATAL);
    SCRIBO(ERROR);
    SCRIBO(WARNING);
    SCRIBO(LOG);
    SCRIBO(INFO);
    SCRIBO(DEBUG);
    
    SCRIBO(DEBUG, "Auto-fill method and trace:");
    SCRIBO(METHOD);
    SCRIBO(TRACE);
    
    quux();
}

// End of file ---------------------------------------------------------------------------------------------------------