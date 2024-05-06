#pragma once

#include <stdint.h>

enum {
  B_ENABLE = 1 << 0,
  B_TICKINT = 1 << 1,
  B_CLKSOURCE = 1 << 2,
  B_COUNTFLAG = 1 << 16
};

typedef volatile struct {
  uint32_t ctrl;
  uint32_t load;
  uint32_t val;
  uint32_t calib;
} systick_t;

void delay_250ns(systick_t *);
void delay_micro(systick_t *, uint32_t);
void delay_milli(systick_t *, uint32_t);
