// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: qux.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages with up to 20 parameters

#define SCRIBO_CATEGORY QUX
#include <scribo.h>

void doQux()
{
    SCRIBO(LOG, "Qux...");                                                                // Category QUX, verbosity LOG
    
    SCRIBO(DEBUG);                                                                      // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "None");                                                              // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "One       %d",
        1);                                                                             // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Two       %d %d",
        1, 2);                                                                          // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Three     %d %d %d",
        1, 2, 3);                                                                       // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Four      %d %d %d %d",
        1, 2, 3, 4);                                                                    // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Five      %d %d %d %d %d",
        1, 2, 3, 4, 5);                                                                 // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Six       %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6);                                                              // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Seven     %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7);                                                           // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Eight     %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8);                                                        // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Nine      %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9);                                                     // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Ten       %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10);                                                 // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Eleven    %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);                                             // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Twelve    %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);                                         // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Thirteen  %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);                                     // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Fourteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);                                 // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Fifteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);                             // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Sixteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);                         // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Seventeen %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);                     // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Eighteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);                 // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Nineteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19);             // Category QUX, verbosity DEBUG
    SCRIBO(DEBUG, "Twenty    %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);         // Category QUX, verbosity DEBUG
}

// End of file ---------------------------------------------------------------------------------------------------------