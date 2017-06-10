%{ 
#include<stdio.h>
int chars=0,spaces=0,lines=0,words=0;
%}
%%

[^ \n\t]+ {words++;chars+=yyleng;}
\n {lines++;}
\t {spaces++;}
" " {spaces++;}
%%

int main()
{ 
 yyin=fopen("data.txt","r");
 yylex();
 printf("\n\tCHARACTERS:\t%dWORDS:\t%dSPACES:\t%dLINES:\t%d",chars,words,spaces,lines);
 return 0;
}
