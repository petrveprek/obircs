// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015, 2017 Petr Vepřek
// File: main.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages for APP category and invoke functions from other compilation units

#define SCRIBO_CATEGORY APP
#include <scribo.h>
#include "foo.h"
#include "bar.h"
#include "baz.h"
#include "qux.h"
#include "quux.h"
#include "fred.h"
#include "flob.h"

int main(int argc, char* argv[])
{
    if (argc >= 1)
    {
        SCRIBO(LOG, "Running %s", argv[0]);
    }
    doFoo();                                            // Produce log messages for FOO category and various verbosities
    doBar();                                            // Produce log messages for BAR category and various verbosities
    doBaz();                                           // Produce regular and shorthand log messages for all verbosities
    doQux();                                                            // Produce log messages with up to 20 parameters
    doQuux();            // Produce log messages with default verbosity (TRACE) and/or automatically-filled message text
    doFred();                             // Produce log messages for default category (GENERIC) and various verbosities
    doFlob();                                                       // Produce log messages while using conditional code
    SCRIBO(LOG, "The end");
    return 0;
}

// End of file ---------------------------------------------------------------------------------------------------------