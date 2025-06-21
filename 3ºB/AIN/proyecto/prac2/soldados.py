from loguru import logger
from pygomas.agents.bditroop import BDITroop
from pygomas.agents.bdifieldop import BDIFieldOp
from pygomas.agents.bdimedic import BDIMedic
import random

class BDITropa(BDIFieldOp, BDITroop):

        def add_custom_actions(self, actions):
            super().add_custom_actions(actions)
        
            @actions.add_function(".distanciaMedia", (tuple,tuple, ))
            def _distanciaMedia(p1, p2):
                "Devuelve la distancia media que hay entre dos puntos"
                return ((p1[0] + p2[0])/2, 0, (p1[2]+ p2[2])/2)
            
            @actions.add_function(".next", (tuple,tuple, ))
            def _next(pos, flag):
                # Devuelve el valor de la próxima posible posición 
                (px, py, pz) = pos
                (fx, fy, fz) = flag

                def dist(p1, p2):
                    return ((p1[0]-p2[0])**2+(p1[1]-p2[1])**2)**0.5

                while True:

                    pnx = px + random.randint(-50,50)
                    pnz= pz + random.randint(-50,50)

                    if self.map.can_walk(pnx, pnz) and 20 < dist((pnx, pnz), (fx, fz)) <= 50: 
                        # Si la nueva posición es visitable y además cumple que se encuentra a una distancia entre 20 y 50 unidades de la bandera, rompemos el bucle 
                        break
                
                "La coordenada y no cambia porque no tenemos altura"
                return (pnx, 0, pnz)
