#! /bin/bash

cat > temp.txt

# Pick first word of first line. Tab is non-printable so regex will stop there.
from=`cat temp.txt | head -1 | grep -o ^[[:print:]]*`
# Pick last word and cost of last line, then erase the cost with sed
to=`cat temp.txt | tail -1 | grep -o [[:blank:]][[:print:]]*[[:blank:]][0-9]*$ | sed s/[0-9]*$//`
# Read the number at the end of the line on each line, paste together with + as delimiter, pass to bc to sum
cost=`cat temp.txt | grep -o [0-9]*$ | paste -sd+ | bc`

echo -e "$from$to$cost"

rm temp.txt

