read length
echo "Given length is: $length"
read breadth
echo "Given breadth is: $breadth"

area=`expr $length \* $breadth`
temp=`expr $length + $breadth`
peri=`expr $temp \* 2`

echo "Area of Rect: $area"
echo "Perimeter of Rect: $peri"
