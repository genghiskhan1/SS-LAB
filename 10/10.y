%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}
%token NUM ID NL
%left '+' '-' 
%left '*' '/' 
%%

S : E NL {printf("\n\tVALID EXPRESSION");exit(0);}
E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | '(' E ')' 
  | NUM
  | ID
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
