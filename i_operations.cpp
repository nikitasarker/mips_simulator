#include "i_operations.h"

int32_t i_addi(int32_t a, int32_t b){
  int32_t sum = a + b;
 	if ((a >= 0 && sum < b) || (a < 0 && sum > b)){
		exit(-10); //arithmetic error, overflow
	}
	else{
		return sum;
	}
}

uint32_t i_addiu(uint32_t a, uint32_t b){
  uint32_t sum = a + b;
 	if ((a >= 0 && sum < b) || (a < 0 && sum > b)){
		exit(-10); //arithmetic error, overflow
	}
	else{
		return sum;
	}
}

uint32_t i_andi(int32_t a, int32_t b){
  return(a&b);
}

uint32_t i_ori(int32_t a, int32_t b){
  return (a|b);
}

int32_t i_xori(int32_t a, int32_t b){
  return a^b;
}

int32_t i_slti(int32_t a, int32_t b){
  if(a<b){
    return 0b1;
  }
  else{
    return 0b0;
  }
}

uint32_t i_sltiu(uint32_t a, uint32_t b){
  if(a<b){
    return 0b1;
  }
  else{
    return 0b0;
  }
}

int32_t i_lb(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  uint32_t addr = a+imm;
  uint32_t byte = memory[addr];
  if(addr >= 0x30000000 && addr < 0x30000004) {
    return(get_c(addr));
  }
  if((byte>>7) == 1){
    return(byte|0b11111111111111111111111100000000);
  }
  return (byte);
}

uint32_t i_lbu(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  uint32_t addr = a+imm;
  if(addr >= 0x30000000 && addr < 0x30000004) {
    return(get_c(addr));
  }
  return (memory[addr]);
}

int32_t i_lh(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  uint32_t addr = a+imm;
  if((addr)%2!=0) {
    exit(-11);
  }
  if(addr >= 0x30000000 && addr < 0x30000004) {
    return(get_c(addr));
  }
  uint32_t half_word_sign = (memory[addr] >> 7);
  if (half_word_sign == 1){
    return((uint32_t) memory[addr] << 8 |
    (uint32_t) memory[addr+1] << 0 |0b11111111111111110000000000000000);
  }
  return(
    (uint32_t) memory[addr] << 8 |
    (uint32_t) memory[addr+1] << 0
  );
}

uint32_t i_lhu(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  uint32_t addr = a+imm;
  if((addr)%2!=0) {
    exit(-11);
  }
  if(addr >= 0x30000000 && addr < 0x30000004) {
    return(get_c(addr));
  }
  return(
    (uint32_t) memory[addr] << 8 |
    (uint32_t) memory[addr+1] << 0
  );
}

int32_t i_lw(int32_t a, int32_t imm, std::vector<uint8_t> &memory){
  uint32_t addr = a+imm;
  if((addr)%4!=0) {
    exit(-11);
  }
  if(addr >= 0x30000000 && addr < 0x30000004) {
    return(get_c(addr));
  }
  return (
		((uint32_t) memory[addr]) << 24 |
		((uint32_t) memory[addr+1]) << 16 |
		((uint32_t) memory[addr+2]) << 8 |
		((uint32_t) memory[addr+3]) << 0
	);
}

void i_sb(uint32_t b, uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  if((a+imm) >= 0x30000004 && (a+imm) < 0x30000008) {
    putchar(b&0x000000ff);
  }
  memory[a+imm] = b&0xff;
}

void i_sh(uint32_t base, uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  if((base+imm)%2!=0) {
    exit(-11);
  }
  if((base+imm) >= 0x30000004 && (base+imm) < 0x30000008) {
    putchar(a&0x000000ff);
  }
  int8_t a_lsb = (a&0b11111111);
  int8_t a_msb = (a>>8);
  memory[base+imm] = a_msb;
  memory[base+imm+1] = a_lsb;
}

void i_sw(uint32_t base, uint32_t a, uint32_t offset, std::vector<uint8_t> &memory){
  if((base+offset)%4!=0) {
    exit(-11);
  }
  if((base+offset) >= 0x30000004 && (base+offset) < 0x30000008) {
    putchar(a&0x000000ff);
  }
  int8_t a_msb = (a>>24);
  int8_t a_lmsb = ((a>>16) & 0b11111111);
  int8_t a_mlsb = ((a>>8) & 0b11111111);
  int8_t a_lsb = (a & 0b11111111);
  memory[base+offset] = a_msb;
  memory[base+offset+1] = a_lmsb;
  memory[base+offset+2] = a_mlsb;
  memory[base+offset+3] = a_lsb;
}

void i_beq(int32_t a, int32_t b, int32_t offset, uint32_t pc, uint32_t &pc_next){
  if(a==b){
    pc_next = pc+(0x4+(offset << 2));
  }
  else{
    pc_next+=4;
  }
}

uint32_t i_bne(int32_t a, int32_t b, int32_t offset, uint32_t pc, uint32_t &pc_next){
  if(a!=b){
    pc_next = pc+(0x4+(offset << 2));
  }
  else{
    pc_next+=4;
  }
}

uint32_t i_bgez(int32_t a, int32_t offset, uint32_t pc){
  if(a>=0) {
    return (pc+(offset<<2)+4);
  }
  return pc+=8;
}

void i_bgezal(int32_t a, int32_t imm, uint32_t pc, uint32_t &pc_next, uint32_t &ra_register){
  if(a>=0){
    ra_register = pc+8;
    pc_next = pc + ((imm<<2)+0x4);
  }
}

void i_bltzal(int32_t a, int32_t imm, uint32_t pc, uint32_t &pc_next, uint32_t &ra_register){
  if(a<0){
    ra_register = pc+8;
    pc_next = pc + ((imm<<2)+0x4);
  }
}

uint32_t i_blez(int32_t a, int32_t offset, uint32_t pc){
  if(a<=0){
    return (pc+(offset<<2)+4);
  }
  return pc+=8;
}

uint32_t i_bgtz(int32_t a, int32_t offset, uint32_t pc){
  if(a>0){
    return pc+(offset<<2)+4;
  }
  return pc+=8;
}

uint32_t i_bltz(int32_t a, int32_t offset, uint32_t pc){
  if(a<0){
    return pc+(offset<<2)+4;
  }
  return pc+=8;
}

uint32_t i_lui(uint32_t imm){
  return(imm<<16);
}

uint32_t i_lwr(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  if((a+imm)%4 == 0){
    return (memory[a+imm]);
  }
  else if((a+imm)%4 == 1){
    uint32_t tmp = (memory[a+imm]);
    tmp = tmp + (memory[a+imm-1] << 8);
    return (tmp);
  }
  else if((a+imm)%4 == 2){
    uint32_t tmp = memory[a+imm];
    tmp = tmp + (memory[a+imm-0x1] << 8);
    tmp = tmp + (memory[a+imm-0x2] << 16);
    return (tmp);
  }
  else{
    uint32_t tmp = memory[a+imm];
    tmp = tmp + (memory[a+imm-1] << 8);
    tmp = tmp + (memory[a+imm-2] << 16);
    tmp = tmp + (memory[a+imm-3] << 24);
    return (tmp);
  }
}

uint32_t i_lwl(uint32_t a, uint32_t imm, std::vector<uint8_t> &memory){
  if((a+imm)%4 == 0){
    uint32_t tmp = (memory[a+imm] << 24);
    tmp = tmp + (memory[a+imm+0x1] >> 16);
    tmp = tmp + (memory[a+imm+0x2] >> 8);
    tmp = tmp + (memory[a+imm+0x3]);
  }
  else if((a+imm)%4 == 1){
    uint32_t tmp = memory[a+imm] << 24;
    tmp = tmp + (memory[a+imm+0x1] << 16);
    tmp = tmp + (memory[a+imm+0x2] << 8);
    return (tmp);
  }
  else if((a+imm)%4 == 2){
    uint32_t tmp = memory[a+imm] << 24;
    tmp = tmp + (memory[a+imm+0x1] << 16);
    return (tmp);
  }
  else{
    uint32_t tmp = memory[a+imm] << 24;
    return (tmp);
  }
}

uint32_t get_c(uint32_t address){
  int8_t val = std::getchar();
  uint32_t tmp_t = static_cast<uint32_t> (val);
  if((tmp_t>>7) == 1){
    return(tmp_t |0xFFFFFF00);
  }
  else{
    return(tmp_t);
  }
}
