// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: scribo.c
// ---------------------------------------------------------------------------------------------------------------------

#include <scribo.h>

// To scribo or not to scribo
#if SCRIBO_DISABLE_ALL != 1
    
    // Delegate outputting log message
#   ifdef SCRIBO_INVOKE_CALLBACK
        #include <stdarg.h>
        #include <string.h>
        void scribo__ouput_message(void (*callback)(const char*), size_t size, int newline, const char* format, ...)
        {
            va_list args1; // First pass to get length of log message (if needed)
            va_start(args1, format);
            va_list args2; // Second pass to output log message
            va_copy(args2, args1);
            if (0 == size)
            {
                size = vsnprintf(NULL, 0, format, args1);
            }
            va_end(args1);
            char text[1 + size];
            vsnprintf(text, sizeof text, format, args2);
            if (1 == newline)
            {
                size = strlen(text);
                if (1 <= size)
                {
                    text[size - 1] = '\n';
                }
            }
            callback(text); // Delegate
            va_end(args2);
        }
#   endif
    
#endif

// End of file ---------------------------------------------------------------------------------------------------------