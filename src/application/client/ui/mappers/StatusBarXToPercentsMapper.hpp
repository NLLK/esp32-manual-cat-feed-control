#pragma once

#include "stdint.h"

class StatusBarXToPercentsMapper {
public:
    StatusBarXToPercentsMapper(){};

    uint8_t map(uint8_t x){
        return (x*100)/240;
    }   
};