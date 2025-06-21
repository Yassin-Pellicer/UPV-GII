// DEFENSORES //

// ARRAY DE SOLDADOS //
soldados([]).
medicos([]).
i(0).

+flag(F): team(200)
<- 
  .register_service("capitan");
  .print("Empezando el Fieldop ");
  .look_at(F);
  .goto(F);
  .wait(8000);
  .get_backups;
  .get_medics;
  +repartirPOS.

/** VIGILANCIA DE BANDERA **/
+repartirPOS:team(200) & flag(F) & soldados(B) & medicos(M)
<-
  .print("Repartiendo posiciones:");
  .defensa(F, Po);

  -+i(0);
  while(i(I) & I < 4) {
    .wait(1000);
    .print(B);
    .nth(I, Po, P1);
    .wait(1000);
    .nth(I, B, Sold); .send(Sold, tell, moverA(P1)); .send(Sold, tell, vigila);
    -+i(I+1);
  }
  -repartirPOS;
  .wait(2000);
  .print("Posiciones repartidas...").

+registrarS[source(S)]:team(200) & soldados(SS)
<-
  -registrarS;
  .concat(SS, [S], L);
  -+soldados(L).

+registrarM[source(S)]:team(200) & medicos(SS)
<-
  -registrarM;
  .concat(SS, [S], L);
  .print("medico registrado");
  -+medicos(L).

+veteAlCentro([X,Y,Z])[source(S)]:flag(F)
<-
  +objetivo([X,Y,Z]);
  .goto(F);
  .print("Voy al centro!!!").

// VIGILAR EL CENTRO // 
+target_reached(T): team(200)
<-
  .print("Estoy en el centro");
  //.send(M, tell, venAlCentro);
  .reload;
  +crearMunicion.

+crearMunicion: team(200) & position([X,Y,Z])
<-
  .print("Doy vueltas.");
  .wait(4000);
  .look_at([X+1,Y,Z]);
  .wait(400);
  .look_at([X-1,Y,Z]);
  .wait(400);
  .look_at([X,Y,Z+1]);
  .wait(400);
  .look_at([X,Y,Z-1]);
  .wait(400);
  -+crearMunicion.