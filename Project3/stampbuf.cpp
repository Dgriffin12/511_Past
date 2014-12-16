#include "stampbuf.h"
#include <cstring>
#include <cstdio> //for EOF in overflow

Stampbuf::Stampbuf(int col_size, int row_size) : col(0), row(0), max_col(col_size), max_row(row_size)
{
	buf_size = col_size/2;
	char* buf_ary = new char[buf_size];
	setp(buf_ary, (buf_ary+sizeof(char)*(buf_size)));
	stamping_press::insert_plate(col_size, row_size);
}
Stampbuf::~Stampbuf()
{
	stamping_press::eject_plate();
	char* p_ptr = (this)->pbase();
	delete p_ptr;
}
int Stampbuf::sync()
{
	char cur_char;
	int size = (int)((this->pptr())-(this->pbase())); //get the size of the buffer
	char* p_ptr = (this)->pbase();

	for(int i = 0; i < size; i++)
	{
		cur_char = p_ptr[i]; //get the character to be written from buffer

		if(cur_char != stamping_press::get_die() && cur_char != ' ' && (isalnum(cur_char) || cur_char == '#' || cur_char == '*'))
		{
			stamping_press::set_die(cur_char); //error checking above assures no exception
		}
		if(cur_char != ' ' && cur_char != '\n' && (isalnum(cur_char) || cur_char == '#' || cur_char == '*') && (col < max_col) && (row < max_row))
		{
			stamping_press::stamp(col, row); //error checking above assures no exception
		}

		col++; 		//move to the next column

		if(cur_char == '\n') //if at the max column, move to next row.
		{			               //if cur_char is a newline, go to next row.
			row++;
			col = 0;
		}
		if(col >= max_col)
		{
			row++;
			col = 0;
			break;
		}	
				
	}
	memset((this)->pbase(), 0, sizeof(char)*buf_size);
	setp(p_ptr, p_ptr+sizeof(char)*buf_size); //reset the pointers.
	
}

int Stampbuf::overflow(int c)
{
	char cur_char;
	int size = (int)((this->pptr())-(this->pbase())); //get the size of the buffer
	char* p_ptr = (this)->pbase();

	for(int i = 0; i < size; i++)
	{
		cur_char = p_ptr[i];   //get the character to be written from buffer

		if(cur_char != stamping_press::get_die() && cur_char != ' ' && (isalnum(cur_char) || cur_char == '#' || cur_char == '*'))
		{
			stamping_press::set_die(cur_char); //error checking above assures no exception
		}
		if(cur_char != ' ' && cur_char != '\n' && (isalnum(cur_char) || cur_char == '#' || cur_char == '*') && (col < max_col) && (row < max_row))
		{
			stamping_press::stamp(col, row); //error checking above assures no exception
		}

		col++; 		//move to the next column

		if(cur_char == '\n') //if at the max column, move to next row.
		{			               //if cur_char is a newline, go to next row.
			row++;
			col = 0;
		}
				
	}
	memset((this)->pbase(), 0, sizeof(char)*(buf_size));
	setp(p_ptr, p_ptr+sizeof(char)*(buf_size)); //reset the pointers.

	if(buf_size>0 && col < max_col) //if the buf_size <= 0, we have no buffer, so we can't put, prevent infinite loop in the event that there is no room to write.
	{
		sputc(c);
		return c;
	}else if (buf_size>0 && col >= max_col)
	{
		
	}else
	{
		return EOF; //no buffer, cannot call sputc without an infinite loop.
	}
	
}


void Stampbuf::change_row(int row_in)
{
	row = row_in;
	col = 0;
}

