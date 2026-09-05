```bash
cd /home/yassin/repos/UPV-GII/MIADA/SHELL_EN_ENTORNOS_LINUX/U2/files

# Cuenta la cantidad de líneas de /var/log/syslog en las 
# que aparezca la palabra root

cat /var/log/syslog | grep -l 'root' | wc -l

# Lista los 5 procesos que más memoria consumen 
# actualmente (sugerencia: usa ps auxh)

ps auxh | sort -f -k 4 

# Supón un fichero notas.csv en el que la primera 
# columna es el nombre de cada usuario. Extrae del fichero 
# una lista alfabética de los nombres de los usuarios, sin 
# repetidos. 

cat notas.csv | cut -d ',' -f 1 | sort -n | uniq -d

# Supón un fichero pagina.html. Sustituye todas las 
# ocurrencias de la etiqueta <strong> por <b> (incluyendo 
# las de cierre)

cat pagina.html | sed 's/<strong>/<b>/g' | sed 's/<\/strong>/<\/b>/g'

``