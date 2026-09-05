#!/bin/bash
# funcion-error arg1 arg2 (imprime el mayor entre 2 valores)

function error () {
      msg=$1      # Pase de parámetros (posicional)
      echo $msg 
      exit 1
}

if [ ! $1 ] || [ ! $2 ]
then
  	error "Error! Uso correcto: mayor arg1 arg2"
fi

if [ $1 -gt $2 ]; then echo $1; else echo $2
fi
