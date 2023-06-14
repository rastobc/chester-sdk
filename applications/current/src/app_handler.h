#ifndef APP_HANDLER_H_
#define APP_HANDLER_H_

/* CHESTER includes */
#include <chester/ctr_lrw.h>
#include <chester/ctr_lte.h>
#include <chester/drivers/ctr_z.h>

#ifdef __cplusplus
extern "C" {
#endif

void app_handler_lrw(enum ctr_lrw_event event, union ctr_lrw_event_data *data, void *param);
void app_handler_lte(enum ctr_lte_event event, union ctr_lte_event_data *data, void *param);

#if defined(CONFIG_SHIELD_CTR_Z)
void app_handler_ctr_z(const struct device *dev, enum ctr_z_event event, void *param);
#endif /* defined(CONFIG_SHIELD_CTR_Z) */

#ifdef __cplusplus
}
#endif

#endif /* APP_HANDLER_H_ */
