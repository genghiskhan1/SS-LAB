%{
#include "y.tab.c"
%}
%%

[0-9]+ return NUM;
[a-zA-Z][a-zA-Z0-9_]* return ID;
\n return NL;
. return yytext[0];
%%

int yywrap()
{ 
 return 1;
}
