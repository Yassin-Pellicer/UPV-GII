#!/bin/bash
# expresiones.sh

x=1; y=2; z=5

let a=$x+$z*$y
echo $a

(( b = x + z * y ))
echo $b

c=`expr $x + $z \* $y `
echo $c


