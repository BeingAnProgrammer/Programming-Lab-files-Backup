#This is a shell program to find the greatest of three numbers

echo "Enter Num1"
read num1
echo "Enter Num2"
read num2
echo "Enter Num3"
read num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then 
	echo $num1 is the greatest number 
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ] 
then 
	echo $num2 is the greatest number
else
	echo $num3 is the greatest number
fi
