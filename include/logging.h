/* Include guard */
#if !defined(LOGGING_H)
#define LOGGING_H

/* Includes */
#include <base.h>

/* Macros */
/* Assertion */
#define ASSERT(expr) do {\
  if (!(expr)) {\
    log_msg(LOG_LEVEL_ERROR, "Assertion \"%s\" failed\n", #expr);\
    abort();\
  }\
} while (0)
/* Assertion with message */
#define ASSERT_MSG(expr, msg) do {\
  if (!(expr)) {\
    log_msg(LOG_LEVEL_ERROR, "Assertion \"%s\" failed: %s\n", #expr, msg);\
    abort();\
  }\
} while (0)
/* Assertion with errno */
#define ASSERT_ERRNO(expr) do {\
  if (!(expr)) {\
    log_msg(\
        LOG_LEVEL_ERROR,\
        "Assertion \"%s\" failed: %s\n",\
        strerror(errno),\
        #expr\
    );\
    abort();\
  }\
} while (0)

/* Enumerations */
/* Logging levels */
typedef enum {
  LOG_LEVEL_SUCCESS,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR
} log_level_t;

/* Log something to stderr */
extern void log_msg(log_level_t level, const char *fmt, ...)
  __attribute__((format(printf, 2, 3)));

#endif /* LOGGING_H */
