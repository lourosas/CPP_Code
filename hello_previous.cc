/*
*/
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int startWithAStringEntry(char* );
void convertFromASCIIToNumerical(char*, int );
void writeOutToABinaryFile(char*, int);
void readBack(int );
char* input = NULL;

int main(int argc, char *argv[]){
   input = new char[81];
   cout<<"Hello World\n\n";
   int size = startWithAStringEntry(input);
   convertFromASCIIToNumerical(input, size);
   writeOutToABinaryFile(input, size);
   readBack(size);
   delete [] input;
   return 0;
}

int startWithAStringEntry(char* input){
   short returnValue = -1;
   cout<<"Enter a String (a good string): ";
   cin.get(input, 80); cin.ignore();
   cout<<input;
   returnValue = strlen(input);
   return returnValue;
}


void convertFromASCIIToNumerical(char* input, int size){
   for(int i = 0; i < size; i++){
      cout<<endl<<input[i]<<endl;
      cout<<hex<<showbase<<(short)input[i]<<endl;
   }
   cout<<dec
     <<sizeof(short)<<endl<<sizeof(int)<<endl<<sizeof(long)<<endl;
}

void writeOutToABinaryFile(char* input, int size){
   cout<<size<<endl;
   ofstream outs("output", ios::binary);
   if(outs){
      short a = 3;
      short b = 5;
      short c = 10;
      double x = 3.141592;
      for(int i = 0; i < size; i++){
         outs.put(input[i]);
      }
      outs.flush();
      outs.write((char*)&a, sizeof(short));
      outs.write((char*)&b, sizeof(short));
      outs.write((char*)&c, sizeof(short));
      outs.write((char*)&x, sizeof(double));
      //outs.write((char*)input, sizeof(size*sizeof(char)));
      //outs<<input<<" "<<(int)a<<(int)b<<(int)c<<(double)x;
   }
   else{ cerr<<"Could NOT SAVE to the binary file!!\n"; }
   outs.close();
}

void readBack(int size){
   char* text = new char[size + 1];
   short a, b, c;
   double x;
   a = -1; b = -1; c = -1; x = -1.0;
   cout<<size<<endl;
   ifstream ins("output", ios::binary);
   if(ins){
      ins.read((char*)text, size*sizeof(char));
      cout<<text<<endl;
      ins.read((char*)&a, sizeof(short));
      cout<<hex<<a<<endl;
      ins.read((char*)&b, sizeof(short));
      cout<<hex<<b<<endl;
      ins.read((char*)&c, sizeof(short));
      cout<<hex<<c<<endl;
      ins.read((char*)&x, sizeof(double));
      cout<<dec<<x<<endl;
   }
   else{ cerr<<"Could not open the binary file!!\n"; }
   ins.close();
}
/////////////////////////////////////////////////////////////////////
