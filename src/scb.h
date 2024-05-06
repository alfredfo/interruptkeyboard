#pragma once

#include "vector_table.h"

// volatile scb_t {
typedef volatile struct {
  uint32_t cpuid;
  uint32_t icsr;
  vector_table_t *vtor;
  uint32_t aircr;
  uint32_t scr;
  uint32_t ccr;
  uint32_t shpr1;
  uint32_t shpr2;
  uint32_t shpr3;
  uint32_t shcsr;
  uint32_t cfsr;
  uint32_t hfsr;
  uint32_t _unused0;
  uint32_t mmar;
  uint32_t bfar;
  uint32_t afsr;
} scb_t;
