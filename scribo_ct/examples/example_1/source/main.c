// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: main.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages and invoke functions from other compilation units

#define SCRIBO_CATEGORY APP
#include <scribo.h>
#include "foo.h"
#include "bar.h"
#include "baz.h"
#include "qux.h"

int main(int argc, char* argv[])
{
    if (argc >= 1)
    {
        SCRIBO(LOG, "Running %s", argv[0]);                                               // Category APP, verbosity LOG
    }
    doFoo();
    doBar();
    doBaz();
    doQux();
    SCRIBO(LOG, "The end");                                                               // Category APP, verbosity LOG
    return 0;
}

// End of file ---------------------------------------------------------------------------------------------------------