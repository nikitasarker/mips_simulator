#include "r_operations.h"
#include "i_operations.h"
#include "j_operations.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

void check_instruction_access(uint32_t pc);
void check_write_access(uint32_t pc);
void check_read_access(uint32_t pc);

uint32_t read_instruction(uint32_t pc, std::vector<uint8_t> memory);
uint32_t execute_instruction(uint32_t pc, uint32_t &pc_next, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t instruction, std::vector<uint8_t> &memory);

//FOR R, I, J TYPE INSTRUCTIONS
char find_instr_type(uint32_t instr);
uint32_t get_opcode(uint32_t instruction);

//FOR R, I TYPE INSTRUCTIONS
uint32_t get_source_one(uint32_t instruction); //can't have shared function if we have classes?
uint32_t get_dest_i(uint32_t instruction);

//FOR R TYPE INSTRUCTIONS
uint32_t get_source_two(uint32_t instruction);
uint32_t get_dest_r(uint32_t instruction); //possible reason to make classes
uint32_t get_shift_amt(uint32_t instruction);
uint32_t get_fn_code(uint32_t instruction);

int r_find_operation(uint32_t fn_code);

//FOR I TYPE INSTRUCTIONS
uint32_t get_dest_i(uint32_t instruction); //possible reason to make classes, this func is the same as get_source_two :(
uint32_t get_immediate_const(uint32_t instruction);

int i_find_operation(uint32_t opcode, uint32_t instruction);

//FOR J TYPE INSTRUCTIONS
int j_find_operation(uint32_t instr);
uint32_t get_imm(uint32_t instruction);

//EXECUTE OPERATION
uint32_t r_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next);
uint32_t i_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next, std::vector<uint8_t> &memory);
uint32_t j_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next);
