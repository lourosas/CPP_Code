/*
*/
//////////////////////////////////////////////////////////////////////
#ifndef INTEGER_H
#define INTEGER_H
#include "Object.h"

class Integer : public Object{
   public:
      Integer();
      Integer(int );
      Integer(const Integer& );
      virtual ~Integer();
      Integer& operator=(const Integer& );
      virtual std::ostream& print(std::ostream& );
   protected:
   private:
};
std::ostream& operator<<(std::ostream& os, Object& obj);
#endif
//////////////////////////////////////////////////////////////////////

