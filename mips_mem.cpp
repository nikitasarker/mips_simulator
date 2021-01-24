#include "mips_mem.h"

void load_to_mem(std::string binName, std::vector<uint8_t> &memory, uint32_t instr_memory_location) {
	long x;
	char *s;

	std::ifstream in;
	in.open(binName, std::ios::binary);

	if(!in.is_open()) {
		std::cout << "error, file cannot be opened" <<std::endl;
		exit(-21);
	}

	in.seekg(0,std::ios::end);
	x = in.tellg();
	in.seekg(0,std::ios::beg);

	s = new char[x];
	in.read(s,x);
	in.close();

	for(int i=0;i<x;i++){
		memory[i+instr_memory_location] = s[i];
	}

}
