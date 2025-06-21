//TEAM_ ATACANTE

i(0).
+flag ([X,Y,Z]): team(100)
  <-
  .goto([X-10,Y,Z-10]);
  .print("A por la bandera!").

//TEAM DEFENSOR

+flag (F):team(200)
  <-
  .register_service("batalla");
  .wait(2000);
  .get_service("capitan");
  .wait(1500);

  ?health(H);
  +vidaIni(H);
  ?ammo(A);
  +balasIni(A);

  .get_backups;
  .get_medics;
  .goto(F).

+capitan(C): team(200) 
  <-
  +capitanAux(C);
  .send(C, tell, registrarS).

/** ---- PROGRAMAMOS A LOS AGENTES TORRETA ---- **/

+moverA(Punto)[source(S)]: team(200)
  <-
  .goto(Punto);
  +puntoOriginal(Punto);
  +punto;
  .print("Montando guardia en el punto: ", Punto, "!").

+target_reached(T): buscopaquete & vigila & puntoOriginal(Punto) & not travelBack
<-
  .goto(Punto);
  +travelBack.

+target_reached(T): travelBack & vigila
<-
  -travelBack;
  -buscopaquete;
  -locked;
  .print("he vuelto");
  +comprobar.

+target_reached(T): vigila & not travelBack & not buscopaquete
<-
  +comprobar.

+comprobar: team(200) & position([X,Y,Z]) & vigila & not buscopaquete 
<-
  .look_at([X+1,Y,Z]);
  .wait(400);
  .look_at([X-1,Y,Z]);
  .wait(400);
  .look_at([X,Y,Z+1]);
  .wait(400);
  .look_at([X,Y,Z-1]);
  .wait(400);
  -+comprobar.

+enemies_in_fov(ID,Type,Angle,Distance,Health,Position): vigila & not travelBack & myBackups(SS)
<-
  ?ammo(A);
  ?health(H);
  if(A > 0 & not buscopaquete){
    .send(SS, tell, VenidYa);
    .send(SS, tell, aqui(Position));
    .look_at(Position);
    .print("Disparo");
    if(Health>H){
        if(A>20){
          .shoot(10, Position);            
        }
        else{
          .shoot(5, Position);
        };
    };
    .shoot(3,Position);
    ?ammo(BB);
    -+balasIni(BB);

  };    
  if((A == 0 | H <= 30) & not buscopaquete){
    +buscopaquete;
    +muni_critica;
  }.

+muni_critica: vigila & flag(F) & buscopaquete
<- 
  .print("Voy al centro!");
  .goto(F);
  +buscopaquete.

+packs_in_fov(ID,Type,Angle,Distance,Health,Position): Type<1003 & health(H) & ammo(A) & (A \== 100 | H \== 100) & buscopaquete & not locked & puntoOriginal(P)
<-
  .print("voy a por paquete");
  .goto(Position);
  +locked.

/** ---- PROGRAMAMOS A LOS AGENTES MÓVILES ---- **/

+target_reached(T): team(200) & not vigila & (not buscopaqueteMuni | not buscopaqueteVida)
  <-
  !patrullar.

+!patrullar: team(200) & flag(F) & position(P) & not vigila
 <-
 .next(P, F, D); /*se dirige al siguiente punto de patrulla*/
 .goto(D).

+target_reached(T): (buscopaqueteMuni | buscopaqueteVida) & not vigila
<-
  -buscopaqueteMuni;
  -buscopaqueteVida;
  -locked;
  .next(P, F, D); /*se dirige al siguiente punto de patrulla*/
  .goto(D).

+enemies_in_fov(ID,Type,Angle,Distance,Health,Position): not vigila
<-
    ?ammo(A);
    ?health(H);
    if(A > 0 & not buscopaquete){
        .look_at(Position);
        .print("Disparo");
        if(Health>H){
            if(A>20){
                .shoot(10, Position);            
            }
            else{
                .shoot(5, Position);
            };
        };
        .shoot(3,Position);
        .goto(Position);
        ?ammo(BB);
        -+balasIni(BB);
    };
    if((A == 0) & not buscopaqueteMuni){
      +buscopaqueteMuni;
      +muni_critica;
    };
    if((H <= 100) & not buscopaqueteVida){
      +buscopaqueteVida;
      +vida_critica;
    }.

+aqui(Punto)[source(S)]: team(200) & VenidYa
  <-
  .goto(Punto);
  +punto;
  .print("Allévoy, ahora te ayudo! ", Punto, "!").

+muni_critica: flag(F) & buscopaqueteMuni
<- 
  .print("Voy a por un paquete de munición!");
  .goto(F);
  +buscopaqueteMuni.

+vida_critica: flag(F) & buscopaqueteVida & position(P) & myMedics(M) & i(T)
<- 
  .print("Voy a por un paquete de vida!", M);
  .nth(T, M, Med);
  .distanciaMedia(F, P, O);
  .goto(O);
  .send(Med, tell, ayudando);
  .send(Med, tell, ayuda(O));
  +buscopaqueteVida.

+packs_in_fov(ID,Type,Angle,Distance,Health,Position): Type<1003 & health(H) & ammo(A) & (A \== 100 | H \== 100) & (buscopaqueteMuni | buscopaqueteVida) & not locked & puntoOriginal(P)
<-
  .print("voy a por paquete");
  .goto(Position);
  +locked.