#pragma once

#include <stdint.h>
#include "../../src/common/utils/CommonDateTime.hpp"
#include "./tasks/RtcTimeSetTask.hpp"

extern RtcTimeSetTask* rtcTimeSetTaskSingletone;

void hal_setup(void);
void hal_loop(void);

void hal_setBrighness(uint8_t percents);
void hal_setTimeToRtc(CommonDateTime time);