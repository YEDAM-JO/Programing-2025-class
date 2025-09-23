#include <stdio.h>

int main(void)
{
	char code1 = 'A';
	const char* message = "Fisrt line\n\n\tIndented second line\n\nThird line";
	const char* quotes = "\"double quotes\" and 'single quotes'";
	float average = 87.35f;

	printf("=== Char/string & Escapes ===\n\n");
	printf("Char : %c, code: %d\n\n",code1,code1);

	printf("Message:\n\n");
	printf("%s\n\n", message);

	printf("Quotes:%s\n\n", quotes);
	printf("Backslash: \\\n\n");

	printf("Average:[%8.2f]", average);

	return 0;










}
