#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
    int passenger, luggage;
    int total;

    printf("승객 수(명)와 짐의 무게(kg)를 입력하세요: ");
    scanf_s("%d %d", &passenger, &luggage);

    // 1. 입력값 유효성 검사
    if (passenger < 0 || passenger > 3 || luggage < 0) {
        printf("invalid input\n");
        return 0;
    }

    // 2. 가능한 탑승 조합인지 검사
    if ((passenger == 3 && luggage > 0) || (passenger == 0 && luggage > 0)) {
        printf("invalid input\n");
        return 0;
    }

    // 3. 총 하중 계산 (승객 1명당 약 70kg으로 가정)
    total = passenger * 70 + luggage;

    // 4. 조건연산자로 출력
    (total <= 600) ? printf("OK\n") : printf("Overload\n");

    return 0;
}
