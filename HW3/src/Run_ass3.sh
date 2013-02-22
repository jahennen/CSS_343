#! /bin/bash
#
make huffcodec

# run the tests

DATA=../tests/*.txt
for data in ${DATA}; do

     base=
    ./build/huffcodec ../tests/${data} ./result.huf ./decode.txt > ./out/`basename $data .txt`.enco
    echo diff of ${data}
	diff ${data} ./decode.txt
    [ $? ] || (echo "test run on ${data} failed" ; exit 1)
    
done
