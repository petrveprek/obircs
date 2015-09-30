// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: fred.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages for unspecified (GENERIC) category and various verbosities

#include <scribo.h>
#include "fred.h"

void doFred()
{
    SCRIBO(LOG, "Fred...");
    
    SCRIBO(INFO, "About to loop...");
    for (int i = 0; i < 10; i++)
    {
        if (i % 5 == 0)
            SCRIBO(INFO, "Loop %d", i);
        else
            SCRIBO(DEBUG, "Loop %d", i);
    }
    SCRIBO(INFO, "...done looping");
}

// End of file ---------------------------------------------------------------------------------------------------------