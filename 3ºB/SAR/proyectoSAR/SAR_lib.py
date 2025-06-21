import json
from nltk.stem.snowball import SnowballStemmer
import os
import re
import sys
import math
from pathlib import Path
from typing import Optional, List, Union, Dict
import pickle

class SAR_Indexer:
    """
    Prototipo de la clase para realizar la indexacion y la recuperacion de artículos de Wikipedia
        
        Preparada para todas las ampliaciones:
          parentesis + multiples indices + posicionales + stemming + permuterm

    Se deben completar los metodos que se indica.
    Se pueden añadir nuevas variables y nuevos metodos
    Los metodos que se añadan se deberan documentar en el codigo y explicar en la memoria
    """

    # lista de campos, el booleano indica si se debe tokenizar el campo
    # NECESARIO PARA LA AMPLIACION MULTIFIELD
    fields = [
        ("all", True), ("title", True), ("summary", True), ("section-name", True), ('url', False),
    ]
    def_field = 'all'
    PAR_MARK = '%'
    # numero maximo de documento a mostrar cuando self.show_all es False
    SHOW_MAX = 10

    all_atribs = ['urls', 'index', 'sindex', 'ptindex', 'docs', 'weight', 'articles',
                  'tokenizer', 'stemmer', 'show_all', 'use_stemming']

    def __init__(self):
        """
        Constructor de la classe SAR_Indexer.
        NECESARIO PARA LA VERSION MINIMA

        Incluye todas las variables necesaria para todas las ampliaciones.
        Puedes añadir más variables si las necesitas 

        """
        self.urls = set() # hash para las urls procesadas,
        self.index = {'all':{},'title':{}, 'summary':{},'section-name':{},'url':{}} # hash para el indice invertido de terminos --> clave: termino, valor: posting list
        self.sindex = {'all':{},'title':{}, 'summary':{},'section-name':{},'url':{}} # hash para el indice invertido de stems --> clave: stem, valor: lista con los terminos que tienen ese stem
        self.ptindex = {'all':{},'title':{}, 'summary':{},'section-name':{},'url':{}} # hash para el indice permuterm.
        self.docs = {} # diccionario de terminos --> clave: entero(docid),  valor: ruta del fichero.
        self.weight = {} # hash de terminos para el pesado, ranking de resultados.
        self.articles = {} # hash de articulos --> clave entero (artid), valor: la info necesaria para diferencia los artículos dentro de su fichero
        self.tokenizer = re.compile("\W+") # expresion regular para hacer la tokenizacion
        self.stemmer = SnowballStemmer('spanish') # stemmer en castellano
        self.show_all = False # valor por defecto, se cambia con self.set_showall()
        self.show_snippet = False # valor por defecto, se cambia con self.set_snippet()
        self.use_stemming = False # valor por defecto, se cambia con self.set_stemming()
        self.use_ranking = False  # valor por defecto, se cambia con self.set_ranking()
        # añadimos contadores que nos ayudarán a imprimir por pantalla los stats de la indexación
        self.counterFiles = 0


    ###############################
    ###                         ###
    ###      CONFIGURACION      ###
    ###                         ###
    ###############################


    def set_showall(self, v:bool):
        """

        Cambia el modo de mostrar los resultados.
        
        input: "v" booleano.

        UTIL PARA TODAS LAS VERSIONES

        si self.show_all es True se mostraran todos los resultados el lugar de un maximo de self.SHOW_MAX, no aplicable a la opcion -C

        """
        self.show_all = v


    def set_snippet(self, v:bool):
        """

        Cambia el modo de mostrar snippet.
        
        input: "v" booleano.

        UTIL PARA TODAS LAS VERSIONES

        si self.show_snippet es True se mostrara un snippet de cada noticia, no aplicable a la opcion -C

        """
        self.show_snippet = v


    def set_stemming(self, v:bool):
        """

        Cambia el modo de stemming por defecto.
        
        input: "v" booleano.

        UTIL PARA LA VERSION CON STEMMING

        si self.use_stemming es True las consultas se resolveran aplicando stemming por defecto.

        """
        self.use_stemming = v



    #############################################
    ###                                       ###
    ###      CARGA Y GUARDADO DEL INDICE      ###
    ###                                       ###
    #############################################


    def save_info(self, filename:str):
        """
        Guarda la información del índice en un fichero en formato binario
        
        """
        info = [self.all_atribs] + [getattr(self, atr) for atr in self.all_atribs]
        with open(filename, 'wb') as fh:
            pickle.dump(info, fh)

    def load_info(self, filename:str):
        """
        Carga la información del índice desde un fichero en formato binario
        
        """
        #info = [self.all_atribs] + [getattr(self, atr) for atr in self.all_atribs]
        with open(filename, 'rb') as fh:
            info = pickle.load(fh)
        atrs = info[0]
        for name, val in zip(atrs, info[1:]):
            setattr(self, name, val)

    ###############################
    ###                         ###
    ###   PARTE 1: INDEXACION   ###
    ###                         ###
    ###############################

    def already_in_index(self, article:Dict) -> bool:
        """

        Args:
            article (Dict): diccionario con la información de un artículo

        Returns:
            bool: True si el artículo ya está indexado, False en caso contrario
        """
        return article['url'] in self.urls


    def index_dir(self, root:str, **args):
        """
        
        Recorre recursivamente el directorio o fichero "root" 
        NECESARIO PARA TODAS LAS VERSIONES
        
        Recorre recursivamente el directorio "root"  y indexa su contenido
        los argumentos adicionales "**args" solo son necesarios para las funcionalidades ampliadas

        """
        self.multifield = args['multifield']
        self.positional = args['positional']
        self.stemming = args['stem']
        self.permuterm = args['permuterm']

        file_or_dir = Path(root)
        
        if file_or_dir.is_file():
            # is a file
            self.index_file(root)
            self.counterFiles += 1
        elif file_or_dir.is_dir():
            # is a directory
            for d, _, files in os.walk(root):
                for filename in files:
                    if filename.endswith('.json'):
                        fullname = os.path.join(d, filename)
                        self.index_file(fullname)
                        self.counterFiles += 1
        else:
            print(f"ERROR:{root} is not a file nor directory!", file=sys.stderr)
            sys.exit(-1)

        if self.stemming:
            self.make_stemming()
        # Si se activa la función de permuterm
        if self.permuterm:
            self.make_permuterm()
        
        
    def parse_article(self, raw_line:str) -> Dict[str, str]:
        """
        Crea un diccionario a partir de una linea que representa un artículo del crawler

        Args:
            raw_line: una linea del fichero generado por el crawler

        Returns:
            Dict[str, str]: claves: 'url', 'title', 'summary', 'all', 'section-name'
        """
        
        article = json.loads(raw_line)
        sec_names = []
        txt_secs = ''
        for sec in article['sections']:
            txt_secs += sec['name'] + '\n' + sec['text'] + '\n'
            txt_secs += '\n'.join(subsec['name'] + '\n' + subsec['text'] + '\n' for subsec in sec['subsections']) + '\n\n'
            sec_names.append(sec['name'])
            sec_names.extend(subsec['name'] for subsec in sec['subsections'])
        article.pop('sections') # no la necesitamos 
        article['all'] = article['title'] + '\n\n' + article['summary'] + '\n\n' + txt_secs
        article['section-name'] = '\n'.join(sec_names)

        return article
                
    
    def index_file(self, filename:str):
        """

        Indexa el contenido de un fichero.
        
        input: "filename" es el nombre de un fichero generado por el Crawler cada línea es un objeto json
            con la información de un artículo de la Wikipedia

        NECESARIO PARA TODAS LAS VERSIONES

        dependiendo del valor de self.multifield y self.positional se debe ampliar el indexado


        """
        self.docs[len(self.docs)] = filename
        for i, line in enumerate(open(filename)):
            j = self.parse_article(line)
            artid = len(self.articles) + 1
            if(self.already_in_index(j)):
                continue
            else:
                self.urls.add(j['url'])

            if self.multifield:
                multiSet = self.fields
            else:
                multiSet = [self.fields[0]]                             #comprobamos si tenemos que hacer una indexación multicampo...
            for field, allow in multiSet:                               #en ese caso, hacemos un índice por campo           
                self.articles[artid] = (len(self.docs),i)           #metemos el articulo en el diccionario si no estaba ya indexado
                txt = j[field]                                      #asignamos a txt todo el texto del articulo j
                if allow: 
                    txt = txt.lower()                               #lo pasamos a minuscula
                    txt = self.tokenizer.split(txt)                 #eliminamos todos los terminos no alfanumericos si el campo lo permite
                
                    if self.positional:
                        for term in txt:                                                   #asociamos una lista a cada término
                            if term not in self.index[field]:
                                self.index[field][term] = {}                             #si buscamos índices posicionales...
                        for pos, term in enumerate(txt):
                            if artid not in self.index[field][term]: 
                                self.index[field][term][artid] = [pos]
                            if pos not in self.index[field][term][artid]:                   #para cada entrada (termino) del dicc vamos añadiendo los articulos en los que salen
                                self.index[field][term][artid].append(pos)
                    else:
                        for term in txt:                                                   #asociamos una lista a cada término
                            if term not in self.index[field]:
                                self.index[field][term] = []
                            if artid not in self.index[field][term]: 
                                self.index[field][term].append(artid)
        
                else:                                                       #tratamiento especial para los términos no tokenizados
                    if txt not in self.index[field]:
                        self.index[field][txt] = []  
                    if txt not in self.index[field][txt]: 
                        self.index[field][txt].append(artid)

            
           
       # self.docs[len(self.docs)] = os.path.dirname(filename)   #añadimos el documento como procesado en el diccionario


    def set_stemming(self, v:bool):
        """

        Cambia el modo de stemming por defecto.
        
        input: "v" booleano.

        UTIL PARA LA VERSION CON STEMMING

        si self.use_stemming es True las consultas se resolveran aplicando stemming por defecto.

        """
        self.use_stemming = v


    def tokenize(self, text:str):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Tokeniza la cadena "texto" eliminando simbolos no alfanumericos y dividientola por espacios.
        Puedes utilizar la expresion regular 'self.tokenizer'.

        params: 'text': texto a tokenizar

        return: lista de tokens

        """
        return self.tokenizer.sub(' ', text.lower()).split()


    def make_stemming(self):
        """

        Crea el indice de stemming (self.sindex) para los terminos de todos los indices.

        NECESARIO PARA LA AMPLIACION DE STEMMING.

        "self.stemmer.stem(token) devuelve el stem del token"


        """
        if self.multifield:
            multifield = ["all", "title", "summary", "section-name", 'url']
        else:
            multifield = ['all']

        for field in multifield:
            for key in self.index[field]:
                stem = self.stemmer.stem(key)
                if stem not in self.sindex[field]:
                    self.sindex[field][stem] = [key]
                else:
                    if key not in self.sindex[field][stem]:
                        self.sindex[field][stem] += [key] 

    
    def make_permuterm(self):
        """

        Crea el indice permuterm (self.ptindex) para los terminos de todos los indices.

        NECESARIO PARA LA AMPLIACION DE PERMUTERM


        """
        self.use_permuterm = True
        
        if self.multifield:
            multifield = ["all", "title", "summary", "section-name", 'url']
        else:
            multifield = ['all']

        for field in multifield:
            for key in self.index[field]:
                key2 = key + '$'
                permutaciones = [key2[i:] + key2[:i] for i in range(len(key2))]
                for perm in permutaciones:
                    self.ptindex[field][perm] = key
                            

    def show_stats(self):
        """
        NECESARIO PARA TODAS LAS VERSIONES
        
        Muestra estadisticas de los indices
        
        """
        print("========================================")
        print("Number of indexed files: ", self.counterFiles)
        print("----------------------------------------")
        print("Number of indexed articles: ", len(self.articles))
        print("----------------------------------------")
        if self.multifield: 
            print("TOKENS:")
            print("\t# of tokens in 'all': ", len(self.index['all']))
            print("\t# of tokens in 'title': ", len(self.index['title']))
            print("\t# of tokens in 'summary': ", len(self.index['summary']))
            print("\t# of tokens in 'section': ", len(self.index['section-name']))
            print("\t# of tokens in 'url': ", len(self.index['url']))
        else:
            print("TOKENS:")
            print("\t# of tokens in 'all': ", len(self.index['all']))

        if self.permuterm:
            print("----------------------------------------")
            if not self.multifield:
                print("PERMUTERMS:")
                print("\t# of permutem in '': ", len(self.ptindex['all']))
            else:
                print("PERMUTERMS:")
                print("\t# of permuterm in 'all': ", len(self.ptindex['all']))
                print("\t# of permuterm in 'title': ", len(self.ptindex['title']))
                print("\t# of permuterm in 'summary': ", len(self.ptindex['summary']))
                print("\t# of permuterm in 'section': ", len(self.ptindex['section-name']))
                print("\t# of permuterm in 'url': ", len(self.ptindex['url']))

        if self.stemming:
            print("----------------------------------------")
            if not self.multifield:
                print("STEMS:")
                print("\t# of stems in 'all': ", len(self.sindex['all']))
            else:
                print("STEMS:")
                print("\t# of stems in 'all': ", len(self.sindex['all']))
                print("\t# of stems in 'title': ", len(self.sindex['title']))
                print("\t# of stems in 'summary': ", len(self.sindex['summary']))
                print("\t# of stems in 'section': ", len(self.sindex['section-name']))
                print("\t# of stems in 'url': ", len(self.sindex['url']))
        if self.positional:
            print("----------------------------------------")
            print("Positional queries are allowed.")
        else:
            print("----------------------------------------")
            print("Positional queries are NOT allowed.")

        print("========================================")


    #################################
    ###                           ###
    ###   PARTE 2: RECUPERACION   ###
    ###                           ###
    #################################

    ###################################
    ###                             ###
    ###   PARTE 2.1: RECUPERACION   ###
    ###                             ###
    ###################################


    def solve_query(self, query:str, prev:List={}):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Resuelve una query.
        Debe realizar el parsing de consulta que sera mas o menos complicado en funcion de la ampliacion que se implementen


        param:  "query": cadena con la query
                "prev": incluido por si se quiere hacer una version recursiva. No es necesario utilizarlo.


        return: posting list con el resultado de la query

        """
        if query is None or len(query) == 0:
            return []
        else:
            # Tokenizamos las keywords y los paréntesis de la frase
            tokenList = re.split(r'AND|OR|AND NOT|OR NOT|NOT|[()]|url:|title:|summary:|section-name:|all:', query)
            tokenList = [re.sub(r'^\s+|\s+$', '', token) for token in tokenList if token.strip()]

            separators = re.findall(r'AND|OR|AND NOT|OR NOT|NOT|[()]', query)
            separators = [token for token in separators if token.strip()]

            fields = re.findall(r'url:|all:|title:|summary:|section-name:', query)
            fields = [token for token in fields if token.strip()]
            #fields = [field.replace(':', '') for field in fields]

            # Luego juntamos listas de separador y tokens
            tokenizedList = []
            
            i = 0; j = 0; k = 0; word = ""
            for letter in query:
                word += letter
                if(i < len(tokenList) and re.sub(r'^\s+|\s+$', '', word) == tokenList[i]): 
                    tokenizedList.append(tokenList[i]); word = ""; i+= 1 
                if(j < len(separators) and re.sub(r'^\s+|\s+$', '', word) == separators[j]): 
                    tokenizedList.append(separators[j]); word = ""; j+= 1
                if(k < len(fields) and re.sub(r'^\s+|\s+$', '', word) == fields[k]): 
                    tokenizedList.append(fields[k]); word = ""; k+= 1    

            fields = []
            for i, t in enumerate(tokenizedList):
                # Hemos de convertir a lista todos los diccionarios posicionales (cuando se utiliza la opción 
                # -P para generar el binario de búsqueda esto es necesario para evitar una excepción)
                if isinstance(tokenizedList[i], dict): tokenizedList[i] = [key for key in tokenizedList[i]]
                if t in ['title:', 'summary:', 'section-name:', 'all:', 'url:']:
                    fields.append(t)
                if t not in ['(', "OR NOT", "AND NOT", "AND", "OR", 'NOT', ')', 'url:', 'all:', 'title:', 'summary:', 'section-name:']:
                    if len(fields)==0: 
                        tokenizedList[i] = self.get_posting_or_positionals(t,None)
                    else:
                        tokenizedList[i] = self.get_posting_or_positionals(t, fields[0].replace(':', ''))
                        fields.pop(0)

            tokenizedList = [t for t in tokenizedList if t not in ['all:','title:','summary:', 'section-name:']]

            # añadimos paréntesis tanto al final como al principio para que la implementación funcione correctamente
            # es necesario porque cuando se evaluan todas las operaciones nesteadas por paréntesis de niveles más altos
            # falta por tratar el nivel más bajo, el cual no es accesible si la query no está envuelta en paréntesis.
            tokenizedList.append(")")
            tokenizedList.insert(0, "(")
            
            lastOpen = 0; firstClosed = 0
            # Mientras haya un par de paréntesis, tendremos que seguir operando para deshacernos de ellos.
            while self.count_parentheses(tokenizedList) > 0:
                if self.count_parentheses(tokenizedList) % 2 != 0: print("Error de input - paréntesis impares."); return []
                for index, token in enumerate(tokenizedList):
                    if token == "(":
                        lastOpen = index
                    if token == ")":
                        firstClosed = index
                        content = tokenizedList[lastOpen+1:firstClosed]
                        if firstClosed - lastOpen > 2:
                            # Eliminamos todo el contenido entre paréntesis inclusive y lo sustituimos en la posición
                            # por el resultado de la subquery
                            for i in range(firstClosed - lastOpen):
                                tokenizedList.pop(lastOpen)
                            tokenizedList[lastOpen] = self.evaluate(content)
                        else:
                            # Si solo hay un término entre paréntesis, simplemente los eliminamos y dejamos el término
                            # (recordemos que sería una lista) intacto
                            tokenizedList.pop(lastOpen)
                            # Hemos de comprobar si tenemos que eliminar el último paréntesis y el primero, ya que
                            # al eliminar su correspondiente, la longitud cambia y se convierte en firstClosed -1
                            if firstClosed == len(tokenizedList):
                                tokenizedList.pop()
                            else:
                                tokenizedList.pop(firstClosed-1) 
                        # Salimos del bucle para volver a encontrar la encapsulación más cercana por la izquierda
                        break
            # Flatten, ya que se devuelve el resultado en una lista de listas
            tokenizedList = [item for sublist in tokenizedList for item in sublist]
            return tokenizedList

    # Evalúa los contenidos de la "sub-query" contenida entre paréntesis que se le pasa
    def evaluate(self, tokens):
        i = 0
        while i < len(tokens):
            if tokens[i] == "AND":
                if i + 1 < len(tokens) and tokens[i + 1] == "NOT":
                    posting_list = self.and_posting(posting_list, self.reverse_posting(tokens[i + 2]))
                    i += 3
                else:
                    posting_list = self.and_posting(posting_list, tokens[i + 1])
                    i += 2
            elif tokens[i] == "OR":
                if i + 1 < len(tokens) and tokens[i + 1] == "NOT":
                    posting_list = self.or_posting(posting_list, self.reverse_posting(tokens[i + 2]))
                    i += 3
                else:
                    posting_list = self.or_posting(posting_list, tokens[i + 1])
                    i += 2
            elif tokens[i] == "NOT":
                posting_list = self.reverse_posting(tokens[i + 1])
                i += 2
            else:
                posting_list = tokens[i]
                i += 1
        return posting_list

    # Método auxiliar para los posting, para los stemming ó para las consultas normales
    def get_posting_or_positionals(self, token,field):
        if self.get_posting(token, field) == None: return []
        return self.get_posting(token, field)

    # Método que devuelve el nº de paréntesis de una lista
    def count_parentheses(self, tokens):
        open_count = 0
        close_count = 0

        for token in tokens:
            if token == "(": open_count += 1
            if token == ")": close_count += 1
    
        return open_count+close_count
        
    def get_posting(self, term:str, field:Optional[str]=None):
        """

        Devuelve la posting list asociada a un termino. 
        Dependiendo de las ampliaciones implementadas "get_posting" puede llamar a:
            - self.get_positionals: para la ampliacion de posicionales
            - self.get_permuterm: para la ampliacion de permuterms
            - self.get_stemming: para la amplaicion de stemming


        param:  "term": termino del que se debe recuperar la posting list.
                "field": campo sobre el que se debe recuperar la posting list, solo necesario si se hace la ampliacion de multiples indices

        return: posting list
        
        NECESARIO PARA TODAS LAS VERSIONES

        """
        if "?" in term or "*" in term:  # si hay comodines en la consulta
            self.use_permuterm= True
        else : 
            self.use_permuterm= False
            
        if '"' in term:
            # en nuestra implementación ignoramos los ""
            term = term.replace('"', '')
            if(field is None):                       #si no se especifica field buscamos en el diccionario donde solo estan los terminos
                return self.get_positionals(term)
            else:                          
                return self.get_positionals(term, field) 
        elif(self.use_permuterm):
            if(field is None):   
                return self.get_permuterm(term,"all") #si no se especifica field buscamos en el diccionario donde solo estan los terminos
            else:                       
                return self.get_permuterm(term, field) 
        elif (self.use_stemming):
            if(field is None):                    #si no se especifica field buscamos en el diccionario donde solo estan los terminos
                return self.get_stemming(term)
            else:                     
                return self.get_stemming(term, field)
        else:
            if(field is None):
                return self.index["all"].get(term)
            else:
                return self.index[field].get(term)
       

    def get_positionals(self, terms, field: Optional[str]=None):
        """

        Devuelve la posting list asociada a una secuencia de terminos consecutivos.
        NECESARIO PARA LA AMPLIACION DE POSICIONALES

        param:  "terms": lista con los terminos consecutivos para recuperar la posting list.
                "field": campo sobre el que se debe recuperar la posting list, solo necesario se se hace la ampliacion de multiples indices

        return: posting list

        """
        posting = [] # lista de posting a devolver

        pass
        if field is not None:
            f = field
        else:
            f = 'all'

        postingDictList = []  # lista de diccionarios
        # Supongamos que 'input_string' es la cadena de entrada
        terms = terms.split()

        for term in terms:
            if term != " ":
                if term in self.index[f]:
                    postingDictList.append(self.index[f][term])    # guardamos en la lista de diccionarios las posting lists de los términos
            
        groupDict={}
        # Ahora creamos un nuevo diccionario que almacene todos los artid con sus respectivos
        # términos para buscar consecuciones.
        index = 0
        while index < len(postingDictList):
            for artid in postingDictList[index]:
                if artid not in groupDict:
                    groupDict[artid] = []
                    groupDict[artid] += postingDictList[index][artid]
                else:
                    groupDict[artid] += postingDictList[index][artid] 
            index += 1

        for artid in groupDict:
            # ordenamos ascendentemente y ahora buscamos términos consecutivos (1,2,3...)
            postingList = sorted(groupDict[artid])
            
            count = 0
            for i, pos in enumerate(postingList):
                if count == len(terms)-1:
                    posting.append(artid)
                    break
                if pos == postingList[-1]:
                    break
                # comprobamos si la palabra que estamos buscando está en el artículo
                if terms[count] in self.index[f] and artid in self.index[f][terms[count]]:
                # tenemos que asegurarnos que la palabra que estamos consultando es la que sigue el orden dictado
                # por los términos. Primero se busca term[0], luego term[1]... etc. La disposición de nuestro código
                # no asegura esto por defecto, y por ello debe comprobarse que la posición siendo consultada
                # existe dentro de la lista de posiciones de la palabra en ese artículo
                    if postingList[i]+1 == postingList[i+1] and pos in self.index[f][terms[count]][artid]:
                        count += 1
                    else:
                        count = 0
                else:
                    count = 0
        return posting                    


    def get_stemming(self, term:str, field: Optional[str]=None):
        """

        Devuelve la posting list asociada al stem de un termino.
        NECESARIO PARA LA AMPLIACION DE STEMMING

        param:  "term": termino para recuperar la posting list de su stem.
                "field": campo sobre el que se debe recuperar la posting list, solo necesario si se hace la ampliacion de multiples indices

        return: posting list

        """
        stem = self.stemmer.stem(term)
        res = []
        if field is not None:
            if stem in self.sindex[field]:
                for token in self.sindex[field][stem]:
                    res = self.or_posting(                      # Se utiliza el OR propio
                        res, list(self.index[field][token]))
            # print(res)
        else:
            if stem in self.sindex["all"]:
                for token in self.sindex["all"].get(stem):
                    res = self.or_posting(                      # Se utiliza el OR propio
                        res, self.index["all"].get(token))
        
        return res


    def get_permuterm(self, term:str, field:Optional[str]=None):
        """

        Devuelve la posting list asociada a un termino utilizando el indice permuterm.
        NECESARIO PARA LA AMPLIACION DE PERMUTERM

        param:  "term": termino para recuperar la posting list, "term" incluye un comodin (* o ?).
                "field": campo sobre el que se debe recuperar la posting list, solo necesario se se hace la ampliacion de multiples indices

        return: posting list

        """
        if not self.use_permuterm:
            raise ValueError("El índice permuterm no ha sido creado. Llame a make_permuterm() primero.")
        
        if field not in self.ptindex:
            raise ValueError(f"El campo '{field}' no existe en el índice permuterm.")
        
        term = str(term)
        term = term.lower()
        if "?" in term: 
            pre = term.split('?')[0]
            post = term.split('?')[1]
        elif "*" in term:
            pre = term.split('*')[0]
            post = term.split('*')[1]

        results = []
        
        for perm in self.ptindex[field]:
            preP = perm.split('$')[0]
            postP = perm.split('$')[1]
            if "?" in term:
                if postP.startswith(pre) and preP.endswith(post):
                    perm2=perm.replace('$','')  
                    if len(term) == len(perm2):  
                        results.append(perm)       
            elif "*" in term:
                if postP.startswith(pre) and preP.endswith(post):
                    results.append(perm) 
        
        posting_list = []
        for term in results:
            if self.ptindex[field].get(term) not in posting_list:
                posting_list.append(self.ptindex[field].get(term))

        posting_list= self.or_posting(posting_list, posting_list)
        real_posting_list = []  
        for term in posting_list:
            real_posting_list = self.or_posting(real_posting_list,self.index[field].get(term))


        return real_posting_list  # Eliminar duplicados
    
    def reverse_posting(self, p:list):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Devuelve una posting list con todas las noticias excepto las contenidas en p.
        Util para resolver las queries con NOT.


        param:  "p": posting list


        return: posting list con todos los artid exceptos los contenidos en p

        """
        reverse = []
        noticias = self.articles.keys()
        for doc in noticias:
             if doc not in p:
                reverse.append(doc)
        return reverse


    def and_posting(self, p1:list, p2:list):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Calcula el AND de dos posting list de forma EFICIENTE

        param:  "p1", "p2": posting lists sobre las que calcular


        return: posting list con los artid incluidos en p1 y p2

        """
        AND = []
        # Ordenamos las listas (sólo por si acaso)
        p1 = sorted(p1)
        p2 = sorted(p2)   
        
        # definimos los índices de la iteración 
        index1 = 0
        index2 = 0
        while index1 != len(p1) and index2 != len(p2):
            if p1[index1] == p2[index2]:
                AND.append(p1[index1])
                index1 += 1
                index2 += 1
            elif p1[index1] > p2[index2]:
                index2 += 1
            else:
                index1 += 1

        return AND

    def or_posting(self,p1:list, p2:list):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Calcula el OR de dos posting list de forma EFICIENTE

        param:  "p1", "p2": posting lists sobre las que calcular


        return: posting list con los artid incluidos de p1 o p2

        """
        OR = []
        # Ordenamos las listas (sólo por si acaso)
        p1 = sorted(p1)
        p2 = sorted(p2) 
        
        # definimos los índices de la iteración 
        index1 = 0
        index2 = 0
        while index1 != len(p1) and index2 != len(p2):
            if p1[index1] < p2[index2]:
                OR.append(p1[index1])
                index1 += 1
            elif p1[index1] > p2[index2]:
                OR.append(p2[index2])
                index2 += 1
            else:
                OR.append(p1[index1])
                index1 += 1
                index2 += 1

        while index1 != len(p1):
            OR.append(p1[index1])
            index1 += 1
        while index2 != len(p2):
            OR.append(p2[index2])
            index2 += 1
        
        return OR


    def minus_posting(self, p1, p2):
        """
        OPCIONAL PARA TODAS LAS VERSIONES

        Calcula el except de dos posting list de forma EFICIENTE.
        Esta funcion se incluye por si es util, no es necesario utilizarla.

        param:  "p1", "p2": posting lists sobre las que calcular


        return: posting list con los artid incluidos de p1 y no en p2

        """
        p1 = sorted(p1)                      # ordenamos las dos listas
        p2 = sorted(p2) 

        DEL = self.and_posting(p1,p2)        # las palabras del and son las que tendremos que eliminar de p1
        for term in p1:
            if term in DEL: p1.remove(term)    
         
        return p1

    #####################################
    ###                               ###
    ### PARTE 2.2: MOSTRAR RESULTADOS ###
    ###                               ###
    #####################################

    def solve_and_count(self, ql:List[str], verbose:bool=True) -> List:
        results = []
        for query in ql:
            if len(query) > 0 and query[0] != '#':
                r = self.solve_query(query)
                results.append(len(r))
                if verbose:
                    print(f'{query}\t{len(r)}')
            else:
                results.append(0)
                if verbose:
                    print(query)
        return results


    def solve_and_test(self, ql:List[str]) -> bool:
        errors = False
        for line in ql:
            if len(line) > 0 and line[0] != '#':
                query, ref = line.split('\t')
                reference = int(ref)
                result = len(self.solve_query(query))
                if reference == result:
                    print(f'{query}\t{result}')
                else:
                    print(f'>>>>{query}\t{reference} != {result}<<<<')
                    errors = True                    
        return not errors


    def solve_and_show(self, query:str):
        """
        NECESARIO PARA TODAS LAS VERSIONES

        Resuelve una consulta y la muestra junto al numero de resultados 

        param:  "query": query que se debe resolver.

        return: el numero de artículo recuperadas, para la opcion -T

        """
        r = self.solve_query(query)

        print("========================================")

        for i, res in enumerate(r, 1):
            aux = self.articles[res][0]

            print('#{:<4} ({})'.format(
                    i, res, aux))
            
            line = self.articles[res][1]           #accedemos al segundo elemento de la tupla del articulo (docid, linea) !POSIBLE CAMBIO LINEA  aux = self.articles[res][1]
            docpath  = self.docs[aux-1]              #aux == docid       res = artid
            sec_names = []
            txt_secs = '' 
            with open (docpath,'rb') as file:              #para leer el texto del articulo sacamos el path del doc que lo contiene y hacemos dicc con el que sacamos su cuerpo
                for j, art in enumerate(file):          #vamos recorriendo las lineas (articulos) del doc. cuando sea la del nuestro parseamos ese articulo
                    if(line == j):
                        article = json.loads(art)
                        for sec in article['sections']:
                            txt_secs += sec['name'] + '\n' + sec['text'] + '\n'
                            txt_secs += '\n'.join(subsec['name'] + '\n' + subsec['text'] + '\n' for subsec in sec['subsections']) + '\n\n'
                            sec_names.append(sec['name'])
                            sec_names.extend(subsec['name'] for subsec in sec['subsections'])
                        article.pop('sections') # no la necesitamos 
                        article['all'] = article['title'] + '\n\n' + article['summary'] + '\n\n' + txt_secs
                        article['section-name'] = '\n'.join(sec_names)

            print(article['title'])
            print(article['url'])
            
            if(self.show_snippet):
                snippets = ""
                
                tokens = re.split(r'AND|OR|NOT|AND NOT|OR NOT', query)
                tokens = [token.strip() for token in tokens if token.strip()]                     
                tokens = [token.strip() for token in tokens if token.strip() and token.strip() not in {'AND', 'OR', 'NOT', 'AND NOT', 'OR NOT'}] #dejamos solo las palabras clave de la query
                cuerpo = ""
                cuerpo += article['all']
                
                cuerpo = cuerpo.replace('\n', ' ').replace('\r', '')
                
                for j, palabra in enumerate(tokens):
                    palabra = palabra.replace('"', '')
                    indice = (cuerpo.lower()).find(palabra)
                    
                    inicio = max(0,indice-100)
                    final = min(len(cuerpo),indice + 100)    
                    
                    snippet = cuerpo[inicio:final]
                    
                    snippets += snippet + "..."

                snippets = "..." + snippets[1:] # Hay un espacio, lo eliminamos con [1:]
                print(snippets+"\n")
                
            if not self.show_all and i >= self.SHOW_MAX:
                break
        
        print("========================================")
        print('Number of results: ' + str(len(r)))
        print()
        return str(len(r))
    






        

