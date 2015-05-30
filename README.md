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
disabling categories or verbosities. Logging disabled at compile-time has zero run-time overhead (i.e. it uses no 
memory space and consumes no computational cycles).

To disable/enable desired logging options, pre-defined pre-processor tokens must be hash-defined either in `scribo.cfg` 
configuration file or via command line toolchain option.

Examples (`scribo.cfg`):
Disable all *scribo* logging:
- `#define SCRIBO_DISABLE_ALL 1` ... completely disables all *scribo* logging
Disable all *scribo* logging for category `GENERIC`:
- `#define SCRIBO_DISABLE_CATEGORY_GENERIC 1` ... disable *scribo* logging for category `GENERIC` (all verbosities)
Disable all *scribo* logging for verbosities `METHOD` and `TRACE`:
- `#define SCRIBO_DISABLE_VERBOSITY_METHOD 1` ... disable *scribo* logging for verbosity `METHOD` (all categories)
- `#define SCRIBO_DISABLE_VERBOSITY_TRACE 1` ... disable *scribo* logging for verbosity `TRACE` (all categories)
Disable all *scribo* logging for category `GENERIC` and all *scribo* logging for verbosities `DEBUG`, `METHOD`, and 
`TRACE`; enable *scribo* logging for category `APP` and verbosity `DEBUG`:
- `#define SCRIBO_DISABLE_CATEGORY_GENERIC 1` ... disable *scribo* logging for category `GENERIC`
- `#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1` ... disable *scribo* logging for verbosity `DEBUG` and more verbose 
(i.e. `METHOD` and `TRACE`)
- `#define SCRIBO_ENABLE_CATEGORY_APP_VERBOSITY_DEBUG 1` ... enable *scribo* logging for category APP with verbosity 
`DEBUG`

## Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see `LICENSE` for further details.