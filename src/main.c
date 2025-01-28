/* Includes */
#include <base.h>
#include <logging.h>
#include <settings.h>

/* Entry point */
int main(void) {
  log_init();
  settings_load();

  log_msg(LOG_LEVEL_INFO, "Testing...");

  settings_save();
  log_quit();
  return 0;
}
