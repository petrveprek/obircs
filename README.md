# Welcome to *scribo*

__*scribo*__ /ˈskriː.boː/ Latin *verb* write; compose

*scribo* -- simple and flexible logging system suitable for embedded C and C++ applications.

| [Description](#basic-description) 
| [Configuration](#configuration-overview) 
| [Installation](#installation-and-setup) 
| [Specification](#detailed-specification) 
| [License](#copyright-and-license) |

---
# Basic Description

Each *scribo* log message is characterized by its category (optional) and verbosity (mandatory). To generate message 
content itself, *scribo* uses same style as printf function i.e. `format, ...` with two additions. The first addition is 
that the `format` may be omitted. In this case, only log message header is output. The second addition is that newline 
(`'\n'`) is automatically appended at the end of each log message. **Category** is user-defined per-source-file string 
(see Specification below for precise definition). It is optional and, when not defined, the default category `GENERIC` 
is used. There are eight levels of **verbosity** (from the least to the most verbose): `FATAL`, `ERROR`, `WARNING`, 
`LOG`, `INFO`, `DEBUG`, `METHOD`, and `TRACE`.

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

---
# Configuration Overview

## Compile Time

At compile time, all *scribo* logging, logging for some categories, or logging for some verbosities can be disabled. In 
addition, logging for some category-verbosity combinations can be enabled. This is useful as an override together with 
disabling categories and verbosities. Logging disabled at compile-time has zero run-time overhead (i.e. it uses no 
memory space and consumes no computational cycles).

To disable/enable desired *scribo* logging options, predefined preprocessor tokens must be hash-defined either in 
`scribo.cfg` configuration file or be provided via command line toolchain option.

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
`TRACE`; enable *scribo* logging for category `APP` and verbosity `DEBUG` combination:
```c
#define SCRIBO_DISABLE_CATEGORY_GENERIC 1 // Disable *scribo* logging for category `GENERIC` (all verbosities)
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable *scribo* logging for verbosity `DEBUG` and more verbose i.e. `METHOD` and `TRACE` (all categories)
#define SCRIBO_ENABLE_CATEGORY_APP_VERBOSITY_DEBUG 1 // Enable *scribo* logging for category APP with verbosity 
`DEBUG`
```

---
# Installation and Setup

Add *scribo* header and implementation files (from `include` and `source` directories respectively) to your project. 
Either copy the files to your project directories or add *scribo*'s `include` and `source` locations to your project 
file.

---
# Detailed Specification

## Run-Time Usage

**First** specify (optional) logging category and include `scribo.h` in your source file(s):
```c
#define SCRIBO_CATEGORY APP
#include <scribo.h>
```
The category is specified per-file so every source file can have its own, or not.

If you don't specify category, then `GENERIC` will be used as the default category.

Category must a valid pre-processor token, more specifically a valid identifier (`[_a-zA-Z][_a-zA-Z0-9]*`).

**Then** output log messages using:
```c
SCRIBO(<verbosity>, "...", ...);
```
where `<verbosity>` is one of predefined verbosities and `"...", ...` is printf-style format and arguments.

Unlike printf, *scribo* does **not** require format. If format is not specified, then *scribo* outputs log message 
header only.

Note that *scribo* automatically appends newline (`'\n'`) at the end of each and every log message.

`<verbosity>` can be one of the following predefined values (ordered from the least to the most verbose):
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
where `<v>` is abbreviation of one of predefined verbosities as follows:
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
// Log message header only - normal form
SCRIBO(FATAL);
SCRIBO(ERROR);
SCRIBO(WARNING);
SCRIBO(LOG);
SCRIBO(INFO);
SCRIBO(DEBUG);
SCRIBO(METHOD);
SCRIBO(TRACE);
// Log message header only - shorthand form
SCRIBOF();
SCRIBOE();
SCRIBOW();
SCRIBOL();
SCRIBOI();
SCRIBOD();
SCRIBOM();
SCRIBOT();
// Log message with format - normal form
SCRIBO(FATAL, "Hello");
SCRIBO(ERROR, "Hello");
SCRIBO(WARNING, "Hello");
SCRIBO(LOG, "Hello");
SCRIBO(INFO, "Hello");
SCRIBO(DEBUG, "Hello");
SCRIBO(METHOD, "Hello");
SCRIBO(TRACE, "Hello");
// Log message with format - shorthand form
SCRIBOF("Hello");
SCRIBOE("Hello");
SCRIBOW("Hello");
SCRIBOL("Hello");
SCRIBOI("Hello");
SCRIBOD("Hello");
SCRIBOM("Hello");
SCRIBOT("Hello");
// Log message with format and arguments - normal form
SCRIBO(FATAL, "%d + %d equals %d", 1, 1, 2);
SCRIBO(ERROR, "%d + %d equals %d", 1, 1, 2);
SCRIBO(WARNING, "%d + %d equals %d", 1, 1, 2);
SCRIBO(LOG, "%d + %d equals %d", 1, 1, 2);
SCRIBO(INFO, "%d + %d equals %d", 1, 1, 2);
SCRIBO(DEBUG, "%d + %d equals %d", 1, 1, 2);
SCRIBO(METHOD, "%d + %d equals %d", 1, 1, 2);
SCRIBO(TRACE, "%d + %d equals %d", 1, 1, 2);
// Log message with format and arguments - shorthand form
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

At compile time, *scribo* logging can be configured.  All logging or selected categories and verbosities can be 
disabled. When disabled, the logging is completely removed and has no memory or computation overhead whatsoever. This 
allows for different types of logging to be present in the codebase on permanent basis.  When building software, 
development version can have detailed logging present, while production version can be less verbose.  Configuration of 
*scribo* is controlled through a set of hash-defines.  The defines can be provided during build time as toolchain 
command-line option, or the defines can be kept in a configuration file (`scribo.cfg`).

Note that for a *scribo* configuration option to be active, it must be either provided on the command line, or be 
hash-defined in `scribo.cfg` to have value of 1. Value 1 of an option is treated as "enabled", any other value 
(including not being defined at all) is treated as "disabled".

#### Disable all *scribo* logging

```c
#define SCRIBO_DISABLE_ALL 1 // Completely disable all *scribo* logging
```

#### Disable *scribo* logging for a category

```c
#define SCRIBO_DISABLE_CATEGORY_<category> 1 // Disable *scribo* logging for category <category> (all verbosities)
```
where `<category>` is the category specified in `#define SCRIBO_CATEGORY <category>`, or `GENERIC` (when category was 
not specified).

Example:
```c
#define SCRIBO_DISABLE_CATEGORY_THIS_MODULE 1 // Disable *scribo* logging for category THIS_MODULE (all verbosities)
#define SCRIBO_DISABLE_CATEGORY_THAT_MODULE 1 // Disable *scribo* logging for category THAT_MODULE (all verbosities)
```

#### Disable *scribo* logging for a verbosity

```c
#define SCRIBO_DISABLE_VERBOSITY_<verbosity> 1 // Disable *scribo* logging for verbosity <verbosity> (all categories)
```
where `<verbosity>` is one of the predefined verbosities i.e. `FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, 
`METHOD`, or `TRACE`.

Example:
```c
#define SCRIBO_DISABLE_VERBOSITY_TRACE 1 // Disable *scribo* logging for verbosity TRACE (all categories)
```

Apart from disabling individual verbosities one-by-one, *scribo* provides shorthand to disable a verbosity and all more 
verbose ones in using one configuration option.

```c
#define SCRIBO_DISABLE_VERBOSITY_<verbosity>_ETC 1 // Disable *scribo* logging for verbosity <verbosity> and more 
verbose ones (all categories)
```

Example:
```c
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable *scribo* logging for verbosity `DEBUG` and more verbose 
(i.e. `METHOD` and `TRACE`) (all categories)
```

#### Enable *scribo* logging for combination of a category and a verbosity

Finally, *scribo* provides configuration option to enable logging for a combination of a category and a verbosity.  This 
is useful in as an override together with the above two options that disable categories and verbosities.

```c
#define SCRIBO_ENABLE_CATEGORY_<category>_VERBOSITY_<verbosity> 1 // Enable *scribo* logging for category <category> 
with verbosity <verbosity>
```
where `<category>` and `` are defined as above.

Example:
```c
#define SCRIBO_DISABLE_CATEGORY_SOME_MODULE 1 // Disable *scribo* logging for category SOME_MODULE (all verbosities)
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable *scribo* logging for verbosity `DEBUG` and more verbose 
(i.e. `METHOD` and `TRACE`) (all categories)
#define SCRIBO_ENABLE_CATEGORY_SOME_MODULE_VERBOSITY_DEBUG 1 // Enable *scribo* logging for category SOME_MODULE 
with verbosity DEBUG
```

---
# Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see `LICENSE` for further details.
