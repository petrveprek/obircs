// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: bar.c
// ---------------------------------------------------------------------------------------------------------------------

#define SCRIBO_CATEGORY BAR
#include <scribo.h>

void bar(int i)
{
    SCRIBO(INFO, "bar(%d)", i);
}

void doBar()
{
    SCRIBO(LOG, "Bar...");
    SCRIBO(INFO, "About to loop...");
    for (int i = 0; i < 10; i++)
    {
        SCRIBO(DEBUG, "Loop %d", i);
        bar(i);
    }
    SCRIBO(INFO, "...done looping");
}

// End of file ---------------------------------------------------------------------------------------------------------