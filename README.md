# Welcome to *scribo*

__*scribo*__ [/ˈskriː.boː/ Latin *verb* write; compose]

*scribo* is simple and flexible logging system suitable for embedded C and C++ applications.

## Description

Each logging message is characterized by category (optional) and verbosity (mandatory).  To generate message content 
itself, *scribo* uses the same style as printf function i.e. `format, ...` with two additions.  The first addition is 
that the `format` can be omitted.  It this case, only the message header is output.  The second addition is that `'\n'` 
is automatically appended at the end of the log message.  **Category** is user-defined per-source-file string.  It is 
optional and when not defined the default category 'UNKNOWN' is used.  There are eight levels of **verbosity** (from 
least to most verbose): 'FATAL', 'ERROR', 'WARNING', 'LOG', 'INFO', 'DEBUG', 'METHOD', and 'TRACE'.  

Example (minimalistic):
```c
#include "scribo.h"
int main(int argc, char* argv[])
{
    SCRIBO(LOG);
}
```

Example (realistic):
```c
#define SCRIBO_CATEGORY APP
#include "scribo.h"
int main(int argc, char* argv[])
{
    SCRIBO(LOG, "Executable %s (%d parameters)", argv[0], argn);
}
```

## Configuration

### Compile Time

At compile time, all *scribo* logging, logging for some categories, or logging for some verbosities can be disabled.  
In addition, logging for some category-verbosity combinations can be enabled.  This is useful as an override together 
with disabling categories or verbosities.

## Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see `LICENSE` for further details.