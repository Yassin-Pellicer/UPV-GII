import json
from loguru import logger
from spade.behaviour import OneShotBehaviour
from spade.template import Template
from spade.message import Message
from pygomas.agents.bditroop import BDITroop
from pygomas.agents.bdifieldop import BDIFieldOp
from pygomas.agents.bdimedic import BDIMedic
from agentspeak import Actions
from agentspeak import grounded
from agentspeak.stdlib import actions as asp_action
from pygomas.ontology import HEALTH
import random
import random as rnd
from pygomas.ontology import DESTINATION
import math
import random
from pygomas.agents import LONG_RECEIVE_WAIT

class BDITropa(BDIFieldOp, BDITroop, BDIMedic):

        def add_custom_actions(self, actions):
            super().add_custom_actions(actions)

           @actions.add_function(".distancia", (tuple,tuple, ))
            def _distancia(p1, p2):
                "Devuelve la distancia Euclidea que hay entre dos puntos"
                return ((p1[0]-p2[0])**2+(p1[2]-p2[2])**2)**0.5

            @actions.add_function(".distanciaMedia", (tuple,tuple, ))
            def _distanciaMedia(p1, p2):
                "Devuelve la distancia media que hay entre dos puntos"
                return ((p1[0] + p2[0])/2, 0, (p1[2]+ p2[2])/2)

            @actions.add_function(".banderaTomada", ())
            def _banderaTomada():
                "Función que le permite conocer a un agente cuando le han robado la bandera 1, cuando la han robado 0 en caso contrario"
                return 1 if self.is_objective_carried else 0
                
            @actions.add_function(".soldados",())
            def _soldados():
                "Devuelve el número de doldados vivos"
                return self.soldiers_count
            
            @actions.add_function(".canGO", (tuple, ))
            def _canGo(position):
                "Método que nos permite conocer si dada una posición el viaje hasta dicha posición es posible"
                
                X, Y, Z = position
                return 1 if self.map.can_walk(X, Z) else 0
            
            @actions.add_function(".tryGO", (tuple, tuple, ))
            def _tryGO(position, posEnemy):
                "Comprueba si es posible moverse a una posición, en caso de serlo se desplaza hasta ella, en caso contrario no y se desplaza hasta la posición de un enemigo"
                X, Y, Z = position
                if self.map.can_walk(X,Z):
                    return position
                else:
                    return posEnemy
        
            @actions.add_function(".centradoEn", ())
            def _centradoEn():
                "Devuelve el Id del agente en el que se está centrando"
                return self.aimed_agent

            def _next(pos, flag):
                "Devuelve el valor de la próxima posible posición"
                (px, py, pz) = pos
                (fx, fy, fz) = flag

                def dist(p1, p2):
                    return ((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**0.5

                while True:

                    pnx = px + random.randint(-50,50)
                    pnz= pz + random.randint(-50,50)

                    if self.map.can_walk(p1, p2) and 20 < dist((p1, p2), (fx, fz)) <= 50: 
                        "Si la nueva posición es visitable y además cumple que se encuentra a una distancia entre 20 y 50 unidades de la bandera, rompemos el bucle"
                        break
                
                "La coordeanda y no cambia porque no tenemos altura"
                return (pnx, 0, pnz)
            

            "Acciones únicas para el líder"

            @actions.add_function(".delF",(tuple,))
            def _delF(t):
                "Elimina último elemento de la lista"

                "Implementado ya que algunas listas nos estaban causando problemas para manejarlas debido a elementos vacíos"
                return t[1:]

            @actions.add_function(".centradoEn", (tuple,tuple ))
            def _centradoEn(pos, flag):
                "Devuelve el ID del agentes más cercano a la bandear"
                
                
                def dist(p1, p2):
                    return ((p1[0]-p2[0])**2+(p1[2]-p2[2])**2)**0.5
                npos = flag
                d = 200
                for i in range(len(pos)):
                    if dist(pos[i], flag) < d:
                        npos = pos[i]
                return npos
            
            #Acciones que realiza el líder unicamente
            @actions.add_function(".defencePOS", (tuple, ))
            def _defencePOS(flagPOS):
                '''
                    Given the agents list and the flag position, 
                    we'll calculate 4 positions of defence in circle,
                    with the minimum distance between the agents so they could 
                    come fast to help, the final list will be the 4 positions for agents.

                    Also we know that the view range of agents are 50v.p, so the remaining
                    distance will be 24 v.p between agents, if not, this distance will
                    decrease.
                '''
                fX, fY, fZ = flagPOS

                positions = []
                cc = 25#17 # CC == CO
                print("[ L ]: The flag is at [",fX,",",fZ,"]" )
                   
                x = 0; z = 0
                i = 0
                # left up
                x = fX - cc
                z = fZ + cc
                while not self.map.can_walk(fX - cc, fZ + cc):
                    x = fX - cc + i
                    z = fZ + cc - i
                    i += 1
                pos1 = (x, 0, z)    

                i = 0
                # right up
                x = fX + cc
                z = fZ + cc
                while not self.map.can_walk(fX - cc, fZ + cc):
                    x = fX + cc - i
                    z = fZ + cc - i
                    i += 1
                pos2 = (x, 0, z) 

                i = 0
                # left down
                x = fX - cc
                z = fZ - cc
                while not self.map.can_walk(fX - cc, fZ + cc):
                    x = fX - cc + i
                    z = fZ - cc + i
                    i += 1
                pos4 = (x, 0, z) 

                i = 0
                # right down
                x = fX + cc
                z = fZ - cc
                while not self.map.can_walk(fX - cc, fZ + cc):
                    x = fX + cc - i
                    z = fZ - cc + i
                    i += 1
                pos3 = (x, 0, z) 

                print("Puntos: ", pos1, pos2, pos3, pos4)
                return (pos1, pos2, pos3, pos4)




