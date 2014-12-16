#ifndef REPORT_H
#define REPORT_H
#include "Time.h"
#include "Date.h"
#include <string>

class Report {
  private:
    Date rep_date;
    Time rep_time;
    std::string rep_desc;
    Report(const Report &rep);
  public:
    Report(const int m, const int d, const int y, const int h, const int min, const std::string desc);
    void display() const;
};
#endif
