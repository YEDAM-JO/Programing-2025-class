#include <stdio.h>

#define S_size 90   
#define M_size 100  
#define _CRT_SECURE_NO_WARNINGS

int main() {

    int chest;
    char size;


    printf("chest size (cm): ");
    scanf_s("%d", &chest);



    if (chest <= S_size) {
        size = 'S';
    }

    else if (chest <= M_size) {
        size = 'M';
    }

    else {
        size = 'L';
    }


    printf("Your Size : '%c' \n", size);

    return 0;
}
