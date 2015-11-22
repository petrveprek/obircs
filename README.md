# Welcome to *scribo*

__*scribo*__ /'skri:.bo:/ Latin *verb* write; compose

*scribo* -- simple and flexible logging system suitable for embedded C and C++ applications.

| [Welcome](#welcome-to-scribo "Welcome to *scribo*") 
| [Contents](#table-of-contents "Table of Contents") 
| [Overview](#quick-overview "Quick Overview") 
| [Editions](#available-editions "Available Editions") 
| [Installation](#installation-and-setup "Installation and Setup") 
| [Specification](#detailed-specification "Detailed Specification") 
| [License](#copyright-and-license "Copyright and License") |

---
# Table of Contents

* [Welcome to *scribo*](#welcome-to-scribo "Welcome to *scribo*")
* [Table of Contents](#table-of-contents "Table of Contents")
* [Quick Overview](#quick-overview "Quick Overview")
* [Available Editions](#available-editions "Available Editions")
* [Installation and Setup](#installation-and-setup "Installation and Setup")
* [Detailed Specification](#detailed-specification "Detailed Specification")
  * <sub>[How to Use](#how-to-use "How to Use")</sub>
    * <sub>[Use Outline](#use-outline "Use Outline")</sub>
    * <sub>[Logging Setup](#logging-setup "Logging Setup")</sub>
    * <sub>[Logging Statements](#logging-statements "Logging Statements")</sub>
  * <sub>[How to Configure](#how-to-configure "How to Configure")</sub>
    * <sub>[Compile Time](#compile-time "Compile Time")</sub>
      * <sub>[Compile-Time Configuration Outline](#compile-time-configuration-outline "Compile-Time Configuration Outline")</sub>
      * <sub>[Disable all *scribo* logging](#disable-all-scribo-logging "Disable all *scribo* logging")</sub>
      * <sub>[Disable *scribo* logging for a category](#disable-scribo-logging-for-a-category "Disable *scribo* logging for a category")</sub>
      * <sub>[Disable *scribo* logging for a verbosity](#disable-scribo-logging-for-a-verbosity "Disable *scribo* logging for a verbosity")</sub>
      * <sub>[Enable *scribo* logging for a combination of a category and a verbosity](#enable-scribo-logging-for-a-combination-of-a-category-and-a-verbosity "Enable *scribo* logging for a combination of a category and a verbosity")</sub>
      * <sub>[Suppress parts of *scribo* log message header](#suppress-parts-of-scribo-log-message-header "Suppress parts of *scribo* log message header")</sub>
      * <sub>[Suppress auto-filling of *scribo* log message text](#suppress-auto-filling-of-scribo-log-message-text "Suppress auto-filling of *scribo* log message text")</sub>
      * <sub>[Suppress *scribo* log message termination and flushing](#suppress-scribo-log-message-termination-and-flushing "Suppress *scribo* log message termination and flushing")</sub>
      * <sub>[Provide custom sink for and specify maximum length of *scribo* log messages](#provide-custom-sink-for-and-specify-maximum-length-of-scribo-log-messages "Provide custom sink for and specify maximum length of *scribo* log messages")</sub>
* [Copyright and License](#copyright-and-license "Copyright and License")

---
# Quick Overview

*scribo* is simple and flexible logging system suitable for embedded C and C++ applications.

Each *scribo* log message is characterized by its (optional) category and (optional) verbosity. To generate message 
text itself, *scribo* uses the same style as printf function i.e. `format, ...` with two additions. The first addition 
is that the `format` may be omitted. In this case, only log message header (optionally followed by default message text) 
is output. The second addition is that newline (`'\n'`) is automatically appended at the end of each log message. 
**Category** is user-defined per-source-file (i.e. per translation a.k.a. compilation unit) string (see 
[Specification](#detailed-specification) below for precise definition). It is optional and, when not defined, the 
default category `GENERIC` is used. There are eight levels of **verbosity** (from the least to the most verbose): 
`FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, `METHOD`, and `TRACE`. Verbosity is also optional and, when not 
specified, the default `TRACE` verbosity is used.

Below is a simple example of basic *scribo* usage.

**First** add logging to your source code:
```c
// foo.c

#define SCRIBO_CATEGORY FOOER
#include <scribo.h>

void doFoo()
{
    SCRIBO(LOG, "Executing doFoo()");     // Enabled in both production and development builds (see scribo.cfg below)
    for (int i = 0; i < 4; i++)
    {
        SCRIBO(DEBUG, "Iteration %d", i); // Disabled in production (verbosity >= debug) (see scribo.cfg below)
    }
}
```

```c
// bar.c

#include <scribo.h>

void doBar()
{
    SCRIBO(LOG, "Executing doBar()");     // Disabled in production (category == generic) (see scribo.cfg below)
}
```

**Then** specify target configuration:
```c
// scribo.cfg

#if defined(PRODUCTION) || !defined(DEVELOPMENT)
    // Production (disable excessive logging)
#   define SCRIBO_DISABLE_CATEGORY_GENERIC 1    // No logging for unspecified category
#   define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // No logging for debugging or more verbose
#else
    // Development (enable all logging)
#endif
```

**Then** build targets:
```
gcc -o app_dev  -D DEVELOPMENT *.c
gcc -o app_prod -D PRODUCTION  *.c
```

**Finally** execute application:
```
app_dev
  2015-06-11 20:45:23 #0000000000 FOOER   LOG     : Executing doFoo()
  2015-06-11 20:45:23 #0000000001 FOOER   DEBUG   : Iteration 0
  2015-06-11 20:45:23 #0000000002 FOOER   DEBUG   : Iteration 1
  2015-06-11 20:45:23 #0000000003 FOOER   DEBUG   : Iteration 2
  2015-06-11 20:45:23 #0000000004 FOOER   DEBUG   : Iteration 3
  2015-06-11 20:45:24 #0000000005 GENERIC LOG     : Executing doBar()

app_prod
  2015-06-11 20:45:23 #0000000000 FOOER   LOG     : Executing doFoo()
```

---
# Available Editions

*scribo* is available in two editions: **compile time** (`ct`) and **light edition** (`le`). *scribo ct* provides 
numerous configuration options that can be used to customize *scribo* log message generation (see 
[Specification](#detailed-specification) below for full details). *scribo le* is a cut-down edition that supports 
essential configuration options only.

Feature | *scribo le* | *scribo ct* | Notes
:--|:--:|:--:|:--
<sub>Default category</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>`GENERIC`</sub>
<sub>Default verbosity</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>`TRACE`</sub>
<sub>Message header - timestamp</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>**2015-11-13 21:35:16** #0000000075 QUX     DEBUG   : Eureka</sub>
<sub>Message header - counter</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 **#0000000075** QUX     DEBUG   : Eureka</sub>
<sub>Message header - category</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 #0000000075 **QUX**     DEBUG   : Eureka</sub>
<sub>Message header - verbosity</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 #0000000075 QUX     **DEBUG**   : Eureka</sub>
<sub>Message text - auto-fill</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>See [Specification](#detailed-specification)</sub>
<sub>Custom message sink</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>void **callback**(const char*)</sub>
<sub>Implementation - scribo.h</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>-</sub>
<sub>Implementation - scribo.c</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>-</sub>

---
# Installation and Setup

First, download the latest *scribo* release (either `.zip` or `.tar.gz`), unpack the downloaded file, and choose one of 
the available editions of *scribo* (either `ct` or `le`) to use.

Then, add *scribo* header (`scribo.h`), configuration (`scribo.cfg`), and, if any, implementation (`scribo.c`) files 
(from `include` and `source` directories of the chosen *scribo* edition respectively) to your project. Either copy the 
files to your project directories or add *scribo*'s `include` and `source` locations to your project settings.

Finally, customize the provided configuration file according to your needs. Note that alternatively, *scribo* can also 
be configured via command-line toolchain options.

---
# Detailed Specification

## How to Use

### Use Outline

In each source file where run-time logging is needed: first (optionally) define logging category and include *scribo* 
header, and then add logging statements as illustrated below.

Example (minimalistic):
```c
#include <scribo.h>
int main(int argc, char* argv[])
{
    SCRIBO();
    return 0;
}
```
In this case *scribo* will use default category `GENERIC` and default verbosity `TRACE`, and it generate default message 
text. Log message similar to `2015-05-31 16:22:39 #0000000000 GENERIC TRACE   : "App.c" : 4` will be output.

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
Here *scribo* will output log message similar to 
`2015-05-31 16:23:47 #0000000000 APP     LOG     : Executable App.exe (1 parameters)`.

### Logging Setup

First specify (optional) logging category and include `scribo.h` in your source file(s).

Category can be specified as follows:
```c
#define SCRIBO_CATEGORY <category>
```
where `<category>` must a valid preprocessor token, more specifically a valid identifier (`[_a-zA-Z][_a-zA-Z0-9]*`).

Example:
```c
#define SCRIBO_CATEGORY APP
#include <scribo.h>
```

Category is specified per source file, more precisely per translation (a.k.a. compilation) unit. So every unit can have 
its own individual category, or multiple units can use the same shared category.

If you don't specify category, then `GENERIC` will be used as the default category.

### Logging Statements

Then output log message(s) using:
```c
SCRIBO(<verbosity>, "...", ...);
```
where `<verbosity>` is one of predefined verbosities and `"...", ...` is printf-style format and arguments.

`<verbosity>` can be one of the following predefined values (ordered from the least to the most verbose):
- `FATAL` ... fatal unrecoverable error message
- `ERROR` ... recoverable error message
- `WARNING` ... warning message
- `LOG` ... operations log message
- `INFO` ... information message
- `DEBUG` ... detailed debug message
- `METHOD` ... method entry/exit message
- `TRACE` ... code filename and line trace message

Above, following each verbosity value, is its intended usage.

If you don't specify  verbosity, then `TRACE` will be used as the default verbosity.

The maximum number of arguments following the format is **limited** by *scribo* to twenty (20).

Unlike printf, *scribo* does **not** require format (and arguments). If format is not specified, then *scribo* by 
default auto-fills message text with predefined value or it leaves the text blank and outputs log message header only. 
Auto-filling message text is useful particularly for `METHOD` and `TRACE` verbosities because *scribo* can automatically 
inject the current function name or filename and line number respectively.

Following is a list of predefined values used to auto-fill log message text for each verbosity value:
- `Game over!` for `FATAL`
- `D'oh!` for `ERROR`
- `Oops` for `WARNING`
- `Fiat lux` for `LOG`
- `Et cetera` for `INFO`
- `Eureka` for `DEBUG`
- `<__func__>` for `METHOD`
- `"<__FILE__>" : <__LINE__>` for `TRACE`

where `<__func__>`, `<__FILE__>`, and `<__LINE__>` are standard preprocessor macros (angle brackets `< >` are used to 
denote each macro).

Note that *scribo* by default automatically appends newline (`'\n'`) at the end of each and every log message. This 
feature can be disabled.

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

Abbreviated form of *scribo* logging can also have its message text auto-filled.  Hence conveniently, 
`SCRIBOM();` (or `SCRIBO(METHOD);`) can be used to output log message similar to 
`2015-09-21 21:39:13 #0000000072 BAZ     METHOD  : doBaz` and `SCRIBOT();` (or `SCRIBO(TRACE);` or simply `SCRIBO();`) 
to get message like `2015-09-21 21:39:13 #0000000073 BAZ     TRACE   : "source/baz.c" : 53`.

Examples:
```c
// Auto-filled log message text or log message header only - default verbosity
SCRIBO();
// Auto-filled log message text or log message header only - normal form
SCRIBO(FATAL);
SCRIBO(ERROR);
SCRIBO(WARNING);
SCRIBO(LOG);
SCRIBO(INFO);
SCRIBO(DEBUG);
SCRIBO(METHOD);
SCRIBO(TRACE);
// Auto-filled log message text or log message header only - shorthand form
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

## How to Configure

### Compile Time

#### Compile-Time Configuration Outline

At compile time, *scribo* logging can be configured. All logging or logging for selected categories and verbosities can 
be disabled. When disabled, the logging is completely removed and has no memory or computation overhead at run time 
whatsoever. Disabled logging has **zero run-time overhead** (i.e. it uses no 
memory space and consumes no computational cycles). This allows for different types of logging to be present in the codebase on permanent basis. When building 
software, development version can have detailed logging present, while production version can be less verbose. 
Configuration of *scribo* is controlled through a set of hash-defines. The defines can be provided during build time as 
command-line toolchain option (usually either `-D <name>` or `/D <name>`), or the defines can be kept in a configuration 
file (`scribo.cfg` as `#define <name> 1`).

Note that for a *scribo* configuration option to be recognized as active, it must have value of `1`. Value `1` of an 
option is treated as "enabled", any other value (including not being defined at all) is treated as "disabled".

Examples (`scribo.cfg`):

Disable all *scribo* logging:
```c
#define SCRIBO_DISABLE_ALL 1 // Completely disable all scribo logging
```

Disable *scribo* logging for category `GENERIC`:
```c
#define SCRIBO_DISABLE_CATEGORY_GENERIC 1 // Disable scribo logging for category 'GENERIC' (all verbosities)
```

Disable *scribo* logging for verbosities `METHOD` and `TRACE`:
```c
#define SCRIBO_DISABLE_VERBOSITY_METHOD 1 // Disable scribo logging for verbosity 'METHOD' (all categories)
#define SCRIBO_DISABLE_VERBOSITY_TRACE 1 // Disable scribo logging for verbosity 'TRACE' (all categories)
```

Disable *scribo* logging for category `GENERIC` and *scribo* logging for verbosities `DEBUG`, `METHOD`, and 
`TRACE`; enable *scribo* logging for combination of category `APP` and verbosity `DEBUG`:
```c
#define SCRIBO_DISABLE_CATEGORY_GENERIC 1 // Disable scribo logging for category 'GENERIC' (all verbosities)
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable scribo logging for verbosity 'DEBUG' and more verbose i.e. 'METHOD' and 'TRACE' (all categories)
#define SCRIBO_ENABLE_CATEGORY_APP_VERBOSITY_DEBUG 1 // Enable scribo logging for combination of category 'APP' with verbosity 'DEBUG'
```

#### Disable all *scribo* logging

```c
#define SCRIBO_DISABLE_ALL 1 // Completely disable all scribo logging
```

#### Disable *scribo* logging for a category

```c
#define SCRIBO_DISABLE_CATEGORY_<category> 1 // Disable scribo logging for category <category> (all verbosities)
```
where `<category>` is the category specified in `#define SCRIBO_CATEGORY <category>`, or `GENERIC` (when category was 
not specified).

Example:
```c
#define SCRIBO_DISABLE_CATEGORY_THIS_MODULE 1 // Disable scribo logging for category 'THIS_MODULE' (all verbosities)
#define SCRIBO_DISABLE_CATEGORY_THAT_MODULE 1 // Disable scribo logging for category 'THAT_MODULE' (all verbosities)
```

#### Disable *scribo* logging for a verbosity

```c
#define SCRIBO_DISABLE_VERBOSITY_<verbosity> 1 // Disable scribo logging for verbosity <verbosity> (all categories)
```
where `<verbosity>` is one of the predefined verbosities i.e. `FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, 
`METHOD`, or `TRACE`.

Example:
```c
#define SCRIBO_DISABLE_VERBOSITY_TRACE 1 // Disable scribo logging for verbosity 'TRACE' (all categories)
```

Apart from disabling individual verbosities one by one, *scribo* provides shorthand form to disable a verbosity and all 
more verbose ones using single configuration option.

```c
#define SCRIBO_DISABLE_VERBOSITY_<verbosity>_ETC 1 // Disable scribo logging for verbosity <verbosity> and all more verbose ones (all categories)
```

Example:
```c
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable scribo logging for verbosity 'DEBUG' and all more verbose ones (i.e. 'METHOD' and 'TRACE') (all categories)
```

#### Enable *scribo* logging for a combination of a category and a verbosity

Finally, *scribo* provides configuration option to enable logging for a combination of a category and a verbosity. This 
is useful as an override together with the above two options that disable categories and verbosities.

```c
#define SCRIBO_ENABLE_CATEGORY_<category>_VERBOSITY_<verbosity> 1 // Enable scribo logging for combination of category <category> and verbosity <verbosity>
```
where `<category>` and `<verbosity>` are defined as above.

Example:
```c
#define SCRIBO_DISABLE_CATEGORY_SOME_MODULE 1 // Disable scribo logging for category 'SOME_MODULE' (all verbosities)
#define SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable scribo logging for verbosity 'DEBUG' and all more verbose ones (i.e. 'METHOD' and 'TRACE') (all categories)
#define SCRIBO_ENABLE_CATEGORY_SOME_MODULE_VERBOSITY_DEBUG 1 // Enable scribo logging for combination of category 'SOME_MODULE' and verbosity 'DEBUG'
```

Note that the order in which various categories and verbosities are disabled, and combinations thereof enabled, is not 
significant and does not need to follow a particular order.

#### Suppress parts of *scribo* log message header

Usual *scribo* log message consists of a standard header followed by custom generated text. The **header** is made of 
`timestamp`, message `counter`, `category`, `verbosity`, and separator. The **text** is generated in printf-like 
fashion. Individual parts of the log message header can be suppressed. When all parts of the header are suppressed, then 
the separator between header and text is also suppressed, automatically.
```c
#define SCRIBO_SUPPRESS_TIMESTAMP 1 // Suppress 'timestamp' in scribo log message header
#define SCRIBO_SUPPRESS_COUNTER   1 // Suppress message 'counter' in scribo log message header
#define SCRIBO_SUPPRESS_CATEGORY  1 // Suppress message 'category' in scribo log message header
#define SCRIBO_SUPPRESS_VERBOSITY 1 // Suppress message 'verbosity' in scribo log message header
```

Examples:
```
Normal scribo log message
  => 2015-05-31 16:23:47 #0000000000 APP     LOG     : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_TIMESTAMP 1
  => #0000000000 APP     LOG     : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_COUNTER   1
  => 2015-05-31 16:23:47 APP     LOG     : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_CATEGORY  1
  => 2015-05-31 16:23:47 #0000000000 LOG     : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_VERBOSITY 1
  => 2015-05-31 16:23:47 #0000000000 APP     : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_COUNTER   1
#define SCRIBO_SUPPRESS_CATEGORY  1
#define SCRIBO_SUPPRESS_VERBOSITY 1
  => 2015-05-31 16:23:47 : Executable Scribo.exe (1 parameters)
#define SCRIBO_SUPPRESS_TIMESTAMP 1
#define SCRIBO_SUPPRESS_COUNTER   1
#define SCRIBO_SUPPRESS_CATEGORY  1
#define SCRIBO_SUPPRESS_VERBOSITY 1
  => Executable Scribo.exe (1 parameters)
```

#### Suppress auto-filling of *scribo* log message text

When text of *scribo* log message in not specified, *scribo* by default auto-fills it with predefined value. This 
functionality can be disabled. When no message text is specified and auto-fill is disabled, only message header is 
output.
```c
#define SCRIBO_SUPPRESS_AUTO_FILL  1 // Suppress 'auto-fill' of message text
```

#### Suppress *scribo* log message termination and flushing

Each *scribo* log message is automatically appended with newline (`'\n'`). It is then output to standard output stream 
(`stdout`) and the stream is flushed to ensure all *scribo* logging is available in the event that the system crashes. 
Both automatic appending of the newline and automatic stream flushing can be suppressed.
```c
#define SCRIBO_SUPPRESS_NEWLINE 1 // Suppress appending 'newline'
#define SCRIBO_SUPPRESS_FLUSH   1 // Suppress 'flushing' stream
```

#### Provide custom sink for and specify maximum length of *scribo* log messages

By default, *scribo* log messages are output to `stdout` using `printf` function. In this case, length of each message 
is not limited and messages can be flushed using `fflush`. Optionally, custom sink function can be provided. The 
function receives one parameter - formatted text of the *scribo* log message to be output. The sink function has no 
return value. Its signature is `void callback(const char*)`. When custom *scribo* log message sink is provided, length 
of each message can be limited to a maximum length (`>=1`), be unlimited (`0`), or be left unspecified in which case it 
is also not limited. When custom sink is provided, messages are not flushed.  Flushing, if desired, becomes 
responsibility of the custom callback function.
```c
#define SCRIBO_INVOKE_CALLBACK <void function(const char*)> // Provide custom sink for scribo log messages
#define SCRIBO_SET_MAX_LENGTH  <maximum log message length> // Specify maximum length of scribo log messages
```

---
# Copyright and License

Copyright (c) 2015 Petr Vepřek

MIT License, see [`LICENSE`](./LICENSE) for further details.
