
isValid() {
	re='^[0-9]+([.][0-9]+)?$'
	if ! [[ $1 =~ $re ]] ; then
	   echo "error: Not a number"
	   echo ""
	   return 0
	else
		if [[ $(echo "$1 > 0" |bc -l) ]] ; then
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
	b_salary=0
	x=0
	while [ $x -ne 1 ]
	do
		echo "Enter basic salary: "
		read b_salary
		echo "Given basic salary: $b_salary"
		isValid "$b_salary"
		x=$?
	done
	
	da=0.04
	hra=0.06
	total=0
	da_amout=`bc <<< "$b_salary * $da"`
	hra_amout=`bc <<< "$b_salary * $hra"`
	total=`bc <<< "$b_salary + $da_amout + $hra_amout"`
	
	echo -e "Total salary: $total \t DA: $da_amout \t HRA: $hra_amout"
}

main

