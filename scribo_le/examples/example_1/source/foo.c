// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: foo.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages for FOO category and various verbosities

#define SCRIBO_CATEGORY FOO
#include <scribo.h>

void doFoo()
{
    int i;
    SCRIBO(LOG, "Foo...");
    
    SCRIBO(INFO, "About to loop...");
    for (i = 0; i < 10; i++)
    {
        if (i % 5 == 0)
            SCRIBO(INFO, "Loop %d", i);
        else
            SCRIBO(DEBUG, "Loop %d", i);
    }
    SCRIBO(INFO, "...done looping");
}

// End of file ---------------------------------------------------------------------------------------------------------