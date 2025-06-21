// DEFENSORES //

+flag(F): team(200)
<- 
  .get_service("capitan");
  .wait(2000);
  .get_backups;
  .get_medics;
  .wait(1500);
  .goto(F).

+capitan(C): team(200) 
  <-
  +capitanAux(C);
  .send(C, tell, registrarM).

// VIGILAR EL CENTRO // 
+target_reached(T): team(200) & not ayudando
  <-
  .print("Estoy en el centro");
  +cure;
  +crearPaquete.

+target_reached(T): team(200) & flag(F) & ayudando & locked
  <-
  +cure;
  -locked;
  -ayudando;
  .goto(F).

+crearPaquete: team(200) & position([X,Y,Z]) & not ayudando
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
  -+crearPaquete.

+ayuda(Punto)[source(S)]: team(200) & ayudando & flag(F) & not locked
  <-
  .goto(Punto);
  +locked;
  .print("Entendido, ahora te ayudo! ", Punto, "!").