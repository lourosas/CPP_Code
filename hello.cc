//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

using namespace std;

void doSomeTesting();

/*
*/
int main(int argc, char *argv[]){
   cout<<"Hello World\n"<<argc<<endl<<argv[0]<<endl;
   doSomeTesting();
}

/*
*/
void doSomeTesting(){
   char* theInput    = new char[81];
   int   loopCounter = 0;
   string toContinue;
   do{
      int number;
      loopCounter = 0; //reset the loop counter
      cout<<"Input a Number:  ";cin>>number; cout<<number<<endl;
      cin.ignore(81,'\n');
      do{
         for(int i = 0; i < 81; i++){
            theInput[i] = '\0';//initialize the string
         }
         cout<<"To Continue? Type \"yes\" or \"no\" ";
         cin.get(theInput, 81);
         cin.ignore(81,'\n');
         for(int i = 0; i < strlen(theInput); i++){
            theInput[i] = toupper(theInput[i]);
         }
         toContinue = theInput;
      }while(toContinue != "YES" &&
             toContinue != "NO"  &&
             ++loopCounter < 3);
   }while(toContinue != "NO" && loopCounter < 3);
   if(loopCounter > 2){
     cout<<"\nIt is obvious you do not want ot answer with either "
       <<"a 'yes' or a 'no'!!  So exiting\n";
   }
   cout<<"Goodbye\n";
   delete [] theInput;
}

/*
void doSomeTesting(){
   char toContinue  = '\0';
   int  loopCounter =    0;
   do{
      int number;
      loopCounter = 0;  //Reset the loop counter
      cout<<"Input a Number:  ";cin>>number; cout<<number<<endl;
      do{
         cout<<"To Continue? type 'y' or type 'n' ";
         cin>>toContinue;
      }while(toupper(toContinue) !='Y' && 
             toupper(toContinue) !='N' &&
             ++loopCounter < 3);
      cout<<loopCounter<<endl;
   }while(toupper(toContinue) != 'N' && loopCounter < 3);
   if(loopCounter > 2){
      cout<<"\nIt is obvious you do not want to answer with "
        <<"either a 'y' or 'n'\nSo Exiting\n";
   }
   cout<<"Goodbye!\n";
}
*/

/*
Same logic as above, but a little more awkward to follow
void doSomeTesting(){
   char toContinue  = '\0';
   int  loopCounter =    0;
   do{
      int number;
      loopCounter = 0;
      cout<<"Input a Number:  ";cin>>number;cout<<number<<endl;
      do{
         cout<<"To Continue? type 'y' or type 'n' ";
         cin>>toContinue;
         if(++loopCounter > 2           && 
            toupper(toContinue) != 'N' &&
            toupper(toContinue) != 'Y'){
            cout<<"\nIt is obvious you do not want to answer with "
              <<"either a 'y' or 'n'\nSo Exiting\n";
            toContinue = 'n'; //Break out of the loop
         }
      }while(toupper(toContinue)!='N' && toupper(toContinue)!='Y');
   }while(toupper(toContinue) != 'N');
   cout<<"Goodbye!\n";
}
*/

//////////////////////////////////////////////////////////////////////
