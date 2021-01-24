simulator: mips_mem.o decode.o r_operations.o i_operations.o j_operations.o main.o
	mkdir -p bin
	g++ mips_mem.o decode.o r_operations.o i_operations.o j_operations.o main.o -o bin/mips_simulator

mips_mem.o: mips_mem.cpp mips_mem.h
	g++ -c mips_mem.cpp

decode.o: decode.cpp decode.h
	g++ -c decode.cpp

r_operations.o: r_operations.cpp r_operations.h
		g++ -c r_operations.cpp

i_operations.o: i_operations.cpp i_operations.h
		g++ -c i_operations.cpp

j_operations.o: j_operations.cpp j_operations.h
	g++ -c j_operations.cpp

main.o: main.cpp
	g++ -c main.cpp

run:
	./bin/mips_simulator

clean:
	rm *.o bin/mips_simulator

testbench:
	
