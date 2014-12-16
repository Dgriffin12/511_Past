#include <iostream>
#include "Nausea.h"
#include "project2.cpp"
using namespace std;

int Nausea::throw_where = 0;
int Nausea::trigger = 0;

int main()
{
	Nausea::trigger = 100;
	Nausea::throw_where = 0;
	Stack<Nausea> teststack; //creates 10 Nausea objects with new in stack in place of TYPE
	Nausea n[10];
	cout << "Ready to start test!" << endl;
	cout << "About to push!\n";
	for(int i = 0; i < 10; i++)
	{
		//Nausea p(n); //copy constructor		
		teststack.push(n[i]);
		
	}
	teststack.print_all();
	Nausea m[10];
	for(int i = 0; i < 10; i++)
	{
		m[i] = n[i];
	}
	return 0;
}
