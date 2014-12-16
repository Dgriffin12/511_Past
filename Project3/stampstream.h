#ifndef STAMPSTREAM_H
#define STAMPSTREAM_H
#include "stamp.h"
#include "stampbuf.h"
#include <iostream>

//to use row(int i) in an ostream
class row
{
	public:
	row(int i);
	int get_row_val() const;
	private:
	int row_val;
	
};

//Stampstream class
class Stampstream : public std::ostream
{
	public:
	Stampstream(int col, int row);
	~Stampstream();
	void endrow_func();
	void row_func(int num);
};

//Ostream functions/operators to use endrow and row(int)
std::ostream& endrow(std::ostream& os);
std::ostream& operator<<(std::ostream& os, const row& r);

#endif
