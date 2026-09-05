#!/bin/bash

echo Hola mundo!
exit 0

# Tu terminal "murió" (probablemente se cerró la ventana por completo o se cerró tu sesión) 
# porque usaste el comando punto (.) para ejecutar el script dentro de tu proceso 
# actual, y tu script contiene la palabra exit. Cuando ejecutas un script
# usando un punto al principio (por ejemplo, . holamundo.sh), 
# no estás creando un subproceso nuevo. 

# Le estás diciendo a la terminal: "Toma todas las líneas de este archivo y ejecútalas 
# aquí mismo, directamente en mi shell actual". Si tu script termina con un comando 
# exit, la terminal obedece ciegamente a ese comando, y cierra el proceso en el que 
# se encuentra. Como el proceso actual era tu propia terminal... la cerró.
