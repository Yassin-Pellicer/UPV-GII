hombre('alfredo').
hombre('felipe').
hombre('francisco').
mujer('sonia').
mujer('eva').
mujer('carmen').

bebe('alfredo', 'whisky').
bebe('alfredo', 'ron_cola').
bebe('felipe', 'cerveza').
bebe('felipe', 'gin_tonic').
bebe('felipe','ron_cola').
bebe('francisco', 'vino').
bebe('francisco', 'malibu').
bebe('sonia', 'gin_tonic').
bebe('sonia', 'malibu').
bebe('eva', 'vino').
bebe('eva', 'cerveza').
bebe('carmen', 'whisky').
bebe('carmen', 'ron_cola').

pareja(X,Y) :- bebe(X,Z), bebe(Y,Z), hombre(X), mujer(Y).
pareja2(X,Y) :- bebe(X,Z), bebe(X,T), bebe(Y,Z), bebe(Y,T), hombre(X), mujer(Y).

pepeBebe(Y) :- bebe('alfredo',Y).
elenaBebe(Z) :- bebe('sonia',Z) | bebe('felipe',Z).
