#pragma once

#include <stdint.h>

typedef volatile struct {
  uint32_t iser0;
  uint32_t iser1;
  uint32_t iser2;
  uint8_t _padding0[116];
  uint32_t icer0;
  uint32_t icer1;
  uint32_t icer2;
  uint8_t _padding1[116];
  uint32_t ispr0;
  uint32_t ispr1;
  uint32_t ispr2;
  uint8_t _padding2[116];
  uint32_t icpr0;
  uint32_t icpr1;
  uint32_t icpr2;
  uint8_t _padding3[116];
  uint32_t iabr0;
  uint32_t iabr1;
  uint32_t iabr2;
} nvic_t;
