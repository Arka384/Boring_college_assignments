
for file in *.sh
do
	mv -- "$file" "${file%.sh}.exe"
	
done
