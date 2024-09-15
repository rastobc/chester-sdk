#include "app_data.h"
#include "app_work.h"

/* CHESTER includes */
#include <chester/ctr_edge.h>
#include <chester/ctr_rtc.h>
#include <chester/ctr_button.h>

/* Zephyr includes */
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

/* Standard includes */
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>

LOG_MODULE_REGISTER(app_tamper, LOG_LEVEL_DBG);

#define ON_TIME  K_MSEC(30)
#define OFF_TIME K_MSEC(1000)

#if defined(CONFIG_APP_TAMPER)
static const struct gpio_dt_spec m_tamper_spec =
	GPIO_DT_SPEC_GET(DT_PATH(zephyr_user), tamper_gpios);
#endif

#if defined(CONFIG_CTR_BUTTON)
static const struct gpio_dt_spec m_button_spec = GPIO_DT_SPEC_GET(DT_ALIAS(sw1), gpios);
#endif

static struct ctr_edge m_edge;
static struct ctr_edge m_edge_ext;

static struct k_timer m_on_timer;
static struct k_timer m_off_timer;

static void edge_callback(struct ctr_edge *edge, enum ctr_edge_event event, void *user_data)
{

	LOG_INF("Callback Event: %d", event);
}

void off_work_handler(struct k_work *work)
{
	int ret;

	k_timer_start(&m_on_timer, OFF_TIME, K_FOREVER);

#if defined(CONFIG_APP_TAMPER)
	ret = ctr_edge_unwatch(&m_edge);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_unwatch` failed: %d", ret);
		return;
	}

	if (!device_is_ready(m_tamper_spec.port)) {
		LOG_ERR("TMP Port not ready");
		return;
	}

	ret = gpio_pin_configure_dt(&m_tamper_spec, GPIO_INPUT | GPIO_PULL_DOWN);
	if (ret) {
		LOG_ERR("TMP Call `gpio_pin_configure_dt` failed: %d", ret);
		return;
	}
#endif

#if defined(CONFIG_CTR_BUTTON)
	ret = ctr_edge_unwatch(&m_edge_ext);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_unwatch` failed: %d", ret);
		return;
	}

	if (!device_is_ready(m_button_spec.port)) {
		LOG_ERR("BTN Port not ready");
		return;
	}

	ret = gpio_pin_configure_dt(&m_button_spec, GPIO_INPUT | GPIO_PULL_DOWN);
	if (ret) {
		LOG_ERR("BTN Call `gpio_pin_configure_dt` failed: %d", ret);
		return;
	}
#endif
}

static K_WORK_DEFINE(m_off_work, off_work_handler);

void off_timer_handler(struct k_timer *timer)
{
	k_work_submit(&m_off_work);
}

void on_work_handler(struct k_work *work)
{
	int ret;

	k_timer_start(&m_off_timer, ON_TIME, K_FOREVER);

#if defined(CONFIG_APP_TAMPER)
	if (!device_is_ready(m_tamper_spec.port)) {
		LOG_ERR("TMP Port not ready");
		return;
	}

	ret = gpio_pin_configure_dt(&m_tamper_spec, GPIO_INPUT | GPIO_PULL_UP);
	if (ret) {
		LOG_ERR("TMP Call `gpio_pin_configure_dt` failed: %d", ret);
		return;
	}

	ret = ctr_edge_watch(&m_edge);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_watch` failed: %d", ret);
		return;
	}
#endif

#if defined(CONFIG_CTR_BUTTON)
	if (!device_is_ready(m_button_spec.port)) {
		LOG_ERR("BTN Port not ready");
		return;
	}

	ret = gpio_pin_configure_dt(&m_button_spec, GPIO_INPUT | GPIO_PULL_UP);
	if (ret) {
		LOG_ERR("BTN Call `gpio_pin_configure_dt` failed: %d", ret);
		return;
	}

	ret = ctr_edge_watch(&m_edge_ext);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_watch` failed: %d", ret);
		return;
	}
#endif
}

static K_WORK_DEFINE(m_on_work, on_work_handler);

void on_timer_handler(struct k_timer *timer)
{
	k_work_submit(&m_on_work);
}

int app_tamper_init(void)
{
	int ret;

	k_timer_init(&m_on_timer, on_timer_handler, NULL);
	k_timer_init(&m_off_timer, off_timer_handler, NULL);

#if defined(CONFIG_APP_TAMPER)

	LOG_INF("Init Tamper");

	if (!device_is_ready(m_tamper_spec.port)) {
		LOG_ERR("TMP Port not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&m_tamper_spec, GPIO_INPUT | GPIO_PULL_DOWN);
	if (ret) {
		LOG_ERR("TMP Call `gpio_pin_configure_dt` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_init(&m_edge, &m_tamper_spec, false);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_init` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_callback(&m_edge, edge_callback, NULL);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_set_callback` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_cooldown_time(&m_edge, 10);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_set_cooldown_time` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_active_duration(&m_edge, 20);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_set_active_duration` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_inactive_duration(&m_edge, 20);
	if (ret) {
		LOG_ERR("TMP Call `ctr_edge_set_inactive_duration` failed: %d", ret);
		return ret;
	}

#endif

#if defined(CONFIG_CTR_BUTTON)

	LOG_INF("Init Button");

	if (!device_is_ready(m_button_spec.port)) {
		LOG_ERR("BTN Port not ready");
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(&m_button_spec, GPIO_INPUT | GPIO_PULL_DOWN);
	if (ret) {
		LOG_ERR("BTN Call `gpio_pin_configure_dt` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_init(&m_edge_ext, &m_button_spec, false);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_init` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_callback(&m_edge_ext, edge_callback, NULL);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_set_callback` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_cooldown_time(&m_edge_ext, 10);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_set_cooldown_time` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_active_duration(&m_edge_ext, 20);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_set_active_duration` failed: %d", ret);
		return ret;
	}

	ret = ctr_edge_set_inactive_duration(&m_edge_ext, 20);
	if (ret) {
		LOG_ERR("BTN Call `ctr_edge_set_inactive_duration` failed: %d", ret);
		return ret;
	}

#endif

	k_timer_start(&m_on_timer, K_NO_WAIT, K_FOREVER);

	return 0;
}

int app_tamper_get_state(int btnID);

int app_tamper_get_states(void)
{

	app_tamper_get_state(0);
	app_tamper_get_state(1);

	return 0;
}

int app_tamper_get_state(int btnID)
{
	int ret = -1;
	bool state = false;

	switch (btnID) {
	case 0:
		ret = ctr_edge_get_active(&m_edge, &state);
		break;
	case 1:
		ret = ctr_edge_get_active(&m_edge_ext, &state);
		break;
	}

	if (ret) {
		LOG_ERR("STATE Call `ctr_edge_get_active` failed: %d", ret);
		return ret;
	}

	LOG_INF("STATE: %d for btnID: %d", (state ? 1 : 0), btnID);

	struct app_data_button *button = &g_app_data.button[btnID];

	app_data_lock();

	if (state > 0) {
		button->close_count++;
	} else {
		button->open_count++;
	}

	LOG_INF("BTN count: open = %d / close = %d", button->open_count, button->close_count);

	app_data_unlock();

	return ret;
}

int app_tamper_clear(void)
{
	app_data_lock();
	// g_app_data.tamper.event_count = 0;
	app_data_unlock();

	return 0;
}
