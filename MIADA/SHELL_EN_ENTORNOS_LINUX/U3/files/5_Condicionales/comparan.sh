#!/bin/bash
# comparan n (compara los primeros n caracteres de 2 cadenas)

if [[ $# -lt 1  || $1 -le 0 ]] ; then
	echo "Error! Uso correcto: comparan n (n > 0)"; exit 1
fi
N=$1
echo "Introduce la primera cadena: " ; read cad1
echo "Introduce la segunda cadena: " ; read cad2

if [[ ${cad1:0:$N} = ${cad2:0:$N} ]] ; then
	echo "Los primeros $N caracteres coinciden."
else
	echo "Los primeros $N caracteres no coinciden."
fi







