main() {
	totalSize=0
	for file in *
	do
		if [ -f "$file" ]
		then
			size=`ls -l "$file" | cut -d ' ' -f5`
			totalSize=$(($totalSize + $size))
		fi
	done
	echo "Total number of bytes used by files is: $totalSize"
}

main > out_q_3.txt
cat out_q_3.txt
