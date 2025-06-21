model('ibiza', 'seat'). % ibiza es un modelo de la marca seat
model('cordoba', 'seat'). 
model('altea', 'seat').
model('golf', 'volkswagen').
model('touran', 'volkswagen').
model('clio', 'renault').
model('twingo', 'renault').
model('mégane', 'renault').
model('scénic', 'renault').
model('2008', 'peugeot').
model('3008', 'peugeot').
model('corsa', 'opel').

country('seat', 'españa'). % seat es una marca fabricada en españa
country('renault', 'francia').
country('peugeot', 'francia').
country('volkswagen', 'alemania').
country('opel', 'alemania').

since('ibiza', 1984). % ibiza es un modelo fabricado desde 1984
since('cordoba', 1993).
since('altea', 2004).
since('golf', 1974).
since('touran', 2003).
since('clio', 1990).
since('twingo', 1993).
since('mégane', 1995).
since('scénic', 1995).
since('2008', 2013).
since('3008', 2008).
since('corsa', 1982).

segment('ibiza', 'b'). % ibiza es un modelo del Segmento B
segment('cordoba', 'b').
segment('altea', 'c'). 
segment('golf', 'c').
segment('touran', 'c').
segment('clio', 'b').
segment('twingo', 'a').
segment('mégane', 'c').
segment('scénic', 'c').
segment('2008', 'b').
segment('3008', 'c').
segment('corsa', 'b').

% A is brand of B is B is model of A
brand(A,B) :- model(B,A).

% A is a model from country B if A is a model of brand C and C c is from country B
isModelFrom(A,B) :- model(A,C), country(C,B).

% A and B are models of the same brand if...
isSameBrand(A,B) :- model(A,C), model(B,C), A \== B.        

% A and B are models of the same year if ...
isSameYear(A,B) :- since(A,C), since(B,C), A \== B.

% A and B are related in some way if...
isRelated(A,B) :- isSameBrand(A,B).
isRelated(A,B) :- isSameYear(A,B).
isRelated(A,B) :- segment(A,C), segment(B,C), A \== B. 

% A clause that defines the isCountryOf relationship
isCountryOf(A,B) :- isModelFrom(B, A).

% A model A was launched before 1995.
isClassic(A,B) :- since(B, A) < 1995.

modelSelector(M,X,S,A):-model(M,X),segment(M,S),since(M,A).
comparatore(M1,M2):-model(M1, B1), model(M2, B2), segment(M1, S), segment(M2, S), B1 \== B2.