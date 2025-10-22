#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
    int gugudan;
    printf("출력할 단을 입력 (2~9, 전체는 0): ");
    scanf_s("%d", &gugudan);

    if (gugudan == 0) {
        for (int i = 2; i <= 9; i++) {
            printf("== %d단 ==\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d x %d = %d\n", i, j, i * j);
            }
            printf("\n");
        }
    }
    else {
        printf("== %d단 ==\n", gugudan);
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n", gugudan, j, gugudan * j);
        }
    }
    return 0;
}
