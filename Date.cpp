#include "Date.h"
#include<iostream>
#include<iomanip>
using namespace std;

Date::Date(const Date& d):month(d.month), day(d.day), year(d.year)
{
  cerr << "Date: Copy ctor" << endl;
}

Date::Date(const int &m,const int &d,const int &y) : month(m), day(d), year(y)
{
  cerr << "Date: 3-arg ctor" << endl;
}

void Date::display() const
{
  cout << month << '/';
  cout << day << '/';
  cout << year << endl;
}
