#include <vector>
#include <iostream>
#include <fstream>
#include <string>

const uint32_t MEMORY_SIZE = 0x40000000;

const uint32_t ADDR_NULL = 0;
const uint32_t NULL_SIZE = 0x4;

void load_to_mem(std::string binName, std::vector<uint8_t> &memory, uint32_t instr_memory_location);
