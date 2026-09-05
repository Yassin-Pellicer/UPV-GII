#!/bin/bash
# expansion3.sh

echo 'basename $PWD       ' $(basename "$PWD")
echo 'dirname $PWD        ' $(dirname "$PWD")

echo

echo '${PWD##*/}          ' ${PWD##*/}
echo '${PWD%/*}           ' ${PWD%/*}


echo
echo

file="/home/usuario/datos/texto.txt"

basefile=${file##*/}

echo 'Nombre sin extension ' ${basefile%%.*}
echo 'Extension            ' ${basefile##*.}
 




