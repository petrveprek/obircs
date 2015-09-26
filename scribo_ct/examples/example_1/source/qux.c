// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: qux.c
// ---------------------------------------------------------------------------------------------------------------------

// Produce log messages with up to 20 parameters

#define SCRIBO_CATEGORY QUX
#include <scribo.h>

void doQux()
{
    SCRIBO(LOG, "Qux...");
    
    SCRIBOD();
    SCRIBOD("None");
    SCRIBOD("One       %d",
        1);
    SCRIBOD("Two       %d %d",
        1, 2);
    SCRIBOD("Three     %d %d %d",
        1, 2, 3);
    SCRIBOD("Four      %d %d %d %d",
        1, 2, 3, 4);
    SCRIBOD("Five      %d %d %d %d %d",
        1, 2, 3, 4, 5);
    SCRIBOD("Six       %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6);
    SCRIBOD("Seven     %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7);
    SCRIBOD("Eight     %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8);
    SCRIBOD("Nine      %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9);
    SCRIBOD("Ten       %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    SCRIBOD("Eleven    %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    SCRIBOD("Twelve    %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    SCRIBOD("Thirteen  %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
    SCRIBOD("Fourteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
    SCRIBOD("Fifteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    SCRIBOD("Sixteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    SCRIBOD("Seventeen %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    SCRIBOD("Eighteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
    SCRIBOD("Nineteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19);
    SCRIBOD("Twenty    %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
    
    SCRIBO(DEBUG);
    SCRIBO(DEBUG,);
    SCRIBO(DEBUG, "None");
    SCRIBO(DEBUG, "One       %d",
        1);
    SCRIBO(DEBUG, "Two       %d %d",
        1, 2);
    SCRIBO(DEBUG, "Three     %d %d %d",
        1, 2, 3);
    SCRIBO(DEBUG, "Four      %d %d %d %d",
        1, 2, 3, 4);
    SCRIBO(DEBUG, "Five      %d %d %d %d %d",
        1, 2, 3, 4, 5);
    SCRIBO(DEBUG, "Six       %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6);
    SCRIBO(DEBUG, "Seven     %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7);
    SCRIBO(DEBUG, "Eight     %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8);
    SCRIBO(DEBUG, "Nine      %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9);
    SCRIBO(DEBUG, "Ten       %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    SCRIBO(DEBUG, "Eleven    %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    SCRIBO(DEBUG, "Twelve    %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    SCRIBO(DEBUG, "Thirteen  %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13);
    SCRIBO(DEBUG, "Fourteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
    SCRIBO(DEBUG, "Fifteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    SCRIBO(DEBUG, "Sixteen   %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16);
    SCRIBO(DEBUG, "Seventeen %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17);
    SCRIBO(DEBUG, "Eighteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18);
    SCRIBO(DEBUG, "Nineteen  %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19);
    SCRIBO(DEBUG, "Twenty    %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20);
}

// End of file ---------------------------------------------------------------------------------------------------------