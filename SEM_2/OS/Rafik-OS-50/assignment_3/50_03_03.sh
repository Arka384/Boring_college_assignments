echo "Total bytes used : " $(ls -lA | awk '{ total += $5 } END { print total }')
