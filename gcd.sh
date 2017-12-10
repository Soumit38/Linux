echo "Enter two number"
read num1 num2
m=$num1
if(($num2<$num1))
then
m=$num2
fi
while(($m!=0))
do
x=`expr $num1 % $m`
y=`expr $num2 % $m`
if(($x==0 && $y==0))
then
echo "GCD of $num1 and $num2 is $m"
break
fi
m=`expr $m - 1`
done
