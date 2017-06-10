%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror(char *s);
%}
%token NUM NL
%left '+' '-' 
%left '*' '/'
%%

S : E NL {printf("\n\tVALID EXPRESSION WITH VALUE:\t%d",$1);exit(0);}
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {if($3==0)
   	     {
		printf("\n\tCANNOT DIVIDE BY ZERO");
		exit(0);
	     }		
	     else
	     {
		$$=$1/$3;
	     }
	    }
  | '(' E ')' {$$=$2;}
  | NUM {$$=$1;}
  ; 
%%

int yyerror(char *s)
{
 printf("\n\tINVALID EXPRESSION");
}

int main()
{
 printf("\n\tENTER AN EXPRESSION:\t"); 
 yyparse();
 return 0;
}				
