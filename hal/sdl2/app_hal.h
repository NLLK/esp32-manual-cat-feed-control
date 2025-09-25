#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>
#include "../../src/common/utils/CommonDateTime.hpp"

void hal_setup(void);
void hal_loop(void);

void hal_setBrighness(uint8_t percents);
void hal_setTimeToRtc(CommonDateTime time);

#endif /*DRIVER_H*/
