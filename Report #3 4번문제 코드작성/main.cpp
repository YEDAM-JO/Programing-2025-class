#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 함수: 배열에 1~100 사이의 난수를 10개 생성하여 저장
void makeRandom(int a[]) {
    int i;
    for (i = 0; i < 10; i++) {
        a[i] = rand() % 100 + 1; // 1~100까지 범위 난수 생성
    }
}

int main() {
    int num[10];    // 난수를 저장할 배열
    int i;
    int sum = 0;    // 총합 변수
    double avg;     // 평균 변수
    double var = 0; // 분산 변수
    double std;     // 표준편차 변수 

    srand(time(0)); // 난수 시드 설정

    makeRandom(num); // 난수 10개 생성

    // 생성된 난수 출력 및 합계 계산
    printf("생성된 숫자 : ");
    for (i = 0; i < 10; i++) {
        printf("%d ", num[i]);
        sum = sum + num[i]; // 합계 누적
    }

    // 평균 계산
    avg = sum / 10.0;

    // 분산 계산
    for (i = 0; i < 10; i++) {
        var = var + (num[i] - avg) * (num[i] - avg);
    }
    var = var / 10;

    // 표준편차 계산 
    std = var;





    // 선택문: 표준편차 크기에 따라 다른 메시지 출력
    if (std > 100) {
        printf("\n표준편차 너무 큼\n");
    }
    else {
        printf("\n표준편차 괜찮음\n");
    }

    // 계산 결과 출력
    printf("총합 = %d\n", sum);
    printf("평균 = %.2f\n", avg);
    printf("분산 = %.2f\n", var);
    printf("표준편차 = %.2f\n", std);

    return 0;
}