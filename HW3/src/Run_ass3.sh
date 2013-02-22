#! /bin/bash
#
make huffcodec

# run the tests

DATA=../tests/*.txt
for data in ${DATA}; do

    NAME=`basename $data`
    ./build/huffcodec ${data} ./result.huf ./decode.txt > ./out/`basename $data .txt`.enco
    [ $? ] || (echo "test run on ${data} failed" ; exit 1)
    echo diff of ${NAME}
	diff ${data} ./decode.txt
	SAVED=` expr \`ls -s ${data} | grep -o [0-9]*\` - \`ls -s result.huf | grep -o [0-9]*\` `
	PERCENT=` expr 100 - \`ls -s result.huf | grep -o [0-9]*\` \* 100 / \`ls -s ${data} | grep -o [0-9]*\` `
	echo space savings for ${NAME}: ${SAVED} bytes, or ${PERCENT}%
	echo
    
done
