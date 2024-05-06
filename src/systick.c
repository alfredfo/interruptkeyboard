#include "systick.h"

void delay_250ns(systick_t *stk) {
  stk->ctrl = 0;
  stk->load = 42;
  stk->val = 0;
  stk->ctrl |= (B_ENABLE | B_CLKSOURCE);
  while ((stk->ctrl & B_COUNTFLAG) == 0)
    ;
  stk->ctrl = 0;
}

void delay_micro(systick_t *stk, unsigned int us) {
  for (int i = 0; i < us; i++) {
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
    delay_250ns(stk);
  }
}

void delay_milli(systick_t *stk, unsigned int ms) {
  for (int i = 0; i < ms; i++) {
    delay_micro(stk, 1000);
  }
}
