trabaja(empleado(antonio,boix),renfe,1200).
trabaja(empleado(carmen,sanchez),endesa,1600).
trabaja(empleado(lana,rey),polydor,4000).
trabaja(empleado(lana,rey),sonymusic,6000).
trabaja(empleado(pablo,sanchez),bayer,2600).
trabaja(empleado(pablo,sanchez),endesa,4000).

pluriempleado(F,E):-trabaja(F,E,_),trabaja(F,Y,_), Y \== E.
comparables(X,Y):-trabaja(X,E1,S),trabaja(Y,E2,S), E1 \== E2, X \== Y.
colegas(X,Y): trabaja(X,Z,_), trabaja(Y,Z,_), X \== Y.
colegas(X,Y): trabaja(X,_,S),trabaja(Y,_,S), X \== Y.