//TEAM DEFENSOR
+flag (F):team(200)
  <-
  .print("Arranca soldado");
  .get_backups;
  .get_medics;
  .register_service("soldados");
  .wait(5000);
  .get_service("capitan");
  .wait(1500);
  +alCentro;
  +objetivo(F);
  .goto(F);
  +bucle.

/*Mediante un mensaje al capitan/medico, se registra el soldado*/
+capitan(C): team(200) 
  <-
  +captain(C);
  .send(C, tell, registrar).

/*Movimientos iniciales para agente fijo*/
+moverA(Punto)[source(S)]: team(200)
  <-
  .goto(Punto);
  +punto;
  .print("Orden recibido, punto de viligancia: ", Punto).

/*Agente fijo, da vueltas sobre la posición designada, esperando detectar a un enemigo. */
+target_reached(F): punto 
  <-
  -punto;
  !patrullandoEnemigos.

/*Aquellos soldados que no son fijos, los mandamos a patrullar de forma aleatoria*/
+target_reached(T): team(200) & alCentro & not Fijo & not combate
  <-
  -alCentro;
  !patrullar.

+!patrullar: team(200) & flag(F) & position(P) & not combate
 <-
 -combate;
 -+seguir;
 .next(P, F, D); /*se dirige al siguiente punto de patrulla*/
 .goto(D);


/* Cuando llega a su posicion de patrulla, da una vuelta para ver si encuentra algún enemigo, si no sige con la patrulla */
+target_reached(T):team(200) & seguir & not combate
  <-
  +check;
  !patrullar.

/*cuando está en combate y consige llegar al objetivo, da una vuelta buscando enemigos. Trata de encontrar enemigos y dispararlos*/
+target_reached(T):team(200) & combate
  <-
  -amenaza(_);
  -eliminar;
  +check;
 
/*fin patrulla fuera de combate*/


/*Patrulla, mientras no encuentro a ningún enemigo, da vueltas sobre si mismo, realiza una pausa para asegurarse de encontrar*/
+!patrullandoEnemigos:team(200) & not combate
  <-
  +check;
  .wait(2100);
  !patrullandoEnemigos.

+Fijo <- .print("Fijo").

/*Vueltas sobre si mismo, segmento de código de las diapositivas de la primera parte de la práctica*/
+check: team(200) & position([X,Y,Z])
  <-
  /*.print("Vuelta de reconocimiento");*/
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
  -check.


/*Cuando entra en combate, lo primero que hace es activar la creencia combate, seguidamente manda el capitan/médico al centro y alerta a los otros compañeros que acudan a ayudar*/
+enemies_in_fov(ID, TYPE, ANGLE, DIST, HEALTH, [X,Y,Z]):team(200) & not combate & captain(C)
 <-
 +combate;
 -+checking;
 .goto([X,Y,Z]);
 -+tg(ID);
 .look_at([X,Y,Z]);
 .shoot(5,[X,Y,Z]);
 +check;
 .send(C, tell, veteAlCentro([X,Y,Z]));
 .print("Entrando en combate!").

/*Cuando esta en combate y no tiene que huir, ya que tiene vida y munición sige disparando al enemigo*/
+enemies_in_fov(ID, TYPE, ANGLE, DIST, HEALTH, [X,Y,Z]):team(200) & combate & not huir 
 <-
  -+estadoAlerta(0);
  -+objetivo([X,Y,Z]);
  .look_at([X,Y,Z]);
  .goto([X,Y,Z]);
  .shoot(1, [X,Y,Z]).

/*Comprueba la distacia con el objetivo, si la distancia es pequeña, entonces incrementa el ataque, ya que sabemos que no se trata de un falso ataque*/
+enemies_in_fov(ID, TYPE, ANGLE, DIST, HEALTH, [X,Y,Z]):team(200) & combate & position(P)
  <-
  .distancia([X,Y,Z], P, D);
  if(D > 30){
    .look_at([X,Y,Z]);
  };
  if(D < 20){
    .look_at([X,Y,Z]);
    .shoot(5, [X,Y,Z]);
  }.

/*Bucle constante que se encarga de comprobar la vida y la munición. También sabemos si tiene que ir a por los paquetes o si se acerca el fieldops o el médico.*/
+check: team(200) & combate & ammo(A) & health(H) & not huir & position(P) & objetivo(O)
  <-
  /*.wait(3000);*/
  -check;
  .look_at(O);
  .goto(O);
  if(H < 40 | A < 20){
    +huir;
    +reuniendose;
    ?flag(F);
    .goto(F);
    ?captain(C);
    .send(C, tell, help(P));
  }.

/*Realiza la comporabación de check de forma continua con un pequeño delay*/
+bucle 
  <- 
  -+check; 
  .wait(3000);
  -+bucle.


// /** Debugger, por si no hay amenaza o el agente se queda pillado, pues poder continuar con su labor,
// utiliza el contador estado alarma que se resetea cada vez que detecta algo, si no se resetea, empezara a 
// dirigirse al centro, luego inentará patrullar, si lo consigue, seguirá apatrullando **/
// +checking: team(200) & estadoAlerta(E) & combate
//   <- 
//   .wait(2000);
//   -+estadoAlerta(E +1);
//   if( E > 3){
//     -+estadoAlerta(0);
//     -amenaza;
//     ?flag(F);
//     .goto(F);
//     !patrullar;
//     +check;
//   } 
//   -+checking.

+reunion(P)[source(S)]: team(200)
  <-
  -+reuniendose;
  +huir;
  .goto(P);

/* El agente va a por paquetes y da una vuelta para localizarlos cuando llega al punto*/
+target_reached(T):reuniendose
  <-
  -reuniendose;
  +paquetes;
  +check;
  .print("Estoy aqui").

/** Cuando localiza el paquete, va a por el **/
+packs_in_fov(ID, TYPE, ANGLE, DIST, HEALTH, [X,Y,Z]): paquetes
  <-
  -paquetes;
  +aporpaquete;
  .goto([X,Y,Z]);
  .wait(2000);
  .look_at([X,Y,Z]);
  .print("Vamos por paquete").

+target_reached(T): aporpaquete
  <-
  -aporpaquete;
  -huir;
  .print("Paquete cogido");
  +check.

/* Pide ayuda a sus amigos, */ 
+friends_in_fov(ID, TYPE, ANGLE, DIST, HEALTH, [X,Y,Z]):team(200) & combate & soldados(SS)
  <-
  .nth(ID, SS,S);
  .send(S, tell, ayudame([X,Y,Z]));

/* Llama a alguien para que venga a asistir*/
+ayudame([X,Y,Z])[source(S)]: team(200) & not combate
 <-
 .look_at([X,Y,Z]);
 .goto([X,Y,Z]);
 -+combate;

+ponercombate <- -+combate; -ponercombate; .print("Entrando en combate!!!").