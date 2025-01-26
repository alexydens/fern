/* Include guard */
#if !defined(LOGGING_H)
#define LOGGING_H

/* Includes */
#include <base.h>

/* Macros */
/* Assertion */
#define ASSERT(expr) {\
  if (!expr) {\
    log_msg(LOG_LEVEL_ERROR, "Assertion \"%s\" failed.", #expr);\
    abort();\
  }\
}
/* Assertion with message */
#define ASSERT_MSG(expr, msg) {\
  if (!expr) {\
    log_msg(LOG_LEVEL_ERROR, "Assertion \"%s\" failed (%s)", #expr, msg);\
    abort();\
  }\
}
/* Assertion using errno */
#define ASSERT_STDLIB(expr) {\
  if (!expr) {\
    __assert_stdlib_fail(#expr);\
  }\
}
extern void __assert_stdlib_fail(const char *msg);

/* Log levels */
typedef enum {
  LOG_LEVEL_SUCCESS,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR
} log_level_t;

/* Initialize logging */
extern void log_init(void);
/* Quit logging */
extern void log_quit(void);

/* Log a message */
extern void log_msg(log_level_t level, const char *msg, ...)
  __attribute__((format(printf, 2, 3)));

#endif /* LOGGING_H */
