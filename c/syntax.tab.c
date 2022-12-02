/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y" /* yacc.c:337  */

    #include"lex.yy.c"
    #include "tree.h"
    #include <string.h>
    #include <stdlib.h>
    #include <stdio.h>
    // int yydebug=1;
    void yyerror(const char*);
    node* root;

#line 81 "syntax.tab.c" /* yacc.c:337  */
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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    tCHAR = 258,
    tINT = 259,
    tFLOAT = 260,
    tID = 261,
    tTYPE = 262,
    tSTRUCT = 263,
    tWHILE = 264,
    tRETURN = 265,
    tIF = 266,
    tELSE = 267,
    tFOR = 268,
    tLC = 269,
    tRC = 270,
    tLB = 271,
    tRB = 272,
    tLP = 273,
    tRP = 274,
    tDOT = 275,
    tSEMI = 276,
    tCOMMA = 277,
    tASSIGN = 278,
    tPLUS = 279,
    tMINUS = 280,
    tMUL = 281,
    tDIV = 282,
    tD_PLUS = 283,
    tD_MINUS = 284,
    tPLUS_EQ = 285,
    tMINUS_EQ = 286,
    tMUL_EQ = 287,
    tDIV_EQ = 288,
    tAND = 289,
    tOR = 290,
    tNOT = 291,
    tNE = 292,
    tEQ = 293,
    tLT = 294,
    tLE = 295,
    tGT = 296,
    tGE = 297,
    INVALID_TOKEN = 298,
    tLOWERELSE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "syntax.y" /* yacc.c:352  */

    node* type_node;

#line 173 "syntax.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   914

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

#define YYUNDEFTOK  2
#define YYMAXUTOK   299

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    63,    71,    80,    88,    96,    99,   107,
     113,   121,   132,   140,   151,   159,   167,   174,   182,   191,
     194,   200,   208,   216,   222,   230,   241,   249,   255,   263,
     269,   277,   288,   296,   304,   312,   316,   324,   332,   335,
     343,   346,   354,   362,   373,   381,   392,   400,   403,   409,
     417,   428,   436,   448,   456,   460,   468,   476,   484,   488,
     496,   500,   508,   512,   520,   525,   533,   537,   545,   549,
     557,   561,   569,   573,   581,   585,   593,   597,   605,   609,
     617,   621,   629,   633,   641,   645,   653,   657,   665,   670,
     678,   681,   689,   697,   705,   713,   716,   719,   727,   730,
     738,   746,   754,   762,   770,   771,   772,   773,   777,   785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tCHAR", "tINT", "tFLOAT", "tID",
  "tTYPE", "tSTRUCT", "tWHILE", "tRETURN", "tIF", "tELSE", "tFOR", "tLC",
  "tRC", "tLB", "tRB", "tLP", "tRP", "tDOT", "tSEMI", "tCOMMA", "tASSIGN",
  "tPLUS", "tMINUS", "tMUL", "tDIV", "tD_PLUS", "tD_MINUS", "tPLUS_EQ",
  "tMINUS_EQ", "tMUL_EQ", "tDIV_EQ", "tAND", "tOR", "tNOT", "tNE", "tEQ",
  "tLT", "tLE", "tGT", "tGE", "INVALID_TOKEN", "tLOWERELSE", "$accept",
  "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "FunDec", "VarDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -156

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-156)))

#define YYTABLE_NINF -5

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     157,    13,  -156,    68,    79,  -156,   157,   102,  -156,    93,
     106,   108,   115,  -156,  -156,  -156,    93,  -156,   113,   106,
      48,   267,    64,  -156,    64,    64,  -156,  -156,   110,   150,
    -156,  -156,   104,     1,   137,   111,   573,    64,   145,   146,
       7,  -156,  -156,  -156,   152,  -156,  -156,    64,   141,    -9,
       0,   169,  -156,  -156,  -156,   151,   174,   590,   175,   176,
     590,   590,   590,    24,  -156,   100,   573,   611,  -156,  -156,
    -156,  -156,  -156,  -156,  -156,   590,  -156,  -156,   150,   260,
     590,    57,   590,    55,   112,   853,    -7,  -156,  -156,  -156,
    -156,   590,   189,  -156,   266,   289,   312,   318,   341,  -156,
    -156,   364,   370,   393,   416,   422,   445,   468,   474,   497,
     520,   526,   549,    24,   751,  -156,  -156,  -156,   639,    14,
     147,  -156,  -156,   182,   590,   150,   178,  -156,  -156,   217,
    -156,  -156,   751,  -156,   853,  -156,   853,  -156,   871,  -156,
     871,  -156,    -7,  -156,    -7,  -156,    -7,  -156,    -7,  -156,
     807,  -156,   779,  -156,   835,  -156,   835,  -156,   835,  -156,
     835,  -156,   835,  -156,   835,  -156,   590,  -156,  -156,  -156,
     573,  -156,   573,   667,   179,   590,  -156,  -156,  -156,  -156,
     184,   590,   590,   695,   573,   185,   723,   590,  -156,   573,
     590,   207,  -156,   208,   573,   573,  -156,  -156
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,     0,     0,     2,     0,     0,    13,     0,
       0,     0,    15,     1,     3,     7,    22,     6,     0,     0,
      10,     0,    45,     9,    45,    45,     5,     8,     0,     0,
      20,    17,     0,     0,    25,     0,    31,    45,     0,     0,
       0,    22,    11,    27,    26,    19,    18,     0,     0,    51,
       0,    49,   103,   101,   102,   100,     0,     0,     0,     0,
       0,     0,     0,   104,    33,     0,    31,     0,    44,    16,
      14,    23,    21,    24,    47,     0,    48,    46,     0,     0,
       0,     0,     0,     0,     0,    91,    92,   106,    29,    28,
      30,     0,     0,    32,     0,     0,     0,     0,     0,    55,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,    52,    50,    96,    94,   109,     0,
       0,    35,    34,     0,     0,     0,     0,    90,    89,     0,
      99,    54,    53,    82,    81,    84,    83,    86,    85,    88,
      87,    58,    57,    60,    59,    62,    61,    64,    63,    66,
      65,    68,    67,    78,    77,    80,    79,    70,    69,    72,
      71,    74,    73,    76,    75,   107,     0,    95,    93,    40,
       0,    38,     0,     0,     0,     0,    98,    97,   108,    39,
      36,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,    41,     0,     0,     0,    42,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,   191,  -156,   199,    10,  -156,   196,    36,   183,
    -156,    56,   163,   -68,    82,  -156,   -66,  -156,   -57,  -155
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,    18,    35,     8,    10,    49,    33,
      34,    64,    65,    66,    36,    37,    50,    51,    67,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    76,    45,    84,    85,    86,    87,    28,    71,    91,
       7,   178,   115,    92,    75,   167,     7,   126,   114,     9,
      46,    77,   118,   120,    72,   123,   185,    52,    53,    54,
      55,    32,   191,   168,   129,   193,   113,   132,   134,   136,
     138,   140,    60,    20,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   165,    32,   121,   174,
      62,    41,     2,     3,    28,    20,    23,   173,    44,    11,
      29,     2,     3,    91,    12,    27,   124,    92,   122,    13,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   125,   107,   108,   109,   110,   111,   112,
     113,    88,   179,    15,   180,    43,    38,    39,    16,   118,
      41,    21,    48,   127,    40,    89,   188,    41,   183,    68,
      22,   192,    24,    17,   118,   186,   196,   197,    91,    25,
     118,   128,    92,   118,    26,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   169,   107,
     108,   109,   110,   111,   112,   113,    41,    -4,     1,    47,
      69,    70,    74,    91,     2,     3,   170,    92,    28,    79,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   171,   107,   108,   109,   110,   111,   112,
     113,    78,    80,    82,    83,   130,   184,    14,    91,   175,
     182,   172,    92,    19,   189,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   176,   107,
     108,   109,   110,   111,   112,   113,   194,   195,    42,    90,
      73,     0,     0,    91,   177,     0,     0,    92,     0,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,   116,     0,    52,    53,    54,    55,   131,    30,    52,
      53,    54,    55,     0,     2,     3,     0,     0,    60,   117,
       0,     0,     0,     0,    60,    61,    31,     0,     0,     0,
     133,    61,    52,    53,    54,    55,    62,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,    60,     0,    63,
       0,     0,     0,   135,    61,    52,    53,    54,    55,   137,
       0,    52,    53,    54,    55,    62,     0,     0,     0,     0,
      60,     0,    63,     0,     0,     0,    60,    61,     0,     0,
       0,     0,   139,    61,    52,    53,    54,    55,    62,     0,
       0,     0,     0,     0,    62,    63,     0,     0,     0,    60,
       0,    63,     0,     0,     0,   141,    61,    52,    53,    54,
      55,   143,     0,    52,    53,    54,    55,    62,     0,     0,
       0,     0,    60,     0,    63,     0,     0,     0,    60,    61,
       0,     0,     0,     0,   145,    61,    52,    53,    54,    55,
      62,     0,     0,     0,     0,     0,    62,    63,     0,     0,
       0,    60,     0,    63,     0,     0,     0,   147,    61,    52,
      53,    54,    55,   149,     0,    52,    53,    54,    55,    62,
       0,     0,     0,     0,    60,     0,    63,     0,     0,     0,
      60,    61,     0,     0,     0,     0,   151,    61,    52,    53,
      54,    55,    62,     0,     0,     0,     0,     0,    62,    63,
       0,     0,     0,    60,     0,    63,     0,     0,     0,   153,
      61,    52,    53,    54,    55,   155,     0,    52,    53,    54,
      55,    62,     0,     0,     0,     0,    60,     0,    63,     0,
       0,     0,    60,    61,     0,     0,     0,     0,   157,    61,
      52,    53,    54,    55,    62,     0,     0,     0,     0,     0,
      62,    63,     0,     0,     0,    60,     0,    63,     0,     0,
       0,   159,    61,    52,    53,    54,    55,   161,     0,    52,
      53,    54,    55,    62,     0,     0,     0,     0,    60,     0,
      63,     0,     0,     0,    60,    61,     0,     0,     0,     0,
     163,    61,    52,    53,    54,    55,    62,     0,     0,     0,
       0,     0,    62,    63,     0,     0,     0,    60,     0,    63,
       0,     0,     0,     0,    61,     0,    52,    53,    54,    55,
       0,     0,    56,    57,    58,    62,    59,    22,     0,     0,
       0,    60,    63,    52,    53,    54,    55,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    62,
       0,     0,     0,     0,     0,    61,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,    91,     0,     0,
       0,    92,    93,    63,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
     109,   110,   111,   112,   113,    91,     0,     0,     0,    92,
       0,   166,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,     0,   107,   108,   109,   110,
     111,   112,   113,    91,     0,     0,     0,    92,   181,     0,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,     0,   107,   108,   109,   110,   111,   112,
     113,    91,     0,     0,     0,    92,   187,     0,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,   112,   113,    91,
       0,     0,     0,    92,   190,     0,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,     0,
     107,   108,   109,   110,   111,   112,   113,    91,     0,     0,
       0,    92,     0,     0,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,     0,   107,   108,
     109,   110,   111,   112,   113,    91,     0,     0,     0,    92,
       0,     0,     0,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,   107,   108,   109,   110,
     111,   112,   113,    91,     0,     0,     0,    92,     0,     0,
       0,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,    91,     0,     0,     0,    92,     0,     0,     0,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    91,
       0,     0,     0,    92,     0,     0,     0,     0,   113,    97,
      98,    99,   100,   101,   102,   103,   104,    91,     0,     0,
       0,    92,     0,     0,     0,     0,   113,     0,     0,    99,
     100,   101,   102,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
      57,     1,     1,    60,    61,    62,    63,    16,     1,    16,
       0,   166,    78,    20,    23,     1,     6,    83,    75,     6,
      19,    21,    79,    80,    17,    82,   181,     3,     4,     5,
       6,    21,   187,    19,    91,   190,    43,    94,    95,    96,
      97,    98,    18,     7,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,    47,     1,   125,
      36,     6,     7,     8,    16,    29,    10,   124,    32,     1,
      22,     7,     8,    16,     6,    19,    21,    20,    21,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    83,    37,    38,    39,    40,    41,    42,
      43,     1,   170,     1,   172,     1,    24,    25,     6,   166,
       6,    18,     1,     1,     4,    15,   184,     6,   175,    37,
      14,   189,    14,    21,   181,   182,   194,   195,    16,    14,
     187,    19,    20,   190,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     1,    37,
      38,    39,    40,    41,    42,    43,     6,     0,     1,    22,
      15,    15,    21,    16,     7,     8,    19,    20,    16,    18,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     1,    37,    38,    39,    40,    41,    42,
      43,    22,    18,    18,    18,     6,    12,     6,    16,    21,
      21,    19,    20,     7,    19,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,     1,    37,
      38,    39,    40,    41,    42,    43,    19,    19,    29,    66,
      47,    -1,    -1,    16,    17,    -1,    -1,    20,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,     1,    -1,     3,     4,     5,     6,     1,     1,     3,
       4,     5,     6,    -1,     7,     8,    -1,    -1,    18,    19,
      -1,    -1,    -1,    -1,    18,    25,    19,    -1,    -1,    -1,
       1,    25,     3,     4,     5,     6,    36,    -1,    -1,    -1,
      -1,    -1,    36,    43,    -1,    -1,    -1,    18,    -1,    43,
      -1,    -1,    -1,     1,    25,     3,     4,     5,     6,     1,
      -1,     3,     4,     5,     6,    36,    -1,    -1,    -1,    -1,
      18,    -1,    43,    -1,    -1,    -1,    18,    25,    -1,    -1,
      -1,    -1,     1,    25,     3,     4,     5,     6,    36,    -1,
      -1,    -1,    -1,    -1,    36,    43,    -1,    -1,    -1,    18,
      -1,    43,    -1,    -1,    -1,     1,    25,     3,     4,     5,
       6,     1,    -1,     3,     4,     5,     6,    36,    -1,    -1,
      -1,    -1,    18,    -1,    43,    -1,    -1,    -1,    18,    25,
      -1,    -1,    -1,    -1,     1,    25,     3,     4,     5,     6,
      36,    -1,    -1,    -1,    -1,    -1,    36,    43,    -1,    -1,
      -1,    18,    -1,    43,    -1,    -1,    -1,     1,    25,     3,
       4,     5,     6,     1,    -1,     3,     4,     5,     6,    36,
      -1,    -1,    -1,    -1,    18,    -1,    43,    -1,    -1,    -1,
      18,    25,    -1,    -1,    -1,    -1,     1,    25,     3,     4,
       5,     6,    36,    -1,    -1,    -1,    -1,    -1,    36,    43,
      -1,    -1,    -1,    18,    -1,    43,    -1,    -1,    -1,     1,
      25,     3,     4,     5,     6,     1,    -1,     3,     4,     5,
       6,    36,    -1,    -1,    -1,    -1,    18,    -1,    43,    -1,
      -1,    -1,    18,    25,    -1,    -1,    -1,    -1,     1,    25,
       3,     4,     5,     6,    36,    -1,    -1,    -1,    -1,    -1,
      36,    43,    -1,    -1,    -1,    18,    -1,    43,    -1,    -1,
      -1,     1,    25,     3,     4,     5,     6,     1,    -1,     3,
       4,     5,     6,    36,    -1,    -1,    -1,    -1,    18,    -1,
      43,    -1,    -1,    -1,    18,    25,    -1,    -1,    -1,    -1,
       1,    25,     3,     4,     5,     6,    36,    -1,    -1,    -1,
      -1,    -1,    36,    43,    -1,    -1,    -1,    18,    -1,    43,
      -1,    -1,    -1,    -1,    25,    -1,     3,     4,     5,     6,
      -1,    -1,     9,    10,    11,    36,    13,    14,    -1,    -1,
      -1,    18,    43,     3,     4,     5,     6,    -1,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    36,
      -1,    -1,    -1,    -1,    -1,    25,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    16,    -1,    -1,
      -1,    20,    21,    43,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    16,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    40,
      41,    42,    43,    16,    -1,    -1,    -1,    20,    21,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    16,    -1,    -1,    -1,    20,    21,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    16,
      -1,    -1,    -1,    20,    21,    -1,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    16,    -1,    -1,
      -1,    20,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    16,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    16,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    16,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    16,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    43,    26,
      27,    28,    29,    30,    31,    32,    33,    16,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    43,    -1,    -1,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    46,    47,    48,    50,    51,     6,
      52,     1,     6,     0,    47,     1,     6,    21,    49,    52,
      53,    18,    14,    56,    14,    14,    21,    56,    16,    22,
       1,    19,    50,    54,    55,    50,    59,    60,    59,    59,
       4,     6,    49,     1,    53,     1,    19,    22,     1,    53,
      61,    62,     3,     4,     5,     6,     9,    10,    11,    13,
      18,    25,    36,    43,    56,    57,    58,    63,    59,    15,
      15,     1,    17,    54,    21,    23,     1,    21,    22,    18,
      18,    63,    18,    18,    63,    63,    63,    63,     1,    15,
      57,    16,    20,    21,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    37,    38,    39,
      40,    41,    42,    43,    63,    61,     1,    19,    63,    64,
      63,     1,    21,    63,    21,    50,    61,     1,    19,    63,
       6,     1,    63,     1,    63,     1,    63,     1,    63,     1,
      63,     1,    63,     1,    63,     1,    63,     1,    63,     1,
      63,     1,    63,     1,    63,     1,    63,     1,    63,     1,
      63,     1,    63,     1,    63,    63,    22,     1,    19,     1,
      19,     1,    19,    63,    61,    21,     1,    17,    64,    58,
      58,    21,    21,    63,    12,    64,    63,    21,    58,    19,
      21,    64,    58,    64,    19,    19,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    48,
      49,    49,    50,    50,    51,    51,    51,    52,    52,    52,
      52,    53,    53,    53,    54,    54,    55,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     2,     3,     3,
       1,     3,     1,     1,     5,     2,     5,     3,     4,     4,
       3,     4,     1,     4,     3,     1,     2,     2,     4,     4,
       2,     0,     2,     1,     3,     3,     5,     7,     4,     5,
       4,     8,     9,    10,     2,     0,     3,     3,     3,     1,
       3,     1,     3,     3,     3,     2,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     4,     3,     4,     3,     4,     4,     3,
       1,     1,     1,     1,     1,     2,     2,     3,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 51 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Program";
        add_child_node((yyval.type_node),1,(yyvsp[0].type_node));
        root=(yyval.type_node);
    }
#line 1657 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 63 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDefList";
        add_child_node((yyval.type_node),2,(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 1670 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 71 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->empty=TRUE;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDefList";
    }
#line 1682 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 80 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDef";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1695 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 88 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDef";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1708 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 96 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing A Semicolon ';'.\n");
    }
#line 1716 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 99 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDef";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1729 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 107 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing specifier.\n");
    }
#line 1737 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 113 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDecList";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 1750 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 121 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ExtDecList";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1763 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 132 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->val="Specifier";
        (yyval.type_node)->lval_or_rval=1;
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 1776 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 140 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->val="Specifier";
        (yyval.type_node)->lval_or_rval=1;
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 1789 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 151 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="StructSpecifier";
        add_child_node((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1802 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 159 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="StructSpecifier";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1815 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 167 "syntax.y" /* yacc.c:1652  */
    {
        printf("StructSpecifier has A Wrong ID or No ID\n");
    }
#line 1823 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 174 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="FunDec";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1836 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 182 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="FunDec";
        add_child_node((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1849 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 191 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis: ')'\n");
    }
#line 1857 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 194 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis: ')'\n");
    }
#line 1865 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 200 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="VarDec";
        add_child_node((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1878 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 208 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="VarDec";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 1891 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 216 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing bracket: ']'\n");
    }
#line 1899 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 222 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="VarList";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1912 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 230 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="VarList";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 1925 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 241 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="ParamDec";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 1938 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 27:
#line 249 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing an ID\n");
    }
#line 1946 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 28:
#line 255 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="CompSt";
        add_child_node((yyval.type_node), 4, (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 1959 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 263 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing RC '}'\n");
    }
#line 1967 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 269 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="StmtList";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 1980 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 277 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->empty=TRUE;
        (yyval.type_node)->line = (yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="StmtList";
    }
#line 1993 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 288 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 2006 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 296 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 2019 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 304 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2032 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 312 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing A Semicolon ';'.\n");
    }
#line 2040 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 36:
#line 316 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 2053 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 37:
#line 324 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 7, (yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2066 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 38:
#line 332 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis ')'\n");
    }
#line 2074 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 39:
#line 335 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 5, (yyvsp[-4].type_node), (yyvsp[-3].type_node), (yyvsp[-2].type_node), (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 2087 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 343 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis ')'\n");
    }
#line 2095 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 346 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 8, (yyvsp[-7].type_node), (yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node), (yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2108 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 354 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 9, (yyvsp[-8].type_node), (yyvsp[-7].type_node), (yyvsp[-6].type_node), (yyvsp[-5].type_node), (yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2121 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 362 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Stmt";
        add_child_node((yyval.type_node), 10, (yyvsp[-9].type_node), (yyvsp[-8].type_node), (yyvsp[-7].type_node), (yyvsp[-6].type_node), (yyvsp[-5].type_node),(yyvsp[-4].type_node),(yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2134 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 44:
#line 373 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="DefList";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node), (yyvsp[0].type_node));
    }
#line 2147 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 381 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->empty=TRUE;
        (yyval.type_node)->line = (yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="DefList";
    }
#line 2160 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 392 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Def";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2173 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 400 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing A Declaration \n");
    }
#line 2181 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 403 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing A Semicolon ';'\n");
    }
#line 2189 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 409 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="DecList";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 2202 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 417 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="DecList";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node), (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2215 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 428 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Dec";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));  
    }
#line 2228 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 436 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Dec";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2241 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 448 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2254 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 456 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '=' need a right Expression\n");       
    }
#line 2262 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 460 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2275 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 468 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2288 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 476 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2301 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 484 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '+=' need a right Expression\n");       
    }
#line 2309 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 488 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2322 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 496 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '-=' need a right Expression\n");       
    }
#line 2330 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 500 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2343 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 508 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '*=' need a right Expression\n");       
    }
#line 2351 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 512 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2364 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 520 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '/=' need a right Expression\n");       
    }
#line 2372 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 525 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));  
    }
#line 2385 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 533 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '&&' need a right Expression\n");       
    }
#line 2393 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 537 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2406 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 545 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '||' need a right Expression\n");       
    }
#line 2414 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 549 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));        
    }
#line 2427 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 557 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '<' need a right Expression\n");       
    }
#line 2435 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 561 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node)); 
    }
#line 2448 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 569 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '<=' need a right Expression\n");       
    }
#line 2456 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 573 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2469 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 581 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '>' need a right Expression\n");       
    }
#line 2477 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 585 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2490 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 593 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '>=' need a right Expression\n");       
    }
#line 2498 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 597 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2511 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 605 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '!=' need a right Expression\n");       
    }
#line 2519 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 609 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2532 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 617 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '==' need a right Expression\n");       
    }
#line 2540 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 621 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2553 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 629 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '+' need a right Expression\n");       
    }
#line 2561 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 633 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));   
    }
#line 2574 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 641 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '-' need a right Expression\n");       
    }
#line 2582 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 645 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2595 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 86:
#line 653 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '*' need a right Expression\n");       
    }
#line 2603 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 87:
#line 657 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));      
    }
#line 2616 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 88:
#line 665 "syntax.y" /* yacc.c:1652  */
    {
      printf("Missing an Expression, '/' need a right Expression\n");       
    }
#line 2624 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 89:
#line 670 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));  
    }
#line 2637 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 90:
#line 678 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis: ')'\n");
    }
#line 2645 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 91:
#line 681 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2658 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 92:
#line 689 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 2, (yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2671 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 93:
#line 697 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 4, (yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));        
    }
#line 2684 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 94:
#line 705 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2697 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 95:
#line 713 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis: ')'\n");
    }
#line 2705 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 96:
#line 716 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing parenthesis: ')'\n");
    }
#line 2713 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 97:
#line 719 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=0;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 4, (yyvsp[-3].type_node),(yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2726 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 98:
#line 727 "syntax.y" /* yacc.c:1652  */
    {
        printf("Missing closing bracket ']'\n");
    }
#line 2734 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 99:
#line 730 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=0;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));        
    }
#line 2747 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 100:
#line 738 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=0;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));        
    }
#line 2760 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 101:
#line 746 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));        
    }
#line 2773 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 102:
#line 754 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));        
    }
#line 2786 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 103:
#line 762 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Exp";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 2799 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 108:
#line 777 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Args";
        add_child_node((yyval.type_node), 3, (yyvsp[-2].type_node),(yyvsp[-1].type_node),(yyvsp[0].type_node));
    }
#line 2812 "syntax.tab.c" /* yacc.c:1652  */
    break;

  case 109:
#line 785 "syntax.y" /* yacc.c:1652  */
    {
        (yyval.type_node)=malloc(sizeof(node));
        (yyval.type_node)->line=(yyloc).first_line;
        (yyval.type_node)->word_type=NTERM;
        (yyval.type_node)->lval_or_rval=1;
        (yyval.type_node)->val="Args";
        add_child_node((yyval.type_node), 1, (yyvsp[0].type_node));
    }
#line 2825 "syntax.tab.c" /* yacc.c:1652  */
    break;


#line 2829 "syntax.tab.c" /* yacc.c:1652  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 795 "syntax.y" /* yacc.c:1918  */


void yyerror(const char* s) {
    parser_error=SYNTAX_ERROR;
    printf("Error type B at Line %d: ",yylloc.first_line-1); 
}



