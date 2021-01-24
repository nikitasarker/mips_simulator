#include <iostream>
#include <cmath>
#include <vector>

uint32_t get_c(uint32_t address);

int32_t i_addi(int32_t a, int32_t b);

uint32_t i_addiu(uint32_t a, uint32_t b);

uint32_t i_ori(int32_t a, int32_t b);

int32_t i_xori(int32_t a, int32_t b);

int32_t i_slti(int32_t a, int32_t b);

uint32_t i_sltiu(uint32_t a, uint32_t b);

uint32_t i_andi(int32_t a, int32_t b);

int32_t i_lb(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

uint32_t i_lbu(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

int32_t i_lh(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

uint32_t i_lhu(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

int32_t i_lw(int32_t a, int32_t imm, std::vector<uint8_t> &memory);

void i_sb(uint32_t b, uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

void i_sh(uint32_t dest, uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

void i_sw(uint32_t base, uint32_t a, uint32_t offset, std::vector<uint8_t> &memory);

void i_beq(int32_t a, int32_t b, int32_t offset, uint32_t pc, uint32_t &pc_next);

uint32_t i_bne(int32_t a, int32_t b, int32_t offset, uint32_t pc, uint32_t &pc_next);

uint32_t i_bgez(int32_t a, int32_t offset, uint32_t pc);

void i_bgezal(int32_t a, int32_t imm, uint32_t pc, uint32_t &pc_next, uint32_t &ra_register);

void i_bltzal(int32_t a, int32_t imm, uint32_t pc, uint32_t &pc_next, uint32_t &ra_registers);

uint32_t i_blez(int32_t a, int32_t offset, uint32_t pc);

uint32_t i_bgtz(int32_t a, int32_t offset, uint32_t pc);

uint32_t i_bltz(int32_t a, int32_t offset, uint32_t pc);

uint32_t i_lui(uint32_t imm);

uint32_t i_lwr(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);

uint32_t i_lwl(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory);
