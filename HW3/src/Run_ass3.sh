#! /bin/bash
#

# Clean up from previous run (if any).
rm -rf build/ out/

mkdir -p build out
make huffcodec

# run the tests

DATA=../tests/*.txt
for data in ${DATA}; do

    NAME=`basename $data`
    build/huffcodec ${data} out/${NAME}.huff out/${NAME}.restore > out/${NAME}.enco
    [ $? ] || (echo "test run on ${data} failed" ; exit 1)
    echo Conducting diff of ${NAME} and ${NAME}.restore
	diff ${data} out/${NAME}.restore
	SAVED=` expr \`wc -c < ${data}\` - \`wc -c < out/${NAME}.huff\` `
	PERCENT=` expr 10000 - \`wc -c < out/${NAME}.huff\` \* 10000 / \`wc -c < ${data}\` `
	echo space savings for ${NAME}: ${SAVED} bytes, or `echo ${PERCENT} | sed 's_.._&._'`%
	echo
    
done
