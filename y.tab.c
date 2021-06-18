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
	#define AUXFILE "auxjava2cpp.txt"
	#define CFILE "java2cpp_translation.cc"
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
	int error_counter=0;
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
	extern int merge_files();
	extern int console_msg();
	extern void write_to_file(char *s);
	extern void print_check_constant_result();
	extern void print_multidecl_error();

	char check_constant_result[256] = "";
	char multiple_decl_msg[256] = "";
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

	FILE *fp_aux;


	// functions
		void append_init(FILE *fp){
		time_t t = time(NULL);
  		struct tm now = *localtime(&t);
		char version_msg[32];
		char owners_msg[128];
		char date_msg[128];

		char *version = "alpha 1.0";
		char owners[2][64] = {{"https://github.com/martinezlucas98"},{"https://github.com/Joaquinecc"}};
		char aux[54];

		sprintf(version_msg, "*\tVersion:\t%s\n", version);
		sprintf(owners_msg, "*\tCode owners:\t%s\n", owners[0]);
		snprintf(aux,70,"*\t\t\t%s\n",owners[1]);
		strcat(owners_msg,aux);
		sprintf(date_msg, "*\tTranslated on:\t%d-%02d-%02d %02d:%02d:%02d (yyyy-MM-dd hh:mm:ss)\n", now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);

		fputs("/*\n*\t===================================================================\n",fp);
		fputs("*\tTranslated from java to c++ using java2cpp\n",fp);
		fputs(version_msg,fp);
		fputs(owners_msg,fp);
		fputs(date_msg,fp);
		fputs("*\t===================================================================\n*/\n\n",fp);
		fputs("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n",fp);
	}

	void print_init(){
		printf("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n");
	}


#line 187 "y.tab.c"

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
#line 118 "java2cpp.y"

int data_type;
char var_name[MAX_NAME_LEN];

#line 369 "y.tab.c"

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
#define YYLAST   374

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  142
/* YYNRULES -- Number of rules.  */
#define YYNRULES  237
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  386

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
       0,   146,   146,   146,   146,   146,   146,   147,   150,   150,
     151,   151,   152,   152,   153,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   158,   158,   159,   159,   160,   161,
     162,   165,   167,   168,   170,   171,   172,   172,   172,   172,
     172,   172,   174,   175,   178,   178,   181,   181,   184,   184,
     184,   184,   185,   185,   185,   186,   186,   186,   186,   186,
     186,   189,   190,   190,   191,   192,   192,   192,   196,   196,
     197,   197,   200,   200,   200,   200,   201,   201,   201,   201,
     202,   202,   202,   202,   205,   206,   209,   210,   210,   211,
     214,   214,   214,   214,   217,   217,   218,   218,   218,   218,
     218,   219,   222,   222,   222,   227,   227,   227,   230,   231,
     231,   231,   234,   235,   235,   236,   236,   237,   240,   240,
     240,   240,   244,   245,   248,   248,   249,   250,   253,   253,
     253,   258,   259,   260,   263,   264,   264,   265,   267,   267,
     267,   268,   269,   269,   269,   270,   271,   274,   275,   276,
     279,   279,   280,   280,   281,   281,   282,   282,   283,   283,
     284,   284,   285,   285,   286,   286,   287,   287,   288,   288,
     289,   289,   290,   290,   291,   291,   292,   292,   293,   293,
     294,   295,   296,   297,   298,   298,   301,   302,   302,   302,
     305,   305,   306,   306,   306,   306,   307,   307,   307,   308,
     309,   312,   313,   314,   315,   316,   317,   320,   321,   322,
     323,   324,   325,   326,   329,   330,   331,   332,   334,   335,
     336,   337,   340,   341,   344,   345,   348,   349,   352,   353,
     356,   357,   360,   361,   361,   362,   362,   363
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
  "STRING", "BOOLEAN", "$accept", "program", "$@1", "$@2", "$@3", "$@4",
  "STATEMENTS", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "IGNORE_SCOPE", "DECLARATION", "CONST", "METHODS",
  "$@15", "$@16", "$@17", "$@18", "$@19", "IS_STATIC", "RETURN_ST", "$@20",
  "BREAK_ST", "$@21", "STDIO", "$@22", "$@23", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "EXPRESSION_OUT", "$@32", "$@33",
  "$@34", "VAR_DECLARATION", "$@35", "$@36", "VAR_USE", "$@37", "$@38",
  "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "MULTI_NUMARRAY",
  "BRACKET_ARRAY", "$@46", "IF_STATEMENT", "$@47", "$@48", "$@49",
  "ELSE_VARIATIONS", "$@50", "$@51", "$@52", "$@53", "$@54", "WHILE_LOOP",
  "$@55", "$@56", "FOR_LOOP", "$@57", "$@58", "FOR_PARAMS", "$@59", "$@60",
  "DECL_EXPR", "$@61", "$@62", "DO_WHILE_LOOP", "$@63", "$@64", "$@65",
  "NUMARRAY", "HAS_ASSIGNMENT", "$@66", "MAIN_METHOD_DECLARATION", "$@67",
  "$@68", "SCOPE", "PARAMS", "$@69", "PARAMS_TYPE", "$@70", "$@71", "$@72",
  "$@73", "HAS_PARAMS", "EXPRESION", "$@74", "$@75", "$@76", "$@77",
  "$@78", "$@79", "$@80", "$@81", "$@82", "$@83", "$@84", "$@85", "$@86",
  "$@87", "$@88", "$@89", "EXPRESION_ARRAY", "$@90", "$@91",
  "EXPRESION_ARRAY_INITIALIZE", "$@92", "$@93", "$@94", "$@95", "$@96",
  "$@97", "TYPE_NO_PRINT", "TYPE", "TERMINAL", "LITERAL_ARGUMENT",
  "COMMENT", "HAS_COMMENT", "DELIMITER", "MUST_SEMICOLON",
  "SEMICOLON_NOT_COMA", "MUST_EXPRESSION", "$@98", "$@99", YY_NULLPTR
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

#define YYPACT_NINF (-248)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-188)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      39,    56,   -16,  -248,  -248,  -248,  -248,    29,    44,  -248,
     250,    10,    18,    48,    50,    45,   -16,    75,    72,    87,
      80,    13,    94,    79,   250,  -248,  -248,   250,   113,    88,
      85,  -248,  -248,  -248,    95,   250,   119,  -248,   250,   250,
     109,   250,   116,   250,   126,   250,   125,   250,  -248,  -248,
    -248,   250,  -248,   250,  -248,   250,  -248,  -248,  -248,  -248,
       6,  -248,  -248,    15,  -248,  -248,    95,   128,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   132,   133,
     170,  -248,   135,  -248,    32,  -248,    84,    78,  -248,  -248,
     130,   -16,   143,     5,  -248,  -248,   187,   240,  -248,    84,
      41,    41,   250,  -248,  -248,  -248,  -248,  -248,   144,  -248,
    -248,  -248,  -248,  -248,  -248,   153,  -248,     4,   334,  -248,
     145,  -248,  -248,  -248,  -248,   146,   148,   147,  -248,   154,
     182,  -248,   151,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,   250,   160,     8,   161,    19,   357,   205,   164,
     208,   165,   142,   142,   194,   168,    32,    32,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,   201,   202,  -248,  -248,
    -248,  -248,  -248,  -248,   135,   169,  -248,   171,     6,   207,
    -248,    -4,   135,   174,   174,   182,   185,   188,   182,   189,
    -248,  -248,    41,   184,   191,  -248,   214,   228,   197,   231,
     199,  -248,     6,  -248,   314,    32,    32,    32,    32,    32,
      32,    32,    32,  -248,    32,  -248,    32,    32,    32,    32,
      32,    32,  -248,  -248,   135,  -248,   196,  -248,   167,   195,
      84,  -248,   200,  -248,  -248,  -248,   135,  -248,  -248,  -248,
    -248,    19,  -248,   182,  -248,   216,   237,  -248,  -248,   135,
     218,   212,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,   357,   357,    78,  -248,
      78,   147,    84,  -248,   219,   167,    17,  -248,  -248,  -248,
    -248,  -248,  -248,   174,  -248,  -248,  -248,   250,   250,    32,
    -248,  -248,   250,  -248,  -248,   135,   142,  -248,   229,   147,
    -248,  -248,  -248,  -248,   240,  -248,  -248,  -248,   263,  -248,
      66,   225,   226,   357,   274,   236,    41,   142,  -248,  -248,
    -248,  -248,   135,  -248,   242,  -248,  -248,  -248,   243,   241,
    -248,  -248,  -248,  -248,   247,  -248,   249,  -248,  -248,    66,
     248,  -248,  -248,    70,  -248,   257,   250,   258,  -248,    66,
     268,   252,  -248,   135,   259,   269,  -248,    66,  -248,  -248,
    -248,  -248,  -248,  -248,    66,   284,   250,    84,   264,  -248,
    -248,  -248,   285,   288,  -248,    66,  -248,  -248,  -248,   289,
    -248,   250,   287,  -248,    70,  -248
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   225,     1,   222,   223,   224,     0,     0,     3,
       0,     0,    72,     0,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   227,   226,     0,     0,     0,
       0,     4,   131,   132,    35,     0,    43,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    52,
      55,     0,    46,     0,    44,     0,    28,    29,    73,    77,
       0,     5,    34,     0,     9,    42,    35,     0,    11,    13,
      90,    15,   105,    17,   102,    19,   118,    21,     0,     0,
       0,    23,   229,    25,     0,    27,   237,   146,   123,   122,
       0,   225,    68,     0,    32,    33,     0,     0,   129,   237,
     117,   117,     0,    49,    53,    56,   228,    47,   183,   166,
     217,   214,   216,   215,   178,   229,   182,   183,   232,    74,
     138,   221,   218,   220,   219,     0,   142,    85,     6,     0,
     127,    87,     0,    70,   213,   207,   208,   209,   210,   211,
     212,    31,     0,     0,   183,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   150,   152,
     156,   154,   158,   160,   162,   164,   168,   170,   172,   174,
     176,    45,   233,   235,   229,     0,    78,     0,     0,     0,
      37,   124,   229,    89,    89,   127,     0,     0,   127,     0,
     231,   230,   117,   113,     0,   113,     0,    64,     0,    61,
       0,    57,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,     0,   181,     0,     0,     0,     0,
       0,     0,    75,   139,   229,   143,     0,    81,   137,     0,
     237,   126,     0,    69,    88,    86,   229,   130,    91,   116,
     106,     0,   109,   127,   103,     0,     0,    50,    62,   229,
       0,     0,   179,   151,   153,   157,   155,   159,   161,   163,
     165,   169,   171,   173,   175,   177,   234,   236,   146,    79,
     146,    85,   237,   135,     0,   137,     0,   201,   202,   203,
     204,   205,   206,    89,   125,   188,    71,     0,     0,     0,
     110,   114,     0,   119,    66,   229,     0,    54,     0,    85,
     140,   144,    84,    82,   149,    38,   134,   147,     0,   186,
     200,     0,     0,   108,     0,     0,   117,     0,    51,    63,
      58,   185,   229,   136,     0,   148,   196,   192,     0,   199,
      92,   107,   111,   104,     0,    67,     0,    83,    39,   200,
       0,   189,   190,   101,   120,     0,     0,     0,   193,   200,
       0,     0,    93,   229,     0,     0,   197,   200,   191,    94,
      96,   121,    59,    40,   200,     0,     0,   237,     0,    41,
     198,   194,     0,     0,    60,   200,    95,    97,   195,     0,
      98,     0,     0,    99,   101,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -248,  -248,  -248,  -248,  -248,  -248,   -24,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,   271,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -141,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -247,
    -177,  -248,  -248,  -248,  -248,  -248,   -31,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   -97,  -248,  -248,  -248,  -248,  -248,  -248,   -88,  -175,
    -248,  -248,  -248,  -248,  -248,    81,  -248,  -234,  -248,  -248,
    -248,  -248,    51,   -68,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,  -248,  -248,  -160,  -248,  -248,  -248,  -248,  -248,  -248,
    -248,   -72,  -115,  -248,   338,   267,  -248,  -113,   118,   -98,
    -248,  -248
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    10,    61,    91,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    34,    35,    63,
      94,   129,   228,   324,   346,   369,    66,    55,    84,    53,
      82,    51,    78,   152,   295,    79,   153,    80,   154,   250,
     336,   368,   198,   296,   246,   317,    95,   130,   185,    24,
      28,    86,   174,    29,    87,   224,    30,   272,   322,   179,
      96,   183,    41,    99,   287,   343,   352,   366,   367,   379,
     381,   384,    45,   101,   292,    43,   100,   288,   145,   290,
     314,   146,   243,   188,    47,   102,   316,   353,    90,   182,
     230,    38,    67,   142,    36,   274,   304,   125,   175,   268,
     177,   270,   275,   118,   205,   206,   208,   207,   209,   210,
     211,   212,   156,   214,   216,   217,   218,   219,   157,   155,
     231,   232,   310,   328,   349,   340,   357,   375,   339,   364,
     283,   150,   116,   126,     6,     7,    27,   107,   192,   119,
     220,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   143,   171,    57,   149,   132,   234,   235,    88,    88,
     236,    64,   200,   239,    68,    69,   115,    71,    92,    73,
     307,    75,   172,    77,   302,   141,  -115,    81,   148,    83,
     229,    85,   147,   147,   300,   108,   301,   199,   199,    -7,
     109,     4,     5,  -187,   144,    48,    49,    89,    89,   109,
       8,    50,   321,  -184,  -115,   131,     3,  -184,    25,  -115,
    -115,   222,    26,   -76,    93,    37,    93,   -80,   291,   233,
     190,   191,   134,   110,   111,   112,   113,   114,   151,    32,
      33,   120,   110,   111,   112,   113,   114,   117,   203,   204,
     226,     9,   109,   350,   351,   241,    31,    40,    42,   308,
     135,   136,   137,   138,   139,   140,   309,   110,   111,   112,
     113,   269,    44,   326,   251,    46,    54,   327,   186,   121,
     122,   123,   124,   286,   147,   110,   111,   112,   113,   114,
      52,    58,   284,    59,    60,    62,   297,   253,   254,   255,
     256,   257,   258,   259,   260,   197,   261,    65,   262,   263,
     264,   265,   266,   267,    70,   319,   276,   158,   159,   160,
     161,    72,   162,   163,   164,   165,   166,   167,   168,   169,
     170,    74,    76,   105,   303,    98,   335,   103,   104,   347,
     127,   199,   318,   110,   111,   112,   113,   106,   -36,   358,
     133,  -141,   176,  -184,  -145,   329,   178,   365,   134,   180,
     181,   184,   199,   276,   370,   106,   187,   189,   193,   337,
     194,   195,   201,   196,   213,   378,   215,   202,   273,   334,
     223,   313,   225,    93,   329,   227,   135,   136,   137,   138,
     139,   140,   276,   237,   329,   238,   240,   242,   244,   245,
     361,   -65,   329,   247,   248,   249,   271,   285,   147,   329,
     294,    11,   298,    12,   277,   278,   279,   280,   281,   282,
     329,   293,   299,   311,   312,   305,   325,   320,   315,   373,
     -10,   134,   -14,   330,   331,   -18,   -16,   332,    -8,    -8,
      -8,    -8,   -22,   -22,   333,   -20,   -24,   -26,   -22,   338,
      -8,   341,   342,   344,   345,   348,   354,   360,   -30,   135,
     136,   137,   138,   139,   140,   362,   356,   -12,   -12,    -8,
      -8,    -8,    -8,    -8,    -8,   359,   374,   363,   158,   159,
     160,   161,   355,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   371,   376,   377,   383,   380,    97,   158,   159,
     160,   161,   372,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   173,   385,    39,   323,   306,   382,   128,   289,
     252,   158,   159,   160,   161,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170
};

static const yytype_int16 yycheck[] =
{
      24,    99,   115,    27,   101,    93,   183,   184,     3,     3,
     185,    35,   153,   188,    38,    39,    84,    41,     3,    43,
       3,    45,    18,    47,   271,    97,    18,    51,   100,    53,
      34,    55,   100,   101,   268,     3,   270,   152,   153,     0,
       8,    57,    58,    47,     3,    32,    33,    42,    42,     8,
      21,    38,   299,    49,    46,    50,     0,    49,    48,    51,
      52,   174,    52,    45,    49,    20,    49,    49,   243,   182,
      51,    52,    31,    41,    42,    43,    44,    45,   102,    29,
      30,     3,    41,    42,    43,    44,    45,     3,   156,   157,
     178,    47,     8,    23,    24,   192,    48,    22,    26,   276,
      59,    60,    61,    62,    63,    64,   283,    41,    42,    43,
      44,   224,    25,    47,   202,    35,    37,    51,   142,    41,
      42,    43,    44,   236,   192,    41,    42,    43,    44,    45,
      36,    18,   230,    45,    49,    40,   249,   205,   206,   207,
     208,   209,   210,   211,   212,     3,   214,    28,   216,   217,
     218,   219,   220,   221,    45,   296,   228,     4,     5,     6,
       7,    45,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    45,    47,     3,   272,    47,   317,    45,    45,   339,
      50,   296,   295,    41,    42,    43,    44,    52,    45,   349,
       3,    46,    46,    49,    46,   310,    49,   357,    31,    45,
      18,    50,   317,   275,   364,    52,    46,    46,     3,   322,
      46,     3,    18,    48,    13,   375,    14,    49,    51,   316,
      51,   289,    51,    49,   339,    18,    59,    60,    61,    62,
      63,    64,   304,    48,   349,    47,    47,    53,    47,    25,
     353,    13,   357,    46,    13,    46,    50,    47,   316,   364,
      13,     1,    34,     3,    59,    60,    61,    62,    63,    64,
     375,    45,    50,   287,   288,    46,     3,    38,   292,   367,
      20,    31,    22,    48,    48,    25,    26,     3,    28,    29,
      30,    31,    32,    33,    48,    35,    36,    37,    38,    47,
      40,    48,    51,    46,    45,    47,    39,    45,    48,    59,
      60,    61,    62,    63,    64,    46,    48,    57,    58,    59,
      60,    61,    62,    63,    64,    47,    52,    48,     4,     5,
       6,     7,   346,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    48,    48,    46,    48,    47,    66,     4,     5,
       6,     7,   366,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,   384,    16,   304,   275,   381,    91,   241,
      46,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,    57,    58,   199,   200,    21,    47,
      68,     1,     3,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,   114,    48,    52,   201,   115,   118,
     121,    48,    29,    30,    82,    83,   159,    20,   156,   199,
      22,   127,    26,   140,    25,   137,    35,   149,    32,    33,
      38,    96,    36,    94,    37,    92,    71,    71,    18,    45,
      49,    69,    40,    84,    71,    28,    91,   157,    71,    71,
      45,    71,    45,    71,    45,    71,    47,    71,    97,   100,
     102,    71,    95,    71,    93,    71,   116,   119,     3,    42,
     153,    70,     3,    49,    85,   111,   125,    84,    47,   128,
     141,   138,   150,    45,    45,     3,    52,   202,     3,     8,
      41,    42,    43,    44,    45,   168,   197,     3,   168,   204,
       3,    41,    42,    43,    44,   162,   198,    50,   200,    86,
     112,    50,   153,     3,    31,    59,    60,    61,    62,    63,
      64,   196,   158,   204,     3,   143,   146,   168,   196,   146,
     196,    71,    98,   101,   103,   184,   177,   183,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,   202,    18,    18,   117,   163,    46,   165,    49,   124,
      45,    18,   154,   126,    50,   113,    71,    46,   148,    46,
      51,    52,   203,     3,    46,     3,    48,     3,   107,   197,
     107,    18,    49,   168,   168,   169,   170,   172,   171,   173,
     174,   175,   176,    13,   178,    14,   179,   180,   181,   182,
     205,   206,   202,    51,   120,    51,   153,    18,    87,    34,
     155,   185,   186,   202,   125,   125,   154,    48,    47,   154,
      47,   146,    53,   147,    47,    25,   109,    46,    13,    46,
     104,   153,    46,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   164,   202,
     166,    50,   122,    51,   160,   167,   196,    59,    60,    61,
      62,    63,    64,   195,   204,    47,   202,   129,   142,   203,
     144,   154,   139,    45,    13,    99,   108,   202,    34,    50,
     162,   162,   124,   204,   161,    46,   160,     3,   125,   125,
     187,    71,    71,   168,   145,    71,   151,   110,   202,   107,
      38,   124,   123,   167,    88,     3,    47,    51,   188,   197,
      48,    48,     3,    48,   146,   107,   105,   202,    47,   193,
     190,    48,    51,   130,    46,    45,    89,   188,    47,   189,
      23,    24,   131,   152,    39,    71,    48,   191,   188,    47,
      45,   202,    46,    48,   194,   188,   132,   133,   106,    90,
     188,    48,    71,   204,    52,   192,    48,    46,   188,   134,
      47,   135,    71,    48,   136,   131
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    67,    68,    69,    70,    66,    66,    72,    71,
      73,    71,    74,    71,    75,    71,    76,    71,    77,    71,
      78,    71,    79,    71,    80,    71,    81,    71,    71,    71,
      71,    82,    83,    83,    84,    84,    86,    87,    88,    89,
      90,    85,    91,    91,    93,    92,    95,    94,    97,    98,
      99,    96,   100,   101,    96,   102,   103,   104,   105,   106,
      96,   107,   108,   107,   107,   109,   110,   107,   112,   111,
     113,   111,   115,   116,   117,   114,   118,   119,   120,   114,
     121,   122,   123,   114,   124,   124,   125,   126,   125,   125,
     128,   129,   130,   127,   132,   131,   133,   134,   135,   136,
     131,   131,   138,   139,   137,   141,   142,   140,   143,   144,
     145,   143,   146,   147,   146,   148,   146,   146,   150,   151,
     152,   149,   153,   153,   155,   154,   154,   154,   157,   158,
     156,   159,   159,   159,   160,   161,   160,   160,   163,   164,
     162,   162,   165,   166,   162,   162,   162,   167,   167,   167,
     169,   168,   170,   168,   171,   168,   172,   168,   173,   168,
     174,   168,   175,   168,   176,   168,   177,   168,   178,   168,
     179,   168,   180,   168,   181,   168,   182,   168,   183,   168,
     168,   168,   168,   168,   184,   168,   185,   186,   187,   185,
     189,   188,   190,   191,   192,   188,   193,   194,   188,   188,
     188,   195,   195,   195,   195,   195,   195,   196,   196,   196,
     196,   196,   196,   196,   197,   197,   197,   197,   198,   198,
     198,   198,   199,   199,   200,   200,   201,   201,   202,   202,
     203,   203,   204,   205,   204,   206,   204,   204
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     0,     0,    10,     0,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     0,     3,     0,     3,     0,     3,     2,     3,
       0,     4,     3,     3,     1,     0,     0,     0,     0,     0,
       0,    12,     1,     0,     0,     4,     0,     3,     0,     0,
       0,     8,     0,     0,     7,     0,     0,     0,     0,     0,
      14,     1,     0,     4,     1,     0,     0,     5,     0,     4,
       0,     5,     0,     0,     0,     7,     0,     0,     0,     8,
       0,     0,     0,    11,     4,     0,     4,     0,     4,     0,
       0,     0,     0,    11,     0,     5,     0,     0,     0,     0,
      12,     0,     0,     0,     9,     0,     0,     9,     5,     0,
       0,     6,     1,     0,     4,     0,     3,     0,     0,     0,
       0,    12,     1,     1,     0,     3,     2,     0,     0,     0,
       6,     1,     1,     0,     2,     0,     3,     0,     0,     0,
       5,     1,     0,     0,     5,     1,     0,     2,     3,     0,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     3,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     3,     1,     1,     0,     6,     3,     0,     0,     5,
       0,     4,     0,     0,     0,     8,     0,     0,     6,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     1,     1,     1,     0,
       1,     1,     1,     0,     4,     0,     4,     0
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
#line 146 "java2cpp.y"
                  { fp_aux = fopen(AUXFILE,"w"); }
#line 1855 "y.tab.c"
    break;

  case 3:
#line 146 "java2cpp.y"
                                                                             {push_scope("global"); write_to_file("\n/* start Main Class */\n\n"); }
#line 1861 "y.tab.c"
    break;

  case 4:
#line 146 "java2cpp.y"
                                                                                                                                                                     {pop_scope(); write_to_file("\n/* end Main Class */\n"); verify_fun_table(); fclose(fp_aux); merge_files();}
#line 1867 "y.tab.c"
    break;

  case 5:
#line 146 "java2cpp.y"
                                                                                                                                                                                                                                                                                 {fp_aux = fopen(CFILE,"a");}
#line 1873 "y.tab.c"
    break;

  case 6:
#line 146 "java2cpp.y"
                                                                                                                                                                                                                                                                                                                        {fclose(fp_aux); console_msg(); exit(0); }
#line 1879 "y.tab.c"
    break;

  case 7:
#line 147 "java2cpp.y"
                                                { write_to_file("\n"); exit(2); }
#line 1885 "y.tab.c"
    break;

  case 8:
#line 150 "java2cpp.y"
                  { print_tabs(); }
#line 1891 "y.tab.c"
    break;

  case 9:
#line 150 "java2cpp.y"
                                                           { }
#line 1897 "y.tab.c"
    break;

  case 10:
#line 151 "java2cpp.y"
                          { print_tabs(); }
#line 1903 "y.tab.c"
    break;

  case 11:
#line 151 "java2cpp.y"
                                                                               { }
#line 1909 "y.tab.c"
    break;

  case 12:
#line 152 "java2cpp.y"
                          { print_tabs(); }
#line 1915 "y.tab.c"
    break;

  case 13:
#line 152 "java2cpp.y"
                                                               { }
#line 1921 "y.tab.c"
    break;

  case 14:
#line 153 "java2cpp.y"
                          { print_tabs(); }
#line 1927 "y.tab.c"
    break;

  case 15:
#line 153 "java2cpp.y"
                                                                    { }
#line 1933 "y.tab.c"
    break;

  case 16:
#line 154 "java2cpp.y"
                          { print_tabs(); }
#line 1939 "y.tab.c"
    break;

  case 17:
#line 154 "java2cpp.y"
                                                                { }
#line 1945 "y.tab.c"
    break;

  case 18:
#line 155 "java2cpp.y"
                          { print_tabs(); }
#line 1951 "y.tab.c"
    break;

  case 19:
#line 155 "java2cpp.y"
                                                                  { }
#line 1957 "y.tab.c"
    break;

  case 20:
#line 156 "java2cpp.y"
                          { print_tabs(); }
#line 1963 "y.tab.c"
    break;

  case 21:
#line 156 "java2cpp.y"
                                                                     { }
#line 1969 "y.tab.c"
    break;

  case 22:
#line 157 "java2cpp.y"
                          { print_tabs(); }
#line 1975 "y.tab.c"
    break;

  case 23:
#line 157 "java2cpp.y"
                                                             { }
#line 1981 "y.tab.c"
    break;

  case 24:
#line 158 "java2cpp.y"
                          { print_tabs(); }
#line 1987 "y.tab.c"
    break;

  case 25:
#line 158 "java2cpp.y"
                                                                { }
#line 1993 "y.tab.c"
    break;

  case 26:
#line 159 "java2cpp.y"
                          { print_tabs(); }
#line 1999 "y.tab.c"
    break;

  case 27:
#line 159 "java2cpp.y"
                                                                 { }
#line 2005 "y.tab.c"
    break;

  case 28:
#line 160 "java2cpp.y"
                                     { }
#line 2011 "y.tab.c"
    break;

  case 30:
#line 162 "java2cpp.y"
                                { }
#line 2017 "y.tab.c"
    break;

  case 34:
#line 170 "java2cpp.y"
                               { write_to_file("const "); current_constant=1; }
#line 2023 "y.tab.c"
    break;

  case 36:
#line 172 "java2cpp.y"
                {push_scope(yylval.var_name);write_to_file(yylval.var_name);insert_funtion(yylval.var_name,current_data_type,1); }
#line 2029 "y.tab.c"
    break;

  case 37:
#line 172 "java2cpp.y"
                                                                                                                                     { write_to_file("("); }
#line 2035 "y.tab.c"
    break;

  case 38:
#line 172 "java2cpp.y"
                                                                                                                                                                       { write_to_file(")"); }
#line 2041 "y.tab.c"
    break;

  case 39:
#line 172 "java2cpp.y"
                                                                                                                                                                                                        { tab_counter++; write_to_file("{\n"); }
#line 2047 "y.tab.c"
    break;

  case 40:
#line 172 "java2cpp.y"
                                                                                                                                                                                                                                                               { write_to_file("}\n"); tab_counter--;pop_scope(); }
#line 2053 "y.tab.c"
    break;

  case 41:
#line 172 "java2cpp.y"
                                                                                                                                                                                                                                                                                                                        { }
#line 2059 "y.tab.c"
    break;

  case 44:
#line 178 "java2cpp.y"
                         { write_to_file("return "); }
#line 2065 "y.tab.c"
    break;

  case 45:
#line 178 "java2cpp.y"
                                                                                { write_to_file("\n"); }
#line 2071 "y.tab.c"
    break;

  case 46:
#line 181 "java2cpp.y"
                        { write_to_file("break"); }
#line 2077 "y.tab.c"
    break;

  case 47:
#line 181 "java2cpp.y"
                                                                   { write_to_file("\n"); }
#line 2083 "y.tab.c"
    break;

  case 48:
#line 184 "java2cpp.y"
                  { write_to_file("std::cout"); }
#line 2089 "y.tab.c"
    break;

  case 49:
#line 184 "java2cpp.y"
                                                     { write_to_file(" << "); }
#line 2095 "y.tab.c"
    break;

  case 50:
#line 184 "java2cpp.y"
                                                                                                  { write_to_file(" <<  std::endl"); }
#line 2101 "y.tab.c"
    break;

  case 51:
#line 184 "java2cpp.y"
                                                                                                                                                      { write_to_file("\n"); }
#line 2107 "y.tab.c"
    break;

  case 52:
#line 185 "java2cpp.y"
                        { write_to_file("std::cout"); }
#line 2113 "y.tab.c"
    break;

  case 53:
#line 185 "java2cpp.y"
                                                           { write_to_file(" << "); }
#line 2119 "y.tab.c"
    break;

  case 54:
#line 185 "java2cpp.y"
                                                                                                                       { write_to_file("\n"); }
#line 2125 "y.tab.c"
    break;

  case 55:
#line 186 "java2cpp.y"
                          { write_to_file("std::string "); }
#line 2131 "y.tab.c"
    break;

  case 56:
#line 186 "java2cpp.y"
                                                                 { write_to_file(yylval.var_name);}
#line 2137 "y.tab.c"
    break;

  case 57:
#line 186 "java2cpp.y"
                                                                                                               {write_to_file(";\n");}
#line 2143 "y.tab.c"
    break;

  case 58:
#line 186 "java2cpp.y"
                                                                                                                                                   {print_tabs();write_to_file("std::cin");}
#line 2149 "y.tab.c"
    break;

  case 59:
#line 186 "java2cpp.y"
                                                                                                                                                                                                          {write_to_file(" >> ");}
#line 2155 "y.tab.c"
    break;

  case 60:
#line 186 "java2cpp.y"
                                                                                                                                                                                                                                             { write_to_file(yylval.var_name); write_to_file(";\n");}
#line 2161 "y.tab.c"
    break;

  case 62:
#line 190 "java2cpp.y"
                                                {write_to_file(" << ");}
#line 2167 "y.tab.c"
    break;

  case 64:
#line 191 "java2cpp.y"
                                      { write_to_file(yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
#line 2173 "y.tab.c"
    break;

  case 65:
#line 192 "java2cpp.y"
                                      { write_to_file(yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
#line 2179 "y.tab.c"
    break;

  case 66:
#line 192 "java2cpp.y"
                                                                                                                                                                         {write_to_file(" << ");}
#line 2185 "y.tab.c"
    break;

  case 68:
#line 196 "java2cpp.y"
                        {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name); {clear_exp_vect('\0');}}
#line 2191 "y.tab.c"
    break;

  case 69:
#line 196 "java2cpp.y"
                                                                                                                                                                    { write_to_file("\n"); check_syntax_errors(); print_type_error_warning();print_multidecl_error();}
#line 2197 "y.tab.c"
    break;

  case 70:
#line 197 "java2cpp.y"
                                                              {insert_to_table(yylval.var_name,current_data_type);write_to_file(yylval.var_name); }
#line 2203 "y.tab.c"
    break;

  case 71:
#line 197 "java2cpp.y"
                                                                                                                                                                                  { write_to_file("\n"); check_syntax_errors(); print_multidecl_error();}
#line 2209 "y.tab.c"
    break;

  case 72:
#line 200 "java2cpp.y"
               { print_tabs(); write_to_file(yylval.var_name);verify_scope(yylval.var_name);check_constant(yylval.var_name); clear_exp_vect('\0'); left_val_type = lookup_in_table(yylval.var_name);}
#line 2215 "y.tab.c"
    break;

  case 73:
#line 200 "java2cpp.y"
                                                                                                                                                                                                                 { write_to_file(" = "); }
#line 2221 "y.tab.c"
    break;

  case 74:
#line 200 "java2cpp.y"
                                                                                                                                                                                                                                                           {type_verification();}
#line 2227 "y.tab.c"
    break;

  case 75:
#line 200 "java2cpp.y"
                                                                                                                                                                                                                                                                                                 { write_to_file("\n"); print_check_constant_result(); check_syntax_errors(); print_type_error_warning(); }
#line 2233 "y.tab.c"
    break;

  case 76:
#line 201 "java2cpp.y"
                                              { print_tabs(); write_to_file(yylval.var_name);insert_funtion(yylval.var_name,current_data_type,0);}
#line 2239 "y.tab.c"
    break;

  case 77:
#line 201 "java2cpp.y"
                                                                                                                                                      { write_to_file("("); }
#line 2245 "y.tab.c"
    break;

  case 78:
#line 201 "java2cpp.y"
                                                                                                                                                                                             { write_to_file(")"); }
#line 2251 "y.tab.c"
    break;

  case 79:
#line 201 "java2cpp.y"
                                                                                                                                                                                                                                    { write_to_file("\n"); check_syntax_errors(); print_type_error_warning(); }
#line 2257 "y.tab.c"
    break;

  case 80:
#line 202 "java2cpp.y"
                                          { print_tabs(); write_to_file(yylval.var_name);verify_scope(yylval.var_name);check_constant(yylval.var_name); clear_exp_vect('\0'); left_val_type = lookup_in_table(yylval.var_name);}
#line 2263 "y.tab.c"
    break;

  case 81:
#line 202 "java2cpp.y"
                                                                                                                                                                                                                                                                          { write_to_file(" = "); }
#line 2269 "y.tab.c"
    break;

  case 82:
#line 202 "java2cpp.y"
                                                                                                                                                                                                                                                                                                                    {type_verification();}
#line 2275 "y.tab.c"
    break;

  case 83:
#line 202 "java2cpp.y"
                                                                                                                                                                                                                                                                                                                                                          { write_to_file("\n"); print_check_constant_result(); check_syntax_errors(); print_type_error_warning(); }
#line 2281 "y.tab.c"
    break;

  case 87:
#line 210 "java2cpp.y"
                                  { bracket_counter++; }
#line 2287 "y.tab.c"
    break;

  case 90:
#line 214 "java2cpp.y"
                        { write_to_file("if (");create_scope_name_and_push_it(); }
#line 2293 "y.tab.c"
    break;

  case 91:
#line 214 "java2cpp.y"
                                                                                                         { tab_counter++; write_to_file(") {\n"); check_syntax_errors(); }
#line 2299 "y.tab.c"
    break;

  case 92:
#line 214 "java2cpp.y"
                                                                                                                                                                                         { pop_scope();tab_counter--; print_tabs(); write_to_file("}"); }
#line 2305 "y.tab.c"
    break;

  case 94:
#line 217 "java2cpp.y"
                          {create_scope_name_and_push_it(); tab_counter++; write_to_file(" else {\n"); }
#line 2311 "y.tab.c"
    break;

  case 95:
#line 217 "java2cpp.y"
                                                                                                                       {pop_scope();tab_counter--; print_tabs(); write_to_file("}"); }
#line 2317 "y.tab.c"
    break;

  case 96:
#line 218 "java2cpp.y"
                                            { write_to_file(" else if ("); }
#line 2323 "y.tab.c"
    break;

  case 97:
#line 218 "java2cpp.y"
                                                                                                { write_to_file(")"); check_syntax_errors(); }
#line 2329 "y.tab.c"
    break;

  case 98:
#line 218 "java2cpp.y"
                                                                                                                                                  {create_scope_name_and_push_it();tab_counter++; write_to_file(") {\n"); }
#line 2335 "y.tab.c"
    break;

  case 99:
#line 218 "java2cpp.y"
                                                                                                                                                                                                                                          { pop_scope();tab_counter--;print_tabs(); write_to_file("}"); }
#line 2341 "y.tab.c"
    break;

  case 101:
#line 219 "java2cpp.y"
                                        { write_to_file("\n"); }
#line 2347 "y.tab.c"
    break;

  case 102:
#line 222 "java2cpp.y"
                       {create_scope_name_and_push_it();write_to_file("while ("); }
#line 2353 "y.tab.c"
    break;

  case 103:
#line 222 "java2cpp.y"
                                                                                                    { tab_counter++; write_to_file("){\n"); }
#line 2359 "y.tab.c"
    break;

  case 104:
#line 222 "java2cpp.y"
                                                                                                                                                            {pop_scope();tab_counter--; print_tabs(); write_to_file("}\n"); }
#line 2365 "y.tab.c"
    break;

  case 105:
#line 227 "java2cpp.y"
                         {create_scope_name_and_push_it(); write_to_file("for ("); }
#line 2371 "y.tab.c"
    break;

  case 106:
#line 227 "java2cpp.y"
                                                                                                      { tab_counter++; write_to_file(") {\n"); check_syntax_errors(); }
#line 2377 "y.tab.c"
    break;

  case 107:
#line 227 "java2cpp.y"
                                                                                                                                                                                      {pop_scope(); tab_counter--; print_tabs(); write_to_file("}\n"); }
#line 2383 "y.tab.c"
    break;

  case 109:
#line 231 "java2cpp.y"
                                         { write_to_file(yylval.var_name); }
#line 2389 "y.tab.c"
    break;

  case 110:
#line 231 "java2cpp.y"
                                                                             { write_to_file(" : "); }
#line 2395 "y.tab.c"
    break;

  case 111:
#line 231 "java2cpp.y"
                                                                                                           { write_to_file(yylval.var_name); }
#line 2401 "y.tab.c"
    break;

  case 113:
#line 235 "java2cpp.y"
                                   {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name); }
#line 2407 "y.tab.c"
    break;

  case 115:
#line 236 "java2cpp.y"
                              {verify_scope(yylval.var_name);write_to_file(yylval.var_name); }
#line 2413 "y.tab.c"
    break;

  case 117:
#line 237 "java2cpp.y"
                                 { }
#line 2419 "y.tab.c"
    break;

  case 118:
#line 240 "java2cpp.y"
                        { write_to_file("do{\n"); tab_counter++;}
#line 2425 "y.tab.c"
    break;

  case 119:
#line 240 "java2cpp.y"
                                                                                         {tab_counter--; print_tabs(); write_to_file("}while("); }
#line 2431 "y.tab.c"
    break;

  case 120:
#line 240 "java2cpp.y"
                                                                                                                                                                { write_to_file(")"); }
#line 2437 "y.tab.c"
    break;

  case 121:
#line 240 "java2cpp.y"
                                                                                                                                                                                                       { write_to_file("\n"); }
#line 2443 "y.tab.c"
    break;

  case 122:
#line 244 "java2cpp.y"
                                { char s[MAX_NAME_LEN+3]; sprintf(s,"[%s]", yylval.var_name); write_to_file(s); }
#line 2449 "y.tab.c"
    break;

  case 123:
#line 245 "java2cpp.y"
                                        { char s[MAX_NAME_LEN+3]; sprintf(s,"[%s]", yylval.var_name); write_to_file(s); }
#line 2455 "y.tab.c"
    break;

  case 124:
#line 248 "java2cpp.y"
                             { write_to_file(" = "); }
#line 2461 "y.tab.c"
    break;

  case 125:
#line 248 "java2cpp.y"
                                                                       {type_verification();print_multidecl_error();}
#line 2467 "y.tab.c"
    break;

  case 126:
#line 249 "java2cpp.y"
                                                                     {print_multidecl_error();}
#line 2473 "y.tab.c"
    break;

  case 127:
#line 250 "java2cpp.y"
                                                              {}
#line 2479 "y.tab.c"
    break;

  case 128:
#line 253 "java2cpp.y"
                                      { push_scope("main");write_to_file("int main(int argc, char **argv)"); }
#line 2485 "y.tab.c"
    break;

  case 129:
#line 253 "java2cpp.y"
                                                                                                                  { tab_counter++; write_to_file("{\n"); }
#line 2491 "y.tab.c"
    break;

  case 130:
#line 253 "java2cpp.y"
                                                                                                                                                                         { write_to_file("\n}\n"); tab_counter--; pop_scope();}
#line 2497 "y.tab.c"
    break;

  case 135:
#line 264 "java2cpp.y"
                           { write_to_file(","); }
#line 2503 "y.tab.c"
    break;

  case 137:
#line 265 "java2cpp.y"
                                                        { write_to_file(" "); }
#line 2509 "y.tab.c"
    break;

  case 138:
#line 267 "java2cpp.y"
                  {write_to_file(yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2515 "y.tab.c"
    break;

  case 139:
#line 267 "java2cpp.y"
                                                                                               { write_to_file(","); }
#line 2521 "y.tab.c"
    break;

  case 141:
#line 268 "java2cpp.y"
                             {write_to_file(yylval.var_name);insert_argument_var( yylval.var_name);}
#line 2527 "y.tab.c"
    break;

  case 142:
#line 269 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2533 "y.tab.c"
    break;

  case 143:
#line 269 "java2cpp.y"
                                                                                        { write_to_file(","); }
#line 2539 "y.tab.c"
    break;

  case 145:
#line 270 "java2cpp.y"
                                           {insert_type_param(current_data_type);}
#line 2545 "y.tab.c"
    break;

  case 147:
#line 274 "java2cpp.y"
                           {insert_to_table(yylval.var_name,current_data_type);write_to_file(yylval.var_name);insert_type_param(current_data_type); print_multidecl_error();}
#line 2551 "y.tab.c"
    break;

  case 148:
#line 275 "java2cpp.y"
                                                        {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name);write_to_file("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--){char s[255];sprintf(s,"[%d]",DIMENSION);write_to_file(s);}print_multidecl_error();}
#line 2557 "y.tab.c"
    break;

  case 150:
#line 279 "java2cpp.y"
                                 { write_to_file(" && "); }
#line 2563 "y.tab.c"
    break;

  case 152:
#line 280 "java2cpp.y"
                                        { write_to_file(" || "); }
#line 2569 "y.tab.c"
    break;

  case 154:
#line 281 "java2cpp.y"
                                        { write_to_file(" <= "); }
#line 2575 "y.tab.c"
    break;

  case 156:
#line 282 "java2cpp.y"
                                        { write_to_file(" >= "); }
#line 2581 "y.tab.c"
    break;

  case 158:
#line 283 "java2cpp.y"
                                       { write_to_file(" > "); }
#line 2587 "y.tab.c"
    break;

  case 160:
#line 284 "java2cpp.y"
                                       { write_to_file(" < "); }
#line 2593 "y.tab.c"
    break;

  case 162:
#line 285 "java2cpp.y"
                                        { write_to_file(" != "); }
#line 2599 "y.tab.c"
    break;

  case 164:
#line 286 "java2cpp.y"
                                        { write_to_file(" == "); }
#line 2605 "y.tab.c"
    break;

  case 166:
#line 287 "java2cpp.y"
                              { write_to_file("!"); }
#line 2611 "y.tab.c"
    break;

  case 168:
#line 288 "java2cpp.y"
                                         { write_to_file(" + "); add_exp_vect('+');}
#line 2617 "y.tab.c"
    break;

  case 170:
#line 289 "java2cpp.y"
                                          { write_to_file(" - "); add_exp_vect('-');}
#line 2623 "y.tab.c"
    break;

  case 172:
#line 290 "java2cpp.y"
                                        { write_to_file(" * "); add_exp_vect('*');}
#line 2629 "y.tab.c"
    break;

  case 174:
#line 291 "java2cpp.y"
                                        { write_to_file(" / "); add_exp_vect('/'); }
#line 2635 "y.tab.c"
    break;

  case 176:
#line 292 "java2cpp.y"
                                        { write_to_file(" % "); }
#line 2641 "y.tab.c"
    break;

  case 178:
#line 293 "java2cpp.y"
                             { write_to_file("("); add_exp_vect('(');}
#line 2647 "y.tab.c"
    break;

  case 179:
#line 293 "java2cpp.y"
                                                                                    { write_to_file(")"); add_exp_vect(')');}
#line 2653 "y.tab.c"
    break;

  case 180:
#line 294 "java2cpp.y"
                                              { write_to_file("++"); }
#line 2659 "y.tab.c"
    break;

  case 181:
#line 295 "java2cpp.y"
                                                { write_to_file("--"); }
#line 2665 "y.tab.c"
    break;

  case 183:
#line 297 "java2cpp.y"
                              { write_to_file(yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
#line 2671 "y.tab.c"
    break;

  case 184:
#line 298 "java2cpp.y"
                              { write_to_file(yylval.var_name);verify_scope(yylval.var_name); }
#line 2677 "y.tab.c"
    break;

  case 186:
#line 301 "java2cpp.y"
                                                  {bracket_counter=0;}
#line 2683 "y.tab.c"
    break;

  case 187:
#line 302 "java2cpp.y"
                                          { for(;bracket_counter>0;bracket_counter--)write_to_file("[]"); }
#line 2689 "y.tab.c"
    break;

  case 188:
#line 302 "java2cpp.y"
                                                                                                               { write_to_file(" = {"); }
#line 2695 "y.tab.c"
    break;

  case 189:
#line 302 "java2cpp.y"
                                                                                                                                                                        { write_to_file("}"); }
#line 2701 "y.tab.c"
    break;

  case 190:
#line 305 "java2cpp.y"
                                                { write_to_file(","); }
#line 2707 "y.tab.c"
    break;

  case 192:
#line 306 "java2cpp.y"
                                                               { write_to_file(","); }
#line 2713 "y.tab.c"
    break;

  case 193:
#line 306 "java2cpp.y"
                                                                                          { write_to_file("{"); }
#line 2719 "y.tab.c"
    break;

  case 194:
#line 306 "java2cpp.y"
                                                                                                                                                { write_to_file("}"); }
#line 2725 "y.tab.c"
    break;

  case 196:
#line 307 "java2cpp.y"
                                                              { write_to_file("{"); }
#line 2731 "y.tab.c"
    break;

  case 197:
#line 307 "java2cpp.y"
                                                                                                                    { write_to_file("}"); }
#line 2737 "y.tab.c"
    break;

  case 207:
#line 320 "java2cpp.y"
              { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type);	write_to_file("int "); }
#line 2743 "y.tab.c"
    break;

  case 208:
#line 321 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); write_to_file("char "); }
#line 2749 "y.tab.c"
    break;

  case 209:
#line 322 "java2cpp.y"
                        { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); write_to_file("float "); }
#line 2755 "y.tab.c"
    break;

  case 210:
#line 323 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); write_to_file("double "); }
#line 2761 "y.tab.c"
    break;

  case 211:
#line 324 "java2cpp.y"
                         { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); write_to_file("std::string "); }
#line 2767 "y.tab.c"
    break;

  case 212:
#line 325 "java2cpp.y"
                          { (yyval.data_type)=(yyvsp[0].data_type); current_data_type=(yyvsp[0].data_type); write_to_file("bool "); }
#line 2773 "y.tab.c"
    break;

  case 213:
#line 326 "java2cpp.y"
                       { write_to_file("void "); }
#line 2779 "y.tab.c"
    break;

  case 214:
#line 329 "java2cpp.y"
                         { write_to_file(yylval.var_name); add_exp_vect(48+T_INT); }
#line 2785 "y.tab.c"
    break;

  case 215:
#line 330 "java2cpp.y"
                                      { write_to_file(yylval.var_name); add_exp_vect(48+T_CHAR); }
#line 2791 "y.tab.c"
    break;

  case 216:
#line 331 "java2cpp.y"
                                        { write_to_file(yylval.var_name); add_exp_vect(48+T_STRING); }
#line 2797 "y.tab.c"
    break;

  case 217:
#line 332 "java2cpp.y"
                                   { write_to_file(yylval.var_name); add_exp_vect(48+T_BOOL); }
#line 2803 "y.tab.c"
    break;

  case 218:
#line 334 "java2cpp.y"
                                 { write_to_file(yylval.var_name); current_data_type=T_INT;}
#line 2809 "y.tab.c"
    break;

  case 219:
#line 335 "java2cpp.y"
                                      { write_to_file(yylval.var_name); current_data_type=T_CHAR; }
#line 2815 "y.tab.c"
    break;

  case 220:
#line 336 "java2cpp.y"
                                        { write_to_file(yylval.var_name); current_data_type=T_STRING; }
#line 2821 "y.tab.c"
    break;

  case 221:
#line 337 "java2cpp.y"
                                   { write_to_file(yylval.var_name); current_data_type=T_BOOL; }
#line 2827 "y.tab.c"
    break;

  case 222:
#line 340 "java2cpp.y"
                                { write_to_file(yylval.var_name); write_to_file("\n"); }
#line 2833 "y.tab.c"
    break;

  case 223:
#line 341 "java2cpp.y"
                                        { write_to_file(yylval.var_name); write_to_file("\n"); }
#line 2839 "y.tab.c"
    break;

  case 226:
#line 348 "java2cpp.y"
                            { }
#line 2845 "y.tab.c"
    break;

  case 227:
#line 349 "java2cpp.y"
                             { write_to_file("}\n"); }
#line 2851 "y.tab.c"
    break;

  case 228:
#line 352 "java2cpp.y"
                            { write_to_file(";"); }
#line 2857 "y.tab.c"
    break;

  case 229:
#line 353 "java2cpp.y"
                                            { yyerror("Syntax error: expected ';' at end of declaration"); }
#line 2863 "y.tab.c"
    break;

  case 230:
#line 356 "java2cpp.y"
                                    { write_to_file(";"); }
#line 2869 "y.tab.c"
    break;

  case 231:
#line 357 "java2cpp.y"
                                               { write_to_file(","); strcat(syntax_errors,"Syntax error: expected ';' instead of ','\t"); }
#line 2875 "y.tab.c"
    break;

  case 233:
#line 361 "java2cpp.y"
                                                 { write_to_file(yylval.var_name); write_to_file("="); }
#line 2881 "y.tab.c"
    break;

  case 234:
#line 361 "java2cpp.y"
                                                                                                                   { }
#line 2887 "y.tab.c"
    break;

  case 235:
#line 362 "java2cpp.y"
                                                       { write_to_file("="); }
#line 2893 "y.tab.c"
    break;

  case 236:
#line 362 "java2cpp.y"
                                                                                         { strcat(syntax_errors,"Syntax error: cannot assign to an expression. Expected '==' operator\n"); }
#line 2899 "y.tab.c"
    break;

  case 237:
#line 363 "java2cpp.y"
                                            { strcat(syntax_errors,"Syntax error: expected expression\n"); }
#line 2905 "y.tab.c"
    break;


#line 2909 "y.tab.c"

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
#line 366 "java2cpp.y"


#include "lex.yy.c"
void print_table_symbols(){
		write_to_file("\n");
		for(int i=0; i<table_idx; i++)
		{	
			char str[256];
			sprintf(str,"%d var=%s Scope=%s type=%d\n",i,sym[i].var_name,sym[i].scope_name,sym[i].type);
			write_to_file(str);			
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
		char formatted_str[256];
		sprintf(formatted_str,"Cannot modify variable's value. Variable %s was declared as const \n",var);
		strcpy(check_constant_result,formatted_str);
	}

}

void print_check_constant_result(){
	if (strcmp(check_constant_result,"")){
		yyerror(check_constant_result);
		strcpy(check_constant_result,"");
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
		char formatted_str[256];
		sprintf(formatted_str,"Variable %s was not declared in the scope  \n",var);
		yyerror(formatted_str);
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
		char formatted_str[256];
		sprintf(formatted_str,"Multiple declaration of variable %s \n",var);
		strcat(multiple_decl_msg,formatted_str);
		//exit(0);
	}
}

void print_multidecl_error(){
	if(strcmp(multiple_decl_msg,"")){
		yyerror(multiple_decl_msg);
		strcpy(multiple_decl_msg,"");
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
		char formatted_str[256];
		sprintf(formatted_str,"Variable not declare %s \n",var);
		yyerror(formatted_str);
	}
}
void insert_type_param(int type){
	fun[table_idf -1].type_params[fun[table_idf -1].counter_type_params++]=type;
}
void print_tabs() {
	for(int i = 0; i < tab_counter; i++){
		write_to_file("\t");
	}
	return;
}

int main() {
	// clear files
	fclose(fopen(CFILE,"w"));
	fclose(fopen("fun.h","w"));
	fclose(fopen(AUXFILE,"w"));
	#if YYDEBUG
        yydebug = 1;
    #endif
	yyparse();
	return 0;
}

int yyerror(const char *msg) {
	extern int yylineno;
	int l = tab_counter*8;
	char formatted_msg[256];
	write_to_file("\n");

	for(int i=0; i<l;i++){
		write_to_file("^");
	}
	sprintf(formatted_msg,"\nError on java file line [%d] :: %s\n", yylineno, msg);
	write_to_file(formatted_msg);
	success = 0;
	error_counter++;
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
		printf("\nSCOPE STACK IS FULL\n");
		yyerror("\nSCOPE STACK IS FULL\n");
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
		}else{
			t = cast_type(type1, type2, operator);
		}
		
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
	if(type_verified){
		type_verified = 0;
		if (strcmp(type_cast_str_error,"")){
			char aux[512];
			yyerror(type_cast_str_error);
			strcpy(type_cast_str_error,"\0");
		}else if(left_val_type!=right_val_type && !casting_table.implicit[right_val_type][left_val_type]){
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
	}
	if(c!='\0'){
		evtop=1;
		expression_vect[0]=c;
	}else{
		right_val_type = INTNOVAL;
	}

}

void add_exp_vect(char type){
	expression_vect[evtop]=type;
	evtop++;
	
}

void add_exp_vect_var(char type){
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
		s[cont]=expression_vect[i];
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
		make_casting(expr[0],expr[2],expr[1]);
		i = 3;
		for (i; i < len; i=i+2){
			make_casting(48+right_val_type,expr[i+1],expr[i]);
		}
	}else{
		make_casting(48+right_val_type,expr[0],'0');
	}
	
}

void type_verification(){
	type_verified = 1;
	left_val_type = left_val_type == INTNOVAL ? current_data_type : left_val_type;
	int r,l,i=0;

	while(evtop>0){
		r = find_r_paren(i);
		if (r==-1){
			for(int len=0; len<EVLEN; len++){
				if(expression_vect[len]=='x'){
					find_new_type(expression_vect, len);
					len=EVLEN;
					break;
				}
			}
			evtop=-99;
		}else{
			l = find_l_paren(r);
			char sub_expr[EVLEN+1];
			strcpy(sub_expr,split_arr(l,r));
			find_new_type(sub_expr, r-l-1);
			remerge_arr(l,r,right_val_type);
			for(int i=0; i<EVLEN; i++){
				if(expression_vect[i]=='x'){
					evtop = i;
					break;
				}
			}
			i=l;
		}
		
		
	}
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
			char formatted_str[312];
			sprintf(formatted_str,"\nError on java file :: Function %s %s(%s) called but not declared \n",type,fun[i].var_name,arguments);
			error_counter++;
			write_to_file(formatted_str);
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


int merge_files(){
	FILE *fp1 = fopen("fun.h", "r");
	FILE *fp2 = fopen(AUXFILE, "r");
	
	// Open file to store the result
	FILE *fp3 = fopen(CFILE, "w+");
	char c;

	int first_line_char = 1;

	append_init(fp3);
	
	if (fp1 == NULL || fp2 == NULL || fp3 == NULL)
	{
			puts("Could not open files");
			//exit(0);
			return 1;
	}

	// Copy contents of first file to CFILE
	while ((c = fgetc(fp1)) != EOF){
		if(!first_line_char){ // for better format
			if(c=='\n'){
				first_line_char = 1;
				fputc(';',fp3);
			}
			fputc(c, fp3);
		}else{
			first_line_char = 0;
		}
	}

	// Copy contents of second file to CFILE
	while ((c = fgetc(fp2)) != EOF)
		fputc(c, fp3);
		
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}

void print_error_counter(){
	if(error_counter>0){
		printf("\nErrors found: %d\n\nCheck the translation file for more details: %s\n\nTRANSLATION FAILED !!!\n",error_counter,CFILE);
	}else{
		printf("\nErrors found: %d\n\nCheck the translation file: %s\n\nTRANSLATION SUCCESSFUL !!!\n",error_counter,CFILE);
	}
}

int console_msg(){
	FILE *fp;
	char c;
	int lines_counter=0;

	fp = fopen(CFILE, "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(1);
		return 1;
    }

	printf("\n");
    // Read contents from file
    c = fgetc(fp);
    while (c != EOF && lines_counter<=8) {
		if(c=='\n'){
			lines_counter++;
		}
        printf ("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);

	print_error_counter();

    return 0;
}

void write_to_file(char *s){
	fputs(s,fp_aux);
}
