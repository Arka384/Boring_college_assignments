
for file in *.exe
do
	mv -- "$file" "${file%.exe}.sh"
done
