#include "r_operations.h"

int32_t r_add(int32_t a, int32_t b) {
	int32_t sum = a + b;
 	if ((a >= 0 && sum < b) || (a < 0 && sum > b)){
		exit(-10); //arithmetic error, overflow
	}
	else{
		return sum;
	}
}

uint32_t r_addu(uint32_t a, uint32_t b) {
	uint32_t sum = a + b;
 	if ((a >= 0 && sum < b) || (a < 0 && sum > b)){
		exit(-10); //arithmetic error, overflow
	}
	else{
		return (a+b);
	}
}

int32_t r_and(int32_t a, int32_t b) {
	return a&b;
}

void r_div(int32_t a, int32_t b, uint32_t &hi, uint32_t &lo){
	if (b == 0){
		exit(-10);
	}
	lo = a/b;
	hi = a%b;
}

void r_mult(int32_t a, int32_t b, uint32_t &hi, uint32_t &lo) {
	int64_t tmp_a = a;
	int64_t tmp_b = b;
	int64_t mult_answer = tmp_a*tmp_b;
	hi = mult_answer >> 32;
	lo = mult_answer & 0b11111111111111111111111111111111;
}

void r_divu(uint32_t a, uint32_t b, uint32_t &hi, uint32_t &lo){
	if (b == 0){
		exit(-10);
	}
	lo = a/b;
	hi = a%b;
}

void r_multu(uint32_t a, uint32_t b, uint32_t &hi, uint32_t &lo){
	uint64_t tmp_a = a;
	uint64_t tmp_b = b;
	uint64_t mult_answer = tmp_a*tmp_b;
	hi = mult_answer >> 32;
	lo = mult_answer&0b11111111111111111111111111111111;
}

int32_t r_or(int32_t a, int32_t b){
	return a|b;
}

uint32_t r_sll(uint32_t b, uint32_t sa){ //shifts zeros in as LSBs
	if (sa == 0){
		exit(-10);   //error due to shifting for longer then the word
	}
	else{
		return (b << sa);
	}
}

uint32_t r_sllv(uint32_t a, uint32_t b){
	if (a >= 32){
		exit(-10);   //error due to shifting for longer then the word
	}
	else{
		return (b << a);
	}
}

int32_t r_srav(int32_t a, int32_t b){
	if (a >= 32){
		exit(-10);   //error due to shifting for longer then the
	}
	else{
		return (b >> a);
	}
}

int32_t r_sra(int32_t b, int32_t sa){
	if(sa == 0){
		exit(-10);   //error due to shifting for longer then the word
	}
	else{
		return (b >> sa);
	}
}

uint32_t r_srl(uint32_t b, uint32_t sa){
	if (sa == 0){
		exit(-10);   //error due to shifting for longer then the word
	}
	else{
		return (b >> sa);
	}
}

uint32_t r_srlv(uint32_t a, uint32_t b){
	if (a >= 32){
		exit(-10);   //error due to shifting for longer then the word
	}
	else{
		return (b >> a);
	}
}

uint32_t r_subu(uint32_t a, uint32_t b){
	uint64_t tmp_a = a;
	uint64_t tmp_b = b;
	uint64_t tmp = tmp_a - tmp_b;
	if((tmp >> 32) >= 1){
		exit(-10);  //overflow
	}
	return (a-b);
}

int32_t r_sub(int32_t a, int32_t b){
	int32_t sum = a-b;
	if((b >= a && sum > 0)){
		exit(-10);
	}
	return (a-b);
}

int32_t r_xor(int32_t a, int32_t b){
	return a^b;
}

int32_t r_slt(int32_t a, int32_t b){
	if(a < b){
		return 1;
	}
	else{
		return 0;
	}
}

uint32_t r_sltu(uint32_t a, uint32_t b){
	if(a < b){
		return 0b1;
	}
	else{
		return 0b0;
	}
}

uint32_t r_jr(uint32_t a, uint32_t pc, uint32_t a_register_num){
	if(a_register_num==0){
		return(0);
	}
	return(a);
}

uint32_t r_jalr(uint32_t a, uint32_t pc, uint32_t& ra_register, uint32_t a_register_num, uint32_t ra_register_num){
	if(a_register_num == ra_register_num){
		exit(-12); //can't have this
	}
	ra_register = pc + 8;
	return(a);
}

uint32_t r_mflo(uint32_t& lo){
	return(lo);
}

uint32_t r_mfhi(uint32_t& hi){
	return(hi);
}

uint32_t r_mtlo(uint32_t a){
	return(a);
}

uint32_t r_mthi(uint32_t a){
	return(a);
}
