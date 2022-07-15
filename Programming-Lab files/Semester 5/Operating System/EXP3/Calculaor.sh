#This a program for a basic calculator
echo "Menu Based Calculator"
echo "Enter the Operands"
read a
read b
echo "Enter the operator"
read o
case $o in
"+") echo "$a + $b" = $(($a + $b));;
"-") echo "$a + $b" = $(($a - $b));;
"*") echo "$a + $b" = $(($a * $b));;
"/") echo "$a + $b" = $(($a / $b));;
*) echo "Invalid Operation"
esac
