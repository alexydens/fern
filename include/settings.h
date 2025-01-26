/* Include guard */
#if !defined(SETTINGS_H)
#define SETTINGS_H

/* Include guard */
#include <base.h>

/* Default settings */
/* Misc */
//#define DEFAULT_MISC_ROOT_PATH "$HOME/.fern"
#define DEFAULT_MISC_ROOT_PATH "./data"
/* Logging */
#define DEFAULT_LOGGING_TARGET LOG_TARGET_STDOUT
#define DEFAULT_LOGGING_COLORS TRUE

/* Settings */
typedef struct {
  /* Misc */
  const char *misc_root_path;
  /* Logging */
  enum {
    LOG_TARGET_FILE,
    LOG_TARGET_STDOUT,
    LOG_TARGET_STDERR,
    LOG_TARGET_NONE
  } logging_target;
  bool logging_colors;
} settings_t;
extern settings_t settings;

#endif /* SETTINGS_H */
