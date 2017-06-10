%{
#include<stdio.h>
int count=0;
%}
%x C
%%

"/*"[.]"*/" {count++;}
"/*" {BEGIN C;}
<C>"*/" {BEGIN 0;count++;}
<C>. {;}
<C>\n {;}
\/\/.* {count++;}
%%

int main()
{
 yyin=fopen("data.c","r");
 yylex();
 printf("\n\tNUMBER OF COMMENTS:\t%d\n",count);
 return 0;
}

int yywrap()
{
 return 1;
}
