main() {
	paths=`echo $PATH`

	for i in $(echo $paths | tr ":" "\n")
	do
		#echo $i
		if [ -d "$i" ]
		then
	  		info=`ls -ld $i`
			#echo $info
			d1=`echo $info | cut -d " " -f 1`
			d2=`echo $info | cut -d " " -f 6`
			d3=`echo $info | cut -d " " -f 7`
			d4=`echo $info | cut -d " " -f 8`
			echo "'$i' -> $d1 $d2 $d3 $d4"
		else
			echo "'$i' -> does not exist"
		fi
		
	done
}

main > out_q_2.txt
cat out_q_2.txt
