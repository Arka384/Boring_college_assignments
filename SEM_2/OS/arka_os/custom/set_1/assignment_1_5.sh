
main() {
	if [ "$1" == "" ]
	then
		echo "No input given"
	else
		user=""
		line=""
		while [ "$user" == "" ]
		do
			line=`cat /etc/passwd | grep -i $1`
			user=`echo $line | cut -d ':' -f 1`
		done

		if [ "$user" == "" ]
		then
			echo "User not found"
			
			else
				resutls=()
				titles=("UserName", "Password", "UserId", "GroupId", "UserId Info", "Home Directory", "Login Shell")

				for i in {1..7}
				do
					info=`echo $line | cut -d ':' -f $i`
					results+=($info)
				done

				for i in {0..6}
				do
					echo "${titles[$i]} : ${results[$i]}"
				done
		fi

	fi
	
}

main $1

