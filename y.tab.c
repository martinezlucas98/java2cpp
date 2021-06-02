/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "java2cpp.y"

	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include<time.h>
	#define MAX_NAME_LEN 32
	#define MAX_VARIABLES 32
	#define DIMENSION 20
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	int current_data_type;
	int bracket_counter=0;
	int expn_type = -1;
	int temp;
	int idx = 0;
	int table_idx = 0;
	int tab_counter = 0;
	char for_var[MAX_NAME_LEN];
	struct symbol_table{char var_name[MAX_NAME_LEN]; int type;} sym[MAX_VARIABLES];
	extern int lookup_in_table(char var[MAX_NAME_LEN]);
	extern void insert_to_table(char var[MAX_NAME_LEN], int type);
	extern void print_tabs();
	char var_list[MAX_VARIABLES][MAX_NAME_LEN];	// MAX_VARIABLES variable names with each variable being atmost MAX_NAME_LEN characters long
	int string_or_var[MAX_VARIABLES];
	//extern int *yytext;

	// functions
	void print_init(){
		time_t t = time(NULL);
  		struct tm now = *localtime(&t);
		char *version = "alpha";
		char *github = "https://github.com/martinezlucas98/java2cpp";

		printf("/*\n*\t===================================================================\n");
		printf("*\tTranslated from java to c++ using java2cpp\n");
		printf("*\tVersion: %s\n", version);
		printf("*\tGithub: %s\n", github);
		printf("*\tTranslated on: %d-%02d-%02d %02d:%02d:%02d (yyyy-MM-dd hh:mm:ss)\n", now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
		printf("*\t===================================================================\n*/\n\n");
		printf("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n");
	}


#line 115 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VAR = 258,
    LAND = 259,
    LOR = 260,
    GEQ = 261,
    LEQ = 262,
    NOT = 263,
    GT = 264,
    LT = 265,
    NEQ = 266,
    DEQ = 267,
    PLUS = 268,
    MINUS = 269,
    MUL = 270,
    DIV = 271,
    MOD = 272,
    ASSIGNMENT = 273,
    EX = 274,
    MAIN_METHOD = 275,
    MAIN_CLASS = 276,
    IF = 277,
    ELSE = 278,
    ELSEIF = 279,
    WHILE = 280,
    FOR = 281,
    CLASS = 282,
    STATIC = 283,
    PUBLIC = 284,
    PRIVATE = 285,
    VOID = 286,
    PRINTLN = 287,
    PRINT = 288,
    NEW = 289,
    DO = 290,
    BREAK = 291,
    RETURN = 292,
    BOOL_VAL = 293,
    NUMBER = 294,
    QUOTED_STRING = 295,
    QUOTED_CHAR = 296,
    LP = 297,
    RP = 298,
    LC = 299,
    RC = 300,
    LB = 301,
    RB = 302,
    COMA = 303,
    SEMICOLON = 304,
    COLON = 305,
    QM = 306,
    SQ = 307,
    DQ = 308,
    ILCOMMENT = 309,
    MLCOMMENT = 310,
    INT = 311,
    CHAR = 312,
    FLOAT = 313,
    DOUBLE = 314,
    STRING = 315,
    BOOLEAN = 316
  };
#endif
/* Tokens.  */
#define VAR 258
#define LAND 259
#define LOR 260
#define GEQ 261
#define LEQ 262
#define NOT 263
#define GT 264
#define LT 265
#define NEQ 266
#define DEQ 267
#define PLUS 268
#define MINUS 269
#define MUL 270
#define DIV 271
#define MOD 272
#define ASSIGNMENT 273
#define EX 274
#define MAIN_METHOD 275
#define MAIN_CLASS 276
#define IF 277
#define ELSE 278
#define ELSEIF 279
#define WHILE 280
#define FOR 281
#define CLASS 282
#define STATIC 283
#define PUBLIC 284
#define PRIVATE 285
#define VOID 286
#define PRINTLN 287
#define PRINT 288
#define NEW 289
#define DO 290
#define BREAK 291
#define RETURN 292
#define BOOL_VAL 293
#define NUMBER 294
#define QUOTED_STRING 295
#define QUOTED_CHAR 296
#define LP 297
#define RP 298
#define LC 299
#define RC 300
#define LB 301
#define RB 302
#define COMA 303
#define SEMICOLON 304
#define COLON 305
#define QM 306
#define SQ 307
#define DQ 308
#define ILCOMMENT 309
#define MLCOMMENT 310
#define INT 311
#define CHAR 312
#define FLOAT 313
#define DOUBLE 314
#define STRING 315
#define BOOLEAN 316

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 46 "java2cpp.y"

int data_type;
char var_name[MAX_NAME_LEN];

#line 291 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  99
/* YYNRULES -- Number of rules.  */
#define YYNRULES  167
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

#define YYUNDEFTOK  2
#define YYMAXUTOK   316


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    74,    74,    75,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    91,    91,    94,
      97,    97,    97,    97,    98,    98,    98,   101,   101,   102,
     102,   108,   109,   109,   110,   113,   113,   113,   113,   116,
     116,   117,   117,   117,   117,   117,   118,   121,   121,   121,
     125,   125,   125,   128,   128,   128,   129,   129,   129,   132,
     133,   133,   134,   134,   135,   138,   138,   138,   142,   143,
     146,   146,   147,   148,   151,   151,   151,   151,   151,   152,
     152,   152,   155,   156,   157,   160,   161,   161,   162,   166,
     167,   168,   171,   171,   172,   172,   173,   173,   174,   174,
     175,   175,   176,   176,   177,   177,   178,   178,   179,   179,
     180,   180,   181,   181,   182,   182,   183,   183,   184,   184,
     185,   186,   187,   188,   191,   192,   192,   192,   195,   195,
     196,   196,   196,   196,   197,   197,   197,   198,   199,   202,
     203,   204,   205,   206,   207,   210,   211,   212,   213,   214,
     215,   216,   219,   220,   221,   222,   225,   226
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "LAND", "LOR", "GEQ", "LEQ",
  "NOT", "GT", "LT", "NEQ", "DEQ", "PLUS", "MINUS", "MUL", "DIV", "MOD",
  "ASSIGNMENT", "EX", "MAIN_METHOD", "MAIN_CLASS", "IF", "ELSE", "ELSEIF",
  "WHILE", "FOR", "CLASS", "STATIC", "PUBLIC", "PRIVATE", "VOID",
  "PRINTLN", "PRINT", "NEW", "DO", "BREAK", "RETURN", "BOOL_VAL", "NUMBER",
  "QUOTED_STRING", "QUOTED_CHAR", "LP", "RP", "LC", "RC", "LB", "RB",
  "COMA", "SEMICOLON", "COLON", "QM", "SQ", "DQ", "ILCOMMENT", "MLCOMMENT",
  "INT", "CHAR", "FLOAT", "DOUBLE", "STRING", "BOOLEAN", "$accept",
  "program", "$@1", "$@2", "STATEMENTS", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "RETURN_ST", "$@13", "BREAK_ST",
  "STDIO", "$@14", "$@15", "$@16", "$@17", "$@18", "VAR_DECLARATION",
  "$@19", "$@20", "BRACKET_ARRAY", "$@21", "IF_STATEMENT", "$@22", "$@23",
  "$@24", "ELSE_VARIATIONS", "$@25", "$@26", "$@27", "$@28", "$@29",
  "WHILE_LOOP", "$@30", "$@31", "FOR_LOOP", "$@32", "$@33", "FOR_PARAMS",
  "$@34", "$@35", "$@36", "$@37", "DECL_EXPR", "$@38", "$@39",
  "DO_WHILE_LOOP", "$@40", "$@41", "NUMARRAY", "HAS_ASSIGNMENT", "$@42",
  "METHODS", "$@43", "$@44", "$@45", "$@46", "$@47", "$@48", "SCOPE",
  "PARAMS", "$@49", "HAS_PARAMS", "EXPRESION", "$@50", "$@51", "$@52",
  "$@53", "$@54", "$@55", "$@56", "$@57", "$@58", "$@59", "$@60", "$@61",
  "$@62", "$@63", "EXPRESION_ARRAY", "$@64", "$@65",
  "EXPRESION_ARRAY_INITIALIZE", "$@66", "$@67", "$@68", "$@69", "$@70",
  "$@71", "TYPE_NO_PRINT", "TYPE", "TERMINAL", "COMMENT", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF (-202)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-136)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,    16,    -3,  -202,   -17,  -202,   251,   -23,     0,   241,
     -18,     9,    15,     8,    21,     7,    23,    20,  -202,  -202,
    -202,  -202,   251,    33,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,   251,     3,  -202,  -202,   251,    22,   251,    24,   251,
      26,   251,    25,   251,  -202,  -202,   251,    47,   251,  -202,
     251,    29,  -202,   241,  -202,  -202,    11,    77,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,    55,    56,  -202,
    -202,  -202,    71,  -202,  -202,    96,    83,  -202,  -202,  -202,
      61,  -202,    71,    64,    64,   251,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,   122,  -202,   251,    86,    -9,
      81,    94,    94,    83,   141,   -11,    98,    93,   303,   140,
     101,   156,   117,    71,    71,    71,    71,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,   148,   149,  -202,  -202,  -202,  -202,
     120,  -202,    58,    71,  -202,   123,  -202,  -202,  -202,   119,
     125,    83,   134,  -202,   129,   136,  -202,   157,   190,   206,
    -202,   227,    71,    71,    71,    71,    71,    71,    71,  -202,
      71,  -202,    71,    71,    71,    71,  -202,   116,  -202,  -202,
    -202,  -202,  -202,  -202,    94,   303,  -202,  -202,  -202,  -202,
    -202,    64,  -202,    83,  -202,   124,  -202,   132,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,   144,   116,     5,  -202,   283,   251,   251,   139,
    -202,  -202,   251,  -202,   142,  -202,   241,  -202,  -202,  -202,
     180,  -202,  -202,   147,   145,   163,   167,  -202,   186,   169,
      64,  -202,  -202,   181,  -202,   283,   182,  -202,  -202,  -202,
    -202,    71,  -202,  -202,   184,  -202,   179,  -202,   283,    31,
     303,   196,   251,  -202,   283,  -202,   185,   193,  -202,  -202,
     183,   283,   202,  -202,  -202,  -202,  -202,  -202,   251,    71,
    -202,   283,   203,   249,  -202,  -202,  -202,   207,  -202,   251,
     205,  -202,    31,  -202
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     8,     0,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,    89,
      92,    93,     8,     0,   161,   155,   156,   157,   158,   159,
     160,     8,     0,   166,   167,     8,     0,     8,     0,     8,
       0,     8,     0,     8,    30,    34,     8,     0,     8,    27,
       8,     0,     7,     0,     9,    37,     0,     0,    11,    45,
      13,    60,    15,    57,    17,    75,    19,     0,     0,    21,
      29,    23,     0,    25,    90,     0,    83,    79,    78,    42,
       0,    39,     0,    74,    74,     8,    31,    35,   133,   116,
     165,   162,   164,   163,   128,     0,   132,     8,     0,    80,
       0,    44,    44,    83,     0,   133,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   104,   106,
     108,   110,   112,   114,   118,   120,   122,   124,   126,    28,
       0,    84,     0,     0,    82,     0,    38,    43,    41,     0,
       0,    83,     0,    63,    70,     0,    70,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,   131,     0,     0,     0,     0,    91,    98,   149,   150,
     151,   152,   153,   154,    44,    81,   136,    40,    46,    73,
      61,    74,    66,    83,    58,     0,    32,     0,   129,   103,
     105,   107,   109,   111,   113,   115,   119,   121,   123,   125,
     127,    96,     0,    98,     0,   134,   148,     8,     8,     0,
      67,    71,     8,    76,     0,    36,   101,    85,    95,    99,
       0,   144,   140,     0,   147,     0,     0,    64,     0,     0,
      74,    33,    97,     0,   100,   148,     0,   137,   138,    47,
      62,     0,    68,    59,     0,    86,     0,   141,   148,    56,
      65,     0,     8,   145,   148,   139,     0,     0,    48,    77,
       0,   148,     0,    49,    51,    87,   146,   142,     8,     0,
      88,   148,     0,     0,   143,    50,    52,     0,    53,     8,
       0,    54,    56,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -202,  -202,  -202,  -202,   -22,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,   -97,  -202,  -202,
    -202,  -202,  -202,   -30,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
     -81,  -202,  -202,  -202,  -202,  -202,  -202,   -93,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,    52,  -202,    51,
     -71,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -201,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,    -7,  -183,  -202
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    50,    72,    48,    46,    67,
     113,   214,    68,   114,    31,    76,   103,    57,   101,    37,
      82,   207,   249,   258,   268,   269,   277,   279,   282,    41,
      84,   212,    39,    83,   208,   106,   181,   241,   210,   228,
     107,   183,   141,    43,    85,   230,    80,   100,   133,    22,
     167,   233,   252,   270,    51,    97,    23,   202,   216,   203,
     108,   152,   153,   154,   155,   156,   157,   158,   115,   160,
     162,   163,   164,   165,   116,   134,   135,   206,   223,   248,
     236,   254,   271,   235,   261,   174,   111,    96,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    95,    32,   110,   137,   138,    55,   -72,   219,    54,
     139,   104,    -5,    58,    77,    60,     3,    62,     4,    64,
      19,    66,    18,   224,    69,   132,    71,     5,    73,    20,
      21,    36,   -72,    40,   246,  -135,    33,    34,   -72,    44,
      45,    38,   148,   149,   150,   151,    75,   255,   179,    56,
      78,    56,   224,   262,   256,   257,    42,    49,    79,    47,
     266,    53,   175,   112,    59,   224,    61,   105,    63,    65,
     274,   224,    89,    74,    88,   130,   109,   205,   224,    89,
      81,   189,   190,   191,   192,   193,   194,   195,   224,   196,
     211,   197,   198,   199,   200,    24,    70,    86,    87,    98,
     209,    99,    90,    91,    92,    93,    94,   220,   102,    90,
      91,    92,    93,    94,   168,   169,   170,   171,   172,   173,
      25,    26,    27,    28,    29,    30,   117,   118,   131,   119,
     136,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      56,   142,   143,   144,   145,   117,   118,    24,   119,   244,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   146,
     204,   159,   147,   161,   201,   166,   213,   176,   177,   178,
     250,   129,    25,    26,    27,    28,    29,    30,   180,   182,
     184,   215,   185,   234,   140,   225,   226,   217,   227,   242,
     229,   231,   237,   238,   117,   118,   204,   119,   273,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   239,   204,
     117,   118,   240,   119,   243,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   253,   245,   247,   251,   265,   263,
     260,   117,   118,   186,   119,   264,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   259,   272,   267,   275,   187,
     281,   278,   283,   117,   118,   218,   119,   280,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   232,     0,     0,
     188,    -6,    24,   -12,     0,     0,   -16,   -14,     0,    -6,
      -6,    -6,     0,   -20,   -20,     0,   -18,   -22,   -24,     0,
       0,     0,   276,     0,     0,     0,   -26,    25,    26,    27,
      28,    29,    30,     0,     0,   -10,   -10,   117,   118,     0,
     119,     0,   120,   121,   122,   123,   124,   125,   126,   127,
     128,    90,    91,    92,    93,     0,     0,   221,     0,     0,
       0,   222
};

static const yytype_int16 yycheck[] =
{
      22,    72,     9,    84,   101,   102,     3,    18,     3,    31,
     103,    82,     0,    35,     3,    37,     0,    39,    21,    41,
      20,    43,    45,   206,    46,    34,    48,    44,    50,    29,
      30,    22,    43,    25,   235,    44,    54,    55,    49,    32,
      33,    26,   113,   114,   115,   116,    53,   248,   141,    46,
      39,    46,   235,   254,    23,    24,    35,    37,    47,    36,
     261,    28,   133,    85,    42,   248,    42,     3,    42,    44,
     271,   254,     8,    44,     3,    97,    83,   174,   261,     8,
       3,   152,   153,   154,   155,   156,   157,   158,   271,   160,
     183,   162,   163,   164,   165,    31,    49,    42,    42,     3,
     181,    18,    38,    39,    40,    41,    42,   204,    47,    38,
      39,    40,    41,    42,    56,    57,    58,    59,    60,    61,
      56,    57,    58,    59,    60,    61,     4,     5,    42,     7,
      49,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      46,    43,    49,     3,    43,     4,     5,    31,     7,   230,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     3,
     167,    13,    45,    14,    48,    45,    42,    44,    49,    44,
     241,    49,    56,    57,    58,    59,    60,    61,    44,    50,
      44,    49,    25,     3,    43,   207,   208,    43,    49,     3,
     212,    49,    45,    48,     4,     5,   203,     7,   269,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    45,   216,
       4,     5,    45,     7,    45,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    45,    44,    44,    43,    45,    44,
     252,     4,     5,    43,     7,    42,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    49,   268,    45,    45,    43,
      45,    44,   282,     4,     5,   203,     7,   279,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   216,    -1,    -1,
      43,    20,    31,    22,    -1,    -1,    25,    26,    -1,    28,
      29,    30,    -1,    32,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    43,    -1,    -1,    -1,    45,    56,    57,    58,
      59,    60,    61,    -1,    -1,    54,    55,     4,     5,    -1,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    38,    39,    40,    41,    -1,    -1,    44,    -1,    -1,
      -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,    21,    44,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    45,    20,
      29,    30,   121,   128,    31,    56,    57,    58,    59,    60,
      61,    86,   158,    54,    55,   160,    22,    91,    26,   104,
      25,   101,    35,   115,    32,    33,    80,    36,    79,    37,
      77,   126,    66,    28,    66,     3,    46,    89,    66,    42,
      66,    42,    66,    42,    66,    44,    66,    81,    84,    66,
      49,    66,    78,    66,    44,   158,    87,     3,    39,    47,
     118,     3,    92,   105,   102,   116,    42,    42,     3,     8,
      38,    39,    40,    41,    42,   132,   159,   127,     3,    18,
     119,    90,    47,    88,   132,     3,   107,   112,   132,   158,
     112,   158,    66,    82,    85,   140,   146,     4,     5,     7,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    49,
      66,    42,    34,   120,   147,   148,    49,    89,    89,   119,
      43,   114,    43,    49,     3,    43,     3,    45,   132,   132,
     132,   132,   133,   134,   135,   136,   137,   138,   139,    13,
     141,    14,   142,   143,   144,   145,    45,   122,    56,    57,
      58,    59,    60,    61,   157,   132,    44,    49,    44,   119,
      44,   108,    50,   113,    44,    25,    43,    43,    43,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,    48,   129,   131,   158,    89,   149,    93,   106,   112,
     110,   119,   103,    42,    83,    49,   130,    43,   129,     3,
      89,    44,    48,   150,   159,    66,    66,    49,   111,    66,
     117,    49,   131,   123,     3,   155,   152,    45,    48,    45,
      45,   109,     3,    45,   112,    44,   150,    44,   151,    94,
     132,    43,   124,    45,   153,   150,    23,    24,    95,    49,
      66,   156,   150,    44,    42,    45,   150,    45,    96,    97,
     125,   154,    66,   132,   150,    45,    43,    98,    44,    99,
      66,    45,   100,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    65,    63,    63,    67,    66,    68,    66,
      69,    66,    70,    66,    71,    66,    72,    66,    73,    66,
      74,    66,    75,    66,    76,    66,    66,    78,    77,    79,
      81,    82,    83,    80,    84,    85,    80,    87,    86,    88,
      86,    89,    90,    89,    89,    92,    93,    94,    91,    96,
      95,    97,    98,    99,   100,    95,    95,   102,   103,   101,
     105,   106,   104,   108,   109,   107,   110,   111,   107,   112,
     113,   112,   114,   112,   112,   116,   117,   115,   118,   118,
     120,   119,   119,   119,   122,   123,   124,   125,   121,   126,
     127,   121,   128,   128,   128,   129,   130,   129,   129,   131,
     131,   131,   133,   132,   134,   132,   135,   132,   136,   132,
     137,   132,   138,   132,   139,   132,   140,   132,   141,   132,
     142,   132,   143,   132,   144,   132,   145,   132,   146,   132,
     132,   132,   132,   132,   147,   148,   149,   147,   151,   150,
     152,   153,   154,   150,   155,   156,   150,   150,   150,   157,
     157,   157,   157,   157,   157,   158,   158,   158,   158,   158,
     158,   158,   159,   159,   159,   159,   160,   160
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     6,     0,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     0,     4,     2,
       0,     0,     0,     8,     0,     0,     7,     0,     5,     0,
       6,     4,     0,     4,     0,     0,     0,     0,    11,     0,
       5,     0,     0,     0,     0,    12,     0,     0,     0,     9,
       0,     0,     9,     0,     0,     7,     0,     0,     6,     1,
       0,     4,     0,     3,     0,     0,     0,    11,     1,     1,
       0,     3,     2,     0,     0,     0,     0,     0,    14,     0,
       0,     6,     1,     1,     0,     2,     0,     3,     0,     2,
       3,     0,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     3,     1,     1,     3,     0,     0,     5,     0,     4,
       0,     0,     0,     8,     0,     0,     6,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 74 "java2cpp.y"
                  { print_init(); }
#line 1701 "y.tab.c"
    break;

  case 3:
#line 74 "java2cpp.y"
                                                  { printf("/* start Main Class */\n"); }
#line 1707 "y.tab.c"
    break;

  case 4:
#line 74 "java2cpp.y"
                                                                                                        { printf("\n/* end Main Class */\n"); exit(0); }
#line 1713 "y.tab.c"
    break;

  case 5:
#line 75 "java2cpp.y"
                                                { printf("\n"); exit(2); }
#line 1719 "y.tab.c"
    break;

  case 6:
#line 78 "java2cpp.y"
                  { print_tabs(); }
#line 1725 "y.tab.c"
    break;

  case 7:
#line 78 "java2cpp.y"
                                                       { }
#line 1731 "y.tab.c"
    break;

  case 8:
#line 79 "java2cpp.y"
                          { print_tabs(); }
#line 1737 "y.tab.c"
    break;

  case 9:
#line 79 "java2cpp.y"
                                                                       { }
#line 1743 "y.tab.c"
    break;

  case 10:
#line 80 "java2cpp.y"
                          { print_tabs(); }
#line 1749 "y.tab.c"
    break;

  case 11:
#line 80 "java2cpp.y"
                                                               { }
#line 1755 "y.tab.c"
    break;

  case 12:
#line 81 "java2cpp.y"
                          { print_tabs(); }
#line 1761 "y.tab.c"
    break;

  case 13:
#line 81 "java2cpp.y"
                                                                    { }
#line 1767 "y.tab.c"
    break;

  case 14:
#line 82 "java2cpp.y"
                          { print_tabs(); }
#line 1773 "y.tab.c"
    break;

  case 15:
#line 82 "java2cpp.y"
                                                                { }
#line 1779 "y.tab.c"
    break;

  case 16:
#line 83 "java2cpp.y"
                          { print_tabs(); }
#line 1785 "y.tab.c"
    break;

  case 17:
#line 83 "java2cpp.y"
                                                                  { }
#line 1791 "y.tab.c"
    break;

  case 18:
#line 84 "java2cpp.y"
                          { print_tabs(); }
#line 1797 "y.tab.c"
    break;

  case 19:
#line 84 "java2cpp.y"
                                                                     { }
#line 1803 "y.tab.c"
    break;

  case 20:
#line 85 "java2cpp.y"
                          { print_tabs(); }
#line 1809 "y.tab.c"
    break;

  case 21:
#line 85 "java2cpp.y"
                                                             { }
#line 1815 "y.tab.c"
    break;

  case 22:
#line 86 "java2cpp.y"
                          { print_tabs(); }
#line 1821 "y.tab.c"
    break;

  case 23:
#line 86 "java2cpp.y"
                                                                { }
#line 1827 "y.tab.c"
    break;

  case 24:
#line 87 "java2cpp.y"
                          { print_tabs(); }
#line 1833 "y.tab.c"
    break;

  case 25:
#line 87 "java2cpp.y"
                                                                 { }
#line 1839 "y.tab.c"
    break;

  case 26:
#line 88 "java2cpp.y"
                                { }
#line 1845 "y.tab.c"
    break;

  case 27:
#line 91 "java2cpp.y"
                         { printf("return "); }
#line 1851 "y.tab.c"
    break;

  case 28:
#line 91 "java2cpp.y"
                                                                    { printf(";\n"); }
#line 1857 "y.tab.c"
    break;

  case 29:
#line 94 "java2cpp.y"
                                   { printf("break;\n"); }
#line 1863 "y.tab.c"
    break;

  case 30:
#line 97 "java2cpp.y"
                  { printf("std::cout"); }
#line 1869 "y.tab.c"
    break;

  case 31:
#line 97 "java2cpp.y"
                                              { printf(" << "); }
#line 1875 "y.tab.c"
    break;

  case 32:
#line 97 "java2cpp.y"
                                                                               { printf(" <<  std::endl"); }
#line 1881 "y.tab.c"
    break;

  case 33:
#line 97 "java2cpp.y"
                                                                                                                       { printf(";\n"); }
#line 1887 "y.tab.c"
    break;

  case 34:
#line 98 "java2cpp.y"
                        { printf("std::cout"); }
#line 1893 "y.tab.c"
    break;

  case 35:
#line 98 "java2cpp.y"
                                                    { printf(" << "); }
#line 1899 "y.tab.c"
    break;

  case 36:
#line 98 "java2cpp.y"
                                                                                               { printf(";\n"); }
#line 1905 "y.tab.c"
    break;

  case 37:
#line 101 "java2cpp.y"
                            { printf("%s", yylval.var_name); }
#line 1911 "y.tab.c"
    break;

  case 38:
#line 101 "java2cpp.y"
                                                                                        { printf(";\n"); }
#line 1917 "y.tab.c"
    break;

  case 39:
#line 102 "java2cpp.y"
                                                          { printf("%s", yylval.var_name); }
#line 1923 "y.tab.c"
    break;

  case 40:
#line 102 "java2cpp.y"
                                                                                                                      { printf(";\n"); }
#line 1929 "y.tab.c"
    break;

  case 42:
#line 109 "java2cpp.y"
                                  { bracket_counter++; }
#line 1935 "y.tab.c"
    break;

  case 45:
#line 113 "java2cpp.y"
                        { printf("if ("); }
#line 1941 "y.tab.c"
    break;

  case 46:
#line 113 "java2cpp.y"
                                                            { tab_counter++; printf(") {\n"); }
#line 1947 "y.tab.c"
    break;

  case 47:
#line 113 "java2cpp.y"
                                                                                                              { tab_counter--; print_tabs(); printf("}"); }
#line 1953 "y.tab.c"
    break;

  case 49:
#line 116 "java2cpp.y"
                          { tab_counter++; printf(" else {\n"); }
#line 1959 "y.tab.c"
    break;

  case 50:
#line 116 "java2cpp.y"
                                                                                { tab_counter--; print_tabs(); printf("}"); }
#line 1965 "y.tab.c"
    break;

  case 51:
#line 117 "java2cpp.y"
                                            { printf(" else if ("); }
#line 1971 "y.tab.c"
    break;

  case 52:
#line 117 "java2cpp.y"
                                                                                   { printf(")"); }
#line 1977 "y.tab.c"
    break;

  case 53:
#line 117 "java2cpp.y"
                                                                                                       { tab_counter++; printf(") {\n"); }
#line 1983 "y.tab.c"
    break;

  case 54:
#line 117 "java2cpp.y"
                                                                                                                                                         { tab_counter--;print_tabs(); printf("}"); }
#line 1989 "y.tab.c"
    break;

  case 56:
#line 118 "java2cpp.y"
                                        { printf("\n"); }
#line 1995 "y.tab.c"
    break;

  case 57:
#line 121 "java2cpp.y"
                           {printf("while ("); }
#line 2001 "y.tab.c"
    break;

  case 58:
#line 121 "java2cpp.y"
                                                                 { tab_counter++; printf("){\n"); }
#line 2007 "y.tab.c"
    break;

  case 59:
#line 121 "java2cpp.y"
                                                                                                                  { tab_counter--; print_tabs(); printf("}\n"); }
#line 2013 "y.tab.c"
    break;

  case 60:
#line 125 "java2cpp.y"
                         { printf("for ("); }
#line 2019 "y.tab.c"
    break;

  case 61:
#line 125 "java2cpp.y"
                                                               { tab_counter++; printf(") {\n"); }
#line 2025 "y.tab.c"
    break;

  case 62:
#line 125 "java2cpp.y"
                                                                                                                 { tab_counter--; print_tabs(); printf("}\n"); }
#line 2031 "y.tab.c"
    break;

  case 63:
#line 128 "java2cpp.y"
                                      { printf("; "); }
#line 2037 "y.tab.c"
    break;

  case 64:
#line 128 "java2cpp.y"
                                                                            { printf("; "); }
#line 2043 "y.tab.c"
    break;

  case 66:
#line 129 "java2cpp.y"
                                         { printf("%s", yylval.var_name); }
#line 2049 "y.tab.c"
    break;

  case 67:
#line 129 "java2cpp.y"
                                                                            { printf(" : "); }
#line 2055 "y.tab.c"
    break;

  case 68:
#line 129 "java2cpp.y"
                                                                                                   { printf("%s", yylval.var_name); }
#line 2061 "y.tab.c"
    break;

  case 70:
#line 133 "java2cpp.y"
                                   { printf("%s", yylval.var_name); }
#line 2067 "y.tab.c"
    break;

  case 72:
#line 134 "java2cpp.y"
                              { printf("%s", yylval.var_name); }
#line 2073 "y.tab.c"
    break;

  case 74:
#line 135 "java2cpp.y"
                                 { }
#line 2079 "y.tab.c"
    break;

  case 75:
#line 138 "java2cpp.y"
                        { printf("do{\n"); tab_counter++;}
#line 2085 "y.tab.c"
    break;

  case 76:
#line 138 "java2cpp.y"
                                                                                  {tab_counter--; print_tabs(); printf("}while("); }
#line 2091 "y.tab.c"
    break;

  case 77:
#line 138 "java2cpp.y"
                                                                                                                                                            { printf(");"); }
#line 2097 "y.tab.c"
    break;

  case 78:
#line 142 "java2cpp.y"
                           { printf("[%s]", yylval.var_name); }
#line 2103 "y.tab.c"
    break;

  case 79:
#line 143 "java2cpp.y"
                              { printf("[%s]", yylval.var_name); }
#line 2109 "y.tab.c"
    break;

  case 80:
#line 146 "java2cpp.y"
                             { printf(" = "); }
#line 2115 "y.tab.c"
    break;

  case 83:
#line 148 "java2cpp.y"
                                                      {}
#line 2121 "y.tab.c"
    break;

  case 84:
#line 151 "java2cpp.y"
                                   { printf("( "); }
#line 2127 "y.tab.c"
    break;

  case 85:
#line 151 "java2cpp.y"
                                                               { printf(") "); }
#line 2133 "y.tab.c"
    break;

  case 86:
#line 151 "java2cpp.y"
                                                                                        { tab_counter++; printf("{\n"); }
#line 2139 "y.tab.c"
    break;

  case 87:
#line 151 "java2cpp.y"
                                                                                                                                        { printf("}\n"); tab_counter--; }
#line 2145 "y.tab.c"
    break;

  case 88:
#line 151 "java2cpp.y"
                                                                                                                                                                                { }
#line 2151 "y.tab.c"
    break;

  case 89:
#line 152 "java2cpp.y"
                              { printf("int main(int argc, char **argv)"); }
#line 2157 "y.tab.c"
    break;

  case 90:
#line 152 "java2cpp.y"
                                                                                { tab_counter++; printf("{\n"); }
#line 2163 "y.tab.c"
    break;

  case 91:
#line 152 "java2cpp.y"
                                                                                                                                { printf("\n}\n"); tab_counter--; }
#line 2169 "y.tab.c"
    break;

  case 96:
#line 161 "java2cpp.y"
                       { printf(","); }
#line 2175 "y.tab.c"
    break;

  case 98:
#line 162 "java2cpp.y"
                                                { printf(" "); }
#line 2181 "y.tab.c"
    break;

  case 99:
#line 166 "java2cpp.y"
                           { printf("%s", yylval.var_name); }
#line 2187 "y.tab.c"
    break;

  case 100:
#line 167 "java2cpp.y"
                                                  { printf("%s", yylval.var_name);printf("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--)printf("[%d]",DIMENSION);}
#line 2193 "y.tab.c"
    break;

  case 102:
#line 171 "java2cpp.y"
                                 { printf("&&"); }
#line 2199 "y.tab.c"
    break;

  case 104:
#line 172 "java2cpp.y"
                                        { printf("||"); }
#line 2205 "y.tab.c"
    break;

  case 106:
#line 173 "java2cpp.y"
                                        { printf("<="); }
#line 2211 "y.tab.c"
    break;

  case 108:
#line 174 "java2cpp.y"
                                       { printf(">"); }
#line 2217 "y.tab.c"
    break;

  case 110:
#line 175 "java2cpp.y"
                                       { printf("<"); }
#line 2223 "y.tab.c"
    break;

  case 112:
#line 176 "java2cpp.y"
                                        { printf("!="); }
#line 2229 "y.tab.c"
    break;

  case 114:
#line 177 "java2cpp.y"
                                        { printf("=="); }
#line 2235 "y.tab.c"
    break;

  case 116:
#line 178 "java2cpp.y"
                              { printf("!"); }
#line 2241 "y.tab.c"
    break;

  case 118:
#line 179 "java2cpp.y"
                                         { printf("+"); }
#line 2247 "y.tab.c"
    break;

  case 120:
#line 180 "java2cpp.y"
                                          { printf("-"); }
#line 2253 "y.tab.c"
    break;

  case 122:
#line 181 "java2cpp.y"
                                        { printf("*"); }
#line 2259 "y.tab.c"
    break;

  case 124:
#line 182 "java2cpp.y"
                                        { printf("/"); }
#line 2265 "y.tab.c"
    break;

  case 126:
#line 183 "java2cpp.y"
                                        { printf("%%"); }
#line 2271 "y.tab.c"
    break;

  case 128:
#line 184 "java2cpp.y"
                             { printf("("); }
#line 2277 "y.tab.c"
    break;

  case 129:
#line 184 "java2cpp.y"
                                                           { printf(")"); }
#line 2283 "y.tab.c"
    break;

  case 130:
#line 185 "java2cpp.y"
                                              { printf("++"); }
#line 2289 "y.tab.c"
    break;

  case 131:
#line 186 "java2cpp.y"
                                                { printf("--"); }
#line 2295 "y.tab.c"
    break;

  case 133:
#line 188 "java2cpp.y"
                              { printf("[%s]", yylval.var_name); }
#line 2301 "y.tab.c"
    break;

  case 134:
#line 191 "java2cpp.y"
                                                  {bracket_counter=0;}
#line 2307 "y.tab.c"
    break;

  case 135:
#line 192 "java2cpp.y"
                                  { for(;bracket_counter>0;bracket_counter--)printf("[]"); }
#line 2313 "y.tab.c"
    break;

  case 136:
#line 192 "java2cpp.y"
                                                                                                { printf(" = {"); }
#line 2319 "y.tab.c"
    break;

  case 137:
#line 192 "java2cpp.y"
                                                                                                                                                  { printf("}"); }
#line 2325 "y.tab.c"
    break;

  case 138:
#line 195 "java2cpp.y"
                                                { printf(","); }
#line 2331 "y.tab.c"
    break;

  case 140:
#line 196 "java2cpp.y"
                                                               { printf(","); }
#line 2337 "y.tab.c"
    break;

  case 141:
#line 196 "java2cpp.y"
                                                                                   { printf("{"); }
#line 2343 "y.tab.c"
    break;

  case 142:
#line 196 "java2cpp.y"
                                                                                                                                  { printf("}"); }
#line 2349 "y.tab.c"
    break;

  case 144:
#line 197 "java2cpp.y"
                                                              { printf("{"); }
#line 2355 "y.tab.c"
    break;

  case 145:
#line 197 "java2cpp.y"
                                                                                                             { printf("}"); }
#line 2361 "y.tab.c"
    break;

  case 155:
#line 210 "java2cpp.y"
              { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type);	printf("int "); }
#line 2367 "y.tab.c"
    break;

  case 156:
#line 211 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("char "); }
#line 2373 "y.tab.c"
    break;

  case 157:
#line 212 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("float "); }
#line 2379 "y.tab.c"
    break;

  case 158:
#line 213 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("double "); }
#line 2385 "y.tab.c"
    break;

  case 159:
#line 214 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("string "); }
#line 2391 "y.tab.c"
    break;

  case 160:
#line 215 "java2cpp.y"
                          { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("bool "); }
#line 2397 "y.tab.c"
    break;

  case 161:
#line 216 "java2cpp.y"
                       { printf("void "); }
#line 2403 "y.tab.c"
    break;

  case 162:
#line 219 "java2cpp.y"
                         { printf("%s", yylval.var_name); }
#line 2409 "y.tab.c"
    break;

  case 163:
#line 220 "java2cpp.y"
                                      { printf("%s", yylval.var_name); }
#line 2415 "y.tab.c"
    break;

  case 164:
#line 221 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2421 "y.tab.c"
    break;

  case 165:
#line 222 "java2cpp.y"
                                   { printf("%s", yylval.var_name); }
#line 2427 "y.tab.c"
    break;

  case 166:
#line 225 "java2cpp.y"
                                { printf("%s\n", yylval.var_name); }
#line 2433 "y.tab.c"
    break;

  case 167:
#line 226 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2439 "y.tab.c"
    break;


#line 2443 "y.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 230 "java2cpp.y"


#include "lex.yy.c"
int lookup_in_table(char var[MAX_NAME_LEN])
{
	for(int i=0; i<table_idx; i++)
	{
		if(strcmp(sym[i].var_name, var)==0)
			return sym[i].type;
	}
	return -1;
}

void insert_to_table(char var[MAX_NAME_LEN], int type)
{
	if(lookup_in_table(var)==-1)
	{
		strcpy(sym[table_idx].var_name,var);
		sym[table_idx].type = type;
		table_idx++;
	}
	else {
		printf("Multiple declaration of variable\n");
		yyerror("");
		exit(0);
	}
}

void print_tabs() {
	for(int i = 0; i < tab_counter; i++){
		printf("\t");
	}
	return;
}

int main() {
	yyparse();
	return 0;
}

int yyerror(const char *msg) {
	extern int yylineno;
	printf("Parsing failed\nLine number: %d %s\n", yylineno, msg);
	success = 0;
	return 0;
}


