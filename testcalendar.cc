#include <iostream>
#include "Calendar.h"

using namespace std;

int main(){
   std::cout<<"\n\n\nHello World\n\n\n";
   Calendar cal;
   //cal.print(std::cout)<<endl;
   std::cout<<cal<<std::endl;
   cal.setDate("December 31, 1900, 12:18:18");
   std::cout<<cal<<std::endl;
   //cal.setDate("01/01/00", cal.AMERICAN);
   return 0;
}
