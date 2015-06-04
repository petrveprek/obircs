// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: main.c
// ---------------------------------------------------------------------------------------------------------------------

#define SCRIBO_CATEGORY APP
#include <scribo.h>
#include "foo.h"
#include "bar.h"

int main(int argc, char* argv[])
{
    if (argc >= 1)
    {
        SCRIBO(LOG, "Running %s", argv[0]);
    }
    doFoo();
    doBar();
    SCRIBO(LOG, "The end");
    return 0;
}

// End of file ---------------------------------------------------------------------------------------------------------