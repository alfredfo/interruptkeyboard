#include <stdint.h>

#include "exti.h"
#include "gpio.h"
#include "nvic.h"
#include "syscfg.h"
#include "vector_table.h"

extern volatile uint8_t currently_pressed_key;
void init_keyboard(syscfg_t *, vector_table_t *, nvic_t *, gpio_t *);
