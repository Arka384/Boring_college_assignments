read b_salary
echo "Given basic salary: $b_salary"

da=0.04
hra=0.06
total=0
da_amout=`bc <<< "$b_salary * $da"`
hra_amout=`bc <<< "$b_salary * $hra"`

total=`bc <<< "$b_salary + $da_amout + $hra_amout"`
echo -e "Total salary: $total \t DA: $da_amout \t HRA: $hra_amout"
