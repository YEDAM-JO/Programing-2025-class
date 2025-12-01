#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define END_COND 999


void RandSeed() {        // 난수 시드 초기화 (REPORT#4 작성에 도움이 되는 코드 참고하여 함수코드 작성)

    srand((unsigned int)(time(NULL)));
}


unsigned int RandNum(unsigned int RandomN) {  // 난수 생성 (0 부터 RandomN-1) 

    return rand() % RandomN;
}

int main(void) {
    RandSeed(); // 난수 시드 초기화(똑같은 난수 생성방지를 위해서)

    int RandomN = 0;
    int numbers[100]; // 최대 100개의 난수 저장 
    int count = 0;    // 배열값을 저장위치 COUNT, 0부터 시작

    while (1) {                // While문은 조건이 참일경우 계속 무한반복하는 특성을 이용함
        printf("난수를 생성할 숫자를 입력하세요 (종료코드 999): ");
        scanf("%d", &RandomN);    //값을 입력받고 그걸 RandomN라는 장소에 저장

        if (RandomN == END_COND) {               // 999를 입력했는지 확인하고 맞으면 종료
            printf("프로그램을 종료합니다...\n");
            break;
        }

        if (count < 100) { // 범위 체크
            numbers[count] = RandNum(RandomN); // 난수 생성 후 couunt라는 배열에 저장
            printf("생성된 난수: %d\n", numbers[count]);
            count++;     // 반복이 끝날 때 count가 하나 증가함
        }
        else {
            printf("더 이상 저장할 수 없습니다.\n");
        }
    }

    
    int* ptr = numbers; // 포인터를 활용해서 배열 값 출력
    printf("\n생성된 모든 난수:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", *(ptr + i)); // 포인터로 배열에 간접적으로 접근
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];  // 입력받은 numbers 배열범위의 전체 난수 더하기
    }
    printf("총합: %d\n", sum);


    
    double avg = (double)sum / count;       // 평균 계산

    
    double variance = 0.0;       // 분산의 값을 저장할 위치는 variance
    for (int i = 0; i < count; i++) {
        variance += (numbers[i] - avg) * (numbers[i] - avg); // (값 - 평균)^2 합산
    }
    variance = variance / count; // 총합 / 개수 -> 분산

   
    printf("분산: %.2f\n", variance);//  결과 출력

    
    int stddev = 0; // 표준편차의 값을 저장할 위치는 stddev
    while ((stddev + 1) * (stddev + 1) <= variance) { // 분산보다 작거나 같은 최대 제곱값 찾기
        stddev++;  //반복이 끝날 때 마다 하나씩 stddev 증가(분산보다 커지는 순간 반복이 멈추는데 즉,그 값이 표준편차)
    }
    printf("표준편차: %d\n", stddev);

    return 0;
}
