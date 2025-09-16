#ifndef APP_HAL_H
#define APP_HAL_H

#include <stdint.h>

void hal_setup(void);
void hal_loop(void);

void hal_setBrighness(uint8_t percents);

#endif /*APP_HAL_H*/
