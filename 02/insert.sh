#!/bin/zsh

for i in `seq 1 7`
do
    # echo '----data'${i}'.dat:0~9999----------------'
    for k in `seq 1 10`
    do
        ./insert data${i}.dat 0 9999
    done
    for j in `seq 1 9`
    do
        # echo '----data'${i}'.dat:0~'${j}'9999----------------'
        for k in `seq 1 10`
        do
            ./insert data${i}.dat 0 ${j}9999
        done
    done
 
done