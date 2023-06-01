main() {
	title=("vendor_id" "model name" "cpu MHz" "cache size")

	for i in {0..3}
	do
		v=`cat /proc/cpuinfo | grep "${title[$i]}"`
		echo "$v"
	done
}

main > out_q_3.txt
cat out_q_3.txt

