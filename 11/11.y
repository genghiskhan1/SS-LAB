%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}
%token LET NUM NL;
%%

S : LET A NL {printf("\n\tVALID EXPRESSION");exit(0);}
A : LET A
  | NUM A 
  | LET
  | NUM
  |
  ;
%%

int yyerror(char *s)
{
 printf("\n\tINVALID EXPRESSION");
}

int main()
{
 printf("\n\tENTER EXPRESSION:\t");
 yyparse();
 return 0;
}
