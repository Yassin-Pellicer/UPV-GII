pygomas manager -np 11 -j manager_yjpellam@gtirouter.dsic.upv.es -sj manager_yjpellam@gtirouter.dsic.upv.es -m map_arena
pygomas render 
pygomas run -g game_arena.json 

EN ESE ORDEN

si funciona mal pero el proceso sigue ejecutándose -> 
ejecutar en nueva terminal: fuser -n tcp -k 8001 

He añadido un ejemplo.asl que implementa un ejemplo de agente del que podemos partir!
