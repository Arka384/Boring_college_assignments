main() {
	fileCount=`ls -l | grep ^- | wc -l`
	dirCount=`ls -l | grep ^d | wc -l`	
	echo "Total number of directories: $dirCount"
	echo "Total number of files: $fileCount"
	echo ""
	
	line=`ls -F`
	for i in `echo $line`
	do
		echo -n $i
		length=`echo $i | wc -c`
		length=`expr $length - 1`
		c=`echo $i | cut -c $length`
		if [ $c == "/" ]
			then
				echo -n " -> "
				echo "Directory"
			else
				echo -n " -> "
				echo "File"
		fi
	done
}

main > out_q_2.txt
cat out_q_2.txt
