// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015, 2017 Petr Vepřek
// File: fred.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages for default category (GENERIC) and various verbosities

#include <scribo.h>

void doFred()
{
    int i;
    SCRIBO(LOG, "`fred` --begin--");
    
    SCRIBO(DEBUG, "Default category and auto-fill default verbosity:");
    SCRIBO();
    
    SCRIBO(INFO, "About to loop...");
    for (i = 0; i < 10; i++)
    {
        if (i % 5 == 0)
            SCRIBO(INFO, "Loop %d", i);
        else
            SCRIBO(DEBUG, "Loop %d", i);
    }
    SCRIBO(INFO, "...done looping");
    
    SCRIBO(LOG, "`fred` --end--");
}

// End of file ---------------------------------------------------------------------------------------------------------