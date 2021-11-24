/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef INTEGER_H
#define INTEGER_H
#include "Object.h"

class Integer : public Object<int>{
   public:
      Integer();
      Integer(int );
      virtual ~Integer();
      //Integer& operator=(const Integer& );
   protected:
   private:
      virtual void generateKey();
};
//std::ostream& operator<<(std::ostream& os, Integer& obj);
#endif
//////////////////////////////////////////////////////////////////////
