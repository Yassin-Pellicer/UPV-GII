%{
    #include "header.h"
    #include "libtds.h" 
    #include <stdio.h>
    #include <string.h>
%}

%union {
    int cent;
    char *ident;
    List list;
    Expr texp;
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
    instSelec 
    instIter 
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

%%

programa 
    : 
    { dvar = 0; niv = 0; cargaContexto(niv); } 
    listDecla 
    { 
        if(verTdS) mostrarTdS(); 
        SIMB simb = obtTdS("main");
        if(simb.t == T_ERROR)
            yyerror("El programa no tiene función 'main'.");
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
    }
    | tipoSimp ID_ CORA_ CTE_ CORC_ SCOL_
    {
        if($4 <= 0)
            yyerror("La talla del vector es incorrecta.");
        else
        {
            int ref = insTdA($1, $4);
            if(!insTdS($2, VARIABLE, T_ARRAY, niv, dvar, ref))
                yyerror("Vector ya declarado con mismo identificador.");
            else
                dvar += $4 * TALLA_SIMPLE;
        }
    }
    ;

tipoSimp 
    : INT_
    { $$ = T_ENTERO; }
    | BOOL_
    { $$ = T_LOGICO; }
    ;

declaFunc 
    : tipoSimp ID_ PARA_ {niv += 1; cargaContexto(niv);} paramForm PARC_
    {
        if(!insTdS($2, FUNCION, $1, 0, -1, $5.ref))
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
        niv -= 1; 
        $$ = $1;
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
    }
    | expre COL_ listParamAct
    {
        $$.ref = insTdD($3.ref, $1.t);
        $$.talla = TALLA_SIMPLE + $3.talla;
    }
    ;

bloque 
    : LLAA_ declaVarLocal listInst RET_ expre
    {
        INF inf = obtTdD(-1);
        if(inf.tipo == T_ERROR)
            yyerror("Función ya declarada. Comprobación de retorno de tipos invalidada.");
        else if(inf.tipo != $5.t)
            yyerror("El tipo de retorno de la función no coincide con el declarado.");
        
    }
    SCOL_ LLAC_
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
    }
    | PRINT_ PARA_ expre PARC_ SCOL_
    {
        if($3.t != T_ENTERO)
            yyerror("El argumento del 'print' debe ser entero.");
    }
    ;

instSelec 
    : IF_ PARA_ expre 
    {
        if($3.t != T_LOGICO && $3.t != T_ERROR)
            yyerror("La expresión del 'if' debe ser de tipo 'lógico'.");
    }
    PARC_ inst ELSE_ inst
    ;

instIter 
    : FOR_ PARA_ expreOP SCOL_ expre SCOL_ expreOP PARC_
    {
        if ($3.t == T_ARRAY || $7.t == T_ARRAY) 
            yyerror("La expresión condicional del 'for' debe ser de tipo 'simple'.");
        else if($5.t != T_LOGICO && $5.t != T_ERROR)
            yyerror("La expresión del 'for' debe ser de tipo 'lógico'.");
    } 
    inst
    ;

expreOP 
    : expre
    { $$.t = $1.t; }
    | 
    { $$.t = T_VACIO; } 
    ;

expre 
    : expreLogic 
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
            else
                $$.t = simb.t;
        }
    }
    | ID_ CORA_ expre CORC_ ASIG_ expre
    {
        SIMB sim = obtTdS($1);
        DIM dim;

        if(sim.t != T_ARRAY)
            yyerror("La variable no es un vector, no se puede acceder mediante indices.");
        else
            dim = obtTdA(sim.ref);
        
        if ($3.t != T_ERROR && $6.t != T_ERROR) {                    
            if(sim.t == T_ERROR) {
                yyerror("No existe ninguna variable con ese identificador.");
            } else if (! ($3.t == T_ENTERO)) {
                yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
            } else if (! ($6.t == dim.telem)) { 
                yyerror("Incompatibilidad de tipos en la asignación del vector."); 
            }                      
        }
    }
    ;

expreLogic 
    : expreIgual 
    { $$.t = $1.t; }
    | expreLogic opLogic expreIgual
    {
        $$.t = T_ERROR;
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            printf("%d, %d, %d", $1.t, $2, $3.t);
            if($3.t != T_LOGICO || $1.t != T_LOGICO)
                yyerror("Error en 'expresion logica'.");
            else if(!($2 == OP_AND || $2 == OP_OR))
                yyerror("Error en 'expresion logica'.");
            else
                $$.t = T_LOGICO;
        }
    }
    ;

expreIgual 
    : expreRel
    { $$.t = $1.t; }
    | expreIgual opIgual expreRel
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if($3.t != $1.t)
                yyerror("Error en 'expresión de igualdad'."); 
            else if(!($3.t == T_LOGICO || $3.t == T_ENTERO))
                yyerror("Error en 'expresión de igualdad'.");
            else
                $$.t = T_LOGICO;
        }
    }   
    ;

expreRel 
    : expreAd 
    { $$.t = $1.t; }
    | expreRel opRel expreAd
    {
        $$.t = T_ERROR; 
        if ($1.t != T_ERROR && $3.t != T_ERROR) {
            if (!($1.t == $3.t && $1.t == T_ENTERO && $3.t == T_ENTERO)) {
                yyerror("Error en 'expresión relacional'.");
            } else {
                $$.t = T_LOGICO;
            }
        }
    }   
    ;

expreAd 
    : expreMul
    { $$.t = $1.t; }
    | expreAd opAd expreMul
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if(!($1.t == $3.t && $1.t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión aditiva'.");
            else
                $$.t = T_ENTERO;
        }
    }   
    ;

expreMul 
    : expreUna
    { $$.t = $1.t; }
    | expreMul opMul expreUna
    {
        $$.t = T_ERROR; 
        if($1.t != T_ERROR && $3.t != T_ERROR)
        {
            if(!($1.t == $3.t && $1.t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión multiplicativa'.");
            else
                $$.t = T_ENTERO;
        }
    }   
    ;

expreUna 
    : expreSufi
    { $$.t = $1.t; }
    | opUna expreUna
    {
        $$.t = T_ERROR;
        if($2.t == T_ENTERO)
        {
            if($1 == OP_NOT)
                yyerror("Error en 'expresión unaria'. No se puede negar un entero.");
            else
                $$.t = T_ENTERO;    
        }
        else if($2.t == T_LOGICO)
        {
            if($1 == OP_SUMA || $1 == OP_RESTA)
                yyerror("Error en 'expresión unaria'. No se puede operar aritméticamente con valores lógicos.");
            else
                $$.t = T_LOGICO;    
        }
        else
            yyerror("Error en 'expresión unaria'. Los valores no son equivalentes o los tipos no casan.");
    }
    ;

expreSufi 
    : const
    { $$.t = $1.t; }
    | PARA_ expre PARC_
    { $$.t = $2.t; }   
    | ID_
    {
        SIMB simb = obtTdS($1);

        $$.t = T_ERROR;

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else
            $$.t = simb.t;
    }
    | ID_ CORA_ expre CORC_
    {
        SIMB simb = obtTdS($1);

        $$.t = T_ERROR; 

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else if($3.t != T_ENTERO)
            yyerror("Los valores no son equivalentes o los tipos no casan.");
        else
        {
            DIM dim = obtTdA(simb.ref);
            $$.t = dim.telem;
        }
    }

    | ID_ PARA_ paramAct PARC_
    {
        SIMB simb = obtTdS($1);

        $$.t = T_ERROR;
                
        if (simb.t == T_ERROR) 
            yyerror("No existe ninguna variable con ese identificador."); 
        if(!cmpDom(simb.ref, $3.ref)){
             yyerror("Los argumentos de la función no coinciden."); 
        }
        INF func = obtTdD(simb.ref);
        if (func.tipo == T_ERROR) 
            yyerror("No existe ninguna funcion con ese identificador."); 
        else
            $$.t = func.tipo;
    }
    ;

const 
    : CTE_    { $$.t = T_ENTERO; }
    | TRUE_   { $$.t = T_LOGICO; }
    | FALSE_  { $$.t = T_LOGICO; }
    ;

opLogic
    : AND_    { $$ = OP_AND; }
    | OR_     { $$ = OP_OR; }
    ;

opIgual
    : EQ_     { $$ = OP_IGUAL; }
    | NEQ_    { $$ = OP_NOTIGUAL; }
    ;

opRel
    : GE_     { $$ = OP_MAYOR; }
    | LE_     { $$ = OP_MENOR; }
    | GEQ_    { $$ = OP_MAYORIG; }
    | LEQ_    { $$ = OP_MENORIG; }
    ;

opAd
    : MAS_    { $$ = OP_SUMA; }
    | MENOS_  { $$ = OP_RESTA; }
    ;

opMul
    : POR_    { $$ = OP_MULT; }
    | DIV_    { $$ = OP_DIV; }
    ;

opUna
    : MAS_    { $$ = OP_SUMA; }
    | MENOS_  { $$ = OP_RESTA; }
    | NOT_    { $$ = OP_NOT; }
    ;
