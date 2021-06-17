%{
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
		char github_msg[64];
		char date_msg[128];

		char *version = "alpha 1.0";
		char *github = "https://github.com/martinezlucas98/java2cpp";

		sprintf(version_msg, "*\tVersion: %s\n", version);
		sprintf(github_msg, "*\tGithub: %s\n", github);
		sprintf(date_msg, "*\tTranslated on: %d-%02d-%02d %02d:%02d:%02d (yyyy-MM-dd hh:mm:ss)\n", now.tm_year + 1900, now.tm_mon + 1, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);

		fputs("/*\n*\t===================================================================\n",fp);
		fputs("*\tTranslated from java to c++ using java2cpp\n",fp);
		fputs(version_msg,fp);
		fputs(github_msg,fp);
		fputs(date_msg,fp);
		fputs("*\t===================================================================\n*/\n\n",fp);
		fputs("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n",fp);
	}

	void print_init(){
		printf("#include <iostream>\n#include <string>\n\nusing namespace std;\n\n");
	}

%}

%union{
int data_type;
char var_name[MAX_NAME_LEN];
}

%token VAR
%token LAND LOR GEQ LEQ NOT GT LT NEQ DEQ PLUS MINUS MUL DIV MOD ASSIGNMENT EX
%token MAIN_METHOD MAIN_CLASS IF ELSE ELSEIF WHILE FOR CLASS STATIC PUBLIC PRIVATE VOID PRINTLN PRINT NEW DO BREAK RETURN SCANNER SYS_IN FINAL
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

program		: { fp_aux = fopen(AUXFILE,"w"); print_init();} HAS_COMMENT MAIN_CLASS LC {push_scope("global"); write_to_file("\n/* start Main Class */\n\n"); }  STATEMENTS  RC HAS_COMMENT {pop_scope(); write_to_file("\n/* end Main Class */\n"); verify_fun_table(); fclose(fp_aux); int r = merge_files(); console_msg(); exit(r); }
			| /* Empty file */	{ write_to_file("\n"); exit(2); }
			;

STATEMENTS	: { print_tabs(); } DECLARATION STATEMENTS { }
			| { print_tabs(); } MAIN_METHOD_DECLARATION STATEMENTS { }
			| { print_tabs(); } COMMENT STATEMENTS { }
			| { print_tabs(); } IF_STATEMENT STATEMENTS { }
			| { print_tabs(); } FOR_LOOP STATEMENTS { }
			| { print_tabs(); } WHILE_LOOP STATEMENTS { }
			| { print_tabs(); } DO_WHILE_LOOP STATEMENTS { }
			| { print_tabs(); } STDIO STATEMENTS { }
			| { print_tabs(); } BREAK_ST STATEMENTS { }
			| { print_tabs(); } RETURN_ST STATEMENTS { }
      		| VAR_USE STATEMENTS { }
			| error DELIMITER STATEMENTS
			| /* */	{ }
			;

IGNORE_SCOPE	: SCOPE IS_STATIC CONST TYPE 
				;
DECLARATION 	:IGNORE_SCOPE CONST METHODS
				|IGNORE_SCOPE CONST VAR_DECLARATION 
				;
CONST			: FINAL{ write_to_file("const "); current_constant=1; }
				| /* empty */
METHODS	:   VAR {push_scope(yylval.var_name);write_to_file(yylval.var_name);insert_funtion(yylval.var_name,current_data_type,1); }LP { write_to_file("("); } PARAMS RP { write_to_file(")"); } LC	{ tab_counter++; write_to_file("{\n"); } STATEMENTS RC { write_to_file("}\n"); tab_counter--;pop_scope(); }	{ }//printf("static %s %s ( %s ) {", current_data_type, ); }
		;
IS_STATIC : STATIC
			| /* */
			;
      
RETURN_ST 	: RETURN { write_to_file("return "); } EXPRESION MUST_SEMICOLON { write_to_file("\n"); }
			      ;

BREAK_ST	: BREAK { write_to_file("break"); } MUST_SEMICOLON { write_to_file("\n"); }
			;

STDIO	: PRINTLN { write_to_file("std::cout"); } LP { write_to_file(" << "); } EXPRESSION_OUT RP { write_to_file(" <<  std::endl"); } MUST_SEMICOLON { write_to_file("\n"); }
		| PRINT { write_to_file("std::cout"); } LP { write_to_file(" << "); } EXPRESSION_OUT RP MUST_SEMICOLON { write_to_file("\n"); }
		| SCANNER { write_to_file("std::string "); } VAR { write_to_file(yylval.var_name);} ASSIGNMENT {write_to_file(";\n");} NEW SCANNER {print_tabs();write_to_file("std::cin");} LP SYS_IN RP {write_to_file(" >> ");} SEMICOLON { write_to_file(yylval.var_name); write_to_file(";\n");} 
		//| VAR ASSIGNMENT NEW SCANNER {write_to_file("std::cin");} LP SYS_IN RP {write_to_file(" >> ");} { write_to_file(yylval.var_name); }
		;

EXPRESSION_OUT	: TERMINAL 
				| TERMINAL PLUS {write_to_file(" << ");} EXPRESSION_OUT
				| VAR
				| VAR PLUS {write_to_file(" << ");}
				;
		
    // Check MUST_SEMICOLON on inputs ::: SCANNER

VAR_DECLARATION	:   VAR {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name); {clear_exp_vect('\0');}} HAS_ASSIGNMENT MUST_SEMICOLON { write_to_file("\n"); check_syntax_errors(); print_type_error_warning();}
				        |   BRACKET_ARRAY VAR {insert_to_table(yylval.var_name,current_data_type);write_to_file(yylval.var_name); } HAS_ASSIGNMENT MUST_SEMICOLON { write_to_file("\n"); check_syntax_errors(); } // shift/reduce
				        ;

VAR_USE	:  VAR { print_tabs(); write_to_file(yylval.var_name);verify_scope(yylval.var_name);check_constant(yylval.var_name); clear_exp_vect('\0'); left_val_type = lookup_in_table(yylval.var_name);} ASSIGNMENT { write_to_file(" = "); } MUST_EXPRESSION {type_verification();} MUST_SEMICOLON { write_to_file("\n"); check_syntax_errors(); print_type_error_warning(); } //MUST_EXPRESSION
					| VAR{ print_tabs(); write_to_file(yylval.var_name);insert_funtion(yylval.var_name,current_data_type,0);} LP { write_to_file("("); } PARAMS_TYPE RP { write_to_file(")"); } MUST_SEMICOLON { write_to_file("\n"); check_syntax_errors(); print_type_error_warning(); }
				        ;

BRACKET_ARRAY	: LB NUMARRAY RB  BRACKET_ARRAY
			|  LB RB  { bracket_counter++; } BRACKET_ARRAY
			| /* */
			;
      
// Check errors for if elseif 
IF_STATEMENT	: IF LP { write_to_file("if (");create_scope_name_and_push_it(); } MUST_EXPRESSION RP LC { tab_counter++; write_to_file(") {\n"); check_syntax_errors(); } STATEMENTS RC { pop_scope();tab_counter--; print_tabs(); write_to_file("}"); } ELSE_VARIATIONS
				      ;

ELSE_VARIATIONS	: ELSE LC {create_scope_name_and_push_it(); tab_counter++; write_to_file(" else {\n"); } STATEMENTS RC {pop_scope();tab_counter--; print_tabs(); write_to_file("}"); }
				| ELSEIF LP { write_to_file(" else if ("); } MUST_EXPRESSION RP { write_to_file(")"); check_syntax_errors(); } LC {create_scope_name_and_push_it();tab_counter++; write_to_file(") {\n"); } STATEMENTS RC { pop_scope();tab_counter--;print_tabs(); write_to_file("}"); } ELSE_VARIATIONS
				| /* */ { write_to_file("\n"); }
				;
				
WHILE_LOOP  : WHILE LP {create_scope_name_and_push_it();write_to_file("while ("); } DECL_EXPR RP LC { tab_counter++; write_to_file("){\n"); } STATEMENTS RC {pop_scope();tab_counter--; print_tabs(); write_to_file("}\n"); }
            ;



FOR_LOOP	: FOR LP {create_scope_name_and_push_it(); write_to_file("for ("); } FOR_PARAMS RP LC { tab_counter++; write_to_file(") {\n"); check_syntax_errors(); } STATEMENTS RC {pop_scope(); tab_counter--; print_tabs(); write_to_file("}\n"); }
			    ;

FOR_PARAMS	: DECL_EXPR SEMICOLON_NOT_COMA DECL_EXPR SEMICOLON_NOT_COMA EXPRESION // SEMICOLON_NOT_COMA causes 1 reduce/reduce conflict
			| TYPE VAR COLON { write_to_file(yylval.var_name); } { write_to_file(" : "); } VAR { write_to_file(yylval.var_name); }// shift/reduce
			;

DECL_EXPR	: EXPRESION
			| TYPE VAR {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name); } HAS_ASSIGNMENT
			| VAR {verify_scope(yylval.var_name);write_to_file(yylval.var_name); } HAS_ASSIGNMENT//ASSIGNMENT { printf(" = "); } EXPRESION
			| /* */  { }
      ;

DO_WHILE_LOOP   : DO LC { write_to_file("do{\n"); tab_counter++;} STATEMENTS RC WHILE LP {tab_counter--; print_tabs(); write_to_file("}while("); } DECL_EXPR RP { write_to_file(")"); } MUST_SEMICOLON { write_to_file("\n"); } 
                ;


NUMARRAY	: NUMBER	{ char s[MAX_NAME_LEN+3]; sprintf(s,"[%s]", yylval.var_name); write_to_file(s); }
			| VAR		{ char s[MAX_NAME_LEN+3]; sprintf(s,"[%s]", yylval.var_name); write_to_file(s); }
			;

HAS_ASSIGNMENT	: ASSIGNMENT { write_to_file(" = "); } MUST_EXPRESSION {type_verification();} //check this
				        | ASSIGNMENT EXPRESION_ARRAY
				        | /* No assignment */ {}
				        ;

MAIN_METHOD_DECLARATION	: MAIN_METHOD { push_scope("main");write_to_file("int main(int argc, char **argv)"); } LC { tab_counter++; write_to_file("{\n"); } STATEMENTS RC { write_to_file("\n}\n"); tab_counter--; pop_scope();}
			                  ;



SCOPE	: PUBLIC
		  | PRIVATE 
		  | /* */
		  ;

PARAMS	: HAS_PARAMS PARAMS
		    | COMA { write_to_file(","); }  HAS_PARAMS
		    | /* No parameters */		{ write_to_file(" "); }
		    ;
PARAMS_TYPE : VAR {write_to_file(yylval.var_name);insert_argument_var( yylval.var_name);} COMA { write_to_file(","); } PARAMS_TYPE
			| VAR{write_to_file(yylval.var_name);insert_argument_var( yylval.var_name);}
			| LITERAL_ARGUMENT {insert_type_param(current_data_type);} COMA { write_to_file(","); } PARAMS_TYPE
			| LITERAL_ARGUMENT {insert_type_param(current_data_type);} 
			| /* empty*/
			;

HAS_PARAMS	: TYPE VAR {insert_to_table(yylval.var_name,current_data_type);write_to_file(yylval.var_name);insert_type_param(current_data_type); }
			      | TYPE  BRACKET_ARRAY VAR {insert_to_table(yylval.var_name,current_data_type); write_to_file(yylval.var_name);write_to_file("[]");bracket_counter-- ;for(;bracket_counter>0;bracket_counter--){char s[255];sprintf(s,"[%d]",DIMENSION);write_to_file(s);}}
			      | /* */
			      ;

EXPRESION	: EXPRESION LAND { write_to_file(" && "); } EXPRESION
			| EXPRESION LOR { write_to_file(" || "); } EXPRESION
			| EXPRESION LEQ { write_to_file(" <= "); } EXPRESION
			| EXPRESION GEQ { write_to_file(" >= "); } EXPRESION
			| EXPRESION GT { write_to_file(" > "); } EXPRESION
			| EXPRESION LT { write_to_file(" < "); } EXPRESION
			| EXPRESION NEQ { write_to_file(" != "); } EXPRESION
			| EXPRESION DEQ { write_to_file(" == "); } EXPRESION
			| NOT { write_to_file("!"); } EXPRESION
			| EXPRESION PLUS { write_to_file(" + "); add_exp_vect('+');} EXPRESION
			| EXPRESION MINUS { write_to_file(" - "); add_exp_vect('-');} EXPRESION
			| EXPRESION MUL { write_to_file(" * "); add_exp_vect('*');} EXPRESION
			| EXPRESION DIV { write_to_file(" / "); add_exp_vect('/'); } EXPRESION
			| EXPRESION MOD { write_to_file(" %% "); } EXPRESION
			| LP { write_to_file("("); add_exp_vect('(');} EXPRESION RP { write_to_file(")"); add_exp_vect(')');}
			| EXPRESION PLUS PLUS { write_to_file("++"); }
			| EXPRESION MINUS MINUS { write_to_file("--"); }
			| TERMINAL
			| VAR { write_to_file(yylval.var_name); verify_scope(yylval.var_name); add_exp_vect_var(48+lookup_in_table_alt(yylval.var_name)); }
			;

EXPRESION_ARRAY	: NEW TYPE_NO_PRINT BRACKET_ARRAY {bracket_counter=0;}
				        | { for(;bracket_counter>0;bracket_counter--)write_to_file("[]"); } LC { write_to_file(" = {"); } EXPRESION_ARRAY_INITIALIZE RC { write_to_file("}"); }
				        ;

EXPRESION_ARRAY_INITIALIZE	: TERMINAL COMA { write_to_file(","); } EXPRESION_ARRAY_INITIALIZE
							| COMA { write_to_file(","); } LC { write_to_file("{"); } EXPRESION_ARRAY_INITIALIZE RC { write_to_file("}"); } EXPRESION_ARRAY_INITIALIZE
							|  LC { write_to_file("{"); } EXPRESION_ARRAY_INITIALIZE RC { write_to_file("}"); } EXPRESION_ARRAY_INITIALIZE
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

TYPE	: INT { $$=$1; current_data_type=$1;	write_to_file("int "); }
		| CHAR  { $$=$1; current_data_type=$1; write_to_file("char "); }
		| FLOAT { $$=$1; current_data_type=$1; write_to_file("float "); }
		| DOUBLE { $$=$1; current_data_type=$1; write_to_file("double "); }
		| STRING { $$=$1; current_data_type=$1; write_to_file("std::string "); }
		| BOOLEAN { $$=$1; current_data_type=$1; write_to_file("bool "); }
		| VOID { write_to_file("void "); }
		;

TERMINAL	: NUMBER { write_to_file(yylval.var_name); add_exp_vect(48+T_INT); }
			| QUOTED_CHAR { write_to_file(yylval.var_name); add_exp_vect(48+T_CHAR); }
			| QUOTED_STRING { write_to_file(yylval.var_name); add_exp_vect(48+T_STRING); }
			| BOOL_VAL { write_to_file(yylval.var_name); add_exp_vect(48+T_BOOL); }
			;
LITERAL_ARGUMENT	: NUMBER { write_to_file(yylval.var_name); current_data_type=T_INT;}
			| QUOTED_CHAR { write_to_file(yylval.var_name); current_data_type=T_CHAR; }
			| QUOTED_STRING { write_to_file(yylval.var_name); current_data_type=T_STRING; }
			| BOOL_VAL { write_to_file(yylval.var_name); current_data_type=T_BOOL; }
			;

COMMENT	: ILCOMMENT		{ write_to_file(yylval.var_name); write_to_file("\n"); }
		| MLCOMMENT		{ write_to_file(yylval.var_name); write_to_file("\n"); } // we need to add comments bewteen { } on methods with POSSIBLE_COMMENT maybe
		;

HAS_COMMENT	: COMMENT
			| /* empty*/
			;

DELIMITER	: SEMICOLON { }
			| RC { write_to_file("}\n"); } // verify this
			;

MUST_SEMICOLON	: SEMICOLON { write_to_file(";"); }
				| /*empty*/ { yyerror("Syntax error: expected ';' at end of declaration"); }
				;

SEMICOLON_NOT_COMA	: SEMICOLON { write_to_file(";"); }
					| COMA { write_to_file(","); strcat(syntax_errors,"Syntax error: expected ';' instead of ','\t"); } 
					;

MUST_EXPRESSION : EXPRESION
				| VAR ASSIGNMENT { write_to_file(yylval.var_name); write_to_file("="); } EXPRESION { }
				| EXPRESION ASSIGNMENT { write_to_file("="); } EXPRESION { strcat(syntax_errors,"Syntax error: expected '==' operator\n"); }
				| /*empty*/ { strcat(syntax_errors,"Syntax error: expected expresion\n"); }
				;

%%

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
		sprintf(formatted_str,"\nVariable %s was declared as a const \n",var);
		write_to_file(formatted_str);
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
		char formatted_str[256];
		sprintf(formatted_str,"\nVariable %s was not declared in the scope  \n",var);
		write_to_file(formatted_str);
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
		char formatted_str[256];
		sprintf(formatted_str,"\nMultiple declaration of variable %s \n",var);
		write_to_file(formatted_str);
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
		char formatted_str[256];
		sprintf(formatted_str,"\nVariable not declare %s \n",var);
		write_to_file(formatted_str);
		yyerror("");
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
	//print_tabs();
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
		}else if(left_val_type!=right_val_type && !casting_table.implicit[right_val_type][left_val_type]){
			printf("\nl: %d, r: %d\n", left_val_type, right_val_type);
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
			char formatted_str[300];
			sprintf(formatted_str,"\n Function %s %s(%s) has not been declared \n",type,fun[i].var_name,arguments);
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
	
	//printf("Merged file1.txt and file2.txt into file3.txt");
	
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}

void print_error_counter(){
	if(error_counter>0){
		printf("\nErrors found: %d\n\nTRANSLATION FAILED !!!\n",error_counter);
	}else{
		printf("\nErrors found: %d\n\nTRANSLATION SUCCESSFUL !!!\n",error_counter);
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

	printf("Check the translation file: %s\n",CFILE);
	print_error_counter();

    return 0;
}

void write_to_file(char *s){
	fputs(s,fp_aux);
	printf("%s",s);
}