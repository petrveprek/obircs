# Welcome to *obircs*

__*obircs*__ /'skri:.bo:/ Latin *verb* write; compose

*obircs* -- simple and flexible logging system suitable for embedded C and C++ applications.

| [Welcome](#welcome-to-obircs "Welcome to *obircs*") 
| [Contents](#table-of-contents "Table of Contents") 
| [Overview](#quick-overview "Quick Overview") 
| [Editions](#available-editions "Available Editions") 
| [Installation](#installation-and-setup "Installation and Setup") 
| [Specification](#detailed-specification "Detailed Specification") 
| [License](#copyright-and-license "Copyright and License") |

---
# Table of Contents

* [Welcome to *obircs*](#welcome-to-obircs "Welcome to *obircs*")
* [Table of Contents](#table-of-contents "Table of Contents")
* [Quick Overview](#quick-overview "Quick Overview")
* [Available Editions](#available-editions "Available Editions")
* [Installation and Setup](#installation-and-setup "Installation and Setup")
* [Detailed Specification](#detailed-specification "Detailed Specification")
  * <sub>[How to Use](#how-to-use "How to Use")</sub>
    * <sub>[Use Outline](#use-outline "Use Outline")</sub>
    * <sub>[Logging Setup](#logging-setup "Logging Setup")</sub>
    * <sub>[Logging Statements](#logging-statements "Logging Statements")</sub>
    * <sub>[Conditional Code Execution](#conditional-code-execution "Conditional Code Execution")</sub>
    * <sub>[Conditional Logging Statements](#conditional-logging-statements "Conditional Logging Statements")</sub>
  * <sub>[How to Configure](#how-to-configure "How to Configure")</sub>
    * <sub>[Compile Time](#compile-time "Compile Time")</sub>
      * <sub>[Compile-Time Configuration Outline](#compile-time-configuration-outline "Compile-Time Configuration Outline")</sub>
      * <sub>[Disable All *obircs* Logging](#disable-all-obircs-logging "Disable All *obircs* Logging")</sub>
      * <sub>[Disable *obircs* Logging for a Category](#disable-obircs-logging-for-a-category "Disable *obircs* Logging for a Category")</sub>
      * <sub>[Disable *obircs* Logging for a Verbosity](#disable-obircs-logging-for-a-verbosity "Disable *obircs* Logging for a Verbosity")</sub>
      * <sub>[Enable *obircs* Logging for a Combination of a Category and a Verbosity](#enable-obircs-logging-for-a-combination-of-a-category-and-a-verbosity "Enable *obircs* Logging for a Combination of a Category and a Verbosity")</sub>
      * <sub>[Suppress Parts of *obircs* Log Message Header](#suppress-parts-of-obircs-log-message-header "Suppress Parts of *obircs* Log Message Header")</sub>
      * <sub>[Suppress Auto-Filling of *obircs* Log Message Text](#suppress-auto-filling-of-obircs-log-message-text "Suppress Auto-Filling of *obircs* Log Message text")</sub>
      * <sub>[Suppress *obircs* Log Message Termination and Flushing](#suppress-obircs-log-message-termination-and-flushing "Suppress *obircs* Log Message Termination and Flushing")</sub>
      * <sub>[Provide Custom Sink for and Specify Maximum Length of *obircs* Log Messages](#provide-custom-sink-for-and-specify-maximum-length-of-obircs-log-messages "Provide Custom Sink for and Specify Maximum Length of *obircs* Log Messages")</sub>
      * <sub>[Note on Conditional Code Execution](#note-on-conditional-code-execution "Note on Conditional Code Execution")</sub>
      * <sub>[Note on Conditional Logging Statements](#note-on-conditional-logging-statements "Note on Conditional Logging Statements")</sub>
      * <sub>[Recap of Default Values](#recap-of-default-values "Recap of Default Values")</sub>
* [Copyright and License](#copyright-and-license "Copyright and License")

---
# Quick Overview

*obircs* is simple and flexible logging system suitable for embedded C and C++ applications.

Each *obircs* log message is characterized by its (optional) category and (optional) verbosity. To generate message 
text itself, *obircs* uses the same style as printf function i.e. `format, ...` with two additions. The first addition 
is that the `format` may be omitted. In this case, only log message header (optionally followed by default message text) 
is output. The second addition is that newline (`'\n'`) is automatically appended at the end of each log message. 
**Category** is user-defined per-source-file (i.e. per translation a.k.a. compilation unit) string (see 
[Specification](#detailed-specification) below for precise definition). It is optional and, when not defined, the 
default category `GENERIC` is used. There are eight levels of **verbosity** (from the least to the most verbose): 
`FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, `METHOD`, and `TRACE`. Verbosity is also optional and, when not 
specified, the default `TRACE` verbosity is used.

Below is a simple example of basic *obircs* usage.

**First** add logging to your source code:
```c
// foo.c

#define OBIRCS_CATEGORY FOOER
#include <obircs.h>

void doFoo()
{
    OBIRCS(LOG, "Executing doFoo()");     // Enabled in both production and development builds (see obircs.cfg below)
    for (int i = 0; i < 4; i++)
    {
        OBIRCS(DEBUG, "Iteration %d", i); // Disabled in production (verbosity >= debug) (see obircs.cfg below)
    }
}
```

```c
// bar.c

#include <obircs.h>

void doBar()
{
    OBIRCS(LOG, "Executing doBar()");     // Disabled in production (category == generic) (see obircs.cfg below)
}
```

**Then** specify target configuration:
```c
// obircs.cfg

#if defined(PRODUCTION) || !defined(DEVELOPMENT)
    // Production (disable excessive logging)
#   define OBIRCS_DISABLE_CATEGORY_GENERIC 1    // No logging for unspecified category
#   define OBIRCS_DISABLE_VERBOSITY_DEBUG_ETC 1 // No logging for debugging or more verbose
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

*obircs* is available in two editions: **compile time** (`ct`) and **light edition** (`le`). *obircs ct* provides 
numerous configuration options that can be used to customize *obircs* log message generation (see 
[Specification](#detailed-specification) below for full details). *obircs le* is a cut-down edition that supports 
essential configuration options only.

Comparison of *obircs* editions:

Feature | *obircs le* | *obircs ct* | Notes
:--|:--:|:--:|:--
<sub>Default category</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>`GENERIC`</sub>
<sub>Default verbosity</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>`TRACE`</sub>
<sub>Message header - timestamp</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>**2015-11-13 21:35:16** #0000000075 QUX     DEBUG   : Eureka</sub>
<sub>Message header - counter</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 **#0000000075** QUX     DEBUG   : Eureka</sub>
<sub>Message header - category</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 #0000000075 **QUX**     DEBUG   : Eureka</sub>
<sub>Message header - verbosity</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>2015-11-13 21:35:16 #0000000075 QUX     **DEBUG**   : Eureka</sub>
<sub>Message text - auto-fill</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>See [Specification](#detailed-specification)</sub>
<sub>Custom message sink</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>void **callback**(const char*)</sub>
<sub>Implementation - obircs.h</sub> | <sub>Yes</sub> | <sub>Yes</sub> | <sub>-</sub>
<sub>Implementation - obircs.c</sub> | <sub>No</sub> | <sub>Yes</sub> | <sub>-</sub>

---
# Installation and Setup

First, download the latest *obircs* release (either `.zip` or `.tar.gz`), unpack the downloaded file, and choose one of 
the available editions of *obircs* (either `ct` or `le`) to use.

Then, add *obircs* header (`obircs.h`), configuration (`obircs.cfg`), and, if any, implementation (`obircs.c`) files 
(from `include` and `source` directories of the chosen *obircs* edition respectively) to your project. Either copy the 
files to your project directories or add *obircs*'s `include` and `source` locations to your project settings.

Finally, customize the provided configuration file according to your needs. Note that alternatively, *obircs* can also 
be configured via command-line toolchain options.

---
# Detailed Specification

## How to Use

### Use Outline

In each source file where run-time logging is needed: first (optionally) define logging category and include *obircs* 
header, and then add logging statements as illustrated below.

Example (minimalistic):
```c
#include <obircs.h>
int main(int argc, char* argv[])
{
    OBIRCS();
    return 0;
}
```
In this case *obircs* will use default category `GENERIC` and default verbosity `TRACE`, and it generate default message 
text. Log message similar to `2015-05-31 16:22:39 #0000000000 GENERIC TRACE   : "App.c" : 4` will be output.

Example (realistic):
```c
#define OBIRCS_CATEGORY APP
#include <obircs.h>
int main(int argc, char* argv[])
{
    OBIRCS(LOG, "Executable %s (%d parameters)", argv[0], argc);
    return 0;
}
```
Here *obircs* will output log message similar to 
`2015-05-31 16:23:47 #0000000000 APP     LOG     : Executable App.exe (1 parameters)`.

### Logging Setup

First specify (optional) logging category (`OBIRCS_CATEGORY`) and include `obircs.h` in your source file(s).

Category can be specified as follows:
```c
#define OBIRCS_CATEGORY <category>
```
where `<category>` must a valid preprocessor token, more specifically a valid identifier (`[_a-zA-Z][_a-zA-Z0-9]*`).

Example:
```c
#define OBIRCS_CATEGORY APP
#include <obircs.h>
```

Category is specified per source file, more precisely per translation (a.k.a. compilation) unit. So every unit can have 
its own individual category, or multiple units can use the same shared category.

If you don't specify category, then `GENERIC` will be used as the default category.

### Logging Statements

Then output log messages using:
```c
OBIRCS(<verbosity>, "...", ...);
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

The maximum number of arguments following the format is **limited** by *obircs* to twenty (20).

Unlike printf, *obircs* does **not** require format (and arguments). If format is not specified, then *obircs* by 
default auto-fills message text with predefined value or it leaves the text blank and outputs log message header only. 
Auto-filling message text is useful particularly for `METHOD` and `TRACE` verbosities because *obircs* can automatically 
inject the current function name or filename and line number respectively.

Following is a list of predefined values used to auto-fill log message text for each verbosity value:
- `GAME OVER!` for `FATAL`
- `D'oh!` for `ERROR`
- `Oops` for `WARNING`
- `Fiat lux` for `LOG`
- `Et cetera` for `INFO`
- `Eureka` for `DEBUG`
- `<__func__>` for `METHOD`
- `"<__FILE__>" : <__LINE__>` for `TRACE`

where `<__func__>`, `<__FILE__>`, and `<__LINE__>` are standard preprocessor macros (angle brackets `< >` are used to 
denote each macro).

Note that *obircs* by default automatically appends newline (`'\n'`) at the end of each and every log message. This 
feature can be disabled.

Format of *obircs* logging can be abbreviated to:
```c
OBIRCS<v>("...", ...);
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

Abbreviated form of *obircs* logging can also have its message text auto-filled.  Hence conveniently, 
`OBIRCSM();` (or `OBIRCS(METHOD);`) can be used to output a log message similar to 
`2015-09-21 21:39:13 #0000000072 BAZ     METHOD  : doBaz` and `OBIRCST();` (or `OBIRCS(TRACE);` or simply `OBIRCS();`) 
to get a message like `2015-09-21 21:39:13 #0000000073 BAZ     TRACE   : "source/baz.c" : 53`.

Examples:
```c
// Auto-filled log message text or log message header only - default verbosity
OBIRCS();
// Auto-filled log message text or log message header only - normal form
OBIRCS(FATAL);
OBIRCS(ERROR);
OBIRCS(WARNING);
OBIRCS(LOG);
OBIRCS(INFO);
OBIRCS(DEBUG);
OBIRCS(METHOD);
OBIRCS(TRACE);
// Auto-filled log message text or log message header only - shorthand form
OBIRCSF();
OBIRCSE();
OBIRCSW();
OBIRCSL();
OBIRCSI();
OBIRCSD();
OBIRCSM();
OBIRCST();
// Log message with format - normal form
OBIRCS(FATAL, "Hello");
OBIRCS(ERROR, "Hello");
OBIRCS(WARNING, "Hello");
OBIRCS(LOG, "Hello");
OBIRCS(INFO, "Hello");
OBIRCS(DEBUG, "Hello");
OBIRCS(METHOD, "Hello");
OBIRCS(TRACE, "Hello");
// Log message with format - shorthand form
OBIRCSF("Hello");
OBIRCSE("Hello");
OBIRCSW("Hello");
OBIRCSL("Hello");
OBIRCSI("Hello");
OBIRCSD("Hello");
OBIRCSM("Hello");
OBIRCST("Hello");
// Log message with format and arguments - normal form
OBIRCS(FATAL, "%d + %d equals %d", 1, 1, 2);
OBIRCS(ERROR, "%d + %d equals %d", 1, 1, 2);
OBIRCS(WARNING, "%d + %d equals %d", 1, 1, 2);
OBIRCS(LOG, "%d + %d equals %d", 1, 1, 2);
OBIRCS(INFO, "%d + %d equals %d", 1, 1, 2);
OBIRCS(DEBUG, "%d + %d equals %d", 1, 1, 2);
OBIRCS(METHOD, "%d + %d equals %d", 1, 1, 2);
OBIRCS(TRACE, "%d + %d equals %d", 1, 1, 2);
// Log message with format and arguments - shorthand form
OBIRCSF("%d + %d equals %d", 1, 1, 2);
OBIRCSE("%d + %d equals %d", 1, 1, 2);
OBIRCSW("%d + %d equals %d", 1, 1, 2);
OBIRCSL("%d + %d equals %d", 1, 1, 2);
OBIRCSI("%d + %d equals %d", 1, 1, 2);
OBIRCSD("%d + %d equals %d", 1, 1, 2);
OBIRCSM("%d + %d equals %d", 1, 1, 2);
OBIRCST("%d + %d equals %d", 1, 1, 2);
```

### Conditional Code Execution

`OBIRCS` can be used to log values of expressions (including variables and function calls).
However, sometimes it is necessary to output these values from within a loop.
Other times, data computation prior to logging is needed.
`EXEQUI` can be used to conditionally execute statements needed for the logging as follows.

Conditional code execution:
```c
EXEQUI(<verbosity>, ...);
```
and
```c
EXEQUI<v>(...);
```
where `<verbosity>` and `<v>` specify the verbosity as described earlier and `...` is zero or more statements.

Statements `...` are placed within brackets `{` `}` and thus have their own local scope. Any variable declared within an 
`EXEQUI` is **not** visible outside of it.

Example:
```c
void process(int* data, unsigned count)
{
    EXEQUI(LOG,
        unsigned i;
        int hash = 0;
        for (i = 0; i < count; i++)
        {
            OBIRCS(DEBUG, "data[%d] = %d", i, data[i]);
            hash ^= data[i];
        }
        OBIRCS(LOG, "data[] xor checksum = %d", hash);
    );
    // ...
}
```

### Conditional Logging Statements

`IF_OBIRCS` can be used to log values of expressions (including variables and function calls) not all the time but only
when a certain condition is met.

Conditional logging statements:
```c
IF_OBIRCS(<condition>, <verbosity>, "...", ...);
```
and
```c
IF_OBIRCS<v>(<condition>, "...", ...);
```
where `<condition>` is a boolean expression, `<verbosity>` and `<v>` specify the verbosity as described earlier and
`"...", ...` is printf-style format and arguments. *obircs*-style log message is output only when expression
`<condition>` evaluates to "true" (i.e. a non-zero value).

Example:
```c
IF_OBIRCS(errorCode != 0, ERROR, "Error: code = %d", errorCode);
IF_OBIRCSE(errorCode != 0, "Error: code = %d", errorCode);
```

## How to Configure

### Compile Time

#### Compile-Time Configuration Outline

At compile time, *obircs* logging can be configured. All logging or logging for selected categories and verbosities can 
be disabled. When disabled, the logging is completely removed (by the preprocessor) and has **zero run-time overhead** 
(i.e. it uses no memory space and consumes no computational cycles). This allows for different types of logging to be 
present in the codebase on permanent basis. When building software, development version can have detailed logging 
present, while production version can be less verbose. Configuration of *obircs* is controlled through a set of 
hash-defines. The defines can be provided during build time as command-line toolchain option (usually either `-D <name>` 
or `/D <name>`), or the defines can be kept in a configuration file (`obircs.cfg` as `#define <name> 1`).

Note that for a *obircs* configuration option to be recognized as active, it must have value of `1`. Value `1` of an 
option is treated as "enabled", any other value (including not being defined at all) is treated as "disabled".

Examples (`obircs.cfg`):

Disable all *obircs* logging:
```c
#define OBIRCS_DISABLE_ALL 1 // Completely disable all obircs logging
```

Disable *obircs* logging for category `GENERIC`:
```c
#define OBIRCS_DISABLE_CATEGORY_GENERIC 1 // Disable obircs logging for category 'GENERIC' (all verbosities)
```

Disable *obircs* logging for verbosities `METHOD` and `TRACE`:
```c
#define OBIRCS_DISABLE_VERBOSITY_METHOD 1 // Disable obircs logging for verbosity 'METHOD' (all categories)
#define OBIRCS_DISABLE_VERBOSITY_TRACE 1 // Disable obircs logging for verbosity 'TRACE' (all categories)
```

Disable *obircs* logging for category `GENERIC` and *obircs* logging for verbosities `DEBUG`, `METHOD`, and 
`TRACE`; enable *obircs* logging for combination of category `APP` and verbosity `DEBUG`:
```c
#define OBIRCS_DISABLE_CATEGORY_GENERIC 1 // Disable obircs logging for category 'GENERIC' (all verbosities)
#define OBIRCS_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable obircs logging for verbosity 'DEBUG' and more verbose i.e. 'METHOD' and 'TRACE' (all categories)
#define OBIRCS_ENABLE_CATEGORY_APP_VERBOSITY_DEBUG 1 // Enable obircs logging for combination of category 'APP' with verbosity 'DEBUG'
```

#### Disable All *obircs* Logging

```c
#define OBIRCS_DISABLE_ALL 1 // Completely disable all obircs logging
```

#### Disable *obircs* Logging for a Category

```c
#define OBIRCS_DISABLE_CATEGORY_<category> 1 // Disable obircs logging for category <category> (all verbosities)
```
where `<category>` is the category specified in `#define OBIRCS_CATEGORY <category>`, or `GENERIC` (when category was 
not specified).

Example:
```c
#define OBIRCS_DISABLE_CATEGORY_THIS_MODULE 1 // Disable obircs logging for category 'THIS_MODULE' (all verbosities)
#define OBIRCS_DISABLE_CATEGORY_THAT_MODULE 1 // Disable obircs logging for category 'THAT_MODULE' (all verbosities)
```

#### Disable *obircs* Logging for a Verbosity

```c
#define OBIRCS_DISABLE_VERBOSITY_<verbosity> 1 // Disable obircs logging for verbosity <verbosity> (all categories)
```
where `<verbosity>` is one of the predefined verbosities i.e. `FATAL`, `ERROR`, `WARNING`, `LOG`, `INFO`, `DEBUG`, 
`METHOD`, or `TRACE`.

Example:
```c
#define OBIRCS_DISABLE_VERBOSITY_TRACE 1 // Disable obircs logging for verbosity 'TRACE' (all categories)
```

Apart from disabling individual verbosities one by one, *obircs* provides shorthand form to disable a verbosity and all 
more verbose ones using single configuration option.

```c
#define OBIRCS_DISABLE_VERBOSITY_<verbosity>_ETC 1 // Disable obircs logging for verbosity <verbosity> and all more verbose ones (all categories)
```

Example:
```c
#define OBIRCS_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable obircs logging for verbosity 'DEBUG' and all more verbose ones (i.e. 'METHOD' and 'TRACE') (all categories)
```

#### Enable *obircs* Logging for a Combination of a Category and a Verbosity

Finally, *obircs* provides configuration option to enable logging for a combination of a category and a verbosity. This 
is useful as an override together with the above two options that disable categories and verbosities.

```c
#define OBIRCS_ENABLE_CATEGORY_<category>_VERBOSITY_<verbosity> 1 // Enable obircs logging for combination of category <category> and verbosity <verbosity>
```
where `<category>` and `<verbosity>` are defined as above.

Example:
```c
#define OBIRCS_DISABLE_CATEGORY_SOME_MODULE 1 // Disable obircs logging for category 'SOME_MODULE' (all verbosities)
#define OBIRCS_DISABLE_VERBOSITY_DEBUG_ETC 1 // Disable obircs logging for verbosity 'DEBUG' and all more verbose ones (i.e. 'METHOD' and 'TRACE') (all categories)
#define OBIRCS_ENABLE_CATEGORY_SOME_MODULE_VERBOSITY_DEBUG 1 // Enable obircs logging for combination of category 'SOME_MODULE' and verbosity 'DEBUG'
```

Note that the order in which various categories and verbosities are disabled, and combinations thereof enabled, is not 
significant and does not need to follow a particular order.

#### Suppress Parts of *obircs* Log Message Header

Usual *obircs* log message consists of a standard header followed by custom generated text. The **header** is made of 
`timestamp`, message `counter`, `category`, `verbosity`, and separator. The **text** is generated in printf-like 
fashion. The entire log message header or its individual parts can be suppressed. When all parts of the header are
suppressed, then the separator between header and text is also suppressed, automatically.
```c
#define OBIRCS_SUPPRESS_HEADER 1 // Suppress the entire log message header

#define OBIRCS_SUPPRESS_TIMESTAMP 1 // Suppress 'timestamp' in obircs log message header
#define OBIRCS_SUPPRESS_COUNTER   1 // Suppress message 'counter' in obircs log message header
#define OBIRCS_SUPPRESS_CATEGORY  1 // Suppress message 'category' in obircs log message header
#define OBIRCS_SUPPRESS_VERBOSITY 1 // Suppress message 'verbosity' in obircs log message header
```

Examples:
```
Normal obircs log message
  => 2015-05-31 16:23:47 #0000000000 APP     LOG     : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_TIMESTAMP 1
  => #0000000000 APP     LOG     : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_COUNTER   1
  => 2015-05-31 16:23:47 APP     LOG     : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_CATEGORY  1
  => 2015-05-31 16:23:47 #0000000000 LOG     : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_VERBOSITY 1
  => 2015-05-31 16:23:47 #0000000000 APP     : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_COUNTER   1
#define OBIRCS_SUPPRESS_CATEGORY  1
#define OBIRCS_SUPPRESS_VERBOSITY 1
  => 2015-05-31 16:23:47 : Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_TIMESTAMP 1
#define OBIRCS_SUPPRESS_COUNTER   1
#define OBIRCS_SUPPRESS_CATEGORY  1
#define OBIRCS_SUPPRESS_VERBOSITY 1
  => Executable obircS.exe (1 parameters)

#define OBIRCS_SUPPRESS_HEADER 1
  => Executable obircS.exe (1 parameters)
```

#### Suppress Auto-Filling of *obircs* Log Message Text

When text of *obircs* log message in not specified, *obircs* by default auto-fills it with predefined value. This 
functionality can be disabled. When no message text is specified and auto-fill is disabled, only message header is 
output.
```c
#define OBIRCS_SUPPRESS_AUTO_FILL  1 // Suppress 'auto-fill' of message text
```

#### Suppress *obircs* Log Message Termination and Flushing

Each *obircs* log message is automatically appended with newline (`'\n'`). It is then output to standard output stream 
(`stdout`) and the stream is flushed to ensure all *obircs* logging is available in the event of a system crash. Both 
automatic appending of the newline and automatic stream flushing can be suppressed.
```c
#define OBIRCS_SUPPRESS_NEWLINE 1 // Suppress appending 'newline'
#define OBIRCS_SUPPRESS_FLUSH   1 // Suppress 'flushing' stream
```

#### Provide Custom Sink for and Specify Maximum Length of *obircs* Log Messages

By default, *obircs* log messages are output to `stdout` using `printf` function. In this case, length of each message 
is not limited and messages (unless suppressed) are flushed using `fflush`. Optionally, custom sink function can be 
provided. The function receives one parameter - formatted text of the *obircs* log message to be output. The sink 
function has no return value. Its signature is `void callback(const char*)`. When custom *obircs* log message sink is 
provided, length of each message can be limited to a maximum length (`>=1`), be unlimited (`0`), or be left unspecified 
in which case it is also not limited. When custom sink is provided, messages are not flushed.  Flushing, if desired, 
becomes responsibility of the custom callback function.
```c
#define OBIRCS_INVOKE_CALLBACK <void function(const char*)> // Provide custom sink for obircs log messages
#define OBIRCS_SET_MAX_LENGTH  <maximum log message length> // Specify maximum length of obircs log messages
```

#### Note on Conditional Code Execution

Conditional code execution (`EXEQUI`) does not have its own configuration settings. Rather, it follows configuration of 
log messages (`OBIRCS`). Conditional code execution can be enabled or disabled based on category, verbosity... together 
with log messages for the same category, verbosity etc.

#### Note on Conditional Logging Statements

Conditional logging statements (`IF_OBIRCS`) do not have their own configuration settings. Rather, they follow
configuration of unconditional logging statements (`OBIRCS`). Conditional logging statements can be enabled or disabled
based on category, verbosity... together with log messages for the same category, verbosity etc.

#### Recap of Default Values

```
OBIRCS()    --> <category> = GENERIRC, <verbosity> = TRACE                       --> Log message
EXEQUI()    --> <category> = GENERIRC, <verbosity> = TRACE, <condition> = "true" --> No operation
IF_OBIRCS() --> <category> = GENERIRC, <verbosity> = TRACE, <condition> = "true" --> Log message
```

---
# Copyright and License

Copyright (c) 2015, 2017 Petr Vepřek

MIT License, see [`LICENSE`](./LICENSE) for further details.
