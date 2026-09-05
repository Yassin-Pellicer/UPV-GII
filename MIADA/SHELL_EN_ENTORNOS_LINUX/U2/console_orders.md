# Estructura básica de una orden en shell

```bash
orden [opciones] [argumentos]
```

Donde:
- Orden: programa o utilidad que queremos ejecutar.
- Opciones: modifican el comportamiento de la orden.
- Arguementos: información que se pasa a la orden.
El carácter por defecto de separación entre elementos es el espacio " ".
Los corchetes y los argumentos son ambos opcionales.

#### Ejemplos

```bash
ls -la /proc /etc
pwd
cd "mis cosas"
```

# Ejecución en la consola

### Expansiones

Las expansiones se usan para reemplazar partes de la orden por otras cosas. Antes
de lanzar a ejecución la orden, se reemplazan las expresiones por lo que corresponden. Las expansiones no las hace el comando, las hace el SHELL.
1. Expansión de variables.
2. Sustitucón de órdenes.
3. Expansión de rutas.

```bash
# La variable $USER contiene el nombre del usuario actual (expansión de variables)

ls -la $USER
dir $HOME

# dir $HOME == dir /home/user

# ~ contiene la ruta del home del usuario actual (expansión de rutas)

cd ~

# De la misma manera Shell puede detectar comandos y expandir su salida (expansión de órdenes)

echo "Hoy: $(date +%d/%m/%Y)"

```
Las variables en shell se declaran con $.

### Comodines (Globbing)

También se pueden hacer expansiones con comodines.
1. Asterisco -> Representa cualquier carácter o cadena, incluso vacía *
2. Pregunta -> Representa cualquier carácter individual o ninguno ?
3. Corchetes -> Contiene un rango de caracteres y representan un carácter individual [] 
4. Llaves -> opciones separadas por comas {}
5. ^ -> Representa el inicio de una cadena
6. $ -> Representa el final de una cadena
7. . -> Representa un carácter OBLIGATORIO (a diferencia de ? que representa cualquier carácter)

#### Ejemplos

1. ls -d [14] -> muestra únicamente el contenido cuyo nombre esté en los corchetes
2. ls -d  {a,b,c} -> muestra únicamente el contenido cuyo nombre esté en las llaves
3. ls -d [14]* -> muestra aquellas carpetas cuyo nombre al menos contenga un 1, un 4 o ambos
4. ls -d [1-4]* muestra aquellas carpetas cuyo nombre contenga un 1, un 2, un 3 o un 4, todos o algunos.

### Entorno de ejecución

El shell mantiene un entorno de ejecución en el que existen una serie de variables de entorno. Hay varias:
- SHELL
- HOME
- USERNAME

La más importante es PATH

El PATH es una variable de entorno que contiene la ruta de los programas y utilidades que queremos usar. Es un listado de directorios separados por : donde el shell busca los programas ejecutables.

Cualquier ejecutable ubicado en esos directorios puede ejecutarse sin necesidad de indicar su ruta absoluta.

```bash
PATH=$PATH:/usr/local/bin
```

Los cambios son solo para la sesión actual del shell. **Si queremos que se apliquen cada vez que iniciemos sesión, los podemos incluir al final del fichero ~/.bashrc** 


# Redirecciones

Todo proceso tiene 3 canales de comunicación.
1. Entrada estándar -> por defecto asociada al teclado.
2. Salida estándar -> por defecto la consola.
3. Salida de error estándar -> por defecto la consola.

Unix permite que el shell redireccione la salida de un proceso a otro canal. Esto se hace mediante símbolos "<" y ">". El símbolo "<" redirige la salida de un proceso a la entrada de otro proceso y el símbolo ">" redirige la entrada de un proceso a la salida de otro proceso.

Para redirigir el error se utiliza el símbolo "2>".

Se pueden añadir >> para anexar la salida a un fichero (se respeta el contenido que existe y lo que vuelca el programa se añade al final del fichero). Lo mismo ocurre con un stderr.

#### Ejemplos

```bash
ls -la /proc /etc > salida.txt
ls -la /proc /etc >> salida.txt
ls -la /proc /etc 2> error.txt
ls -la /proc /etc 2>> error.txt
```

# Tuberías (Pipes)

Linux permite redireccionar directamente la salida de un proceso a la entrada de otro sin utilizar ficheros intermedios.

```bash
# Sintaxis
# orden1 | orden2 [ | orden3 | … | ordenN ]

# Ejemplos

ls -la /proc /etc | wc -l

# Nº de ficheros que hay en /usr/bin
ls -la /usr/bin | grep rwx | wc -l

# Nº de procesos bash que hay en ejecución en el sistema (sin contar el propio shell)

ps aux | grep bash | grep -v grep | wc -l

# Nº de procesos que más CPU consumen

ps auxh | sort -k 3 -nr | head -n 10

```

# Órdenes comunes en Linux

```bash
cp [-riu] origen destino
mv [-iu] origen destino

# -r recursivamente
# -i interactivamente (confirmación)
# -u sobreescribir si el destino ya existe 

rm [-rfi] origen

# -f fuerza la eliminación (necesario para directorios)

touch [-c] fichero

# -c no crea el fichero si no existe, sólo actualiza la fecha de acceso

mkdir [-p] directorio

# -p crea directorios intermedios si no existen

grep [-inHv] patrón [fichero(s)]

# -i case insensitive
# -n mostrar el número de línea
# -H imprime el nombre del fichero
# -v mostrar el contenido de las líneas que no contienen el patrón (búsqueda inversa)

find ruta [criterios]

# ¡-name '*.txt' búsqueda por nombre
# -type f/d  búsqueda por tipo: f (fichero) / d (directorio)
# -mtime -N  búsqueda fecha (modificados los últimos N días)
# -exec orden {} \;   ejecuta orden sobre cada resultado

sort [-fnr][-k cols][-t delim] [ficheros(s)]

# -f numerico
# -n alfabeticamente
# -r orden reverso
# -k columnas
# -t delimitador

uniq [-cdu] [fichero(s)]

# -c contar ocurrencias
# -d muestra las líneas repetidas
# -u muestra las líneas únicas

cut -c caracteres [ficheros(s)]
cut -f campos [-d delimitador] [fichero(s)]

# -c posiciones (por carácter) a extraer
# -f campos (por campo) a extraer
# -d delimitador de campos (entre comillas simples)

tr [-d] [-s] conjunto1 conjunto2

# -d elimina la entrada de los caracteres en conjunto1
# -s elimina ocurrencias repetidas en conjunto1
# Sin argumentos, sustituye cada carácter de conjunto1 por su 
# correspondiente (misma posición) en conjunto2

# EJEMPLO -> cat f1.txt | tr [aeiou] [43102] > pass.txt

bc [-l] 

# Calcula las operaciones que recibe por su entrada estándar, incluyendo
# operaciones con números reales y funciones matemáticas.

# -l incluye la librería de funciones matemáticas

# EJEMPLO -> echo "4.5 / 2.3" | bc -l
# echo "scale=10, 4*a(1)" | bc -l

```
### Sed

Tiene la siguiente expresión:

```bash
sed 'n1[,n2] s/patron1/patron2/{n,ng,g} {p,d,i,a} texto' fichero
```

```bash
 seq 10 15 | sed 's/[0-9]/5/1'
 seq 10 15 | sed '2,4d'
 seq 10 15 | sed -n '2,4p' 
 seq 10 15 | sed '2,4 a Hola'
```

### AWK

```bash
ps aux | awk 'BEGIN { printf "%-15s %-10s %-10s\n", "Usuario", "Procesos", "Promedio_CPU" }
NR > 1 { cpu[$1]+=$3; count[$1]+= 1 }
END { for (u in cpu) printf "%-15s %-10d %-10.2f\n", u, count[u], cpu[u]/count[u] }'

# $1 -> primera columna
# $2 -> segunda columna
# BEGIN = ejecutar antes de todo
# END = ejecutar al final
# NR = número de renglones
# NF = número de campos
# cpu[$1] += $3 -> acumulua el valor de la tercera columna de cada usuario para cada uno de ellos.
# count[$1] += 1 -> cuenta el número de renglones de cada usuario.
```