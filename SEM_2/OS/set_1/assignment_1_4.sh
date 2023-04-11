read number
echo "Given number is: $number"

rev=0

while [ $number -gt 0 ]
do
	rem=`expr $number % 10`
	rev=`expr $rev \* 10`
	rev=`expr $rev + $rem`
	number=`expr $number / 10`
done

echo "Sum of digits is: $rev"

