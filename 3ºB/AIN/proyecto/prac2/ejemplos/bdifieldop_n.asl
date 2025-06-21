/*Falta registrar servicio*/
+flag(F): team(200)
    <-
    +f(F);
    .wait(3000);
    .get_service("capitan");
    .goto(F).

/*Cuando aparece el capitan, lo registramos en una variable*/
+capitan(C)
<-
    +captain(C);
    .print("Buenos dias Capitan").

/*Cuando llega al centro empieza a generar paquetes de munición*/
target_reached(T): team 200
<-
    .reload;
    .print("Paquetes de munición en el centro").


/*El capitán da ordenes para que vaya a la posición P. Solamente usado para que vaya la centro*/
+dirigeteA(P)
<-
    .goto(P).

/*Da vueltas para comprobar si hay alguien a la vista*/
+check: team(200) & position([X,Y,Z])
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
  -check.

/*Le llega un send, que le indica que vaya al centro. El centro se refiere a la posición de la bandara. Una vez allí se encarga de activar el modo combate*/
+venAlCentro:f(F)
  <-
  +combate;
  .goto(F);
  .print("Entendido");
  .look_at(F).

/*Cuando esta en el centro, empieza a generar botiquines y lanza comprobar, creencia que lo pone a dar vueltas para observar lo que ocurre*/
+target_reached(T): combate
 <-
 .reload;
 +crearMunicion;
 +check.

/*Empieza a crear paquetes de municion sin parar cada 4 segundos, tenemos que poner un delay porque necesitan un tiempo mínimo para recargar la stamina*/
+crearMunicion
  <-
  .cure;
  .wait(4000);
  -+crearMunicion.
