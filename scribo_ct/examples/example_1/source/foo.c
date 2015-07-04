// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: foo.c
// ---------------------------------------------------------------------------------------------------------------------

#define SCRIBO_CATEGORY FOO
#include <scribo.h>

void doFoo()
{
    SCRIBO(LOG, "Foo...");                                                               // Category FOO, verbosity LOG.
    SCRIBO(INFO, "About to loop...");                                                   // Category FOO, verbosity INFO.
    for (int i = 0; i < 10; i++)
    {
        if (i % 5 == 0)
            SCRIBO(INFO, "Loop %d", i);                                                 // Category FOO, verbosity INFO.
        else
            SCRIBO(DEBUG, "Loop %d", i);                                               // Category FOO, verbosity DEBUG.
    }
    SCRIBO(INFO, "...done looping");                                                    // Category FOO, verbosity INFO.
}

// End of file ---------------------------------------------------------------------------------------------------------