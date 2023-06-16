#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

/* Zephyr includes */
#include <zephyr/shell/shell.h>

/* Standard includes */
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

enum app_config_mode {
	APP_CONFIG_MODE_NONE = 0,
	APP_CONFIG_MODE_LTE = 1,
	APP_CONFIG_MODE_LRW = 2,
};

struct app_config {
	enum app_config_mode mode;

	int interval_sample;
	int interval_report;

#if defined(CONFIG_SHIELD_CTR_Z)
	int event_report_delay;
	int event_report_rate;
	bool backup_report_connected;
	bool backup_report_disconnected;
#endif /* defined(CONFIG_SHIELD_CTR_Z) */
};

extern struct app_config g_app_config;

int app_config_cmd_config_show(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_mode(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_interval_sample(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_interval_report(const struct shell *shell, size_t argc, char **argv);

#if defined(CONFIG_SHIELD_CTR_Z)
int app_config_cmd_config_event_report_delay(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_event_report_rate(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_backup_report_connected(const struct shell *shell, size_t argc,
						  char **argv);
int app_config_cmd_config_backup_report_disconnected(const struct shell *shell, size_t argc,
						     char **argv);
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#ifdef __cplusplus
}
#endif

#endif /* APP_CONFIG_H_ */
