/* Implements logging.h */
#include <logging.h>
#include <stdarg.h>

/* Consts */
/* Logging level strings */
#if defined(USE_LOG_COLORS)
const char *log_levels[] = {
  "[\x1b[32;1mSUCCESS\x1b[0m]: ",
  "[\x1b[34;1mINFO\x1b[0m]: ",
  "[\x1b[33;1mWARNING\x1b[0m]: ",
  "[\x1b[31;1mERROR\x1b[0m]: "
};
#else
const char *log_levels[] = {
  "[SUCCESS]: ",
  "[INFO]: ",
  "[WARNING]: ",
  "[ERROR]: "
};
#endif

/* Log something to stderr */
void log_msg(log_level_t level, const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  fprintf(stderr, "%s", log_levels[level]);
  vfprintf(stderr, fmt, args);
  fprintf(stderr, "\n");
  va_end(args);
}
