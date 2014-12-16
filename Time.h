#ifndef TIME_H
#define TIME_H
class Time {
  public:
    Time(const int &hr, const int &min);
    Time(const Time& t);
    void display() const;
  private:
    int hour;
    int minute;
};
#endif
