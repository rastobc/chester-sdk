/*
 * Copyright (c) 2023 HARDWARIO a.s.
 *
 * SPDX-License-Identifier: LicenseRef-HARDWARIO-5-Clause
 */

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

#define APP_CONFIG_CHANNEL_COUNT 4

#define APP_CONFIG_INTERVAL_REPORT_MIN 30
#define APP_CONFIG_INTERVAL_REPORT_MAX 86400

#if defined(CONFIG_SHIELD_CTR_K1)
int app_config_cmd_config_channel_active(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_channel_differential(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_channel_calib_x0(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_channel_calib_y0(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_channel_calib_x1(const struct shell *shell, size_t argc, char **argv);
int app_config_cmd_config_channel_calib_y1(const struct shell *shell, size_t argc, char **argv);
int h_rev_commit(void);
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

struct app_config {
	int interval_sample;
	int interval_aggreg;
	int interval_report;

#if defined(CONFIG_SHIELD_CTR_Z)
	int event_report_delay;
	int event_report_rate;
	bool backup_report_connected;
	bool backup_report_disconnected;
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#if defined(CONFIG_SHIELD_CTR_K1)
	int channel_interval_sample;
	int channel_interval_aggreg;
	bool channel_active[APP_CONFIG_CHANNEL_COUNT];
	bool channel_differential[APP_CONFIG_CHANNEL_COUNT];
	int channel_calib_x0[APP_CONFIG_CHANNEL_COUNT];
	int channel_calib_y0[APP_CONFIG_CHANNEL_COUNT];
	int channel_calib_x1[APP_CONFIG_CHANNEL_COUNT];
	int channel_calib_y1[APP_CONFIG_CHANNEL_COUNT];
	int channel_calib_a1;
	int channel_calib_a10;
	int channel_calib_v5;
	int channel_calib_v24;
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

#if defined(CONFIG_SHIELD_CTR_DS18B20)
	int w1_therm_interval_sample;
	int w1_therm_interval_aggreg;
#endif /* defined(CONFIG_SHIELD_CTR_DS18B20) */
};

extern struct app_config g_app_config;

/* clang-format off */

#define CONFIG_PARAM_LIST_COMMON() \
	CONFIG_PARAM_INT(interval-sample, interval_sample, 1, 86400, "Get/Set sample interval in seconds (format: <1-86400>).") \
	CONFIG_PARAM_INT(interval-aggreg, interval_aggreg, 1, 86400, "Get/Set aggregate interval in seconds (format: <1-86400>).") \
	CONFIG_PARAM_INT(interval-report, interval_report, 30, 86400, "Get/Set report interval in seconds (format: <30-86400>).")

#if defined(CONFIG_SHIELD_CTR_Z)
	#define CONFIG_PARAM_LIST_CTR_Z() \
		CONFIG_PARAM_INT(event-report-delay, event_report_delay, 1, 86400, "Get/Set event report delay in seconds (format: <1-86400>).") \
		CONFIG_PARAM_INT(event-report-rate, event_report_rate, 1, 3600, "Get/Set event report rate in reports per hour (format: <1-3600>).") \
		CONFIG_PARAM_BOOL(backup-report-connected, backup_report_connected, "Get/Set report when backup is active (format: true, false).") \
		CONFIG_PARAM_BOOL(backup-report-disconnected, backup_report_disconnected, "Get/Set report when backup is inactive (format: true, false).")
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#if defined(CONFIG_SHIELD_CTR_K1)
	#define CONFIG_PARAM_LIST_CTR_K1() \
		CONFIG_PARAM_INT(channel-interval-sample, channel_interval_sample, 1, 86400, "Get/Set sample interval in seconds (format: <1-86400>).") \
		CONFIG_PARAM_INT(channel-interval-aggreg, channel_interval_aggreg, 1, 86400, "Get/Set aggregate interval in seconds (format: <1-86400>).") \
		CONFIG_PARAM_INT(channel-calib-a1, channel_calib_a1, 0, 1, "Get/Set channel auto calibration for 1 Amp (format: 0-1).") \
		CONFIG_PARAM_INT(channel-calib-a10, channel_calib_a10, 0, 1, "Get/Set channel auto calibration for 10 Amp (format: 0-1).") \
		CONFIG_PARAM_INT(channel-calib-v5, channel_calib_v5, 0, 1, "Get/Set channel auto calibration for 5 Volt (format: 0-1).") \
		CONFIG_PARAM_INT(channel-calib-v24, channel_calib_v24, 0, 1, "Get/Set channel auto calibration for 24 Volt (format: 0-1).")
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

#if defined(CONFIG_SHIELD_CTR_DS18B20)
	#define CONFIG_PARAM_LIST_CTR_DS18B20() \
		CONFIG_PARAM_INT(w1-therm-interval-sample, w1_therm_interval_sample, 1, 86400, "Get/Set 1-Wire temperature sample interval in seconds (format: <1-86400>).") \
		CONFIG_PARAM_INT(w1-therm-interval-aggreg, w1_therm_interval_aggreg, 1, 86400, "Get/Set 1-Wire temperature aggregate interval in seconds (format: <1-86400>).")
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

/* clang-format on */

#define CONFIG_PARAM_LIST() CONFIG_PARAM_LIST_COMMON()

int app_config_cmd_config_show(const struct shell *shell, size_t argc, char **argv);

#define CONFIG_PARAM_INT(_name_d, _name_u, _min, _max, _help)                                      \
	int app_config_cmd_config_##_name_u(const struct shell *shell, size_t argc, char **argv);
#define CONFIG_PARAM_FLOAT(_name_d, _name_u, _min, _max, _help)                                    \
	int app_config_cmd_config_##_name_u(const struct shell *shell, size_t argc, char **argv);
#define CONFIG_PARAM_BOOL(_name_d, _name_u, _help)                                                 \
	int app_config_cmd_config_##_name_u(const struct shell *shell, size_t argc, char **argv);

CONFIG_PARAM_LIST();

#if defined(CONFIG_PARAM_LIST_CTR_Z)
CONFIG_PARAM_LIST_CTR_Z();
#endif

#if defined(CONFIG_PARAM_LIST_CTR_K1)
CONFIG_PARAM_LIST_CTR_K1();
#endif

#if defined(CONFIG_PARAM_LIST_CTR_DS18B20)
CONFIG_PARAM_LIST_CTR_DS18B20();
#endif

#undef CONFIG_PARAM_INT
#undef CONFIG_PARAM_FLOAT
#undef CONFIG_PARAM_BOOL

#ifdef __cplusplus
}
#endif

#endif /* APP_CONFIG_H_ */
