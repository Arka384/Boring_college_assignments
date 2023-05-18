
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

	rev=0
	while [ $number -gt 0 ]
	do
		rem=`expr $number % 10`
		rev=`expr $rev \* 10`
		rev=`expr $rev + $rem`
		number=`expr $number / 10`
	done

	echo "Reversed number is: $rev"

}

main


