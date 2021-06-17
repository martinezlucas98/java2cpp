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
	int current_constant=0;
	struct symbol_table{char var_name[MAX_NAME_LEN]; int type;char scope_name[MAX_NAME_LEN];int is_constant;} sym[MAX_VARIABLES];
	struct fun_table{char var_name[MAX_NAME_LEN]; int type; int type_params[MAX_VARIABLES];int counter_type_params;int is_def;} fun[MAX_DECL_FUN];
	extern int lookup_in_table(char var[MAX_NAME_LEN]);
	int verify_scope(char var[MAX_NAME_LEN]); // When a variable is used look first if it was declared before
	extern int check_constant(char var[MAX_NAME_LEN]); //Check if varaible tha is assigned is not constant
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
	extern void verify_fun_table();
	extern void get_format_string_types(char dest[200],struct fun_table source);
	extern void write_fun_table_header_file();
	extern void convert_type_to_string(char dest[20],int type);
	extern void get_format_string_types(char dest[200],struct fun_table source);
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


#line 159 "y.tab.c"

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
    FINAL = 295,
    BOOL_VAL = 296,
    NUMBER = 297,
    QUOTED_STRING = 298,
    QUOTED_CHAR = 299,
    LP = 300,
    RP = 301,
    LC = 302,
    RC = 303,
    LB = 304,
    RB = 305,
    COMA = 306,
    SEMICOLON = 307,
    COLON = 308,
    QM = 309,
    SQ = 310,
    DQ = 311,
    ILCOMMENT = 312,
    MLCOMMENT = 313,
    INT = 314,
    CHAR = 315,
    FLOAT = 316,
    DOUBLE = 317,
    STRING = 318,
    BOOLEAN = 319
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
#define FINAL 295
#define BOOL_VAL 296
#define NUMBER 297
#define QUOTED_STRING 298
#define QUOTED_CHAR 299
#define LP 300
#define RP 301
#define LC 302
#define RC 303
#define LB 304
#define RB 305
#define COMA 306
#define SEMICOLON 307
#define COLON 308
#define QM 309
#define SQ 310
#define DQ 311
#define ILCOMMENT 312
#define MLCOMMENT 313
#define INT 314
#define CHAR 315
#define FLOAT 316
#define DOUBLE 317
#define STRING 318
#define BOOLEAN 319

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 90 "java2cpp.y"

int data_type;
char var_name[MAX_NAME_LEN];

#line 341 "y.tab.c"

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
#define YYLAST   394

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  224
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

#define YYUNDEFTOK  2
#define YYMAXUTOK   319


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   118,   118,   119,   122,   122,   123,   123,
     124,   124,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   133,   134,   137,
     139,   140,   142,   143,   144,   144,   144,   144,   144,   144,
     146,   147,   150,   150,   153,   153,   156,   156,   156,   156,
     157,   157,   157,   158,   159,   163,   163,   163,   163,   163,
     167,   167,   167,   170,   170,   171,   171,   174,   174,   174,
     174,   175,   175,   175,   175,   178,   179,   179,   180,   184,
     184,   184,   184,   187,   187,   188,   188,   188,   188,   188,
     189,   192,   192,   192,   197,   197,   197,   200,   201,   201,
     201,   204,   205,   205,   206,   206,   207,   210,   210,   210,
     210,   214,   215,   218,   218,   219,   220,   223,   223,   223,
     228,   229,   230,   233,   234,   234,   235,   237,   237,   237,
     238,   239,   239,   239,   240,   241,   244,   245,   246,   249,
     249,   250,   250,   251,   251,   252,   252,   253,   253,   254,
     254,   255,   255,   256,   256,   257,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   262,   263,   263,   264,
     265,   266,   267,   270,   271,   271,   271,   274,   274,   275,
     275,   275,   275,   276,   276,   276,   277,   278,   281,   282,
     283,   284,   285,   286,   289,   290,   291,   292,   293,   294,
     295,   298,   299,   300,   301,   303,   304,   305,   306,   309,
     310,   313,   314,   317,   318,   321,   322,   325,   326,   329,
     330,   330,   331,   331,   332
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
  "FINAL", "BOOL_VAL", "NUMBER", "QUOTED_STRING", "QUOTED_CHAR", "LP",
  "RP", "LC", "RC", "LB", "RB", "COMA", "SEMICOLON", "COLON", "QM", "SQ",
  "DQ", "ILCOMMENT", "MLCOMMENT", "INT", "CHAR", "FLOAT", "DOUBLE",
  "STRING", "BOOLEAN", "$accept", "program", "$@1", "$@2", "STATEMENTS",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "IGNORE_SCOPE", "DECLARATION", "CONST", "METHODS", "$@13", "$@14",
  "$@15", "$@16", "$@17", "IS_STATIC", "RETURN_ST", "$@18", "BREAK_ST",
  "$@19", "STDIO", "$@20", "$@21", "$@22", "$@23", "$@24",
  "SCANNER_OBJECT", "$@25", "$@26", "$@27", "$@28", "MY_INPUT", "$@29",
  "$@30", "VAR_DECLARATION", "$@31", "$@32", "VAR_USE", "$@33", "$@34",
  "$@35", "$@36", "$@37", "$@38", "BRACKET_ARRAY", "$@39", "IF_STATEMENT",
  "$@40", "$@41", "$@42", "ELSE_VARIATIONS", "$@43", "$@44", "$@45",
  "$@46", "$@47", "WHILE_LOOP", "$@48", "$@49", "FOR_LOOP", "$@50", "$@51",
  "FOR_PARAMS", "$@52", "$@53", "DECL_EXPR", "$@54", "$@55",
  "DO_WHILE_LOOP", "$@56", "$@57", "$@58", "NUMARRAY", "HAS_ASSIGNMENT",
  "$@59", "MAIN_METHOD_DECLARATION", "$@60", "$@61", "SCOPE", "PARAMS",
  "$@62", "PARAMS_TYPE", "$@63", "$@64", "$@65", "$@66", "HAS_PARAMS",
  "EXPRESION", "$@67", "$@68", "$@69", "$@70", "$@71", "$@72", "$@73",
  "$@74", "$@75", "$@76", "$@77", "$@78", "$@79", "$@80", "$@81",
  "EXPRESION_ARRAY", "$@82", "$@83", "EXPRESION_ARRAY_INITIALIZE", "$@84",
  "$@85", "$@86", "$@87", "$@88", "$@89", "TYPE_NO_PRINT", "TYPE",
  "TERMINAL", "LITERAL_ARGUMENT", "COMMENT", "HAS_COMMENT", "DELIMITER",
  "MUST_SEMICOLON", "SEMICOLON_NOT_COMA", "MUST_EXPRESSION", "$@90",
  "$@91", YY_NULLPTR
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
     315,   316,   317,   318,   319
};
# endif

#define YYPACT_NINF (-291)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-175)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    17,    -7,  -291,  -291,  -291,  -291,     5,   -19,  -291,
     159,    -5,   -11,     0,    23,    35,    -7,    38,    31,    37,
      33,    26,    46,    51,   159,  -291,  -291,   159,    76,    52,
      -7,  -291,  -291,    59,   159,    74,  -291,   159,   159,    65,
     159,    66,   159,    67,   159,    68,   159,    96,  -291,  -291,
    -291,   159,  -291,  -291,  -291,   159,  -291,   159,  -291,  -291,
    -291,  -291,  -291,  -291,    12,  -291,  -291,    59,    69,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,    86,
      73,    77,   118,  -291,    72,  -291,    29,  -291,    36,    42,
      80,     4,  -291,  -291,   124,   167,  -291,    36,   201,   201,
     159,    91,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,   262,  -291,   112,   353,  -291,    87,
    -291,  -291,  -291,  -291,    88,    90,   100,   136,  -291,  -291,
    -291,    97,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,   159,   110,    49,   111,    53,   377,   155,   113,   158,
     121,  -291,    29,    29,   160,    29,    29,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,   164,   168,  -291,  -291,  -291,
    -291,  -291,  -291,    72,   132,  -291,   135,  -291,    -9,    72,
     144,   144,   136,   153,   161,   136,   163,  -291,  -291,   201,
     149,   165,  -291,   180,   166,   276,   296,   172,  -291,   339,
      29,    29,    29,    29,    29,    29,    29,    29,  -291,    29,
    -291,    29,    29,    29,    29,    29,    29,  -291,  -291,    72,
    -291,   104,   235,    36,  -291,   177,  -291,  -291,  -291,    72,
    -291,  -291,  -291,  -291,    53,  -291,   136,  -291,   169,   174,
    -291,    72,   195,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,   377,   377,    42,
    -291,    42,  -291,   188,   104,    16,  -291,  -291,  -291,  -291,
    -291,  -291,   144,  -291,  -291,  -291,   159,   159,    29,  -291,
    -291,   159,  -291,   189,    72,  -291,  -291,  -291,  -291,   167,
    -291,  -291,  -291,   233,  -291,   129,   191,   192,   377,   234,
     193,   201,  -291,  -291,   202,  -291,   203,  -291,  -291,  -291,
     200,   198,  -291,  -291,  -291,  -291,   205,   204,   216,  -291,
     129,   211,  -291,  -291,    84,  -291,  -291,   213,   159,   222,
    -291,   129,   237,   270,  -291,    72,  -291,   268,  -291,   129,
    -291,  -291,  -291,  -291,   265,  -291,   129,   271,   159,    36,
    -291,  -291,  -291,  -291,   272,   275,   129,  -291,  -291,  -291,
     278,  -291,   159,   279,  -291,    84,  -291
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   212,     1,   209,   210,   211,     0,     0,     3,
       0,     0,    67,     0,   122,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   214,   213,     0,     0,     0,
     212,   120,   121,    33,     0,    41,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,    50,
      55,     0,    53,    54,    44,     0,    42,     0,    26,    27,
      68,    72,     4,    32,     0,     7,    40,    33,     0,     9,
      11,    79,    13,    94,    15,    91,    17,   107,    19,     0,
       0,     0,     0,    21,   216,    23,     0,    25,   224,   135,
      63,     0,    30,    31,     0,     0,   118,   224,   106,   106,
       0,     0,    47,    51,    56,   215,    45,   172,   155,   204,
     201,   203,   202,   167,   216,   171,   172,   219,    69,   127,
     208,   205,   207,   206,     0,   131,     0,   116,   112,   111,
      76,     0,    65,   200,   194,   195,   196,   197,   198,   199,
      29,     0,     0,   172,     0,     0,   101,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,   139,   141,   145,
     143,   147,   149,   151,   153,   157,   159,   161,   163,   165,
      43,   220,   222,   216,     0,    73,     0,    35,   113,   216,
      78,    78,   116,     0,     0,   116,     0,   218,   217,   106,
     102,     0,   102,     0,     0,     0,     0,     0,   156,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,     0,
     170,     0,     0,     0,     0,     0,     0,    70,   128,   216,
     132,   126,     0,   224,   115,     0,    64,    77,    75,   216,
     119,    80,   105,    95,     0,    98,   116,    92,     0,     0,
      48,   216,     0,   168,   140,   142,   146,   144,   148,   150,
     152,   154,   158,   160,   162,   164,   166,   221,   223,   135,
      74,   135,   124,     0,   126,     0,   188,   189,   190,   191,
     192,   193,    78,   114,   175,    66,     0,     0,     0,    99,
     103,     0,   108,     0,   216,    52,    57,   129,   133,   138,
      36,   123,   136,     0,   173,   187,     0,     0,    97,     0,
       0,   106,    61,    49,     0,   125,     0,   137,   183,   179,
       0,   186,    81,    96,   100,    93,     0,     0,     0,    37,
     187,     0,   176,   177,    90,   109,    62,     0,     0,     0,
     180,   187,     0,     0,    82,   216,    58,     0,   184,   187,
     178,    83,    85,   110,     0,    38,   187,     0,     0,   224,
      59,    39,   185,   181,     0,     0,   187,    84,    86,   182,
       0,    87,     0,     0,    88,    90,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -291,  -291,  -291,  -291,   -24,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,   251,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -169,  -291,  -291,  -291,  -291,  -291,   -42,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,   -98,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -161,  -291,  -291,  -291,  -291,  -291,    62,  -291,
    -219,  -291,  -291,  -291,  -291,    39,   -63,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -233,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,   -89,  -290,  -291,   313,   300,  -291,  -110,
      98,   -95,  -291,  -291
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    33,    34,    64,    92,   126,
     221,   306,   328,   351,    67,    57,    86,    55,    84,    51,
      80,   152,   284,    81,   153,    52,    82,   154,   304,   344,
      53,   194,   317,    93,   127,   182,    24,    28,    88,   173,
      29,    89,   219,    94,   180,    40,    97,   276,   324,   334,
     348,   349,   360,   362,   365,    44,    99,   281,    42,    98,
     277,   144,   279,   299,   145,   236,   185,    46,   100,   301,
     335,   131,   179,   223,    37,    68,   141,    35,   263,   289,
     124,   174,   259,   176,   261,   264,   117,   200,   201,   203,
     202,   204,   205,   206,   207,   155,   209,   211,   212,   213,
     214,   156,   224,   225,   295,   310,   331,   321,   339,   356,
     320,   346,   272,   149,   115,   125,     6,     7,    27,   106,
     189,   118,   215,   216
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,   148,   142,    59,   170,   311,   140,   128,    -5,   147,
      65,   227,   228,    69,    70,    90,    72,     3,    74,   292,
      76,   229,    78,   114,   232,   222,     8,    83,     9,    47,
     311,    85,   107,    87,   -71,   146,   146,   108,  -174,   116,
     287,   311,   288,    25,   108,   119,   129,    26,    30,   311,
       4,     5,    31,    32,   130,    36,   311,    41,    48,    49,
      39,    91,    43,   217,    50,    91,   311,  -104,    45,   226,
     109,   110,   111,   112,   113,   280,   150,   109,   110,   111,
     112,   113,    54,   120,   121,   122,   123,   329,    56,   195,
     196,   234,   198,   199,    60,  -104,   293,    61,   340,    63,
    -104,  -104,    66,   294,   187,   188,   347,   332,   333,   260,
      71,    73,    75,   352,    79,    77,    96,   183,   102,   275,
     101,   104,   103,   359,   105,   -34,   146,   132,   273,   151,
     171,   285,   265,  -130,   175,   133,  -134,   244,   245,   246,
     247,   248,   249,   250,   251,   177,   252,   181,   253,   254,
     255,   256,   257,   258,   178,   262,   184,   186,   190,   191,
      11,   192,    12,   134,   135,   136,   137,   138,   139,   193,
     109,   110,   111,   112,   303,   265,   308,   208,   197,    -8,
     309,   -12,   210,   218,   -16,   -14,   220,    -6,    -6,    -6,
      -6,   -20,   -20,    91,   -18,   -22,   -24,   -20,   133,    -6,
     265,   230,   235,   316,   143,   238,   242,   -28,   231,   108,
     233,   239,   237,   283,   282,   298,   -10,   -10,    -6,    -6,
      -6,    -6,    -6,    -6,   274,   343,   134,   135,   136,   137,
     138,   139,   133,   286,   290,   302,   307,   314,   146,   312,
     313,   315,   109,   110,   111,   112,   113,   318,   322,   323,
     319,   325,   296,   297,   355,   327,   326,   300,   330,   336,
     134,   135,   136,   137,   138,   139,   157,   158,   159,   160,
     338,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     157,   158,   159,   160,   341,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   266,   267,   268,   269,   270,   271,
     157,   158,   159,   160,   337,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   105,   342,   345,   350,    95,   353,
     357,   358,   240,   366,   354,   361,   291,   364,   305,    38,
      62,     0,   278,     0,     0,     0,     0,     0,   363,     0,
       0,     0,   241,   157,   158,   159,   160,     0,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   157,   158,   159,
     160,     0,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   160,   243,   161,   162,   163,   164,
     165,   166,   167,   168,   169
};

static const yytype_int16 yycheck[] =
{
      24,    99,    97,    27,   114,   295,    95,     3,     0,    98,
      34,   180,   181,    37,    38,     3,    40,     0,    42,     3,
      44,   182,    46,    86,   185,    34,    21,    51,    47,     3,
     320,    55,     3,    57,    45,    98,    99,     8,    47,     3,
     259,   331,   261,    48,     8,     3,    42,    52,    48,   339,
      57,    58,    29,    30,    50,    20,   346,    26,    32,    33,
      22,    49,    25,   173,    38,    49,   356,    18,    35,   179,
      41,    42,    43,    44,    45,   236,   100,    41,    42,    43,
      44,    45,    36,    41,    42,    43,    44,   320,    37,   152,
     153,   189,   155,   156,    18,    46,   265,    45,   331,    40,
      51,    52,    28,   272,    51,    52,   339,    23,    24,   219,
      45,    45,    45,   346,    18,    47,    47,   141,    45,   229,
      34,     3,    45,   356,    52,    45,   189,     3,   223,    38,
      18,   241,   221,    46,    46,    31,    46,   200,   201,   202,
     203,   204,   205,   206,   207,    45,   209,    50,   211,   212,
     213,   214,   215,   216,    18,    51,    46,    46,     3,    46,
       1,     3,     3,    59,    60,    61,    62,    63,    64,    48,
      41,    42,    43,    44,   284,   264,    47,    13,    18,    20,
      51,    22,    14,    51,    25,    26,    51,    28,    29,    30,
      31,    32,    33,    49,    35,    36,    37,    38,    31,    40,
     289,    48,    53,   301,     3,    25,    34,    48,    47,     8,
      47,    45,    47,    39,    45,   278,    57,    58,    59,    60,
      61,    62,    63,    64,    47,   335,    59,    60,    61,    62,
      63,    64,    31,    38,    46,    46,     3,     3,   301,    48,
      48,    48,    41,    42,    43,    44,    45,    45,    48,    51,
      47,    46,   276,   277,   349,    39,    52,   281,    47,    46,
      59,    60,    61,    62,    63,    64,     4,     5,     6,     7,
      48,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       4,     5,     6,     7,    47,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    59,    60,    61,    62,    63,    64,
       4,     5,     6,     7,   328,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    52,    45,    48,    52,    67,    48,
      48,    46,    46,   365,   348,    47,   264,    48,   289,    16,
      30,    -1,   234,    -1,    -1,    -1,    -1,    -1,   362,    -1,
      -1,    -1,    46,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,    46,     9,    10,    11,    12,
      13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,    57,    58,   191,   192,    21,    47,
      68,     1,     3,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,   111,    48,    52,   193,   112,   115,
      48,    29,    30,    80,    81,   152,    20,   149,   191,    22,
     120,    26,   133,    25,   130,    35,   142,     3,    32,    33,
      38,    94,   100,   105,    36,    92,    37,    90,    69,    69,
      18,    45,   192,    40,    82,    69,    28,    89,   150,    69,
      69,    45,    69,    45,    69,    45,    69,    47,    69,    18,
      95,    98,   101,    69,    93,    69,    91,    69,   113,   116,
       3,    49,    83,   108,   118,    82,    47,   121,   134,   131,
     143,    34,    45,    45,     3,    52,   194,     3,     8,    41,
      42,    43,    44,    45,   161,   189,     3,   161,   196,     3,
      41,    42,    43,    44,   155,   190,    84,   109,     3,    42,
      50,   146,     3,    31,    59,    60,    61,    62,    63,    64,
     188,   151,   196,     3,   136,   139,   161,   188,   139,   188,
      69,    38,    96,    99,   102,   170,   176,     4,     5,     6,
       7,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     194,    18,    18,   114,   156,    46,   158,    45,    18,   147,
     119,    50,   110,    69,    46,   141,    46,    51,    52,   195,
       3,    46,     3,    48,   106,   161,   161,    18,   161,   161,
     162,   163,   165,   164,   166,   167,   168,   169,    13,   171,
      14,   172,   173,   174,   175,   197,   198,   194,    51,   117,
      51,    85,    34,   148,   177,   178,   194,   118,   118,   147,
      48,    47,   147,    47,   139,    53,   140,    47,    25,    45,
      46,    46,    34,    46,   161,   161,   161,   161,   161,   161,
     161,   161,   161,   161,   161,   161,   161,   161,   161,   157,
     194,   159,    51,   153,   160,   188,    59,    60,    61,    62,
      63,    64,   187,   196,    47,   194,   122,   135,   195,   137,
     147,   132,    45,    39,    97,   194,    38,   155,   155,   154,
      46,   153,     3,   118,   118,   179,    69,    69,   161,   138,
      69,   144,    46,   194,   103,   160,    86,     3,    47,    51,
     180,   189,    48,    48,     3,    48,   139,   107,    45,    47,
     185,   182,    48,    51,   123,    46,    52,    39,    87,   180,
      47,   181,    23,    24,   124,   145,    46,    69,    48,   183,
     180,    47,    45,   194,   104,    48,   186,   180,   125,   126,
      52,    88,   180,    48,    69,   196,   184,    48,    46,   180,
     127,    47,   128,    69,    48,   129,   124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    67,    68,    66,    66,    70,    69,    71,    69,
      72,    69,    73,    69,    74,    69,    75,    69,    76,    69,
      77,    69,    78,    69,    79,    69,    69,    69,    69,    80,
      81,    81,    82,    82,    84,    85,    86,    87,    88,    83,
      89,    89,    91,    90,    93,    92,    95,    96,    97,    94,
      98,    99,    94,    94,    94,   101,   102,   103,   104,   100,
     106,   107,   105,   109,   108,   110,   108,   112,   113,   114,
     111,   115,   116,   117,   111,   118,   119,   118,   118,   121,
     122,   123,   120,   125,   124,   126,   127,   128,   129,   124,
     124,   131,   132,   130,   134,   135,   133,   136,   137,   138,
     136,   139,   140,   139,   141,   139,   139,   143,   144,   145,
     142,   146,   146,   148,   147,   147,   147,   150,   151,   149,
     152,   152,   152,   153,   154,   153,   153,   156,   157,   155,
     155,   158,   159,   155,   155,   155,   160,   160,   160,   162,
     161,   163,   161,   164,   161,   165,   161,   166,   161,   167,
     161,   168,   161,   169,   161,   170,   161,   171,   161,   172,
     161,   173,   161,   174,   161,   175,   161,   176,   161,   161,
     161,   161,   161,   177,   178,   179,   177,   181,   180,   182,
     183,   184,   180,   185,   186,   180,   180,   180,   187,   187,
     187,   187,   187,   187,   188,   188,   188,   188,   188,   188,
     188,   189,   189,   189,   189,   190,   190,   190,   190,   191,
     191,   192,   192,   193,   193,   194,   194,   195,   195,   196,
     197,   196,   198,   196,   196
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     2,     3,     0,     4,
       3,     3,     1,     0,     0,     0,     0,     0,     0,    12,
       1,     0,     0,     4,     0,     3,     0,     0,     0,     8,
       0,     0,     7,     1,     1,     0,     0,     0,     0,    13,
       0,     0,    10,     0,     4,     0,     5,     0,     0,     0,
       7,     0,     0,     0,     8,     4,     0,     4,     0,     0,
       0,     0,    11,     0,     5,     0,     0,     0,     0,    12,
       0,     0,     0,     9,     0,     0,     9,     5,     0,     0,
       6,     1,     0,     4,     0,     3,     0,     0,     0,     0,
      12,     1,     1,     0,     3,     2,     0,     0,     0,     6,
       1,     1,     0,     2,     0,     3,     0,     0,     0,     5,
       1,     0,     0,     5,     1,     0,     2,     3,     0,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     3,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       3,     1,     1,     3,     0,     0,     5,     0,     4,     0,
       0,     0,     8,     0,     0,     6,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     1,     0,     1,     1,     1,
       0,     4,     0,     4,     0
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
#line 118 "java2cpp.y"
                  { print_init(); }
#line 1820 "y.tab.c"
    break;

  case 3:
#line 118 "java2cpp.y"
                                                              {push_scope("global");printf("/* start Main Class */\n"); }
#line 1826 "y.tab.c"
    break;

  case 4:
#line 118 "java2cpp.y"
                                                                                                                                                      {pop_scope(); printf("\n/* end Main Class */\n"); verify_fun_table();exit(0); }
#line 1832 "y.tab.c"
    break;

  case 5:
#line 119 "java2cpp.y"
                                                { printf("\n"); exit(2); }
#line 1838 "y.tab.c"
    break;

  case 6:
#line 122 "java2cpp.y"
                  { print_tabs(); }
#line 1844 "y.tab.c"
    break;

  case 7:
#line 122 "java2cpp.y"
                                                           { }
#line 1850 "y.tab.c"
    break;

  case 8:
#line 123 "java2cpp.y"
                          { print_tabs(); }
#line 1856 "y.tab.c"
    break;

  case 9:
#line 123 "java2cpp.y"
                                                                               { }
#line 1862 "y.tab.c"
    break;

  case 10:
#line 124 "java2cpp.y"
                          { print_tabs(); }
#line 1868 "y.tab.c"
    break;

  case 11:
#line 124 "java2cpp.y"
                                                               { }
#line 1874 "y.tab.c"
    break;

  case 12:
#line 125 "java2cpp.y"
                          { print_tabs(); }
#line 1880 "y.tab.c"
    break;

  case 13:
#line 125 "java2cpp.y"
                                                                    { }
#line 1886 "y.tab.c"
    break;

  case 14:
#line 126 "java2cpp.y"
                          { print_tabs(); }
#line 1892 "y.tab.c"
    break;

  case 15:
#line 126 "java2cpp.y"
                                                                { }
#line 1898 "y.tab.c"
    break;

  case 16:
#line 127 "java2cpp.y"
                          { print_tabs(); }
#line 1904 "y.tab.c"
    break;

  case 17:
#line 127 "java2cpp.y"
                                                                  { }
#line 1910 "y.tab.c"
    break;

  case 18:
#line 128 "java2cpp.y"
                          { print_tabs(); }
#line 1916 "y.tab.c"
    break;

  case 19:
#line 128 "java2cpp.y"
                                                                     { }
#line 1922 "y.tab.c"
    break;

  case 20:
#line 129 "java2cpp.y"
                          { print_tabs(); }
#line 1928 "y.tab.c"
    break;

  case 21:
#line 129 "java2cpp.y"
                                                             { }
#line 1934 "y.tab.c"
    break;

  case 22:
#line 130 "java2cpp.y"
                          { print_tabs(); }
#line 1940 "y.tab.c"
    break;

  case 23:
#line 130 "java2cpp.y"
                                                                { }
#line 1946 "y.tab.c"
    break;

  case 24:
#line 131 "java2cpp.y"
                          { print_tabs(); }
#line 1952 "y.tab.c"
    break;

  case 25:
#line 131 "java2cpp.y"
                                                                 { }
#line 1958 "y.tab.c"
    break;

  case 26:
#line 132 "java2cpp.y"
                                     { }
#line 1964 "y.tab.c"
    break;

  case 28:
#line 134 "java2cpp.y"
                                { }
#line 1970 "y.tab.c"
    break;

  case 32:
#line 142 "java2cpp.y"
                               {printf("const ");current_constant=1;}
#line 1976 "y.tab.c"
    break;

  case 34:
#line 144 "java2cpp.y"
                {push_scope(yylval.var_name);printf("%s", yylval.var_name);insert_funtion(yylval.var_name,current_data_type,1); }
#line 1982 "y.tab.c"
    break;

  case 35:
#line 144 "java2cpp.y"
                                                                                                                                    { printf("("); }
#line 1988 "y.tab.c"
    break;

  case 36:
#line 144 "java2cpp.y"
                                                                                                                                                               { printf(")"); }
#line 1994 "y.tab.c"
    break;

  case 37:
#line 144 "java2cpp.y"
                                                                                                                                                                                        { tab_counter++; printf("{\n"); }
#line 2000 "y.tab.c"
    break;

  case 38:
#line 144 "java2cpp.y"
                                                                                                                                                                                                                                        { printf("}\n"); tab_counter--;pop_scope(); }
#line 2006 "y.tab.c"
    break;

  case 39:
#line 144 "java2cpp.y"
                                                                                                                                                                                                                                                                                        { }
#line 2012 "y.tab.c"
    break;

  case 42:
#line 150 "java2cpp.y"
                         { printf("return "); }
#line 2018 "y.tab.c"
    break;

  case 43:
#line 150 "java2cpp.y"
                                                                         { printf("\n"); }
#line 2024 "y.tab.c"
    break;

  case 44:
#line 153 "java2cpp.y"
                        { printf("break"); }
#line 2030 "y.tab.c"
    break;

  case 45:
#line 153 "java2cpp.y"
                                                            { printf("\n"); }
#line 2036 "y.tab.c"
    break;

  case 46:
#line 156 "java2cpp.y"
                  { printf("std::cout"); }
#line 2042 "y.tab.c"
    break;

  case 47:
#line 156 "java2cpp.y"
                                              { printf(" << "); }
#line 2048 "y.tab.c"
    break;

  case 48:
#line 156 "java2cpp.y"
                                                                               { printf(" <<  std::endl"); }
#line 2054 "y.tab.c"
    break;

  case 49:
#line 156 "java2cpp.y"
                                                                                                                            { printf("\n"); }
#line 2060 "y.tab.c"
    break;

  case 50:
#line 157 "java2cpp.y"
                        { printf("std::cout"); }
#line 2066 "y.tab.c"
    break;

  case 51:
#line 157 "java2cpp.y"
                                                    { printf(" << "); }
#line 2072 "y.tab.c"
    break;

  case 52:
#line 157 "java2cpp.y"
                                                                                                    { printf("\n"); }
#line 2078 "y.tab.c"
    break;

  case 55:
#line 163 "java2cpp.y"
                         { printf("std::string "); }
#line 2084 "y.tab.c"
    break;

  case 56:
#line 163 "java2cpp.y"
                                                         { printf("%s;", yylval.var_name); }
#line 2090 "y.tab.c"
    break;

  case 57:
#line 163 "java2cpp.y"
                                                                                                                    {printf("std::cin");}
#line 2096 "y.tab.c"
    break;

  case 58:
#line 163 "java2cpp.y"
                                                                                                                                                       {printf(">>");}
#line 2102 "y.tab.c"
    break;

  case 59:
#line 163 "java2cpp.y"
                                                                                                                                                                                 { printf("%s;", yylval.var_name); }
#line 2108 "y.tab.c"
    break;

  case 60:
#line 167 "java2cpp.y"
                                       {printf("std::cin");}
#line 2114 "y.tab.c"
    break;

  case 61:
#line 167 "java2cpp.y"
                                                                          {printf(">>");}
#line 2120 "y.tab.c"
    break;

  case 62:
#line 167 "java2cpp.y"
                                                                                                    { printf("%s;", yylval.var_name); }
#line 2126 "y.tab.c"
    break;

  case 63:
#line 170 "java2cpp.y"
                        {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); {clear_exp_vect('\0');}}
#line 2132 "y.tab.c"
    break;

  case 64:
#line 170 "java2cpp.y"
                                                                                                                                                                   { printf("\n"); check_syntax_errors(); print_type_error_warning();}
#line 2138 "y.tab.c"
    break;

  case 65:
#line 171 "java2cpp.y"
                                                              {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); }
#line 2144 "y.tab.c"
    break;

  case 66:
#line 171 "java2cpp.y"
                                                                                                                                                                                 { printf("\n"); check_syntax_errors(); }
#line 2150 "y.tab.c"
    break;

  case 67:
#line 174 "java2cpp.y"
               { print_tabs(); printf("%s", yylval.var_name);verify_scope(yylval.var_name);check_constant(yylval.var_name); clear_exp_vect('\0'); left_val_type = lookup_in_table(yylval.var_name);}
#line 2156 "y.tab.c"
    break;

  case 68:
#line 174 "java2cpp.y"
                                                                                                                                                                                                                { printf(" = "); }
#line 2162 "y.tab.c"
    break;

  case 69:
#line 174 "java2cpp.y"
                                                                                                                                                                                                                                                   {type_verification();}
#line 2168 "y.tab.c"
    break;

  case 70:
#line 174 "java2cpp.y"
                                                                                                                                                                                                                                                                                         { printf("\n"); check_syntax_errors(); print_type_error_warning(); }
#line 2174 "y.tab.c"
    break;

  case 71:
#line 175 "java2cpp.y"
                                             { print_tabs(); printf("%s", yylval.var_name);insert_funtion(yylval.var_name,current_data_type,0);}
#line 2180 "y.tab.c"
    break;

  case 72:
#line 175 "java2cpp.y"
                                                                                                                                                    { printf("("); }
#line 2186 "y.tab.c"
    break;

  case 73:
#line 175 "java2cpp.y"
                                                                                                                                                                                    { printf(")"); }
#line 2192 "y.tab.c"
    break;

  case 74:
#line 175 "java2cpp.y"
                                                                                                                                                                                                                    { printf("\n"); check_syntax_errors(); print_type_error_warning(); }
#line 2198 "y.tab.c"
    break;

  case 76:
#line 179 "java2cpp.y"
                                  { bracket_counter++; }
#line 2204 "y.tab.c"
    break;

  case 79:
#line 184 "java2cpp.y"
                        { printf("if (");create_scope_name_and_push_it(); }
#line 2210 "y.tab.c"
    break;

  case 80:
#line 184 "java2cpp.y"
                                                                                                  { tab_counter++; printf(") {\n"); check_syntax_errors(); }
#line 2216 "y.tab.c"
    break;

  case 81:
#line 184 "java2cpp.y"
                                                                                                                                                                           { pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2222 "y.tab.c"
    break;

  case 83:
#line 187 "java2cpp.y"
                          {create_scope_name_and_push_it(); tab_counter++; printf(" else {\n"); }
#line 2228 "y.tab.c"
    break;

  case 84:
#line 187 "java2cpp.y"
                                                                                                                {pop_scope();tab_counter--; print_tabs(); printf("}"); }
#line 2234 "y.tab.c"
    break;

  case 85:
#line 188 "java2cpp.y"
                                            { printf(" else if ("); }
#line 2240 "y.tab.c"
    break;

  case 86:
#line 188 "java2cpp.y"
                                                                                         { printf(")"); check_syntax_errors(); }
#line 2246 "y.tab.c"
    break;

  case 87:
#line 188 "java2cpp.y"
                                                                                                                                    {create_scope_name_and_push_it();tab_counter++; printf(") {\n"); }
#line 2252 "y.tab.c"
    break;

  case 88:
#line 188 "java2cpp.y"
                                                                                                                                                                                                                     { pop_scope();tab_counter--;print_tabs(); printf("}"); }
#line 2258 "y.tab.c"
    break;

  case 90:
#line 189 "java2cpp.y"
                                        { printf("\n"); }
#line 2264 "y.tab.c"
    break;

  case 91:
#line 192 "java2cpp.y"
                       {create_scope_name_and_push_it();printf("while ("); }
#line 2270 "y.tab.c"
    break;

  case 92:
#line 192 "java2cpp.y"
                                                                                             { tab_counter++; printf("){\n"); }
#line 2276 "y.tab.c"
    break;

  case 93:
#line 192 "java2cpp.y"
                                                                                                                                              {pop_scope();tab_counter--; print_tabs(); printf("}\n"); }
#line 2282 "y.tab.c"
    break;

  case 94:
#line 197 "java2cpp.y"
                         {create_scope_name_and_push_it(); printf("for ("); }
#line 2288 "y.tab.c"
    break;

  case 95:
#line 197 "java2cpp.y"
                                                                                               { tab_counter++; printf(") {\n"); check_syntax_errors(); }
#line 2294 "y.tab.c"
    break;

  case 96:
#line 197 "java2cpp.y"
                                                                                                                                                                        {pop_scope(); tab_counter--; print_tabs(); printf("}\n"); }
#line 2300 "y.tab.c"
    break;

  case 98:
#line 201 "java2cpp.y"
                                         { printf("%s", yylval.var_name); }
#line 2306 "y.tab.c"
    break;

  case 99:
#line 201 "java2cpp.y"
                                                                            { printf(" : "); }
#line 2312 "y.tab.c"
    break;

  case 100:
#line 201 "java2cpp.y"
                                                                                                   { printf("%s", yylval.var_name); }
#line 2318 "y.tab.c"
    break;

  case 102:
#line 205 "java2cpp.y"
                                   {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); }
#line 2324 "y.tab.c"
    break;

  case 104:
#line 206 "java2cpp.y"
                              {verify_scope(yylval.var_name);printf("%s", yylval.var_name); }
#line 2330 "y.tab.c"
    break;

  case 106:
#line 207 "java2cpp.y"
                                 { }
#line 2336 "y.tab.c"
    break;

  case 107:
#line 210 "java2cpp.y"
                        { printf("do{\n"); tab_counter++;}
#line 2342 "y.tab.c"
    break;

  case 108:
#line 210 "java2cpp.y"
                                                                                  {tab_counter--; print_tabs(); printf("}while("); }
#line 2348 "y.tab.c"
    break;

  case 109:
#line 210 "java2cpp.y"
                                                                                                                                                  { printf(")"); }
#line 2354 "y.tab.c"
    break;

  case 110:
#line 210 "java2cpp.y"
                                                                                                                                                                                  { printf("\n"); }
#line 2360 "y.tab.c"
    break;

  case 111:
#line 214 "java2cpp.y"
                           { printf("[%s]", yylval.var_name); }
#line 2366 "y.tab.c"
    break;

  case 112:
#line 215 "java2cpp.y"
                                  { printf("[%s]", yylval.var_name); }
#line 2372 "y.tab.c"
    break;

  case 113:
#line 218 "java2cpp.y"
                             { printf(" = "); }
#line 2378 "y.tab.c"
    break;

  case 114:
#line 218 "java2cpp.y"
                                                                {type_verification();}
#line 2384 "y.tab.c"
    break;

  case 116:
#line 220 "java2cpp.y"
                                                              {}
#line 2390 "y.tab.c"
    break;

  case 117:
#line 223 "java2cpp.y"
                                      { push_scope("main");printf("int main(int argc, char **argv)"); }
#line 2396 "y.tab.c"
    break;

  case 118:
#line 223 "java2cpp.y"
                                                                                                           { tab_counter++; printf("{\n"); }
#line 2402 "y.tab.c"
    break;

  case 119:
#line 223 "java2cpp.y"
                                                                                                                                                           { printf("\n}\n"); tab_counter--; pop_scope();}
#line 2408 "y.tab.c"
    break;

  case 124:
#line 234 "java2cpp.y"
                           { printf(","); }
#line 2414 "y.tab.c"
    break;

  case 126:
#line 235 "java2cpp.y"
                                                        { printf(" "); }
#line 2420 "y.tab.c"
    break;

  case 127:
#line 237 "java2cpp.y"
                  {printf("%s", yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2426 "y.tab.c"
    break;

  case 128:
#line 237 "java2cpp.y"
                                                                                              { printf(","); }
#line 2432 "y.tab.c"
    break;

  case 130:
#line 238 "java2cpp.y"
                             {printf("%s", yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2438 "y.tab.c"
    break;

  case 131:
#line 239 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2444 "y.tab.c"
    break;

  case 132:
#line 239 "java2cpp.y"
                                                                                        { printf(","); }
#line 2450 "y.tab.c"
    break;

  case 134:
#line 240 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2456 "y.tab.c"
    break;

  case 136:
#line 244 "java2cpp.y"
                           {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name);insert_type_param(current_data_type); }
#line 2462 "y.tab.c"
    break;

  case 137:
#line 245 "java2cpp.y"
                                                        {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name);printf("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--)printf("[%d]",DIMENSION);}
#line 2468 "y.tab.c"
    break;

  case 139:
#line 249 "java2cpp.y"
                                 { printf(" && "); }
#line 2474 "y.tab.c"
    break;

  case 141:
#line 250 "java2cpp.y"
                                        { printf(" || "); }
#line 2480 "y.tab.c"
    break;

  case 143:
#line 251 "java2cpp.y"
                                        { printf(" <= "); }
#line 2486 "y.tab.c"
    break;

  case 145:
#line 252 "java2cpp.y"
                                        { printf(" >= "); }
#line 2492 "y.tab.c"
    break;

  case 147:
#line 253 "java2cpp.y"
                                       { printf(" > "); }
#line 2498 "y.tab.c"
    break;

  case 149:
#line 254 "java2cpp.y"
                                       { printf(" < "); }
#line 2504 "y.tab.c"
    break;

  case 151:
#line 255 "java2cpp.y"
                                        { printf(" != "); }
#line 2510 "y.tab.c"
    break;

  case 153:
#line 256 "java2cpp.y"
                                        { printf(" == "); }
#line 2516 "y.tab.c"
    break;

  case 155:
#line 257 "java2cpp.y"
                              { printf("!"); }
#line 2522 "y.tab.c"
    break;

  case 157:
#line 258 "java2cpp.y"
                                         { printf(" + "); add_exp_vect('+');}
#line 2528 "y.tab.c"
    break;

  case 159:
#line 259 "java2cpp.y"
                                          { printf(" - "); add_exp_vect('-');}
#line 2534 "y.tab.c"
    break;

  case 161:
#line 260 "java2cpp.y"
                                        { printf(" * "); add_exp_vect('*');}
#line 2540 "y.tab.c"
    break;

  case 163:
#line 261 "java2cpp.y"
                                        { printf(" / "); add_exp_vect('/'); }
#line 2546 "y.tab.c"
    break;

  case 165:
#line 262 "java2cpp.y"
                                        { printf(" %% "); }
#line 2552 "y.tab.c"
    break;

  case 167:
#line 263 "java2cpp.y"
                             { printf("("); add_exp_vect('(');}
#line 2558 "y.tab.c"
    break;

  case 168:
#line 263 "java2cpp.y"
                                                                             { printf(")"); add_exp_vect(')');}
#line 2564 "y.tab.c"
    break;

  case 169:
#line 264 "java2cpp.y"
                                              { printf("++"); }
#line 2570 "y.tab.c"
    break;

  case 170:
#line 265 "java2cpp.y"
                                                { printf("--"); }
#line 2576 "y.tab.c"
    break;

  case 172:
#line 267 "java2cpp.y"
                              { printf("%s", yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
#line 2582 "y.tab.c"
    break;

  case 173:
#line 270 "java2cpp.y"
                                                  {bracket_counter=0;}
#line 2588 "y.tab.c"
    break;

  case 174:
#line 271 "java2cpp.y"
                                          { for(;bracket_counter>0;bracket_counter--)printf("[]"); }
#line 2594 "y.tab.c"
    break;

  case 175:
#line 271 "java2cpp.y"
                                                                                                        { printf(" = {"); }
#line 2600 "y.tab.c"
    break;

  case 176:
#line 271 "java2cpp.y"
                                                                                                                                                          { printf("}"); }
#line 2606 "y.tab.c"
    break;

  case 177:
#line 274 "java2cpp.y"
                                                { printf(","); }
#line 2612 "y.tab.c"
    break;

  case 179:
#line 275 "java2cpp.y"
                                                               { printf(","); }
#line 2618 "y.tab.c"
    break;

  case 180:
#line 275 "java2cpp.y"
                                                                                   { printf("{"); }
#line 2624 "y.tab.c"
    break;

  case 181:
#line 275 "java2cpp.y"
                                                                                                                                  { printf("}"); }
#line 2630 "y.tab.c"
    break;

  case 183:
#line 276 "java2cpp.y"
                                                              { printf("{"); }
#line 2636 "y.tab.c"
    break;

  case 184:
#line 276 "java2cpp.y"
                                                                                                             { printf("}"); }
#line 2642 "y.tab.c"
    break;

  case 194:
#line 289 "java2cpp.y"
              { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type);	printf("int "); }
#line 2648 "y.tab.c"
    break;

  case 195:
#line 290 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("char "); }
#line 2654 "y.tab.c"
    break;

  case 196:
#line 291 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("float "); }
#line 2660 "y.tab.c"
    break;

  case 197:
#line 292 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("double "); }
#line 2666 "y.tab.c"
    break;

  case 198:
#line 293 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("std::string "); }
#line 2672 "y.tab.c"
    break;

  case 199:
#line 294 "java2cpp.y"
                          { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); printf("bool "); }
#line 2678 "y.tab.c"
    break;

  case 200:
#line 295 "java2cpp.y"
                       { printf("void "); }
#line 2684 "y.tab.c"
    break;

  case 201:
#line 298 "java2cpp.y"
                         { printf("%s", yylval.var_name); add_exp_vect(48+T_INT); }
#line 2690 "y.tab.c"
    break;

  case 202:
#line 299 "java2cpp.y"
                                      { printf("%s", yylval.var_name); add_exp_vect(48+T_CHAR); }
#line 2696 "y.tab.c"
    break;

  case 203:
#line 300 "java2cpp.y"
                                        { printf("%s", yylval.var_name); add_exp_vect(48+T_STRING); }
#line 2702 "y.tab.c"
    break;

  case 204:
#line 301 "java2cpp.y"
                                   { printf("%s", yylval.var_name); add_exp_vect(48+T_BOOL); }
#line 2708 "y.tab.c"
    break;

  case 205:
#line 303 "java2cpp.y"
                                 { printf("%s", yylval.var_name); current_data_type=T_INT;}
#line 2714 "y.tab.c"
    break;

  case 206:
#line 304 "java2cpp.y"
                                      { printf("%s", yylval.var_name); current_data_type=T_CHAR; }
#line 2720 "y.tab.c"
    break;

  case 207:
#line 305 "java2cpp.y"
                                        { printf("%s", yylval.var_name); current_data_type=T_STRING; }
#line 2726 "y.tab.c"
    break;

  case 208:
#line 306 "java2cpp.y"
                                   { printf("%s", yylval.var_name); current_data_type=T_BOOL; }
#line 2732 "y.tab.c"
    break;

  case 209:
#line 309 "java2cpp.y"
                                { printf("%s\n", yylval.var_name); }
#line 2738 "y.tab.c"
    break;

  case 210:
#line 310 "java2cpp.y"
                                        { printf("%s", yylval.var_name); }
#line 2744 "y.tab.c"
    break;

  case 213:
#line 317 "java2cpp.y"
                            { }
#line 2750 "y.tab.c"
    break;

  case 214:
#line 318 "java2cpp.y"
                             { printf("}\n"); }
#line 2756 "y.tab.c"
    break;

  case 215:
#line 321 "java2cpp.y"
                            { printf(";"); }
#line 2762 "y.tab.c"
    break;

  case 216:
#line 322 "java2cpp.y"
                                            { yyerror("Syntax error: expected ';' at end of declaration"); }
#line 2768 "y.tab.c"
    break;

  case 217:
#line 325 "java2cpp.y"
                                    { printf(";"); }
#line 2774 "y.tab.c"
    break;

  case 218:
#line 326 "java2cpp.y"
                                               { printf(","); strcat(syntax_errors,"Syntax error: expected ';' instead of ','\t"); }
#line 2780 "y.tab.c"
    break;

  case 220:
#line 330 "java2cpp.y"
                                                 { printf("%s", yylval.var_name); printf("="); }
#line 2786 "y.tab.c"
    break;

  case 221:
#line 330 "java2cpp.y"
                                                                                                           { }
#line 2792 "y.tab.c"
    break;

  case 222:
#line 331 "java2cpp.y"
                                                       { printf("="); }
#line 2798 "y.tab.c"
    break;

  case 223:
#line 331 "java2cpp.y"
                                                                                  { strcat(syntax_errors,"Syntax error: expected '==' operator\n"); }
#line 2804 "y.tab.c"
    break;

  case 224:
#line 332 "java2cpp.y"
                                            { strcat(syntax_errors,"Syntax error: expected expresion\n"); }
#line 2810 "y.tab.c"
    break;


#line 2814 "y.tab.c"

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
#line 335 "java2cpp.y"


#include "lex.yy.c"
void print_table_symbols(){
		printf("\n");
		for(int i=0; i<table_idx; i++)
		{	
			printf("%d var=%s Scope=%s type=%d\n",i,sym[i].var_name,sym[i].scope_name,sym[i].type);			
		}
}
int check_constant(char var[MAX_NAME_LEN]){
	int is_correct=0;
	for(int j=stack_scope_counter;j>=0;j--)
	for(int i=0; i<table_idx; i++)
	{	
		if(strcmp(sym[i].var_name, var)==0 &&
		 strcmp(sym[i].scope_name, stack_scope[j])==0 ){
			if(sym[i].is_constant)
				break;
			is_correct=1;
			break;
			}
	}
	if(!is_correct){
		printf("\nVariable %s was declared as a const \n",var);
		yyerror("");
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
			break;
			}
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
		sym[table_idx].is_constant=current_constant;
		current_constant=0;
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
void verify_fun_table(){
	struct fun_table temp;
	for(int i=0;i<table_idf;i++){
		if(!fun[i].is_def){
			temp=fun[i];
			int check=0;
			for(int j=0;j<table_idf;j++){
				if(fun[j].is_def){
					if(strcmp(fun[j].var_name,temp.var_name) == 0 && fun[j].counter_type_params == temp.counter_type_params){
						int check_type=1;
						for(int z=0;z<temp.counter_type_params;z++){
							if(fun[j].type_params[z] != temp.type_params[z])
								check_type=0;
						}
						check =check_type?1:0;
						
					}
				}
			}	
			if(!check){
			char type[20]={0},arguments[200]={0};
			convert_type_to_string(type,fun[i].type);
			get_format_string_types(arguments,fun[i]);
			printf("\n Function %s %s(%s) has not been declared \n",type,fun[i].var_name,arguments);
			break;
		}
		}		
	}
	//If the loop end, everything ok
	write_fun_table_header_file();

}
void write_fun_table_header_file(){
	FILE *fp;

   fp = fopen("fun.h", "w+");
   char fun_decl[300];
	for(int i=0;i<table_idf;i++){
		if(fun[i].is_def){
			char type[20]={0},arguments[200]={0};
			convert_type_to_string(type,fun[i].type);
			get_format_string_types(arguments,fun[i]);
			sprintf(fun_decl," %s %s(%s)\n",type,fun[i].var_name,arguments);
			fputs(fun_decl,fp);
		}
	}
	fclose(fp);
}
void get_format_string_types(char dest[200],struct fun_table source){
	int c=0;
	for(int z=0;z<source.counter_type_params;z++){
		switch(source.type_params[z]){
			case T_INT:
				strcat(dest,"int,");
				c+=4;
				break;
			case T_CHAR:
				strcat(dest,"char,");
				c+=5;
				break;
			case T_FLOAT:
				strcat(dest,"float,");
				c+=6;
				break;
			case T_DOUBLE:
				strcat(dest,"double,");
				c+=7;
				break;
			case T_STRING:
				strcat(dest,"string,");
				c+=7;
				break;
			case T_BOOL:
				strcat(dest,"bool,");
				c+=5;
				break;
		}
	}
		dest[c-1]='\0'; //Remove the last coma

}
void convert_type_to_string(char dest[20],int type){
			switch(type){
			case T_INT:
				strcat(dest,"int");
				break;
			case T_CHAR:
				strcat(dest,"char");
				break;
			case T_FLOAT:
				strcat(dest,"float");
				break;
			case T_DOUBLE:
				strcat(dest,"double");
				break;
			case T_STRING:
				strcat(dest,"string");
				break;
			case T_BOOL:
				strcat(dest,"bool");
				break;
			}
}
