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
  YYSYMBOL_IN_ = 31,                       /* IN_  */
  YYSYMBOL_RANGE_ = 32,                    /* RANGE_  */
  YYSYMBOL_WHILE_ = 33,                    /* WHILE_  */
  YYSYMBOL_USING_ = 34,                    /* USING_  */
  YYSYMBOL_TIMES_ = 35,                    /* TIMES_  */
  YYSYMBOL_DO_ = 36,                       /* DO_  */
  YYSYMBOL_INT_ = 37,                      /* INT_  */
  YYSYMBOL_BOOL_ = 38,                     /* BOOL_  */
  YYSYMBOL_SCOL_ = 39,                     /* SCOL_  */
  YYSYMBOL_COMMA_ = 40,                    /* COMMA_  */
  YYSYMBOL_SWITCH_ = 41,                   /* SWITCH_  */
  YYSYMBOL_LESS_ = 42,                     /* LESS_  */
  YYSYMBOL_EQUAL_ = 43,                    /* EQUAL_  */
  YYSYMBOL_GREATER_ = 44,                  /* GREATER_  */
  YYSYMBOL_COL_ = 45,                      /* COL_  */
  YYSYMBOL_WHEN_ = 46,                     /* WHEN_  */
  YYSYMBOL_CTE_ = 47,                      /* CTE_  */
  YYSYMBOL_ID_ = 48,                       /* ID_  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_programa = 50,                  /* programa  */
  YYSYMBOL_51_1 = 51,                      /* @1  */
  YYSYMBOL_listDecla = 52,                 /* listDecla  */
  YYSYMBOL_decla = 53,                     /* decla  */
  YYSYMBOL_declaVar = 54,                  /* declaVar  */
  YYSYMBOL_tipoSimp = 55,                  /* tipoSimp  */
  YYSYMBOL_declaFunc = 56,                 /* declaFunc  */
  YYSYMBOL_57_2 = 57,                      /* @2  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_paramForm = 59,                 /* paramForm  */
  YYSYMBOL_listParamForm = 60,             /* listParamForm  */
  YYSYMBOL_paramAct = 61,                  /* paramAct  */
  YYSYMBOL_listParamAct = 62,              /* listParamAct  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_bloque = 64,                    /* bloque  */
  YYSYMBOL_65_5 = 65,                      /* @5  */
  YYSYMBOL_declaVarLocal = 66,             /* declaVarLocal  */
  YYSYMBOL_listInst = 67,                  /* listInst  */
  YYSYMBOL_inst = 68,                      /* inst  */
  YYSYMBOL_instExpre = 69,                 /* instExpre  */
  YYSYMBOL_instEntSal = 70,                /* instEntSal  */
  YYSYMBOL_instSelec = 71,                 /* instSelec  */
  YYSYMBOL_72_6 = 72,                      /* @6  */
  YYSYMBOL_73_7 = 73,                      /* @7  */
  YYSYMBOL_instIter = 74,                  /* instIter  */
  YYSYMBOL_75_8 = 75,                      /* @8  */
  YYSYMBOL_76_9 = 76,                      /* @9  */
  YYSYMBOL_77_10 = 77,                     /* $@10  */
  YYSYMBOL_78_11 = 78,                     /* $@11  */
  YYSYMBOL_79_12 = 79,                     /* @12  */
  YYSYMBOL_80_13 = 80,                     /* @13  */
  YYSYMBOL_81_14 = 81,                     /* @14  */
  YYSYMBOL_instruccionUsingTimes = 82,     /* instruccionUsingTimes  */
  YYSYMBOL_83_15 = 83,                     /* @15  */
  YYSYMBOL_instSwitch = 84,                /* instSwitch  */
  YYSYMBOL_85_16 = 85,                     /* @16  */
  YYSYMBOL_86_17 = 86,                     /* @17  */
  YYSYMBOL_87_18 = 87,                     /* @18  */
  YYSYMBOL_instWhen = 88,                  /* instWhen  */
  YYSYMBOL_lClause = 89,                   /* lClause  */
  YYSYMBOL_clause = 90,                    /* clause  */
  YYSYMBOL_expreOP = 91,                   /* expreOP  */
  YYSYMBOL_expre = 92,                     /* expre  */
  YYSYMBOL_expreLogic = 93,                /* expreLogic  */
  YYSYMBOL_expreIgual = 94,                /* expreIgual  */
  YYSYMBOL_expreRel = 95,                  /* expreRel  */
  YYSYMBOL_expreAd = 96,                   /* expreAd  */
  YYSYMBOL_expreMul = 97,                  /* expreMul  */
  YYSYMBOL_expreUna = 98,                  /* expreUna  */
  YYSYMBOL_expreSufi = 99,                 /* expreSufi  */
  YYSYMBOL_100_19 = 100,                   /* $@19  */
  YYSYMBOL_const = 101,                    /* const  */
  YYSYMBOL_opLogic = 102,                  /* opLogic  */
  YYSYMBOL_opIgual = 103,                  /* opIgual  */
  YYSYMBOL_opRel = 104,                    /* opRel  */
  YYSYMBOL_opAd = 105,                     /* opAd  */
  YYSYMBOL_opMul = 106,                    /* opMul  */
  YYSYMBOL_opUna = 107                     /* opUna  */
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
#define YYLAST   200

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    67,    87,    89,    94,    96,   101,   109,
     122,   136,   138,   143,   144,   143,   166,   172,   179,   185,
     194,   200,   208,   216,   215,   228,   227,   254,   255,   259,
     260,   264,   265,   266,   267,   268,   269,   270,   271,   275,
     276,   280,   287,   297,   309,   296,   322,   326,   343,   321,
     357,   371,   356,   390,   394,   389,   407,   406,   437,   451,
     457,   436,   470,   473,   474,   477,   480,   483,   487,   489,
     510,   536,   538,   565,   567,   590,   592,   612,   614,   629,
     631,   646,   648,   677,   683,   685,   698,   718,   717,   746,
     747,   748,   752,   753,   757,   758,   762,   763,   764,   765,
     769,   770,   774,   775,   779,   780,   781
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
  "RET_", "IN_", "RANGE_", "WHILE_", "USING_", "TIMES_", "DO_", "INT_",
  "BOOL_", "SCOL_", "COMMA_", "SWITCH_", "LESS_", "EQUAL_", "GREATER_",
  "COL_", "WHEN_", "CTE_", "ID_", "$accept", "programa", "@1", "listDecla",
  "decla", "declaVar", "tipoSimp", "declaFunc", "@2", "$@3", "paramForm",
  "listParamForm", "paramAct", "listParamAct", "$@4", "bloque", "@5",
  "declaVarLocal", "listInst", "inst", "instExpre", "instEntSal",
  "instSelec", "@6", "@7", "instIter", "@8", "@9", "$@10", "$@11", "@12",
  "@13", "@14", "instruccionUsingTimes", "@15", "instSwitch", "@16", "@17",
  "@18", "instWhen", "lClause", "clause", "expreOP", "expre", "expreLogic",
  "expreIgual", "expreRel", "expreAd", "expreMul", "expreUna", "expreSufi",
  "$@19", "const", "opLogic", "opIgual", "opRel", "opAd", "opMul", "opUna", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-125)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -125,     3,   -24,  -125,  -125,  -125,   -24,  -125,  -125,   -38,
    -125,  -125,    20,  -125,    38,     4,  -125,   -24,  -125,  -125,
    -125,    17,    39,    10,    52,  -125,  -125,    33,    35,  -125,
    -125,   -24,    62,  -125,  -125,  -125,  -125,   -24,  -125,    31,
      73,    42,  -125,  -125,     2,  -125,  -125,    75,    83,    85,
      -3,     2,    86,    46,  -125,    53,     2,    61,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,    65,    54,    -1,    68,
      14,    26,  -125,  -125,  -125,    16,    97,   119,    60,     2,
       2,     2,    78,    74,  -125,     2,   104,  -125,     2,    71,
    -125,     2,     2,  -125,  -125,  -125,    16,  -125,  -125,    16,
    -125,  -125,  -125,  -125,    16,  -125,  -125,    16,  -125,  -125,
      16,    15,  -125,  -125,  -125,   110,   116,   120,    88,  -125,
     100,   117,     2,  -125,    91,  -125,   152,     2,  -125,   123,
      -1,    68,    14,    26,  -125,     2,    95,    99,  -125,  -125,
     132,  -125,   139,   105,  -125,  -125,   141,  -125,   111,   140,
     143,  -125,  -125,   152,     2,     2,  -125,   118,   152,  -125,
    -125,     2,  -125,  -125,   122,  -125,   152,   152,   121,     2,
    -125,   134,  -125,   128,  -125,  -125,  -125,  -125,   152,     2,
       2,   152,  -125,   161,  -125,   126,  -125,   163,  -125,   152,
     152,   152,  -125,  -125,   160,  -125
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,    11,    12,     3,     4,     6,     0,
       7,     5,     0,    13,     0,     0,     8,    17,    90,    91,
      89,     0,     0,     0,     0,    16,     9,     0,    18,    14,
      10,     0,     0,    19,    25,    15,    28,    30,    27,     0,
       0,     0,   104,   105,     0,    30,   106,     0,     0,     0,
       0,     0,     0,     0,    40,     0,     0,    85,    29,    32,
      33,    34,    35,    36,    37,    38,     0,    68,    71,    73,
      75,    77,    79,    81,    83,     0,     0,     0,     0,     0,
       0,    67,     0,     0,    53,     0,     0,    62,    64,     0,
      87,     0,     0,    39,    92,    93,     0,    94,    95,     0,
      97,    96,    99,    98,     0,   100,   101,     0,   102,   103,
       0,    85,    82,    84,    31,     0,     0,     0,     0,    66,
       0,     0,     0,    56,     0,    63,     0,    21,    69,     0,
      72,    74,    76,    78,    80,     0,     0,     0,    43,    46,
       0,    26,     0,     0,    58,    65,     0,    20,    22,    86,
       0,    41,    42,     0,     0,     0,    54,     0,     0,    88,
      23,     0,    86,    44,     0,    50,     0,     0,     0,     0,
      70,     0,    47,     0,    55,    57,    59,    24,     0,    67,
       0,     0,    45,     0,    51,     0,    48,     0,    60,     0,
       0,     0,    49,    52,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -125,  -125,  -125,  -125,   167,   145,   -16,  -125,  -125,  -125,
    -125,   149,  -125,    18,  -125,  -125,  -125,  -125,   138,  -124,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
    -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,  -125,
      96,  -125,     9,   -44,  -125,    93,    98,    90,    89,   -64,
    -125,  -125,   176,  -125,  -125,  -125,  -125,  -125,  -125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     6,     7,     8,     9,    10,    17,    32,
      24,    25,   146,   147,   169,    35,    36,    37,    40,    58,
      59,    60,    61,   153,   171,    62,   154,   179,   189,   173,
     187,   122,   166,    63,   143,    64,   158,   181,   191,    65,
      87,    88,   118,    66,    67,    68,    69,    70,    71,    72,
      73,   127,    74,    96,    99,   104,   107,   110,    75
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,    23,   145,     3,    81,    42,    43,    83,    97,    44,
      12,   112,    89,     4,     5,    23,    98,   105,   106,    42,
      43,    39,    90,    44,    46,    18,    19,    13,   135,   163,
      14,   108,   109,    15,   168,   116,   117,   119,    46,    18,
      19,   123,   174,   175,    89,    82,   134,   128,   129,    20,
      57,    22,    14,    27,   182,    15,    26,   185,    28,    16,
      29,    18,    19,    20,   111,   192,   193,   194,    90,    94,
      95,    91,    30,    34,    92,    31,    42,    43,   142,    41,
      44,    16,    78,   148,    45,    20,   100,   101,   102,   103,
      79,   150,    80,    84,    85,    46,    18,    19,    47,    48,
      49,    86,    50,    51,    93,   113,    52,    53,   115,   120,
     164,   165,    54,   121,    55,   124,   126,   170,   136,    56,
      20,    57,    42,    43,   137,   148,    44,   139,   138,   141,
      45,   114,   140,   144,   151,   119,   184,   149,   152,   155,
     157,    46,    18,    19,    47,    48,    49,   156,    50,   159,
     161,   160,    52,    53,   167,    42,    43,   162,    54,    44,
      55,   172,   178,    45,   176,    56,    20,    57,   180,   186,
     188,   190,   195,    11,    46,    18,    19,    47,    48,    49,
      33,    50,    38,    77,   125,    52,    53,   177,   183,   130,
      21,    54,     0,    55,   132,     0,   133,   131,    56,    20,
      57
};

static const yytype_int16 yycheck[] =
{
      44,    17,   126,     0,     7,     3,     4,    51,     9,     7,
      48,    75,    56,    37,    38,    31,    17,     3,     4,     3,
       4,    37,     7,     7,    22,    23,    24,     7,    13,   153,
      10,     5,     6,    13,   158,    79,    80,    81,    22,    23,
      24,    85,   166,   167,    88,    48,   110,    91,    92,    47,
      48,    47,    10,    14,   178,    13,    39,   181,    48,    39,
       8,    23,    24,    47,    48,   189,   190,   191,     7,    15,
      16,    10,    39,    11,    13,    40,     3,     4,   122,    48,
       7,    39,     7,   127,    11,    47,    18,    19,    20,    21,
       7,   135,     7,     7,    48,    22,    23,    24,    25,    26,
      27,    48,    29,    30,    39,     8,    33,    34,    48,    31,
     154,   155,    39,    39,    41,    11,    45,   161,     8,    46,
      47,    48,     3,     4,     8,   169,     7,    39,     8,    12,
      11,    12,    32,    42,    39,   179,   180,    14,    39,     7,
      35,    22,    23,    24,    25,    26,    27,     8,    29,     8,
      10,    40,    33,    34,    36,     3,     4,    14,    39,     7,
      41,    39,    28,    11,    43,    46,    47,    48,    40,     8,
      44,     8,    12,     6,    22,    23,    24,    25,    26,    27,
      31,    29,    37,    45,    88,    33,    34,   169,   179,    96,
      14,    39,    -1,    41,   104,    -1,   107,    99,    46,    47,
      48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    50,    51,     0,    37,    38,    52,    53,    54,    55,
      56,    53,    48,     7,    10,    13,    39,    57,    23,    24,
      47,   101,    47,    55,    59,    60,    39,    14,    48,     8,
      39,    40,    58,    60,    11,    64,    65,    66,    54,    55,
      67,    48,     3,     4,     7,    11,    22,    25,    26,    27,
      29,    30,    33,    34,    39,    41,    46,    48,    68,    69,
      70,    71,    74,    82,    84,    88,    92,    93,    94,    95,
      96,    97,    98,    99,   101,   107,    92,    67,     7,     7,
       7,     7,    48,    92,     7,    48,    48,    89,    90,    92,
       7,    10,    13,    39,    15,    16,   102,     9,    17,   103,
      18,    19,    20,    21,   104,     3,     4,   105,     5,     6,
     106,    48,    98,     8,    12,    48,    92,    92,    91,    92,
      31,    39,    80,    92,    11,    89,    45,   100,    92,    92,
      94,    95,    96,    97,    98,    13,     8,     8,     8,    39,
      32,    12,    92,    83,    42,    68,    61,    62,    92,    14,
      92,    39,    39,    72,    75,     7,     8,    35,    85,     8,
      40,    10,    14,    68,    92,    92,    81,    36,    68,    63,
      92,    73,    39,    78,    68,    68,    43,    62,    28,    76,
      40,    86,    68,    91,    92,    68,     8,    79,    44,    77,
       8,    87,    68,    68,    68,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    51,    50,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    57,    58,    56,    59,    59,    60,    60,
      61,    61,    62,    63,    62,    65,    64,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    72,    73,    71,    75,    76,    77,    74,
      78,    79,    74,    80,    81,    74,    83,    82,    85,    86,
      87,    84,    88,    89,    89,    90,    91,    91,    92,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,   100,    99,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     1,     1,     3,     5,
       6,     1,     1,     0,     0,     8,     1,     0,     2,     4,
       1,     0,     1,     0,     4,     0,     8,     2,     0,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     5,     0,     0,     9,     0,     0,     0,    12,
       0,     0,    12,     0,     0,     7,     0,     7,     0,     0,
       0,    13,     2,     2,     1,     3,     1,     0,     1,     3,
       6,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     2,     1,     3,     1,     4,     0,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 1319 "asin.c"
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
#line 1334 "asin.c"
    break;

  case 4: /* listDecla: decla  */
#line 88 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1340 "asin.c"
    break;

  case 5: /* listDecla: listDecla decla  */
#line 90 "src/asin.y"
    { (yyval.cent) = (yyvsp[-1].cent) + (yyvsp[0].cent); }
#line 1346 "asin.c"
    break;

  case 6: /* decla: declaVar  */
#line 95 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1352 "asin.c"
    break;

  case 7: /* decla: declaFunc  */
#line 97 "src/asin.y"
    { (yyval.cent) = (yyvsp[0].cent); }
#line 1358 "asin.c"
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
#line 1370 "asin.c"
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
#line 1387 "asin.c"
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
#line 1402 "asin.c"
    break;

  case 11: /* tipoSimp: INT_  */
#line 137 "src/asin.y"
    { (yyval.cent) = T_ENTERO; }
#line 1408 "asin.c"
    break;

  case 12: /* tipoSimp: BOOL_  */
#line 139 "src/asin.y"
    { (yyval.cent) = T_LOGICO; }
#line 1414 "asin.c"
    break;

  case 13: /* @2: %empty  */
#line 143 "src/asin.y"
                         {(yyval.cent) = dvar; dvar = 0; niv=1; cargaContexto(niv); }
#line 1420 "asin.c"
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
#line 1435 "asin.c"
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
#line 1448 "asin.c"
    break;

  case 16: /* paramForm: listParamForm  */
#line 167 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1457 "asin.c"
    break;

  case 17: /* paramForm: %empty  */
#line 172 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1466 "asin.c"
    break;

  case 18: /* listParamForm: tipoSimp ID_  */
#line 180 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[-1].cent));
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
        if(!insTdS((yyvsp[0].ident), PARAMETRO, (yyvsp[-1].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador.");
    }
#line 1476 "asin.c"
    break;

  case 19: /* listParamForm: tipoSimp ID_ COMMA_ listParamForm  */
#line 186 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-3].cent));
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
        if(!insTdS((yyvsp[-2].ident), PARAMETRO, (yyvsp[-3].cent), niv, -(yyval.list).talla, -1)) yyerror("Ya existe un parametro con el mismo identificador."); 
    }
#line 1486 "asin.c"
    break;

  case 20: /* paramAct: listParamAct  */
#line 195 "src/asin.y"
    {
        (yyval.list).ref = (yyvsp[0].list).ref;
        (yyval.list).talla = (yyvsp[0].list).talla;
    }
#line 1495 "asin.c"
    break;

  case 21: /* paramAct: %empty  */
#line 200 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, T_VACIO);
        (yyval.list).talla = 0;   
    }
#line 1504 "asin.c"
    break;

  case 22: /* listParamAct: expre  */
#line 209 "src/asin.y"
    {
        (yyval.list).ref = insTdD(-1, (yyvsp[0].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + TALLA_DOBLE;
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[0].texp).pos));
    }
#line 1514 "asin.c"
    break;

  case 23: /* $@4: %empty  */
#line 216 "src/asin.y"
    { 
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-1].texp).pos)); 
    }
#line 1522 "asin.c"
    break;

  case 24: /* listParamAct: expre COMMA_ $@4 listParamAct  */
#line 220 "src/asin.y"
    {
        (yyval.list).ref = insTdD((yyvsp[0].list).ref, (yyvsp[-3].texp).t);
        (yyval.list).talla = TALLA_SIMPLE + (yyvsp[0].list).talla;
    }
#line 1531 "asin.c"
    break;

  case 25: /* @5: %empty  */
#line 228 "src/asin.y"
    {
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        (yyval.cent) = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));   
    }
#line 1542 "asin.c"
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
#line 1563 "asin.c"
    break;

  case 41: /* instEntSal: READ_ PARA_ ID_ PARC_ SCOL_  */
#line 281 "src/asin.y"
    {			
        SIMB simb = obtTdS((yyvsp[-2].ident));
        if(simb.t != T_ENTERO)
            yyerror("El argumento del 'read' debe ser entero.");
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(simb.n, simb.d));
    }
#line 1574 "asin.c"
    break;

  case 42: /* instEntSal: PRINT_ PARA_ expre PARC_ SCOL_  */
#line 288 "src/asin.y"
    {
        if((yyvsp[-2].texp).t != T_ENTERO)
            yyerror("El argumento del 'print' debe ser entero.");
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, (yyvsp[-2].texp).pos));
    }
#line 1584 "asin.c"
    break;

  case 43: /* @6: %empty  */
#line 297 "src/asin.y"
    {
        if((yyvsp[-1].texp).t != T_LOGICO && (yyvsp[-1].texp).t != T_ERROR)
            yyerror("La expresión del 'if' debe ser de tipo 'lógico'.");
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        (yyval.aux).ref1 = creaLans(si);          
        // Las etiquetas (los saltos) están todavía por inicializarse. Apuntan a la referencia 
        // de la inst previa (apuntan a creaLans, linea 267)
        // Se saltará a la etiqueta cuando la condición de la expresión sea verdadera.
        // Es decir, si 0 es igual al contenido del argumento $6, o si la condición es FALSA.
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].texp).pos), crArgEnt(0), crArgEtq(-1));
    }
#line 1600 "asin.c"
    break;

  case 44: /* @7: %empty  */
#line 309 "src/asin.y"
    {
        (yyval.aux).ref2 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans((yyvsp[-1].aux).ref1, crArgEtq(si));
    }
#line 1610 "asin.c"
    break;

  case 45: /* instSelec: IF_ PARA_ expre PARC_ @6 inst @7 ELSE_ inst  */
#line 315 "src/asin.y"
    {
        completaLans((yyvsp[-2].aux).ref2, crArgEtq(si));
    }
#line 1618 "asin.c"
    break;

  case 46: /* @8: %empty  */
#line 322 "src/asin.y"
    {
       (yyval.aux).ref0 = si; 
    }
#line 1626 "asin.c"
    break;

  case 47: /* @9: %empty  */
#line 326 "src/asin.y"
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
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].texp).pos), crArgEnt(1), crArgEtq(-1));
        // Se inicializa una lista de etiquetas pendientes a completar posteriormente
        (yyval.aux).ref2 = creaLans(si);                              
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        (yyval.aux).ref3 = si;    
    }
#line 1647 "asin.c"
    break;

  case 48: /* $@10: %empty  */
#line 343 "src/asin.y"
    {
        if ((yyvsp[-4].texp).t == T_ARRAY) {}
        else if((yyvsp[-4].texp).t != T_LOGICO && (yyvsp[-4].texp).t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-5].aux).ref0)); 
        completaLans((yyvsp[-2].aux).ref1, crArgEtq(si));
    }
#line 1658 "asin.c"
    break;

  case 49: /* instIter: FOR_ PARA_ expreOP SCOL_ @8 expre SCOL_ @9 expreOP PARC_ $@10 inst  */
#line 350 "src/asin.y"
    {
        if ((yyvsp[-6].texp).t == T_ARRAY) {}
        else if((yyvsp[-6].texp).t != T_LOGICO && (yyvsp[-6].texp).t != T_ERROR) {}
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-4].aux).ref3)); 
        completaLans((yyvsp[-4].aux).ref2, crArgEtq(si));
    }
#line 1669 "asin.c"
    break;

  case 50: /* $@11: %empty  */
#line 357 "src/asin.y"
    {
        if(!insTdS((yyvsp[-4].ident), VARIABLE, T_ENTERO, niv, dvar, -1)) 
            yyerror("Variable ya declarada con mismo identificador.");
        else
            dvar += TALLA_SIMPLE;

        SIMB simb = obtTdS((yyvsp[-4].ident));

        if((yyvsp[0].texp).t != T_ENTERO)
            yyerror("La expresión del rango debe ser entera.");

        emite(EASIG, crArgPos(niv, (yyvsp[0].texp).pos), crArgNul(), crArgPos(simb.n, simb.d));
    }
#line 1687 "asin.c"
    break;

  case 51: /* @12: %empty  */
#line 371 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-7].ident));

        if((yyvsp[0].texp).t != T_ENTERO)
            yyerror("La expresión del rango debe ser entera."); 

        (yyval.aux).ref1 = si;

        (yyval.aux).ref2 = creaLans(si);
        emite(EMAYEQ, crArgPos(simb.n, simb.d), crArgPos(niv, (yyvsp[0].texp).pos), crArgEtq(-1));
    }
#line 1703 "asin.c"
    break;

  case 52: /* instIter: FOR_ ID_ IN_ RANGE_ PARA_ expre $@11 COMMA_ expre @12 PARC_ inst  */
#line 383 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-10].ident));
        emite(ESUM, crArgPos(simb.n, simb.d), crArgEnt(1), crArgPos(simb.n, simb.d));
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-2].aux).ref1)); 
        completaLans((yyvsp[-2].aux).ref2, crArgEtq(si));
    }
#line 1714 "asin.c"
    break;

  case 53: /* @13: %empty  */
#line 390 "src/asin.y"
    {
        (yyval.aux).ref2 = si;
    }
#line 1722 "asin.c"
    break;

  case 54: /* @14: %empty  */
#line 394 "src/asin.y"
    {
        (yyval.aux).ref1 = creaLans(si);
        emite(EIGUAL, crArgPos(niv, (yyvsp[-1].texp).pos), crArgEnt(0), crArgEtq(-1));
    }
#line 1731 "asin.c"
    break;

  case 55: /* instIter: WHILE_ PARA_ @13 expre PARC_ @14 inst  */
#line 399 "src/asin.y"
    {
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-4].aux).ref2));
        completaLans((yyvsp[-1].aux).ref1, crArgEtq(si));
    }
#line 1740 "asin.c"
    break;

  case 56: /* @15: %empty  */
#line 407 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-1].ident));

        if(simb.t != T_ERROR) 
        {
            if((yyvsp[0].texp).t != T_ENTERO)
                yyerror("El tipo de la expresión no es entero.");
            if(simb.t != T_ENTERO)
                yyerror("El tipo de la variable no es entero.");
        }
        else
            yyerror("Variable no declarada.");

        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(simb.n, simb.d));
        (yyval.aux).ref0 = si;
    }
#line 1761 "asin.c"
    break;

  case 57: /* instruccionUsingTimes: USING_ ID_ expre @15 TIMES_ DO_ inst  */
#line 424 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-5].ident));

        int ref = creaLans(si);
        emite(EMAYEQ,  crArgPos(simb.n, simb.d), crArgPos(niv, (yyvsp[-4].texp).pos), crArgEtq(-1));
        emite(ESUM, crArgPos(simb.n, simb.d), crArgEnt(1), crArgPos(simb.n, simb.d));
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq((yyvsp[-3].aux).ref0));
        completaLans(ref, crArgEtq(si));
    }
#line 1775 "asin.c"
    break;

  case 58: /* @16: %empty  */
#line 437 "src/asin.y"
    {
        SIMB simb = obtTdS((yyvsp[-2].ident));
        if (simb.t != T_ENTERO)
            yyerror("El id del 'switch' debe ser entero");
        int ref0 = creaLans(si);
        emite(EMENEQ,  crArgPos(simb.n, simb.d), crArgEnt(0), crArgEtq(-1));
        (yyval.aux).ref1 = creaLans(si);
        emite(EIGUAL,  crArgPos(simb.n, simb.d), crArgEnt(0), crArgEtq(-1));
        (yyval.aux).ref2 = creaLans(si);
        emite(EMAYEQ,  crArgPos(simb.n, simb.d), crArgEnt(0), crArgEtq(-1));

        completaLans(ref0, crArgEtq(si));
    }
#line 1793 "asin.c"
    break;

  case 59: /* @17: %empty  */
#line 451 "src/asin.y"
    {
        (yyval.aux).ref3 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans((yyvsp[-2].aux).ref1, crArgEtq(si));
    }
#line 1803 "asin.c"
    break;

  case 60: /* @18: %empty  */
#line 457 "src/asin.y"
    {
        (yyval.aux).ref4 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        completaLans((yyvsp[-5].aux).ref2, crArgEtq(si));
    }
#line 1813 "asin.c"
    break;

  case 61: /* instSwitch: SWITCH_ ID_ LLAA_ LESS_ @16 inst EQUAL_ @17 inst GREATER_ @18 inst LLAC_  */
#line 463 "src/asin.y"
    {
        completaLans((yyvsp[-5].aux).ref3, crArgEtq(si));   
        completaLans((yyvsp[-2].aux).ref4, crArgEtq(si));   
    }
#line 1822 "asin.c"
    break;

  case 66: /* expreOP: expre  */
#line 481 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1828 "asin.c"
    break;

  case 67: /* expreOP: %empty  */
#line 483 "src/asin.y"
    { (yyval.texp).t = T_VACIO; }
#line 1834 "asin.c"
    break;

  case 68: /* expre: expreLogic  */
#line 488 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1840 "asin.c"
    break;

  case 69: /* expre: ID_ ASIG_ expre  */
#line 490 "src/asin.y"
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
#line 1865 "asin.c"
    break;

  case 70: /* expre: ID_ CORA_ expre CORC_ ASIG_ expre  */
#line 511 "src/asin.y"
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
#line 1892 "asin.c"
    break;

  case 71: /* expreLogic: expreIgual  */
#line 537 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1898 "asin.c"
    break;

  case 72: /* expreLogic: expreLogic opLogic expreIgual  */
#line 539 "src/asin.y"
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
#line 1926 "asin.c"
    break;

  case 73: /* expreIgual: expreRel  */
#line 566 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1932 "asin.c"
    break;

  case 74: /* expreIgual: expreIgual opIgual expreRel  */
#line 568 "src/asin.y"
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
#line 1955 "asin.c"
    break;

  case 75: /* expreRel: expreAd  */
#line 591 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1961 "asin.c"
    break;

  case 76: /* expreRel: expreRel opRel expreAd  */
#line 593 "src/asin.y"
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
#line 1982 "asin.c"
    break;

  case 77: /* expreAd: expreMul  */
#line 613 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 1988 "asin.c"
    break;

  case 78: /* expreAd: expreAd opAd expreMul  */
#line 615 "src/asin.y"
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
#line 2004 "asin.c"
    break;

  case 79: /* expreMul: expreUna  */
#line 630 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 2010 "asin.c"
    break;

  case 80: /* expreMul: expreMul opMul expreUna  */
#line 632 "src/asin.y"
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
#line 2026 "asin.c"
    break;

  case 81: /* expreUna: expreSufi  */
#line 647 "src/asin.y"
    { (yyval.texp).t = (yyvsp[0].texp).t; (yyval.texp).pos = (yyvsp[0].texp).pos; }
#line 2032 "asin.c"
    break;

  case 82: /* expreUna: opUna expreUna  */
#line 649 "src/asin.y"
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
#line 2062 "asin.c"
    break;

  case 83: /* expreSufi: const  */
#line 678 "src/asin.y"
    {   
        (yyval.texp).t = (yyvsp[0].texp).t; 
        (yyval.texp).pos = creaVarTemp();
        emite(EASIG, crArgEnt((yyvsp[0].texp).pos), crArgNul(), crArgPos(niv, (yyval.texp).pos));         
    }
#line 2072 "asin.c"
    break;

  case 84: /* expreSufi: PARA_ expre PARC_  */
#line 684 "src/asin.y"
    { (yyval.texp).t = (yyvsp[-1].texp).t; (yyval.texp).pos = (yyvsp[-1].texp).pos; }
#line 2078 "asin.c"
    break;

  case 85: /* expreSufi: ID_  */
#line 686 "src/asin.y"
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
#line 2095 "asin.c"
    break;

  case 86: /* expreSufi: ID_ CORA_ expre CORC_  */
#line 699 "src/asin.y"
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
#line 2117 "asin.c"
    break;

  case 87: /* $@19: %empty  */
#line 718 "src/asin.y"
    {   
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(TALLA_SIMPLE)); 
    }
#line 2125 "asin.c"
    break;

  case 88: /* expreSufi: ID_ PARA_ $@19 paramAct PARC_  */
#line 722 "src/asin.y"
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
#line 2151 "asin.c"
    break;

  case 89: /* const: CTE_  */
#line 746 "src/asin.y"
              { (yyval.texp).t = T_ENTERO; (yyval.texp).pos = (yyvsp[0].cent); }
#line 2157 "asin.c"
    break;

  case 90: /* const: TRUE_  */
#line 747 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; (yyval.texp).pos = 1; }
#line 2163 "asin.c"
    break;

  case 91: /* const: FALSE_  */
#line 748 "src/asin.y"
              { (yyval.texp).t = T_LOGICO; (yyval.texp).pos = 0; }
#line 2169 "asin.c"
    break;

  case 92: /* opLogic: AND_  */
#line 752 "src/asin.y"
              { (yyval.cent) = EMULT; }
#line 2175 "asin.c"
    break;

  case 93: /* opLogic: OR_  */
#line 753 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 2181 "asin.c"
    break;

  case 94: /* opIgual: EQ_  */
#line 757 "src/asin.y"
              { (yyval.cent) = EIGUAL; }
#line 2187 "asin.c"
    break;

  case 95: /* opIgual: NEQ_  */
#line 758 "src/asin.y"
              { (yyval.cent) = EDIST; }
#line 2193 "asin.c"
    break;

  case 96: /* opRel: GE_  */
#line 762 "src/asin.y"
              { (yyval.cent) = EMAY; }
#line 2199 "asin.c"
    break;

  case 97: /* opRel: LE_  */
#line 763 "src/asin.y"
              { (yyval.cent) = EMEN; }
#line 2205 "asin.c"
    break;

  case 98: /* opRel: GEQ_  */
#line 764 "src/asin.y"
              { (yyval.cent) = EMAYEQ; }
#line 2211 "asin.c"
    break;

  case 99: /* opRel: LEQ_  */
#line 765 "src/asin.y"
              { (yyval.cent) = EMENEQ; }
#line 2217 "asin.c"
    break;

  case 100: /* opAd: MAS_  */
#line 769 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 2223 "asin.c"
    break;

  case 101: /* opAd: MENOS_  */
#line 770 "src/asin.y"
              { (yyval.cent) = EDIF; }
#line 2229 "asin.c"
    break;

  case 102: /* opMul: POR_  */
#line 774 "src/asin.y"
              { (yyval.cent) = EMULT; }
#line 2235 "asin.c"
    break;

  case 103: /* opMul: DIV_  */
#line 775 "src/asin.y"
              { (yyval.cent) = EDIVI; }
#line 2241 "asin.c"
    break;

  case 104: /* opUna: MAS_  */
#line 779 "src/asin.y"
              { (yyval.cent) = ESUM; }
#line 2247 "asin.c"
    break;

  case 105: /* opUna: MENOS_  */
#line 780 "src/asin.y"
              { (yyval.cent) = EDIF; }
#line 2253 "asin.c"
    break;

  case 106: /* opUna: NOT_  */
#line 781 "src/asin.y"
              { (yyval.cent) = ESIG; }
#line 2259 "asin.c"
    break;


#line 2263 "asin.c"

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

