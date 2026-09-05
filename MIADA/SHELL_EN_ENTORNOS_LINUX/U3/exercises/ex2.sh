#!/bin/bash

# Lea un valor entero que representa una nota, y compruebe si está en el rango adecuado (0 a 10)
#   Si lo está, debe imprimirlo; si no lo está, debe mostrar 
#   un mensaje de error. 
#   El formato de impresión debe ser una tabla con valores. 

echo "Please introduce a mark"
read mark

if [[ ! $mark =~ ^[0-9]+$ ]]; then
  echo "Your mark is not a number"
else
  if [[ $mark -ge 0 && $mark -le 10 ]] then
    case $mark in
    [0-3]) echo "You have failed miserably." ;;
    [4-5]) echo "You have failed, but u almost got there." ;;
    [5]) echo "You passed. Barely." ;;
    [6]) echo "You have passed. You can do better." ;;
    [7-8]) echo "You have passed. Not bad. Not at all." ;;
    [9]) echo "You have passed. Well done!" ;;
    10) echo "You got a 10! Congrats!" ;;
    *) echo "Your mark is not between 0 and 10" ;;
    esac
    echo "Your mark is $mark"
  fi
fi
