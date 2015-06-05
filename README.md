# Welcome to *scribo*

__*scribo*__ /ˈskriː.boː/ Latin *verb* write; compose

*scribo* -- simple and flexible logging system suitable for embedded C and C++ applications.

| [Description](#basic-description) 
| [Configuration](#configuration-overview) 
| [Installation](#package-installation) 
| [Specification](#detailed-specification) 
| [License](#copyright-and-license) |

# Basic Description

Each logging message is characterized by category (optional) and verbosity (mandatory). To generate message content 
itself, *scribo* uses same style as printf function i.e. `format, ...` with two additions. The first addition is that 
the `format` may be omitted. In this case, only message header is output. The second addition is that `'\n'` is 
automatically appended at the end of each log message. **Category** is user-defined per-source-file string. It is 
optional and, when not defined, the default category `GENERIC` is used. There are eight levels of **verbosity** (from 
the least to the most verbose): `FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, `METHOD`, and `TRACE`.

Example (minimalistic):
```c
#include <scribo.h>
int main(int argc, char* argv[])
{
    SCRIBO(LOG);
    return 0;
}
```
This outputs log message similar to "`2015-05-31 16:22:39 #0000000024 GENERIC LOG     : `".

Example (realistic):
```c
#define SCRIBO_CATEGORY APP
#include <scribo.h>
int main(int argc, char* argv[])
{
    SCRIBO(LOG, "Executable %s (%d parameters)", argv[0], argc);
    return 0;
}
```
This outputs log message similar to "`2015-05-31 16:23:47 #0000000000 APP     LOG     : Executable Scribo.exe (1 parameters)`".

# Configuration Overview

## Compile Time

At compile time, all *scribo* logging, logging for some categories, or logging for some verbosities can be disabled. In 
addition, logging for some category-verbosity combinations can be enabled. This is useful as an override together with 
disabling categories or verbosities. Logging disabled at compile-time has zero run-time overhead (i.e. it uses no 
memory space and consumes no computational cycles).

To disable/enable desired logging options, pre-defined pre-processor tokens must be hash-defined either in `scribo.cfg` 
configuration file or via command line toolchain option.

Examples (`scribo.cfg`):

Disable all *scribo* logging:
```c
#define SCRIBO_DISABLE_ALL 1 // Completely disable all *scribo* logging
```

Disable *scribo* logging for category `GENERIC`:
```c
#define SCRIBO_DISABLE_CATEGORY_GENERIC 1 // Disable *scribo* logging for category `GENERIC` (all verbosities)
```

Disable *scribo* logging for verbosities `METHOD` and `TRACE`:
```c
#define SCRIBO_DISABLE_VERBOSITY_METHOD 1 // Disable *scribo* logging for verbosity `METHOD` (all categories)
#define SCRIBO_DISABLE_VERBOSITY_TRACE 1 // Disable *scribo* logging for verbosity `TRACE` (all categories)
```

Disable *scribo* logging for category `GENERIC` and *scribo* logging for verbosities `DEBUG`, `METHOD`, and 
`TRACE`; enable *scribo* logging for category `APP` and verbosity `DEBUG`:
```c
#define SCRIBO_DISABLE_CATEGORY_GENERIC 1 // Disable *scribo* logging for category `GENERIC`
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable *scribo* logging for verbosity `DEBUG` and more verbose 
(i.e. `METHOD` and `TRACE`)
#define SCRIBO_ENABLE_CATEGORY_APP_VERBOSITY_DEBUG 1 // Enable *scribo* logging for category APP with verbosity 
`DEBUG`
```

# Package Installation

Add *scribo* header and implementation files (from `include` and `source` directories respectively) to your project. 
Either copy the files to your project directories or add *scribo*'s `include` and `source` locations to your project 
file.

# Detailed Specification

## Run-Time Usage

**First** specify (optional) logging category and include `scribo.h`:
```c
#define SCRIBO_CATEGORY APP
#include <scribo.h>
```
If you don't specify category, then `GENERIC` will be used as the default category.

Category must a valid pre-processor token, more specifically a valid identifier (`[_a-zA-Z][_a-zA-Z0-9]*`).

**Then** output logging messages using:
```c
SCRIBO(<verbosity>, "...", ...);
```
where `<verbosity>` is one of pre-defined verbosities and `"...", ...` are printf-style format and arguments.

Unlike printf, *scribo* does **not** require format. If format is not specified, then *scribo* outputs message header 
only.

Note that *scribo* automatically appends `'\n'` to each logging message.

`<verbosity>` can be one of the following pre-defined values (ordered from the least to the most verbose):
- `FATAL` ... fatal unrecoverable error message
- `ERROR` ... recoverable error message
- `WARNING` ... warning message
- `LOG` ... basic log message
- `INFO` ... information message
- `DEBUG` ... detailed debug message
- `METHOD` ... method entry/exit message
- `TRACE` ... code file and line trace message

Above, following each verbosity value, is its suggested usage.

The maximum number of arguments following the format is **limited** by *scribo* to twenty (20).

Format of *scribo* logging can be abbreviated to:
```c
SCRIBO<v>("...", ...);
```
where `<v>` is abbreviation of one of pre-defined verbosities as follows:
- `F` for `FATAL`
- `E` for `ERROR`
- `W` for `WARNING`
- `L` for `LOG`
- `I` for `INFO`
- `D` for `DEBUG`
- `M` for `METHOD`
- `T` for `TRACE`

Examples:
```c
// Logging message header only - normal form
SCRIBO(FATAL);
SCRIBO(ERROR);
SCRIBO(WARNING);
SCRIBO(LOG);
SCRIBO(INFO);
SCRIBO(DEBUG);
SCRIBO(METHOD);
SCRIBO(TRACE);
// Logging message header only - shorthand form
SCRIBOF();
SCRIBOE();
SCRIBOW();
SCRIBOL();
SCRIBOI();
SCRIBOD();
SCRIBOM();
SCRIBOT();
// Logging message with format - normal form
SCRIBO(FATAL, "Hello");
SCRIBO(ERROR, "Hello");
SCRIBO(WARNING, "Hello");
SCRIBO(LOG, "Hello");
SCRIBO(INFO, "Hello");
SCRIBO(DEBUG, "Hello");
SCRIBO(METHOD, "Hello");
SCRIBO(TRACE, "Hello");
// Logging message with format - shorthand form
SCRIBOF("Hello");
SCRIBOE("Hello");
SCRIBOW("Hello");
SCRIBOL("Hello");
SCRIBOI("Hello");
SCRIBOD("Hello");
SCRIBOM("Hello");
SCRIBOT("Hello");
// Logging message with format and arguments - normal form
SCRIBO(FATAL, "%d + %d equals %d", 1, 1, 2);
SCRIBO(ERROR, "%d + %d equals %d", 1, 1, 2);
SCRIBO(WARNING, "%d + %d equals %d", 1, 1, 2);
SCRIBO(LOG, "%d + %d equals %d", 1, 1, 2);
SCRIBO(INFO, "%d + %d equals %d", 1, 1, 2);
SCRIBO(DEBUG, "%d + %d equals %d", 1, 1, 2);
SCRIBO(METHOD, "%d + %d equals %d", 1, 1, 2);
SCRIBO(TRACE, "%d + %d equals %d", 1, 1, 2);
// Logging message with format and arguments - shorthand form
SCRIBOF("%d + %d equals %d", 1, 1, 2);
SCRIBOE("%d + %d equals %d", 1, 1, 2);
SCRIBOW("%d + %d equals %d", 1, 1, 2);
SCRIBOL("%d + %d equals %d", 1, 1, 2);
SCRIBOI("%d + %d equals %d", 1, 1, 2);
SCRIBOD("%d + %d equals %d", 1, 1, 2);
SCRIBOM("%d + %d equals %d", 1, 1, 2);
SCRIBOT("%d + %d equals %d", 1, 1, 2);
```

## Configuration

### Compile Time

### Run Time

# Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see `LICENSE` for further details.
