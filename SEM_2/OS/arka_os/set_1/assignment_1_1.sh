
function isValid() {
	valid=1
	inValid=0
	re='^[0-9]+$'
	rer='[0-9]+([.][0-9]+)?$'
	if ! [[ $1 =~ $rer && $2 =~ $rer ]] ; then
		echo "Not a number"
		return $inValid
		if [[ $1 -le 0 || $2 -le 0 ]] ; then
			echo "Negetive number given"
			return $inValid
		fi
	fi
	
	return $valid
}

main() {
	x=0
	length=0
	breadth=0
	while [ $x -ne 1 ]
	do
		echo ""
		echo "Enter length: "
		read length
		echo "Enter breadth: "
		read breadth
		isValid "$length" "$breadth"
		x=$?
	done

	echo "Given length is: $length" > set_1_1_out.txt
	echo "Given breadth is: $breadth" >> set_1_1_out.tx
	area=`bc <<< "$length * $breadth"`
	temp=`bc <<< "$length + $breadth"`
	peri=`bc <<< "$temp * 2"`
	echo "Area of Rect: $area" >> set_1_1_out.txt
	echo "Perimeter of Rect: $peri" >> set_1_1_out.txt
	
}
main

echo ""
cat set_1_1_out.txt
