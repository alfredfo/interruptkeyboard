#pragma once

#include <stdint.h>

typedef void (*irq_handler_t)(void);

typedef volatile struct {
  irq_handler_t _reserved0;
  irq_handler_t reset;
  irq_handler_t nmi;
  irq_handler_t hardfault;
  irq_handler_t memmanage;
  irq_handler_t busfault;
  irq_handler_t usagefault;
  uint8_t _reserved1[16];
  irq_handler_t svcall;
  irq_handler_t debugmonitor;
  irq_handler_t _reserved2;
  irq_handler_t pendsv;
  irq_handler_t systick;
  irq_handler_t wwdg;
  irq_handler_t pvd;
  uint8_t _unused0[16];
  irq_handler_t exti0;
  irq_handler_t exti1;
  irq_handler_t exti2;
  irq_handler_t exti3;
  irq_handler_t exti4;
  uint8_t _unused1[280];
} vector_table_t;
