#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
    int a, b, x, y, r;

    // while문 버전
    printf("두 수 입력: ");
    scanf_s("%d %d", &a, &b);
    x = a; y = b;

    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    printf("최대공약수: %d\n", a);
    printf("최소공배수: %d\n", x * y / a);

    // do-while문 버전
    printf("\n두 수 입력: ");
    scanf_s("%d %d", &a, &b);
    x = a; y = b;

    do {
        r = a % b;
        a = b;
        b = r;
    } while (b != 0);

    printf("최대공약수: %d\n", a);
    printf("최소공배수: %d\n", x * y / a);

    return 0;
}
