/* Implements logging.h */
#include <logging.h>
#include <settings.h>

/* Stdlib stuff */
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>

/* Consts */
const char *log_levels[] = {
  "SUCCESS",
  "INFO",
  "WARNING",
  "ERROR"
};
const char *log_levels_color[] = {
  "\x1b[1;32mSUCCESS\x1b[0m",
  "\x1b[1;34mINFO\x1b[0m",
  "\x1b[1;33mWARNING\x1b[0m",
  "\x1b[1;31mERROR\x1b[0m"
};

/* State */
static FILE *log_file = NULL;

/* Assertion using errno */
extern void __assert_stdlib_fail(const char *msg) {
  log_msg(
      LOG_LEVEL_ERROR,
      "Assertion \"%s\" failed (%s)", msg, strerror(errno)
  );
  abort();
}

/* Initialize logging */
void log_init(void) {
  if (settings.logging_target == LOG_TARGET_FILE) {
    time_t t;
    struct tm tm;
    char filename[32];
    char path[128];

    t = time(NULL);
    tm = *localtime(&t);
    memset(filename, 0, sizeof(filename));
    strftime(filename, sizeof(filename), "%m-%d-%y_%X.log", &tm);
    
    memset(path, 0, sizeof(path));
    snprintf(path, sizeof(path), "%s/log/%s", settings.misc_root_path, filename);
    if (log_file) fclose(log_file);
    log_file = fopen(path, "w");
    if (log_file) {
      log_msg(LOG_LEVEL_SUCCESS, "Logging to file %s", path);
    }
  }
}
/* Quit logging */
void log_quit(void) {
  if (log_file) fclose(log_file);
}

/* Log a message */
void log_msg(log_level_t level, const char *msg, ...) {
  va_list args;
  va_start(args, msg);
  switch (settings.logging_target) {
    case LOG_TARGET_FILE:
      if (settings.logging_colors)
        fprintf(log_file, "[%s]: ", log_levels_color[level]);
      else
        fprintf(log_file, "[%s]: ", log_levels[level]);
      vfprintf(log_file, msg, args);
      fprintf(log_file, "\n");
      break;
    case LOG_TARGET_STDOUT:
      if (settings.logging_colors)
        fprintf(stdout, "[%s]: ", log_levels_color[level]);
      else
        fprintf(stdout, "[%s]: ", log_levels[level]);
      vfprintf(stdout, msg, args);
      fprintf(stdout, "\n");
      break;
    case LOG_TARGET_STDERR:
      if (settings.logging_colors)
        fprintf(stderr, "[%s]: ", log_levels_color[level]);
      else
        fprintf(stderr, "[%s]: ", log_levels[level]);
      vfprintf(stderr, msg, args);
      fprintf(stderr, "\n");
      break;
    case LOG_TARGET_NONE:
      break;
  }
  va_end(args);
}
