// ---------------------------------------------------------------------------------------------------------------------
// Copyright (c) 2015 Petr Vepřek
// File: scribo.h
// ---------------------------------------------------------------------------------------------------------------------

#pragma once

#include <scribo.cfg>

// Detect macro conflict
#if defined(SCRIBO)
#   error "Macro SCRIBO is already defined!"
#endif

// Interpret configuration shorthand
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_FATAL
#       undef SCRIBO_DISABLE_VERBOSITY_FATAL
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_FATAL 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_ERROR
#       undef SCRIBO_DISABLE_VERBOSITY_ERROR
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_ERROR 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_WARNING
#       undef SCRIBO_DISABLE_VERBOSITY_WARNING
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_WARNING 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_LOG
#       undef SCRIBO_DISABLE_VERBOSITY_LOG
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_LOG 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_INFO
#       undef SCRIBO_DISABLE_VERBOSITY_INFO
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_INFO 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_DEBUG
#       undef SCRIBO_DISABLE_VERBOSITY_DEBUG
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_DEBUG 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_METHOD_ETC  == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_METHOD
#       undef SCRIBO_DISABLE_VERBOSITY_METHOD
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_METHOD 1
#endif
#if          (SCRIBO_DISABLE_VERBOSITY_FATAL_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_ERROR_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_WARNING_ETC == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_LOG_ETC     == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_INFO_ETC    == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_DEBUG_ETC   == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_METHOD_ETC  == 1) || \
             (SCRIBO_DISABLE_VERBOSITY_TRACE_ETC   == 1)
#   ifdef     SCRIBO_DISABLE_VERBOSITY_TRACE
#       undef SCRIBO_DISABLE_VERBOSITY_TRACE
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_TRACE 1
#endif

// Interpret usage shorthand
#define SCRIBOF(...) SCRIBO(FATAL,   __VA_ARGS__)
#define SCRIBOE(...) SCRIBO(ERROR,   __VA_ARGS__)
#define SCRIBOW(...) SCRIBO(WARNING, __VA_ARGS__)
#define SCRIBOL(...) SCRIBO(LOG,     __VA_ARGS__)
#define SCRIBOI(...) SCRIBO(INFO,    __VA_ARGS__)
#define SCRIBOD(...) SCRIBO(DEBUG,   __VA_ARGS__)
#define SCRIBOM(...) SCRIBO(METHOD,  __VA_ARGS__)
#define SCRIBOT(...) SCRIBO(TRACE,   __VA_ARGS__)

// Initialize default category
#ifndef    SCRIBO_CATEGORY
#	define SCRIBO_CATEGORY GENERIC
#endif

// Configure disabling current category
#define SCRIBO__GET_CATEGORY_DISABLED_LOOKUP(CATEGORY) SCRIBO_DISABLE_CATEGORY_ ## CATEGORY
#define SCRIBO__GET_CATEGORY_DISABLED(       CATEGORY) SCRIBO__GET_CATEGORY_DISABLED_LOOKUP(CATEGORY)
#if SCRIBO__GET_CATEGORY_DISABLED(SCRIBO_CATEGORY) == 1
#	define SCRIBO__DISABLE_CATEGORY 1
#else
#	define SCRIBO__DISABLE_CATEGORY 0
#endif

// Configure disabling known verbosities
#if           SCRIBO_DISABLE_VERBOSITY_FATAL != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_FATAL
#       undef SCRIBO_DISABLE_VERBOSITY_FATAL
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_FATAL 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_ERROR != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_ERROR
#       undef SCRIBO_DISABLE_VERBOSITY_ERROR
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_ERROR 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_WARNING != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_WARNING
#       undef SCRIBO_DISABLE_VERBOSITY_WARNING
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_WARNING 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_LOG != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_LOG
#       undef SCRIBO_DISABLE_VERBOSITY_LOG
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_LOG 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_INFO != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_INFO
#       undef SCRIBO_DISABLE_VERBOSITY_INFO
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_INFO 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_DEBUG != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_DEBUG
#       undef SCRIBO_DISABLE_VERBOSITY_DEBUG
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_DEBUG 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_METHOD != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_METHOD
#       undef SCRIBO_DISABLE_VERBOSITY_METHOD
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_METHOD 0
#endif
#if           SCRIBO_DISABLE_VERBOSITY_TRACE != 1
#   ifdef     SCRIBO_DISABLE_VERBOSITY_TRACE
#       undef SCRIBO_DISABLE_VERBOSITY_TRACE
#   endif
#   define    SCRIBO_DISABLE_VERBOSITY_TRACE 0
#endif

// Configure enabling combinations of current category & known verbosity
#define SCRIBO__GET_COMBO_ENABLED_LOOKUP(CATEGORY, VERBOSITY) SCRIBO_ENABLE_CATEGORY_ ## CATEGORY ## _ ## VERBOSITY
#define SCRIBO__GET_COMBO_ENABLED(       CATEGORY, VERBOSITY) SCRIBO__GET_COMBO_ENABLED_LOOKUP(CATEGORY, VERBOSITY_ ## VERBOSITY)
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, FATAL) == 1
#   define SCRIBO__ENABLE_COMBO_FATAL 1
#else
#   define SCRIBO__ENABLE_COMBO_FATAL 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, ERROR) == 1
#   define SCRIBO__ENABLE_COMBO_ERROR 1
#else
#   define SCRIBO__ENABLE_COMBO_ERROR 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, WARNING) == 1
#   define SCRIBO__ENABLE_COMBO_WARNING 1
#else
#   define SCRIBO__ENABLE_COMBO_WARNING 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, LOG) == 1
#   define SCRIBO__ENABLE_COMBO_LOG 1
#else
#   define SCRIBO__ENABLE_COMBO_LOG 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, INFO) == 1
#   define SCRIBO__ENABLE_COMBO_INFO 1
#else
#   define SCRIBO__ENABLE_COMBO_INFO 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, DEBUG) == 1
#   define SCRIBO__ENABLE_COMBO_DEBUG 1
#else
#   define SCRIBO__ENABLE_COMBO_DEBUG 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, METHOD) == 1
#   define SCRIBO__ENABLE_COMBO_METHOD 1
#else
#   define SCRIBO__ENABLE_COMBO_METHOD 0
#endif
#if SCRIBO__GET_COMBO_ENABLED(SCRIBO_CATEGORY, TRACE) == 1
#   define SCRIBO__ENABLE_COMBO_TRACE 1
#else
#   define SCRIBO__ENABLE_COMBO_TRACE 0
#endif

// Process scribo
#if SCRIBO_DISABLE_ALL == 1
    // Remove scribo
#   define SCRIBO(...)
#else
    // Prepare scribo
#   define SCRIBO__EXPAND_ARGUMENTS(ARGUMENTS) ARGUMENTS
#   define SCRIBO__PICK_21ST(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, ...) _21
#   define SCRIBO(...)                                                                                               SCRIBO__EXPAND_ARGUMENTS(SCRIBO__PICK_21ST(__VA_ARGS__,  SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, \
                                                                                                                                                                SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, SCRIBO__SOME, \
                                                                                                                                                                SCRIBO__NONE, _)(__VA_ARGS__))
#   define SCRIBO__NONE(                                                                             VERBOSITY)      SCRIBO__INJECT_CONFIGURATION(SCRIBO__DISABLE_CATEGORY, SCRIBO_DISABLE_VERBOSITY_ ## VERBOSITY, SCRIBO__ENABLE_COMBO_ ## VERBOSITY, SCRIBO_CATEGORY, #VERBOSITY, "")
#   define SCRIBO__SOME(                                                                             VERBOSITY, ...) SCRIBO__INJECT_CONFIGURATION(SCRIBO__DISABLE_CATEGORY, SCRIBO_DISABLE_VERBOSITY_ ## VERBOSITY, SCRIBO__ENABLE_COMBO_ ## VERBOSITY, SCRIBO_CATEGORY, #VERBOSITY, __VA_ARGS__)
#   define SCRIBO__INJECT_CONFIGURATION(DISABLE_CATEGORY, DISABLE_VERBOSITY, ENABLE_COMBO, CATEGORY, VERBOSITY, ...) SCRIBO__LOOKUP_CONFIGURATION(        DISABLE_CATEGORY,                      DISABLE_VERBOSITY,                       ENABLE_COMBO,        CATEGORY,  VERBOSITY, __VA_ARGS__)
#   define SCRIBO__LOOKUP_CONFIGURATION(DISABLE_CATEGORY, DISABLE_VERBOSITY, ENABLE_COMBO, CATEGORY, VERBOSITY, ...) SCRIBO__CONFIGURATION_ ## DISABLE_CATEGORY ## _ ## DISABLE_VERBOSITY ## _ ## ENABLE_COMBO(                                               #CATEGORY,  VERBOSITY, __VA_ARGS__)
    // Enable or disable scribo
#   define SCRIBO__CONFIGURATION_1_0_0(...) // Category disabled, no combo override
#   define SCRIBO__CONFIGURATION_0_1_0(...) // Verbosity disabled, no combo override
#   define SCRIBO__CONFIGURATION_1_1_0(...) // Category and verbosity disabled, no combo override
#   define SCRIBO__CONFIGURATION_0_0_0(CATEGORY, VERBOSITY, ...) SCRIBO__THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURATION_0_0_1(CATEGORY, VERBOSITY, ...) SCRIBO__THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURATION_1_0_1(CATEGORY, VERBOSITY, ...) SCRIBO__THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURATION_0_1_1(CATEGORY, VERBOSITY, ...) SCRIBO__THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
#   define SCRIBO__CONFIGURATION_1_1_1(CATEGORY, VERBOSITY, ...) SCRIBO__THIS(CATEGORY, VERBOSITY, __VA_ARGS__)
    // Implement scribo
#   include <stdio.h>
#   if SCRIBO_SUPPRESS_TIMESTAMP != 1
#       include <time.h>
#       define SCRIBO__DECLARE_RAW time_t raw
#       define SCRIBO__DECLARE_NOW struct tm now
#       define SCRIBO__GET_RAW time(&raw)
#       if defined(__linux__)
#           define SCRIBO__GET_NOW localtime_r(&raw, &now)
#       elif defined(_MSC_VER)
#           define SCRIBO__GET_NOW localtime_s(&now, &raw)
#       else
#           define SCRIBO__GET_NOW now = *localtime(&raw)
#       endif
#       define SCRIBO__TIMESTAMP_FORMAT "%04d-%02d-%02d %02d:%02d:%02d "
#       define SCRIBO__TIMESTAMP_VALUE  now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec,
#   else
#       define SCRIBO__DECLARE_RAW
#       define SCRIBO__DECLARE_NOW
#       define SCRIBO__GET_RAW
#       define SCRIBO__GET_NOW
#       define SCRIBO__TIMESTAMP_FORMAT
#       define SCRIBO__TIMESTAMP_VALUE
#   endif
#   if SCRIBO_SUPPRESS_COUNTER != 1
        extern unsigned long scribo__count;
#       define SCRIBO__COUNTER_FORMAT    "#%010d "
#       define SCRIBO__COUNTER_VALUE     scribo__count,
#       define SCRIBO__INCREMENT_COUNTER scribo__count++
#   else
#       define SCRIBO__COUNTER_FORMAT
#       define SCRIBO__COUNTER_VALUE
#       define SCRIBO__INCREMENT_COUNTER
#   endif
#   if SCRIBO_SUPPRESS_CATEGORY != 1
#       define SCRIBO__CATEGORY_FORMAT "%-7.7s "
#   else
#       define SCRIBO__CATEGORY_FORMAT "%.0s"
#   endif
#   if SCRIBO_SUPPRESS_VERBOSITY != 1
#       define SCRIBO__VERBOSITY_FORMAT "%-7.7s "
#   else
#       define SCRIBO__VERBOSITY_FORMAT "%.0s"
#   endif
#   if (SCRIBO_SUPPRESS_TIMESTAMP != 1) || \
       (SCRIBO_SUPPRESS_COUNTER != 1) || \
       (SCRIBO_SUPPRESS_CATEGORY != 1) || \
       (SCRIBO_SUPPRESS_VERBOSITY != 1)
#       define SCRIBO__SEPARATOR ": "
#   else
#       define SCRIBO__SEPARATOR
#   endif
#   if SCRIBO_SUPPRESS_NEWLINE != 1
#       define SCRIBO__NEWLINE "\n"
#   else
#       define SCRIBO__NEWLINE
#   endif
#   ifdef SCRIBO_INVOKE_CALLBACK
#       include <stdarg.h>
#       ifndef SCRIBO_SET_MAX_LENGTH
#           define SCRIBO_SET_MAX_LENGTH 128
#       endif
#       define SCRIBO__DECLARE_TEXT char text[SCRIBO_SET_MAX_LENGTH + 1]
        static void scribo__make_message(char* text, size_t size, const char* format, ...)
        {
            va_list args1;
            va_start(args1, format);
            va_list args2;
            va_copy(args2, args1);
            //    char buf[1+vsnprintf(NULL, 0, fmt, args1)];
            va_end(args1);
            //    vsnprintf(buf, sizeof buf, fmt, args2);
            vsnprintf(text, size, format, args2);
            va_end(args2);
        }
#       define SCRIBO__DO_OUTPUT(...) scribo__make_message(text, sizeof text, __VA_ARGS__); SCRIBO_INVOKE_CALLBACK(text);
#       define SCRIBO__DO_FLUSH
#   else
#       define SCRIBO__DECLARE_TEXT
#       define SCRIBO__DO_OUTPUT printf
#       if SCRIBO_SUPPRESS_FLUSH != 1
#           define SCRIBO__DO_FLUSH fflush(stdout)
#       else
#           define SCRIBO__DO_FLUSH
#   endif
#   endif
#   define SCRIBO__THIS(      CATEGORY, VERBOSITY,         ...) SCRIBO__EXPAND_ARGUMENTS(SCRIBO__THIS_DUMMY(CATEGORY, VERBOSITY, __VA_ARGS__, ""))
#   define SCRIBO__THIS_DUMMY(CATEGORY, VERBOSITY, FORMAT, ...) \
        do { \
            SCRIBO__DECLARE_RAW; \
            SCRIBO__DECLARE_NOW; \
            SCRIBO__GET_RAW; \
            SCRIBO__GET_NOW; \
            SCRIBO__DECLARE_TEXT; \
            SCRIBO__DO_OUTPUT(SCRIBO__TIMESTAMP_FORMAT SCRIBO__COUNTER_FORMAT SCRIBO__CATEGORY_FORMAT SCRIBO__VERBOSITY_FORMAT SCRIBO__SEPARATOR FORMAT "%s" SCRIBO__NEWLINE, \
                              SCRIBO__TIMESTAMP_VALUE  SCRIBO__COUNTER_VALUE          CATEGORY,               VERBOSITY,                         __VA_ARGS__); \
            SCRIBO__DO_FLUSH; \
            SCRIBO__INCREMENT_COUNTER; \
        } while (0)
#endif
/*
prn(fmt,...)

char buf[max+1]
vsn(buf,max+1,fmt,...)
cb(buf)

X(...)    X -> vsn(buf,max+1,varg); cb(buf);

	int n = vsnprintf(NULL, 0, format, ap);
	if (unlikely(n < 0))
		return;
	char msg[n + 1];
	if (unlikely(vsnprintf(msg, n + 1, format, ap) != n))
		return;
*/
/*
max len 0 ==> unlimited
move helper function to .c
should always have newline, even if rest is trimmed
*/
/*
readme: added 2x defs;  if cb then no flush;  if cb then len maxed (default 128) else no max
change: add note
*/

// End of file ---------------------------------------------------------------------------------------------------------