template<class TYPE>
class Stack
{
  public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int count();
    void push(TYPE element);
    TYPE pop();
  private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    TYPE* base;
};

template<class TYPE>
const int Stack<TYPE>::chunk_size=10;

template<class TYPE>
Stack<TYPE>::Stack():current_size(-1),maximum_size(chunk_size),base(new TYPE[chunk_size])
{
  if(base==0)
    throw "No more memory!";
}

template<class TYPE>
Stack<TYPE>::Stack(const Stack<TYPE>& s):maximum_size(s.maximum_size), base(new TYPE[s.maximum_size])
{
  if(base==0)
    throw "No more memory!";
  if(s.current_size>-1)
  {
    for(current_size=0; current_size<=s.current_size; current_size++)
      base[current_size]=s.base[current_size];
    current_size--;
  }
}

template<class TYPE>
Stack<TYPE>::~Stack()
{
  delete [] base;
}

template<class TYPE>
Stack<TYPE>& Stack<TYPE>::operator=(const Stack<TYPE>& s)
{
  delete [] base;
  maximum_size=s.maximum_size;
  base=new TYPE[maximum_size];
  if(base==0)
    throw "No more memory!";
  current_size=s.current_size;
  if(current_size>-1)
  {
    for(int x=0; x<=current_size; x++)
      base[x]=s.base[x];
  }
  return *this;
}

template<class TYPE>
void Stack<TYPE>::push(TYPE element)
{
  current_size++;
  if(current_size==maximum_size-1)
  {
    maximum_size+=chunk_size;
    TYPE* new_buffer = new TYPE[maximum_size];
    if(new_buffer==0)
      throw "No more memory!";
    for(int x=0; x<current_size; x++)
      new_buffer[x]=base[x];
    delete [] base;
    base=new_buffer;
  }
  base[current_size]=element;
}

template<class TYPE>
TYPE Stack<TYPE>::pop()
{
  if(current_size<0)
    throw "Nothing to pop!";
  return base[current_size--];
}

template<class TYPE>
int Stack<TYPE>::count()
{
  return current_size+1;
}

//FOR TESTING
/*
#include <iostream>
using namespace std;
int main()
{
	Stack <int> my_int_stack;
	Stack <double> my_double_stack;
	my_int_stack.push(5);
	my_double_stack.push(3.14);
	cout << my_int_stack.pop() << endl;
	cout << my_double_stack.pop() << endl;
	return 0;
} */
