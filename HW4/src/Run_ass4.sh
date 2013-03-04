#! /bin/bash

make network_cost

rm -r graphs
mkdir graphs
TESTS=tests/*.txt

for test in $TESTS
do	
	echo Processing $test
	from=`cat $test | sort -R | head -1 | grep -o ^[[:print:]]*`
	to=`cat $test | sort -R | head -1 | grep -o [[:print:]]*[[:blank:]][0-9]*$ | sed s/[[:blank:]][0-9]*$//`
	name=`basename $test .txt`
	mkdir graphs/$name
	echo +---Full path:
	cat $test | ./network_cost "$from" "$to" -o graphs/$name/$name > temp.txt
	cat temp.txt
	echo +---Total cost:
	cat temp.txt | ./total_message_cost.sh
	for file in graphs/$name/*.dot
	do
		dot -Tgif $file -o $file.gif	
	done
	rm graphs/$name/*.dot
	echo
done

