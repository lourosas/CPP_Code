/**/
#include <iostream>

int* a;

void mergeSort(int , int);
void merge(int , int , int );
void print();

int main()
{
   std::cout<<"\n\nHello World\n\n";
   a = new int[7];
   if(a)
   {
      a[0] = 7; a[1] = 3; a[2] = 5; a[3] = 1;
      a[4] = 6; a[5] = 2; a[6] = 4; //a[7] = 8;
   }
   mergeSort(0, 7);
   print();

   delete [] a;

   return 1;
}

void mergeSort(int beg, int end)
{
   if(beg < (end - 1))
   {
      int mid = (beg + end)/2;
      mergeSort(beg, mid);
      mergeSort(mid, end);
      merge(beg, mid, end);
   }
}

void merge(int beg, int right, int end)
{
   int n1 = right - beg;
   int n2 = end - right;
   int* L = new int[n1];
   int* R = new int[n2];

   for(int i = 0; i < n1; ++i)
   {
      L[i] = a[beg + i];
   }
   for(int i = 0; i < n2; ++i)
   {
      R[i] = a[right + i];
   }
   int i = 0;
   int j = 0;
   for(int k = beg; k < end; ++k)
   {
      if((j >= n2) || ((i < n1) && (L[i] <= R[j])))
      {
         a[k] = L[i];
         ++i;
      }
      else
      {
         a[k] = R[j];
         ++j;
      }
   }
   std::cout<<"\n";
   for(int i = 0; i < n1; ++i)
   {
      std::cout<<L[i]<<" ";
   }
   std::cout<<"\n";
   for(int i = 0; i < n2; ++i)
   {
      std::cout<<R[i]<<" ";
   }
   std::cout<<"\n";
   delete [] L;
   delete [] R;
}

void print()
{
   std::cout<<"\n\n";
   for(int i = 0; i < 7; ++i)
   {
      std::cout<<a[i]<<" ";
   }
   std::cout<<"\n\n";
}
