#include "Report.h"
#include <iostream>


// constructor to create a report
Report::Report(const int m, const int d, const int y, const int h, const int min, const std::string desc)
: rep_date(m, d, y), rep_time(h, min), rep_desc(desc)
{

}

//display function
void Report::display() const
{
	rep_time.display();
	rep_date.display();
	std::cout << rep_desc << std::endl;
}

