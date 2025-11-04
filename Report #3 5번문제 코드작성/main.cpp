#define _CRT_SECURITY_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int answer, guess, i;

    srand(time(0)); // 난수 시드 초기화
    answer = rand() % 100 + 1; // 1~100 사이 숫자 생성

    printf("1~100 사이 숫자를 맞춰보세요! (기회 10번)\n");

    for (i = 1; i <= 10; i++) {
        printf("%d번째 시도: ", i);
        scanf_s("%d", &guess);

        if (guess > answer) {
            printf("DOWN!\n");
        }
        else if (guess < answer) {
            printf("UP!\n");
        }
        else {
            printf("정답!\n");
            break;
        }
    }

    if (i > 10) {
        printf("기회를 모두 사용했습니다. 정답은 %d였습니다.\n", answer);
    }

    return 0;
}
