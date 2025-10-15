#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void)
{
    printf("\n");

    int a, b;
    char op;
    int result;

    printf("사칙연산 입력(정수) : ");

    if (scanf_s("%d %c %d", &a, &op, 1, &b) != 3) {

        printf("오류: 입력 형식 잘못 됨.\n");
        return 1;
    }

    if (op == '+')
    {
        result = a + b;
    }
    else if (op == '-')
    {
        result = a - b;
    }
    else if (op == '*')
    {
        result = a * b;
    }
    else if (op == '/')
    {

        if (b == 0) {
            printf("오류: 0으로 나누기 불가함.\n");
            return 1;
        }
        result = a / b;
    }
    else
    {
        printf("오류: 연산자 오류 \n");
        return 1;
    }


    printf("%d%c%d=%d\n", a, op, b, result);

    return 0;
}