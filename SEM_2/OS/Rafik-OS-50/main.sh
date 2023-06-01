#!/bin/bash
CON=1

while [[ $CON -eq 1 ]] 
do
	clear
	DIR_PATH=`pwd`"/assignment_"
	DIR_COUNT=1
	SC_COUNT=1
	ARGS=""
	END=".sh"
	for i in `ls`
	do
		if [ -d "$i" ]
		then
			echo "DIRECTORY $DIR_COUNT - $i"
			DIR_COUNT=$((DIR_COUNT+1))
		fi
	done
	echo -n "CHOOSE DIRECTORY: "
	read DIR
	echo ""
	DIR_PATH+=$DIR
	cd $DIR_PATH
	for file in *.sh; 
	do
  		echo "SCRIPT $SC_COUNT - $file"
		SC_COUNT=$((SC_COUNT+1))
	done
	echo -n "CHOOSE SCRIPT TO RUN: "
	read SCR
	if [[ $DIR -eq 2 && $SCR -eq 5 ]]
	then
		echo ""
		echo -n "Enter the directory names as arguments: "
		read ARGS
		END=$END" "$ARGS
	fi
	echo ""
	PR_PATH=$DIR_PATH"/50_0"$DIR"_0"$SCR$END
	( $PR_PATH )
	cd ..
	echo ""
	echo "Enter 1 to coninue or 0 to exit: "
	read CON
done
clear
