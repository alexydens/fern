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
  struct {
    const char *root_path;
  } misc;
  struct {
    enum {
      LOG_TARGET_FILE,
      LOG_TARGET_STDOUT,
      LOG_TARGET_STDERR,
      LOG_TARGET_NONE
    } target;
    bool colors;
  } logging;
} settings_t;
extern settings_t settings;

/* Load settings from file */
extern void settings_load(void);
/* Save settings to file */
extern void settings_save(void);

#endif /* SETTINGS_H */
