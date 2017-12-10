echo "Enter the number"
read num
i=2
while(($i<$num))
do
rem=$(($num % $i))
if(($rem == 0))
then
echo "Not a prime"
break
fi
i=$(($i+1))
done

if(($i==$num))
then
echo "Prime!"
fi
