#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<bitset>
#include<iomanip>
using namespace std;
int main()
{
 string data;
 char type;
 int start;
 ifstream input("input.txt");
 ofstream output("output.txt");
 cout<<"\n\tENTER STARTING ADDRESS:\t";
 cin>>hex>>start;
 while(type!='E')
 { 
  getline(input,data);
  type=data.at(0);
  if(type=='T')
  {
   int mod,add,loc=0;
   int mask=0x800;
   string address;
   string locString=data.substr(1,6);
   string modifier=data.substr(7,3);
   string opcodes=data.substr(10); 
   stringstream s1(locString);
   s1>>hex>>loc;
   loc+=start;
   stringstream s2(modifier);
   s2>>hex>>add;
   while(opcodes.length()>0)
   {
     address=opcodes.substr(0,6); 
     stringstream s3(address);
     s3>>hex>>add;
     int a=mod;
     if(a & mask)
     {
      add+=start;
     }
     mod=mod << 1;
     a=mod;
     output<<hex<<loc<<" "<<hex<<add<<endl;
     opcodes.erase(0,6);
     loc+=3;
   }
  }
 }
}
