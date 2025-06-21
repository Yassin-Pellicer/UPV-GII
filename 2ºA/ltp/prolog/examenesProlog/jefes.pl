% pepe es jefe de juan
% y sus ingresos son 300 euros
% mayores que los ingresos de juan

jefe(pepe,juan,300).
jefe(juan,ana,200).
jefe(ana,mario,100).
jefe(mario,luisa,400).
jefe(pepe,lola,400).
jefe(lola,jorge,600).
jefe(ana,toni,500).
jefe(carla,marco,400).
jefe(carla,elisa,400).
jefe(lola,carla,200).

% luisa es mileurista,
% sus ingresos son 1000 euros

mileurista(luisa).
mileurista(toni).
mileurista(jorge).
mileurista(marco).
mileurista(elisa).

ingresos(X,1000):-mileurista(X).
ingresos(X,Y):-jefe(X,Z,S),ingresos(Z,T), Y is T+S.

cadenaMando(X,Y,[Y]) :- jefe(X,Y,_).
cadenaMando(X,Y,[H|R]):-jefe(X,Z,_),cadenaMando(Z,Y,R).


