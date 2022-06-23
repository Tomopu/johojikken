#!/bin/bash

for i in `seq 1 10`
do
    for j in `seq 1 10` 
    do
        ./quick3 data6.dat $((50000 - (${i}0000/2))) $((50000 + (${i}0000/2)-1))
    done
done