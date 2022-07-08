#This is a program to find the greatest of two numbers

echo "Enter Num1"
read num1
echo "Enter Num2"
read num2
if [ $num1 -gt $num2 ]  #-gt stands for greater then
then 
	echo $num1 is the greater number
else
	echo $num2 is the greater number
fi
