/* Implements settings.h */
#include <settings.h>
#include <logging.h>

/* Consts */
#define SETTINGS_FILE_NAME "settings.dat"

/* Default settings */
settings_t settings = {
  .misc.root_path = DEFAULT_MISC_ROOT_PATH,
  .logging.target = DEFAULT_LOGGING_TARGET,
  .logging.colors = DEFAULT_LOGGING_COLORS
};

void settings_load(void) {
  log_msg(LOG_LEVEL_WARNING, "settings_load() not implemented");
}
void settings_save(void) {
  log_msg(LOG_LEVEL_WARNING, "settings_save() not implemented");
}

#if 0
#include <unistd.h>
#include <stdio.h>
/* Load settings from file */
void settings_load(void) {
  char path[128];
  FILE *f = NULL;
  /* Get settings path */
  memset(path, 0, sizeof(path));
  snprintf(
      path, sizeof(path),
      "%s/%s",
      settings.misc.root_path, SETTINGS_FILE_NAME
  );
  /* Check if file exists and is readable and writable */
  if (access(path, F_OK | R_OK | W_OK)) {
    /* Create default one */
    log_msg(
        LOG_LEVEL_WARNING,
        "No settings file found, creating with default settings"
    );
    settings_save();
  }
  /* Open file */
  log_msg(LOG_LEVEL_INFO, "Loading settings from %s", path);
  f = fopen(path, "r");
  ASSERT_STDLIB(f);
  /* Read settings */
  ASSERT_STDLIB(fread(&settings, sizeof(settings), 1, f));
  /* Close file */
  fclose(f);
}
/* Save settings to file */
void settings_save(void) {
  char path[128];
  FILE *f = NULL;
  /* Get settings path */
  memset(path, 0, sizeof(path));
  snprintf(
      path, sizeof(path),
      "%s/%s",
      settings.misc.root_path, SETTINGS_FILE_NAME
  );
  /* Open file */
  log_msg(LOG_LEVEL_INFO, "Saving settings to %s", path);
  f = fopen(path, "w");
  ASSERT_STDLIB(f);
  /* Write settings */
  ASSERT_STDLIB(fwrite(&settings, sizeof(settings), 1, f));
  /* Close file */
  fclose(f);
}
#endif
