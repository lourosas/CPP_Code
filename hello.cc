/********************************************************************
********************************************************************/
#include <iostream>
#include <iomanip>
#include "complex.h"

using namespace std;

int main(int argv, char* argc[]){
   int i = -1;
   cout<<"Hello World\n";
   cout<<++i<<" ";
   Complex a(1,3);
   cout<<++i<<" ";
   Complex b(1,4);
   cout<<a*a.complexConjugate()<<endl;
   Complex c = Complex(1,2) + Complex(0,1);
   cout<<endl<<a<<endl<<b<<endl<<c<<endl;
   a *= b;
   cout<<endl<<a<<endl;
   c *= b;
   b -= a;
   cout<<endl<<a<<endl<<b<<endl<<c<<endl;
   cout<<a*a.complexConjugate()<<endl;
   return 1;
}
