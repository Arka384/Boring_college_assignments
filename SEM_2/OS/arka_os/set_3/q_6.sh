main() {
	count=0
	for file in *.exe
	do
		if [ -f "$file" ]
		then
			count=$(($count + 1))
		fi
	done
	echo "Total number of shell files is: $count";
}

main > out_q_6.txt
cat out_q_6.txt
