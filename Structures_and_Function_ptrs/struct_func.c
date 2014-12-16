#include <stdio.h>
#include <math.h>

struct Triangle
{
	short base;
	short height;
	char shade;
	char color;
};

struct Circle
{
	short radius;
	char shade;
	char color;
};

union func_ary_type
{
	void (*circle_print_ptr)(struct Circle*);
	void (*triangle_print_ptr)(struct Triangle*);
	float (*circle_area_ptr)(struct Circle*);
	float (*triangle_area_ptr)(struct Triangle*);
};

void setCircle(struct Circle* x, char sha, char col, short rad);
void setTriangle(struct Triangle* x, char sha, char col, short ba, short hei);
void drawCircle(struct Circle* x);
void drawTriangle(struct Triangle* x);
float areaCircle(struct Circle* x);
float areaTriangle(struct Triangle* x);

int main()
{
	struct Circle my_circle;
	struct Triangle my_triangle;
	union func_ary_type vtc[2];
	union func_ary_type vtt[2];
	vtc[0].circle_print_ptr = &drawCircle;
	vtc[1].circle_area_ptr = &areaCircle;
	vtt[0].triangle_print_ptr = &drawTriangle;
	vtt[1].triangle_area_ptr = &areaTriangle;
	setCircle(&my_circle, 'd', 'r', 32);
	setTriangle(&my_triangle, 'l', 'g', 5, 4);
	
	vtc[0].circle_print_ptr(&my_circle);
	printf("My Circle Area = %f\n",vtc[1].circle_area_ptr(&my_circle));
	vtt[0].triangle_print_ptr(&my_triangle);
	printf("My Triangle Area = %f\n", vtt[1].triangle_area_ptr(&my_triangle));
	return 0;
}



void setCircle(struct Circle* x, char sha, char col, short rad)
{
	x->shade = sha;
	x->color = col;
	x->radius = rad;
}

void setTriangle(struct Triangle* x, char sha, char col, short ba, short hei)
{
	x->shade = sha;
	x->color = col;
	x->base = ba;
	x->height = hei;
}

void drawCircle(struct Circle* x)
{
	if(x->shade == 'l')
		printf("light ");
	if(x->shade == 'd')
		printf("dark ");	
	if(x->color == 'r')
		printf("red ");
	if(x->color == 'g')
		printf("green ");
	if(x->color == 'b')
		printf("blue ");
	printf("Circle , radius = %u\n", x->radius);
}

void drawTriangle(struct Triangle* x)
{
	if(x->shade == 'l')
		printf("light ");
	if(x->shade == 'd')
		printf("dark ");	
	if(x->color == 'r')
		printf("red ");
	if(x->color == 'g')
		printf("green ");
	if(x->color == 'b')
		printf("blue ");
	printf("Triangle , base = %u, height = %u\n", x->base, x->height);
}

float areaCircle(struct Circle* x)
{
	return ((x->radius)*(x->radius)*M_PI);	
}	

float areaTriangle(struct Triangle* x)
{
	return (((x->base)*(x->height))/2);	
}	
