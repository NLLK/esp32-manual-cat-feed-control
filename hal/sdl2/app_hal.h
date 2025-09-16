#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>

void hal_setup(void);
void hal_loop(void);

void hal_setBrighness(uint8_t percents);

#endif /*DRIVER_H*/
