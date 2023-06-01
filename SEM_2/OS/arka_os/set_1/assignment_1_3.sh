read number
echo "Given number is: $number"

sum=0

while [ $number -gt 0 ]
do
	rem=`expr $number % 10`
	sum=`expr $sum + $rem`
	number=`expr $number / 10`
done

echo "Sum of digits is: $sum"

