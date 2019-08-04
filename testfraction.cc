/*********************************************************************
*********************************************************************/
#include <iostream>
#include <stdexcept>
#include "fraction.h"

using namespace std;

int main(int argv, char* argc[]){
   cout<<"\n\n\nHello World\n\n\n";
   Fraction a;
   Fraction b(2, 5);
   Fraction c(b);
   Fraction d = Fraction(32, 17);
   cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
   d = b;
   cout<<d<<endl;
   try{
      Fraction e(1,0);
      cout<<e<<endl;
   }
   catch(runtime_error& e){
      cout<<e.what();
   }
   cout<<a+b<<endl<<b+b<<endl;
   Fraction e = b+b;
   try{
      cout<<e<<endl<<b + Fraction(1,0);
   }
   catch(runtime_error& e){
      cout<<e.what();
   }
   cout<<b*Fraction(-1,1)<<endl;
   cout<<b*-1<<endl<<b - b<<endl<<b/d<<endl;
   try{
      cout<<b/Fraction(3,5)<<endl;
   }
   catch(runtime_error& e){
      cout<<e.what();
   }
   try{
      cout<<b/-3<<endl;
   }
   catch(runtime_error& e){
      cout<<e.what();
   }
   try{
      cout<<c/0<<endl;
   }
   catch(runtime_error& e){
      e.what();
   }
   try{
      cout<<Fraction(9,8)<<endl;
      cout<<b.divide(Fraction(9,8))<<endl;
      cout<<b.divide(0)<<endl;
   }
   catch(runtime_error& e){
      e.what();
   }
   cout<<b<<endl<<b.divide(9)<<endl;
   cout<<Fraction(-2,8)<<endl<<Fraction(2,-8)<<endl;
   return 0;
}
