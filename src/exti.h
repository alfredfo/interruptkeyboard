#pragma once

#include <stdint.h>

typedef volatile struct {
  uint32_t imr;
  uint32_t emr;
  uint32_t rtsr;
  uint32_t ftsr;
  uint32_t swier;
  uint32_t pr;
} exti_t;
