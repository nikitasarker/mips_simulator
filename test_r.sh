# # !/bin/bash

./bin/mips_simulator test/ADD_1
CODE=$?
echo -n "ADD_1, ADD, "
if [ "$CODE" == 3 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Add 1 to 2"

./bin/mips_simulator test/ADD_2
CODE=$?
echo -n "ADD_2, ADD, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,  Testing Overflow"

./bin/mips_simulator test/ADD_3
CODE=$?
echo -n "ADD_3, ADD, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Testing Overflow"

./bin/mips_simulator test/ADD_4
CODE=$?
echo -n "ADD_4, ADD, "
if [ "$CODE" == 253 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Add -1 to -2"

./bin/mips_simulator test/SUB_1
CODE=$?
echo -n "SUB_1, SUB, "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   SUB 1 from 3"

./bin/mips_simulator test/SUB_2
CODE=$?
echo -n "SUB_2, SUB, "
if [ "$CODE" == 254 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   SUB 3 from 1"

./bin/mips_simulator test/SUB_3
CODE=$?
echo -n "SUB_3, SUB, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Testing Overflow"

./bin/mips_simulator test/ADDU_1
CODE=$?
echo -n "ADDU_1, ADDU, "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Add 3 to 1"

./bin/mips_simulator test/ADDU_2
CODE=$?
echo -n "ADDU_2, ADDU, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Testing Overflow"

./bin/mips_simulator test/ADDU_3
CODE=$?
echo -n "ADDU_3, ADDU, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Testing if addition is unsigned"

./bin/mips_simulator test/AND_1
CODE=$?
echo -n "AND_1, AND, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   testing AND with 5 and 1"

./bin/mips_simulator test/AND_2
CODE=$?
echo -n "AND_2, AND, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   testing AND with 0"

./bin/mips_simulator test/DIV_1
CODE=$?
echo -n "DIV_1, DIV, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   testing remainder when 5/2"

./bin/mips_simulator test/DIV_2
CODE=$?
echo -n "DIV_2, DIV, "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   testing quotient when 5/2"

./bin/mips_simulator test/DIV_3
CODE=$?
echo -n "DIV_3, DIV, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   testing devide by zero"

./bin/mips_simulator test/DIVU_1
CODE=$?
echo -n "DIVU_1, DIVU, "
if [ "$CODE" == 49 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   dividing -10 by 5"

./bin/mips_simulator test/DIVU_2
CODE=$?
echo -n "DIVU_2, DIVU, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Testing unsigned division" #not too sure

./bin/mips_simulator test/DIVU_3
CODE=$?
echo -n "DIVU_3, DIVU, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   dividing by zero"

./bin/mips_simulator test/MULT_1
CODE=$?
echo -n "MULT_1, MULT, "
if [ "$CODE" == 10 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   MULTIPLYING 5 BY 2"

./bin/mips_simulator test/MULT_2
CODE=$?
echo -n "MULT_2, MULT, "
if [ "$CODE" == 251 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   MULTIPLYING 5 BY -1"

./bin/mips_simulator test/MULT_3
CODE=$?
echo -n "MULT_3, MULT, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING HI REGISTERS WORKS IN MULTIPLICATION"
#
./bin/mips_simulator test/MULTU_1
CODE=$?
echo -n "MULTU_1, MULTU, "
if [ "$CODE" == 254 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING UNSIGNED MULTIPLICATION FOR NO OVERFLOWS"

./bin/mips_simulator test/MULTU_2
CODE=$?
echo -n "MULTU_2, MULTU, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING ANSWER ON HI REGISTER"

./bin/mips_simulator test/MULTU_3
CODE=$?
echo -n "MULTU_3, MULTU, "
if [ "$CODE" == 10 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING ON NORMAL CASE OF 5 TIMES 5"

./bin/mips_simulator test/MFHI_1
CODE=$?
echo -n "MFHI_1, MFHI, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING HI REGISTERS WORKS IN MULTIPLICATION"

./bin/mips_simulator test/MFLO_1
CODE=$?
echo -n "MFLO_1, MFLO, "
if [ "$CODE" == 10 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING MOVE TO LO REGISTER"

./bin/mips_simulator test/MTHI_1
CODE=$?
echo -n "MTHI_1, MTHI, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING MOVE TO HI REGISTER"

./bin/mips_simulator test/MTLO_1
CODE=$?
echo -n "MTLO_1, MTLO, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING MOVE TO HI REGISTER"

./bin/mips_simulator test/OR_1
CODE=$?
echo -n "OR_1, OR, "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING OR"

./bin/mips_simulator test/SLL_1
CODE=$?
echo -n "SLL_1, SLL, "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LOGICAL SHIFT LEFT"

./bin/mips_simulator test/SLL_2
CODE=$?
echo -n "SLL_2, SLL, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING ARITHMETIC ERROR"

./bin/mips_simulator test/SLLV_1
CODE=$?
echo -n "SLLV_1, SLLV, "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LOGICAL SHIFT LEFT WITH VARIABLES"

./bin/mips_simulator test/SLLV_2
CODE=$?
echo -n "SLLV_2, SLLV, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LOGICAL SHIFT LEFT WITH VARIABLES SHOULD BE ARITHMETIC ERROR"

./bin/mips_simulator test/SRAV_1
CODE=$?
echo -n "SRAV_1, SRAV, "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT ARITHMETIC SHIFT WITH VARIABLES"

./bin/mips_simulator test/SRAV_2
CODE=$?
echo -n "SRAV_2, SRAV, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT ARITHMETIC SHIFT WITH VARIABLES SHOULD BE ARITHMETIC ERROR"

./bin/mips_simulator test/SRA_1
CODE=$?
echo -n "SRA_1, SRA, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT ARITHMETIC SHIFT"

./bin/mips_simulator test/SRA_2
CODE=$?
echo -n "SRA_2, SRA, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT ARITHMETIC SHIFT SHOULD BE ARITHMETIC ERROR"

./bin/mips_simulator test/SRL_1
CODE=$?
echo -n "SRL_1, SRL, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT LOGICAL SHIFT"

./bin/mips_simulator test/SRL_2
CODE=$?
echo -n "SRL_2, SRL, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING RIGHT LOGICAL SHIFT TO MAKE SURE UNSIGNED"

./bin/mips_simulator test/SRL_3
CODE=$?
echo -n "SRL_3, SRL, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   SHOULD BE DATA ERROR"

./bin/mips_simulator test/SLT_1
CODE=$?
echo -n "SLT_1, SLT, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SET IF LESS THEN NORMALLY WORKS"

./bin/mips_simulator test/SLT_2
CODE=$?
echo -n "SLT_2, SLT, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SET IF LESS THEN WORKS WHEN BOTH VALUES THE SAME"

./bin/mips_simulator test/SLT_3
CODE=$?
echo -n "SLT_3, SLT, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SET IF LESS THEN NORMALLY WORKS WITH A MINUS NUMBER"

./bin/mips_simulator test/SLTU_1
CODE=$?
echo -n "SLTU_1, SLTU, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SET IF LESS THEN NORMALLY WORKS"

./bin/mips_simulator test/SLTU_2
CODE=$?
echo -n "SLTU_2, SLTU, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SET IF LESS THEN UNSIGNED NORMALLY WORKS WITH A MINUS NUMBER"

./bin/mips_simulator test/XOR_1
CODE=$?
echo -n "XOR_1, XOR, "
if [ "$CODE" == 31 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF XOR WORKS"


./bin/mips_simulator test/SKIP_NEXT
CODE=$?
echo -n "SKIP_NEXT, SKIPPING, "
if [ "$CODE" == 16 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF DOES NEXT INSTRUCTION AFTER SKIP"

./bin/mips_simulator test/JR_1
CODE=$?
echo -n "JR_1, JR, "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF JR WORKS"

./bin/mips_simulator test/JR_2
CODE=$?
echo -n "JR_2, JR, "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF PC IS HIGHER THEN EXPECTED FOR JR"

./bin/mips_simulator test/JALR_1
CODE=$?
echo -n "JALR_1, JALR, "
if [ "$CODE" == 24 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF JALR WORKS"

./bin/mips_simulator test/JALR_2
CODE=$?
echo -n "JALR_2, JALR, "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING IF JALR RETURNS AN ERROR"
