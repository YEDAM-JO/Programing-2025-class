#include <stdio.h>

int main()
{
	int age = 24;
	unsigned int Count = 3000000000;
	float Score = 93.5f;
	const char* title = "Basic Constatns";
	const char* name = "Yedam";
	char Initial = name[0];
	printf("=== %s ===\n\n Name \t : %s\n\n Initial : %c\n\n Age : %d\n\n Score \t : %.6f\n\n Count \t : %u\n\n", title, name, Initial, age, Score, Count);
	return 0;
}