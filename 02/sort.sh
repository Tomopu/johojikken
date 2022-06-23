#!/bin/zsh

./bucket.sh > data/bucket.dat && ./avg data/bucket.dat 10 > data/bucket-avg.dat && echo "bucket sort finish!!"
./insert.sh > data/insert.dat && ./avg data/insert.dat 10 > data/insert-avg.dat && echo "insert sort finish!!"
./bubble.sh > data/bubble.dat && ./avg data/bubble.dat 10 > data/bubble-avg.dat && echo "bubble sort finish!!"

