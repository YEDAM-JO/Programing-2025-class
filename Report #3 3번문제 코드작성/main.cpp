#include <stdio.h>

// 두 수의 합을 계산하는 함수 선언
int add(int a, int b) {
    return a + b;            // 전달받은 두 수를 더한 결과 반환
}

int main() {
    int code1 = 10, code2 = 20;
    int result;

    // 함수를 호출하여 num1과 num2의 합을 계산
    result = add(code1, code2);

    // 결과 출력
    printf("두 수의 합은 %d입니다.\n", result);

    return 0;
}