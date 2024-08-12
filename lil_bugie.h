#ifndef LIL_BUGIE_H
#define LIL_BUGIE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum BugieLogLevel
{
    BUGIE_TRACE,
    BUGIE_DEBUG,
    BUGIE_INFO,
    BUGIE_WARN,
    BUGIE_ERROR,
    BUGIE_SUCCESS,
    BUGIE_DEFAULT = BUGIE_TRACE
} BugieLogLevel;

static const char * const BUGIE_LOG_CODE[6] =
{
    "\033[90m", // BUGIE_TRACE - GRAY
    "\033[36m", // BUGIE_DEBUG - CYAN
    "\033[34m", // BUGIE_INFO - BLUE
    "\033[33m", // BUGIE_WARN - YELLOW
    "\033[31m", // BUGIE_ERROR - RED
    "\033[32m", // BUGIE_SUCCESS - GREEN
};

static const char * const BUGIE_LOG_MODE[6] =
{
    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "SUCCESS",
}; 

#define BUGIE_LOG_FORMAT "[%s%s%s][%s%s%s%s] %s%s%s: %s%s%s%s\n"
#define BUGIE_LOG_TIMESTAMP_SIZE 100

#define BUGIE_LOG_DEFAULT_STREAM stdout
#define BUGIE_LOG_DEFAULT_MODE "TRACE"
#define BUGIE_LOG_DEFAULT_TIMESTAMP_FORMAT "%H:%M:%S"

#define BUGIE_LOG_TRACE(stream, context, message) bugieLog(BUGIE_TRACE, stream, context, message, NULL, NULL)
#define BUGIE_LOG_DEBUG(stream, context, message) bugieLog(BUGIE_DEBUG, stream, context, message, NULL, NULL)
#define BUGIE_LOG_INFO(stream, context, message) bugieLog(BUGIE_INFO, stream, context, message, NULL, NULL)
#define BUGIE_LOG_WARN(stream, context, message) bugieLog(BUGIE_WARN, stream, context, message, NULL, NULL)
#define BUGIE_LOG_ERROR(stream, context, message) bugieLog(BUGIE_ERROR, stream, context, message, NULL, NULL)
#define BUGIE_LOG_SUCCESS(stream, context, message) bugieLog(BUGIE_SUCCESS, stream, context, message, NULL, NULL)


/**
 * @brief Logs a message with a specified log level, context, and timestamp.
 *
 * This function outputs a formatted log message to a specified output stream
 * or to the default stream (`stdout`) if no stream is provided. The log message
 * includes a timestamp, a mode (such as TRACE, DEBUG, INFO, etc.), the context
 * of the message, and the message itself. Each log level is associated with a
 * specific color for easy identification in the output.
 *
 * @param level The log level of the message (e.g., BUGIE_TRACE, BUGIE_DEBUG, BUGIE_INFO).
 *              If an invalid level is provided, it defaults to BUGIE_TRACE.
 * @param stream The output stream where the log will be written. If NULL, the log will be 
 *               written to `stdout`.
 * @param context A string that provides context for the log message (e.g., the function or 
 *                module where the log is being generated).
 * @param message The actual log message to be output.
 * @param mode A custom mode string to be displayed in the log (e.g., "INFO"). If NULL, the 
 *             mode corresponding to the `level` will be used.
 * @param timestamp_format The format for the timestamp in the log message. If NULL, the 
 *                         default format "%H:%M:%S" will be used.
*/
static void bugieLog(BugieLogLevel level, FILE * stream, const char * context, const char * message, char * mode, char * timestamp_format)
{
    #define ANSI_RESET "\033[0m"
    #define ANSI_BOLD "\033[1m"
    
    switch (level)
    {
        case BUGIE_TRACE:
        case BUGIE_DEBUG:
        case BUGIE_INFO:
        case BUGIE_WARN:
        case BUGIE_ERROR:
        case BUGIE_SUCCESS:
        break;
        default: level = BUGIE_TRACE;
    }
    
    char timestamp[BUGIE_LOG_TIMESTAMP_SIZE];
    time_t now = time(NULL);
    struct tm * time_info = localtime(&now);
    
    if (timestamp_format)
    {
        (void) strftime(timestamp, BUGIE_LOG_TIMESTAMP_SIZE, timestamp_format, time_info);
    }
    else
    {
        (void) strftime(timestamp, BUGIE_LOG_TIMESTAMP_SIZE, BUGIE_LOG_DEFAULT_TIMESTAMP_FORMAT, time_info);
    }
    
    if (!mode)
    {
        mode = (char *) BUGIE_LOG_MODE[level];
    }
    
    (void) fprintf(
        (stream) ? stream : BUGIE_LOG_DEFAULT_STREAM, BUGIE_LOG_FORMAT,
        (char *) BUGIE_LOG_CODE[level], timestamp, ANSI_RESET, // timestamp
        ANSI_BOLD, (char *) BUGIE_LOG_CODE[level], mode, ANSI_RESET, // mode
        (char *) BUGIE_LOG_CODE[BUGIE_DEFAULT], context, ANSI_RESET, // context
        ANSI_BOLD, (char *) BUGIE_LOG_CODE[level], message, ANSI_RESET // message
    );
    
    #undef ANSI_RESET
    #undef ANSI_BOLD
}

#endif // LIL_BUGIE_H
