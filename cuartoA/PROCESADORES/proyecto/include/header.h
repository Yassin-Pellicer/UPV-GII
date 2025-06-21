#include <stdio.h>

/*****************************************************************************/
/*****************************************************************************/
#ifndef _HEADER_H
#define _HEADER_H

/************************************* Variables externas definidas en el AL */
#define TRUE  1
#define FALSE 0
#define TALLA_SIMPLE 1
#define TALLA_DOBLE 2

#define OP_NOT 0
#define OP_SUMA 1
#define OP_RESTA 2
#define OP_MULT 3
#define OP_DIV 4
#define OP_MAYOR 5
#define OP_MENOR 6
#define OP_MAYORIG 7
#define OP_MENORIG 8
#define OP_IGUAL 9
#define OP_NOTIGUAL 10
#define OP_OR 11
#define OP_AND 12

typedef struct lista{
    int ref;
    int talla;
} List;

typedef struct texp{
   int t;           
   int pos;
} Expr;

typedef struct aux{
   int ref0;
   int ref1;
   int ref2;
   int ref3;
   int ref4;
} Aux;

extern int yylex();
extern int yyparse();

extern FILE *yyin;                           /* Fichero de entrada           */
extern int   yylineno;                       /* Contador del numero de linea */
extern char *yytext;                         /* Patron detectado             */

/********* Funciones y variables externas definidas en el Programa Principal */
extern void yyerror(const char * msg) ;     /* Tratamiento de errores          */

extern int verbosidad;                      /* Flag si se desea una traza       */
extern int numErrores;                      /* Contador del numero de errores        */
extern int verTdS;                          /* Flag para saber si mostrar la TdS */

extern int dvar;                            /* Desplazamiento en el Segmento de Variables */
extern int niv;                             /* Nivel de anidamiento "global" o "local" */

extern int si;

#endif  /* _HEADER_H */
