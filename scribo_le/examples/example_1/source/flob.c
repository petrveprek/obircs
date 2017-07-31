// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015, 2017 Petr Vepřek
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
    typedef enum { false, true } bool;
    int data[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    SCRIBO(LOG, "`flob` --begin--");
    
    EXEQUI();
    EXEQUI(INFO);
    EXEQUI(INFO, SCRIBO());
    process(data, sizeof(data)/sizeof(data[0]));
    
    IF_SCRIBO(true, FATAL,   "IF_SCRIBO(true, FATAL, ...)");
    IF_SCRIBO(true, ERROR,   "IF_SCRIBO(true, ERROR, ...)");
    IF_SCRIBO(true, WARNING, "IF_SCRIBO(true, WARNING, ...)");
    IF_SCRIBO(true, LOG,     "IF_SCRIBO(true, LOG, ...)");
    IF_SCRIBO(true, INFO,    "IF_SCRIBO(true, INFO, ...)");
    IF_SCRIBO(true, DEBUG,   "IF_SCRIBO(true, DEBUG, ...)");
    IF_SCRIBO(true, METHOD,  "IF_SCRIBO(true, METHOD, ...)");
    IF_SCRIBO(true, TRACE,   "IF_SCRIBO(true, TRACE, ...)");
    
    IF_SCRIBOF(true, "IF_SCRIBOF(true, ...)");
    IF_SCRIBOE(true, "IF_SCRIBOE(true, ...)");
    IF_SCRIBOW(true, "IF_SCRIBOW(true, ...)");
    IF_SCRIBOL(true, "IF_SCRIBOL(true, ...)");
    IF_SCRIBOI(true, "IF_SCRIBOI(true, ...)");
    IF_SCRIBOD(true, "IF_SCRIBOD(true, ...)");
    IF_SCRIBOM(true, "IF_SCRIBOM(true, ...)");
    IF_SCRIBOT(true, "IF_SCRIBOT(true, ...)");
    
    IF_SCRIBO(false, INFO,   "Oops!");
    IF_SCRIBO(true,  INFO,   "Okay.");
    
    IF_SCRIBO(true, INFO, "Et cetera");
    IF_SCRIBO(true, INFO, );
    IF_SCRIBO(true, INFO,);
    IF_SCRIBO(true, INFO);
    
    IF_SCRIBOI(true, "Et cetera");
    IF_SCRIBOI(true, );
    IF_SCRIBOI(true,);
    IF_SCRIBOI(true);
    
    IF_SCRIBO(true, TRACE);
    IF_SCRIBO(true, );
    IF_SCRIBO(true,);
    IF_SCRIBO(true);
    IF_SCRIBO();
    
    IF_SCRIBOT(true);
    IF_SCRIBOT();
    
    SCRIBO(LOG, "`flob` --end--");
}

// End of file ---------------------------------------------------------------------------------------------------------