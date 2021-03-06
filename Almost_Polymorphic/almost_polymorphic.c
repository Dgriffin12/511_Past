#include <stdio.h>
#include <math.h>

struct Circle;
struct Triangle;

union func_ary_type
{
	void (*circle_print_ptr)(struct Circle*);
	void (*triangle_print_ptr)(struct Triangle*);
	float (*circle_area_ptr)(struct Circle*);
	float (*triangle_area_ptr)(struct Triangle*);
};

union shape_ptr{
	struct Circle* cir_ptr;
	struct Triangle* tri_ptr;
};

struct Triangle
{
	short base;
	union func_ary_type vtt[2];
	short height;
	char shade;
	char color;		
};

struct Circle
{
	short radius;
	union func_ary_type vtc[2];
	char shade;
	char color;	
};

void do_poly(union shape_ptr shape);
void setCircle(struct Circle* x, char sha, char col, short rad);
void setTriangle(struct Triangle* x, char sha, char col, short ba, short hei);
void drawCircle(struct Circle* x);
void drawTriangle(struct Triangle* x);
float areaCircle(struct Circle* x);
float areaTriangle(struct Triangle* x);

int main()
{
	int i = 0;
	struct Circle my_circle1;
	struct Circle my_circle2;
	struct Triangle my_triangle1;
	struct Triangle my_triangle2;
		
	setCircle(&my_circle1, 'd', 'r', 32);
	setCircle(&my_circle2, 'l', 'b', 12);
	setTriangle(&my_triangle1, 'l', 'g', 5, 4);
	setTriangle(&my_triangle2, 'd', 'b', 2, 3);
	
	union shape_ptr shapes[4];
	shapes[0].tri_ptr = &my_triangle1;
	shapes[1].tri_ptr = &my_triangle2;
	shapes[2].cir_ptr = &my_circle1;
	shapes[3].cir_ptr = &my_circle2;

	for(i = 0; i < 4; i++)
	{
		do_poly(shapes[i]);
	}
	return 0;
}


void do_poly(union shape_ptr shape)
{
	shape.tri_ptr->vtt[0].triangle_print_ptr(shape.tri_ptr);
	shape.tri_ptr->vtt[1].triangle_area_ptr(shape.tri_ptr);
}

void setCircle(struct Circle* x, char sha, char col, short rad)
{
	x->shade = sha;
	x->color = col;
	x->radius = rad;
	x->vtc[0].circle_print_ptr = &drawCircle;
	x->vtc[1].circle_area_ptr = &areaCircle;
}

void setTriangle(struct Triangle* x, char sha, char col, short ba, short hei)
{
	x->shade = sha;
	x->color = col;
	x->base = ba;
	x->height = hei;
	x->vtt[0].triangle_print_ptr = &drawTriangle;
	x->vtt[1].triangle_area_ptr = &areaTriangle;
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
	printf("Area Circle = %f\n", ((x->radius)*(x->radius)*M_PI));
	return ((x->radius)*(x->radius)*M_PI);	
}	

float areaTriangle(struct Triangle* x)
{
	printf("Area Triangle = %f\n", (((x->base)*(x->height))/2.0));
	return (((x->base)*(x->height))/2.0);	
}	
