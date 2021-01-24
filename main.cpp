#include "mips_mem.h"
#include "decode.h"

int main(int argc, char *argv[]) {
	std::string binName = argv[1]; //get instruction binary

	//initialise whole memory;
	std::vector<uint8_t> memory;
	memory.resize(MEMORY_SIZE);

	uint32_t ADDR_INSTR = 0x10000000;

	//initialise registers
	std::vector<uint32_t> registers(32, 0); //initialising all registers to 0
	uint32_t hi = 0;  //initialising hi and lo registers
	uint32_t lo = 0;	//this may change


	//load to instr_memory
	load_to_mem(binName, memory, ADDR_INSTR);

	//allocate program counter
	uint32_t pc = ADDR_INSTR; //point program counter to first instruction
	uint32_t pc_next = ADDR_INSTR + 4;

	//while there are instructions to execute, read instructions
	while(pc!=0) {
		uint32_t instruction = read_instruction(pc, memory);
		pc = execute_instruction(pc, pc_next, registers, hi, lo, instruction, memory);
	}

	int return_code = registers[2] & 0b00000000000000000000000011111111; //initialising 8 LSB from register 2 as exit code
	exit(return_code);
}
