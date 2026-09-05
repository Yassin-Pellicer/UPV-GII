#!/bin/bash
# funcion-mayor arg1 arg2 (imprime el mayor entre 2 valores)

function mayor () {
   x=$1;  y=$2      # Pase de parámetros (posicional)
   if [ $x -gt $y ]
   then
	echo $x   # Se "imprime" el valor de retorno
   else
	echo $y
   fi
   return 0 # Retorno de la orden, no valor de salida
}

if [ ! $1 ] || [ ! $2 ]
then
	echo Error! Uso correcto: mayor arg1 arg2
	exit 1
fi

resultado=$(mayor $1 $2)  # Se invoca como una orden para
                          # recuperar el valor de retorno
echo $resultado



