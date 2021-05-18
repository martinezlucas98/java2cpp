%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#define MAX_NAME_LEN 32
	#define MAX_VARIABLES 32
	int yylex(void);
	int yyerror(const char *s);
	int success = 1;
	int current_data_type;
	int bracket_counter=0;
	int expn_type = -1;
	int temp;
	int idx = 0;
	int table_idx = 0;
	int tab_count = 0;
	char for_var[MAX_NAME_LEN];
	struct symbol_table{char var_name[MAX_NAME_LEN]; int type;} sym[MAX_VARIABLES];
	extern int lookup_in_table(char var[MAX_NAME_LEN]);
	extern void insert_to_table(char var[MAX_NAME_LEN], int type);
	extern void print_tabs();
	char var_list[MAX_VARIABLES][MAX_NAME_LEN];	// MAX_VARIABLES variable names with each variable being atmost MAX_NAME_LEN characters long
	int string_or_var[MAX_VARIABLES];
	//extern int *yytext;
%}

%union{
int data_type;
char var_name[MAX_NAME_LEN];
}

%token VAR
%token LAND LOR GEQ LEQ NOT GT LT NEQ DEQ PLUS MINUS MUL DIV MOD ASSIGNMENT EX
%token MAIN_METHOD MAIN_CLASS IF ELSE ELSEIF WHILE FOR CLASS STATIC PUBLIC PRIVATE VOID PRINTLN NEW
%token BOOL_VAL NUMBER QUOTED_STRING QUOTED_CHAR
%token LP RP LC RC LB RB COMA SEMICOLON COLON QM SQ DQ
%token ILCOMMENT MLCOMMENT

%left LAND LOR GEQ LEQ NOT GT LT NEQ DEQ PLUS MINUS MUL DIV MOD

%token<data_type>INT
%token<data_type>CHAR
%token<data_type>FLOAT
%token<data_type>DOUBLE
%token<data_type>STRING
%token<data_type>BOOLEAN



%type<data_type>TYPE
%start program

%%

program		: MAIN_CLASS LC { printf("start Main\n"); } STATEMENTS RC { printf("\nend Main\n"); exit(0); }
					| /* Empty file */								{ printf("\n"); exit(2); }
					;

STATEMENTS			: METHODS STATEMENTS		{ }
								| VAR_DECLARATION STATEMENTS		{ }
								|	COMMENT STATEMENTS { }
								| IF_STATEMENT { }
								| /* */						{ }
								;

VAR_DECLARATION		: TYPE  VAR { printf("%s", yylval.var_name); } HAS_ASSIGNMENT SEMICOLON { printf(";\n"); }
					| TYPE  COLON_ARRAY VAR { printf("%s", yylval.var_name);} HAS_ASSIGNMENT SEMICOLON { printf(";\n"); }
					;

COLON_ARRAY			: LB NUMARRAY RB  COLON_ARRAY  
					|  LB RB  {bracket_counter++;} COLON_ARRAY 
					| /* */
					;


IF_STATEMENT		: IF LP { printf("if ("); } EXPRESION RP LC { printf(") {"); } STATEMENTS RC { printf("}"); } ELSE_VARIATIONS
								;

ELSE_VARIATIONS		: ELSE LC { printf(" else {"); } STATEMENTS RC { printf("}"); }
									| ELSEIF LP { printf(" else if ("); } EXPRESION RP { printf(")"); } LC { printf(") {"); } STATEMENTS RC { printf("}"); } ELSE_VARIATIONS
									| /* */ { printf("\n"); }
									;

NUMARRAY			: NUMBER   {printf("[%s]", yylval.var_name);} 
					| VAR { printf("[%s]", yylval.var_name); } 
					;

HAS_ASSIGNMENT		: ASSIGNMENT { printf(" = "); } EXPRESION
					| ASSIGNMENT EXPRESION_ARRAY
					| /* No assignment */ {}
					;

METHODS		: STATIC TYPE VAR LP PARAMS RP LC	STATEMENTS RC	{ }//printf("static %s %s ( %s ) {", current_data_type, ); }
					| MAIN_METHOD { printf("int main(int argc, char **argv)"); } LC {printf("{\n");} STATEMENTS RC {printf("\n}\n");}
					;

PARAMS		: HAS_PARAMS {}
					| /* No parameters */		{ printf(" "); }
					;


HAS_PARAMS	: TERMINAL COMA {printf(",");} HAS_PARAMS { }
						| TERMINAL										{ }
						;

EXPRESION			: EXPRESION LAND {printf("&&");} EXPRESION
					| EXPRESION LOR {printf("||");} EXPRESION
		 			| EXPRESION LEQ {printf("<=");} EXPRESION
					| EXPRESION GT {printf(">");} EXPRESION
					| EXPRESION LT {printf("<");} EXPRESION
					| EXPRESION NEQ {printf("!=");} EXPRESION
					| EXPRESION DEQ {printf("==");} EXPRESION
					| NOT {printf("!");} EXPRESION
					| EXPRESION PLUS {printf("+");} EXPRESION
					| EXPRESION MINUS {printf("-");} EXPRESION
					| EXPRESION MUL {printf("*");} EXPRESION
					| EXPRESION DIV {printf("/");} EXPRESION
					| EXPRESION MOD {printf("%%");} EXPRESION
					| LP { printf("("); } EXPRESION RP { printf(")"); }
					| TERMINAL
					;

EXPRESION_ARRAY		: NEW TYPE_NO_PRINT COLON_ARRAY {bracket_counter=0;} 
					|{for(;bracket_counter>0;bracket_counter--)printf("[]");}LC { printf("= {"); } EXPRESION_ARRAY_INITIALIZE RC { printf("} "); }

EXPRESION_ARRAY_INITIALIZE		: TERMINAL COMA { printf(","); } EXPRESION_ARRAY_INITIALIZE
					| COMA { printf(","); }  LC { printf("{"); } EXPRESION_ARRAY_INITIALIZE RC { printf("}"); }  EXPRESION_ARRAY_INITIALIZE
					|  LC { printf("{"); } EXPRESION_ARRAY_INITIALIZE RC { printf("} "); } EXPRESION_ARRAY_INITIALIZE
					| TERMINAL
					| /* */
					;

TYPE_NO_PRINT		: INT 
					| CHAR
					| FLOAT 
					| DOUBLE
					| STRING 
					| BOOLEAN
					;

TYPE			: INT { $$=$1; current_data_type=$1;	printf("int "); }
					| CHAR  { $$=$1; current_data_type=$1; printf("char "); }
					| FLOAT { $$=$1; current_data_type=$1; printf("float "); }
					| DOUBLE { $$=$1; current_data_type=$1; printf("double "); }
					| STRING { $$=$1; current_data_type=$1; printf("String "); }
					| BOOLEAN { $$=$1; current_data_type=$1; printf("bool "); }
					;

TERMINAL	: NUMBER { printf("%s", yylval.var_name); }
					| QUOTED_CHAR { printf("%s", yylval.var_name); }
					| QUOTED_STRING { printf("%s", yylval.var_name); }
					| BOOL_VAL { printf("%s", yylval.var_name); }
					;

COMMENT	: ILCOMMENT		{ printf("%s\n", yylval.var_name); }
				| MLCOMMENT		{ printf("%s", yylval.var_name); } // falta poner entre los metodos antes y despues del { } creo con POSSIBLE_COMMENT cpaz
				;


%%

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
	for(int i = 0; i < tab_count; i++){
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
