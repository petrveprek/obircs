# Welcome to *scribo*

__*scribo*__ /ˈskriː.boː/ Latin *verb* write; compose

*scribo* is simple and flexible logging system suitable for embedded C and C++ applications.

## Description

Each logging message is characterized by category (optional) and verbosity (mandatory). To generate message content 
itself, *scribo* uses the same style as printf function i.e. `format, ...` with two additions. The first addition is 
that the `format` can be omitted. In this case, only the message header is output. The second addition is that `'\n'` is 
automatically appended at the end of each log message. **Category** is user-defined per-source-file string. It is 
optional and when not defined the default category `GENERIC` is used. There are eight levels of **verbosity** (from 
least to most verbose): `FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, `METHOD`, and `TRACE`.

Example (minimalistic):
```c
#include "scribo.h"
int main(int argc, char* argv[])
{
    SCRIBO(LOG);
    return 0;
}
```

Example (realistic):
```c
#define SCRIBO_CATEGORY APP
#include "scribo.h"
int main(int argc, char* argv[])
{
    SCRIBO(LOG, "Executable %s (%d parameters)", argv[0], argc);
    return 0;
}
```

## Configuration

### Compile Time

At compile time, all *scribo* logging, logging for some categories, or logging for some verbosities can be disabled. In 
addition, logging for some category-verbosity combinations can be enabled. This is useful as an override together with 
disabling categories or verbosities. Logging disabled at compile-time has zero run-time overhead (i.e. it consumes no 
memory space and no computational cycles).

To disable/enable desired logging options, pre-defined pre-processor tokens must be hash-defined either in `scribo.cfg` 
configuration file or via command line toolchain option.

Examples (`scribo.cfg`):
- `#define SCRIBO_DISABLE_ALL` ... completely disables all *scribo* logging

## Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see `LICENSE` for further details.