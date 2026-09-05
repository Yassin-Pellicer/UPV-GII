#!/bin/bash

# Lea un valor entero que representa una nota, y compruebe si está en el rango adecuado (0 a 10)
#   Si lo está, debe imprimirlo; si no lo está, debe mostrar 
#   un mensaje de error. 
#   Si no se introduce ningún número, el script debe 
#   asumir un valor por defecto de 0. 

echo "Please introduce a mark"
read mark

if [[ ! $mark =~ ^[0-9]+$ ]]; then
  echo "Your mark is not a number"
else
  if [[ $mark -ge 0 && $mark -le 10 ]] then
    echo "Your mark is $mark"
  else
    echo "Your mark is not between 0 and 10"
  fi
fi
