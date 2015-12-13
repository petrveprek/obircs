// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: flob.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages while using conditional code

#define SCRIBO_CATEGORY FLOB
#include <scribo.h>

void doFlob()
{
    int i, n = 0;
    SCRIBO(LOG, "Flob...");
    
    EXEQUI(DEBUG,
        SCRIBO(TRACE);
        for (i = 0; i < 10; i++)
        {
            n += i;
        }
        n -= 3;
    );
    SCRIBO(DEBUG, "The answer is %d", n);
}

// End of file ---------------------------------------------------------------------------------------------------------