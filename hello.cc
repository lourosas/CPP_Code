/********************************************************************
********************************************************************/
#include <iostream>
#include <iomanip>
#include "complex.h"
#include "complx.h"

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
   cout<<"\n*****************************************************\n";
   cout<<"\nNow Going to try a template class\n";
   cout<<"\n*****************************************************\n";
   /*
   Complx<int> aplx;
   Complx<int> bplx(0,0);
   Complx<int> cplx(1, -3);
   cout<<bplx<<endl<<cplx<<endl;
   bplx = cplx;
   cout<<bplx<<endl<<cplx<<endl;
   Complx<int> dplx = cplx;
   cout<<dplx<<endl;
   Complx<int> eplx(Complx<int>(23, -6));
   cout<<eplx<<endl;
   cout<<Complx<double>(8.639, 2.22535)<<endl;
   Complx<int> fplx = aplx * bplx;
   cout<<fplx<<endl;
   cout<<dplx * eplx<<endl;
   cout<<Complx<int>(3,5) * Complx<int>(5,0)<<endl;
   cout<<Complx<>(8.1,-1.) * Complx<>(-2.4,3.)<<endl;
   cout<<dplx.complexConjugate()<<endl;
   cout<<cplx.complexConjugate()<<endl;
   cout<<dplx.lengthSquared()<<endl;
   cout<<cplx.lengthSquared()<<endl;
   cout<<aplx.complexConjugate()<<endl;
   cout<<aplx.lengthSquared()<<endl;
   cout<<(Complx<>(8.1, -1.)).complexConjugate()<<endl;
   cout<<(Complx<>(8.1, -1.)).lengthSquared()<<endl;
   cout<<cplx*cplx.complexConjugate()<<endl;
   cout<<(cplx <= bplx)<<endl<<(fplx <= eplx)<<endl;
   dplx = cplx*cplx.complexConjugate();
   cout<<dplx<<endl;
   */
   Complx<int> aplx(3,2);
   Complx<int> bplx(1,1);
   Complx<int> cplx(bplx * bplx.complexConjugate());
   Complx<int> dplx(0,1);
   Complx<>    eplx(aplx/dplx);
   cout<<aplx/bplx<<endl<<cplx<<endl<<aplx/dplx<<endl<<eplx<<endl;
   return 1;
}
