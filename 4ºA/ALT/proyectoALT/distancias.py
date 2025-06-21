import numpy as np

def levenshtein_matriz(x, y, threshold=None):
    # esta versión no utiliza threshold, se pone porque se puede
    # invocar con él, en cuyo caso se ignora
    lenX, lenY = len(x), len(y)
    D = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        D[i][0] = D[i - 1][0] + 1
    for j in range(1, lenY + 1):
        D[0][j] = D[0][j - 1] + 1
        for i in range(1, lenX + 1):
            D[i][j] = min(
                D[i - 1][j] + 1,
                D[i][j - 1] + 1,
                D[i - 1][j - 1] + (x[i - 1] != y[j - 1]),
            )
            
    return D[lenX, lenY]
    
def levenshtein_edicion(x, y, threshold=None):
    # a partir de la versión levenshtein_matriz
    '''
    Hecho por Yassin Pellicer Lamla
    '''
    lenX, lenY = len(x), len(y)
    D = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        D[i][0] = D[i - 1][0] + 1
    for j in range(1, lenY + 1):
        D[0][j] = D[0][j - 1] + 1
        for i in range(1, lenX + 1):
            D[i][j] = min(
                D[i - 1][j] + 1,
                D[i][j - 1] + 1,
                D[i - 1][j - 1] + (x[i - 1] != y[j - 1])
            )
            
    X = lenX
    Y = lenY
    path = []
    while X > 0 or Y > 0:
        # DIAGONAL (SUSTITUCIÓN):
        # se ha hecho una sustitución, por lo que la distancia
        # entre x y y es la misma que la de x[0..X-1] y y[0..Y-1]
        # más 1 si x[X-1] no es igual a y[Y-1] (lo que costaría 1 operación de edición)
        if X > 0 and Y > 0 and D[X, Y] == (D[X - 1, Y - 1] + (x[X - 1] != y[Y - 1])):
            xi = X - 1
            yi = Y - 1
            to_append = (x[xi], y[yi])
        
        # IZQUIERDA (ELIMINACIÓN):
        elif X > 0 and D[X, Y] == D[X - 1, Y] + 1:
            xi = X - 1
            yi = Y
            to_append = (x[xi], "")
        
        # ABAJO (ADICIÓN):
        else:
            xi = X
            yi = Y - 1
            to_append = ("", y[yi])
        
        path.append(to_append)
        X = xi
        Y = yi
        
    path.reverse()
    return D[lenX, lenY], path

def levenshtein_reduccion(x, y, threshold=None):
    # completar versión con reducción coste espacial
    # se hace una reducción POR FILAS
    '''
    Hecho por Yassin Pellicer Lamla
    '''
    iter = 0
    lenX, lenY = len(x), len(y)
    # Establecemos las columnas necesarias
    current = np.zeros(lenX + 1, dtype=int)
    next = np.zeros(lenX + 1, dtype=int) 
    for i in range(1, lenX + 1):
        # Inicializamos la columna actual a 0,1,2, ..., lenX (es la del principio)
        current[i] = current[i - 1] + 1
    for j in range(1, lenY + 1):
        # Copiamos siempre el valor izquierdo de la columna siguiente del de la anterior + 1
        next[0] = current[0] + 1
        for i in range(1, lenX + 1):
            next[i] = min(
                # IZQUIERDA
                next[i - 1] + 1,
                # ABAJO
                current[i] + 1,
                # DIAGONAL
                current[i - 1] + (x[i - 1] != y[j - 1]),
            )
        # intercambiamos las columnas para que el valor next se convierta en el actual
        # para la nueva iteración
        current, next = next, current

    return current[lenX]

def levenshtein(x, y, threshold):
    # completar versión reducción coste espacial y parada por threshold
    # SE HACE LA OPTIMIZACIÓN POR COLUMNAS (sólo se necesitan 2)
    '''
    Hecho por Yassin Pellicer Lamla
    '''
    lenX, lenY = len(x), len(y)
    # Establecemos las columnas necesarias
    current = np.zeros(lenX + 1, dtype=int)
    next = np.zeros(lenX + 1, dtype=int) 
    for i in range(1, lenX + 1):
        # Inicializamos la columna actual a 0,1,2, ..., lenX (es la del principio)
        current[i] = current[i - 1] + 1
    for j in range(1, lenY + 1):
        # Copiamos siempre el valor izquierdo de la columna siguiente del de la anterior + 1
        next[0] = current[0] + 1
        # Declaramos la variable th que comprueba si el threshold se sigue cumpliendo
        th = True
        # Comprobación del threshold. Si el valor de next es menor o igual que threshold se continúa.
        # Lo mismo ocurre si next es igual a threshold y quedan la misma cantidad de términos por analizar
        # por parte de una palabra que de otra, ya que no se pueden obtener valores por debajo del threshold
        # en este punto.
        for i in range(1, lenX + 1):
            next[i] = min(
                # IZQUIERDA
                next[i - 1] + 1,
                # ABAJO
                current[i] + 1,
                # DIAGONAL
                current[i - 1] + (x[i - 1] != y[j - 1]),
            )
            if next[i] < threshold: th = False
            elif(next[i] == threshold and lenX - i == lenY - j): th = False
        if(th): return threshold+1
        next, current = current, next

    return current[lenX]

def levenshtein_cota_optimista(x, y, threshold):
    lenX, lenY = len(x), len(y)
    if abs(lenX - lenY) > threshold:
        return threshold + 1
    current = np.zeros(lenX + 1, dtype=int)
    next = np.zeros(lenX + 1, dtype=int)
    for i in range(1, lenX + 1):
        current[i] = current[i - 1] + 1
    for j in range(1, lenY + 1):
        next[0] = current[0] + 1
        th = True
        for i in range(1, lenX + 1):
            next[i] = min(
                next[i - 1] + 1,
                current[i] + 1,
                current[i - 1] + (x[i - 1] != y[j - 1])
            )
            if next[i] < threshold:
                th = False
            elif next[i] == threshold and lenX - i == lenY - j:
                th = False
        if th:
            return threshold + 1
        current, next = next, current
    return current[lenX]

def damerau_restricted_matriz(x, y, threshold=None):
    # completar versión Damerau-Levenstein restringida con matriz
    lenX, lenY = len(x), len(y)
    matriz = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        matriz[i][0] = matriz[i - 1][0] + 1
    for j in range(1, lenY + 1):
        matriz[0][j] = matriz[0][j - 1] + 1
        for i in range(1, lenX + 1):
            matriz[i][j] = min(
                matriz[i - 1][j] + 1,
                matriz[i][j - 1] + 1,
                matriz[i - 1][j - 1] + (x[i - 1] != y[j - 1])
            )
            #Añadimos la regla de la nueva restricción de la transposición
            if j > 1 and i > 1:
                if x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1]:
                    matriz[i][j] = min(matriz[i][j], matriz[i-2][j-2] + 1)
    return matriz[lenX, lenY]

def damerau_restricted_edicion(x, y, threshold=None):
    # partiendo de damerau_restricted_matriz añadir recuperar
    # secuencia de operaciones de edición
    
    #Sacamos la matriz que usaremos ahora
    lenX, lenY = len(x), len(y)
    matriz = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        matriz[i][0] = matriz[i - 1][0] + 1
    for j in range(1, lenY + 1):
        matriz[0][j] = matriz[0][j - 1] + 1
        for i in range(1, lenX + 1):
            matriz[i][j] = min(
                matriz[i - 1][j] + 1,
                matriz[i][j - 1] + 1,
                matriz[i - 1][j - 1] + (x[i - 1] != y[j - 1])
            )
            #Añadimos la regla de la nueva restricción de la transposición
            if j > 1 and i > 1:
                if x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1]:
                    matriz[i][j] = min(matriz[i][j], matriz[i-2][j-2] + 1)
    
    X = len(x); Y = len(y); path = []
    while X > 0 or Y > 0:       
        #Ahora primero tendremos que ver si hay transposición o no
        if X > 1 and Y > 1 and (matriz[X-2][Y-2] <= min(matriz[X-1][Y-1], matriz[X][Y-1], matriz[X-1][Y])) and (x[X-2] == y[Y-1] and x[X-1] == y[Y-2]):
            xi = X-2
            yi = Y-2
            to_append = (x[xi] + x[X - 1], y[yi] + y[Y - 1])
        # DIAGONAL (SUSTITUCIÓN):
        # entre x y y es la misma que la de x[0..X-1] y y[0..Y-1]
        # más 1 si x[X-1] no es igual a y[Y-1] (lo que costaría 1 operación de edición)
        elif X > 0 and Y > 0 and matriz[X, Y] == (matriz[X - 1, Y - 1] + (x[X - 1] != y[Y - 1])):
            xi = X - 1
            yi = Y - 1
            to_append = (x[xi], y[yi])
        
        # IZQUIERDA (ELIMINACIÓN):
        elif X > 0 and matriz[X, Y] == matriz[X - 1, Y] + 1:
            xi = X - 1
            yi = Y
            to_append = (x[xi], "")
        
        # ABAJO (ADICIÓN):
        elif Y > 0 and matriz[X,Y] == matriz[X, Y-1] + 1:
            xi = X
            yi = Y - 1
            to_append = ("", y[yi])
        
        path.append(to_append)
        X = xi
        Y = yi
    path.reverse()
    return matriz[len(x),len(y)], path

def damerau_restricted(x, y, threshold=None):
    # versión con reducción coste espacial y parada por threshold
    lenX, lenY = len(x), len(y)
    # COMPLETAR
    iter = 0
    # Establecemos las columnas necesarias
    current = np.zeros(lenX + 1, dtype=int)
    next = np.zeros(lenX + 1, dtype=int)
    # Ahora necesitamos una columna más ya que necesitare una dependencia j-2
    postNext = np.zeros(lenX + 1, dtype=int)
    for i in range(1, lenX + 1):
        # Inicializamos la columna actual a 0,1,2, ..., lenX (es la del principio)
        current[i] = current[i - 1] + 1
    for j in range(1, lenY + 1):
        # Copiamos siempre el valor izquierdo de la columna siguiente del de la anterior + 1
        next[0] = current[0] + 1
        # En este caso ahora también tendremos que el valor de la columna postNext tendrá el valor de la anterior + 2
        postNext[0] = current[0] + 2
        # Declaramos la variable th que comprueba si el threshold se sigue cumpliendo
        th = True
        # Comprobación del threshold. Si el valor de next es menor o igual que threshold se continúa.
        # Lo mismo ocurre si next es igual a threshold y quedan la misma cantidad de términos por analizar
        # por parte de una palabra que de otra, ya que no se pueden obtener valores por debajo del threshold
        # en este punto.
        if next[i] < threshold: th = False
        elif(next[i] == threshold and lenX - i == lenY - j): th = False
        for i in range(1, lenX + 1):
            next[i] = min(
                # IZQUIERDA
                next[i - 1] + 1,
                # ABAJO
                current[i] + 1,
                # DIAGONAL
                current[i - 1] + (x[i - 1] != y[j - 1])
                )
            # Calculamos transposición si es aplicable
            if i > 1 and j > 1 and x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1]:
                next[i] = min(
                    current[i] + 1,
                    next[i-1] + 1,
                    current[i-1] + (x[i-1] != y[j - 1]),
                    postNext[i - 2] + 1
                    )
            if next[i] < threshold: th = False
            elif(next[i] == threshold and lenX - i == lenY - j): th = False
        if(th): return threshold+1
        next, current, postNext = postNext, next, current

    return current[lenX]

def damerau_intermediate_matriz(x, y, threshold=None):
    # completar versión Damerau-Levenstein intermedia con matriz
    lenX, lenY = len(x), len(y)
    # inicialización de la matriz de resultados intermedios a zeros
    D = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        D[i][0] = D[i - 1][0] + 1 # primera fila de Levenshtein 
    for j in range(1, lenY + 1):
        D[0][j] = D[0][j - 1] + 1 # primera columna de Levenshtein
        for i in range(1, lenX + 1):
            D[i][j] = min(
                D[i - 1][j] + 1, # borrado
                D[i][j - 1] + 1, # inserción
                D[i - 1][j - 1] + (x[i - 1] != y[j - 1]), # sustitución
                # Damerau
                # intercambio (versión restringida)
                D[i-2][j-2]+1 if (i > 1 and j > 1 and x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1]) else float('inf'),
                # intercambio (version intermedia)
                D[i-2][j-3]+2 if (i > 1 and j > 2 and x[i - 1] == y[j - 3] and x[i - 2] == y[j - 1]) else float('inf'),
                # intercambio (versión intermedia)
                D[i-3][j-2]+2 if (i > 2 and j > 1 and x[i - 1] == y[j - 2] and x[i - 3] == y[j - 1]) else float('inf')  
            )
    return D[lenX, lenY]

def damerau_intermediate_edicion(x, y, threshold=None):
    # partiendo de matrix_intermediate_damerau añadir recuperar
    # secuencia de operaciones de edición
    # completar versión Damerau-Levenstein intermedia con matriz
    lenX, lenY = len(x), len(y)
    D = np.zeros((lenX + 1, lenY + 1), dtype=int)
    for i in range(1, lenX + 1):
        D[i][0] = D[i - 1][0] + 1
    for j in range(1, lenY + 1):
        D[0][j] = D[0][j - 1] + 1
        for i in range(1, lenX + 1):
            D[i][j] = min(
                D[i - 1][j] + 1, # borrado
                D[i][j - 1] + 1, # inserción
                D[i - 1][j - 1] + (x[i - 1] != y[j - 1]), # sustitución
                # Damerau
                # intercambio (versión restringida)
                D[i-2][j-2]+1 if (i > 1 and j > 1 and x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1]) else float('inf'),
                # intercambio (version intermedia)
                D[i-2][j-3]+2 if (i > 1 and j > 2 and x[i - 1] == y[j - 3] and x[i - 2] == y[j - 1]) else float('inf'),
                # intercambio (versión intermedia)
                D[i-3][j-2]+2 if (i > 2 and j > 1 and x[i - 1] == y[j - 2] and x[i - 3] == y[j - 1]) else float('inf')  
            )

    # recuperación del camino
    # se parte desde la última posición de la matriz de resultados intermedios y se recorre en sentido inverso
    i, j = lenX, lenY
    l=[] # lista del camino
    while(i > 0 and j > 0):
        m = min(D[i-1][j], D[i][j-1], D[i-1][j-1]) 
        
        # caso intercambio (version intermedia)
        if i > 1 and j > 2 and x[i - 1] == y[j - 3] and x[i - 2] == y[j - 1] and D[i-2][j-3]+2 <= m:
            l.append((x[i - 2:i], y[j - 3:j]))
            # retrocedo en D
            i -= 2
            j -= 3
        # caso intercambio (version intermedia)
        elif i > 2 and j > 1 and x[i - 1] == y[j - 2] and x[i - 3] == y[j - 1] and D[i-3][j-2]+2 <= m:
            l.append((x[i - 3:i], y[j - 2:j]))
            i -= 3
            j -= 2
        # caso intercambio (version restringida)
        elif i > 1 and j > 1 and x[i - 1] == y[j - 2] and x[i - 2] == y[j - 1] and D[i-2][j-2]+1 <= m:
            l.append((x[i - 2:i], y[j - 2:j]))
            i -= 2
            j -= 2
        # caso sustitución
        elif m == D[i-1][j-1]:
                l.append((x[i-1], y[j-1]))
                i -= 1
                j -= 1
        # caso inserción
        elif m == D[i][j-1]:
            l.append(("", y[j-1]))
            j -= 1
        # caso borrado
        elif m == D[i-1][j]:
            l.append((x[i-1], ""))
            i -= 1
                    
    # caso en el que aún queden simbolos de x (borrados)
    while i > 0:
        l.append((x[i-1], ""))
        i -= 1
    # caso en el que aún queden simbolos de y (inserciones)
    while j > 0:
        l.append(("", y[j-1]))
        j -= 1

    l.reverse() # para dar el camino ordenado en sentido ascendente
    return D[lenX][lenY], l
    
def damerau_intermediate(x, y, threshold=None):
    # versión con reducción coste espacial y parada por threshold
    lenX, lenY = len(x), len(y)
    # ventana de los únicos 3 vectores que se necesitan para realizar las comprobaciones
    row1 = list(range(lenX + 1))
    row2 = [0] * (lenX + 1)
    row3 = [0] * (lenX + 1)

    for i in range(1, lenY + 1):
        rowActual = [0] * (lenX + 1)
        rowActual[0] = i
        for j in range(1, lenX + 1):
            rowActual[j] = min(
                rowActual[j - 1] + 1, # borrado
                row1[j] + 1, # inserción
                row1[j - 1] + (x[j - 1] != y[i - 1]), # sustitución
                # Damerau
                # intercambio (versión restringida)
                row2[j - 2] + 1 if (i > 1 and j > 1 and x[j - 2] == y[i - 1] and x[j - 1] == y[i - 2]) else float('inf'),
                # intercambio (versión intermedia)
                row2[j - 3] + 2 if (i > 1 and j > 2 and x[j - 1] == y[i - 2] and x[j - 3] == y[i - 1]) else float('inf'),
                # intercambio (versión intermedia)
                row3[j - 2] + 2 if (i > 2 and j > 1 and x[j - 2] == y[i - 1] and x[j - 1] == y[i - 3]) else float('inf')
            )
        # reasignación de los vectores para la próxima iteración    
        row3 = row2.copy()
        row2 = row1.copy()
        row1 = rowActual.copy()
        
        if threshold is not None and all(d > threshold for d in row1):
            return threshold + 1
    return min(row1[-1], threshold + 1)

opcionesSpell = {
    'levenshtein_m': levenshtein_matriz,
    'levenshtein_r': levenshtein_reduccion,
    'levenshtein':   levenshtein,
    'levenshtein_o': levenshtein_cota_optimista,
    'damerau_rm':    damerau_restricted_matriz,
    'damerau_r':     damerau_restricted,
    'damerau_im':    damerau_intermediate_matriz,
    'damerau_i':     damerau_intermediate
}

opcionesEdicion = {
    'levenshtein': levenshtein_edicion,
    'damerau_r':   damerau_restricted_edicion,
    'damerau_i':   damerau_intermediate_edicion
}

