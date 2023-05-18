
isValid() {
	re='^[0-9]+([.][0-9]+)?$'
	if ! [[ $1 =~ $re && $2 =~ $re ]] ; then
	   echo "error: Not a number"
	   echo ""
	   return 0
	else
		if [[ $(echo "$1 > 0" |bc -l) && $(echo "$2 > 0" |bc -l) ]] ; then
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
	length=0
	breadth=0
	x=0
	while [ $x -ne 1 ]
	do
		echo "Enter length: "
		read length
		echo "Given length is: $length"
		echo "Enter breadth: "
		read breadth
		echo "Given breadth is: $breadth"
		isValid "$length" "$breadth"
		x=$?
	done
	
	area=`bc <<< "$length * $breadth"`
	temp=`bc <<< "$length + $breadth"`
	peri=`bc <<< "$temp * 2"`

	echo "Area of Rect: $area"
	echo "Perimeter of Rect: $peri"
}

main



