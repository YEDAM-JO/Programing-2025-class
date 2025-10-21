#include <stdio.h> 
#define _CRT_SECURE_NO_WARNINGS
int main(void) {
    int a, b;                         // 입력받을 두 정수 변수 선언

    printf("두 개의 정수를 입력하세요: ");  // 안내 문구 출력
    scanf_s("%d,%d", &a, &b); // 두 정수를 입력받아 a와 b에 저장

    if (a > b)                        // a가 b보다 큰 경우
        printf("a는 b보다 큽니다.\n");
    else if (a < b)                   // a가 b보다 작은 경우
        printf("a는 b보다 작습니다.\n");
    else                              // a와 b가 같은 경우
        printf("a와 b는 같습니다.\n");

    if ((a > 0) && (b > 0))           // 두 수가 모두 양수인 경우 "두 수 모두 양수입니다"라고 출력
        printf("두 수 모두 양수입니다.\n");
    else if ((a < 0) || (b < 0))      // 두 수 중 하나라도 음수인 경우 "둘 중 하나는 음수입니다"라고 출력
        printf("둘 중 하나는 음수입니다.\n");
    else                              // 나머지의 경우 "하나 이상의 수가 0입니다."라고 출력
        printf("하나 이상의 수가 0입니다.\n");

    a++;                              // a를 1 만큼 증가시킨다 
    b--;                              // b를 1 만큼 감소한다 
    printf("증감 후 a = %d, b = %d\n", a, b);  // 변경값 출력

    printf("프로그램을 종료합니다.\n");   // 프로그램 종료 안내부분

    return 0;                         // 프로그램 정상 종료
}
