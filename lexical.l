%{
#include"syntax.tab.h"

int yycolumn=1;
#define YY_USER_ACTION \
	yylloc.first_line = yylloc.last_line = yylineno; \
	yylloc.first_column = yycolumn; \
	yylloc.last_column = yycolumn + yyleng - 1; \
	yycolumn += yyleng;
%}
%option yylineno
decimal_digital [1-9]
octal_digital [1-7]
hex_digital [1-9a-fA-F]
letter [a-zA-Z]
decimal_int [+-]?(0|({decimal_digital}(0|{decimal_digital})*))
octal_int [+-]?0(0|{octal_digital})+
hex_int [+-]?(0x|0X)(0|{hex_digital})+
int ({hex_int}|{octal_int}|{decimal_int})
float_without_exp [+-]?(0|{decimal_digital})+(\.(0|{decimal_digital})+)?
float_with_exp {float_without_exp}(e|E)[+-]?[0-9]+
float ({float_with_exp}|{float_without_exp})
id (_|{letter})(_|{letter}|[0-9])*
%%
(\t|" ") {}
{int} {yylval = atoi(yytext);return INT;}
{float} {yylval = atof(yytext);return FLOAT;}
struct {return STRUCT;}
return {return RETURN;}
if {return IF;}
else {return ELSE;}
while {return WHILE;}
(int|float) {return TYPE;}
{id} {return ID;}
; {return SEMI;}
, {return COMMA;}
= {return ASSIGNOP;}
>|<|>=|<=|==|!= {return RELOP;}
"+" {return PLUS;}
- {return MINUS;}
"*" {return STAR;}
"/" {return DIV;}
&& {return AND;}
"||" {return OR;}
"." {return DOT;}
! {return NOT;}
"(" {return LP;}
")" {return RP;}
"[" {return LB;}
"]" {return RB;}
"{" {return LC;}
"}" {return RC;}
\n {yycolumn = 1;}
. {printf("error type at line %d with text: %s\n",yylineno,yytext);}
%%
