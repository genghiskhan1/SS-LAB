%{
#include<stdio.h>
int a=0,s=0,m=0,d=0;
int fa=0,fs=0,fm=0,fd=0;
int n1=0,n2=0,ob=0,cb=0;
%}
id [a-zA-Z][a-zA-Z0-9_]*
%%

{id} {n1++;printf("%s \n",yytext);}
[+] {n2++;fa=1;a++;}
[-] {n2++;fs=1;s++;}
[*] {n2++;fm=1;m++;}
[/] {n2++;fd=1;d++;}
[(] {ob++;}
[)] {cb++;}
%%

int main()
{
 printf("\n\tENTER ARITHMETIC EXPRESSION:\t");
 yylex();
 if((n1-n2==1)&&(ob-cb==0))
 {  
  printf("\n\tVALID ARITHMETIC EXPRESSION\n\n");
  if(fa) printf("+ = %d\n",a);
  if(fs) printf("- = %d\n",s);
  if(fm) printf("* = %d\n",m);
  if(fd) printf("/ = %d\n",d);
 }
 else
 {
  printf("\n\tINVALID ARITHMETIC EXPRESSION");
 }
 return 0;
}

int yywrap()
{
 return 1;
}
