vecinas('sevilla','huelva').
vecinas('sevilla','cadiz').
vecinas('sevilla','malaga').
vecinas('sevilla','cordoba').
vecinas('huelva','cadiz').
vecinas('malaga','cadiz').
vecinas('malaga','cordoba').
vecinas('malaga','granada').
vecinas('granada','jaen').
vecinas('granada','almeria').
vecinas('cordoba','jaen').
vecinas('cordoba','granada').

fronterizas(X,Y):-vecinas(X,Y)|vecinas(Y,X).

viaje(X,Y):-fronterizas(X,Y).
viaje(X,Y):-fronterizas(X,Z), fronterizas(Z,Y).