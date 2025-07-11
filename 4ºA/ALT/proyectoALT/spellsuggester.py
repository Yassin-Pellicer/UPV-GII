# -*- coding: utf-8 -*-
import re
import distancias
class SpellSuggester:

    """
    Clase que implementa el método suggest para la búsqueda de términos.
    """

    def __init__(self,
                 dist_functions,
                 vocab = [],
                 default_distance = None,
                 default_threshold = None):
        
        """Método constructor de la clase SpellSuggester

        Construye una lista de términos únicos (vocabulario),

        Args:
           dist_functions es un diccionario nombre->funcion_distancia
           vocab es una lista de palabras o la ruta de un fichero
           default_distance debe ser una clave de dist_functions
           default_threshold un entero positivo

        """
        self.distance_functions = dist_functions
        self.set_vocabulary(vocab)
        if default_distance is None:
            default_distance = 'levenshtein'
        if default_threshold is None:
            default_threshold = 3
        self.default_distance = default_distance
        self.default_threshold = default_threshold

    def build_vocabulary(self, vocab_file_path):
        """Método auxiliar para crear el vocabulario.

        Se tokeniza por palabras el fichero de texto,
        se eliminan palabras duplicadas y se ordena
        lexicográficamente.

        Args:
            vocab_file (str): ruta del fichero de texto para cargar el vocabulario.
            tokenizer (re.Pattern): expresión regular para la tokenización.
        """
        tokenizer=re.compile("\W+")
        with open(vocab_file_path, "r", encoding="utf-8") as fr:
            vocab = set(tokenizer.split(fr.read().lower()))
            vocab.discard("")  # por si acaso
            return sorted(vocab)

    def set_vocabulary(self, vocabulary):
        if isinstance(vocabulary,list):
            self.vocabulary = vocabulary # atención! nos quedamos una referencia, a tener en cuenta
        elif isinstance(vocabulary,str):
            self.vocabulary = self.build_vocabulary(vocabulary)
        else:
            raise Exception("SpellSuggester incorrect vocabulary value")
    
    def suggest(self, term, distance=None, threshold=None, flatten=True):
        """
        Args:
            term (str): término de búsqueda.
            distance (str): nombre del algoritmo de búsqueda a utilizar
            threshold (int): threshold máximo para limitar la búsqueda
            flatten (bool): si True, devuelve una lista plana, si False, devuelve una lista de listas
        Returns:
            list: lista de palabras sugeridas organizadas por distancia (lista de listas).
        """

        """Guillermo Sanchis Terol"""
        if distance is None:
            distance = self.default_distance
        if threshold is None:
            threshold = self.default_threshold

        # Obtener la función de distancia basada en el nombre proporcionado
        distance_func = self.distance_functions.get(distance)
        if not distance_func:
            raise ValueError(f"No se ha encontrado '{distance}' entre las funciones disponibles.")

        # Crear una lista de listas para almacenar las palabras por distancia
        resul = []
        for th in range (0, threshold + 1):
            newresul = []
            for palabra in self.vocabulary:
                # Calcular la distancia y añadir la palabra a la lista correspondiente
                if distance_func(term, palabra, th) == th:
                    newresul.append(palabra)
            resul.append(newresul)
        if flatten:
            return [item for sublist in resul for item in sublist]
        else:
            return resul

