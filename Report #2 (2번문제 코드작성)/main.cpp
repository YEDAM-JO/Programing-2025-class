#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int door;         // 문 상태 (0: 닫힘, 1: 열림)
    float temp;       // 현재 온도 (°C)
    int time;         // 경과 시간 (초)

    printf("문 상태(0=닫힘, 1=열림), 온도(°C), 경과시간(초)를 입력하세요: ");
    scanf("%d %f %d", &door, &temp, &time);

    // 1. 입력값 유효성 검사
    if ((door != 0 && door != 1) || time < 0 || temp < -50 || temp > 50) {
        printf("invalid input\n");
        return 0;
    }

    // 2. 정상 범위 (문 닫힘 + 2~8°C)
    if (door == 0 && temp >= 2.0 && temp <= 8.0) {
        printf("Normal\n");
    }

    // 3. 문이 열림 + 60초 이상 + 온도 초과 또는 저하
    else if (door == 1 && time >= 60 && (temp >= 8.0 || temp <= 2.0)) {
        printf("Critical\n");
    }

    // 4. 문 닫힘 + 온도 벗어남 + 30초 이하
    else if (door == 0 && (temp < 2.0 || temp > 8.0) && time <= 30) {
        printf("Warning\n");
    }

    // 5. 문 닫힘 + 온도 벗어남 + 30초 초과
    else if (door == 0 && (temp < 2.0 || temp > 8.0) && time > 30) {
        printf("Critical\n");
    }

    // 6. 나머지 경우 (예: 문 열렸지만 아직 60초 미만)
    else {
        printf("Normal\n");
    }

    return 0;
}
