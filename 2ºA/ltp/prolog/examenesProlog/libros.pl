% "Fundamentos de Algoritmia", de "G. Brassard" y "P. Bratley",
% libro publicado por "Prentice Hall" en 1997
book("Fundamentos de Algoritmia", ["G. Brassard", "P. Bratley"], "Prentice Hall", 1997).
book("Sistemas Operativos", ["William Stallings"], "Prentice Hall", 1997).
book("Fundamentos de Bases de Datos", ["H. Korth", "A. Silberschatz"], "McGrawHill", 1993).
book("Fisica Cuantica", ["Robert Eisberg", "Robert Resnick"], "Limusa", 1979).
book("Sistemas Operativos", ["Milan Milenkovic"], "McGrawHill", 1994).

published(X,Y,Z):-book(X,_,Y,A), A < Z.

% prestamos(DB,F), donde:
% DB es una lista de pares (P,B), siendo P una persona y B un libro
% F una fecha de prestamo mediante el functor date(D,M,A)
% Cada hecho prestamos(DB,F) contiene la lista de prestamos DB hechos en una fecha F.
prestamos([("Ana", "Ana Karenina"), ("Juan", "La broma"), ("Pepe", "El castillo"),
("Alicia", "Lituma en los Andes")], date(29,dic,2020)).
prestamos([("Alicia", "Niebla"), ("Juan", "Hamlet"), ("Pepe", "Odessa"),
("Alicia", "La ciudad de las bestias")], date(7,ene,2021)).
prestamos([("Pepe", "El pirata"), ("Ana", "Cumbres borrascosas"), ("Ana", "El unicornio"),
("Juan", "Niebla")], date(21,ene,2021)).

obtain(X,Y,date(D,M,Y)):-prestamos(DB,date(D,M,Y)),member((X,Y),DB).