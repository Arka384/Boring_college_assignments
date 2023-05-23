
main() {

	setChoice=0
	qChoice=0
	while true
	do
		echo "1 -> set_1"
		echo "2 -> set_2"
		echo "3 -> set_3"
		echo "4 -> Exit"
		echo "Enter your choice: "
		read setChoice

		if [ $setChoice -lt 1 -a $setChoice -gt 4 ]
		then
			echo "Wrong choice"
		fi

		case $setChoice in
		1)
			cd ./set_1
			while true
			do
				progName="assignment_1_"
				echo "0 -> go to set choice"
				echo "1 -> question_1"
				echo "2 -> question_2"
				echo "3 -> question_3"
				echo "4 -> question_4"
				echo "5 -> question_5"
				read qChoice
				if [ $qChoice -eq 0 ] 
				then
					cd $OLDPWD
					break
				fi
				progName="${progName}${qChoice}"
				progName="${progName}".sh""
				if [ $qChoice -eq 5 ]
				then
					echo "Enter user name to find: "
					read userName
					bash $progName "$userName"
				else
					bash $progName
				fi
			done
		;;

		2)
			cd ./set_2
			while true
			do
				progName="q_"
				echo "0 -> go to set choice"
				echo "1 -> question_1"
				echo "2 -> question_2"
				echo "3 -> question_3"
				echo "4 -> question_4"
				echo "5 -> question_5"
				read qChoice
				if [ $qChoice -eq 0 ]
				then
					cd $OLDPWD
					break
				fi
				progName="${progName}${qChoice}"
				progName="${progName}".sh""
				if [ $qChoice -eq 5 ]
				then
					echo "Enter folder name to find: "
					read folderName
					bash $progName "$folderName"
				else
					bash $progName
				fi
			done
		;;	

		3)
			cd ./set_3
			while true
			do
				progName="q_"
				echo "0 -> go to set choice"
				echo "1 -> question_1"
				echo "2 -> question_2"
				echo "3 -> question_3"
				echo "4 -> question_4"
				echo "5 -> question_5"
				echo "6 -> question_6"
				read qChoice
				if [ $qChoice -eq 0 ]
				then
					cd $OLDPWD
					break
				fi
				progName="${progName}${qChoice}"
				progName="${progName}".sh""
				
				if [ $qChoice -eq 1 ]
				then
					echo "Enter target filename: "
					read fileName
					bash $progName "$fileName"
				
				elif [ $qChoice -le 6 -a $qChoice -ge 4 ]
				then
					echo "Enter target folder: "
					read folderName
					cd ./$folderName
					bash $progName "$folderName"
					cd $OLDPWD
				else
					bash $progName
				fi
			done
		;;

		4)
			break
		esac


	done

}

main $@
