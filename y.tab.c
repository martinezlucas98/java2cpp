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
	#include"type_conversion.h"
	#define YYDEBUG 0
	#define MAX_NAME_LEN 32
	#define MAX_VARIABLES 32
	#define MAX_DECL_FUN 32
	#define MAX_SCOPE 32
	#define DIMENSION 20
	#define INTNOVAL -2
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
	int current_param_count=0;
	char for_var[MAX_NAME_LEN];
	char stack_scope[MAX_SCOPE][MAX_VARIABLES];
	int stack_scope_counter=-1;
	int table_idf=0;
	struct symbol_table{char var_name[MAX_NAME_LEN]; int type;char scope_name[MAX_NAME_LEN];} sym[MAX_VARIABLES];
	struct fun_table{char var_name[MAX_NAME_LEN]; int type; int type_params[MAX_VARIABLES];int counter_type_params;int is_def;} fun[MAX_DECL_FUN];
	extern int lookup_in_table(char var[MAX_NAME_LEN]);
	int verify_scope(char var[MAX_NAME_LEN]); // When a variable is used look first if it was declared before
	extern void insert_to_table(char var[MAX_NAME_LEN], int type);
	extern void insert_funtion(char var[MAX_NAME_LEN], int type,int def);
	extern void insert_type_param(int type); // Insert the type of the current parameter or argument(literal) of the current function in the table
	extern void insert_argument_var(char var[MAX_NAME_LEN]);// Insert the type of the rgument( not literal) of the current function in the table. Also check scope the variable
	extern void push_scope(char var[MAX_NAME_LEN]);// Add to the stack the name of the current scope
	extern void create_scope_name_and_push_it();//Create unique name for loops and conditional statment
	extern void pop_scope();
	extern void print_tabs();
	extern void check_syntax_errors();
	extern void print_table_symbols();
	extern void print_type_error_warning();
	extern void clear_exp_vect(char c);
	extern void add_exp_vect(char type);
	extern void type_verification();
	extern void add_exp_vect_var(char type);
    extern int lookup_in_table_alt(char var[MAX_NAME_LEN]);
	char var_list[MAX_VARIABLES][MAX_NAME_LEN];	// MAX_VARIABLES variable names with each variable being atmost MAX_NAME_LEN characters long
	int string_or_var[MAX_VARIABLES];
	//extern int *yytext;
	char syntax_errors[256] = "";

	// type check variables
	char type_cast_str_warning[256] = "";
	char type_cast_str_error[256] = "";
	int right_val_type=INTNOVAL;
	int left_val_type=INTNOVAL;
	#define EVLEN 256
	char expression_vect[EVLEN+1];
	int evtop = 0;
	int type_verified = 0;


	// functions
	void print_init(){
		time_t t = time(NULL);
  		struct tm now = *localtime(&t);
		char *version = "alpha 1.0";
		char *github = "https://github.com/martinezlucas98/java2cpp";

		printf("/*\n*\t===================================================================\n");
		printf("*\tTranslated from java to c++ using java2cpp\n");
		printf("*\tVersion: %s\n", version);
		printf("*\tGithub: %s\n", github);
		printf("*\tTranslated on: %d-%02d-%02d %02d:%02d:%02d (yyyy-MM-dd hh:mm:ss)\n", now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
		printf("*\t===================================================================\n*/\n\n");
		printf("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n");
	}


#line 152 "y.tab.c"

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
    SCANNER = 293,
    SYS_IN = 294,
    BOOL_VAL = 295,
    NUMBER = 296,
    QUOTED_STRING = 297,
    QUOTED_CHAR = 298,
    LP = 299,
    RP = 300,
    LC = 301,
    RC = 302,
    LB = 303,
    RB = 304,
    COMA = 305,
    SEMICOLON = 306,
    COLON = 307,
    QM = 308,
    SQ = 309,
    DQ = 310,
    ILCOMMENT = 311,
    MLCOMMENT = 312,
    INT = 313,
    CHAR = 314,
    FLOAT = 315,
    DOUBLE = 316,
    STRING = 317,
    BOOLEAN = 318
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
#define SCANNER 293
#define SYS_IN 294
#define BOOL_VAL 295
#define NUMBER 296
#define QUOTED_STRING 297
#define QUOTED_CHAR 298
#define LP 299
#define RP 300
#define LC 301
#define RC 302
#define LB 303
#define RB 304
#define COMA 305
#define SEMICOLON 306
#define COLON 307
#define QM 308
#define SQ 309
#define DQ 310
#define ILCOMMENT 311
#define MLCOMMENT 312
#define INT 313
#define CHAR 314
#define FLOAT 315
#define DOUBLE 316
#define STRING 317
#define BOOLEAN 318

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "java2cpp.y"

int data_type;
char var_name[MAX_NAME_LEN];

#line 332 "y.tab.c"

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
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  133
/* YYNRULES -- Number of rules.  */
#define YYNRULES  222
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  364

#define YYUNDEFTOK  2
#define YYMAXUTOK   318


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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   111,   111,   112,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   126,   127,   130,
     132,   133,   136,   136,   136,   136,   136,   136,   138,   139,
     142,   142,   145,   145,   148,   148,   148,   148,   149,   149,
     149,   150,   151,   155,   155,   155,   155,   155,   159,   159,
     159,   162,   162,   163,   163,   166,   166,   166,   166,   167,
     167,   167,   167,   170,   171,   171,   172,   176,   176,   176,
     176,   179,   179,   180,   180,   180,   180,   180,   181,   184,
     184,   184,   189,   189,   189,   192,   193,   193,   193,   196,
     197,   197,   198,   198,   199,   202,   202,   202,   202,   206,
     207,   210,   210,   211,   212,   215,   215,   215,   220,   221,
     222,   225,   226,   226,   227,   229,   229,   229,   230,   231,
     231,   231,   232,   233,   236,   237,   238,   241,   241,   242,
     242,   243,   243,   244,   244,   245,   245,   246,   246,   247,
     247,   248,   248,   249,   249,   250,   250,   251,   251,   252,
     252,   253,   253,   254,   254,   255,   255,   256,   257,   258,
     259,   262,   263,   263,   263,   266,   266,   267,   267,   267,
     267,   268,   268,   268,   269,   270,   273,   274,   275,   276,
     277,   278,   281,   282,   283,   284,   285,   286,   287,   290,
     291,   292,   293,   295,   296,   297,   298,   301,   302,   305,
     306,   309,   310,   313,   314,   317,   318,   321,   322,   322,
     323,   323,   324
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
  "PRINTLN", "PRINT", "NEW", "DO", "BREAK", "RETURN", "SCANNER", "SYS_IN",
  "BOOL_VAL", "NUMBER", "QUOTED_STRING", "QUOTED_CHAR", "LP", "RP", "LC",
  "RC", "LB", "RB", "COMA", "SEMICOLON", "COLON", "QM", "SQ", "DQ",
  "ILCOMMENT", "MLCOMMENT", "INT", "CHAR", "FLOAT", "DOUBLE", "STRING",
  "BOOLEAN", "$accept", "program", "$@1", "$@2", "STATEMENTS", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "IGNORE_SCOPE", "DECLARATION", "METHODS", "$@13", "$@14", "$@15", "$@16",
  "$@17", "IS_STATIC", "RETURN_ST", "$@18", "BREAK_ST", "$@19", "STDIO",
  "$@20", "$@21", "$@22", "$@23", "$@24", "SCANNER_OBJECT", "$@25", "$@26",
  "$@27", "$@28", "MY_INPUT", "$@29", "$@30", "VAR_DECLARATION", "$@31",
  "$@32", "VAR_ASSIGNATION", "$@33", "$@34", "$@35", "$@36", "$@37",
  "$@38", "BRACKET_ARRAY", "$@39", "IF_STATEMENT", "$@40", "$@41", "$@42",
  "ELSE_VARIATIONS", "$@43", "$@44", "$@45", "$@46", "$@47", "WHILE_LOOP",
  "$@48", "$@49", "FOR_LOOP", "$@50", "$@51", "FOR_PARAMS", "$@52", "$@53",
  "DECL_EXPR", "$@54", "$@55", "DO_WHILE_LOOP", "$@56", "$@57", "$@58",
  "NUMARRAY", "HAS_ASSIGNMENT", "$@59", "MAIN_METHOD_DECLARATION", "$@60",
  "$@61", "SCOPE", "PARAMS", "$@62", "PARAMS_TYPE", "$@63", "$@64", "$@65",
  "$@66", "HAS_PARAMS", "EXPRESION", "$@67", "$@68", "$@69", "$@70",
  "$@71", "$@72", "$@73", "$@74", "$@75", "$@76", "$@77", "$@78", "$@79",
  "$@80", "$@81", "EXPRESION_ARRAY", "$@82", "$@83",
  "EXPRESION_ARRAY_INITIALIZE", "$@84", "$@85", "$@86", "$@87", "$@88",
  "$@89", "TYPE_NO_PRINT", "TYPE", "TERMINAL", "LITERAL_ARGUMENT",
  "COMMENT", "HAS_COMMENT", "DELIMITER", "MUST_SEMICOLON",
  "SEMICOLON_NOT_COMA", "MUST_EXPRESSION", "$@90", "$@91", YY_NULLPTR
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
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF (-282)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      34,    38,   -31,  -282,  -282,  -282,  -282,    30,     7,  -282,
     191,   -23,    12,    14,    11,    39,   -31,    46,    45,    47,
      44,    73,    37,    43,   191,  -282,  -282,   191,    65,    31,
     -31,  -282,  -282,     6,   191,    59,  -282,   191,   191,    48,
     191,    49,   191,    50,   191,    56,   191,    77,  -282,  -282,
    -282,   191,  -282,  -282,  -282,   191,  -282,   191,  -282,  -282,
    -282,  -282,  -282,    63,     8,  -282,  -282,   106,  -282,  -282,
     260,    64,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,    79,    78,    84,   126,  -282,    89,  -282,    57,
    -282,    83,    75,    86,   131,  -282,  -282,  -282,   101,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,    83,
     111,   111,   191,   122,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,   174,  -282,   145,   343,
    -282,   119,  -282,  -282,  -282,  -282,   120,   123,  -282,   -11,
      89,   127,   127,   131,   191,   132,    -6,   137,    -4,   358,
     173,   148,   192,   149,  -282,    57,    57,   179,    57,    57,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   185,   187,
    -282,  -282,  -282,  -282,  -282,  -282,    89,   152,  -282,   153,
     283,   267,    83,  -282,   158,  -282,  -282,  -282,    89,   159,
     161,   131,   163,  -282,  -282,   111,   147,   164,  -282,   189,
     168,   258,   272,   184,  -282,   295,    57,    57,    57,    57,
      57,    57,    57,    57,  -282,    57,  -282,    57,    57,    57,
      57,    57,    57,  -282,  -282,    89,  -282,  -282,   188,   283,
      18,  -282,  -282,  -282,  -282,  -282,  -282,   127,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,    -4,  -282,   131,  -282,   186,
     193,  -282,    89,   196,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,   358,   358,
      75,  -282,    75,   260,  -282,  -282,  -282,   232,  -282,   116,
     191,   191,    57,  -282,  -282,   191,  -282,   194,    89,  -282,
    -282,  -282,  -282,  -282,   190,  -282,  -282,  -282,   195,   205,
     197,   198,   358,   234,   199,   111,  -282,  -282,   214,  -282,
     116,   213,  -282,  -282,  -282,  -282,  -282,  -282,   215,   229,
     201,   191,   219,  -282,   116,    40,  -282,  -282,   245,   246,
    -282,   116,  -282,   248,   251,  -282,    89,  -282,  -282,   116,
     249,  -282,  -282,  -282,   241,  -282,  -282,  -282,   191,    83,
    -282,   116,   266,   253,  -282,  -282,  -282,   269,  -282,   191,
     284,  -282,    40,  -282
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   210,     1,   207,   208,   209,     0,     0,     3,
       0,     0,    65,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   211,     0,     0,     0,
     210,   118,   119,     0,     0,    39,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    44,    48,
      53,     0,    51,    52,    42,     0,    40,     0,    26,    27,
      66,    70,     4,    61,     0,    30,    31,     0,     7,    38,
       0,     0,     9,    11,    77,    13,    92,    15,    89,    17,
     105,    19,     0,     0,     0,     0,    21,   214,    23,     0,
      25,   222,   133,     0,   114,   110,   109,    74,     0,    63,
     198,   192,   193,   194,   195,   196,   197,    29,   116,   222,
     104,   104,     0,     0,    45,    49,    54,   213,    43,   170,
     153,   202,   199,   201,   200,   165,   214,   169,   170,   217,
      67,   125,   206,   203,   205,   204,     0,   129,    33,   111,
     214,    76,    76,   114,     0,     0,   170,     0,     0,    99,
       0,     0,     0,     0,    58,     0,     0,     0,     0,     0,
     137,   139,   143,   141,   145,   147,   149,   151,   155,   157,
     159,   161,   163,    41,   218,   220,   214,     0,    71,     0,
     124,     0,   222,   113,     0,    62,    75,    73,   214,     0,
       0,   114,     0,   216,   215,   104,   100,     0,   100,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   167,     0,   168,     0,     0,     0,
       0,     0,     0,    68,   126,   214,   130,   122,     0,   124,
       0,   186,   187,   188,   189,   190,   191,    76,   112,   173,
      64,   117,    78,   103,    93,     0,    96,   114,    90,     0,
       0,    46,   214,     0,   166,   138,   140,   144,   142,   146,
     148,   150,   152,   156,   158,   160,   162,   164,   219,   221,
     133,    72,   133,   136,    34,   121,   134,     0,   171,   185,
       0,     0,     0,    97,   101,     0,   106,     0,   214,    50,
      55,   127,   131,   123,     0,   135,   181,   177,     0,   184,
       0,     0,    95,     0,     0,   104,    59,    47,     0,    35,
     185,     0,   174,   175,    79,    94,    98,    91,     0,     0,
       0,     0,     0,   178,   185,    88,   107,    60,     0,     0,
     182,   185,   176,     0,     0,    80,   214,    56,    36,   185,
       0,    81,    83,   108,     0,    37,   183,   179,     0,   222,
      57,   185,     0,     0,   180,    82,    84,     0,    85,     0,
       0,    86,    88,    87
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,  -282,  -282,   -24,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -134,  -282,  -282,  -282,  -282,  -282,  -119,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -105,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -139,  -282,  -282,  -282,  -282,  -282,    87,  -282,  -240,
    -282,  -282,  -282,  -282,    61,   -74,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -281,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,   -68,  -262,  -282,   316,   306,  -282,  -121,    92,
    -108,  -282,  -282
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    33,    34,    65,    93,   180,
     294,   321,   345,    70,    57,    89,    55,    87,    51,    83,
     155,   288,    84,   156,    52,    85,   157,   308,   344,    53,
     200,   319,    66,    94,   143,    24,    28,    91,   176,    29,
      92,   225,    67,   141,    40,   109,   280,   325,   335,   348,
     349,   357,   359,   362,    44,   111,   285,    42,   110,   281,
     147,   283,   303,   148,   247,   191,    46,   112,   305,   336,
      98,   140,   182,    37,    71,   144,    35,   228,   273,   136,
     177,   270,   179,   272,   229,   129,   206,   207,   209,   208,
     210,   211,   212,   213,   158,   215,   217,   218,   219,   220,
     159,   183,   184,   279,   298,   324,   311,   331,   351,   310,
     339,   237,   152,   127,   137,     6,     7,    27,   118,   195,
     130,   221,   222
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,   145,   107,    59,   188,   173,   151,   186,   187,    63,
      68,    95,  -102,    72,    73,   126,    75,   299,    77,   185,
      79,   276,    81,   181,    25,     4,     5,    86,    26,   322,
     291,    88,   292,    90,    -5,  -172,   149,   149,     3,  -102,
      31,    32,   150,   332,  -102,  -102,   193,   194,   299,    96,
     340,     8,   243,     9,    64,   223,   -69,    97,   346,    36,
     119,    30,   299,   333,   334,   120,    64,   240,    39,   299,
     354,    41,    43,    54,   238,    61,    47,   299,   131,    45,
      56,   201,   202,    60,   204,   205,   128,    69,   153,   299,
     245,   120,    74,    76,    78,    82,   277,   121,   122,   123,
     124,   125,    80,   278,   271,    48,    49,   -32,   284,    99,
     108,    50,   230,   113,   146,   132,   133,   134,   135,   120,
     189,   149,   114,   121,   122,   123,   124,   125,   115,   116,
     138,   289,   255,   256,   257,   258,   259,   260,   261,   262,
     117,   263,   100,   264,   265,   266,   267,   268,   269,   139,
     142,   121,   122,   123,   124,   125,   121,   122,   123,   124,
     154,   230,   296,   174,  -128,   178,   297,   307,  -132,   101,
     102,   103,   104,   105,   106,    64,   196,   190,   160,   161,
     162,   163,   192,   164,   165,   166,   167,   168,   169,   170,
     171,   172,    11,   197,    12,   198,   199,   203,   214,   246,
     318,   216,   224,   226,   239,   230,   241,   242,   302,   244,
     248,    -8,   250,   -12,   249,   343,   -16,   -14,   253,    -6,
      -6,    -6,    -6,   -20,   -20,   117,   -18,   -22,   -24,   -20,
     286,   149,   287,   274,   290,   295,   309,   316,   -28,   306,
     328,   353,   312,   363,   314,   315,   317,   -10,   -10,    -6,
      -6,    -6,    -6,    -6,    -6,   313,   300,   301,   320,   323,
     326,   304,   160,   161,   162,   163,   330,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   160,   161,   162,   163,
     327,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     337,   100,   350,   338,   341,   342,   347,   329,   356,   160,
     161,   162,   163,   251,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   355,   100,   358,   275,   252,   101,   102,
     103,   104,   105,   106,   352,   231,   232,   233,   234,   235,
     236,   361,    38,   227,   293,   360,    62,   282,     0,     0,
     254,   101,   102,   103,   104,   105,   106,   160,   161,   162,
     163,     0,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   175,   160,   161,   162,   163,     0,   164,   165,   166,
     167,   168,   169,   170,   171,   172
};

static const yytype_int16 yycheck[] =
{
      24,   109,    70,    27,   143,   126,   111,   141,   142,     3,
      34,     3,    18,    37,    38,    89,    40,   279,    42,   140,
      44,     3,    46,    34,    47,    56,    57,    51,    51,   310,
     270,    55,   272,    57,     0,    46,   110,   111,     0,    45,
      29,    30,   110,   324,    50,    51,    50,    51,   310,    41,
     331,    21,   191,    46,    48,   176,    44,    49,   339,    20,
       3,    47,   324,    23,    24,     8,    48,   188,    22,   331,
     351,    26,    25,    36,   182,    44,     3,   339,     3,    35,
      37,   155,   156,    18,   158,   159,     3,    28,   112,   351,
     195,     8,    44,    44,    44,    18,   230,    40,    41,    42,
      43,    44,    46,   237,   225,    32,    33,    44,   247,     3,
      46,    38,   180,    34,     3,    40,    41,    42,    43,     8,
     144,   195,    44,    40,    41,    42,    43,    44,    44,     3,
      44,   252,   206,   207,   208,   209,   210,   211,   212,   213,
      51,   215,    31,   217,   218,   219,   220,   221,   222,    18,
      49,    40,    41,    42,    43,    44,    40,    41,    42,    43,
      38,   229,    46,    18,    45,    45,    50,   288,    45,    58,
      59,    60,    61,    62,    63,    48,     3,    45,     4,     5,
       6,     7,    45,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     1,    45,     3,     3,    47,    18,    13,    52,
     305,    14,    50,    50,    46,   273,    47,    46,   282,    46,
      46,    20,    44,    22,    25,   336,    25,    26,    34,    28,
      29,    30,    31,    32,    33,    51,    35,    36,    37,    38,
      44,   305,    39,    45,    38,     3,    46,     3,    47,    45,
      39,   349,    47,   362,    47,    47,    47,    56,    57,    58,
      59,    60,    61,    62,    63,    50,   280,   281,    44,    46,
      45,   285,     4,     5,     6,     7,    47,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     4,     5,     6,     7,
      51,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      45,    31,    51,    47,    46,    44,    47,   321,    45,     4,
       5,     6,     7,    45,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    47,    31,    46,   229,    45,    58,    59,
      60,    61,    62,    63,   348,    58,    59,    60,    61,    62,
      63,    47,    16,    50,   273,   359,    30,   245,    -1,    -1,
      45,    58,    59,    60,    61,    62,    63,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,     0,    56,    57,   189,   190,    21,    46,
      67,     1,     3,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   109,    47,    51,   191,   110,   113,
      47,    29,    30,    79,    80,   150,    20,   147,   189,    22,
     118,    26,   131,    25,   128,    35,   140,     3,    32,    33,
      38,    92,    98,   103,    36,    90,    37,    88,    68,    68,
      18,    44,   190,     3,    48,    81,   106,   116,    68,    28,
      87,   148,    68,    68,    44,    68,    44,    68,    44,    68,
      46,    68,    18,    93,    96,    99,    68,    91,    68,    89,
      68,   111,   114,    82,   107,     3,    41,    49,   144,     3,
      31,    58,    59,    60,    61,    62,    63,   186,    46,   119,
     132,   129,   141,    34,    44,    44,     3,    51,   192,     3,
       8,    40,    41,    42,    43,    44,   159,   187,     3,   159,
     194,     3,    40,    41,    42,    43,   153,   188,    44,    18,
     145,   117,    49,   108,   149,   194,     3,   134,   137,   159,
     186,   137,   186,    68,    38,    94,    97,   100,   168,   174,
       4,     5,     6,     7,     9,    10,    11,    12,    13,    14,
      15,    16,    17,   192,    18,    18,   112,   154,    45,   156,
      83,    34,   146,   175,   176,   192,   116,   116,   145,    68,
      45,   139,    45,    50,    51,   193,     3,    45,     3,    47,
     104,   159,   159,    18,   159,   159,   160,   161,   163,   162,
     164,   165,   166,   167,    13,   169,    14,   170,   171,   172,
     173,   195,   196,   192,    50,   115,    50,    50,   151,   158,
     186,    58,    59,    60,    61,    62,    63,   185,   194,    46,
     192,    47,    46,   145,    46,   137,    52,   138,    46,    25,
      44,    45,    45,    34,    45,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     155,   192,   157,   152,    45,   151,     3,   116,   116,   177,
     120,   133,   193,   135,   145,   130,    44,    39,    95,   192,
      38,   153,   153,   158,    84,     3,    46,    50,   178,   187,
      68,    68,   159,   136,    68,   142,    45,   192,   101,    46,
     183,   180,    47,    50,    47,    47,     3,    47,   137,   105,
      44,    85,   178,    46,   179,   121,    45,    51,    39,    68,
      47,   181,   178,    23,    24,   122,   143,    45,    47,   184,
     178,    46,    44,   192,   102,    86,   178,    47,   123,   124,
      51,   182,    68,   194,   178,    47,    45,   125,    46,   126,
      68,    47,   127,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    66,    67,    65,    65,    69,    68,    70,    68,
      71,    68,    72,    68,    73,    68,    74,    68,    75,    68,
      76,    68,    77,    68,    78,    68,    68,    68,    68,    79,
      80,    80,    82,    83,    84,    85,    86,    81,    87,    87,
      89,    88,    91,    90,    93,    94,    95,    92,    96,    97,
      92,    92,    92,    99,   100,   101,   102,    98,   104,   105,
     103,   107,   106,   108,   106,   110,   111,   112,   109,   113,
     114,   115,   109,   116,   117,   116,   116,   119,   120,   121,
     118,   123,   122,   124,   125,   126,   127,   122,   122,   129,
     130,   128,   132,   133,   131,   134,   135,   136,   134,   137,
     138,   137,   139,   137,   137,   141,   142,   143,   140,   144,
     144,   146,   145,   145,   145,   148,   149,   147,   150,   150,
     150,   151,   152,   151,   151,   154,   155,   153,   153,   156,
     157,   153,   153,   153,   158,   158,   158,   160,   159,   161,
     159,   162,   159,   163,   159,   164,   159,   165,   159,   166,
     159,   167,   159,   168,   159,   169,   159,   170,   159,   171,
     159,   172,   159,   173,   159,   174,   159,   159,   159,   159,
     159,   175,   176,   177,   175,   179,   178,   180,   181,   182,
     178,   183,   184,   178,   178,   178,   185,   185,   185,   185,
     185,   185,   186,   186,   186,   186,   186,   186,   186,   187,
     187,   187,   187,   188,   188,   188,   188,   189,   189,   190,
     190,   191,   191,   192,   192,   193,   193,   194,   195,   194,
     196,   194,   194
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     2,     3,     0,     3,
       2,     2,     0,     0,     0,     0,     0,    12,     1,     0,
       0,     4,     0,     3,     0,     0,     0,     8,     0,     0,
       7,     1,     1,     0,     0,     0,     0,    13,     0,     0,
      10,     0,     4,     0,     5,     0,     0,     0,     7,     0,
       0,     0,     8,     4,     0,     4,     0,     0,     0,     0,
      11,     0,     5,     0,     0,     0,     0,    12,     0,     0,
       0,     9,     0,     0,     9,     5,     0,     0,     6,     1,
       0,     4,     0,     3,     0,     0,     0,     0,    12,     1,
       1,     0,     3,     2,     0,     0,     0,     6,     1,     1,
       0,     2,     0,     3,     0,     0,     0,     5,     1,     0,
       0,     5,     1,     0,     2,     3,     0,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     3,     3,     1,
       1,     3,     0,     0,     5,     0,     4,     0,     0,     0,
       8,     0,     0,     6,     1,     0,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     1,     0,     1,     1,     1,     0,     4,
       0,     4,     0
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
#line 111 "java2cpp.y"
                  { print_init(); }
#line 1806 "y.tab.c"
    break;

  case 3:
#line 111 "java2cpp.y"
                                                              {push_scope("global");printf("/* start Main Class */\n"); }
#line 1812 "y.tab.c"
    break;

  case 4:
#line 111 "java2cpp.y"
                                                                                                                                                      {pop_scope(); printf("\n/* end Main Class */\n"); exit(0); }
#line 1818 "y.tab.c"
    break;

  case 5:
#line 112 "java2cpp.y"
                                                { printf("\n"); exit(2); }
#line 1824 "y.tab.c"
    break;

  case 6:
#line 115 "java2cpp.y"
                  { print_tabs(); }
#line 1830 "y.tab.c"
    break;

  case 7:
#line 115 "java2cpp.y"
                                                           { }
#line 1836 "y.tab.c"
    break;

  case 8:
#line 116 "java2cpp.y"
                          { print_tabs(); }
#line 1842 "y.tab.c"
    break;

  case 9:
#line 116 "java2cpp.y"
                                                                               { }
#line 1848 "y.tab.c"
    break;

  case 10:
#line 117 "java2cpp.y"
                          { print_tabs(); }
#line 1854 "y.tab.c"
    break;

  case 11:
#line 117 "java2cpp.y"
                                                               { }
#line 1860 "y.tab.c"
    break;

  case 12:
#line 118 "java2cpp.y"
                          { print_tabs(); }
#line 1866 "y.tab.c"
    break;

  case 13:
#line 118 "java2cpp.y"
                                                                    { }
#line 1872 "y.tab.c"
    break;

  case 14:
#line 119 "java2cpp.y"
                          { print_tabs(); }
#line 1878 "y.tab.c"
    break;

  case 15:
#line 119 "java2cpp.y"
                                                                { }
#line 1884 "y.tab.c"
    break;

  case 16:
#line 120 "java2cpp.y"
                          { print_tabs(); }
#line 1890 "y.tab.c"
    break;

  case 17:
#line 120 "java2cpp.y"
                                                                  { }
#line 1896 "y.tab.c"
    break;

  case 18:
#line 121 "java2cpp.y"
                          { print_tabs(); }
#line 1902 "y.tab.c"
    break;

  case 19:
#line 121 "java2cpp.y"
                                                                     { }
#line 1908 "y.tab.c"
    break;

  case 20:
#line 122 "java2cpp.y"
                          { print_tabs(); }
#line 1914 "y.tab.c"
    break;

  case 21:
#line 122 "java2cpp.y"
                                                             { }
#line 1920 "y.tab.c"
    break;

  case 22:
#line 123 "java2cpp.y"
                          { print_tabs(); }
#line 1926 "y.tab.c"
    break;

  case 23:
#line 123 "java2cpp.y"
                                                                { }
#line 1932 "y.tab.c"
    break;

  case 24:
#line 124 "java2cpp.y"
                          { print_tabs(); }
#line 1938 "y.tab.c"
    break;

  case 25:
#line 124 "java2cpp.y"
                                                                 { }
#line 1944 "y.tab.c"
    break;

  case 26:
#line 125 "java2cpp.y"
                                             { }
#line 1950 "y.tab.c"
    break;

  case 28:
#line 127 "java2cpp.y"
                                { }
#line 1956 "y.tab.c"
    break;

  case 32:
#line 136 "java2cpp.y"
                {push_scope(yylval.var_name);printf("%s", yylval.var_name);insert_funtion(yylval.var_name,current_data_type,1); }
#line 1962 "y.tab.c"
    break;

  case 33:
#line 136 "java2cpp.y"
                                                                                                                                    { printf("("); }
#line 1968 "y.tab.c"
    break;

  case 34:
#line 136 "java2cpp.y"
                                                                                                                                                               { printf(")"); }
#line 1974 "y.tab.c"
    break;

  case 35:
#line 136 "java2cpp.y"
                                                                                                                                                                                        { tab_counter++; printf("{\n"); }
#line 1980 "y.tab.c"
    break;

  case 36:
#line 136 "java2cpp.y"
                                                                                                                                                                                                                                        { printf("}\n"); tab_counter--;pop_scope(); }
#line 1986 "y.tab.c"
    break;

  case 37:
#line 136 "java2cpp.y"
                                                                                                                                                                                                                                                                                        { }
#line 1992 "y.tab.c"
    break;

  case 40:
#line 142 "java2cpp.y"
                         { printf("return "); }
#line 1998 "y.tab.c"
    break;

  case 41:
#line 142 "java2cpp.y"
                                                                         { printf("\n"); }
#line 2004 "y.tab.c"
    break;

  case 42:
#line 145 "java2cpp.y"
                        { printf("break"); }
#line 2010 "y.tab.c"
    break;

  case 43:
#line 145 "java2cpp.y"
                                                            { printf("\n"); }
#line 2016 "y.tab.c"
    break;

  case 44:
#line 148 "java2cpp.y"
                  { printf("std::cout"); }
#line 2022 "y.tab.c"
    break;

  case 45:
#line 148 "java2cpp.y"
                                              { printf(" << "); }
#line 2028 "y.tab.c"
    break;

  case 46:
#line 148 "java2cpp.y"
                                                                               { printf(" <<  std::endl"); }
#line 2034 "y.tab.c"
    break;

  case 47:
#line 148 "java2cpp.y"
                                                                                                                            { printf("\n"); }
#line 2040 "y.tab.c"
    break;

  case 48:
#line 149 "java2cpp.y"
                        { printf("std::cout"); }
#line 2046 "y.tab.c"
    break;

  case 49:
#line 149 "java2cpp.y"
                                                    { printf(" << "); }
#line 2052 "y.tab.c"
    break;

  case 50:
#line 149 "java2cpp.y"
                                                                                                    { printf("\n"); }
#line 2058 "y.tab.c"
    break;

  case 53:
#line 155 "java2cpp.y"
                         { printf("std::string "); }
#line 2064 "y.tab.c"
    break;

  case 54:
#line 155 "java2cpp.y"
                                                         { printf("%s;", yylval.var_name); }
#line 2070 "y.tab.c"
    break;

  case 55:
#line 155 "java2cpp.y"
                                                                                                                    {printf("std::cin");}
#line 2076 "y.tab.c"
    break;

  case 56:
#line 155 "java2cpp.y"
                                                                                                                                                       {printf(">>");}
#line 2082 "y.tab.c"
    break;

  case 57:
#line 155 "java2cpp.y"
                                                                                                                                                                                 { printf("%s;", yylval.var_name); }
#line 2088 "y.tab.c"
    break;

  case 58:
#line 159 "java2cpp.y"
                                       {printf("std::cin");}
#line 2094 "y.tab.c"
    break;

  case 59:
#line 159 "java2cpp.y"
                                                                          {printf(">>");}
#line 2100 "y.tab.c"
    break;

  case 60:
#line 159 "java2cpp.y"
                                                                                                    { printf("%s;", yylval.var_name); }
#line 2106 "y.tab.c"
    break;

  case 61:
#line 162 "java2cpp.y"
                        {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); {clear_exp_vect('\0');}}
#line 2112 "y.tab.c"
    break;

  case 62:
#line 162 "java2cpp.y"
                                                                                                                                                                   { printf("\n"); check_syntax_errors(); print_type_error_warning();}
#line 2118 "y.tab.c"
    break;

  case 63:
#line 163 "java2cpp.y"
                                                              {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); }
#line 2124 "y.tab.c"
    break;

  case 64:
#line 163 "java2cpp.y"
                                                                                                                                                                                 { printf("\n"); check_syntax_errors(); }
#line 2130 "y.tab.c"
    break;

  case 65:
#line 166 "java2cpp.y"
                       { print_tabs(); printf("%s", yylval.var_name);verify_scope(yylval.var_name); clear_exp_vect('\0'); left_val_type = lookup_in_table(yylval.var_name);}
#line 2136 "y.tab.c"
    break;

  case 66:
#line 166 "java2cpp.y"
                                                                                                                                                                                        { printf(" = "); }
#line 2142 "y.tab.c"
    break;

  case 67:
#line 166 "java2cpp.y"
                                                                                                                                                                                                                           {type_verification();}
#line 2148 "y.tab.c"
    break;

  case 68:
#line 166 "java2cpp.y"
                                                                                                                                                                                                                                                                 { printf("\n"); check_syntax_errors(); print_type_error_warning(); }
#line 2154 "y.tab.c"
    break;

  case 69:
#line 167 "java2cpp.y"
                                             { print_tabs(); printf("%s", yylval.var_name);insert_funtion(yylval.var_name,current_data_type,0);}
#line 2160 "y.tab.c"
    break;

  case 70:
#line 167 "java2cpp.y"
                                                                                                                                                    { printf("("); }
#line 2166 "y.tab.c"
    break;

  case 71:
#line 167 "java2cpp.y"
                                                                                                                                                                                    { printf(")"); }
#line 2172 "y.tab.c"
    break;

  case 72:
#line 167 "java2cpp.y"
                                                                                                                                                                                                                    { printf("\n"); check_syntax_errors(); print_type_error_warning(); }
#line 2178 "y.tab.c"
    break;

  case 74:
#line 171 "java2cpp.y"
                                  { bracket_counter++; }
#line 2184 "y.tab.c"
    break;

  case 77:
#line 176 "java2cpp.y"
                        { printf("if (");create_scope_name_and_push_it(); }
#line 2190 "y.tab.c"
    break;

  case 78:
#line 176 "java2cpp.y"
                                                                                                  { tab_counter++; printf(") {\n"); check_syntax_errors(); }
#line 2196 "y.tab.c"
    break;

  case 79:
#line 176 "java2cpp.y"
                                                                                                                                                                           { pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2202 "y.tab.c"
    break;

  case 81:
#line 179 "java2cpp.y"
                          {create_scope_name_and_push_it(); tab_counter++; printf(" else {\n"); }
#line 2208 "y.tab.c"
    break;

  case 82:
#line 179 "java2cpp.y"
                                                                                                                {pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2214 "y.tab.c"
    break;

  case 83:
#line 180 "java2cpp.y"
                                            { printf(" else if ("); }
#line 2220 "y.tab.c"
    break;

  case 84:
#line 180 "java2cpp.y"
                                                                                         { printf(")"); check_syntax_errors(); }
#line 2226 "y.tab.c"
    break;

  case 85:
#line 180 "java2cpp.y"
                                                                                                                                    {create_scope_name_and_push_it();tab_counter++; printf(") {\n"); }
#line 2232 "y.tab.c"
    break;

  case 86:
#line 180 "java2cpp.y"
                                                                                                                                                                                                                     { pop_scope();tab_counter--;print_tabs(); printf("}"); }
#line 2238 "y.tab.c"
    break;

  case 88:
#line 181 "java2cpp.y"
                                        { printf("\n"); }
#line 2244 "y.tab.c"
    break;

  case 89:
#line 184 "java2cpp.y"
                       {create_scope_name_and_push_it();printf("while ("); }
#line 2250 "y.tab.c"
    break;

  case 90:
#line 184 "java2cpp.y"
                                                                                             { tab_counter++; printf("){\n"); }
#line 2256 "y.tab.c"
    break;

  case 91:
#line 184 "java2cpp.y"
                                                                                                                                              {pop_scope();tab_counter--; print_tabs(); printf("}\n"); }
#line 2262 "y.tab.c"
    break;

  case 92:
#line 189 "java2cpp.y"
                         {create_scope_name_and_push_it(); printf("for ("); }
#line 2268 "y.tab.c"
    break;

  case 93:
#line 189 "java2cpp.y"
                                                                                               { tab_counter++; printf(") {\n"); check_syntax_errors(); }
#line 2274 "y.tab.c"
    break;

  case 94:
#line 189 "java2cpp.y"
                                                                                                                                                                        {pop_scope(); tab_counter--; print_tabs(); printf("}\n"); }
#line 2280 "y.tab.c"
    break;

  case 96:
#line 193 "java2cpp.y"
                                         { printf("%s", yylval.var_name); }
#line 2286 "y.tab.c"
    break;

  case 97:
#line 193 "java2cpp.y"
                                                                            { printf(" : "); }
#line 2292 "y.tab.c"
    break;

  case 98:
#line 193 "java2cpp.y"
                                                                                                   { printf("%s", yylval.var_name); }
#line 2298 "y.tab.c"
    break;

  case 100:
#line 197 "java2cpp.y"
                                   {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); }
#line 2304 "y.tab.c"
    break;

  case 102:
#line 198 "java2cpp.y"
                              {verify_scope(yylval.var_name);printf("%s", yylval.var_name); }
#line 2310 "y.tab.c"
    break;

  case 104:
#line 199 "java2cpp.y"
                                 { }
#line 2316 "y.tab.c"
    break;

  case 105:
#line 202 "java2cpp.y"
                        { printf("do{\n"); tab_counter++;}
#line 2322 "y.tab.c"
    break;

  case 106:
#line 202 "java2cpp.y"
                                                                                  {tab_counter--; print_tabs(); printf("}while("); }
#line 2328 "y.tab.c"
    break;

  case 107:
#line 202 "java2cpp.y"
                                                                                                                                                  { printf(")"); }
#line 2334 "y.tab.c"
    break;

  case 108:
#line 202 "java2cpp.y"
                                                                                                                                                                                  { printf("\n"); }
#line 2340 "y.tab.c"
    break;

  case 109:
#line 206 "java2cpp.y"
                           { printf("[%s]", yylval.var_name); }
#line 2346 "y.tab.c"
    break;

  case 110:
#line 207 "java2cpp.y"
                                  { printf("[%s]", yylval.var_name); }
#line 2352 "y.tab.c"
    break;

  case 111:
#line 210 "java2cpp.y"
                             { printf(" = "); }
#line 2358 "y.tab.c"
    break;

  case 112:
#line 210 "java2cpp.y"
                                                                {type_verification();}
#line 2364 "y.tab.c"
    break;

  case 114:
#line 212 "java2cpp.y"
                                                              {}
#line 2370 "y.tab.c"
    break;

  case 115:
#line 215 "java2cpp.y"
                                      { push_scope("main");printf("int main(int argc, char **argv)"); }
#line 2376 "y.tab.c"
    break;

  case 116:
#line 215 "java2cpp.y"
                                                                                                           { tab_counter++; printf("{\n"); }
#line 2382 "y.tab.c"
    break;

  case 117:
#line 215 "java2cpp.y"
                                                                                                                                                           { printf("\n}\n"); tab_counter--; pop_scope();}
#line 2388 "y.tab.c"
    break;

  case 122:
#line 226 "java2cpp.y"
                           { printf(","); }
#line 2394 "y.tab.c"
    break;

  case 124:
#line 227 "java2cpp.y"
                                                        { printf(" "); }
#line 2400 "y.tab.c"
    break;

  case 125:
#line 229 "java2cpp.y"
                  {printf("%s", yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2406 "y.tab.c"
    break;

  case 126:
#line 229 "java2cpp.y"
                                                                                              { printf(","); }
#line 2412 "y.tab.c"
    break;

  case 128:
#line 230 "java2cpp.y"
                             {printf("%s", yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2418 "y.tab.c"
    break;

  case 129:
#line 231 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2424 "y.tab.c"
    break;

  case 130:
#line 231 "java2cpp.y"
                                                                                        { printf(","); }
#line 2430 "y.tab.c"
    break;

  case 132:
#line 232 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2436 "y.tab.c"
    break;

  case 134:
#line 236 "java2cpp.y"
                           {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name);insert_type_param(current_data_type); }
#line 2442 "y.tab.c"
    break;

  case 135:
#line 237 "java2cpp.y"
                                                        {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name);printf("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--)printf("[%d]",DIMENSION);}
#line 2448 "y.tab.c"
    break;

  case 137:
#line 241 "java2cpp.y"
                                 { printf(" && "); }
#line 2454 "y.tab.c"
    break;

  case 139:
#line 242 "java2cpp.y"
                                        { printf(" || "); }
#line 2460 "y.tab.c"
    break;

  case 141:
#line 243 "java2cpp.y"
                                        { printf(" <= "); }
#line 2466 "y.tab.c"
    break;

  case 143:
#line 244 "java2cpp.y"
                                        { printf(" >= "); }
#line 2472 "y.tab.c"
    break;

  case 145:
#line 245 "java2cpp.y"
                                       { printf(" > "); }
#line 2478 "y.tab.c"
    break;

  case 147:
#line 246 "java2cpp.y"
                                       { printf(" < "); }
#line 2484 "y.tab.c"
    break;

  case 149:
#line 247 "java2cpp.y"
                                        { printf(" != "); }
#line 2490 "y.tab.c"
    break;

  case 151:
#line 248 "java2cpp.y"
                                        { printf(" == "); }
#line 2496 "y.tab.c"
    break;

  case 153:
#line 249 "java2cpp.y"
                              { printf("!"); }
#line 2502 "y.tab.c"
    break;

  case 155:
#line 250 "java2cpp.y"
                                         { printf(" + "); add_exp_vect('+');}
#line 2508 "y.tab.c"
    break;

  case 157:
#line 251 "java2cpp.y"
                                          { printf(" - "); add_exp_vect('-');}
#line 2514 "y.tab.c"
    break;

  case 159:
#line 252 "java2cpp.y"
                                        { printf(" * "); add_exp_vect('*');}
#line 2520 "y.tab.c"
    break;

  case 161:
#line 253 "java2cpp.y"
                                        { printf(" / "); add_exp_vect('/'); }
#line 2526 "y.tab.c"
    break;

  case 163:
#line 254 "java2cpp.y"
                                        { printf(" %% "); }
#line 2532 "y.tab.c"
    break;

  case 165:
#line 255 "java2cpp.y"
                             { printf("("); add_exp_vect('(');}
#line 2538 "y.tab.c"
    break;

  case 166:
#line 255 "java2cpp.y"
                                                                             { printf(")"); add_exp_vect(')');}
#line 2544 "y.tab.c"
    break;

  case 167:
#line 256 "java2cpp.y"
                                              { printf("++"); }
#line 2550 "y.tab.c"
    break;

  case 168:
#line 257 "java2cpp.y"
                                                { printf("--"); }
#line 2556 "y.tab.c"
    break;

  case 170:
#line 259 "java2cpp.y"
                              { printf("%s", yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
#line 2562 "y.tab.c"
    break;

  case 171:
#line 262 "java2cpp.y"
                                                  {bracket_counter=0;}
#line 2568 "y.tab.c"
    break;

  case 172:
#line 263 "java2cpp.y"
                                          { for(;bracket_counter>0;bracket_counter--)printf("[]"); }
#line 2574 "y.tab.c"
    break;

  case 173:
#line 263 "java2cpp.y"
                                                                                                        { printf(" = {"); }
#line 2580 "y.tab.c"
    break;

  case 174:
#line 263 "java2cpp.y"
                                                                                                                                                          { printf("}"); }
#line 2586 "y.tab.c"
    break;

  case 175:
#line 266 "java2cpp.y"
                                                { printf(","); }
#line 2592 "y.tab.c"
    break;

  case 177:
#line 267 "java2cpp.y"
                                                               { printf(","); }
#line 2598 "y.tab.c"
    break;

  case 178:
#line 267 "java2cpp.y"
                                                                                   { printf("{"); }
#line 2604 "y.tab.c"
    break;

  case 179:
#line 267 "java2cpp.y"
                                                                                                                                  { printf("}"); }
#line 2610 "y.tab.c"
    break;

  case 181:
#line 268 "java2cpp.y"
                                                              { printf("{"); }
#line 2616 "y.tab.c"
    break;

  case 182:
#line 268 "java2cpp.y"
                                                                                                             { printf("}"); }
#line 2622 "y.tab.c"
    break;

  case 192:
#line 281 "java2cpp.y"
              { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type);	printf("int "); }
#line 2628 "y.tab.c"
    break;

  case 193:
#line 282 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("char "); }
#line 2634 "y.tab.c"
    break;

  case 194:
#line 283 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("float "); }
#line 2640 "y.tab.c"
    break;

  case 195:
#line 284 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("double "); }
#line 2646 "y.tab.c"
    break;

  case 196:
#line 285 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("std::string "); }
#line 2652 "y.tab.c"
    break;

  case 197:
#line 286 "java2cpp.y"
                          { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("bool "); }
#line 2658 "y.tab.c"
    break;

  case 198:
#line 287 "java2cpp.y"
                       { printf("void "); }
#line 2664 "y.tab.c"
    break;

  case 199:
#line 290 "java2cpp.y"
                         { printf("%s", yylval.var_name); add_exp_vect(48+T_INT); }
#line 2670 "y.tab.c"
    break;

  case 200:
#line 291 "java2cpp.y"
                                      { printf("%s", yylval.var_name); add_exp_vect(48+T_CHAR); }
#line 2676 "y.tab.c"
    break;

  case 201:
#line 292 "java2cpp.y"
                                        { printf("%s", yylval.var_name); add_exp_vect(48+T_STRING); }
#line 2682 "y.tab.c"
    break;

  case 202:
#line 293 "java2cpp.y"
                                   { printf("%s", yylval.var_name); add_exp_vect(48+T_BOOL); }
#line 2688 "y.tab.c"
    break;

  case 203:
#line 295 "java2cpp.y"
                                 { printf("%s", yylval.var_name); current_data_type=T_INT;}
#line 2694 "y.tab.c"
    break;

  case 204:
#line 296 "java2cpp.y"
                                      { printf("%s", yylval.var_name); current_data_type=T_CHAR; }
#line 2700 "y.tab.c"
    break;

  case 205:
#line 297 "java2cpp.y"
                                        { printf("%s", yylval.var_name); current_data_type=T_STRING; }
#line 2706 "y.tab.c"
    break;

  case 206:
#line 298 "java2cpp.y"
                                   { printf("%s", yylval.var_name); current_data_type=T_BOOL; }
#line 2712 "y.tab.c"
    break;

  case 207:
#line 301 "java2cpp.y"
                                { printf("%s\n", yylval.var_name); }
#line 2718 "y.tab.c"
    break;

  case 208:
#line 302 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2724 "y.tab.c"
    break;

  case 211:
#line 309 "java2cpp.y"
                            { }
#line 2730 "y.tab.c"
    break;

  case 212:
#line 310 "java2cpp.y"
                             { printf("}\n"); }
#line 2736 "y.tab.c"
    break;

  case 213:
#line 313 "java2cpp.y"
                            { printf(";"); }
#line 2742 "y.tab.c"
    break;

  case 214:
#line 314 "java2cpp.y"
                                            { yyerror("Syntax error: expected ';' at end of declaration"); }
#line 2748 "y.tab.c"
    break;

  case 215:
#line 317 "java2cpp.y"
                                    { printf(";"); }
#line 2754 "y.tab.c"
    break;

  case 216:
#line 318 "java2cpp.y"
                                               { printf(","); strcat(syntax_errors,"Syntax error: expected ';' instead of ','\t"); }
#line 2760 "y.tab.c"
    break;

  case 218:
#line 322 "java2cpp.y"
                                                 { printf("%s", yylval.var_name); printf("="); }
#line 2766 "y.tab.c"
    break;

  case 219:
#line 322 "java2cpp.y"
                                                                                                           { }
#line 2772 "y.tab.c"
    break;

  case 220:
#line 323 "java2cpp.y"
                                                       { printf("="); }
#line 2778 "y.tab.c"
    break;

  case 221:
#line 323 "java2cpp.y"
                                                                                  { strcat(syntax_errors,"Syntax error: expected '==' operator\n"); }
#line 2784 "y.tab.c"
    break;

  case 222:
#line 324 "java2cpp.y"
                                            { strcat(syntax_errors,"Syntax error: expected expresion\n"); }
#line 2790 "y.tab.c"
    break;


#line 2794 "y.tab.c"

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
#line 327 "java2cpp.y"


#include "lex.yy.c"
void print_table_symbols(){
		printf("\n");
		for(int i=0; i<table_idx; i++)
		{	
			printf("%d var=%s Scope=%s type=%d\n",i,sym[i].var_name,sym[i].scope_name,sym[i].type);			
		}
}
int verify_scope(char var[MAX_NAME_LEN]){
	int found= 0;
	int index=-1;
	//Look in the table if var was declare in the current Scope
	//If not look on the parent scope and so on
	for(int j=stack_scope_counter;j>=0;j--)
	for(int i=0; i<table_idx; i++)
	{	
		if(strcmp(sym[i].var_name, var)==0 &&
		 strcmp(sym[i].scope_name, stack_scope[j])==0 ){
			found=1;
			index=i;
			break;}
	}

	if(!found){
		printf("\nVariable %s was not declared in the scope  \n",var);
		//print_table_symbols();
		yyerror("");
		//exit(0);
	}

        return index;
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
		//exit(0);
	}
}
void insert_funtion(char var[MAX_NAME_LEN], int type,int is_def)
{	
		strcpy(fun[table_idf].var_name,var);
		fun[table_idf].type = type;
		fun[table_idf].is_def = is_def;
		table_idf++;
		

}
void insert_argument_var(char var[MAX_NAME_LEN]){
	int type=lookup_in_table(var);
	if(type !=-1){
		insert_type_param(type);
	}else{
		printf("\nVariable not declare %s \n",var);
		yyerror("");
	}
}
void insert_type_param(int type){
	fun[table_idf -1].type_params[fun[table_idf -1].counter_type_params++]=type;
}
void print_tabs() {
	for(int i = 0; i < tab_counter; i++){
		printf("\t");
	}
	return;
}

int main() {
	#if YYDEBUG
        yydebug = 1;
    #endif
	yyparse();
	return 0;
}

int yyerror(const char *msg) {
	extern int yylineno;
	int l = tab_counter*8;
	printf("\n");
	//print_tabs();
	for(int i=0; i<l;i++){
		printf("^");
	}
	printf("\nError on java file line [%d] :: %s\n", yylineno, msg);
	success = 0;
	return 0;
}

void check_syntax_errors(){
	if (strcmp(syntax_errors,"")){
		yyerror(syntax_errors);
		strcpy(syntax_errors,"");
	}
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

void warning(char *msg){ //Still under development
	//printf("/*\n%s*/\n",msg);
}

void make_casting(char type1, char type2, char operator){
	if(right_val_type!=T_ERROR){
		struct T_tuple t;
		if(type1==INTNOVAL){
			t.warning = 0;
			t.type = type2;
			//printf("if\n");
		}else{
			//printf("type1: %c, type2: %c, operator: %c\n",type1, type2, operator);
			t = cast_type(type1, type2, operator);
			//printf("else\n");
		}

		//printf("t.type: %d, t.warning: %d\n",t.type, t.warning);
		
		if (t.warning){
			char waux[52];
			sprintf(waux,"Warning: Implicit type conversion to %s\n",type_to_str(48+t.type));
			strcat(type_cast_str_warning,waux);
		}

		if (t.type == T_ERROR){
			if(operator=='0'){
				char *eaux;
				sprintf(eaux,"Error: Cannot convert from %s to %s\n",type_to_str(type1), type_to_str(type2));
				strcat(type_cast_str_error,eaux);
			}else{
				char eaux[56];
				sprintf(eaux,"Error: No conversion for %s, %s with \"%c\" operator\n",type_to_str(type1), type_to_str(type2), operator);
				strcat(type_cast_str_error,eaux);
			}
			
		}

		right_val_type = t.type;
	}
	


}

void print_type_error_warning(){
	//left_val_type = current_data_type;
	//type_verification();
	if(type_verified){
		type_verified = 0;
		//printf("Lval: %d Rval: %d\n",left_val_type, right_val_type);
		if (strcmp(type_cast_str_error,"")){
			char aux[512];
			//strcat(aux, type_cast_str_error);
			//strcat(aux, type_cast_str_warning);
			//yyerror(aux);
			yyerror(type_cast_str_error);
			strcpy(type_cast_str_error,"\0");
		}else if(left_val_type!=right_val_type ){
			char aux2[512];
			char *sty1 = type_to_str(48+right_val_type);
			char * sty2 = type_to_str(48+left_val_type);
			if(strcmp(sty1,"ERROR") && strcmp(sty2,"ERROR")){
				sprintf(aux2,"Error: implicit cast: Cannot cast from %s to %s\n",sty1, sty2);
				yyerror(aux2);
			}
			
		}

		if(strcmp(type_cast_str_warning,"")){
			warning(type_cast_str_warning);
			strcpy(type_cast_str_warning,"\0");
		}

	}
	left_val_type=INTNOVAL;
}

void clear_exp_vect(char c){
	evtop=0;
	for(int i = 0; i < EVLEN+1; i++){
		expression_vect[i]='x';
		//printf("%c",expression_vect[i]);
	}
	if(c!='\0'){
		evtop=1;
		expression_vect[0]=c;
	}else{
		right_val_type = INTNOVAL;
	}
	//printf("\nevtop: %d\n",evtop);
}

void add_exp_vect(char type){
	expression_vect[evtop]=type;
	//printf("\nitem: %c, index: %d\n",type, evtop);
	evtop++;
	
}

void add_exp_vect_var(char type){
	//printf("TYPE VAR: %c\n",type);
	if (type != 47){ // 48 - 1 ... ASCCI 48 + Ttpe and type is -1 for a var not declared in scope
		add_exp_vect(type);
	}
}

int find_r_paren(int p){
	for(int i = p; i<EVLEN; i++){
		if(expression_vect[i]==')'){
			return i;
		}
	}
	return -1;
}

int find_l_paren(int p){
	for(int i = p; i>=0; i--){
		if(expression_vect[i]=='('){
			return i;
		}
	}
	return -1;
}

char *split_arr(int l, int r){
	static char s[EVLEN+1];
	int cont = 0;
	for(int i = l+1; i<r; i++){
		//char c[EVLEN+1];
		//sprintf(c,"%c",expression_vect[i]);
		//strcat(s,c);
		s[cont]=expression_vect[i];
		//printf("%c",s[cont]);
		cont++;
	}
	s[r]='\0';
	return s;
}

void remerge_arr(int l, int r, int new_type){
	int dif = r-l;
	expression_vect[l]=48+new_type;
	for(int i = l+1; i<EVLEN; i++){
		if (expression_vect[i]=='x'){
			return;
		}
		expression_vect[i] = expression_vect[i+dif];
	}
}

void find_new_type(char expr[EVLEN+1], int len){
	int i = 0;
	if (len>=3){
		//printf("len: %d\n",len);
		//printf("find_new_type_expr:\n");
		/*for(int h=0; h<len; h++){
			printf("%c",expr[h]);
		}*/
		//printf("\n");
		make_casting(expr[0],expr[2],expr[1]);
		i = 3;
		for (i; i < len; i=i+2){
			//printf("i: %d\n",i);
			//if(i+2<len){
			make_casting(48+right_val_type,expr[i+1],expr[i]);
			//}
		}
	}else{
		make_casting(48+right_val_type,expr[0],'0');
	}
	
}

void type_verification(){
	type_verified = 1;
	//left_val_type = current_data_type;
	left_val_type = left_val_type == INTNOVAL ? current_data_type : left_val_type;
	int r,l,i=0;
	//printf("INITIAL evtop: %d\n",evtop);
	//char *sub_expr;
	while(evtop>0){
		r = find_r_paren(i);
		//printf("r: %d\n",r);
		if (r==-1){
			for(int len=0; len<EVLEN; len++){
				if(expression_vect[len]=='x'){
					/*for(int x =0; x<len; x++){
						printf("expression_vect[%d]: %c\n",x, expression_vect[x]);
					}*/
					//printf("my len %d\n",len);
					find_new_type(expression_vect, len);
					len=EVLEN;
					break;
				}
			}
			//printf("\nNEW right_val_type: %d\n",right_val_type);
			evtop=-99;
		}else{
			l = find_l_paren(r);
			//printf("l: %d\n",l);
			char sub_expr[EVLEN+1];
			strcpy(sub_expr,split_arr(l,r));
			//printf("r-l-1=%d\n",r-l-1);
			/*for(int y=0; y<3; y++){
				printf("%c",sub_expr[y]);
			}*/
			find_new_type(sub_expr, r-l-1);
			/*for(int y=0; y<EVLEN; y++){
				printf("%c",expression_vect[y]);
			}*/
			//printf("\nright_val_type: %d\n",right_val_type);
			remerge_arr(l,r,right_val_type);
			/*for(int y=0; y<EVLEN; y++){
				printf("%c",expression_vect[y]);
			}*/
			//evtop = evtop - r -l + 1;
			for(int i=0; i<EVLEN; i++){
				if(expression_vect[i]=='x'){
					evtop = i;
					break;
				}
			}
			i=l;
			//printf("ok\n");
			//printf("evtop: %d\n",evtop);
		}
		
		
	}
	//left_val_type = INTNOVAL;
}

int lookup_in_table_alt(char var[MAX_NAME_LEN])
{
	int i = verify_scope(var);
	if (i>=0){
		return sym[i].type;
	}

	return -1;
}
