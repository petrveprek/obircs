// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: bar.c
// ---------------------------------------------------------------------------------------------------------------------

#define SCRIBO_CATEGORY BAR
#include <scribo.h>

void bar(int i)
{
    SCRIBO(INFO, "bar(%d)", i);                                                         // Category BAR, verbosity INFO.
}

void doBar()
{
    SCRIBO(LOG, "Bar...");                                                               // Category BAR, verbosity LOG.
    SCRIBO(INFO, "About to loop...");                                                   // Category BAR, verbosity INFO.
    for (int i = 0; i < 10; i++)
    {
        SCRIBO(DEBUG, "Loop %d", i);                                                   // Category BAR, verbosity DEBUG.
        bar(i);
    }
    SCRIBO(INFO, "...done looping");                                                    // Category BAR, verbosity INFO.
}

// End of file ---------------------------------------------------------------------------------------------------------