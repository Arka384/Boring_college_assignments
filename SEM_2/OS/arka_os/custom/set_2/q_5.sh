
main(){
	for dir in $@
	do
		if [[ -d $dir ]]
		then
			echo "Directory name: $dir"
			a=`du -s -b "$dir" | cut -f 1`
			echo "Size in bytes: $a"
			b=`du -s -h "$dir" | cut -f 1`
			echo "Size in KB: $b"
		else
			echo "Folder does not exist"
		fi
	done
}

main $@ > out_q_5.txt
cat out_q_5.txt
