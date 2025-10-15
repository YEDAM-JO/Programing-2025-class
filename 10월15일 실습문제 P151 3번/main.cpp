#include <stdio.h>

#define age_limit 20
#define Young_S 85 
#define Young_M 95 

#define Adult_S 90
#define Adult_M 100

int main(void)
{
    int age;
    int chest;
    char size;

    printf("Your age?\n");
    scanf_s("%d", &age);

    printf("Your chest size?\n");
    scanf_s("%d", &chest);

   
    if (age < age_limit)
    {
        
        if (chest <= Young_S) {
            size = 'S';
        }
        else if (chest <= Young_M) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    } 

    else 
    {
        if (chest <= Adult_S) {
            size = 'S';
        }
        else if (chest <= Adult_M) {
            size = 'M';
        }
        else {
            size = 'L';
        }
    } 
    printf("Your size is: %c\n", size);

    return 0;
}



    




	
