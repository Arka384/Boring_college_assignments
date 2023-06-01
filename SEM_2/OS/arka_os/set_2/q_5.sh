
main(){
	for dir in $@
	do
		echo "Directory name: $dir"
		a=`du -s -b "$dir" | cut -f 1`
		echo "Size in bytes: $a"
		b=`du -s -h "$dir" | cut -f 1`
		echo "Size in KB: $b"
	done
}

main $@ > out_q_5.txt
