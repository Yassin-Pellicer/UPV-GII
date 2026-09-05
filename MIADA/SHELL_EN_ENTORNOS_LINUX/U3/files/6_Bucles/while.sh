#!/bin/bash
# while.sh

V=(0 100 200)
V[4]=400

i=0
while [ $i -lt 6 ]
do
   echo "\$V[$i]: ${V[$i]}"
   ((i++))
done



