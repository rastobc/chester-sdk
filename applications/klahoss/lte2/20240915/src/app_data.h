/*
 * Copyright (c) 2023 HARDWARIO a.s.
 *
 * SPDX-License-Identifier: LicenseRef-HARDWARIO-5-Clause
 */

#ifndef APP_DATA_H_
#define APP_DATA_H_

#include "app_config.h"

/* CHESTER includes */
#include <chester/ctr_lte.h>

/* Standard includes */
#include <stdbool.h>
#include <stdint.h>

#define APP_DATA_ANALOG_MAX_SAMPLES        32
#define APP_DATA_ANALOG_MAX_MEASUREMENTS   32
#define APP_DATA_MAX_BACKUP_EVENTS         32
#define APP_DATA_MAX_TAMPER_EVENTS         32
#define APP_DATA_W1_THERM_COUNT            10
#define APP_DATA_W1_THERM_MAX_SAMPLES      32
#define APP_DATA_W1_THERM_MAX_MEASUREMENTS 32
#define APP_DATA_BUTTON_COUNT              2
#define APP_DATA_MAX_BUTTON_EVENTS         8

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_APP_TAMPER)
struct app_data_tamper_event {
	int64_t timestamp;
	bool activated;
};

struct app_data_tamper {
	bool activated;
	int event_count;
	struct app_data_tamper_event events[APP_DATA_MAX_TAMPER_EVENTS];
};
#endif /* defined(CONFIG_APP_TAMPER) */

#if defined(CONFIG_SHIELD_CTR_Z)
struct app_data_backup_event {
	int64_t timestamp;
	bool connected;
};

struct app_data_backup {
	float line_voltage;
	float battery_voltage;
	bool line_present;
	int event_count;
	struct app_data_backup_event events[APP_DATA_MAX_BACKUP_EVENTS];
};

struct app_data_button_event {
	int open;
	int close;
};

struct app_data_button {
	int64_t timestamp;

	int sample_count;
	int open_count;
	int close_count;

	int event_count;
	struct app_data_button_event events[APP_DATA_MAX_BUTTON_EVENTS];
};
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#if defined(CONFIG_SHIELD_CTR_K1)
struct app_data_analog_aggreg {
	float min;
	float max;
	float avg;
	float mdn;
};

struct app_data_channel {
	int64_t timestamp;

	int sample_count;
	float samples_mean[APP_DATA_ANALOG_MAX_SAMPLES];
	float samples_rms[APP_DATA_ANALOG_MAX_SAMPLES];

	int measurement_count;
	struct app_data_analog_aggreg measurements_mean[APP_DATA_ANALOG_MAX_MEASUREMENTS];
	struct app_data_analog_aggreg measurements_rms[APP_DATA_ANALOG_MAX_MEASUREMENTS];
};
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

#if defined(CONFIG_SHIELD_CTR_DS18B20)
struct app_data_w1_therm_measurement {
	struct app_data_analog_aggreg temperature;
};

struct app_data_w1_therm_sensor {
	uint64_t serial_number;
	int sample_count;
	float samples_temperature[APP_DATA_W1_THERM_MAX_SAMPLES];

	int measurement_count;
	struct app_data_w1_therm_measurement measurements[APP_DATA_W1_THERM_MAX_MEASUREMENTS];
};

struct app_data_w1_therm {
	struct app_data_w1_therm_sensor sensor[APP_DATA_W1_THERM_COUNT];

	int64_t timestamp;
	atomic_t sample;
	atomic_t aggreg;
};
#endif /* defined(CONFIG_SHIELD_CTR_DS18B20) */

struct app_data {
	uint32_t sequence;
	float system_voltage_rest;
	float system_voltage_load;
	float system_current_load;
	float therm_temperature;
	float accel_acceleration_x;
	float accel_acceleration_y;
	float accel_acceleration_z;
	int accel_orientation;
	int serial_number;

#if defined(CONFIG_APP_TAMPER)
	struct app_data_tamper tamper;
#endif /* defined(CONFIG_APP_TAMPER) */

#if defined(CONFIG_SHIELD_CTR_Z)
	struct app_data_backup backup;
	struct app_data_button button[APP_DATA_BUTTON_COUNT];
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#if defined(CONFIG_SHIELD_CTR_K1)
	struct app_data_channel channel[4];
#endif /* defined(CONFIG_SHIELD_CTR_K1) */

#if defined(CONFIG_SHIELD_CTR_DS18B20)
	struct app_data_w1_therm w1_therm;
#endif /* defined(CONFIG_SHIELD_CTR_DS18B20) */
};

extern struct app_data g_app_data;

void app_data_lock(void);
void app_data_unlock(void);

#ifdef __cplusplus
}
#endif

#endif /* APP_DATA_H_ */
