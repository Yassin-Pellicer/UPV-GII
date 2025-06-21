/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/asin.y"

    #include "header.h"
    #include "libtds.h" 
    #include <stdio.h>
    #include <string.h>

#line 78 "asin.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "asin.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAS_ = 3,                       /* MAS_  */
  YYSYMBOL_MENOS_ = 4,                     /* MENOS_  */
  YYSYMBOL_POR_ = 5,                       /* POR_  */
  YYSYMBOL_DIV_ = 6,                       /* DIV_  */
  YYSYMBOL_PARA_ = 7,                      /* PARA_  */
  YYSYMBOL_PARC_ = 8,                      /* PARC_  */
  YYSYMBOL_EQ_ = 9,                        /* EQ_  */
  YYSYMBOL_ASIG_ = 10,                     /* ASIG_  */
  YYSYMBOL_LLAA_ = 11,                     /* LLAA_  */
  YYSYMBOL_LLAC_ = 12,                     /* LLAC_  */
  YYSYMBOL_CORA_ = 13,                     /* CORA_  */
  YYSYMBOL_CORC_ = 14,                     /* CORC_  */
  YYSYMBOL_AND_ = 15,                      /* AND_  */
  YYSYMBOL_OR_ = 16,                       /* OR_  */
  YYSYMBOL_NEQ_ = 17,                      /* NEQ_  */
  YYSYMBOL_LE_ = 18,                       /* LE_  */
  YYSYMBOL_GE_ = 19,                       /* GE_  */
  YYSYMBOL_LEQ_ = 20,                      /* LEQ_  */
  YYSYMBOL_GEQ_ = 21,                      /* GEQ_  */
  YYSYMBOL_NOT_ = 22,                      /* NOT_  */
  YYSYMBOL_TRUE_ = 23,                     /* TRUE_  */
  YYSYMBOL_FALSE_ = 24,                    /* FALSE_  */
  YYSYMBOL_READ_ = 25,                     /* READ_  */
  YYSYMBOL_PRINT_ = 26,                    /* PRINT_  */
  YYSYMBOL_IF_ = 27,                       /* IF_  */
  YYSYMBOL_ELSE_ = 28,                     /* ELSE_  */
  YYSYMBOL_FOR_ = 29,                      /* FOR_  */
  YYSYMBOL_RET_ = 30,                      /* RET_  */
  YYSYMBOL_INT_ = 31,                      /* INT_  */
  YYSYMBOL_BOOL_ = 32,                     /* BOOL_  */
  YYSYMBOL_SCOL_ = 33,                     /* SCOL_  */
  YYSYMBOL_COL_ = 34,                      /* COL_  */
  YYSYMBOL_CTE_ = 35,                      /* CTE_  */
  YYSYMBOL_ID_ = 36,                       /* ID_  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_listDecla = 40,                 /* listDecla  */
  YYSYMBOL_decla = 41,                     /* decla  */
  YYSYMBOL_declaVar = 42,                  /* declaVar  */
  YYSYMBOL_tipoSimp = 43,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 44,                 /* declaFunc  */
  YYSYMBOL_45_2 = 45,                      /* $@2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_paramForm = 47,                 /* paramForm  */
  YYSYMBOL_listParamForm = 48,             /* listParamForm  */
  YYSYMBOL_paramAct = 49,                  /* paramAct  */
  YYSYMBOL_listParamAct = 50,              /* listParamAct  */
  YYSYMBOL_bloque = 51,                    /* bloque  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_declaVarLocal = 53,             /* declaVarLocal  */
  YYSYMBOL_listInst = 54,                  /* listInst  */
  YYSYMBOL_inst = 55,                      /* inst  */
  YYSYMBOL_instExpre = 56,                 /* instExpre  */
  YYSYMBOL_instEntSal = 57,                /* instEntSal  */
  YYSYMBOL_instSelec = 58,                 /* instSelec  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_instIter = 60,                  /* instIter  */
  YYSYMBOL_61_6 = 61,                      /* $@6  */
  YYSYMBOL_expreOP = 62,                   /* expreOP  */
  YYSYMBOL_expre = 63,                     /* expre  */
  YYSYMBOL_expreLogic = 64,                /* expreLogic  */
  YYSYMBOL_expreIgual = 65,                /* expreIgual  */
  YYSYMBOL_expreRel = 66,                  /* expreRel  */
  YYSYMBOL_expreAd = 67,                   /* expreAd  */
  YYSYMBOL_expreMul = 68,                  /* expreMul  */
  YYSYMBOL_expreUna = 69,                  /* expreUna  */
  YYSYMBOL_expreSufi = 70,                 /* expreSufi  */
  YYSYMBOL_const = 71,                     /* const  */
  YYSYMBOL_opLogic = 72,                   /* opLogic  */
  YYSYMBOL_opIgual = 73,                   /* opIgual  */
  YYSYMBOL_opRel = 74,                     /* opRel  */
  YYSYMBOL_opAd = 75,                      /* opAd  */
  YYSYMBOL_opMul = 76,                     /* opMul  */
  YYSYMBOL_opUna = 77                      /* opUna  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   168

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    65,    76,    78,    83,    85,    90,    98,
     107,   123,   125,   130,   131,   130,   153,   159,   166,   172,
     181,   187,   195,   200,   209,   208,   221,   222,   226,   227,
     231,   232,   233,   234,   235,   239,   240,   244,   250,   259,
     258,   268,   267,   278,   281,   285,   286,   306,   329,   331,
     347,   349,   365,   367,   381,   383,   397,   399,   413,   415,
     438,   440,   442,   453,   470,   490,   491,   492,   496,   497,
     501,   502,   506,   507,   508,   509,   513,   514,   518,   519,
     523,   524,   525
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAS_", "MENOS_",
  "POR_", "DIV_", "PARA_", "PARC_", "EQ_", "ASIG_", "LLAA_", "LLAC_",
  "CORA_", "CORC_", "AND_", "OR_", "NEQ_", "LE_", "GE_", "LEQ_", "GEQ_",
  "NOT_", "TRUE_", "FALSE_", "READ_", "PRINT_", "IF_", "ELSE_", "FOR_",
  "RET_", "INT_", "BOOL_", "SCOL_", "COL_", "CTE_", "ID_", "$accept",
  "programa", "$@1", "listDecla", "decla", "declaVar", "tipoSimp",
  "declaFunc", "$@2", "$@3", "paramForm", "listParamForm", "paramAct",
  "listParamAct", "bloque", "$@4", "declaVarLocal", "listInst", "inst",
  "instExpre", "instEntSal", "instSelec", "$@5", "instIter", "$@6",
  "expreOP", "expre", "expreLogic", "expreIgual", "expreRel", "expreAd",
  "expreMul", "expreUna", "expreSufi", "const", "opLogic", "opIgual",
  "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -128,     4,    27,  -128,  -128,  -128,    27,  -128,  -128,   -30,
    -128,  -128,     8,  -128,   -12,   -26,  -128,    27,  -128,  -128,
    -128,    -7,    31,    15,    56,  -128,  -128,    34,    37,  -128,
    -128,    27,    57,  -128,  -128,  -128,    27,  -128,    33,    13,
      -8,  -128,  -128,   125,  -128,  -128,    63,    65,    69,    72,
     125,  -128,    40,  -128,  -128,  -128,  -128,  -128,    48,    45,
      35,    36,    59,    60,  -128,  -128,  -128,   132,    76,    71,
      49,   125,   125,   125,  -128,   125,   125,   125,  -128,  -128,
    -128,   132,  -128,  -128,   132,  -128,  -128,  -128,  -128,   132,
    -128,  -128,   132,  -128,  -128,   132,     6,  -128,  -128,  -128,
      78,    79,  -128,    55,  -128,    58,    82,  -128,    74,  -128,
      85,    35,    36,    59,    60,  -128,   125,    70,    77,   103,
     125,   100,  -128,   125,   104,    99,  -128,  -128,    98,    83,
    -128,  -128,   125,  -128,    87,   125,  -128,    98,   109,  -128,
    -128,    98,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     3,     4,     6,     0,
       7,     5,     0,    13,     0,     0,     8,    17,    66,    67,
      65,     0,     0,     0,     0,    16,     9,     0,    18,    14,
      10,     0,     0,    19,    27,    15,    29,    26,     0,     0,
       0,    80,    81,     0,    29,    82,     0,     0,     0,     0,
       0,    36,    62,    28,    31,    32,    33,    34,     0,    45,
      48,    50,    52,    54,    56,    58,    60,     0,     0,     0,
       0,     0,     0,    44,    24,    21,     0,     0,    35,    68,
      69,     0,    70,    71,     0,    73,    72,    75,    74,     0,
      76,    77,     0,    78,    79,     0,    62,    59,    61,    30,
       0,     0,    39,     0,    43,     0,     0,    20,    22,    46,
       0,    49,    51,    53,    55,    57,     0,     0,     0,     0,
       0,     0,    64,     0,    63,     0,    37,    38,     0,     0,
      25,    23,     0,    63,     0,    44,    47,     0,     0,    40,
      41,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,   112,    90,    -9,  -128,  -128,  -128,
    -128,    88,  -128,     7,  -128,  -128,  -128,    93,  -127,  -128,
    -128,  -128,  -128,  -128,  -128,     3,   -43,  -128,    61,    62,
      51,    52,   -64,  -128,   127,  -128,  -128,  -128,  -128,  -128,
    -128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,     9,    10,    17,    32,
      24,    25,   106,   107,    35,   105,    36,    39,    53,    54,
      55,    56,   119,    57,   141,   103,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    81,    84,    89,    92,    95,
      67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      68,   134,    14,    97,     3,    15,    12,    74,    23,    22,
     139,    18,    19,    75,   142,    13,    41,    42,    14,   116,
      43,    15,    23,    20,    44,    16,    26,    38,   101,   102,
     104,   115,   108,   109,   110,    45,    18,    19,    46,    47,
      48,    16,    49,    50,    82,    27,    51,    75,    20,    52,
      76,    28,    83,    77,    85,    86,    87,    88,     4,     5,
      79,    80,    90,    91,    29,    93,    94,    30,    34,    40,
      70,    31,    71,   125,    41,    42,    72,   129,    43,    73,
     108,    78,    44,    99,    98,   100,   117,   118,   120,   136,
     122,   121,   104,    45,    18,    19,    46,    47,    48,   124,
      49,    41,    42,   126,    51,    43,    20,    52,   123,    44,
     127,   128,   130,   133,   132,   137,   135,   140,    11,    33,
      45,    18,    19,    46,    47,    48,    37,    49,    41,    42,
     131,    51,    43,    20,    52,    41,    42,    69,   138,    43,
     113,    21,   111,     0,   114,     0,   112,    45,    18,    19,
       0,     0,     0,     0,    45,    18,    19,     0,     0,     0,
      20,    52,     0,     0,     0,     0,     0,    20,    96
};

static const yytype_int16 yycheck[] =
{
      43,   128,    10,    67,     0,    13,    36,    50,    17,    35,
     137,    23,    24,     7,   141,     7,     3,     4,    10,    13,
       7,    13,    31,    35,    11,    33,    33,    36,    71,    72,
      73,    95,    75,    76,    77,    22,    23,    24,    25,    26,
      27,    33,    29,    30,     9,    14,    33,     7,    35,    36,
      10,    36,    17,    13,    18,    19,    20,    21,    31,    32,
      15,    16,     3,     4,     8,     5,     6,    33,    11,    36,
       7,    34,     7,   116,     3,     4,     7,   120,     7,     7,
     123,    33,    11,    12,     8,    36,     8,     8,    33,   132,
       8,    33,   135,    22,    23,    24,    25,    26,    27,    14,
      29,     3,     4,    33,    33,     7,    35,    36,    34,    11,
      33,     8,    12,    14,    10,    28,    33,     8,     6,    31,
      22,    23,    24,    25,    26,    27,    36,    29,     3,     4,
     123,    33,     7,    35,    36,     3,     4,    44,   135,     7,
      89,    14,    81,    -1,    92,    -1,    84,    22,    23,    24,
      -1,    -1,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    -1,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    31,    32,    40,    41,    42,    43,
      44,    41,    36,     7,    10,    13,    33,    45,    23,    24,
      35,    71,    35,    43,    47,    48,    33,    14,    36,     8,
      33,    34,    46,    48,    11,    51,    53,    42,    43,    54,
      36,     3,     4,     7,    11,    22,    25,    26,    27,    29,
      30,    33,    36,    55,    56,    57,    58,    60,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    77,    63,    54,
       7,     7,     7,     7,    63,     7,    10,    13,    33,    15,
      16,    72,     9,    17,    73,    18,    19,    20,    21,    74,
       3,     4,    75,     5,     6,    76,    36,    69,     8,    12,
      36,    63,    63,    62,    63,    52,    49,    50,    63,    63,
      63,    65,    66,    67,    68,    69,    13,     8,     8,    59,
      33,    33,     8,    34,    14,    63,    33,    33,     8,    63,
      12,    50,    10,    14,    55,    33,    63,    28,    62,    55,
       8,    61,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    45,    46,    44,    47,    47,    48,    48,
      49,    49,    50,    50,    52,    51,    53,    53,    54,    54,
      55,    55,    55,    55,    55,    56,    56,    57,    57,    59,
      58,    61,    60,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    70,    70,    70,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     0,     0,     8,     1,     0,     2,     4,
       1,     0,     1,     3,     0,     8,     2,     0,     2,     0,
       3,     1,     1,     1,     1,     2,     1,     5,     5,     0,
       8,     0,    10,     1,     0,     1,     3,     6,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 65 "src/asin.y"
    { dvar = 0; niv = 0; cargaContexto(niv); }
#line 1248 "asin.c"
    break;

  case 3: /* programa: $@1 listDecla  */
#line 67 "src/asin.y"
    { 
        if(verTdS) mostrarTdS(); 
        SIMB simb = obtTdS("main");
        if(simb.t == T_ERROR)
            yyerror("El programa no tiene función 'main'.");
    }
#line 1259 "asin.c"
    break;

  case 4: /* listDecla: decla  */
#line 77 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1265 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 79 "src/asin.y"
    { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); }
#line 1271 "asin.c"
    break;

  case 6: /* decla: declaVar  */
#line 84 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1277 "asin.c"
    break;

  case 7: /* decla: declaFunc  */
#line 86 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1283 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ SCOL_  */
#line 91 "src/asin.y"
    { 
        // Si la variable todavía no se ha añadido a la tabla de símbolos, se añade.
        if(!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else
            dvar += TALLA_SIMPLE;
    }
#line 1295 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const SCOL_  */
#line 99 "src/asin.y"
    {
        if(!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else if ((yyvsp[-4].cent) != (yyvsp[-1].texp).t)
            yyerror("El tipo esperado es inválido.");
        else
            dvar += TALLA_SIMPLE;
    }
#line 1308 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ CORA_ CTE_ CORC_ SCOL_  */
#line 108 "src/asin.y"
    {
        if((yyvsp[-2].cent) <= 0)
            yyerror("La talla del vector es incorrecta.");
        else
        {
            int ref = insTdA((yyvsp[-5].cent), (yyvsp[-2].cent));
            if(!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, ref))
                yyerror("Vector ya declarado con mismo identificador.");
            else
                dvar += (yyvsp[-2].cent) * TALLA_SIMPLE;
        }
    }
#line 1325 "asin.c"
    break;

  case 11: /* tipoSimp: INT_  */
#line 124 "src/asin.y"
    { (yyval.cent) = T_ENTERO; }
#line 1331 "asin.c"
    break;

  case 12: /* tipoSimp: BOOL_  */
#line 126 "src/asin.y"
    { (yyval.cent) = T_LOGICO; }
#line 1337 "asin.c"
    break;

  case 13: /* $@2: %empty  */
#line 130 "src/asin.y"
                         {niv += 1; cargaContexto(niv);}
#line 1343 "asin.c"
    break;

  case 14: /* $@3: %empty  */
#line 131 "src/asin.y"
    {
        if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), 0, -1, (yyvsp[-1].list).ref))
        {
            if (strcmp((yyvsp[-4].ident), "main\0") == 0) 
            {
                yyerror("Esta función ya ha sido declarada. (Ya se ha declarado 'main').");
            }
            yyerror("Esta función ya ha sido declarada.");
        }
    }
#line 1358 "asin.c"
    break;

  case 15: /* declaFunc: tipoSimp ID_ PARA_ $@2 paramForm PARC_ $@3 bloque  */
#line 142 "src/asin.y"
    {
        if (verTdS) {
            mostrarTdS(); 
        }
        descargaContexto(niv); 
        niv -= 1; 
        (yyval.cent) = (yyvsp[-7].cent);
    }
#line 1371 "asin.c"
    break;

  case 16: /* paramForm: listParamForm  */
#line 154 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1380 "asin.c"
    break;

  case 17: /* paramForm: %empty  */
#line 159 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1389 "asin.c"
    break;

  case 18: /* listParamForm: tipoSimp ID_  */
#line 167 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[-1].cent));
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
        if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador.");
    }
#line 1399 "asin.c"
    break;

  case 19: /* listParamForm: tipoSimp ID_ COL_ listParamForm  */
#line 173 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-3].cent));
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
        if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador."); 
    }
#line 1409 "asin.c"
    break;

  case 20: /* paramAct: listParamAct  */
#line 182 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1418 "asin.c"
    break;

  case 21: /* paramAct: %empty  */
#line 187 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1427 "asin.c"
    break;

  case 22: /* listParamAct: expre  */
#line 196 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[0].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
    }
#line 1436 "asin.c"
    break;

  case 23: /* listParamAct: expre COL_ listParamAct  */
#line 201 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-2].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
    }
#line 1445 "asin.c"
    break;

  case 24: /* $@4: %empty  */
#line 209 "src/asin.y"
    {
        INF inf = obtTdD(-1);
        if(inf.tipo == T_ERROR)
            yyerror("Función ya declarada. Comprobación de retorno de tipos invalidada.");
        else if(inf.tipo != (yyvsp[0].texp).t)
            yyerror("El tipo de retorno de la función no coincide con el declarado.");
        
    }
#line 1458 "asin.c"
    break;

  case 37: /* instEntSal: READ_ PARA_ ID_ PARC_ SCOL_  */
#line 245 "src/asin.y"
    {			
        SIMB simb = obtTdS((yyvsp[-2].ident));
        if(simb.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser entero.");
    }
#line 1468 "asin.c"
    break;

  case 38: /* instEntSal: PRINT_ PARA_ expre PARC_ SCOL_  */
#line 251 "src/asin.y"
    {
        if((yyvsp[-2].texp).t != T_ENTERO)
            yyerror("El argumento del 'print' debe ser entero.");
    }
#line 1477 "asin.c"
    break;

  case 39: /* $@5: %empty  */
#line 259 "src/asin.y"
    {
        if((yyvsp[0].texp).t != T_LOGICO && (yyvsp[0].texp).t != T_ERROR)
            yyerror("La expresión del 'if' debe ser de tipo 'lógico'.");
    }
#line 1486 "asin.c"
    break;

  case 41: /* $@6: %empty  */
#line 268 "src/asin.y"
    {
        if ((yyvsp[-5].texp).t == T_ARRAY || (yyvsp[-1].texp).t == T_ARRAY) 
            yyerror("La expresión condicional del 'for' debe ser de tipo 'simple'.");
        else if((yyvsp[-3].texp).t != T_LOGICO && (yyvsp[-3].texp).t != T_ERROR)
            yyerror("La expresión del 'for' debe ser de tipo 'lógico'.");
    }
#line 1497 "asin.c"
    break;

  case 43: /* expreOP: expre  */
#line 279 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1503 "asin.c"
    break;

  case 44: /* expreOP: %empty  */
#line 281 "src/asin.y"
    { (yyval.texp).t = T_VACIO; }
#line 1509 "asin.c"
    break;

  case 46: /* expre: ID_ ASIG_ expre  */
#line 287 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        SIMB simb = obtTdS((yyvsp[-2].ident));

        if((yyvsp[0].texp).t != T_ERROR)
        {   
            if(simb.t == T_ERROR)
                yyerror("Objeto no declarado.");
            else if (simb.t != (yyvsp[0].texp).t)
            {
                if (simb.t == T_ARRAY || (yyvsp[0].texp).t == T_ARRAY)
                    yyerror("Una de las variables es un vector. La asignación es incompatible.");
                else
                    yyerror("Tipos incompatibles.");
            }
            else
                (yyval.texp).t = simb.t;
        }
    }
#line 1533 "asin.c"
    break;

  case 47: /* expre: ID_ CORA_ expre CORC_ ASIG_ expre  */
#line 307 "src/asin.y"
    {
        SIMB sim = obtTdS((yyvsp[-5].ident));
        DIM dim;

        if(sim.t != T_ARRAY)
            yyerror("La variable no es un vector, no se puede acceder mediante indices.");
        else
            dim = obtTdA(sim.ref);
        
        if ((yyvsp[-3].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {                    
            if(sim.t == T_ERROR) {
                yyerror("No existe ninguna variable con ese identificador.");
            } else if (! ((yyvsp[-3].texp).t == T_ENTERO)) {
                yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
            } else if (! ((yyvsp[0].texp).t == dim.telem)) { 
                yyerror("Incompatibilidad de tipos en la asignación del vector."); 
            }                      
        }
    }
#line 1557 "asin.c"
    break;

  case 48: /* expreLogic: expreIgual  */
#line 330 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1563 "asin.c"
    break;

  case 49: /* expreLogic: expreLogic opLogic expreIgual  */
#line 332 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR;
        if ((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {
            printf("%d, %d, %d", (yyvsp[-2].texp).t, (yyvsp[-1].cent), (yyvsp[0].texp).t);
            if((yyvsp[0].texp).t != T_LOGICO || (yyvsp[-2].texp).t != T_LOGICO)
                yyerror("Error en 'expresion logica'.");
            else if(!((yyvsp[-1].cent) == OP_AND || (yyvsp[-1].cent) == OP_OR))
                yyerror("Error en 'expresion logica'.");
            else
                (yyval.texp).t = T_LOGICO;
        }
    }
#line 1580 "asin.c"
    break;

  case 50: /* expreIgual: expreRel  */
#line 348 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1586 "asin.c"
    break;

  case 51: /* expreIgual: expreIgual opIgual expreRel  */
#line 350 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if((yyvsp[0].texp).t != (yyvsp[-2].texp).t)
                yyerror("Error en 'expresión de igualdad'."); 
            else if(!((yyvsp[0].texp).t == T_LOGICO || (yyvsp[0].texp).t == T_ENTERO))
                yyerror("Error en 'expresión de igualdad'.");
            else
                (yyval.texp).t = T_LOGICO;
        }
    }
#line 1603 "asin.c"
    break;

  case 52: /* expreRel: expreAd  */
#line 366 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1609 "asin.c"
    break;

  case 53: /* expreRel: expreRel opRel expreAd  */
#line 368 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if ((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {
            if (!((yyvsp[-2].texp).t == (yyvsp[0].texp).t && (yyvsp[-2].texp).t == T_ENTERO && (yyvsp[0].texp).t == T_ENTERO)) {
                yyerror("Error en 'expresión relacional'.");
            } else {
                (yyval.texp).t = T_LOGICO;
            }
        }
    }
#line 1624 "asin.c"
    break;

  case 54: /* expreAd: expreMul  */
#line 382 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1630 "asin.c"
    break;

  case 55: /* expreAd: expreAd opAd expreMul  */
#line 384 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if(!((yyvsp[-2].texp).t == (yyvsp[0].texp).t && (yyvsp[-2].texp).t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión aditiva'.");
            else
                (yyval.texp).t = T_ENTERO;
        }
    }
#line 1645 "asin.c"
    break;

  case 56: /* expreMul: expreUna  */
#line 398 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1651 "asin.c"
    break;

  case 57: /* expreMul: expreMul opMul expreUna  */
#line 400 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if(!((yyvsp[-2].texp).t == (yyvsp[0].texp).t && (yyvsp[-2].texp).t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión multiplicativa'.");
            else
                (yyval.texp).t = T_ENTERO;
        }
    }
#line 1666 "asin.c"
    break;

  case 58: /* expreUna: expreSufi  */
#line 414 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1672 "asin.c"
    break;

  case 59: /* expreUna: opUna expreUna  */
#line 416 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR;
        if((yyvsp[0].texp).t == T_ENTERO)
        {
            if((yyvsp[-1].cent) == OP_NOT)
                yyerror("Error en 'expresión unaria'. No se puede negar un entero.");
            else
                (yyval.texp).t = T_ENTERO;    
        }
        else if((yyvsp[0].texp).t == T_LOGICO)
        {
            if((yyvsp[-1].cent) == OP_SUMA || (yyvsp[-1].cent) == OP_RESTA)
                yyerror("Error en 'expresión unaria'. No se puede operar aritméticamente con valores lógicos.");
            else
                (yyval.texp).t = T_LOGICO;    
        }
        else
            yyerror("Error en 'expresión unaria'. Los valores no son equivalentes o los tipos no casan.");
    }
#line 1696 "asin.c"
    break;

  case 60: /* expreSufi: const  */
#line 439 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; }
#line 1702 "asin.c"
    break;

  case 61: /* expreSufi: PARA_ expre PARC_  */
#line 441 "src/asin.y"
    { (yyval.texp).t = (yyvsp[-1].texp).t; }
#line 1708 "asin.c"
    break;

  case 62: /* expreSufi: ID_  */
#line 443 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[0].ident));

        (yyval.texp).t = T_ERROR;

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else
            (yyval.texp).t = simb.t;
    }
#line 1723 "asin.c"
    break;

  case 63: /* expreSufi: ID_ CORA_ expre CORC_  */
#line 454 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-3].ident));

        (yyval.texp).t = T_ERROR; 

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else if((yyvsp[-1].texp).t != T_ENTERO)
            yyerror("Los valores no son equivalentes o los tipos no casan.");
        else
        {
            DIM dim = obtTdA(simb.ref);
            (yyval.texp).t = dim.telem;
        }
    }
#line 1743 "asin.c"
    break;

  case 64: /* expreSufi: ID_ PARA_ paramAct PARC_  */
#line 471 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-3].ident));

        (yyval.texp).t = T_ERROR;
                
        if (simb.t == T_ERROR) 
            yyerror("No existe ninguna variable con ese identificador."); 
        if(!cmpDom(simb.ref, (yyvsp[-1].list).ref)){
             yyerror("Los argumentos de la función no coinciden."); 
        }
        INF func = obtTdD(simb.ref);
        if (func.tipo == T_ERROR) 
            yyerror("No existe ninguna funcion con ese identificador."); 
        else
            (yyval.texp).t = func.tipo;
    }
#line 1764 "asin.c"
    break;

  case 65: /* const: CTE_  */
#line 490 "src/asin.y"
              { (yyval.texp).t = T_ENTERO; }
#line 1770 "asin.c"
    break;

  case 66: /* const: TRUE_  */
#line 491 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; }
#line 1776 "asin.c"
    break;

  case 67: /* const: FALSE_  */
#line 492 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; }
#line 1782 "asin.c"
    break;

  case 68: /* opLogic: AND_  */
#line 496 "src/asin.y"
              { (yyval.cent) = OP_AND; }
#line 1788 "asin.c"
    break;

  case 69: /* opLogic: OR_  */
#line 497 "src/asin.y"
              { (yyval.cent) = OP_OR; }
#line 1794 "asin.c"
    break;

  case 70: /* opIgual: EQ_  */
#line 501 "src/asin.y"
              { (yyval.cent) = OP_IGUAL; }
#line 1800 "asin.c"
    break;

  case 71: /* opIgual: NEQ_  */
#line 502 "src/asin.y"
              { (yyval.cent) = OP_NOTIGUAL; }
#line 1806 "asin.c"
    break;

  case 72: /* opRel: GE_  */
#line 506 "src/asin.y"
              { (yyval.cent) = OP_MAYOR; }
#line 1812 "asin.c"
    break;

  case 73: /* opRel: LE_  */
#line 507 "src/asin.y"
              { (yyval.cent) = OP_MENOR; }
#line 1818 "asin.c"
    break;

  case 74: /* opRel: GEQ_  */
#line 508 "src/asin.y"
              { (yyval.cent) = OP_MAYORIG; }
#line 1824 "asin.c"
    break;

  case 75: /* opRel: LEQ_  */
#line 509 "src/asin.y"
              { (yyval.cent) = OP_MENORIG; }
#line 1830 "asin.c"
    break;

  case 76: /* opAd: MAS_  */
#line 513 "src/asin.y"
              { (yyval.cent) = OP_SUMA; }
#line 1836 "asin.c"
    break;

  case 77: /* opAd: MENOS_  */
#line 514 "src/asin.y"
              { (yyval.cent) = OP_RESTA; }
#line 1842 "asin.c"
    break;

  case 78: /* opMul: POR_  */
#line 518 "src/asin.y"
              { (yyval.cent) = OP_MULT; }
#line 1848 "asin.c"
    break;

  case 79: /* opMul: DIV_  */
#line 519 "src/asin.y"
              { (yyval.cent) = OP_DIV; }
#line 1854 "asin.c"
    break;

  case 80: /* opUna: MAS_  */
#line 523 "src/asin.y"
              { (yyval.cent) = OP_SUMA; }
#line 1860 "asin.c"
    break;

  case 81: /* opUna: MENOS_  */
#line 524 "src/asin.y"
              { (yyval.cent) = OP_RESTA; }
#line 1866 "asin.c"
    break;

  case 82: /* opUna: NOT_  */
#line 525 "src/asin.y"
              { (yyval.cent) = OP_NOT; }
#line 1872 "asin.c"
    break;


#line 1876 "asin.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

