#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    double D = 0.05;             // 배관 내경 (m)
    double rho = 998.2;          // 밀도 (kg/m^3)
    double mu = 0.001002;        // 점도 (Pa·s)
    double V;                    // 유속 (m/s)
    double Re, q;                // 레이놀즈수, 동압
    int repeat;                  // 반복 제어 변수

    do {
        printf("유속 V를 입력하세요 (m/s): ");
        scanf("%lf", &V);

        // 레이놀즈수 계산
        Re = (rho * V * D) / mu;

        // 동압 계산
        q = 0.5 * rho * V * V;

        printf("\n===== 결과 =====\n");
        printf("Reynolds 수: %.2f\n", Re);
        printf("동압 q: %.2f Pa\n", q);

        // 유동상태 판정
        if (Re < 2300)
            printf("유동상태: 층류 (Laminar)\n");
        else if (Re <= 4000)
            printf("유동상태: 천이 (Transition)\n");
        else
            printf("유동상태: 난류 (Turbulent)\n");

        printf("\n다시 계산하시겠습니까? (1: 예 / 0: 아니오): ");
        scanf_s("%d", &repeat);

        printf("\n");
    } while (repeat == 1);

    return 0;
}
