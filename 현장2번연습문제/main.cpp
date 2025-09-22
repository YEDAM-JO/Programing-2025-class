#include <stdio.h>

#define PI_VALUE 3.14159265358979123

int main(void)
{
	int version = 1;

	const int year = 2025;

	const char* title = " C \"printf\" demo\n";
	int Width_demo_num = 123;

	char sample_char = 'A';

	printf("=== Constants &  Formats ===\n\n");

	printf("Course: C Programing (v%d,%u)\n\n",version , year);
	
	printf("Title :%s\n" , title );

	printf("PI default \t : %f\n\n" , PI_VALUE);
	printf("PI 2 digits \t : %.2f\n\n" , PI_VALUE);

	printf("Width demo \t : [%8d]\n\n", Width_demo_num);

	printf("Char sample \t : %c\n\n" , sample_char);
	printf("Backslash \t : \\\n\n");
	return 0;

}