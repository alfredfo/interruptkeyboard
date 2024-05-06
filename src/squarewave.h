#pragma once

#include "gpio.h"
#include "systick.h"
#include "vector_table.h"

extern gpio_t *gpio_e;
extern systick_t *stk;

void init_square_wave(vector_table_t *);
void start_square_wave(uint32_t);
void stop_square_wave();
