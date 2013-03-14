#! /bin/bash

make micro

./micro < test.txt

./micro < test.txt > output.txt

diff output.txt demo.txt
