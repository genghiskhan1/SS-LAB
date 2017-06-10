%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}
%token A B NL
%%

S : C D NL {printf("\n\tVALID EXPRESSION");exit(0);}
C : A C
  |
  ;
D : B D
  | 
  ;
%%

int yyerror(char *s)
{
 printf("\n\tINVALID EXPRESSION");
}

int main()
{
 printf("\n\tENTER THE EXPRESSION:\t");
 yyparse();
 return 0;
}
