%option yylineno
digital [0-9]
letter [a-zA-Z]
%%
[+-]?{digital}+ {printf("%s\n",yytext);}
{letter}(_|{letter})* {printf("%s\n",yytext);}
. {printf("error type at line %d with text: %s\n",yylineno,yytext);}
%%
