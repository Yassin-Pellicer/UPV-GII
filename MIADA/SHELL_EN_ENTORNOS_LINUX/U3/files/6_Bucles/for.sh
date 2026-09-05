#!/bin/bash
# for.sh

V=(0 100 200)
V[4]=400

for (( i=0; i < 6; i++ ))
do
   echo "\$V[$i]: ${V[$i]}"
done



