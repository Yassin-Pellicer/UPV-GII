padece('pedro'.'gripe').
padece('pedro','hepatitis').
padece('juan','hepatitis').
padece('maria','gripe').
padece('carlos','intoxicacion').
sintoma('fiebre','gripe').
sintoma('cansancio','hepatitis').
sintoma('vomito','intoxicacion').
sintoma('cansancio','gripe').
suprime('aspirina','fiebre').
suprime('motilium','vomito').

% donde X es un fármaco e Y una enfermedad 
alivia(X,Y):-suprime(X,Z),sintoma(Z,Y).

% donde X es un fármaco e Y una persona malita 
debeTomar(X,Y):-padece(Y,Z),alivia(X,Z).

padeceSintoma(X,T):-sintoma(X,Z),padece(T,Z).
