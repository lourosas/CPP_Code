#include <iostream>
#include "Calendar.h"

using namespace std;

int main(){
   std::cout<<"\n\n\nHello World\n\n\n";
   Calendar cal;
   //cal.print(std::cout)<<endl;
   std::cout<<cal<<std::endl;
   //cal.setDate("August 31, 2019");
   //cal.setDate("August 31, 2019, 12:18:38");
   cal.setDate("22/7/2019 12:18", cal.BRITISH);
   std::cout<<cal<<std::endl;
   return 0;
}
