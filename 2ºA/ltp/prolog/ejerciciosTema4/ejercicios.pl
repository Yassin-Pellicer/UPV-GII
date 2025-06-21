/* 
    Ejercicio 6.

    Esto en realidad es muy lógico: pongamos como ejemplo
    la palabra giraffarig. lo que hace este programa es pillar la g
    como la cabeza de la lista, y irraffarig como el resto de la palabra.
    La función append lo que hace es evaluar dos listas 1 y 2, y unirlas en 
    una tercera resultado 3. Si nuestra lista resultado tiene que ser
    iraffarig, y nuestra segunda lista es g, nuestra primera lista necesariamente
    tiene que ser iraffari, con la cual se vuelve a llamar a la función. 
    El proceso se repite. Pillamos la i como cabeza, el resto de a lista será 
    entonces raffari. Entonces, T será raffar...

    Si nuestro resultado unifica con la [] o bien [H] como único elemento para palabras
    impares, entonces la palabra será un palíndromo. En caso contrario, no lo será.
*/

palindromo([]).
palindromo([H]).
palindromo([H|L]):-append(T,[H],L),palindromo(T).

/* también hay una versión más sencilla: palindromo(L):-reverse(L,L). */

/* Ejercicio 7. */

vertical(segmento(punto(X,_),punto(X,_))).
horizontal(segmento(punto(_,Y),punto(_,Y))).

/* Ejercicio 8 */

f(X,0):- X<3.
f(X,2):- 3=<X, X<6.
f(X,4):- 6=<X.

/* Ejercicio 10 y 11*/

impar([_]).
impar([_,_|L]):- impar(L).

par([]).
par([_,_|L]):- par(L).

/* Ejercicio 10 y 11 (recursión cruzada de los anteriores) */

impar([_]).
impar([_|L]):- par(L).

par([]).
par([_|L]):- impar(L).

/* Ejercicio 13 */

remove(X,[],[]).
remove(X,[X|L],Z):-remove(X,L,Z).
remove(X,[Y|L],[Y|Z]):-X\=Y, remove(X,L,Z).

remove_rep([],[]).
remove_rep([X],[X]).
remove_rep([X|L],[X|Z]):-member(X,L), remove(X,L,M),remove_rep(M,Z).
remove_rep([X|L],[X|Z]):-not(member(X,L)), remove_rep(L,Z).

/* Ejercicio 14 */

repeat(_,[],0).
repeat(X,[X|L],N):-repeat(X,L,M), N is M+1.
repeat(X,[Y|L],N):-X\=Y, repeat(X,L,N).

/* Ejercicio 15 */

largest([Y],Y).
largest([X,Y|L],Z):-X>=Y,largest([X|L],Z).
largest([X,Y|L],Z):-X<Y,largest([Y|L],Z).

/* Ejercicio 16 */

split(U,[],[],[]).
split(U,[X|L],[X|Z],V):- U>=X, split(U,L,Z,V).
split(U,[X|L],Z,[X|V]):- U<X, split(U,L,Z,V).

/* Ejercicio 17 */

add([],0).
add([X|L],A):- add(L,B), A is X+B.