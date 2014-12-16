#ifndef NAUSEA_H
#define NAUSEA_H

class Nausea
{
	public:
	static int throw_where; //copy_ctor = 0 , default_ctor = 1, assignment_op = 2
	static int trigger;
	Nausea();
	Nausea(const Nausea&);
	Nausea& operator=(const Nausea&);
	
};

#endif
