%{
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

%}

%union{
int data_type;
char var_name[MAX_NAME_LEN];
}

%token VAR
%token LAND LOR GEQ LEQ NOT GT LT NEQ DEQ PLUS MINUS MUL DIV MOD ASSIGNMENT EX
%token MAIN_METHOD MAIN_CLASS IF ELSE ELSEIF WHILE FOR CLASS STATIC PUBLIC PRIVATE VOID PRINTLN PRINT NEW DO BREAK RETURN
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

program		: { print_init(); } MAIN_CLASS LC {push_scope("global");printf("/* start Main Class */\n"); } GLOBAL_VAR_DECLARATION STATEMENTS GLOBAL_VAR_DECLARATION RC {pop_scope(); printf("\n/* end Main Class */\n"); exit(0); }
			| /* Empty file */	{ printf("\n"); exit(2); }
			;

STATEMENTS	: { print_tabs(); } METHODS STATEMENTS { }
			| { print_tabs(); } VAR_DECLARATION STATEMENTS { }
			| { print_tabs(); } COMMENT STATEMENTS { }
			| { print_tabs(); } IF_STATEMENT STATEMENTS { }
			| { print_tabs(); } FOR_LOOP STATEMENTS { }
			| { print_tabs(); } WHILE_LOOP STATEMENTS { }
			| { print_tabs(); } DO_WHILE_LOOP STATEMENTS { }
			| { print_tabs(); } STDIO STATEMENTS { }
			| { print_tabs(); } BREAK_ST STATEMENTS { }
			| { print_tabs(); } RETURN_ST STATEMENTS { }
			| { print_tabs(); } VAR_ASSIGNATION STATEMENTS { }
			| /* */	{ }
			;
GLOBAL_VAR_DECLARATION : SCOPE IS_STATIC VAR_DECLARATION
						| /* */
						;

IS_STATIC : STATIC
			| /* */
			;

RETURN_ST 	: RETURN { printf("return "); } EXPRESION SEMICOLON { printf(";\n"); }
			;

BREAK_ST	: BREAK SEMICOLON  { printf("break;\n"); }
			;

STDIO	: PRINTLN { printf("std::cout"); } LP { printf(" << "); } EXPRESION RP { printf(" <<  std::endl"); } SEMICOLON { printf(";\n"); }
		| PRINT { printf("std::cout"); } LP { printf(" << "); } EXPRESION RP SEMICOLON { printf(";\n"); }
		;

VAR_DECLARATION	: TYPE  VAR {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name); } HAS_ASSIGNMENT SEMICOLON { printf(";\n"); }
				| TYPE  BRACKET_ARRAY VAR {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); } HAS_ASSIGNMENT SEMICOLON { printf(";\n"); } // shift/reduce
				;

VAR_ASSIGNATION	: VAR {printf("%s", yylval.var_name);verify_scope(yylval.var_name);  } ASSIGNMENT { printf(" = "); } EXPRESION SEMICOLON { printf(";\n"); }
				;

BRACKET_ARRAY	: LB NUMARRAY RB  BRACKET_ARRAY
			|  LB RB  { bracket_counter++; } BRACKET_ARRAY
			| /* */
			;

IF_STATEMENT	: IF LP { printf("if (");create_scope_name_and_push_it(); } EXPRESION RP LC { tab_counter++; printf(") {\n"); } STATEMENTS RC { pop_scope();tab_counter--; print_tabs(); printf("}"); } ELSE_VARIATIONS
				;

ELSE_VARIATIONS	: ELSE LC {create_scope_name_and_push_it(); tab_counter++; printf(" else {\n"); } STATEMENTS RC { tab_counter--; print_tabs(); printf("}"); }
				| ELSEIF LP { printf(" else if ("); } EXPRESION RP { printf(")"); } LC {create_scope_name_and_push_it();tab_counter++; printf(") {\n"); } STATEMENTS RC { pop_scope();tab_counter--;print_tabs(); printf("}"); } ELSE_VARIATIONS
				| /* */ { printf("\n"); }
				;
				
WHILE_LOOP      : WHILE LP {printf("while ("); } DECL_EXPR RP LC { tab_counter++; printf("){\n"); } STATEMENTS RC { tab_counter--; print_tabs(); printf("}\n"); }
                           ;


FOR_LOOP	: FOR LP { printf("for ("); } FOR_PARAMS RP LC { tab_counter++; printf(") {\n"); } STATEMENTS RC { tab_counter--; print_tabs(); printf("}\n"); }
			;

FOR_PARAMS	: DECL_EXPR SEMICOLON { printf("; "); } DECL_EXPR SEMICOLON { printf("; "); } EXPRESION
			| TYPE VAR COLON { printf("%s", yylval.var_name); } { printf(" : "); } VAR { printf("%s", yylval.var_name); }// shift/reduce
			;

DECL_EXPR	: EXPRESION
			| TYPE VAR { printf("%s", yylval.var_name); } HAS_ASSIGNMENT
			| VAR { printf("%s", yylval.var_name); } HAS_ASSIGNMENT//ASSIGNMENT { printf(" = "); } EXPRESION
			| /* */  { }
        	;

DO_WHILE_LOOP   : DO LC { printf("do{\n"); tab_counter++;} STATEMENTS RC WHILE LP {tab_counter--; print_tabs(); printf("}while("); } DECL_EXPR RP SEMICOLON { printf(");"); } 
                ;


NUMARRAY	: NUMBER   { printf("[%s]", yylval.var_name); }
			| VAR { printf("[%s]", yylval.var_name); }
			;

HAS_ASSIGNMENT	: ASSIGNMENT { printf(" = "); } EXPRESION
				| ASSIGNMENT EXPRESION_ARRAY
				| /* No assignment */ {}
				;

METHODS	: SCOPE STATIC TYPE VAR { push_scope(yylval.var_name);printf("%s", yylval.var_name); }LP { printf("("); } PARAMS RP { printf(")"); } LC	{ tab_counter++; printf("{\n"); } STATEMENTS RC { printf("}\n"); tab_counter--;pop_scope(); }	{ }//printf("static %s %s ( %s ) {", current_data_type, ); }
		| MAIN_METHOD {push_scope("main");printf("int main(int argc, char **argv)"); } LC { tab_counter++; printf("{\n"); } STATEMENTS RC { printf("\n}\n"); tab_counter--; pop_scope();}
		;

SCOPE	: PUBLIC
		| PRIVATE 
		| /* */
		;

PARAMS	: HAS_PARAMS PARAMS
		| COMA { printf(","); }  HAS_PARAMS
		| /* No parameters */		{ printf(" "); }
		;


HAS_PARAMS	: TYPE VAR {insert_to_table(yylval.var_name,current_data_type);printf("%s", yylval.var_name); }
			| TYPE  BRACKET_ARRAY VAR {insert_to_table(yylval.var_name,current_data_type); printf("%s", yylval.var_name);printf("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--)printf("[%d]",DIMENSION);}
			| /* */
			;

EXPRESION	: EXPRESION LAND { printf("&&"); } EXPRESION
			| EXPRESION LOR { printf("||"); } EXPRESION
			| EXPRESION LEQ { printf("<="); } EXPRESION
			| EXPRESION GT { printf(">"); } EXPRESION
			| EXPRESION LT { printf("<"); } EXPRESION
			| EXPRESION NEQ { printf("!="); } EXPRESION
			| EXPRESION DEQ { printf("=="); } EXPRESION
			| NOT { printf("!"); } EXPRESION
			| EXPRESION PLUS { printf("+"); } EXPRESION
			| EXPRESION MINUS { printf("-"); } EXPRESION
			| EXPRESION MUL { printf("*"); } EXPRESION
			| EXPRESION DIV { printf("/"); } EXPRESION
			| EXPRESION MOD { printf("%%"); } EXPRESION
			| LP { printf("("); } EXPRESION RP { printf(")"); }
			| EXPRESION PLUS PLUS { printf("++"); }
			| EXPRESION MINUS MINUS { printf("--"); }
			| TERMINAL
			| VAR { printf("%s", yylval.var_name); verify_scope(yylval.var_name);}
			;

EXPRESION_ARRAY	: NEW TYPE_NO_PRINT BRACKET_ARRAY {bracket_counter=0;}
				| { for(;bracket_counter>0;bracket_counter--)printf("[]"); } LC { printf(" = {"); } EXPRESION_ARRAY_INITIALIZE RC { printf("}"); }
				;

EXPRESION_ARRAY_INITIALIZE	: TERMINAL COMA { printf(","); } EXPRESION_ARRAY_INITIALIZE
							| COMA { printf(","); } LC { printf("{"); } EXPRESION_ARRAY_INITIALIZE RC { printf("}"); } EXPRESION_ARRAY_INITIALIZE
							|  LC { printf("{"); } EXPRESION_ARRAY_INITIALIZE RC { printf("}"); } EXPRESION_ARRAY_INITIALIZE
							| TERMINAL
							| /* */
							;

TYPE_NO_PRINT	: INT
				| CHAR
				| FLOAT
				| DOUBLE
				| STRING
				| BOOLEAN
				;

TYPE	: INT { $$=$1; current_data_type=$1;	printf("int "); }
		| CHAR  { $$=$1; current_data_type=$1; printf("char "); }
		| FLOAT { $$=$1; current_data_type=$1; printf("float "); }
		| DOUBLE { $$=$1; current_data_type=$1; printf("double "); }
		| STRING { $$=$1; current_data_type=$1; printf("string "); }
		| BOOLEAN { $$=$1; current_data_type=$1; printf("bool "); }
		| VOID { printf("void "); }
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
		printf("\nVariable %s was not declared in the scope \n",var);
		yyerror("");
		exit(0);

	}
}
int lookup_in_table(char var[MAX_NAME_LEN])
{
	for(int i=0; i<table_idx; i++)
	{	//Return rype if name and scope is match
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
