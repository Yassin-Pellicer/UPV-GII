%{
    #include "header.h"
    #include "libtds.h" 
    #include "libgci.h"
    #include <stdio.h>
    #include <string.h>
%}

%union {
    int cent;
    char *ident;
    List list;
    Expr texp;
    Aux aux;  
}

%token MAS_ MENOS_ POR_ DIV_ PARA_ PARC_ EQ_ ASIG_
%token LLAA_ LLAC_ CORA_ CORC_ AND_ OR_ NEQ_ LE_ GE_ LEQ_ GEQ_ NOT_ TRUE_ FALSE_
%token READ_ PRINT_ IF_ ELSE_ FOR_ RET_ 
%token INT_ BOOL_ SCOL_  COL_

%token <cent> CTE_
%token <ident> ID_
%type <list> 
    listParamForm 
    listParamAct 
    paramForm
    paramAct 

%type <cent>  
    programa 
    decla 
    declaVar 
    tipoSimp 
    declaFunc
    bloque 
    declaVarLocal 
    inst 
    instExpre 
    listDecla
    instEntSal 
    opLogic 
    opIgual 
    opRel 
    opAd 
    opMul 
    opUna

%type <texp> 
    expreOP 
    expre 
    expreLogic 
    expreIgual 
    expreRel 
    expreAd 
    expreMul 
    expreUna 
    expreSufi 
    const

%type <aux> instSelec instIter 

%%

programa 
    : 
    {   niv = 0; dvar = 0; si = 0; cargaContexto(niv); 
        $<aux>$.ref1 = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
        $<aux>$.ref2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
    } 
    listDecla 
    { 
        SIMB simb = obtTdS("main");
        if(simb.t == T_ERROR)
            yyerror("El programa no tiene función 'main'.");
        completaLans($<aux>1.ref1, crArgEnt(dvar));

        $<aux>$.ref3 = simb.d;

        completaLans($<aux>1.ref2, crArgEtq($<aux>$.ref3));
    }
    ;

listDecla 
    : decla              
    { $$ = $1; }
    | listDecla decla    
    { $$ = $1 + $2; }
    ;

decla 
    : declaVar           
    { $$ = $1; }
    | declaFunc          
    { $$ = $1; }
    ;

declaVar 
    : tipoSimp ID_ SCOL_
    { 
        // Si la variable todavía no se ha añadido a la tabla de símbolos, se añade.
        if(!insTdS($2, VARIABLE, $1, niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else
            dvar += TALLA_SIMPLE;
    }
    | tipoSimp ID_ ASIG_ const SCOL_
    {
        if(!insTdS($2, VARIABLE, $1, niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else if ($1 != $4.t)
            yyerror("El tipo esperado es inválido.");
        else
            dvar += TALLA_SIMPLE;

        SIMB simb = obtTdS($2);
        emite(EASIG, crArgEtq($4.pos), crArgNul(), crArgPos(simb.n, simb.d));
        
    }
    | tipoSimp ID_ CORA_ CTE_ CORC_ SCOL_
    {

        if($4 <= 0)
            yyerror("La talla del vector es incorrecta.");
        int ref = insTdA($1, $4);
        if(!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, ref))
            yyerror("Vector ya declarado con mismo identificador.");
        else
            dvar += $4 * TALLA_SIMPLE;
    }
    ;

tipoSimp 
    : INT_
    { $$ = T_ENTERO; }
    | BOOL_
    { $$ = T_LOGICO; }
    ;

declaFunc 
    : tipoSimp ID_ PARA_ {$<cent>$ = dvar; dvar = 0; niv=1; cargaContexto(niv); } paramForm PARC_
    {
        if(!insTdS($2, FUNCION, $1, 0, si, $5.ref))
        {
            if (strcmp($2, "main\0") == 0) 
            {
                yyerror("Esta función ya ha sido declarada. (Ya se ha declarado 'main').");
            }
            yyerror("Esta función ya ha sido declarada.");
        }
    }
    bloque
    {
        if (verTdS) {
            mostrarTdS(); 
        }
        descargaContexto(niv); 
        niv = 0;
        dvar = $<cent>4;
    }
    ;

paramForm : 
    listParamForm
    {
        $$.ref = $1.ref;
        $$.talla = $1.talla;
    }
    |
    {
        $$.ref = insTdD(-1, T_VACIO);
        $$.talla = 0;   
    }
    ;

listParamForm 
    : tipoSimp ID_
    {
        $$.ref = insTdD(-1, $1);
        $$.talla = TALLA_SIMPLE + TALLA_DOBLE;
        if(!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1)) yyerror("Ya existe un parametro con el mismo identificador.");
    }
    | tipoSimp ID_ COL_ listParamForm
    {
        $$.ref = insTdD($4.ref, $1);
        $$.talla = TALLA_SIMPLE + $4.talla;
        if(!insTdS($2, PARAMETRO, $1, niv, -$$.talla, -1)) yyerror("Ya existe un parametro con el mismo identificador."); 
    }
    ;

paramAct : 
    listParamAct
    {
        $$.ref = $1.ref;
        $$.talla = $1.talla;
    }
    |
    {
        $$.ref = insTdD(-1, T_VACIO);
        $$.talla = 0;   
    }
    ;


listParamAct
    : expre
    {
        $$.ref = insTdD(-1, $1.t);
        $$.talla = TALLA_SIMPLE + TALLA_DOBLE;
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.pos));
    }
    | 
    expre COL_ 
    { 
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.pos)); 
    }
    listParamAct
    {
        $$.ref = insTdD($4.ref, $1.t);
        $$.talla = TALLA_SIMPLE + $4.talla;
    }
    ;

bloque 
    : LLAA_
    {
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        $<cent>$ = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));   
    }
    declaVarLocal listInst RET_ expre SCOL_ LLAC_
    {
        INF inf = obtTdD(-1);
        if(inf.tipo == T_ERROR)
            yyerror("Función ya declarada. Comprobación de retorno de tipos invalidada.");
        else if(inf.tipo != $6.t)
            yyerror("El tipo de retorno de la función no coincide con el declarado.");
        completaLans($<cent>2, crArgEnt(dvar));

        int dret = TALLA_DOBLE + TALLA_SIMPLE + inf.tsp;
        emite(EASIG, crArgPos(niv, $6.pos), crArgNul(), crArgPos(niv, -dret));
        emite(TOPFP, crArgNul(), crArgNul(), crArgNul() );
        emite(FPPOP, crArgNul(), crArgNul(), crArgNul() );

        if (strcmp(inf.nom,"main") == 0) { emite(FIN, crArgNul(), crArgNul(), crArgNul()); }
        else { emite(RET, crArgNul(), crArgNul(), crArgNul()); }
    }
    ;

declaVarLocal 
    : declaVarLocal declaVar
    | 
    ;

listInst 
    : listInst inst
    |
    ;

inst 
    : LLAA_ listInst LLAC_
    | instExpre
    | instEntSal
    | instSelec
    | instIter
    ;

instExpre 
    : expre SCOL_
    | SCOL_
    ;

instEntSal
    : READ_ PARA_ ID_ PARC_ SCOL_
    {			
        SIMB simb = obtTdS($3);
        if(simb.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser entero.");
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.n, simb.d));
    }
    | PRINT_ PARA_ expre PARC_ SCOL_
    {
        if($3.t != T_ENTERO)
            yyerror("El argumento del 'print' debe ser entero.");
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.pos));
    }
    ;

instSelec 
    : IF_ PARA_ expre PARC_  
    {
        if($3.t != T_LOGICO && $3.t != T_ERROR)
            yyerror("La expresión del 'if' debe ser de tipo 'lógico'.");
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        $<aux>$.ref1 = creaLans(si);          
        // Las etiquetas (los saltos) están todavía por inicializarse. Apuntan a la referencia 
        // de la inst previa (apuntan a creaLans, linea 267)
        // Se saltará a la etiqueta cuando la condición de la expresión sea verdadera.
        // Es decir, si 0 es igual al contenido del argumento $6, o si la condición es FALSA.
        emite(EIGUAL, crArgPos(niv, $3.pos), crArgEnt(0), crArgEtq(-1) );
    }
    inst
    {
        $<aux>$.ref2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans($<aux>5.ref1, crArgEtq(si));
    }
    ELSE_ inst
    {
        completaLans($<aux>7.ref2, crArgEtq(si));
    }
    ;

instIter 
    : FOR_ PARA_ expreOP SCOL_ 
    {
       $<aux>$.ref0 = si; 
    } 
    expre SCOL_ 
    {
        if ($6.t == T_ARRAY) 
            yyerror("La expresión condicional del 'for' debe ser de tipo 'simple'.");
        else if($6.t != T_LOGICO && $6.t != T_ERROR)
            yyerror("La expresión del 'for' debe ser de tipo 'lógico'.");
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        $<aux>$.ref1 = creaLans(si);          
        // Las etiquetas (los saltos) están todavía por inicializarse. Apuntan a la referencia 
        // de la inst previa (apuntan a creaLans, linea 282)
        // Se saltará a la etiqueta cuando la condición de la expresión sea verdadera
        emite(EIGUAL, crArgPos(niv, $6.pos), crArgEnt(1), crArgEtq(-1) );
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        $<aux>$.ref2 = creaLans(si);                              
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        $<aux>$.ref3 = si;    
    } 
    expreOP PARC_
    {
        if ($6.t == T_ARRAY) {}
        else if($6.t != T_LOGICO && $6.t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<aux>5.ref0)); 
        completaLans($<aux>8.ref1, crArgEtq(si));
    }
    inst
    {
        if ($6.t == T_ARRAY) {}
        else if($6.t != T_LOGICO && $6.t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<aux>8.ref3)); 
        completaLans($<aux>8.ref2, crArgEtq(si));
    }
    ;

expreOP 
    : expre
    { $$.t = $1.t; $$.pos = $1.pos; }
    | 
    { $$.t = T_VACIO; } 
    ;

expre 
    : expreLogic 
    { $$.t = $1.t; $$.pos = $1.pos; }
    | ID_ ASIG_ expre
    {
        $$.t = T_ERROR; 
        SIMB simb = obtTdS($1);

        if($3.t != T_ERROR)
        {   
            if(simb.t == T_ERROR)
                yyerror("Objeto no declarado.");
            else if (simb.t != $3.t)
            {
                if (simb.t == T_ARRAY || $3.t == T_ARRAY)
                    yyerror("Una de las variables es un vector. La asignación es incompatible.");
                else
                    yyerror("Tipos incompatibles.");
            }
            $$.t = simb.t;
        }
        $$.pos = $3.pos;
        emite(EASIG, crArgPos(niv, $3.pos), crArgNul(), crArgPos(simb.n, simb.d));
    }
    | ID_ CORA_ expre CORC_ ASIG_ expre
    {
        SIMB simb = obtTdS($1);
        DIM dim;

        if(simb.t != T_ARRAY)
            yyerror("La variable no es un vector, no se puede acceder mediante indices.");
        else
            dim = obtTdA(simb.ref);
        
        if ($3.t != T_ERROR && $6.t != T_ERROR) {                    
            if(simb.t == T_ERROR) {
                yyerror("No existe ninguna variable con ese identificador.");
            } else if (! ($3.t == T_ENTERO)) {
                yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
            } else if (! ($6.t == dim.telem)) { 
                yyerror("Incompatibilidad de tipos en la asignación del vector."); 
            }                      
        }
        $$.pos = $3.pos;
        emite(EVA, crArgPos(simb.n, simb.d), crArgPos(niv, $3.pos), crArgPos(niv, $6.pos));

    }
    ;

expreLogic 
    : expreIgual 
    { $$.t = $1.t; $$.pos = $1.pos; }
    | expreLogic opLogic expreIgual
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if($3.t != T_LOGICO || $1.t != T_LOGICO)
                yyerror("Error en 'expresion logica'.");
            else if(!($2 == EMULT || $2 == ESUM))
                yyerror("Error en 'expresion logica'.");
        }
        $$.t = T_LOGICO;
        $$.pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        if ($2 == EMULT) { 
            emite(EMULT, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
        } 
        else 
        {
            emite(ESUM, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
            // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
            emite(EMENEQ, crArgPos(niv, $$.pos), crArgEnt(1), crArgEtq(si+2));
            // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
            emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
        }
    }
    ;

expreIgual 
    : expreRel
    { $$.t = $1.t; $$.pos = $1.pos; }
    | expreIgual opIgual expreRel
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if($3.t != $1.t)
                yyerror("Error en 'expresión de igualdad'."); 
            else if(!($3.t == T_LOGICO || $3.t == T_ENTERO))
                yyerror("Error en 'expresión de igualdad'.");
        }
        $$.t = T_LOGICO;
        $$.pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
        // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
        emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));
        // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.pos));
    }   
    ;


expreRel 
    : expreAd 
    { $$.t = $1.t; $$.pos = $1.pos; }
    | expreRel opRel expreAd
    {
        $$.t = T_ERROR; 
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if (!($1.t == $3.t && $1.t == T_ENTERO && $3.t == T_ENTERO)) {
                yyerror("Error en 'expresión relacional'.");
            } 
        }
        $$.t = T_LOGICO;
        $$.pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.pos));
        // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
        emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgEtq(si + 2));
        // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.pos));
    }   
    ;

expreAd 
    : expreMul
    { $$.t = $1.t; $$.pos = $1.pos; }
    | expreAd opAd expreMul
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if(!($1.t == $3.t && $1.t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión aditiva'.");
        }
        $$.t = T_ENTERO;
        $$.pos = creaVarTemp();
        emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
    }   
    ;

expreMul 
    : expreUna
    { $$.t = $1.t; $$.pos = $1.pos; }
    | expreMul opMul expreUna
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if(!($1.t == T_ENTERO && $3.t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión multiplicativa'.");
        }
        $$.t = T_ENTERO;
        $$.pos = creaVarTemp();
        emite($2, crArgPos(niv, $1.pos), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos));
    }   
    ;

expreUna 
    : expreSufi
    { $$.t = $1.t; $$.pos = $1.pos; }
    | opUna expreUna
    {
        $$.t = T_ERROR;
        if($2.t == T_ENTERO)
        {
            if($1 == ESIG)
                yyerror("Error en 'expresión unaria'. No se puede negar un entero.");
            $$.t = T_ENTERO;   
        }
        else if($2.t == T_LOGICO)
        {
            if($1 == ESUM || $1 == EDIF)
                yyerror("Error en 'expresión unaria'. No se puede operar aritméticamente con valores lógicos.");
            else
            {
                $$.t = T_LOGICO;    
            }
        }
        else
            yyerror("Error en 'expresión unaria'. Los valores no son equivalentes o los tipos no casan.");
        $$.pos = creaVarTemp();
        if($1 == ESIG)
            emite(EDIF, crArgEnt(1), crArgPos(niv, $2.pos), crArgPos(niv, $$.pos));
        else
            emite($1, crArgEnt(0), crArgPos(niv, $2.pos), crArgPos(niv, $$.pos));
    }
    ;

expreSufi 
    : const
    {   
        $$.t = $1.t; 
        $$.pos = creaVarTemp();
        emite(EASIG, crArgEnt($1.pos), crArgNul(), crArgPos(niv, $$.pos));         
    }
    | PARA_ expre PARC_
    { $$.t = $2.t; $$.pos = $2.pos; }   
    | ID_
    {
        SIMB simb = obtTdS($1);

        $$.t = T_ERROR;

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else
            $$.t = simb.t;
        $$.pos = creaVarTemp();
        emite(EASIG, crArgPos(simb.n, simb.d), crArgNul(), crArgPos(niv, $$.pos));   
    }
    | ID_ CORA_ expre CORC_
    {
        SIMB simb = obtTdS($1);

        $$.t = T_ERROR; 

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else if($3.t != T_ENTERO)
        yyerror("Los valores no son equivalentes o los tipos no casan.");
        DIM dim = obtTdA(simb.ref);
        $$.t = dim.telem;

        // En este caso debemos hacer una asignación para instanciar el valor que almacena la variable
        // de nombre ID en $$.pos (que viene a ser la posición de expreSufi)
        $$.pos = creaVarTemp();
        emite(EAV, crArgPos(simb.n, simb.d), crArgPos(niv, $3.pos), crArgPos(niv, $$.pos)); 
    }
    | 
    ID_ PARA_ 
    {   
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_SIMPLE)); 
    }
    paramAct PARC_
    {
        SIMB simb = obtTdS($1);
        INF inf = obtTdD(simb.ref);

        $$.t = T_ERROR;
                
        if (simb.t == T_ERROR) 
            yyerror("No existe ninguna variable con ese identificador."); 
        if(!cmpDom(simb.ref, $4.ref)){
             yyerror("Los argumentos de la función no coinciden."); 
        }
        INF func = obtTdD(simb.ref);
        if (func.tipo == T_ERROR) 
            yyerror("No existe ninguna funcion con ese identificador."); 
        else
            $$.t = inf.tipo;
        emite(CALL, crArgNul(), crArgNul(), crArgEtq(simb.d)); 
        emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp)); 
        $$.pos = creaVarTemp();
        emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.pos));
    }
    ;
    
const 
    : CTE_    { $$.t = T_ENTERO; $$.pos = $1; }
    | TRUE_   { $$.t = T_LOGICO; $$.pos = 1; }
    | FALSE_  { $$.t = T_LOGICO; $$.pos = 0; }
    ;

opLogic
    : AND_    { $$ = EMULT; }
    | OR_     { $$ = ESUM; }
    ;

opIgual
    : EQ_     { $$ = EIGUAL; }
    | NEQ_    { $$ = EDIST; }
    ;

opRel
    : GE_     { $$ = EMAY; }
    | LE_     { $$ = EMEN; }
    | GEQ_    { $$ = EMAYEQ; }
    | LEQ_    { $$ = EMENEQ; }
    ;

opAd
    : MAS_    { $$ = ESUM; }
    | MENOS_  { $$ = EDIF; }
    ;

opMul
    : POR_    { $$ = EMULT; }
    | DIV_    { $$ = EDIVI; }
    ;

opUna
    : MAS_    { $$ = ESUM; }
    | MENOS_  { $$ = EDIF; }
    | NOT_    { $$ = ESIG; }
    ;
