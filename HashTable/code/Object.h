/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <iomanip>

class Object{
   public:
      Object();
      Object(int );
      Object(const Object& );
      virtual ~Object();
      Object& operator=(const Object& );
      int key() const;
      virtual std::ostream& print(std::ostream& );
   protected:
      int _key;
   private:
};
std::ostream& operator<<(std::ostream& os, Object& obj);
#endif
//////////////////////////////////////////////////////////////////////
