#include <iostream>
#include <sstream>
using namespace std;

class repeat
{
	private:
	char repeat_char;
	int times_to_repeat;
	public:
	repeat(char c, int r) : repeat_char(c), times_to_repeat(r) {}
	ostream& operator<< (ostream& os, const repeat& r)
	{	
		ostringstream ostr;
		for(int i = 0; i < r.times_to_repeat; i++)
			ostr << r.repeat_char;
		return ostr;
	}
};

int main()
{
	cout << repeat('-', 80) << endl;

	return 0;
}
