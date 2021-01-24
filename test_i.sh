!/bin/bash

./bin/mips_simulator test/ADDI_1
CODE=$?
echo -n "ADDI_1, ADDI, "
if [ "$CODE" == 15 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Add 15 TO REGISTER V0"

./bin/mips_simulator test/ADDI_2
CODE=$?
echo -n "ADDI_2, ADDI, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING OVERFLOW"

./bin/mips_simulator test/ADDIU_1
CODE=$?
echo -n "ADDIU_1, ADDIU, "
if [ "$CODE" == 15 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   Add 15 TO REGISTER V0"

./bin/mips_simulator test/ADDIU_2
CODE=$?
echo -n "ADDIU_2, ADDIU, "
if [ "$CODE" == 246 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING OVERFLOW"

./bin/mips_simulator test/ANDI_1
CODE=$?
echo -n "ANDI_1, ANDI, "
if [ "$CODE" == 15 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING AND"

./bin/mips_simulator test/ANDI_2
CODE=$?
echo -n "ANDI_2, ANDI, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING AND WITH ZERO"

./bin/mips_simulator test/ORI_1
CODE=$?
echo -n "ORI_1, ORI, "
if [ "$CODE" == 15 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING OR"

./bin/mips_simulator test/ORI_2
CODE=$?
echo -n "ORI_2, ORI, "
if [ "$CODE" == 15 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING OR"

./bin/mips_simulator test/XORI_1
CODE=$?
echo -n "XORI_1, XORI, "
if [ "$CODE" == 254 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING XOR"

./bin/mips_simulator test/XORI_2
CODE=$?
echo -n "XORI_2, XORI, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING XOR WITH ALL ONES"

./bin/mips_simulator test/SLTI_1
CODE=$?
echo -n "SLTI_1, SLTI, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SLTI NORMALLY"

./bin/mips_simulator test/SLTI_2
CODE=$?
echo -n "SLTI_2, SLTI, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SLTI WHEN NEGATIVES"

./bin/mips_simulator test/SLTIU_1
CODE=$?
echo -n "SLTIU_1, SLTIU, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SLTIU NORMALLY"

./bin/mips_simulator test/SLTIU_2
CODE=$?
echo -n "SLTIU_2, SLTIU, "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SLTIU WITH NEGATIVES"

./bin/mips_simulator test/BEQ_1
CODE=$?
echo -n "BEQ_1, BEQ, "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BEQ NORMALLY"

./bin/mips_simulator test/BEQ_2
CODE=$?
echo -n "BEQ_2, BEQ "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BEQ WHEN NOT EQUAL"

./bin/mips_simulator test/SLTI_1
CODE=$?
echo -n "SLTI_1, SLTI, "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SLTI NORMALLY"

./bin/mips_simulator test/BNE_1
CODE=$?
echo -n "BNE_1, BNE "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BNE NORMALLY"

./bin/mips_simulator test/BNE_2
CODE=$?
echo -n "BNE_2, BNE "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BNE WHEN EQUAL"

./bin/mips_simulator test/LB_1
CODE=$?
echo -n "LB_1, LB "
if [ "$CODE" == 16 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LB NORMALLY"

./bin/mips_simulator test/LB_2
CODE=$?
echo -n "LB_2, LB "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LB SIGN EXTENTION"

./bin/mips_simulator test/LB_3
CODE=$?
echo -n "LB_3, LB "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "ns5618,  LB attempts to access illegal memory location"

./bin/mips_simulator test/LBU_1
CODE=$?
echo -n "LBU_1, LBU "
if [ "$CODE" == 16 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LBU NORMALLY"

./bin/mips_simulator test/LBU_2
CODE=$?
echo -n "LBU_2, LBU "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LB SIGN EXTENTION"

./bin/mips_simulator test/LBU_3
CODE=$?
echo -n "LBU_3, LBU "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   LB attempts to access illegal memory location"

./bin/mips_simulator test/LH_1
CODE=$?
echo -n "LH_1, LH "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LH NORMALLY"

./bin/mips_simulator test/LH_2
CODE=$?
echo -n "LH_2, LH "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LH SIGN EXTENTION"

./bin/mips_simulator test/LH_3
CODE=$?
echo -n "LH_3, LH "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   LH attempts to read illegal memory address"

./bin/mips_simulator test/LHU_1
CODE=$?
echo -n "LHU_1, LHU "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LHU NORMALLY"

./bin/mips_simulator test/LHU_2
CODE=$?
echo -n "LHU_2, LHU "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LHU SIGN EXTENTION"

./bin/mips_simulator test/LHU_3
CODE=$?
echo -n "LHU_3, LHU "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   LH attempt to read from illegal memory address"

./bin/mips_simulator test/LW_1
CODE=$?
echo -n "LW_1, LW "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LW NORMALLY"

./bin/mips_simulator test/LW_2
CODE=$?
echo -n "LW_2, LW "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LW RETURN AN ERROR"

./bin/mips_simulator test/SB_1
CODE=$?
echo -n "SB_1, SB "
if [ "$CODE" == 16 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SB NORMALLY"

./bin/mips_simulator test/SB_2
CODE=$?
echo -n "SB_2, SB "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SB SIGN EXTENTION"

./bin/mips_simulator test/SB_3
CODE=$?
echo -n "SB_3, SB "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SB SHOULD RETURN AN ERROR"

./bin/mips_simulator test/SH_1
CODE=$?
echo -n "SH_1, SH "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SH NORMALLY"

./bin/mips_simulator test/SH_2
CODE=$?
echo -n "SH_2, SH "
if [ "$CODE" == 255 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SH SIGN EXTENTION"

./bin/mips_simulator test/SH_3
CODE=$?
echo -n "SH_3, SH "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING SH RETURN AN ERROR"

./bin/mips_simulator test/SW_1
CODE=$?
echo -n "SW_1, SW "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   SW stores correct value in correct location"

./bin/mips_simulator test/SW_2
CODE=$?
echo -n "SW_2, SW "
if [ "$CODE" == 245 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   SW attempts to write to illegal memory location"

./bin/mips_simulator test/BGEZ_1
CODE=$?
echo -n "BGEZ_1, BGEZ "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ TAKES THE BRANCH"

./bin/mips_simulator test/BGEZ_2
CODE=$?
echo -n "BGEZ_2, BGEZ "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ TAKES THE BRANCH"

./bin/mips_simulator test/BGEZ_3
CODE=$?
echo -n "BGEZ_3, BGEZ "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/BGEZAL_1
CODE=$?
echo -n "BGEZAL_1, BGEZAL "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZAL TAKES THE BRANCH"

./bin/mips_simulator test/BGEZAL_2
CODE=$?
echo -n "BGEZAL_2, BGEZAL "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZAL DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/BLEZ_1
CODE=$?
echo -n "BLEZ_1, BLEZ "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/BLEZ_2
CODE=$?
echo -n "BLEZ_2, BLEZ "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ TAKES THE BRANCH"

./bin/mips_simulator test/BLEZ_3
CODE=$?
echo -n "BLEZ_3, BLEZ "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZ TAKES THE BRANCH"

./bin/mips_simulator test/BLTZAL_1
CODE=$?
echo -n "BLTZAL_1, BLTZAL "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZAL DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/BLTZAL_2
CODE=$?
echo -n "BLTZAL_2, BLTZAL "
if [ "$CODE" == 1 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGEZAL TAKES THE BRANCH"

./bin/mips_simulator test/BGTZ_1
CODE=$?
echo -n "BGTZ_1, BGTZ "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGTZ TAKES THE BRANCH"

./bin/mips_simulator test/BGTZ_2
CODE=$?
echo -n "BGTZ_1, BGTZ "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGTZ DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/BGTZ_3
CODE=$?
echo -n "BGTZ_3, BGTZ "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BGTZ DOESN'T TAKES THE BRANCH"

./bin/mips_simulator test/LUI_1
CODE=$?
echo -n "LUI_1, LUI "
if [ "$CODE" == 0 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LUI WORKS NORMALLY"

./bin/mips_simulator test/LUI_2
CODE=$?
echo -n "LUI_2, LUI "
if [ "$CODE" == 17 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LUI WORKS NORMALLY"

./bin/mips_simulator test/BLTZ_1
CODE=$?
echo -n "BLTZ_1, BLTZ "
if [ "$CODE" == 11 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BLTZ WORKS NORMALLY"

./bin/mips_simulator test/BLTZ_2
CODE=$?
echo -n "BLTZ_2, BLTZ "
if [ "$CODE" == 117 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING BLTZ DOESN'T TAKE THE BRANCH"

./bin/mips_simulator test/LWR_1
CODE=$?
echo -n "LWR_1, LWR "
if [ "$CODE" == 3 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LWR WORKS NORMALLY"

./bin/mips_simulator test/LWR_2
CODE=$?
echo -n "LWR_2, LWR "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LWR CAN'T READ FROM PUT_CHAR"

./bin/mips_simulator test/LWL_1
CODE=$?
echo -n "LWL_1, LWL "
if [ "$CODE" == 5 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LWL WORKS NORMALLY"

./bin/mips_simulator test/LWL_2
CODE=$?
echo -n "LWL_2, LWL "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING LWL CAN'T READ FROM PUT_CHAR"
