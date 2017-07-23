// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015, 2017 Petr Vepřek
// File: baz.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce regular and shorthand log messages for all verbosities

#define SCRIBO_CATEGORY BAZ
#include <scribo.h>

void doBaz()
{
    SCRIBO(LOG, "`baz` --begin--");
    
    SCRIBO(LOG, "Regular log messages with parameter:");
    SCRIBO(FATAL, "Fatal blah...");
    SCRIBO(ERROR, "Error blah...");
    SCRIBO(WARNING, "Warning blah...");
    SCRIBO(LOG, "Log blah...");
    SCRIBO(INFO, "Info blah...");
    SCRIBO(DEBUG, "Debug blah...");
    SCRIBO(METHOD, "Method blah...");
    SCRIBO(TRACE, "Trace blah...");
    
    SCRIBO(LOG, "Regular log messages without parameter:");
    SCRIBO(FATAL);
    SCRIBO(ERROR);
    SCRIBO(WARNING);
    SCRIBO(LOG);
    SCRIBO(INFO);
    SCRIBO(DEBUG);
    SCRIBO(METHOD);
    SCRIBO(TRACE);
    
    SCRIBO(LOG, "Shorthand log messages with parameter:");
    SCRIBOF("Fatal blah...");
    SCRIBOE("Error blah...");
    SCRIBOW("Warning blah...");
    SCRIBOL("Log blah...");
    SCRIBOI("Info blah...");
    SCRIBOD("Debug blah...");
    SCRIBOM("Method blah...");
    SCRIBOT("Trace blah...");
    
    SCRIBO(LOG, "Shorthand log messages without parameter:");
    SCRIBOF();
    SCRIBOE();
    SCRIBOW();
    SCRIBOL();
    SCRIBOI();
    SCRIBOD();
    SCRIBOM();
    SCRIBOT();
    
    SCRIBO(LOG, "`baz` --end--");
}

// End of file ---------------------------------------------------------------------------------------------------------