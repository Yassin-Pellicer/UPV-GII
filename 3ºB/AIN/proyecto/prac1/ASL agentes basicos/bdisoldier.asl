

+flag(F): team(200)
<-
+mirando([[0,0,0],[250,0,0],[250,0,250],[0,0,250]]);
+estado(0);
!agirar.

+friends_in_fov(ID,Type,Angle,Distance,Health,Position)
<-
.print("Disparo");
.shoot(4,Position).

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