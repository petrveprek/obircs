// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: baz.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce regular and shorthand log messages for all verbosities

#define SCRIBO_CATEGORY BAZ
#include <scribo.h>

void doBaz()
{
    SCRIBO(LOG, "Baz...");                                                                // Category BAZ, verbosity LOG
     
    SCRIBO(LOG, "Regular log messages with parameter:");                                  // Category BAZ, verbosity LOG
    SCRIBO(FATAL, "Fatal blah...");                                                     // Category BAZ, verbosity FATAL
    SCRIBO(ERROR, "Error blah...");                                                     // Category BAZ, verbosity ERROR
    SCRIBO(WARNING, "Warning blah...");                                               // Category BAZ, verbosity WARNING
    SCRIBO(LOG, "Log blah...");                                                           // Category BAZ, verbosity LOG
    SCRIBO(INFO, "Info blah...");                                                        // Category BAZ, verbosity INFO
    SCRIBO(DEBUG, "Debug blah...");                                                     // Category BAZ, verbosity DEBUG
    SCRIBO(METHOD, "Method blah...");                                                  // Category BAZ, verbosity METHOD
    SCRIBO(TRACE, "Trace blah...");                                                     // Category BAZ, verbosity TRACE
    
    SCRIBO(LOG, "Regular log messages without parameter:");                               // Category BAZ, verbosity LOG
    SCRIBO(FATAL);                                                                      // Category BAZ, verbosity FATAL
    SCRIBO(ERROR);                                                                      // Category BAZ, verbosity ERROR
    SCRIBO(WARNING);                                                                  // Category BAZ, verbosity WARNING
    SCRIBO(LOG);                                                                          // Category BAZ, verbosity LOG
    SCRIBO(INFO);                                                                        // Category BAZ, verbosity INFO
    SCRIBO(DEBUG);                                                                      // Category BAZ, verbosity DEBUG
    SCRIBO(METHOD);                                                                    // Category BAZ, verbosity METHOD
    SCRIBO(TRACE);                                                                      // Category BAZ, verbosity TRACE
    
    SCRIBO(LOG, "Shorthand log messages with parameter:");                                // Category BAZ, verbosity LOG
    SCRIBOF("Fatal blah...");                                                           // Category BAZ, verbosity FATAL
    SCRIBOE("Error blah...");                                                           // Category BAZ, verbosity ERROR
    SCRIBOW("Warning blah...");                                                       // Category BAZ, verbosity WARNING
    SCRIBOL("Log blah...");                                                               // Category BAZ, verbosity LOG
    SCRIBOI("Info blah...");                                                             // Category BAZ, verbosity INFO
    SCRIBOD("Debug blah...");                                                           // Category BAZ, verbosity DEBUG
    SCRIBOM("Method blah...");                                                         // Category BAZ, verbosity METHOD
    SCRIBOT("Trace blah...");                                                           // Category BAZ, verbosity TRACE
    
    SCRIBO(LOG, "Shorthand log messages without parameter:");                             // Category BAZ, verbosity LOG
    SCRIBOF();                                                                          // Category BAZ, verbosity FATAL
    SCRIBOE();                                                                          // Category BAZ, verbosity ERROR
    SCRIBOW();                                                                        // Category BAZ, verbosity WARNING
    SCRIBOL();                                                                            // Category BAZ, verbosity LOG
    SCRIBOI();                                                                           // Category BAZ, verbosity INFO
    SCRIBOD();                                                                          // Category BAZ, verbosity DEBUG
    SCRIBOM();                                                                         // Category BAZ, verbosity METHOD
    SCRIBOT();                                                                          // Category BAZ, verbosity TRACE
}

// End of file ---------------------------------------------------------------------------------------------------------