#ifndef APP_TAMPER_H_
#define APP_TAMPER_H_

#ifdef __cplusplus
extern "C" {
#endif

int app_tamper_init(void);
int app_tamper_clear(void);
int app_tamper_get_states(void);
int app_tamper_get_state(int btnID);

#ifdef __cplusplus
}
#endif

#endif /* APP_TAMPER_H_ */
