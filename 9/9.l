%{
#include<stdio.h>
int count=0;
%}
id [a-zA-Z][a-zA-Z0-9_]*
%%

{id} {count++;printf("%s \n",yytext);}
\n {;}
.* {;}
%%

int main()
{ 
 yyin=fopen("id.txt","r");
 yylex();
 printf("\n\tNUMBER OF IDENTIFIERS:%d",count);
 return 0;
}

int yywrap()
{
 return 1;
}
