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
      std::ostream& print(std::ostream& ) const;
   protected:
   private:
      void generateKey();
};
std::ostream& operator<<(std::ostream& os, Integer& obj);
std::ostream& operator<<(std::ostream& os, const Integer& obj);
#endif
//////////////////////////////////////////////////////////////////////
