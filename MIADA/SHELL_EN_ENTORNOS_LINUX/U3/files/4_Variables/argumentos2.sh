#!/bin/bash
# argumentos2.sh

echo 'nombre del shell script que se está ejecutando:'
echo '$0 =' "$0"

echo 'lista con todos los argumentos (separando por blancos):'
echo '$@ ='
for argumento in "$@"; do
	echo "  <$argumento>"
done

echo 'lista con todos los argumentos (separando por el primer carácter de $IFS):'
echo '$* =' "$*"

echo 'número de argumentos, del 1 al N:'
echo '$# =' "$#"

echo '$1, $2, ...: valores de los argumentos, del 1 al N:'
echo '$1 =' "${1-}"
echo '$2 =' "${2-}"
echo '$3 =' "${3-}"

ultimo_argumento=$_
echo 'valor del último argumento de la última orden ejecutada:'
echo '$_ =' "$ultimo_argumento"

# $? debe guardarse antes de ejecutar el echo explicativo.
true
estado_retorno=$?
echo 'valor de retorno de la última orden ejecutada:'
echo '$? =' "$estado_retorno"

echo 'valor del PID del proceso que ejecuta el script:'
echo '$$ =' "$$"