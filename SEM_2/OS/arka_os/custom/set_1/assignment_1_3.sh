
isValid() {
	re='^[0-9]+$'
	if ! [[ $1 =~ $re ]] ; then
	   echo "error: Not a Valid number"
	   echo ""
	   return 0
	else
		if [[ $(echo "$1 >= 0" |bc -l) ]] ; then
			return 1
		else
			echo "error: Invalid length"
			echo ""
			return 0
		fi
	fi
	return 1
}

main() {
	number=0
	x=0
	while [ $x -ne 1 ]
	do
		echo "Enter a number: "
		read number
		echo "Given number is: $number"
		isValid "$number"
		x=$?
	done

	sum=0
	while [ $number -gt 0 ]
	do
		rem=`expr $number % 10`
		sum=`expr $sum + $rem`
		number=`expr $number / 10`
	done

	echo "Sum of digits is: $sum"
}

main

