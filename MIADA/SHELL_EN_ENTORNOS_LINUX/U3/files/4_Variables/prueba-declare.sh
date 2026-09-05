#!/bin/bash

declare -r dia=jueves
echo $dia
#dia=viernes
echo "Resultado: $?"
echo $dia

declare -l mes=diciembre
echo mes: $mes

declare -u MES=diciembre
echo MES: $MES

echo "****************************"

mes="ENERO"
echo mes: $mes
MES="enero"
echo MES: $MES

declare -x exportada1="prueba de exportación"
declare    exportada2="no debería aparecer contenido"
declare -x exportada3="prueba de exportación adicional"

./prueba-export.sh

export exportada2

./prueba-export.sh
