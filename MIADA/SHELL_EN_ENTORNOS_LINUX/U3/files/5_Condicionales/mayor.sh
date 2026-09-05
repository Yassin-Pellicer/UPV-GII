#!/bin/bash
# mayor arg1 arg2 (imprime el mayor entre 2 valores)

if [ ! $1 ] || [ ! $2 ]
then
	echo Error! Uso correcto: mayor arg1 arg2
	exit 1
fi
if [ $1 -gt $2 ]
then
	echo $1
else
	echo $2
fi






