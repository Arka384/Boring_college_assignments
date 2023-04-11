main() {
	title=("OS type" "version" "release number" "kernel version")
	uname_flags=("o" "v" "r" "v")
 
	homeDir=`ls /home`
	echo "Home directory :" $homeDir
 
	for i in {0..3}
	do
		info=`uname -${uname_flags[$i]}`
		echo "${title[$i]} : $info"
	done
 
	echo "All Path settings :" $PATH
}
 
main > out_q_4.txt
clear
cat out_q_4.txt