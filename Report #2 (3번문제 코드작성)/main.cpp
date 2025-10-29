#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846   

int main(void) {
    double theta;
    double m = 100.0;
    double g = 9.8;
    double mu_s = 0.5;
    double mu_k = 0.4;
    double F_down, F_N, F_s, a;
    double rad;

    printf("경사각(도 단위)을 입력하세요: ");
    scanf_s("%lf", &theta);

    // 도 → 라디안 변환
    rad = theta * M_PI / 180.0;

    // 힘 계산
    F_down = m * g * sin(rad);
    F_N = m * g * cos(rad);
    F_s = mu_s * F_N;

    // 정지 여부 판단
    if (F_down <= F_s) {
        printf("정지상태 유지\n");
    }
    else {
        a = g * (sin(rad) - mu_k * cos(rad));
        printf("미끄러집니다 가속도: %.2f m/s²\n", a);
    }

    return 0;
}
