%{
#define YYDEBUG 0
#include"lex.yy.c"
%}
%locations

%token INT FLOAT ID
%token SEMI COMMA
%token TYPE
%token LC RC LP RP LB RB
%token STRUCT
%token RETURN
%token IF ELSE
%token WHILE
%token DOT
%token ASSIGNOP
%token AND OR NOT
%token PLUS MINUS STAR DIV
%token RELOP

%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left DOT LP RP LB RB
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
Program : ExtDefList
 ;
ExtDefList : ExtDef ExtDefList
 |
 ;
ExtDef : Specifier ExtDecList SEMI
 | Specifier SEMI
 | Specifier FunDec CompSt
 ;
ExtDecList : VarDec
 | VarDec COMMA ExtDecList
 ;
Specifier : TYPE
 | StructSpecifier
 ;
StructSpecifier : STRUCT OptTag LC DefList RC
 | STRUCT TAG
 ;
OptTag : ID
 |
 ;
TAG : ID;
VarDec : ID
 | VarDec LB INT RB
 ;
FunDec : ID LP VarList RP
 | ID LP RP
 ;
VarList : ParamDec COMMA VarList
 | ParamDec
 ;
ParamDec : Specifier VarDec;
CompSt : LC DefList StmtList RC;
StmtList : Stmt StmtList
 |
 ;
Stmt : Exp SEMI
 | CompSt
 | RETURN Exp SEMI
 | IF LP Exp RP Stmt %prec LOWER_THAN_ELSE
 | IF LP Exp RP Stmt ELSE Stmt
 | WHILE LP Exp RP Stmt
 ;
DefList : Def DefList
 |
 ;
Def : Specifier DecList SEMI;
DecList : Dec
 | Dec COMMA DecList
 ;
Dec : VarDec
 | VarDec ASSIGNOP Exp
 ;
Exp : Exp ASSIGNOP Exp
 | Exp AND Exp
 | Exp OR Exp
 | Exp RELOP Exp
 | Exp PLUS Exp
 | Exp MINUS Exp
 | Exp STAR Exp
 | Exp DIV Exp
 | LP Exp RP
 | MINUS Exp
 | NOT Exp
 | ID LP Args RP
 | ID LP RP
 | Exp LB Exp RB
 | Exp DOT ID
 | ID
 | INT
 | FLOAT
 ;
Args : Exp COMMA Args
 | Exp
 ;
%%
