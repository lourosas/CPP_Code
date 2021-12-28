/*
 * This file is part of the CPP_Code Dsistribution
 * Copyright (c) 2021 Lou Rosas
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
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
