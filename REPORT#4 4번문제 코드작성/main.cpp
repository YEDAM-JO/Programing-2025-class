#include <stdio.h>
#include <stdlib.h>      // 함수들을 쓰기 위해 필요하여 작성 (rand(),srand()등)
#include <time.h>        // 난수를 현재시간으로 초기화하기 위해 작성

const int LOTTO_NUM = 6;//로또번호 6개
const int MAX_NUM = 45; // 로또번호는 1~45까지

void Randstarting() {   //난수 시작값 설정
    srand((unsigned int)time(NULL));    //  현재시간을 난수 시작값으로
}

// 1~MAX_NUM 난수 생성
int RandNum() {
    return (rand() % MAX_NUM) + 1;
}

void Lotto(int* arr) {  // 랜덤 로또 번호 생성 (int는 return0;
    for (int i = 0; i < LOTTO_NUM; i++) {
        int num, dup;                    //num은 난수 생성 및 저장하는 변수  dup은 중복인지 포시하는 변수
        while (1) {                     // 0이 아닌값은 전부 참 계속 반복한다는 조건 넣음
            num = RandNum(); // 난수 생성
            dup = 0;
            for (int j = 0; j < i; j++) { // 이전 번호와 중복 체크
                if (arr[j] == num) {
                    dup = 1; // 중복 발견
                    break;
                }
          }
            if (dup == 0) break; // 중복 없으면 스톱
      }
        arr[i] = num; // 배열에 저장
    }
}


void User(int* arr) { //배열저장
    
    int num;      // 입력받는 숫자
    int dup = 0;  // 중복 여부 저장 (0: 중복 아님, 1: 중복)
    
    for (int i = 0; i < LOTTO_NUM; i++) {

        while (1) {   // 무한 반복을 하다가 올바른 값이 들어오면 break로 스톱하기
            scanf_s("%d", &num);

            // 1에서 45까지 체크하고 45를 넘어갈 경우 다시 입력받기
            if (num < 1 || num > MAX_NUM) {
                printf("1~45 사이 입력: ");
                continue;   // 다시 입력받기
            }

            // 입력한 숫자 중복 체크하기
            dup = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] == num) {
                    dup = 1;
                    printf("중복입니다., 다시 입력하세요: ");
                    break;
                }
            }

            if (dup == 0) break;  // 중복이 아니면 while 반복문 종료
        }

        arr[i] = num;  // 유효한 값 저장
    }
}


int CountMatch(int* user, int* lotto) {
    int match = 0;                 // 일치하는 개수를 저장할 변수
    for (int i = 0; i < 6; i++) { // 사용자 번호를 하나씩 확인
        for (int j = 0; j < 6; j++) { // 로또 번호를 하나씩 확인하고
            if (user[i] == lotto[j]) { // 같으면
                match++;              // 일치 개수 증가
                break;                // 이미 일치했으니 다음 사용자 번호로
            }
        }
    }
    return match; // 총 일치 개수 반환
}


int main() {
    int lotto[LOTTO_NUM], user[LOTTO_NUM];

    Randstarting();
    Lotto(lotto);
    printf("6개 로또 번호 입력: ");
    User(user);

    printf("\n컴퓨터 번호: ");
    for (int i = 0; i < LOTTO_NUM; i++) printf("%d ", lotto[i]);

    int match = CountMatch(user, lotto);
    printf("\n일치한 개수: %d\n", match);
    
    if (match == 6)
        printf("1등 당첨\n");
    else if (match >= 3)
        printf("당첨\n");
    else
        printf("꽝\n");

    return 0;
}
