/*
 * Copyright (c) 2023 HARDWARIO a.s.
 *
 * SPDX-License-Identifier: LicenseRef-HARDWARIO-5-Clause
 */

#include "app_config.h"
#include "app_work.h"

/* Zephyr includes */
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/shell/shell.h>

/* Standard includes */
#include <errno.h>
#include <stdlib.h>

LOG_MODULE_REGISTER(app_shell, LOG_LEVEL_INF);

static int cmd_sample(const struct shell *shell, size_t argc, char **argv)
{
	if (argc > 1) {
		shell_error(shell, "unknown parameter: %s", argv[1]);
		shell_help(shell);
		return -EINVAL;
	}

	app_work_sample();

	return 0;
}

static int cmd_send(const struct shell *shell, size_t argc, char **argv)
{
	if (argc > 1) {
		shell_error(shell, "unknown parameter: %s", argv[1]);
		shell_help(shell);
		return -EINVAL;
	}

	app_work_send();

	return 0;
}

static int cmd_aggreg(const struct shell *shell, size_t argc, char **argv)
{
	if (argc > 1) {
		shell_error(shell, "unknown parameter: %s", argv[1]);
		shell_help(shell);
		return -EINVAL;
	}

	app_work_aggreg();

	return 0;
}

static int print_help(const struct shell *shell, size_t argc, char **argv)
{
	if (argc > 1) {
		shell_error(shell, "command not found: %s", argv[1]);
		shell_help(shell);
		return -EINVAL;
	}

	shell_help(shell);

	return 0;
}

#define CONFIG_PARAM_INT(_name_d, _name_u, _min, _max, _help)                                      \
	SHELL_CMD_ARG(_name_d, NULL, _help, app_config_cmd_config_##_name_u, 1, 1),
#define CONFIG_PARAM_FLOAT(_name_d, _name_u, _min, _max, _help)                                    \
	SHELL_CMD_ARG(_name_d, NULL, _help, app_config_cmd_config_##_name_u, 1, 1),
#define CONFIG_PARAM_BOOL(_name_d, _name_u, _help)                                                 \
	SHELL_CMD_ARG(_name_d, NULL, _help, app_config_cmd_config_##_name_u, 1, 1),

/* clang-format off */

SHELL_STATIC_SUBCMD_SET_CREATE(
	sub_app_config,

	SHELL_CMD_ARG(show, NULL,
	              "List current configuration.",
	              app_config_cmd_config_show, 1, 0),

	CONFIG_PARAM_LIST()

	#if defined(CONFIG_PARAM_LIST_CTR_Z)
		CONFIG_PARAM_LIST_CTR_Z()
	#endif

	#if defined(CONFIG_PARAM_LIST_CTR_K1)
		CONFIG_PARAM_LIST_CTR_K1()
	#endif

	#if defined(CONFIG_SHIELD_CTR_K1)
		SHELL_CMD_ARG(channel-active, NULL,
			"Get/Set channel activation (format: <channel> <true|false>).",
			app_config_cmd_config_channel_active, 2, 1),

		SHELL_CMD_ARG(channel-differential, NULL,
			"Get/Set channel differential mode (format: <channel> <true|false>).",
			app_config_cmd_config_channel_differential, 2, 1),

		SHELL_CMD_ARG(channel-calib-x0, NULL,
			"Get/Set channel X0 calibration point "
			"(format: <channel> <-2147483648..2147483647>).",
			app_config_cmd_config_channel_calib_x0, 2, 1),

		SHELL_CMD_ARG(channel-calib-y0, NULL,
			"Get/Set channel Y0 calibration point "
			"(format: <channel> <-2147483648..2147483647>).",
			app_config_cmd_config_channel_calib_y0, 2, 1),

		SHELL_CMD_ARG(channel-calib-x1, NULL,
			"Get/Set channel X1 calibration point "
			"(format: <channel> <-2147483648..2147483647>).",
			app_config_cmd_config_channel_calib_x1, 2, 1),

		SHELL_CMD_ARG(channel-calib-y1, NULL,
			"Get/Set channel Y1 calibration point "
			"(format: <channel> <-2147483648..2147483647>).",
			app_config_cmd_config_channel_calib_y1, 2, 1),
	#endif /* defined(CONFIG_SHIELD_CTR_K1) */

	#if defined(CONFIG_PARAM_LIST_CTR_DS18B20)
		CONFIG_PARAM_LIST_CTR_DS18B20()
	#endif

	SHELL_SUBCMD_SET_END
);

SHELL_STATIC_SUBCMD_SET_CREATE(
	sub_app,

	SHELL_CMD_ARG(config, &sub_app_config, "Configuration commands.",
	              print_help, 1, 0),

	SHELL_SUBCMD_SET_END
);

SHELL_CMD_REGISTER(app, &sub_app, "Application commands.", print_help);

SHELL_CMD_REGISTER(sample, NULL, "Sample immediately.", cmd_sample);
SHELL_CMD_REGISTER(send, NULL, "Send data immediately.", cmd_send);
SHELL_CMD_REGISTER(aggreg, NULL, "Aggregate data immediately", cmd_aggreg);

/* clang-format on */

#undef CONFIG_PARAM_INT
#undef CONFIG_PARAM_FLOAT
#undef CONFIG_PARAM_BOOL
