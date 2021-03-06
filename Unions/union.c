/* Doug Griffin
   CSCI 511
   Union Assignment(Responses after main() )
*/


#include <stdio.h>

union My_union
{
	int union_int;
	float union_float;
	char union_char;
	int *union_int_ptr;
};


int main()
{
	union My_union example;
	
	example.union_int = 5;
	printf("Union Int = %d\n", example.union_int);
	example.union_float = 4.157;
	printf("Union Float = %lf\n", example.union_float);
	example.union_char = 'd';
	printf("Union Char = %c\n", example.union_char);
	example.union_int_ptr = &example.union_int;
	printf("Union Int PTR = %p\n", example.union_int_ptr);
	printf("Union Float = %lf\n", example.union_float);


	return 0;
}

/*Union Assignment Responses:
	Explanation of Unions: It seems that unions are structures that can be used when you
	may not want every member to be stored for every object. For example, in a parser, we
	could read in a string, int, double, or other types, but we only want to deal with one 
	at a time, so we would use a union with a type of each that would take up less space than
	if we were to use a class made up of multiple members each with locations in memory even
	though they all won't be used at once ever.

	Casting and Unions: Unions are a way to type cast without explicitly stating it. The 		union will only hold one member at a time. The union doesn't convert the type, but in 		memory it is similar to a cast because you could store an integer in the union, but 		print out this memory as a different member type in the union. In a way, this casts the 
	memory to whatever you want from the union.
*/
