//Doug Griffin
//CSCI 511
//Function PTR Assignment

#include <stdio.h>

//Function Definitions
float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float divide(float a, float b);


int main()
{
	//Variable Declarations
	int i = 0;
	float a = 5;
	float b = 2;
	float c = 0;
	float (*add_ptr) (float, float) = add;
	float (*function_ptr[4]) (float,float) = {add, subtract, multiply, divide};

	//Add function pointer
	c = add_ptr(a, b);
	printf("%f + %f = %f\n", a, b, c);
	
	//Iterate through function_ptr array of function pointers
	for(i = 0; i < 4; i++)
	{
		c = function_ptr[i](a, b);
		switch(i)
		{
			case 0:
				printf("%f + %f = %f\n", a, b, c);
				break;
			case 1:
				printf("%f - %f = %f\n", a, b, c);
				break;
			case 2:
				printf("%f * %f = %f\n", a, b, c);
				break;
			case 3:
				printf("%f / %f = %f\n", a, b, c);
				break;
			default:
				printf("ERROR, i not the value expected!\n");
				break;

		};
	}
	

}

//FUNCTION DEFINITIONS
float add(float a, float b)
{
	return (a + b);
}

float subtract(float a, float b)
{
	return (a - b);
}

float multiply(float a, float b)
{
	return (a * b);
}

float divide(float a, float b)
{
	return (a / b);
}
