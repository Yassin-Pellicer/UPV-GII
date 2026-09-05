#!/bin/bash
# expansion1.sh

defecto="valor por defecto"
alternativo="valor alternativo"
#cadena="hola"

echo ${cadena:-$defecto}
echo ${cadena}
echo ${cadena:=$defecto}
echo ${cadena}
echo ${cadena:+$alternativo}
echo ${cadena}
echo ${cadena:?"Error: sin valor"}
echo ${noexiste:?"Error: sin valor"}





