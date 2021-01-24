#include "decode.h"

const uint32_t ADDR_DATA = 0x20000000;
const uint32_t DATA_SIZE = 0x4000000;

const uint32_t ADDR_INSTR = 0x10000000; //cheeky since this is also defined in main.cpp
const uint32_t INSTR_SIZE = 0x1000000;

const uint32_t ADDR_GETC = 0x30000000;
const uint32_t ADDR_PUTC = 0x30000004;
const uint32_t CHAR_SIZE = 0x4;

void check_instruction_access(uint32_t pc) {
	if((ADDR_INSTR <= pc) && (pc <= ((ADDR_INSTR + INSTR_SIZE) - 1))) {
		return;
	}
	else if(pc == 0) {
		return;
	}
	else if(pc%4==0) {
		return;
	}
	exit(-11);
}

void check_write_access(uint32_t pc) {
	if(((ADDR_DATA <= pc) && (pc <= ((ADDR_DATA + DATA_SIZE) - 1)))
	 	|| ((ADDR_PUTC <= pc) && (pc<= ((ADDR_PUTC + CHAR_SIZE) -1)))
		) {
		return;
	}
	exit(-11);
}

void check_read_access(uint32_t pc) {
	if(
		((ADDR_DATA <= pc) && (pc <= ((ADDR_DATA + DATA_SIZE) - 1)))
		|| ((ADDR_GETC <= pc) && (pc<= ((ADDR_GETC + CHAR_SIZE) -1)))
		|| ((ADDR_INSTR <= pc) && (pc <= ((ADDR_INSTR + INSTR_SIZE) - 1)))
	) {
		return;
	}
	exit(-11);
}

uint32_t read_instruction(uint32_t pc, std::vector<uint8_t> memory) {
	check_instruction_access(pc);
	uint32_t instruction = (
		((uint32_t) memory[pc]) << 24 |
		((uint32_t) memory[pc+1]) << 16 |
		((uint32_t) memory[pc+2]) << 8 |
		((uint32_t) memory[pc+3]) << 0
	);
	if(instruction == 0) {
		exit(-12);
	}
	return instruction;
}

uint32_t execute_instruction(uint32_t pc, uint32_t &pc_next, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t instruction, std::vector<uint8_t> &memory) {

	uint32_t opcode = get_opcode(instruction);
	char instr_type = find_instr_type(opcode); //which type of instr is it? R, I, J?

	if(instr_type == 'R') {
		uint32_t fn_code = get_fn_code(instruction);
		int operation = r_find_operation(fn_code);

		pc = r_execute_operation(operation, instruction, registers, hi, lo, pc, pc_next); //do operation
	}
	else if(instr_type == 'I') {
		uint32_t fn_code = get_opcode(instruction);
		int operation = i_find_operation(fn_code, instruction);

		pc = i_execute_operation(operation, instruction, registers, hi, lo, pc, pc_next, memory);
	}
	else if(instr_type == 'J') {
		int operation = j_find_operation(opcode);
		pc = j_execute_operation(operation, instruction, registers, hi, lo, pc, pc_next);
	}

	return pc;
}

/*
//////////////////////////////////
//FOR R, I, J TYPE INSTRUCTIONS //
//////////////////////////////////
*/
char find_instr_type(uint32_t opcode) {
	if (opcode == 0b0){
		return 'R';
	}
	else if ((opcode == 0b10) || (opcode == 0b11)){
		return 'J';
	}
	else{
		return 'I';
	}
}

uint32_t get_opcode(uint32_t instruction) {
	return instruction >> 26;
}

/*
//////////////////////////////////
/// FOR R, I TYPE INSTRUCTIONS ///
//////////////////////////////////
*/
uint32_t get_source_one(uint32_t instruction) {
	return (instruction & 0b00000011111000000000000000000000) >> 21;
}

/*
//////////////////////////////////
/////FOR R TYPE INSTRUCTIONS /////
//////////////////////////////////
*/
uint32_t get_source_two(uint32_t instruction) {
	return (instruction & 0b00000000000111110000000000000000) >> 16;
}

uint32_t get_dest_r(uint32_t instruction) {
	return (instruction & 0b00000000000000001111100000000000) >> 11;
}

uint32_t get_shift_amt(uint32_t instruction) {
	return (instruction & 0b00000000000000000000011111000000) >> 6;
}

uint32_t get_fn_code(uint32_t instruction) {
	return (instruction & 0b00000000000000000000000000111111);
}

int r_find_operation(uint32_t fn_code){
  if (fn_code == 0b100000){   //add
    return 1;
  }
  else if (fn_code == 0b100001){  //addu
    return 2;
  }
	else if (fn_code == 0b100100){  //and
    return 3;
  }
  else if (fn_code == 0b011010){ //div
    return 4;
  }
	else if (fn_code == 0b011011){  //divu
    return 5;
  }
	else if (fn_code == 0b001000){ //jr
    return 6;
  }
  else if (fn_code == 0b001001){ //jalr
    return 7;
  }
  else if (fn_code == 0b011000){ //mult
    return 8;
  }
  else if (fn_code == 0b011001){ //multu
    return 9;
  }
	else if (fn_code == 0b010010){ //mflo
		return 10;
	}
	else if (fn_code == 0b010000){ //mfhi
		return 11;
	}
	else if (fn_code == 0b010011){ //mtlo
		return 12;
	}
	else if (fn_code == 0b010001){ //mthi
		return 13;
	}
  else if (fn_code == 0b100101){ //or
    return 14;
  }
	else if (fn_code == 0b0){ //sll
    return 15;
  }
  else if (fn_code == 0b000100){  //sllv
    return 16;
  }
  else if (fn_code == 0b000111){ //srav
    return 17;
  }
  else if (fn_code == 0b000011){ //sra
    return 18;
  }
	else if (fn_code == 0b000010){ //srl
		return 19;
	}
  else if (fn_code == 0b000110){ //srlv
    return 20;
  }
	else if (fn_code == 0b100010){ //sub
		return 21;
	}
  else if (fn_code == 0b100011){ //subu
    return 22;
  }
  else if (fn_code == 0b101010){ //slt
    return 23;
  }
  else if (fn_code == 0b101011){ //sltu
    return 24;
  }
	else if (fn_code == 0b100110){ //xor
    return 25;
  }
	else{
		exit(-12); //invalid instruction
	}

}


/*
//////////////////////////////////
/////FOR I TYPE INSTRUCTIONS /////
//////////////////////////////////
*/
uint32_t get_dest_i(uint32_t instruction) {
	return (instruction & 0b00000000000111110000000000000000) >> 16;
}

uint32_t get_immediate_const(uint32_t instruction) {
	return (instruction & 0b00000000000000001111111111111111);
}

int i_find_operation(uint32_t opcode, uint32_t instruction){
  if(opcode == 0b001000){
    return 26;
  }
  else if(opcode == 0b001001){
    return 27;
  }
  else if(opcode == 0b001100){
    return 28;
  }
  else if(opcode == 0b001101){
    return 29;
  }
  else if(opcode == 0b001110){
    return 30;
  }
  else if(opcode == 0b001010){
    return 31;
  }
  else if(opcode == 0b001011){
    return 32;
  }
  else if(opcode == 0b000100){
    return 33;
  }
  else if(opcode == 0b000101){
    return 34;
  }
  else if(opcode == 0b100000){
    return 35;
  }
  else if(opcode == 0b100100){
    return 36;
  }
  else if(opcode == 0b100101){
    return 37;
  }
  else if(opcode == 0b100001){
    return 38;
  }
  else if(opcode == 0b100011){
    return 39;
  }
  else if(opcode == 0b101000){
    return 40;
  }
  else if(opcode == 0b101001){
    return 41;
  }
  else if(opcode == 0b101011){
    return 42;
  }
  else if(opcode == 0b000001){
    uint32_t offset =  (instruction & 0b00000000000111110000000000000000) >> 16;
    if (offset == 0b00001){
      return 43;
    }
    else if(offset == 0b10001){
      return 44;
    }
    else if(offset == 0b0){ //BLTZ
      return 45;
    }
    else if(offset == 0b10000){
			return 46;
		}
  }
  else if(opcode == 0b000111){
    return 47;
  }
	else if(opcode == 0b001111){
		return 48;
	}
	else if(opcode == 0b100110){
		return 49;
	}
	else if(opcode == 0b100010){
		return 50;
	}
	else if(opcode == 0b000110){ //BLEZ
		return 51;
	}
	else{
		exit(-12); //invalid instruction
	}
}

/*
//////////////////////////////////
/////FOR J TYPE INSTRUCTIONS /////
//////////////////////////////////
*/

int j_find_operation(uint32_t opcode){
  if(opcode == 0b000010){  //j
    return 51;
  }
  else if(opcode == 0b000011){  //jal
    return 52;
  }
	else {
		exit(-12);
	}
}

uint32_t get_imm(uint32_t instruction){
	return instruction&0b00000011111111111111111111111111;
}

/*
//////////////////////////////////
/////EXECUTING THE OPERATIONS ////
//////////////////////////////////
*/

uint32_t r_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next) {
	uint32_t a = registers[get_source_one(instruction)];
	uint32_t a_register_num = get_source_one(instruction);
	uint32_t b = registers[get_source_two(instruction)];
	uint32_t dest = get_dest_r(instruction);
	uint32_t sa = get_shift_amt(instruction);
	switch(operation) {
		case 1: //ADD
			{
				registers[dest] = r_add(a, b);
				break;
			}
		case 2: //ADDU
			{
				registers[dest] = r_addu(a, b);
				break;
			}
		case 3: //AND
			{
				registers[dest] = r_and(a, b);
				break;
			}
		case 4: //DIV
			{
				r_div(a, b, hi, lo);
				break;
			}
		case 5: //DIVU
			{
				r_divu(a, b, hi, lo);
				break;
			}
		case 6: //JR
			{
				pc_next = r_jr(a, pc, a_register_num);
				check_instruction_access(pc_next);
				return pc+=4;
			}
		case 7: //JALR
			{
				pc_next = r_jalr(a, pc, registers[dest], a_register_num, dest);
				check_instruction_access(pc_next);
				return pc+=4;
			}
		case 8: //MULT
			{
				r_mult(a, b, hi, lo);
				break;
			}
		case 9: //MULTU
			{
				r_multu(a, b, hi, lo);
				break;
			}
		case 10: //MFLO
			{
				registers[dest] = r_mflo(lo);
				break;
			}
		case 11: //MFHI
			{
				registers[dest] = r_mfhi(hi);
				break;
			}
		case 12: //MTLO
			{
				lo = r_mtlo(a);
				break;
			}
		case 13: //MTHI
			{
				hi = r_mthi(a);
				break;
			}
		case 14: //OR
			{
				registers[dest] = r_or(a, b);
				break;
			}
		case 15: //SLL
			{
				registers[dest] = r_sll(b, sa);
				break;
			}
		case 16: //SLLV
			{
				registers[dest] = r_sllv(a, b);
				break;
			}
		case 17: //SRAV
			{
				registers[dest] = r_srav(a, b);
				break;
			}
		case 18:  //SRA
			{
				registers[dest] = r_sra(b, sa);
				break;
			}
		case 19: //SRL
			{
				registers[dest] = r_srl(b, sa);
				break;
			}
		case 20:  //SRLV
			{
				registers[dest] = r_srlv(a, b);
				break;
			}
		case 21:  //SUB
			{
				registers[dest] = r_sub(a, b);
				break;
			}
		case 22: //SUBU
			{
				registers[dest] = r_subu(a, b);
				break;
			}
		case 23: //SLT
			{
				registers[dest] = r_slt(a, b);
				break;
			}
		case 24:
			{
				registers[dest] = r_sltu(a, b);
				break;
			}
		case 25: //XOR
			{
				registers[dest] = r_xor(a, b);
				break;
			}
	}
	pc = pc_next;
	pc_next+=4;
	return pc;
}

uint32_t i_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next, std::vector<uint8_t> &memory){
	uint32_t a = registers[get_source_one(instruction)];
	uint32_t b = registers[get_source_two(instruction)];
	uint32_t dest = get_dest_i(instruction);
	uint32_t imm = get_immediate_const(instruction);
	switch(operation){
		case 26: //ADDI
		{
			registers[dest] = i_addi(a, imm);
			break;
		}
		case 27: //ADDIU
		{
			registers[dest] = i_addiu(a, imm);
			break;
		}
		case 28: //ANDI
		{
			registers[dest] = i_andi(a, imm);
			break;
		}
		case 29: //ORI
		{
			registers[dest] = i_ori(a, imm);
			break;
		}
		case 30: //XORI
		{
			registers[dest] = i_xori(a, imm);
			break;
		}
		case 31: //SLTI
		{
			registers[dest] = i_slti(a, imm);
			break;
		}
		case 32: //SLTIU
		{
			registers[dest] = i_sltiu(a, imm);
			break;
		}
		case 33: //BEQ
		{
			i_beq(a, b, imm, pc, pc_next);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 34: //BNE
		{
			i_bne(a, b, imm, pc, pc_next);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 35: //LB
		{
			check_read_access(a + imm);
			registers[dest] = i_lb(a, imm, memory);
			break;
		}
		case 36: //LBU
		{
			check_read_access(a + imm);
			registers[dest] = i_lbu(a, imm, memory);
			break;
		}
		case 38: //LH
		{
			check_read_access(a + imm);
			registers[dest] = i_lh(a, imm, memory);
			break;
		}
		case 37: //LHU
		{
			check_read_access(a + imm);
			registers[dest] = i_lhu(a, imm, memory);
			break;
		}
		case 39: //LW
		{
			check_read_access(a + imm);
			registers[dest] = i_lw(a, imm, memory);
			break;
		}
		case 40: //SB
		{
			check_write_access(a + imm);
			i_sb(b, a, imm, memory);
			break;
		}
		case 41: //SH
		{
			check_write_access(a + imm);
			i_sh(a, b, imm, memory);
			break;
		}
		case 42: //SW
		{
			check_write_access(a + imm);
			i_sw(a, b, imm, memory);
			break;
		}
		case 43: //BGEZ
		{
			pc_next = i_bgez(a, imm, pc);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 44: //BGEZAL
		{
			i_bgezal(a, imm, pc, pc_next, registers[31]);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 45: //BLTZ
		{
			pc_next = i_bltz(a, imm, pc);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 46: //BLTZAL
		{
			i_bltzal(a, imm, pc, pc_next, registers[31]);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 47: //BGTZ
		{
			pc_next = i_bgtz(a, imm, pc);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 48: //LUI
		{
			registers[dest] = i_lui(imm);
			break;
		}
		case 49: //LWR
		{
			check_read_access(a + imm);
			registers[dest] = i_lwr(a, imm, memory);
			break;
		}
		case 50: //LWL
		{
			check_read_access(a + imm);
			registers[dest] = i_lwl(a, imm, memory);
			break;
		}
		case 51: //BLEZ
		{
			pc_next = i_blez(a, imm, pc);
			check_instruction_access(pc_next);
			//printf("pc_next = %X\n", pc_next);
			return pc+=4;
		}
	}
	pc = pc_next;
	pc_next+=4;
	return pc;
}

uint32_t j_execute_operation(int operation, uint32_t instruction, std::vector<uint32_t> &registers, uint32_t &hi, uint32_t &lo, uint32_t pc, uint32_t &pc_next){
	uint32_t imm = get_imm(instruction);
	switch(operation){
		case 51: //J
		{
			pc_next = j_j(imm);
			check_instruction_access(pc_next);
			return pc+=4;
		}
		case 52: //JAL
		{
			pc_next = j_jal(imm, registers[31], pc);
			check_instruction_access(pc_next);
			return pc+=4;
		}
	}
}
