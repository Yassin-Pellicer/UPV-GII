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
    #include "libgci.h"
    #include <stdio.h>
    #include <string.h>

#line 79 "asin.c"

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
  YYSYMBOL_39_1 = 39,                      /* @1  */
  YYSYMBOL_listDecla = 40,                 /* listDecla  */
  YYSYMBOL_decla = 41,                     /* decla  */
  YYSYMBOL_declaVar = 42,                  /* declaVar  */
  YYSYMBOL_tipoSimp = 43,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 44,                 /* declaFunc  */
  YYSYMBOL_45_2 = 45,                      /* @2  */
  YYSYMBOL_46_3 = 46,                      /* $@3  */
  YYSYMBOL_paramForm = 47,                 /* paramForm  */
  YYSYMBOL_listParamForm = 48,             /* listParamForm  */
  YYSYMBOL_paramAct = 49,                  /* paramAct  */
  YYSYMBOL_listParamAct = 50,              /* listParamAct  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_bloque = 52,                    /* bloque  */
  YYSYMBOL_53_5 = 53,                      /* @5  */
  YYSYMBOL_declaVarLocal = 54,             /* declaVarLocal  */
  YYSYMBOL_listInst = 55,                  /* listInst  */
  YYSYMBOL_inst = 56,                      /* inst  */
  YYSYMBOL_instExpre = 57,                 /* instExpre  */
  YYSYMBOL_instEntSal = 58,                /* instEntSal  */
  YYSYMBOL_instSelec = 59,                 /* instSelec  */
  YYSYMBOL_60_6 = 60,                      /* @6  */
  YYSYMBOL_61_7 = 61,                      /* @7  */
  YYSYMBOL_instIter = 62,                  /* instIter  */
  YYSYMBOL_63_8 = 63,                      /* @8  */
  YYSYMBOL_64_9 = 64,                      /* @9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_expreOP = 66,                   /* expreOP  */
  YYSYMBOL_expre = 67,                     /* expre  */
  YYSYMBOL_expreLogic = 68,                /* expreLogic  */
  YYSYMBOL_expreIgual = 69,                /* expreIgual  */
  YYSYMBOL_expreRel = 70,                  /* expreRel  */
  YYSYMBOL_expreAd = 71,                   /* expreAd  */
  YYSYMBOL_expreMul = 72,                  /* expreMul  */
  YYSYMBOL_expreUna = 73,                  /* expreUna  */
  YYSYMBOL_expreSufi = 74,                 /* expreSufi  */
  YYSYMBOL_75_11 = 75,                     /* $@11  */
  YYSYMBOL_const = 76,                     /* const  */
  YYSYMBOL_opLogic = 77,                   /* opLogic  */
  YYSYMBOL_opIgual = 78,                   /* opIgual  */
  YYSYMBOL_opRel = 79,                     /* opRel  */
  YYSYMBOL_opAd = 80,                      /* opAd  */
  YYSYMBOL_opMul = 81,                     /* opMul  */
  YYSYMBOL_opUna = 82                      /* opUna  */
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
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

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
       0,    67,    67,    67,    87,    89,    94,    96,   101,   109,
     122,   136,   138,   143,   144,   143,   166,   172,   179,   185,
     194,   200,   208,   216,   215,   228,   227,   254,   255,   259,
     260,   264,   265,   266,   267,   268,   272,   273,   277,   284,
     294,   306,   293,   319,   323,   340,   318,   356,   359,   363,
     365,   386,   412,   414,   441,   443,   466,   468,   488,   490,
     505,   507,   522,   524,   553,   559,   561,   574,   594,   593,
     622,   623,   624,   628,   629,   633,   634,   638,   639,   640,
     641,   645,   646,   650,   651,   655,   656,   657
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
  "programa", "@1", "listDecla", "decla", "declaVar", "tipoSimp",
  "declaFunc", "@2", "$@3", "paramForm", "listParamForm", "paramAct",
  "listParamAct", "$@4", "bloque", "@5", "declaVarLocal", "listInst",
  "inst", "instExpre", "instEntSal", "instSelec", "@6", "@7", "instIter",
  "@8", "@9", "$@10", "expreOP", "expre", "expreLogic", "expreIgual",
  "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi", "$@11",
  "const", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -88,     4,    20,   -88,   -88,   -88,    20,   -88,   -88,   -23,
     -88,   -88,    -1,   -88,   -13,   -12,   -88,    20,   -88,   -88,
     -88,   -14,    31,    -9,    45,   -88,   -88,    27,    28,   -88,
     -88,    20,    53,   -88,   -88,   -88,   -88,    20,   -88,    38,
      13,    -8,   -88,   -88,   117,   -88,   -88,    68,    75,    77,
      79,   117,   -88,    37,   -88,   -88,   -88,   -88,   -88,    58,
      40,     9,    49,    69,    94,   -88,   -88,   -88,   124,    87,
      54,    60,   117,   117,   117,    70,   -88,   117,   117,   -88,
     -88,   -88,   124,   -88,   -88,   124,   -88,   -88,   -88,   -88,
     124,   -88,   -88,   124,   -88,   -88,   124,     1,   -88,   -88,
     -88,    96,    97,    98,    74,   -88,    99,   117,   -88,    88,
       9,    49,    69,    94,   -88,   117,    76,    85,   -88,   -88,
     -88,   100,   -88,    95,   112,   116,   -88,   -88,    90,   117,
     -88,   -88,   117,   -88,   -88,   101,   117,   -88,    82,   -88,
     -88,    90,   117,   -88,   125,   -88,    90,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     3,     4,     6,     0,
       7,     5,     0,    13,     0,     0,     8,    17,    71,    72,
      70,     0,     0,     0,     0,    16,     9,     0,    18,    14,
      10,     0,     0,    19,    25,    15,    28,    30,    27,     0,
       0,     0,    85,    86,     0,    30,    87,     0,     0,     0,
       0,     0,    37,    66,    29,    32,    33,    34,    35,     0,
      49,    52,    54,    56,    58,    60,    62,    64,     0,     0,
       0,     0,     0,     0,    48,     0,    68,     0,     0,    36,
      73,    74,     0,    75,    76,     0,    78,    77,    80,    79,
       0,    81,    82,     0,    83,    84,     0,    66,    63,    65,
      31,     0,     0,     0,     0,    47,     0,    21,    50,     0,
      53,    55,    57,    59,    61,     0,     0,     0,    40,    43,
      26,     0,    20,    22,    67,     0,    38,    39,     0,     0,
      69,    23,     0,    67,    41,     0,     0,    51,     0,    44,
      24,     0,    48,    42,     0,    45,     0,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   126,   105,   -16,   -88,   -88,   -88,
     -88,   104,   -88,     0,   -88,   -88,   -88,   -88,    92,   -87,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,    -4,
     -44,   -88,    61,    59,    55,    56,   -65,   -88,   -88,   136,
     -88,   -88,   -88,   -88,   -88,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,     9,    10,    17,    32,
      24,    25,   121,   122,   136,    35,    36,    37,    40,    54,
      55,    56,    57,   128,   138,    58,   129,   142,   146,   104,
      59,    60,    61,    62,    63,    64,    65,    66,   107,    67,
      82,    85,    90,    93,    96,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      69,    23,    14,    98,     3,    15,    13,    75,    76,    14,
      18,    19,    15,    12,   115,    23,    42,    43,    83,    26,
      44,    39,    20,    22,    45,    16,    84,    28,   102,   103,
     105,   114,    16,   108,   109,    46,    18,    19,    47,    48,
      49,   134,    50,    51,    76,    27,    52,    77,    20,    53,
      78,     4,     5,    29,   143,    80,    81,    42,    43,   147,
      30,    44,    31,   123,    34,    45,   100,    86,    87,    88,
      89,   125,    91,    92,    41,    71,    46,    18,    19,    47,
      48,    49,    72,    50,    73,   135,    74,    52,   137,    20,
      53,    79,   123,    42,    43,    99,   101,    44,   105,    94,
      95,    45,   124,   106,   116,   117,   118,   119,   130,   126,
     141,   120,    46,    18,    19,    47,    48,    49,   127,    50,
      42,    43,   132,    52,    44,    20,    53,    42,    43,   131,
     133,    44,    11,   145,   139,    33,   140,    70,   144,    46,
      18,    19,    38,   110,   111,   112,    46,    18,    19,   113,
      21,     0,    20,    53,     0,     0,     0,     0,     0,    20,
      97
};

static const yytype_int16 yycheck[] =
{
      44,    17,    10,    68,     0,    13,     7,    51,     7,    10,
      23,    24,    13,    36,    13,    31,     3,     4,     9,    33,
       7,    37,    35,    35,    11,    33,    17,    36,    72,    73,
      74,    96,    33,    77,    78,    22,    23,    24,    25,    26,
      27,   128,    29,    30,     7,    14,    33,    10,    35,    36,
      13,    31,    32,     8,   141,    15,    16,     3,     4,   146,
      33,     7,    34,   107,    11,    11,    12,    18,    19,    20,
      21,   115,     3,     4,    36,     7,    22,    23,    24,    25,
      26,    27,     7,    29,     7,   129,     7,    33,   132,    35,
      36,    33,   136,     3,     4,     8,    36,     7,   142,     5,
       6,    11,    14,    33,     8,     8,     8,    33,     8,    33,
      28,    12,    22,    23,    24,    25,    26,    27,    33,    29,
       3,     4,    10,    33,     7,    35,    36,     3,     4,    34,
      14,     7,     6,     8,    33,    31,   136,    45,   142,    22,
      23,    24,    37,    82,    85,    90,    22,    23,    24,    93,
      14,    -1,    35,    36,    -1,    -1,    -1,    -1,    -1,    35,
      36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    31,    32,    40,    41,    42,    43,
      44,    41,    36,     7,    10,    13,    33,    45,    23,    24,
      35,    76,    35,    43,    47,    48,    33,    14,    36,     8,
      33,    34,    46,    48,    11,    52,    53,    54,    42,    43,
      55,    36,     3,     4,     7,    11,    22,    25,    26,    27,
      29,    30,    33,    36,    56,    57,    58,    59,    62,    67,
      68,    69,    70,    71,    72,    73,    74,    76,    82,    67,
      55,     7,     7,     7,     7,    67,     7,    10,    13,    33,
      15,    16,    77,     9,    17,    78,    18,    19,    20,    21,
      79,     3,     4,    80,     5,     6,    81,    36,    73,     8,
      12,    36,    67,    67,    66,    67,    33,    75,    67,    67,
      69,    70,    71,    72,    73,    13,     8,     8,     8,    33,
      12,    49,    50,    67,    14,    67,    33,    33,    60,    63,
       8,    34,    10,    14,    56,    67,    51,    67,    61,    33,
      50,    28,    64,    56,    66,     8,    65,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    41,    42,    42,
      42,    43,    43,    45,    46,    44,    47,    47,    48,    48,
      49,    49,    50,    51,    50,    53,    52,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      60,    61,    59,    63,    64,    65,    62,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    74,    74,    75,    74,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    79,
      79,    80,    80,    81,    81,    82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     0,     0,     8,     1,     0,     2,     4,
       1,     0,     1,     0,     4,     0,     8,     2,     0,     2,
       0,     3,     1,     1,     1,     1,     2,     1,     5,     5,
       0,     0,     9,     0,     0,     0,    12,     1,     0,     1,
       3,     6,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     2,     1,     3,     1,     4,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* @1: %empty  */
#line 67 "src/asin.y"
    {   niv = 0; dvar = 0; si = 0; cargaContexto(niv); 
        (yyval.aux).ref1 = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));
        (yyval.aux).ref2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
    }
#line 1259 "asin.c"
    break;

  case 3: /* programa: @1 listDecla  */
#line 74 "src/asin.y"
    { 
        SIMB simb = obtTdS("main");
        if(simb.t == T_ERROR)
            yyerror("El programa no tiene función 'main'.");
        completaLans((yyvsp[-1].aux).ref1, crArgEnt(dvar));

        (yyval.aux).ref3 = simb.d;

        completaLans((yyvsp[-1].aux).ref2, crArgEtq((yyval.aux).ref3));
    }
#line 1274 "asin.c"
    break;

  case 4: /* listDecla: decla  */
#line 88 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1280 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 90 "src/asin.y"
    { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); }
#line 1286 "asin.c"
    break;

  case 6: /* decla: declaVar  */
#line 95 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1292 "asin.c"
    break;

  case 7: /* decla: declaFunc  */
#line 97 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1298 "asin.c"
    break;

  case 8: /* declaVar: tipoSimp ID_ SCOL_  */
#line 102 "src/asin.y"
    { 
        // Si la variable todavía no se ha añadido a la tabla de símbolos, se añade.
        if(!insTdS((yyvsp[-1].ident), VARIABLE, (yyvsp[-2].cent), niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else
            dvar += TALLA_SIMPLE;
    }
#line 1310 "asin.c"
    break;

  case 9: /* declaVar: tipoSimp ID_ ASIG_ const SCOL_  */
#line 110 "src/asin.y"
    {
        if(!insTdS((yyvsp[-3].ident), VARIABLE, (yyvsp[-4].cent), niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else if ((yyvsp[-4].cent) != (yyvsp[-1].texp).t)
            yyerror("El tipo esperado es inválido.");
        else
            dvar += TALLA_SIMPLE;

        SIMB simb = obtTdS((yyvsp[-3].ident));
        emite(EASIG, crArgEtq((yyvsp[-1].texp).pos), crArgNul(), crArgPos(simb.n, simb.d));
        
    }
#line 1327 "asin.c"
    break;

  case 10: /* declaVar: tipoSimp ID_ CORA_ CTE_ CORC_ SCOL_  */
#line 123 "src/asin.y"
    {

        if((yyvsp[-2].cent) <= 0)
            yyerror("La talla del vector es incorrecta.");
        int ref = insTdA((yyvsp[-5].cent), (yyvsp[-2].cent));
        if(!insTdS((yyvsp[-4].ident), VARIABLE, T_ARRAY, niv, dvar, ref))
            yyerror("Vector ya declarado con mismo identificador.");
        else
            dvar += (yyvsp[-2].cent) * TALLA_SIMPLE;
    }
#line 1342 "asin.c"
    break;

  case 11: /* tipoSimp: INT_  */
#line 137 "src/asin.y"
    { (yyval.cent) = T_ENTERO; }
#line 1348 "asin.c"
    break;

  case 12: /* tipoSimp: BOOL_  */
#line 139 "src/asin.y"
    { (yyval.cent) = T_LOGICO; }
#line 1354 "asin.c"
    break;

  case 13: /* @2: %empty  */
#line 143 "src/asin.y"
                         {(yyval.cent) = dvar; dvar = 0; niv=1; cargaContexto(niv); }
#line 1360 "asin.c"
    break;

  case 14: /* $@3: %empty  */
#line 144 "src/asin.y"
    {
        if(!insTdS((yyvsp[-4].ident), FUNCION, (yyvsp[-5].cent), 0, si, (yyvsp[-1].list).ref))
        {
            if (strcmp((yyvsp[-4].ident), "main\0") == 0) 
            {
                yyerror("Esta función ya ha sido declarada. (Ya se ha declarado 'main').");
            }
            yyerror("Esta función ya ha sido declarada.");
        }
    }
#line 1375 "asin.c"
    break;

  case 15: /* declaFunc: tipoSimp ID_ PARA_ @2 paramForm PARC_ $@3 bloque  */
#line 155 "src/asin.y"
    {
        if (verTdS) {
            mostrarTdS(); 
        }
        descargaContexto(niv); 
        niv = 0;
        dvar = (yyvsp[-4].cent);
    }
#line 1388 "asin.c"
    break;

  case 16: /* paramForm: listParamForm  */
#line 167 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1397 "asin.c"
    break;

  case 17: /* paramForm: %empty  */
#line 172 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1406 "asin.c"
    break;

  case 18: /* listParamForm: tipoSimp ID_  */
#line 180 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[-1].cent));
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
        if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador.");
    }
#line 1416 "asin.c"
    break;

  case 19: /* listParamForm: tipoSimp ID_ COL_ listParamForm  */
#line 186 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-3].cent));
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
        if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador."); 
    }
#line 1426 "asin.c"
    break;

  case 20: /* paramAct: listParamAct  */
#line 195 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1435 "asin.c"
    break;

  case 21: /* paramAct: %empty  */
#line 200 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1444 "asin.c"
    break;

  case 22: /* listParamAct: expre  */
#line 209 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[0].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[0].texp).pos));
    }
#line 1454 "asin.c"
    break;

  case 23: /* $@4: %empty  */
#line 216 "src/asin.y"
    { 
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-1].texp).pos)); 
    }
#line 1462 "asin.c"
    break;

  case 24: /* listParamAct: expre COL_ $@4 listParamAct  */
#line 220 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-3].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
    }
#line 1471 "asin.c"
    break;

  case 25: /* @5: %empty  */
#line 228 "src/asin.y"
    {
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        (yyval.cent) = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));   
    }
#line 1482 "asin.c"
    break;

  case 26: /* bloque: LLAA_ @5 declaVarLocal listInst RET_ expre SCOL_ LLAC_  */
#line 235 "src/asin.y"
    {
        INF inf = obtTdD(-1);
        if(inf.tipo == T_ERROR)
            yyerror("Función ya declarada. Comprobación de retorno de tipos invalidada.");
        else if(inf.tipo != (yyvsp[-2].texp).t)
            yyerror("El tipo de retorno de la función no coincide con el declarado.");
        completaLans((yyvsp[-6].cent), crArgEnt(dvar));

        int dret = TALLA_DOBLE + TALLA_SIMPLE + inf.tsp;
        emite(EASIG, crArgPos(niv, (yyvsp[-2].texp).pos), crArgNul(), crArgPos(niv, -dret));
        emite(TOPFP, crArgNul(), crArgNul(), crArgNul() );
        emite(FPPOP, crArgNul(), crArgNul(), crArgNul() );

        if (strcmp(inf.nom,"main") == 0) { emite(FIN, crArgNul(), crArgNul(), crArgNul()); }
        else { emite(RET, crArgNul(), crArgNul(), crArgNul()); }
    }
#line 1503 "asin.c"
    break;

  case 38: /* instEntSal: READ_ PARA_ ID_ PARC_ SCOL_  */
#line 278 "src/asin.y"
    {			
        SIMB simb = obtTdS((yyvsp[-2].ident));
        if(simb.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser entero.");
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.n, simb.d));
    }
#line 1514 "asin.c"
    break;

  case 39: /* instEntSal: PRINT_ PARA_ expre PARC_ SCOL_  */
#line 285 "src/asin.y"
    {
        if((yyvsp[-2].texp).t != T_ENTERO)
            yyerror("El argumento del 'print' debe ser entero.");
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-2].texp).pos));
    }
#line 1524 "asin.c"
    break;

  case 40: /* @6: %empty  */
#line 294 "src/asin.y"
    {
        if((yyvsp[-1].texp).t != T_LOGICO && (yyvsp[-1].texp).t != T_ERROR)
            yyerror("La expresión del 'if' debe ser de tipo 'lógico'.");
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        (yyval.aux).ref1 = creaLans(si);          
        // Las etiquetas (los saltos) están todavía por inicializarse. Apuntan a la referencia 
        // de la inst previa (apuntan a creaLans, linea 267)
        // Se saltará a la etiqueta cuando la condición de la expresión sea verdadera.
        // Es decir, si 0 es igual al contenido del argumento $6, o si la condición es FALSA.
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].texp).pos), crArgEnt(0), crArgEtq(-1) );
    }
#line 1540 "asin.c"
    break;

  case 41: /* @7: %empty  */
#line 306 "src/asin.y"
    {
        (yyval.aux).ref2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans((yyvsp[-1].aux).ref1, crArgEtq(si));
    }
#line 1550 "asin.c"
    break;

  case 42: /* instSelec: IF_ PARA_ expre PARC_ @6 inst @7 ELSE_ inst  */
#line 312 "src/asin.y"
    {
        completaLans((yyvsp[-2].aux).ref2, crArgEtq(si));
    }
#line 1558 "asin.c"
    break;

  case 43: /* @8: %empty  */
#line 319 "src/asin.y"
    {
       (yyval.aux).ref0 = si; 
    }
#line 1566 "asin.c"
    break;

  case 44: /* @9: %empty  */
#line 323 "src/asin.y"
    {
        if ((yyvsp[-1].texp).t == T_ARRAY) 
            yyerror("La expresión condicional del 'for' debe ser de tipo 'simple'.");
        else if((yyvsp[-1].texp).t != T_LOGICO && (yyvsp[-1].texp).t != T_ERROR)
            yyerror("La expresión del 'for' debe ser de tipo 'lógico'.");
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        (yyval.aux).ref1 = creaLans(si);          
        // Las etiquetas (los saltos) están todavía por inicializarse. Apuntan a la referencia 
        // de la inst previa (apuntan a creaLans, linea 282)
        // Se saltará a la etiqueta cuando la condición de la expresión sea verdadera
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].texp).pos), crArgEnt(1), crArgEtq(-1) );
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        (yyval.aux).ref2 = creaLans(si);                              
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        (yyval.aux).ref3 = si;    
    }
#line 1587 "asin.c"
    break;

  case 45: /* $@10: %empty  */
#line 340 "src/asin.y"
    {
        if ((yyvsp[-4].texp).t == T_ARRAY) {}
        else if((yyvsp[-4].texp).t != T_LOGICO && (yyvsp[-4].texp).t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].aux).ref0)); 
        completaLans((yyvsp[-2].aux).ref1, crArgEtq(si));
    }
#line 1598 "asin.c"
    break;

  case 46: /* instIter: FOR_ PARA_ expreOP SCOL_ @8 expre SCOL_ @9 expreOP PARC_ $@10 inst  */
#line 347 "src/asin.y"
    {
        if ((yyvsp[-6].texp).t == T_ARRAY) {}
        else if((yyvsp[-6].texp).t != T_LOGICO && (yyvsp[-6].texp).t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-4].aux).ref3)); 
        completaLans((yyvsp[-4].aux).ref2, crArgEtq(si));
    }
#line 1609 "asin.c"
    break;

  case 47: /* expreOP: expre  */
#line 357 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1615 "asin.c"
    break;

  case 48: /* expreOP: %empty  */
#line 359 "src/asin.y"
    { (yyval.texp).t = T_VACIO; }
#line 1621 "asin.c"
    break;

  case 49: /* expre: expreLogic  */
#line 364 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1627 "asin.c"
    break;

  case 50: /* expre: ID_ ASIG_ expre  */
#line 366 "src/asin.y"
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
            (yyval.texp).t = simb.t;
        }
        (yyval.texp).pos = (yyvsp[0].texp).pos;
        emite(EASIG, crArgPos(niv, (yyvsp[0].texp).pos), crArgNul(), crArgPos(simb.n, simb.d));
    }
#line 1652 "asin.c"
    break;

  case 51: /* expre: ID_ CORA_ expre CORC_ ASIG_ expre  */
#line 387 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-5].ident));
        DIM dim;

        if(simb.t != T_ARRAY)
            yyerror("La variable no es un vector, no se puede acceder mediante indices.");
        else
            dim = obtTdA(simb.ref);
        
        if ((yyvsp[-3].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {                    
            if(simb.t == T_ERROR) {
                yyerror("No existe ninguna variable con ese identificador.");
            } else if (! ((yyvsp[-3].texp).t == T_ENTERO)) {
                yyerror("El indice para acceder a un vector debe ser un entero 0 o positivo.");
            } else if (! ((yyvsp[0].texp).t == dim.telem)) { 
                yyerror("Incompatibilidad de tipos en la asignación del vector."); 
            }                      
        }
        (yyval.texp).pos = (yyvsp[-3].texp).pos;
        emite(EVA, crArgPos(simb.n, simb.d), crArgPos(niv, (yyvsp[-3].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos));

    }
#line 1679 "asin.c"
    break;

  case 52: /* expreLogic: expreIgual  */
#line 413 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1685 "asin.c"
    break;

  case 53: /* expreLogic: expreLogic opLogic expreIgual  */
#line 415 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR;
        if ((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {
            if((yyvsp[0].texp).t != T_LOGICO || (yyvsp[-2].texp).t != T_LOGICO)
                yyerror("Error en 'expresion logica'.");
            else if(!((yyvsp[-1].cent) == EMULT || (yyvsp[-1].cent) == ESUM))
                yyerror("Error en 'expresion logica'.");
        }
        (yyval.texp).t = T_LOGICO;
        (yyval.texp).pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        if ((yyvsp[-1].cent) == EMULT) { 
            emite(EMULT, crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
        } 
        else 
        {
            emite(ESUM, crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
            // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
            emite(EMENEQ, crArgPos(niv, (yyval.texp).pos), crArgEnt(1), crArgEtq(si+2));
            // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
            emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.texp).pos));
        }
    }
#line 1713 "asin.c"
    break;

  case 54: /* expreIgual: expreRel  */
#line 442 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1719 "asin.c"
    break;

  case 55: /* expreIgual: expreIgual opIgual expreRel  */
#line 444 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if((yyvsp[0].texp).t != (yyvsp[-2].texp).t)
                yyerror("Error en 'expresión de igualdad'."); 
            else if(!((yyvsp[0].texp).t == T_LOGICO || (yyvsp[0].texp).t == T_ENTERO))
                yyerror("Error en 'expresión de igualdad'.");
        }
        (yyval.texp).t = T_LOGICO;
        (yyval.texp).pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.texp).pos));
        // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgEtq(si + 2));
        // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.texp).pos));
    }
#line 1742 "asin.c"
    break;

  case 56: /* expreRel: expreAd  */
#line 467 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1748 "asin.c"
    break;

  case 57: /* expreRel: expreRel opRel expreAd  */
#line 469 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if ((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR) {
            if (!((yyvsp[-2].texp).t == (yyvsp[0].texp).t && (yyvsp[-2].texp).t == T_ENTERO && (yyvsp[0].texp).t == T_ENTERO)) {
                yyerror("Error en 'expresión relacional'.");
            } 
        }
        (yyval.texp).t = T_LOGICO;
        (yyval.texp).pos = creaVarTemp();
        // True. Se asigna siempre a true al principio.
        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, (yyval.texp).pos));
        // crArgEtq(si + 2): Label for skipping the "true" assignment if the condition fails.
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgEtq(si + 2));
        // False. Si la condición falla, se salta esta sentencia y se va a la instrucción inmediatamente posterior.
        emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, (yyval.texp).pos));
    }
#line 1769 "asin.c"
    break;

  case 58: /* expreAd: expreMul  */
#line 489 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1775 "asin.c"
    break;

  case 59: /* expreAd: expreAd opAd expreMul  */
#line 491 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if(!((yyvsp[-2].texp).t == (yyvsp[0].texp).t && (yyvsp[-2].texp).t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión aditiva'.");
        }
        (yyval.texp).t = T_ENTERO;
        (yyval.texp).pos = creaVarTemp();
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
    }
#line 1791 "asin.c"
    break;

  case 60: /* expreMul: expreUna  */
#line 506 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1797 "asin.c"
    break;

  case 61: /* expreMul: expreMul opMul expreUna  */
#line 508 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR; 
        if((yyvsp[-2].texp).t != T_ERROR && (yyvsp[0].texp).t != T_ERROR)
        {
            if(!((yyvsp[-2].texp).t == T_ENTERO && (yyvsp[0].texp).t == T_ENTERO))
                yyerror("Error de tipos en la 'expresión multiplicativa'.");
        }
        (yyval.texp).t = T_ENTERO;
        (yyval.texp).pos = creaVarTemp();
        emite((yyvsp[-1].cent), crArgPos(niv, (yyvsp[-2].texp).pos), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
    }
#line 1813 "asin.c"
    break;

  case 62: /* expreUna: expreSufi  */
#line 523 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1819 "asin.c"
    break;

  case 63: /* expreUna: opUna expreUna  */
#line 525 "src/asin.y"
    {
        (yyval.texp).t = T_ERROR;
        if((yyvsp[0].texp).t == T_ENTERO)
        {
            if((yyvsp[-1].cent) == ESIG)
                yyerror("Error en 'expresión unaria'. No se puede negar un entero.");
            (yyval.texp).t = T_ENTERO;   
        }
        else if((yyvsp[0].texp).t == T_LOGICO)
        {
            if((yyvsp[-1].cent) == ESUM || (yyvsp[-1].cent) == EDIF)
                yyerror("Error en 'expresión unaria'. No se puede operar aritméticamente con valores lógicos.");
            else
            {
                (yyval.texp).t = T_LOGICO;    
            }
        }
        else
            yyerror("Error en 'expresión unaria'. Los valores no son equivalentes o los tipos no casan.");
        (yyval.texp).pos = creaVarTemp();
        if((yyvsp[-1].cent) == ESIG)
            emite(EDIF, crArgEnt(1), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
        else
            emite((yyvsp[-1].cent), crArgEnt(0), crArgPos(niv, (yyvsp[0].texp).pos), crArgPos(niv, (yyval.texp).pos));
    }
#line 1849 "asin.c"
    break;

  case 64: /* expreSufi: const  */
#line 554 "src/asin.y"
    {   
        (yyval.texp).t = (yyvsp[0].texp).t; 
        (yyval.texp).pos = creaVarTemp();
        emite(EASIG, crArgEnt((yyvsp[0].texp).pos), crArgNul(), crArgPos(niv, (yyval.texp).pos));         
    }
#line 1859 "asin.c"
    break;

  case 65: /* expreSufi: PARA_ expre PARC_  */
#line 560 "src/asin.y"
    { (yyval.texp).t = (yyvsp[-1].texp).t; (yyval.texp).pos = (yyvsp[-1].texp).pos; }
#line 1865 "asin.c"
    break;

  case 66: /* expreSufi: ID_  */
#line 562 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[0].ident));

        (yyval.texp).t = T_ERROR;

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else
            (yyval.texp).t = simb.t;
        (yyval.texp).pos = creaVarTemp();
        emite(EASIG, crArgPos(simb.n, simb.d), crArgNul(), crArgPos(niv, (yyval.texp).pos));   
    }
#line 1882 "asin.c"
    break;

  case 67: /* expreSufi: ID_ CORA_ expre CORC_  */
#line 575 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-3].ident));

        (yyval.texp).t = T_ERROR; 

        if(simb.t == T_ERROR)
            yyerror("No existe ninguna variable con ese identificador.");
        else if((yyvsp[-1].texp).t != T_ENTERO)
        yyerror("Los valores no son equivalentes o los tipos no casan.");
        DIM dim = obtTdA(simb.ref);
        (yyval.texp).t = dim.telem;

        // En este caso debemos hacer una asignación para instanciar el valor que almacena la variable
        // de nombre ID en $$.pos (que viene a ser la posición de expreSufi)
        (yyval.texp).pos = creaVarTemp();
        emite(EAV, crArgPos(simb.n, simb.d), crArgPos(niv, (yyvsp[-1].texp).pos), crArgPos(niv, (yyval.texp).pos)); 
    }
#line 1904 "asin.c"
    break;

  case 68: /* $@11: %empty  */
#line 594 "src/asin.y"
    {   
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_SIMPLE)); 
    }
#line 1912 "asin.c"
    break;

  case 69: /* expreSufi: ID_ PARA_ $@11 paramAct PARC_  */
#line 598 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-4].ident));
        INF inf = obtTdD(simb.ref);

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
            (yyval.texp).t = inf.tipo;
        emite(CALL, crArgNul(), crArgNul(), crArgEtq(simb.d)); 
        emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp)); 
        (yyval.texp).pos = creaVarTemp();
        emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, (yyval.texp).pos));
    }
#line 1938 "asin.c"
    break;

  case 70: /* const: CTE_  */
#line 622 "src/asin.y"
              { (yyval.texp).t = T_ENTERO; (yyval.texp).pos = (yyvsp[0].cent); }
#line 1944 "asin.c"
    break;

  case 71: /* const: TRUE_  */
#line 623 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; (yyval.texp).pos = 1; }
#line 1950 "asin.c"
    break;

  case 72: /* const: FALSE_  */
#line 624 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; (yyval.texp).pos = 0; }
#line 1956 "asin.c"
    break;

  case 73: /* opLogic: AND_  */
#line 628 "src/asin.y"
              { (yyval.cent) = EMULT; }
#line 1962 "asin.c"
    break;

  case 74: /* opLogic: OR_  */
#line 629 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 1968 "asin.c"
    break;

  case 75: /* opIgual: EQ_  */
#line 633 "src/asin.y"
              { (yyval.cent) = EIGUAL; }
#line 1974 "asin.c"
    break;

  case 76: /* opIgual: NEQ_  */
#line 634 "src/asin.y"
              { (yyval.cent) = EDIST; }
#line 1980 "asin.c"
    break;

  case 77: /* opRel: GE_  */
#line 638 "src/asin.y"
              { (yyval.cent) = EMAY; }
#line 1986 "asin.c"
    break;

  case 78: /* opRel: LE_  */
#line 639 "src/asin.y"
              { (yyval.cent) = EMEN; }
#line 1992 "asin.c"
    break;

  case 79: /* opRel: GEQ_  */
#line 640 "src/asin.y"
              { (yyval.cent) = EMAYEQ; }
#line 1998 "asin.c"
    break;

  case 80: /* opRel: LEQ_  */
#line 641 "src/asin.y"
              { (yyval.cent) = EMENEQ; }
#line 2004 "asin.c"
    break;

  case 81: /* opAd: MAS_  */
#line 645 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 2010 "asin.c"
    break;

  case 82: /* opAd: MENOS_  */
#line 646 "src/asin.y"
              { (yyval.cent) = EDIF; }
#line 2016 "asin.c"
    break;

  case 83: /* opMul: POR_  */
#line 650 "src/asin.y"
              { (yyval.cent) = EMULT; }
#line 2022 "asin.c"
    break;

  case 84: /* opMul: DIV_  */
#line 651 "src/asin.y"
              { (yyval.cent) = EDIVI; }
#line 2028 "asin.c"
    break;

  case 85: /* opUna: MAS_  */
#line 655 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 2034 "asin.c"
    break;

  case 86: /* opUna: MENOS_  */
#line 656 "src/asin.y"
              { (yyval.cent) = EDIF; }
#line 2040 "asin.c"
    break;

  case 87: /* opUna: NOT_  */
#line 657 "src/asin.y"
              { (yyval.cent) = ESIG; }
#line 2046 "asin.c"
    break;


#line 2050 "asin.c"

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

