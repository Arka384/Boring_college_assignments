
isValid() {
	re='^[0-9]+([.][0-9]+)?$'
	if ! [[ $1 =~ $re ]] ; then
	   return 0
	fi
	return 1
}

main() {
	sum=0
	i=1
	while read -r line
	do
		currSum=0
		a=0
		b=0
		c=0

		a=`echo $line | cut -d ' ' -f 1`
		isValid "$a"
		x=$?
		if [[ $x -ne 1 ]]; then
			echo "contents not valid"
			exit
			a=0
		fi

		b=`echo $line | cut -d ' ' -f 2`
		isValid "$a"
		x=$?
		if [[ $x -ne 1 ]]; then
			echo "contents not valid"
			exit
			b=0
		fi

		c=`echo $line | cut -d ' ' -f 3`
		isValid "$a"
		x=$?
		if [[ $x -ne 1 ]]; then
			echo "contents not valid"
			exit
			c=0
		fi
		
		currSum=$(($a + $b + $c))
		echo "Sum in line:$i is: $currSum"
		sum=$(($sum + $currSum))
		i=`expr $i + 1`
	done
	echo "Total sum is: $sum"
}

main < $1 

