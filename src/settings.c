/* Implements settings.h */
#include <settings.h>
#include <logging.h>

/* Default settings */
settings_t settings = {
  .misc.root_path = DEFAULT_MISC_ROOT_PATH,
  .logging.target = DEFAULT_LOGGING_TARGET,
  .logging.colors = DEFAULT_LOGGING_COLORS
};

/* Load settings from file */
void settings_load(void);
/* Save settings to file */
void settings_save(void);
