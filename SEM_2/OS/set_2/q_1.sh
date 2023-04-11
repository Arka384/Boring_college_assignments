
line=`ls -F`
#echo $line

for i in `echo $line`
do
	echo -n $i
	length=`echo $i | wc -c`
	length=`expr $length - 1`
	#echo $length
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
