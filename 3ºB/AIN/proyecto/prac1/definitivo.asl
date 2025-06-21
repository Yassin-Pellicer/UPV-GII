seguro([102, 0, 102],[102,0,204],[204,0,102],[204,0,102]). /**Puntos seguros**/

+flag(F): team(200)
    <-
        !calculapuntoseguro;
        ?dist1(D1);
        ?dist2(D2);
        ?dist3(D3);
        ?dist4(D4);
        .min([D1,D2,D3,D4], Minimo)


+!calculapuntoseguro
    <-
        ?positio([X,Y,Z]);
        +dist1((X-20)+(Z-20));
        +dist2(()+())
        +dist3(()+())
        +dist4(()+())

        .goto([125, 0, 126]);
        +miposicion([20, 0, 20])

+target_reached(T): alcentro
    <-
        -alcentro;
        .print("He llegado al centro ", T);
        ?flag(F);
        .look_at(F);
        -target_reached(T).        

+friends_in_fov(ID,Type,Angle,Distance,Health,Position)
    <-
        .print("Disparo");
        .shoot(3,Position).

+!agirar: estado(E) & E<4
    <-
        ?mirando(L);
        .nth(E, L, P);
        .look_at(P);
        .wait(1000);
        -estado(_);
        +estado(E+1);
        !agirar.

+!agirar: estado(E) & E=4
    <-
        -estado(_);
        +estado(0);
        !agirar.