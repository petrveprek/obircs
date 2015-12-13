// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: flob.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages while using conditional code

#define SCRIBO_CATEGORY FLOB
#include <scribo.h>

void process(int* data, unsigned count)
{
    EXEQUI(LOG,
        unsigned i;
        int hash = 0;
        for (i = 0; i < count; i++)
        {
            SCRIBO(DEBUG, "data[%d] = %d", i, data[i]);
            hash |= data[i];
        }
        SCRIBO(LOG, "data[] xor checksum = %d", hash);
    );
}

void doFlob()
{
    int data[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    SCRIBO(LOG, "Flob...");
    process(data, sizeof(data)/sizeof(data[0]));
}

// End of file ---------------------------------------------------------------------------------------------------------