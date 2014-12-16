#include "stampstream.h"
#include <memory>

Stampstream::Stampstream(int col, int row) : std::ostream(new Stampbuf(col, row))
{	

}

Stampstream::~Stampstream()
{
	std::streambuf* streambuf_ptr; //declare a temp pointer to call delete on
	streambuf_ptr = (*this).rdbuf(); //get the streambuf pointer
	delete streambuf_ptr; //call delete on the streambuf pointer, freeing the memory.
}


void Stampstream::row_func(int num)
{
	std::streambuf* streambuf_ptr; //declare a temp pointer to call delete on
	streambuf_ptr = (*this).rdbuf(); //get the streambuf pointer
	Stampbuf* stampbuf_ptr = dynamic_cast<Stampbuf*>(streambuf_ptr); //cast streambuf to stampbuf to use row change function
	stampbuf_ptr->change_row(num); //change the row in stampbuf
}

//Row class functions
row::row(int i): row_val(i)
{ 

}

int row::get_row_val() const 
{
	return row_val;
}

//Ostream function additions

std::ostream& endrow(std::ostream& os)
{
	os << '\n';
	os.flush();
	return (os);
}

std::ostream& operator<<(std::ostream& os, const row& r)
{		
	Stampstream* ss = dynamic_cast<Stampstream*>(&os); //get ostream, cast to Stampstream ptr
	ss->flush();
	ss->row_func(r.get_row_val()); //call Stampstreams row function to modify cur_row in Stampbuf
	return (os);
}


