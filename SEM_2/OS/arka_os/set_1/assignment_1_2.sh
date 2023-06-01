
function isValid() {
	valid=1
	inValid=0
	re='^[0-9]+$'
	rer='[0-9]+([.][0-9]+)?$'
	if ! [[ $1 =~ $rer ]] ; then
		echo "Not a number"
		return $inValid
		if [[ $1 -lt 0 ]] ; then
			echo "Negetive number given"
			return $inValid
		fi
	fi
	
	return $valid
}


main() {
	x=0
	b_salary=0
	while [ $x -ne 1 ]
	do
		echo "Enter basic salary"
		read b_salary
		
	done
	
	echo "Given basic salary: $b_salary"
	da=0.04
	hra=0.06
	total=0
	da_amout=`bc <<< "$b_salary * $da"`
	hra_amout=`bc <<< "$b_salary * $hra"`
	
	total=`bc <<< "$b_salary + $da_amout + $hra_amout"`
	echo -e "Total salary: $total \t DA: $da_amout \t HRA: $hra_amout"
}


