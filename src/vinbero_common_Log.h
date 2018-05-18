#ifndef _VINBERO_COMMON_LOG_H
#define _VINBERO_COMMON_LOG_H

int vinbero_common_Log_raw(int level, const char* source, int line, const char* format, ...);

#define VINBERO_COMMON_LOG_LEVEL_TRACE 0
#define VINBERO_COMMON_LOG_LEVEL_DEBUG 1 
#define VINBERO_COMMON_LOG_LEVEL_INFO 2
#define VINBERO_COMMON_LOG_LEVEL_WARN 3
#define VINBERO_COMMON_LOG_LEVEL_ERROR 4
#define VINBERO_COMMON_LOG_LEVEL_FATAL 5

#define VINBERO_COMMON_LOG_TRACE(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_TRACE, __FILE__, __LINE__, __VA_ARGS__)
#define VINBERO_COMMON_LOG_DEBUG(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define VINBERO_COMMON_LOG_INFO(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define VINBERO_COMMON_LOG_WARN(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_WARN, __FILE__, __LINE__, __VA_ARGS__)
#define VINBERO_COMMON_LOG_ERROR(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define VINBERO_COMMON_LOG_FATAL(...) vinbero_common_Log_raw(VINBERO_COMMON_LOG_LEVEL_FATAL, __FILE__, __LINE__, __VA_ARGS__)

#endif