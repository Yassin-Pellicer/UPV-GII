countTo(1,[1]).
countTo(2,[1,2]).
countTo(3,[1,2,3]).
countTo(4,[1,2,3,4]).

/*  Ejercicio 1

    ?- countTo(X,[_,_,_,Y]).
    X = Y, Y = 4.

    ?- countTo(X,[_,_,_|Y]).
    X = 3,
    Y = [] ;
    X = 4,
    Y = [4].
*/

/*  Ejercicio 3

    ?- countTo(4,[H|T]).
    H = 1,
    T = [2, 3, 4].
    
    ?- countTo(4,[H|T]).
    H = 1, 2.
    T = [3, 4].
    
    ?- countTo(4,[_,X|_]).
    X = 2.
*/

/*  Ejercicio 3 
    ?- member(2,[5,2,3,2]).
    true 

    ?- member(X,[5,2,3]).
    X = 5;
    X = 2;
    X = 3;
*/

/*  Ejercicio 4 */

mymember(E,[E,_]).
mymember(E,[H|L]):-mymember(E,L).

/*  Ejercicio 5 */

myappend([],L,L).
myappend([E|L1],L2,[X|L3]) :- X is E, myappend(L1,L2,L3).

/*  Ejercicio 6 

?-  append([a,Y],[Z,d],[X,b,c,W]).
?-  append(L1,L2,[a,b,c,d]).
...
*/

/*  Ejercicio 7 */
swap([X|[Y|Z]],[Y|[X|Z]]).

/*  Ejercicio 8
    mistery([],0).
    mistery([_|T],N) :- mistery(T,M), N is M+1.

    cuenta el total de elementos de una lista.
*/

/*  Ejercicio 9 */

subset([],_).
subset([A|X],Y) :- member(A,Y),subset(Y,X).

/* Ejercicio 10 */

sorted([]).
sorted([_]).
sorted([X,Y|Ys]):- X =< Y, sorted([Y|Ys]).

/* Ejercicio 11 */

remove(_,[],[]).
remove(C,[X|R],L) :- X == C, remove(C,R,L).
remove(C,[X|R],W) :- X \== C, remove(C,R,L), W = [X|L].