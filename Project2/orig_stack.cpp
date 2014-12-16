class Stack
{
  public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    Stack& operator=(const Stack&);
    int count();
    void push(int);
    int pop();
  private:
    static const int chunk_size;
    unsigned maximum_size;
    int current_size;
    int* base;
};

const int Stack::chunk_size=10;

  Stack::Stack()
:current_size(-1),maximum_size(chunk_size),base(new int[chunk_size])
{
  if(base==0)
    throw "No more memory!";
}

  Stack::Stack(const Stack& s)
:maximum_size(s.maximum_size), base(new int[s.maximum_size])
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

Stack::~Stack()
{
  delete [] base;
}

Stack& Stack::operator=(const Stack& s)
{
  delete [] base;
  maximum_size=s.maximum_size;
  base=new int[maximum_size];
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

void Stack::push(int element)
{
  current_size++;
  if(current_size==maximum_size-1)
  {
    maximum_size+=chunk_size;
    int* new_buffer = new int[maximum_size];
    if(new_buffer==0)
      throw "No more memory!";
    for(int x=0; x<current_size; x++)
      new_buffer[x]=base[x];
    delete [] base;
    base=new_buffer;
  }
  base[current_size]=element;
}

int Stack::pop()
{
  if(current_size<0)
    throw "Nothing to pop!";
  return base[current_size--];
}

int Stack::count()
{
  return current_size+1;
}
