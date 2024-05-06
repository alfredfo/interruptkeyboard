#include "keyboard.h"
#include "exti.h"
#include "nvic.h"
#include "squarewave.h"
#include "syscfg.h"

volatile uint8_t currently_pressed_key = 0xFF;
extern exti_t *exti;

void activate_row(gpio_t *gpio, uint8_t row) { gpio->odr.l = 16 << (row - 1); }

uint8_t read_col(gpio_t *gpio) {
  if (gpio->idr.l & 1) {
    return 1;
  } else if (gpio->idr.l & 2) {
    return 2;
  } else if (gpio->idr.l & 4) {
    return 3;
  } else if (gpio->idr.l & 8) {
    return 4;
  }
  return 0;
}

unsigned char key_value(uint8_t row, uint8_t col) {
  return (row - 1) * 4 + col;
}

unsigned char keyb(gpio_t *gpio) {
  unsigned char k = 0xFF;
  for (uint8_t i = 1; i <= 4; i++) {
    activate_row(gpio, i);
    const uint8_t col = read_col(gpio);
    if (col) {
      k = key_value(i, col);
    }
  }
  return k;
}

void out7seg(gpio_t *gpio, unsigned char c) {
  const uint8_t segcodes[] = {0x3F, 0x6,  0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
                              0x7F, 0x6F, 0x77, 0x7F, 0x39, 0x3F, 0x79, 0x71};

  gpio->odr.h = segcodes[c];
}

void keyboard_irq_handler(void) {
  exti->imr &= ~(1 | 2 | 4 | 8);
  unsigned char c = keyb(gpio_e);
  out7seg(gpio_e, c);
  gpio_e->odr.l = 0xF0;
  exti->pr |= (1 | 2 | 4 | 8);
  exti->imr |= (1 | 2 | 4 | 8);
}

void init_keyboard(syscfg_t *syscfg, vector_table_t *vtor, nvic_t *nvic,
                   gpio_t *gpio) {
  gpio_e->moder = 0x55555500;
  gpio_e->otyper = 0x000F;
  gpio_e->pupdr = 0x000000AA;
  gpio_e->odr.h = 0x3F;
  gpio_e->odr.l = 0xF0;

  syscfg->exticr1 = PE | PE << 4 | PE << 8 | PE << 0xC;

  exti->imr |= (1 | 2 | 4 | 8);
  exti->rtsr |= (1 | 2 | 4 | 8);
  ;
  nvic->iser0 = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);
  vtor->exti0 = keyboard_irq_handler;
  vtor->exti1 = keyboard_irq_handler;
  vtor->exti2 = keyboard_irq_handler;
  vtor->exti3 = keyboard_irq_handler;
}
