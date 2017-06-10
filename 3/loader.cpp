#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
 string data; 
 char type;
 ifstream input;
 ofstream output;
 input.open("input.txt");
 output.open("output.txt");
 while(type!='E')
 {
  getline(input,data);
  type=data.at(0);
  if(type=='T')
  {
   string opcodes=data.substr(9);
   string locString=data.substr(1,6);
   stringstream s(locString);  
   int loc;
   s>>hex>>loc;
   while(opcodes.length()>0)
   {
    output<<hex<<loc<<" "<<opcodes.substr(0,2)<<endl;
    opcodes.erase(0,2);
    loc++;
   }
  }
 }
}
