
./bin/mips_simulator test/J_1
CODE=$?
echo -n "j_1, j_1 "
if [ "$CODE" == 2 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING J WORKS NORMALLY"

./bin/mips_simulator test/J_2
CODE=$?
echo -n "J_2, J_2 "
if [ "$CODE" == 4 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING J CARRIES OUT THE INSTRUCITON AFTER THE JUMP"

./bin/mips_simulator test/JAL_1
CODE=$?
echo -n "JAL_1, JAL_1 "
if [ "$CODE" == 9 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING JAL WORKS NORMALLY AND CARRIES OUT INSTRUCTION AFTER JUMP"

./bin/mips_simulator test/JAL_2
CODE=$?
echo -n "JAL_2, JAL_2 "
if [ "$CODE" == 244 ]; then
  echo -n "Pass, "
else
  echo -n "Fail, "
fi
echo "eh1618,   TESTING JAL CAN'T JUMP TO NON-EXISTANT PLACE"
