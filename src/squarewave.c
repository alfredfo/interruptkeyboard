#include "squarewave.h"
#include "gpio.h"
#include "systick.h"
#include "vector_table.h"

void systick_handler(void) {
  gpio_e->moder = 1;
  gpio_e->odr.l ^= 0xFF;
}

void init_square_wave(vector_table_t *vtor) {
  gpio_e->moder = 1;
  gpio_e->odr.l = 1;
  vtor->systick = systick_handler;
}

void start_square_wave(uint32_t us) {
  stk->ctrl = 0;
  stk->load = 168 * us;
  stk->ctrl = B_ENABLE | B_TICKINT | B_CLKSOURCE;
}

void stop_square_wave() { stk->ctrl &= ~B_ENABLE; }
