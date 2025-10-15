#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 

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
            printf("오류: 0으로 나눌 수 없습니다.\n");
            return 1;
        }
        result = a / b;
    }
    else
    {
        printf("오류: 지원하지 않는 연산자입니다.\n");
        return 1;
    }


    printf("%d%c%d=%d\n", a, op, b, result);

    return 0;
}