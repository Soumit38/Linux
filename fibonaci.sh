echo "Enter How many numbers:"
read num
num1=0
num2=1
echo "Fibonacci Series:"
echo $num1
echo $num2
count=2
while (($count <= $num))
do
num3=`expr $num1 + $num2`
echo $num3
num1=$num2
num2=$num3
count=`expr $count + 1`
done

