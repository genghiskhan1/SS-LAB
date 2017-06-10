#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
string macroName,label,mnemonic,operand,data;
ifstream input("input.txt");
ofstream output("output.txt");
fstream macro("macro.txt");
void getData()
{
 label=" ";
 mnemonic=" ";
 operand=" ";
 getline(input,data);
 stringstream s(data);
 getline(s,label,'\t');
 getline(s,mnemonic,'\t');
 getline(s,operand,'\t');
}
int main()
{
 getData();
 while(!input.eof())
 {
  if(!mnemonic.compare("MACRO"))
  {
   macroName=label;
   getData();
   while(mnemonic.compare("MEND"))
   {
     macro<<label<<"\t"<<mnemonic<<"\t"<<operand<<"\n";
     getData();
   }
  }
  getData();
 }
 input.clear();
 input.seekg(0,ios::beg);
 macro.clear();
 macro.seekg(0,ios::beg);
 getData();
 while(!input.eof())
 {
  if(!mnemonic.compare(macroName))
  {
   if(!label.empty())
   {
    output<<label;
   }
   while(!macro.eof())
   {
     getline(macro,data);
     output<<data<<endl;
   }
  output.seekp(-1,ios::cur);
  macro.clear();
  macro.seekg(0,ios::beg);
 }
 else if(!mnemonic.compare("MACRO"))
 {  
  while(mnemonic.compare("MEND"))
  {
    getData();
  }
 }
 else
 {
  output<<label<<"\t"<<mnemonic<<"\t"<<operand<<endl;
 }
  getData();
 }
 input.close();
 output.close();
 macro.close();
}
