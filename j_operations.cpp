#include "j_operations.h"

uint32_t j_j(uint32_t imm){
  return (0x10000000+(imm<<2));
}

uint32_t j_jal(uint32_t imm, uint32_t &ra_register, uint32_t pc){
  ra_register = pc+8;
  return (0x10000000+(imm<<2));
}
