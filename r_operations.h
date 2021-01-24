#include <iostream>
#include <cmath>

uint32_t r_addu(uint32_t a, uint32_t b); //add - unsigned(no overflow)

int32_t r_add(int32_t a, int32_t b);

void r_div(int32_t a, int32_t b, uint32_t &hi, uint32_t &lo);

int32_t r_and(int32_t a, int32_t b);

void r_mult(int32_t a, int32_t b, uint32_t& hi, uint32_t& lo); //something about HI, LO registers

void r_divu(uint32_t a, uint32_t b, uint32_t &hi, uint32_t &lo);

void r_multu(uint32_t a, uint32_t b, uint32_t &hi, uint32_t &lo);

int32_t r_or(int32_t a, int32_t b);

uint32_t r_sllv(uint32_t a, uint32_t b);

uint32_t r_sll(uint32_t b, uint32_t sa);

int32_t r_srav(int32_t a, int32_t b);

int32_t r_sra(int32_t b, int32_t sa);

uint32_t r_srl(uint32_t b, uint32_t sa);

uint32_t r_srlv(uint32_t a, uint32_t b);

uint32_t r_subu(uint32_t a, uint32_t b);

int32_t r_sub(int32_t a, int32_t b);

int32_t r_xor(int32_t a, int32_t b);

int32_t r_slt(int32_t a, int32_t b);

uint32_t r_sltu(uint32_t a, uint32_t b);

uint32_t r_jr(uint32_t a, uint32_t pc, uint32_t a_register_num);

uint32_t r_jalr(uint32_t a, uint32_t pc, uint32_t& ra_register, uint32_t a_register_num, uint32_t ra_register_num);

uint32_t r_mflo(uint32_t& lo);

uint32_t r_mfhi(uint32_t& hi);

uint32_t r_mtlo(uint32_t a);

uint32_t r_mthi(uint32_t a);

uint32_t execute_operation(std::string op, uint32_t instruction);
