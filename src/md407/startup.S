  .globl _start
  .section .start_section, "ax", %progbits
_start:
  ldr r0, =stack_top
  mov sp, r0
  ldr r0, =0x40023830
  ldr r1, =0x18
  str r1, [r0]
  bl main
  b .
