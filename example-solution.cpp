/////////////////////////////////////////////////////////////
//
// Author: Иван Иванов
// FN: 80000
// Program: Компютърни науки
// Date: 25.08.2017
//

#include <iostream>

///
/// Клас представящ UNIX времево клеймо
///
class Timestamp
{
private:
  unsigned long m_Seconds;

public:

  Timestamp(unsigned long seconds = 0) : m_Seconds(seconds)
  {
  }

  unsigned long GetValue() const
  {
    return m_Seconds;
  }

  unsigned long SetValue(unsigned long seconds)
  {
    m_Seconds = seconds;
  }

  Timestamp& operator+= (unsigned long seconds)
  {
    SetValue(GetValue() + seconds);
    return *this;
  }

  Timestamp operator+ (Timestamp const& ts) const
  {
    return Timestamp(GetValue() + ts.GetValue());
  }

};

std::ostream& operator<< (std::ostream& os, Timestamp const& ts)
{
  return os << ts.GetValue();
}

std::istream& operator>> (std::istream& is, Timestamp& ts)
{
  unsigned long seconds;
  is >> seconds;
  ts.SetValue(seconds);
  return is;
}

#include "UnitTestFramework.h"

//-------------------------------------------------------------------------
//
// ВАЖНО: Преди предаване на решението, моля премахнете коментара от дадения по-долу ред,
//        за да активирате автоматичните тестове за решението си.
//
//-------------------------------------------------------------------------
#include "example-tests.h"

int main()
{

  //-------------------------------------------------------------------------
  //
  // ВАЖНО: При предаване на работата във тялото на функцията main не трябва да се
  //        изпълнява нищо друго освен функцията RunTests().
  //
  //-------------------------------------------------------------------------
  RunTests();

  return 0;
}
