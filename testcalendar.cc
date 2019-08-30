#include <iostream>
#include "Calendar.h"

using namespace std;

int main(){
   std::cout<<"\n\n\nHello World\n\n\n";
   Calendar cal;
   cal.print(std::cout)<<endl;
   cal.setDate("January 8, 2019, 12:18:18");
   //cal.setDate("01/01/00");
   return 0;
}
