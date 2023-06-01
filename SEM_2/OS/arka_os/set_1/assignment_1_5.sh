
user=`cat /etc/passwd | grep -i "$1" | cut -d ':' -f 1`
if [ "$user" == "" ]
then
	echo "User not found"
	
	else
		result=()
		titles=("UserName", "Password", "UserId", "GroupId", "UserId info", "Home Directory", "Login shell")
		for i in {1..7}
		do
			info=`cat /etc/passwd | grep -i "$1" | cut -d ':' -f $i`
			result+=($info)
		done

		for i in {0..6}
		do
			echo "${titles[$i]} : ${result[$i]}"
		done
fi




