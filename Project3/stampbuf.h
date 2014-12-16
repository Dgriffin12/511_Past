#ifndef STAMPBUF_H
#define STAMPBUF_H
#include <iostream>
#include "stamp.h"
#include <cctype>

class Stampbuf : public std::streambuf
{
	public:
	Stampbuf(int col_size, int row_size);
	~Stampbuf();
	virtual int sync();
	virtual int overflow(int c);
	void change_row(int row_in);

	private:
	int col;
	int row;
	int buf_size; //holds the size of the buffer (member var here so you can change from constructor and not need to change it everywhere in the .cpp file.
	int max_col;
	int max_row;
	
};
#endif
