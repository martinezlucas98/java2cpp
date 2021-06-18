%option yylineno

%{
	#include<stdio.h>
	#include<string.h>
	//#include"y.tab.h"
	#include<math.h>
%}

%%
[\n\t ]+                      {/* ignoring newlines, tabs and spaces */}

"/\*"(.|\n)*"\*/"			{strcpy(yylval.var_name, yytext);return MLCOMMENT;}
"//"(.)*							{strcpy(yylval.var_name, yytext);return ILCOMMENT;}

"int"                 {yylval.data_type=0; return INT;}
"char"                {yylval.data_type=1; return CHAR;}
"float"								{yylval.data_type=2; return FLOAT;}
"double"							{yylval.data_type=3; return DOUBLE;}
"String"							{yylval.data_type=4; return STRING;}
"boolean"							{yylval.data_type=5; return BOOLEAN;}

"public static void main(String[] args)"							{return MAIN_METHOD;}
"public class Main"               {return MAIN_CLASS;}

"new"									{return NEW;}
"if"								  {return IF;}
"else"								{return ELSE;}
"else"[ ]+"if"        {return ELSEIF;}
"for"								  {return FOR;}
"do"                                                              {return DO;}
"while"								{return WHILE;}

"class"               {return CLASS;}
"static"              {return STATIC;}
"public"              {return PUBLIC;}
"private"             {return PRIVATE;}
"void"                {return VOID;}
"final"					{return FINAL;}
"System.out.println"   {return PRINTLN;}
"System.out.print"	    {return PRINT;}
"Scanner"                {return SCANNER;}
"System.in"              {return SYS_IN;}

":"										{return COLON;}
"?"										{return QM;}
"("									  {return LP;}
")"									  {return RP;}
"{"									  {return LC;}
"}"									  {return RC;}
"["									  {return LB;}
"]"									  {return RB;}
";"									  {return SEMICOLON;}
","									  {return COMA;}
"="                   {return ASSIGNMENT;}
"&&"								  {return LAND;}
"||"								  {return LOR;}
">="								  {return GEQ;}
"<="								  {return LEQ;}
">"									  {return GT;}
"<"									  {return LT;}
"!="								  {return NEQ;}
"=="								  {return DEQ;}
"+"									  {return PLUS;}
"-"									  {return MINUS;}
"*"									  {return MUL;}
"/"									  {return DIV;}
"%"									  {return MOD;}
"!"                   {return NOT;}
"Math.pow("[0-9]+(.[0-9]+)?"[ ]*,[ ]*"[0-9]+(.[0-9]+)?")"   {return EX;}

("true"|"false")              {strcpy(yylval.var_name, yytext);return BOOL_VAL;}
"break"						{return BREAK;}
"return"					{return RETURN;}

[$_a-zA-Z]+[$_a-zA-Z0-9]*			{strcpy(yylval.var_name, yytext);return VAR;}
("-")?[0-9]+("."[0-9]+)?            {strcpy(yylval.var_name, yytext);return NUMBER;}
\"[^"]*\"                     {strcpy(yylval.var_name, yytext);return QUOTED_STRING;}
'[^']*'                       {strcpy(yylval.var_name, yytext);return QUOTED_CHAR;}


%%

int yywrap(void) {
	return 1;
}
