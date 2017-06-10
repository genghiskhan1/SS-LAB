#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
 char label[10],opcode[10],operand[10];
 char mnemonic[10],operand1[10],temp[10],obj[100][100];
 int p,u,i,v,start,address,length=0,len;
 FILE *f1,*f2,*f3,*f4,*f5;
 f1=fopen("input.txt","r");
 f2=fopen("optab.txt","r");
 f3=fopen("symtab.txt","r");
 f4=fopen("objectcode.txt","w");
 f5=fopen("objectprog.txt","w");
 fscanf(f1,"%s%s%s",label,opcode,operand);
 if(strcmp(opcode,"START")==0)
 {
  fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
  strcpy(obj[0],label);
  start=atoi(operand);
  strcpy(obj[1],operand);
  fscanf(f1,"%x%s%s%s",&address,label,opcode,operand);
 }
 else
 {
  strcpy(obj[0],"**");
  strcpy(obj[1],"00000");
 }
 strcpy(obj[2],"null");
 p=3;
 while(strcmp(opcode,"END")!=0)
 {
  if(strcmp(opcode,"BYTE")==0)
  {
   fprintf(f4,"%x\t%s\t%s\t%s\t",address,label,opcode,operand);
   len=strlen(operand);
   for(i=2;i<len-1;i++)
   {
    fprintf(f4,"%x",operand[i]);
    sprintf(temp,"%x",operand[i]);
    strcat(obj[p],temp);
    length++;
   }
   fprintf(f4,"\n");
   p++;
  }
 else if(strcmp(opcode,"WORD")==0)
 {   
  fprintf(f4,"%x\t%s\t%s\t%s\t00000%s\n",address,label,opcode,operand,operand);
  strcpy(obj[p],"00000");
  strcat(obj[p],operand);
  length=length+3;
 }
 else if((strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0))
 {
  fprintf(f4,"%x\t%s\t%s\t%s\n",address,label,opcode,operand);
 }
 else
 {
  rewind(f2);
  fscanf(f2,"%s%x",mnemonic,&u);
  while(strcmp(opcode,mnemonic)!=0)
  {
    fscanf(f2,"%s%x",mnemonic,&u);
  }
  rewind(f3);
  fscanf(f3,"%s%x",mnemonic,&v);
  strcpy(operand1,operand);
  while(strcmp(strtok(operand1,","),mnemonic)!=0)
  {
   fscanf(f3,"%s%x",mnemonic,&v);
  }
  if(strchr(operand,','))
  {
   v=v+0x8000;
   fprintf(f4,"%x\t%s\t%s\t%s\t%x%x\n",address,label,opcode,operand,u,v);
  }
  else
  {
   fprintf(f4,"%x\t%s\t%s\t%s\t%x%x\n",address,label,opcode,operand,u,v);
  }
  sprintf(obj[p],"%x%x",u,v);
  p++;
  length=length+3;
 }
  fscanf(f1,"%x%s%s%s",&address,label,opcode,operand);
 }
 fprintf(f4,"%x\t%s\t%s\t%s",address,label,opcode,operand); 
 sprintf(obj[2],"%x",address);
 start=atoi(obj[2])-start;
 sprintf(obj[2],"%d",start);
 fprintf(f5,"H %s %s %s\n",obj[0],obj[1],obj[2]); 
 fprintf(f5,"T %s %x ",obj[1],length);
 for(i=3;i<p;i++)
 {
  fprintf(f5,"%s ",obj[i]);
 }
 fprintf(f5,"\nE%s",obj[1]);
 fclose(f1);
 fclose(f2);
 fclose(f3);
 fclose(f4);
 fclose(f5);
}
