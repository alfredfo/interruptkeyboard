#pragma once

#include <stdint.h>

enum { PA, PB, PC, PD, PE, PF, PG, PH, PI, PJ, PK };

typedef volatile struct {
  uint32_t memrmp;
  uint32_t pmc;
  union {
    uint16_t exticr1;
    uint32_t _exticr1_full;
  };
  uint32_t exticr2;
  uint32_t exticr3;
  uint32_t exticr4;
  uint32_t cmpcr;
} syscfg_t;
