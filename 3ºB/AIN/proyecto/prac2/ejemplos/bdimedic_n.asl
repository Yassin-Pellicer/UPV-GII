//TEAM_DEFENSOR
cont(0).
soldados([]).
i(0).

/** Creencias iniciales, se obtienen los médicos y los soldados,
tambien se inicia la reparticion de posiciones **/
+flag (F): team(200)
  <-
  .register_service("capitan");
  .look_at(F);
  .goto(F);
  .wait(2000);

/**  .get_backups; **/ 
/**  .get_medics; **/
  +repartirPOS.

/** Reparte 4 posiciones iniciales entre los 4 primeros agentes registrados**/
+repartirPOS:team(200) & flag(F) & soldados(B)
  <-
  .defencePOS(F, Po);
  +vigilantes(Po);

  .wait(1000);
  -+i(0);
  while(i(I) & I < 4) {
    .nth(I,Po, P1);
    .print("Punto ",I, ": ", P1);

    .nth(I, B, Sold);
    .send(Sold, tell, moverA(P1));
    .print("Ahora",Sold," es torre.");
    .send(Sold, tell, laTorre);
    -+i(I+1);
  }
  -repartirPOS;
  +dejarMuni;
  .print("Posiciones repartidas...").

/** Cuando un agente se conecta, este se registra en la lista de fieldop para
su posterior posible uso **/
+registrar[source(S)]:team(200) & soldados(SS)
  <-
  -registrar;
  .concat(SS, [S], L);
  -+soldados(L).

+mueveteA(P)
  <-
  .goto(P).

+coronel(C)
  <-
  +coronelli(C);
  .print("Hola coronel!").

+comprobar: team(200) & position([X,Y,Z])
  <-
  .look_at([X+1,Y,Z]);
  .wait(400);
  .look_at([X-1,Y,Z]);
  .wait(400);
  .look_at([X,Y,Z+1]);
  .wait(400);
  .look_at([X,Y,Z-1]);
  .wait(400);
  ?objetivo(O);
  .look_at(O);
  -comprobar.

+venAlCentro:f(F)
  <-
  +combate;
  .goto(F);
  .print("Entendido");
  .look_at(F).

+target_reached(T): team(200) & combate & objetivo([X,Y,Z])
  <-
  .look_at([X,Y,Z]);
  .cure;
  +crearPaquetes;
  +comprobar.

+crearPaquetes
  <-
  .cure;
  .wait(4000);
  -+crearPaquetes.
  
