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
	#define MAX_SCOPE 32
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
	char stack_scope[MAX_SCOPE][MAX_VARIABLES];
	int stack_scope_counter=-1;
	struct symbol_table{char var_name[MAX_NAME_LEN]; int type;char scope_name[MAX_NAME_LEN];} sym[MAX_VARIABLES];
	extern int lookup_in_table(char var[MAX_NAME_LEN]);
	void verify_scope(char var[MAX_NAME_LEN]); // When a variable is used look first if it was declared before
	extern void insert_to_table(char var[MAX_NAME_LEN], int type);
	extern void push_scope(char var[MAX_NAME_LEN]);// Add to the stack the name of the current scope
	extern void create_scope_name_and_push_it();//Create unique name for loops and conditional statment
	extern void pop_scope();
	extern void print_tabs();
	extern void print_table_symbols();
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


#line 123 "y.tab.c"

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
#line 54 "java2cpp.y"

int data_type;
char var_name[MAX_NAME_LEN];

#line 299 "y.tab.c"

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
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  178
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

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
       0,    82,    82,    82,    82,    83,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    96,    96,    97,   100,
     102,   103,   106,   106,   106,   106,   106,   106,   108,   109,
     112,   112,   115,   118,   118,   118,   118,   119,   119,   119,
     122,   122,   123,   123,   126,   126,   126,   129,   130,   130,
     131,   134,   134,   134,   134,   137,   137,   138,   138,   138,
     138,   138,   139,   142,   142,   142,   146,   146,   146,   149,
     149,   149,   150,   150,   150,   153,   154,   154,   155,   155,
     156,   159,   159,   159,   163,   164,   167,   167,   168,   169,
     172,   172,   172,   177,   178,   179,   182,   183,   183,   184,
     188,   189,   190,   193,   193,   194,   194,   195,   195,   196,
     196,   197,   197,   198,   198,   199,   199,   200,   200,   201,
     201,   202,   202,   203,   203,   204,   204,   205,   205,   206,
     206,   207,   208,   209,   210,   213,   214,   214,   214,   217,
     217,   218,   218,   218,   218,   219,   219,   219,   220,   221,
     224,   225,   226,   227,   228,   229,   232,   233,   234,   235,
     236,   237,   238,   241,   242,   243,   244,   247,   248
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
  "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "IGNORE_SCOPE",
  "DECLARATION", "METHODS", "$@14", "$@15", "$@16", "$@17", "$@18",
  "IS_STATIC", "RETURN_ST", "$@19", "BREAK_ST", "STDIO", "$@20", "$@21",
  "$@22", "$@23", "$@24", "VAR_DECLARATION", "$@25", "$@26",
  "VAR_ASSIGNATION", "$@27", "$@28", "BRACKET_ARRAY", "$@29",
  "IF_STATEMENT", "$@30", "$@31", "$@32", "ELSE_VARIATIONS", "$@33",
  "$@34", "$@35", "$@36", "$@37", "WHILE_LOOP", "$@38", "$@39", "FOR_LOOP",
  "$@40", "$@41", "FOR_PARAMS", "$@42", "$@43", "$@44", "$@45",
  "DECL_EXPR", "$@46", "$@47", "DO_WHILE_LOOP", "$@48", "$@49", "NUMARRAY",
  "HAS_ASSIGNMENT", "$@50", "MAIN_METHOD_DECLARATION", "$@51", "$@52",
  "SCOPE", "PARAMS", "$@53", "HAS_PARAMS", "EXPRESION", "$@54", "$@55",
  "$@56", "$@57", "$@58", "$@59", "$@60", "$@61", "$@62", "$@63", "$@64",
  "$@65", "$@66", "$@67", "EXPRESION_ARRAY", "$@68", "$@69",
  "EXPRESION_ARRAY_INITIALIZE", "$@70", "$@71", "$@72", "$@73", "$@74",
  "$@75", "TYPE_NO_PRINT", "TYPE", "TERMINAL", "COMMENT", YY_NULLPTR
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

#define YYPACT_NINF (-215)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-147)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    20,     1,  -215,    -9,  -215,   108,    -1,     0,    26,
     -22,    27,    29,    25,    31,     5,    12,    15,    64,  -215,
    -215,  -215,    22,   108,    44,  -215,   108,  -215,  -215,   108,
      32,   108,    33,   108,    35,   108,    34,   108,  -215,  -215,
     108,    36,   108,  -215,   108,  -215,   108,    45,     4,  -215,
    -215,    86,  -215,  -215,   243,    48,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,    52,    53,  -215,  -215,
    -215,   209,  -215,    85,  -215,    68,    94,  -215,  -215,  -215,
      70,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,   209,    23,    23,   108,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,   109,  -215,  -215,  -215,   -16,    66,
      83,    83,    94,   108,   179,    -7,    88,   106,   301,   129,
      92,   153,   112,   209,   209,   209,   209,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,   146,   147,  -215,  -215,  -215,  -215,
     209,   206,    91,   209,  -215,   116,  -215,  -215,  -215,   118,
     124,   135,    94,   136,  -215,   131,   138,  -215,   172,   214,
     229,  -215,   266,   209,   209,   209,   209,   209,   209,   209,
    -215,   209,  -215,   209,   209,   209,   209,   161,  -215,   156,
     206,    24,  -215,  -215,  -215,  -215,  -215,  -215,    83,   301,
    -215,  -215,  -215,  -215,  -215,  -215,    23,  -215,    94,  -215,
     158,  -215,   154,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   243,  -215,  -215,
    -215,   202,  -215,    98,   108,   108,   159,  -215,  -215,   108,
    -215,   160,  -215,  -215,   163,  -215,  -215,  -215,   168,   166,
     171,   187,  -215,   249,   208,    23,  -215,  -215,    98,   211,
    -215,  -215,  -215,  -215,   209,  -215,  -215,   213,   108,   215,
    -215,    98,    17,   301,   210,   216,  -215,    98,  -215,   225,
     244,  -215,  -215,  -215,    98,   253,  -215,  -215,  -215,  -215,
    -215,   108,   209,    98,   262,   280,  -215,  -215,  -215,   275,
    -215,   108,   276,  -215,    17,  -215
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     0,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
     103,   104,     0,     6,    39,   100,     6,   177,   178,     6,
       0,     6,     0,     6,     0,     6,     0,     6,    43,    47,
       6,     0,     6,    40,     6,    54,     6,    50,     0,    30,
      31,     0,     7,    38,     0,     0,     9,    11,    61,    13,
      76,    15,    73,    17,    91,    19,     0,     0,    21,    42,
      23,     0,    25,     0,    27,     0,    99,    95,    94,    58,
       0,    52,   172,   166,   167,   168,   169,   170,   171,    29,
     101,     0,    90,    90,     6,    44,    48,   144,   127,   176,
     173,   175,   174,   139,     0,   143,    55,    33,    96,     0,
      60,    60,    99,     6,     0,   144,     0,     0,    85,     0,
       0,     0,     0,     0,     0,     0,     0,   113,   115,   117,
     119,   121,   123,   125,   129,   131,   133,   135,   137,    41,
       0,   109,     0,     0,    98,     0,    51,    59,    57,     0,
       0,     0,    99,     0,    79,    86,     0,    86,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,   142,     0,     0,     0,     0,     0,   107,     0,
     109,     0,   160,   161,   162,   163,   164,   165,    60,    97,
     147,    53,   102,    62,    89,    77,    90,    82,    99,    74,
       0,    45,     0,   140,   114,   116,   118,   120,   122,   124,
     126,   130,   132,   134,   136,   138,    56,   112,    34,   106,
     110,     0,   145,   159,     6,     6,     0,    83,    87,     6,
      92,     0,    49,   108,     0,   111,   155,   151,     0,   158,
       0,     0,    80,     0,     0,    90,    46,    35,   159,     0,
     148,   149,    63,    78,     0,    84,    75,     0,     6,     0,
     152,   159,    72,    81,     0,     0,   156,   159,   150,     0,
       0,    64,    93,    36,   159,     0,    65,    67,    37,   157,
     153,     6,     0,   159,     0,     0,   154,    66,    68,     0,
      69,     6,     0,    70,    72,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -215,  -215,  -215,  -215,   -23,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
     -95,  -215,  -215,  -215,  -215,  -215,    -6,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,   -91,  -215,  -215,  -215,  -215,  -215,  -215,
    -107,  -215,  -215,  -215,  -215,  -215,   140,  -215,   105,   -67,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,  -215,  -215,   -63,  -215,  -215,
    -215,  -215,  -215,  -215,  -215,   -53,  -214,  -215
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    22,    23,    49,    75,
     141,   234,   258,   278,    54,    44,    71,    42,    40,    66,
     123,   231,    67,   124,    50,    76,   112,    46,    73,   140,
      51,   110,    31,    91,   224,   262,   271,   281,   282,   289,
     291,   294,    35,    93,   229,    33,    92,   225,   116,   196,
     254,   227,   243,   117,   198,   152,    37,    94,   245,    80,
     109,   143,    26,    55,   113,    24,   179,   217,   180,   118,
     163,   164,   165,   166,   167,   168,   169,   125,   171,   173,
     174,   175,   176,   126,   144,   145,   223,   238,   261,   249,
     267,   283,   248,   274,   188,   121,   105,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    89,   120,    56,   104,   149,    57,    77,    59,   239,
      61,   -88,    63,    -5,    65,   147,   148,    68,   142,    70,
       3,    72,     4,    74,   114,    47,   115,   220,  -146,    20,
      21,    98,    27,    28,   239,     5,   -88,    38,    39,   119,
     269,   270,   -88,    78,    19,   194,    25,   239,    41,    30,
      34,    79,    43,   239,    82,    32,   159,   160,   161,   162,
     239,    99,   100,   101,   102,   103,    36,    45,    48,   239,
      48,   122,    53,   177,    58,    60,   189,    62,    64,    83,
      84,    85,    86,    87,    88,    69,   221,   -32,   181,    81,
     150,   228,    90,   222,    95,    96,   204,   205,   206,   207,
     208,   209,   210,   106,   211,   226,   212,   213,   214,   215,
     107,   -26,   108,   127,   128,   146,   129,   111,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   181,    -8,    48,
     -12,   153,   155,   -16,   -14,   156,    99,   100,   101,   102,
     -20,   -20,   236,   -18,   -22,   -24,   237,   182,   183,   184,
     185,   186,   187,   -28,   257,   154,   157,   158,   139,   170,
     190,   172,   -10,   -10,   181,   127,   128,   191,   129,   192,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   193,
     195,   197,   199,   127,   128,   259,   129,   263,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   200,   268,   218,
     230,   240,   241,   232,   275,   235,   244,   247,   242,   246,
     216,   279,    97,   250,   251,   285,   252,    98,   127,   128,
     286,   129,   151,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   253,   127,   128,   265,   129,    82,   130,   131,
     132,   133,   134,   135,   136,   137,   138,    99,   100,   101,
     102,   103,   255,   256,   178,   260,   264,   201,   284,   272,
     266,   273,    83,    84,    85,    86,    87,    88,   292,   276,
     127,   128,   202,   129,    82,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   127,   128,   277,   129,   295,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   280,    83,
      84,    85,    86,    87,    88,   127,   128,   287,   129,   203,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   290,
     219,   293,   233,   288
};

static const yytype_int16 yycheck[] =
{
      23,    54,    93,    26,    71,   112,    29,     3,    31,   223,
      33,    18,    35,     0,    37,   110,   111,    40,    34,    42,
       0,    44,    21,    46,    91,     3,     3,     3,    44,    29,
      30,     8,    54,    55,   248,    44,    43,    32,    33,    92,
      23,    24,    49,    39,    45,   152,    20,   261,    36,    22,
      25,    47,    37,   267,    31,    26,   123,   124,   125,   126,
     274,    38,    39,    40,    41,    42,    35,     3,    46,   283,
      46,    94,    28,   140,    42,    42,   143,    42,    44,    56,
      57,    58,    59,    60,    61,    49,   181,    42,   141,     3,
     113,   198,    44,   188,    42,    42,   163,   164,   165,   166,
     167,   168,   169,    18,   171,   196,   173,   174,   175,   176,
      42,     3,    18,     4,     5,    49,     7,    47,     9,    10,
      11,    12,    13,    14,    15,    16,    17,   180,    20,    46,
      22,    43,     3,    25,    26,    43,    38,    39,    40,    41,
      32,    33,    44,    35,    36,    37,    48,    56,    57,    58,
      59,    60,    61,    45,   245,    49,     3,    45,    49,    13,
      44,    14,    54,    55,   217,     4,     5,    49,     7,    45,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    44,
      44,    50,    44,     4,     5,   248,     7,   254,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    25,   261,    43,
      42,   224,   225,    49,   267,     3,   229,    44,    49,    49,
      49,   274,     3,    45,    48,   282,    45,     8,     4,     5,
     283,     7,    43,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    45,     4,     5,   258,     7,    31,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    38,    39,    40,
      41,    42,     3,    45,    48,    44,    43,    43,   281,    49,
      45,    45,    56,    57,    58,    59,    60,    61,   291,    44,
       4,     5,    43,     7,    31,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     4,     5,    42,     7,   294,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    45,    56,
      57,    58,    59,    60,    61,     4,     5,    45,     7,    43,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    44,
     180,    45,   217,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,    21,    44,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    45,
      29,    30,    78,    79,   137,    20,   134,    54,    55,   169,
      22,   104,    26,   117,    25,   114,    35,   128,    32,    33,
      90,    36,    89,    37,    87,     3,    99,     3,    46,    80,
      96,   102,    66,    28,    86,   135,    66,    66,    42,    66,
      42,    66,    42,    66,    44,    66,    91,    94,    66,    49,
      66,    88,    66,   100,    66,    81,    97,     3,    39,    47,
     131,     3,    31,    56,    57,    58,    59,    60,    61,   167,
      44,   105,   118,   115,   129,    42,    42,     3,     8,    38,
      39,    40,    41,    42,   141,   168,    18,    42,    18,   132,
     103,    47,    98,   136,   141,     3,   120,   125,   141,   167,
     125,   167,    66,    92,    95,   149,   155,     4,     5,     7,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    49,
     101,    82,    34,   133,   156,   157,    49,   102,   102,   132,
      66,    43,   127,    43,    49,     3,    43,     3,    45,   141,
     141,   141,   141,   142,   143,   144,   145,   146,   147,   148,
      13,   150,    14,   151,   152,   153,   154,   141,    48,   138,
     140,   167,    56,    57,    58,    59,    60,    61,   166,   141,
      44,    49,    45,    44,   132,    44,   121,    50,   126,    44,
      25,    43,    43,    43,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,    49,   139,    43,   138,
       3,   102,   102,   158,   106,   119,   125,   123,   132,   116,
      42,    93,    49,   140,    83,     3,    44,    48,   159,   168,
      66,    66,    49,   124,    66,   130,    49,    44,   164,   161,
      45,    48,    45,    45,   122,     3,    45,   125,    84,   159,
      44,   160,   107,   141,    43,    66,    45,   162,   159,    23,
      24,   108,    49,    45,   165,   159,    44,    42,    85,   159,
      45,   109,   110,   163,    66,   141,   159,    45,    43,   111,
      44,   112,    66,    45,   113,   108
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    65,    63,    63,    67,    66,    68,    66,
      69,    66,    70,    66,    71,    66,    72,    66,    73,    66,
      74,    66,    75,    66,    76,    66,    77,    66,    66,    78,
      79,    79,    81,    82,    83,    84,    85,    80,    86,    86,
      88,    87,    89,    91,    92,    93,    90,    94,    95,    90,
      97,    96,    98,    96,   100,   101,    99,   102,   103,   102,
     102,   105,   106,   107,   104,   109,   108,   110,   111,   112,
     113,   108,   108,   115,   116,   114,   118,   119,   117,   121,
     122,   120,   123,   124,   120,   125,   126,   125,   127,   125,
     125,   129,   130,   128,   131,   131,   133,   132,   132,   132,
     135,   136,   134,   137,   137,   137,   138,   139,   138,   138,
     140,   140,   140,   142,   141,   143,   141,   144,   141,   145,
     141,   146,   141,   147,   141,   148,   141,   149,   141,   150,
     141,   151,   141,   152,   141,   153,   141,   154,   141,   155,
     141,   141,   141,   141,   141,   156,   157,   158,   156,   160,
     159,   161,   162,   163,   159,   164,   165,   159,   159,   159,
     166,   166,   166,   166,   166,   166,   167,   167,   167,   167,
     167,   167,   167,   168,   168,   168,   168,   169,   169
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     6,     0,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       2,     2,     0,     0,     0,     0,     0,    12,     1,     0,
       0,     4,     2,     0,     0,     0,     8,     0,     0,     7,
       0,     4,     0,     5,     0,     0,     6,     4,     0,     4,
       0,     0,     0,     0,    11,     0,     5,     0,     0,     0,
       0,    12,     0,     0,     0,     9,     0,     0,     9,     0,
       0,     7,     0,     0,     6,     1,     0,     4,     0,     3,
       0,     0,     0,    11,     1,     1,     0,     3,     2,     0,
       0,     0,     6,     1,     1,     0,     2,     0,     3,     0,
       2,     3,     0,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     3,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     3,     3,     1,     1,     3,     0,     0,     5,     0,
       4,     0,     0,     0,     8,     0,     0,     6,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 82 "java2cpp.y"
                  { print_init(); }
#line 1717 "y.tab.c"
    break;

  case 3:
#line 82 "java2cpp.y"
                                                  {push_scope("global");printf("/* start Main Class */\n"); }
#line 1723 "y.tab.c"
    break;

  case 4:
#line 82 "java2cpp.y"
                                                                                                                              {pop_scope(); printf("\n/* end Main Class */\n"); exit(0); }
#line 1729 "y.tab.c"
    break;

  case 5:
#line 83 "java2cpp.y"
                                                { printf("\n"); exit(2); }
#line 1735 "y.tab.c"
    break;

  case 6:
#line 86 "java2cpp.y"
                  { print_tabs(); }
#line 1741 "y.tab.c"
    break;

  case 7:
#line 86 "java2cpp.y"
                                                           { }
#line 1747 "y.tab.c"
    break;

  case 8:
#line 87 "java2cpp.y"
                          { print_tabs(); }
#line 1753 "y.tab.c"
    break;

  case 9:
#line 87 "java2cpp.y"
                                                                               { }
#line 1759 "y.tab.c"
    break;

  case 10:
#line 88 "java2cpp.y"
                          { print_tabs(); }
#line 1765 "y.tab.c"
    break;

  case 11:
#line 88 "java2cpp.y"
                                                               { }
#line 1771 "y.tab.c"
    break;

  case 12:
#line 89 "java2cpp.y"
                          { print_tabs(); }
#line 1777 "y.tab.c"
    break;

  case 13:
#line 89 "java2cpp.y"
                                                                    { }
#line 1783 "y.tab.c"
    break;

  case 14:
#line 90 "java2cpp.y"
                          { print_tabs(); }
#line 1789 "y.tab.c"
    break;

  case 15:
#line 90 "java2cpp.y"
                                                                { }
#line 1795 "y.tab.c"
    break;

  case 16:
#line 91 "java2cpp.y"
                          { print_tabs(); }
#line 1801 "y.tab.c"
    break;

  case 17:
#line 91 "java2cpp.y"
                                                                  { }
#line 1807 "y.tab.c"
    break;

  case 18:
#line 92 "java2cpp.y"
                          { print_tabs(); }
#line 1813 "y.tab.c"
    break;

  case 19:
#line 92 "java2cpp.y"
                                                                     { }
#line 1819 "y.tab.c"
    break;

  case 20:
#line 93 "java2cpp.y"
                          { print_tabs(); }
#line 1825 "y.tab.c"
    break;

  case 21:
#line 93 "java2cpp.y"
                                                             { }
#line 1831 "y.tab.c"
    break;

  case 22:
#line 94 "java2cpp.y"
                          { print_tabs(); }
#line 1837 "y.tab.c"
    break;

  case 23:
#line 94 "java2cpp.y"
                                                                { }
#line 1843 "y.tab.c"
    break;

  case 24:
#line 95 "java2cpp.y"
                          { print_tabs(); }
#line 1849 "y.tab.c"
    break;

  case 25:
#line 95 "java2cpp.y"
                                                                 { }
#line 1855 "y.tab.c"
    break;

  case 26:
#line 96 "java2cpp.y"
                          { print_tabs(); }
#line 1861 "y.tab.c"
    break;

  case 27:
#line 96 "java2cpp.y"
                                                                       { }
#line 1867 "y.tab.c"
    break;

  case 28:
#line 97 "java2cpp.y"
                                { }
#line 1873 "y.tab.c"
    break;

  case 32:
#line 106 "java2cpp.y"
                {push_scope(yylval.var_name);printf("%s", yylval.var_name); }
#line 1879 "y.tab.c"
    break;

  case 33:
#line 106 "java2cpp.y"
                                                                                { printf("("); }
#line 1885 "y.tab.c"
    break;

  case 34:
#line 106 "java2cpp.y"
                                                                                                           { printf(")"); }
#line 1891 "y.tab.c"
    break;

  case 35:
#line 106 "java2cpp.y"
                                                                                                                                { tab_counter++; printf("{\n"); }
#line 1897 "y.tab.c"
    break;

  case 36:
#line 106 "java2cpp.y"
                                                                                                                                                                                { printf("}\n"); tab_counter--;pop_scope(); }
#line 1903 "y.tab.c"
    break;

  case 37:
#line 106 "java2cpp.y"
                                                                                                                                                                                                                                { }
#line 1909 "y.tab.c"
    break;

  case 40:
#line 112 "java2cpp.y"
                         { printf("return "); }
#line 1915 "y.tab.c"
    break;

  case 41:
#line 112 "java2cpp.y"
                                                                    { printf(";\n"); }
#line 1921 "y.tab.c"
    break;

  case 42:
#line 115 "java2cpp.y"
                                   { printf("break;\n"); }
#line 1927 "y.tab.c"
    break;

  case 43:
#line 118 "java2cpp.y"
                  { printf("std::cout"); }
#line 1933 "y.tab.c"
    break;

  case 44:
#line 118 "java2cpp.y"
                                              { printf(" << "); }
#line 1939 "y.tab.c"
    break;

  case 45:
#line 118 "java2cpp.y"
                                                                               { printf(" <<  std::endl"); }
#line 1945 "y.tab.c"
    break;

  case 46:
#line 118 "java2cpp.y"
                                                                                                                       { printf(";\n"); }
#line 1951 "y.tab.c"
    break;

  case 47:
#line 119 "java2cpp.y"
                        { printf("std::cout"); }
#line 1957 "y.tab.c"
    break;

  case 48:
#line 119 "java2cpp.y"
                                                    { printf(" << "); }
#line 1963 "y.tab.c"
    break;

  case 49:
#line 119 "java2cpp.y"
                                                                                               { printf(";\n"); }
#line 1969 "y.tab.c"
    break;

  case 50:
#line 122 "java2cpp.y"
                        {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); }
#line 1975 "y.tab.c"
    break;

  case 51:
#line 122 "java2cpp.y"
                                                                                                                                       { printf(";\n"); }
#line 1981 "y.tab.c"
    break;

  case 52:
#line 123 "java2cpp.y"
                                                      {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); }
#line 1987 "y.tab.c"
    break;

  case 53:
#line 123 "java2cpp.y"
                                                                                                                                                                    { printf(";\n"); }
#line 1993 "y.tab.c"
    break;

  case 54:
#line 126 "java2cpp.y"
                      {printf("%s", yylval.var_name);verify_scope(yylval.var_name);  }
#line 1999 "y.tab.c"
    break;

  case 55:
#line 126 "java2cpp.y"
                                                                                                  { printf(" = "); }
#line 2005 "y.tab.c"
    break;

  case 56:
#line 126 "java2cpp.y"
                                                                                                                                         { printf(";\n"); }
#line 2011 "y.tab.c"
    break;

  case 58:
#line 130 "java2cpp.y"
                                  { bracket_counter++; }
#line 2017 "y.tab.c"
    break;

  case 61:
#line 134 "java2cpp.y"
                        { printf("if (");create_scope_name_and_push_it(); }
#line 2023 "y.tab.c"
    break;

  case 62:
#line 134 "java2cpp.y"
                                                                                            { tab_counter++; printf(") {\n"); }
#line 2029 "y.tab.c"
    break;

  case 63:
#line 134 "java2cpp.y"
                                                                                                                                              { pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2035 "y.tab.c"
    break;

  case 65:
#line 137 "java2cpp.y"
                          {create_scope_name_and_push_it(); tab_counter++; printf(" else {\n"); }
#line 2041 "y.tab.c"
    break;

  case 66:
#line 137 "java2cpp.y"
                                                                                                                {pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2047 "y.tab.c"
    break;

  case 67:
#line 138 "java2cpp.y"
                                            { printf(" else if ("); }
#line 2053 "y.tab.c"
    break;

  case 68:
#line 138 "java2cpp.y"
                                                                                   { printf(")"); }
#line 2059 "y.tab.c"
    break;

  case 69:
#line 138 "java2cpp.y"
                                                                                                       {create_scope_name_and_push_it();tab_counter++; printf(") {\n"); }
#line 2065 "y.tab.c"
    break;

  case 70:
#line 138 "java2cpp.y"
                                                                                                                                                                                        { pop_scope();tab_counter--;print_tabs(); printf("}"); }
#line 2071 "y.tab.c"
    break;

  case 72:
#line 139 "java2cpp.y"
                                        { printf("\n"); }
#line 2077 "y.tab.c"
    break;

  case 73:
#line 142 "java2cpp.y"
                           {create_scope_name_and_push_it();printf("while ("); }
#line 2083 "y.tab.c"
    break;

  case 74:
#line 142 "java2cpp.y"
                                                                                                 { tab_counter++; printf("){\n"); }
#line 2089 "y.tab.c"
    break;

  case 75:
#line 142 "java2cpp.y"
                                                                                                                                                  {pop_scope();tab_counter--; print_tabs(); printf("}\n"); }
#line 2095 "y.tab.c"
    break;

  case 76:
#line 146 "java2cpp.y"
                         {create_scope_name_and_push_it(); printf("for ("); }
#line 2101 "y.tab.c"
    break;

  case 77:
#line 146 "java2cpp.y"
                                                                                               { tab_counter++; printf(") {\n"); }
#line 2107 "y.tab.c"
    break;

  case 78:
#line 146 "java2cpp.y"
                                                                                                                                                 {pop_scope(); tab_counter--; print_tabs(); printf("}\n"); }
#line 2113 "y.tab.c"
    break;

  case 79:
#line 149 "java2cpp.y"
                                      { printf("; "); }
#line 2119 "y.tab.c"
    break;

  case 80:
#line 149 "java2cpp.y"
                                                                            { printf("; "); }
#line 2125 "y.tab.c"
    break;

  case 82:
#line 150 "java2cpp.y"
                                         { printf("%s", yylval.var_name); }
#line 2131 "y.tab.c"
    break;

  case 83:
#line 150 "java2cpp.y"
                                                                            { printf(" : "); }
#line 2137 "y.tab.c"
    break;

  case 84:
#line 150 "java2cpp.y"
                                                                                                   { printf("%s", yylval.var_name); }
#line 2143 "y.tab.c"
    break;

  case 86:
#line 154 "java2cpp.y"
                                   {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); }
#line 2149 "y.tab.c"
    break;

  case 88:
#line 155 "java2cpp.y"
                              {verify_scope(yylval.var_name);printf("%s", yylval.var_name); }
#line 2155 "y.tab.c"
    break;

  case 90:
#line 156 "java2cpp.y"
                                 { }
#line 2161 "y.tab.c"
    break;

  case 91:
#line 159 "java2cpp.y"
                        { printf("do{\n"); tab_counter++;}
#line 2167 "y.tab.c"
    break;

  case 92:
#line 159 "java2cpp.y"
                                                                                  {tab_counter--; print_tabs(); printf("}while("); }
#line 2173 "y.tab.c"
    break;

  case 93:
#line 159 "java2cpp.y"
                                                                                                                                                            { printf(");"); }
#line 2179 "y.tab.c"
    break;

  case 94:
#line 163 "java2cpp.y"
                           { printf("[%s]", yylval.var_name); }
#line 2185 "y.tab.c"
    break;

  case 95:
#line 164 "java2cpp.y"
                              { printf("[%s]", yylval.var_name); }
#line 2191 "y.tab.c"
    break;

  case 96:
#line 167 "java2cpp.y"
                             { printf(" = "); }
#line 2197 "y.tab.c"
    break;

  case 99:
#line 169 "java2cpp.y"
                                                      {}
#line 2203 "y.tab.c"
    break;

  case 100:
#line 172 "java2cpp.y"
                                      { push_scope("main");printf("int main(int argc, char **argv)"); }
#line 2209 "y.tab.c"
    break;

  case 101:
#line 172 "java2cpp.y"
                                                                                                           { tab_counter++; printf("{\n"); }
#line 2215 "y.tab.c"
    break;

  case 102:
#line 172 "java2cpp.y"
                                                                                                                                                           { printf("\n}\n"); tab_counter--; pop_scope();}
#line 2221 "y.tab.c"
    break;

  case 107:
#line 183 "java2cpp.y"
                       { printf(","); }
#line 2227 "y.tab.c"
    break;

  case 109:
#line 184 "java2cpp.y"
                                                { printf(" "); }
#line 2233 "y.tab.c"
    break;

  case 110:
#line 188 "java2cpp.y"
                           {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); }
#line 2239 "y.tab.c"
    break;

  case 111:
#line 189 "java2cpp.y"
                                                  {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name);printf("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--)printf("[%d]",DIMENSION);}
#line 2245 "y.tab.c"
    break;

  case 113:
#line 193 "java2cpp.y"
                                 { printf("&&"); }
#line 2251 "y.tab.c"
    break;

  case 115:
#line 194 "java2cpp.y"
                                        { printf("||"); }
#line 2257 "y.tab.c"
    break;

  case 117:
#line 195 "java2cpp.y"
                                        { printf("<="); }
#line 2263 "y.tab.c"
    break;

  case 119:
#line 196 "java2cpp.y"
                                       { printf(">"); }
#line 2269 "y.tab.c"
    break;

  case 121:
#line 197 "java2cpp.y"
                                       { printf("<"); }
#line 2275 "y.tab.c"
    break;

  case 123:
#line 198 "java2cpp.y"
                                        { printf("!="); }
#line 2281 "y.tab.c"
    break;

  case 125:
#line 199 "java2cpp.y"
                                        { printf("=="); }
#line 2287 "y.tab.c"
    break;

  case 127:
#line 200 "java2cpp.y"
                              { printf("!"); }
#line 2293 "y.tab.c"
    break;

  case 129:
#line 201 "java2cpp.y"
                                         { printf("+"); }
#line 2299 "y.tab.c"
    break;

  case 131:
#line 202 "java2cpp.y"
                                          { printf("-"); }
#line 2305 "y.tab.c"
    break;

  case 133:
#line 203 "java2cpp.y"
                                        { printf("*"); }
#line 2311 "y.tab.c"
    break;

  case 135:
#line 204 "java2cpp.y"
                                        { printf("/"); }
#line 2317 "y.tab.c"
    break;

  case 137:
#line 205 "java2cpp.y"
                                        { printf("%%"); }
#line 2323 "y.tab.c"
    break;

  case 139:
#line 206 "java2cpp.y"
                             { printf("("); }
#line 2329 "y.tab.c"
    break;

  case 140:
#line 206 "java2cpp.y"
                                                           { printf(")"); }
#line 2335 "y.tab.c"
    break;

  case 141:
#line 207 "java2cpp.y"
                                              { printf("++"); }
#line 2341 "y.tab.c"
    break;

  case 142:
#line 208 "java2cpp.y"
                                                { printf("--"); }
#line 2347 "y.tab.c"
    break;

  case 144:
#line 210 "java2cpp.y"
                              { printf("%s", yylval.var_name); verify_scope(yylval.var_name);}
#line 2353 "y.tab.c"
    break;

  case 145:
#line 213 "java2cpp.y"
                                                  {bracket_counter=0;}
#line 2359 "y.tab.c"
    break;

  case 146:
#line 214 "java2cpp.y"
                                  { for(;bracket_counter>0;bracket_counter--)printf("[]"); }
#line 2365 "y.tab.c"
    break;

  case 147:
#line 214 "java2cpp.y"
                                                                                                { printf(" = {"); }
#line 2371 "y.tab.c"
    break;

  case 148:
#line 214 "java2cpp.y"
                                                                                                                                                  { printf("}"); }
#line 2377 "y.tab.c"
    break;

  case 149:
#line 217 "java2cpp.y"
                                                { printf(","); }
#line 2383 "y.tab.c"
    break;

  case 151:
#line 218 "java2cpp.y"
                                                               { printf(","); }
#line 2389 "y.tab.c"
    break;

  case 152:
#line 218 "java2cpp.y"
                                                                                   { printf("{"); }
#line 2395 "y.tab.c"
    break;

  case 153:
#line 218 "java2cpp.y"
                                                                                                                                  { printf("}"); }
#line 2401 "y.tab.c"
    break;

  case 155:
#line 219 "java2cpp.y"
                                                              { printf("{"); }
#line 2407 "y.tab.c"
    break;

  case 156:
#line 219 "java2cpp.y"
                                                                                                             { printf("}"); }
#line 2413 "y.tab.c"
    break;

  case 166:
#line 232 "java2cpp.y"
              { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type);	printf("int "); }
#line 2419 "y.tab.c"
    break;

  case 167:
#line 233 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("char "); }
#line 2425 "y.tab.c"
    break;

  case 168:
#line 234 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("float "); }
#line 2431 "y.tab.c"
    break;

  case 169:
#line 235 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("double "); }
#line 2437 "y.tab.c"
    break;

  case 170:
#line 236 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("string "); }
#line 2443 "y.tab.c"
    break;

  case 171:
#line 237 "java2cpp.y"
                          { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("bool "); }
#line 2449 "y.tab.c"
    break;

  case 172:
#line 238 "java2cpp.y"
                       { printf("void "); }
#line 2455 "y.tab.c"
    break;

  case 173:
#line 241 "java2cpp.y"
                         { printf("%s", yylval.var_name); }
#line 2461 "y.tab.c"
    break;

  case 174:
#line 242 "java2cpp.y"
                                      { printf("%s", yylval.var_name); }
#line 2467 "y.tab.c"
    break;

  case 175:
#line 243 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2473 "y.tab.c"
    break;

  case 176:
#line 244 "java2cpp.y"
                                   { printf("%s", yylval.var_name); }
#line 2479 "y.tab.c"
    break;

  case 177:
#line 247 "java2cpp.y"
                                { printf("%s\n", yylval.var_name); }
#line 2485 "y.tab.c"
    break;

  case 178:
#line 248 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2491 "y.tab.c"
    break;


#line 2495 "y.tab.c"

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
#line 252 "java2cpp.y"


#include "lex.yy.c"
void print_table_symbols(){
		printf("\n");
		for(int i=0; i<table_idx; i++)
		{	
			printf("%d var=%s Scope=%s type=%d\n",i,sym[i].var_name,sym[i].scope_name,sym[i].type);			
		}
}
void verify_scope(char var[MAX_NAME_LEN]){
	int found= 0;
	//Look in the table if var was declare in the current Scope
	//If not look on the parent scope and so on
	for(int j=stack_scope_counter;j>=0;j--)
	for(int i=0; i<table_idx; i++)
	{	
		if(strcmp(sym[i].var_name, var)==0 &&
		 strcmp(sym[i].scope_name, stack_scope[j])==0 ){
			found=1;
			break;}
	}

	if(!found){
		printf("\nVariable %s was not declared in the scope %s \n",var,stack_scope[stack_scope_counter]);
		print_table_symbols();
		yyerror("");
		exit(0);

	}
}
int lookup_in_table(char var[MAX_NAME_LEN])
{
	for(int i=0; i<table_idx; i++)
	{	
		if(strcmp(sym[i].var_name, var)==0 &&
		 strcmp(sym[i].scope_name, stack_scope[stack_scope_counter])==0 )
			return sym[i].type;
	}
	return -1;
}

void insert_to_table(char var[MAX_NAME_LEN], int type)
{	
	if(lookup_in_table(var)==-1)
	{
		strcpy(sym[table_idx].var_name,var);
		strcpy(sym[table_idx].scope_name, stack_scope[stack_scope_counter]);
		sym[table_idx].type = type;
		table_idx++;
	}
	else {
		printf("\nMultiple declaration of variable %s \n",var);
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
void create_scope_name_and_push_it(){
	static int id_special_block=0;

	char buff[20]; 
	 snprintf(buff,20, "%s_%d","es_scope", id_special_block++); 
	 push_scope(buff);
	
}

void push_scope(char var[MAX_NAME_LEN] ){
	if(stack_scope_counter == MAX_SCOPE){
	printf("SCOPE STACK IS FULL");
		yyerror("");
		exit(0);
	}
	strcpy(stack_scope[++stack_scope_counter],var);
}
void pop_scope(){
	--stack_scope_counter;
}
