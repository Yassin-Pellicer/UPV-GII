#!/bin/bash
# arrays.sh

V=(0 100 200)
V[4]=400
echo ${V[0]}; echo ${V[1]}
echo ${V[2]}; echo ${V[3]}
echo ${V[4]}; echo ${V[5]}

echo "Elementos:   ${V[*]}"         
echo "Elementos:   ${V[@]}"         
echo "Indices:     ${!V[*]}"       
echo "Tamaño:      ${#V[*]}"       
echo "Tamaño de 1: ${#V[1]}"        

