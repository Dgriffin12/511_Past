#ifndef DATE_H
#define DATE_H
//compile with -fno-elide-constructors
class Date {
  public:
    Date(const int &m, const int &d, const int &y); //3-arg ctor
    Date(const Date& d);       //copy ctor
    void display() const;
  private:
    int month;
    int day;
    int year;
};
#endif
