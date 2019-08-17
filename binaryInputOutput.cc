/////////////////////////////////////////////////////////////////////
/*
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <sstream>

using namespace std;

struct AccademicData{
   char   firstName[80];
   char   lastName[80];
   long   studentId;
   short  totalClassesTaken;
   double gpa;
   
};

AccademicData* accademicData = NULL;

void inputAndSaveAccademicData(AccademicData* , int);
void printAccademicData(int );

int main(int argc, char* argv[]){
   try{
      int records = 0;
      std::cout<<"Hello World\n"<<argv[1]<<endl;
      std::istringstream iss(argv[1]);
      iss>>records;
      accademicData = new AccademicData[records];
      inputAndSaveAccademicData(accademicData, records);
      printAccademicData(records);
      delete [] accademicData;
      cout<<sizeof(AccademicData)<<endl<<sizeof(long)<<sizeof(short)
         <<sizeof(double)<<endl;
   }
   catch(std::logic_error& error){
      cout<<"What just happened?\n";
      cout<<error.what()<<endl;
   }
   catch(const char* msg){
      cout<<msg<<endl;
   }
   catch(...){
      cout<<"What just happened?\n";
   }
}


void inputAndSaveAccademicData(AccademicData* data, int records){
   cout<<data<<endl;
   for(int i = 0; i < records; i++){
      std::cout<<"\nFirst Name:  ";cin.get(data[i].firstName, 80);
      cin.ignore();
      std::cout<<"Last Name: ";cin.get(data[i].lastName, 80);
      cin.ignore();
      std::cout<<"ID: ";cin>>data[i].studentId;
      std::cout<<"Total Classes Taken:  ";
      cin>>data[i].totalClassesTaken;
      std::cout<<"GPA:  ";cin>>data[i].gpa;
      cin.ignore();
   }
   ofstream outs("Students", ios::binary);
   for(int i = 0; i < records; i++){
      outs.write((char*)(data+i), sizeof(AccademicData));
   }
   outs.close();
}


void printAccademicData(int records){
   AccademicData current;
   ifstream ins("Students", ios::binary);
   for(int i = 0; i < records; i++){
      ins.read((char*)&current, sizeof(AccademicData));
      cout<<current.lastName<<", "<<current.firstName
        <<", "<<current.studentId<<", "<<current.totalClassesTaken
        <<", "<<current.gpa<<endl;
   }
   ins.close();
}


/////////////////////////////////////////////////////////////////////
