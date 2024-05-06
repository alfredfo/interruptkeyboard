#include "board-constants.h"
#include "gpio.h"
#include "keyboard.h"
#include "scb.h"
#include "squarewave.h"
#include "syscfg.h"
#include "systick.h"
#include "vector_table.h"

systick_t *stk = 0x0;
gpio_t *gpio_e = 0x0;
exti_t *exti = 0x0;

int main() {
  scb_t *scb = (scb_t *)SCB_ADDR;
  syscfg_t *syscfg = (syscfg_t *)SYSCFG_ADDR;
  exti = (exti_t *)EXTI_ADDR;
  nvic_t *nvic = (nvic_t *)NVIC_ADDR;

  gpio_e = (gpio_t *)GPIO_E_ADDR;
  stk = (systick_t *)SYSTICK_ADDR;
  scb->vtor = (vector_table_t *)MY_VECTOR_TABLE_ADDR;

  init_keyboard(syscfg, scb->vtor, nvic, gpio_e);

  while (1) {
  };

  return 0;
}
