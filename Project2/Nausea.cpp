#include "Nausea.h"
#include <iostream>
using namespace std;

Nausea::Nausea()
{
	if(throw_where == 0 && trigger <= 1)
	{
		cout << "Throwing default ctor exception\n";
		cout << "Trigger = " << trigger << endl;
		throw "default ctor failed!";
	}
	trigger--;
}


Nausea::Nausea(const Nausea& s)
{
	if(throw_where == 1 && trigger <= 1)
	{
		cout << "Throwing copy ctor exception\n";
		cout << "Trigger = " << trigger << endl;
		throw "copy ctor failed!";		
	}
	trigger--;	
}

Nausea& Nausea::operator=(const Nausea& s)
{
	if(throw_where == 2 && trigger <= 1)
	{
		cout << "Throwing operator exception\n";
		cout << "Trigger = " << trigger << endl;
		throw "operator failed!";		
	}
	trigger--;
	return *this;
}

