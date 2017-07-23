// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015, 2017 Petr Vepřek
// File: bar.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages for BAR category and various verbosities

#define SCRIBO_CATEGORY BAR
#include <scribo.h>

void bar(int i)
{
    SCRIBO(INFO, "bar(%d)", i);
}

void doBar()
{
    int i;
    SCRIBO(LOG, "`bar` --begin--");
    
    SCRIBO(INFO, "About to loop...");
    for (i = 0; i < 10; i++)
    {
        SCRIBO(DEBUG, "Loop %d", i);
        bar(i);
    }
    SCRIBO(INFO, "...done looping");
    
    SCRIBO(LOG, "`bar` --end--");
}

// End of file ---------------------------------------------------------------------------------------------------------