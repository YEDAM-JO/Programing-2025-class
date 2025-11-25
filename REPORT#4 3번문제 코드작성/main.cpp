#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

double vecA[3];   // 3차원 벡터라서 크기를 3으로 설정 (면,행,열)
double vecB[3];

double CalcDot(double* a, double* b) // 두 벡터의 내적을 계산하는 함수   '내적 (dot product)'

{
    double sum = 0.0;  // 내적 결과를 저장할 바구니

    
    for (int i = 0; i < 3; i++)  
    {
        sum += a[i] * b[i];     // 각각을 곱한 뒤 모두 더함
    }

    return sum;  // 계산한 내적 값을 sum이라는 변수에 돌려줌
}


void CalcCross(double* a, double* b, double* res) // 두 벡터의 외적을 계산하는 함수, 결과는 res 배열에 넣어줌   '외적 (cross product)'
                                                  // (여기서 나오는*은 곱하기 기호가 아닌 데이터를 가리키는 주소)
{
    
    res[0] = a[1] * b[2] - a[2] * b[1];  // x 성분 (// 외적 구하는 공식 그대로 작성)
    res[1] = a[2] * b[0] - a[0] * b[2];  // y 성분
    res[2] = a[0] * b[1] - a[1] * b[0];  // z 성분
}

int main(void)
{
   
    double vecA[3];   // 벡터 A를 저장할 배열
    double vecB[3];   // 벡터 B를 저장할 배열

    
    double crossRes[3]; // 외적 결과를 저장할 배열

    
    double dotRes = 0.0;   // 내적 결과 저장 할 바구니

    
    printf("벡터 A값을 입력하세요 (3개): ");   // 벡터 A 입력받기
    for (int i = 0; i < 3; i++)
        scanf_s("%lf", &vecA[i]);

    
    printf("벡터 B의 값을 입력하세요 (3개): ");    // 벡터 B 입력받기
    for (int i = 0; i < 3; i++)
        scanf_s("%lf", &vecB[i]);

    
    dotRes = CalcDot(vecA, vecB);         // 내적 계산 함수 호출

    
    CalcCross(vecA, vecB, crossRes);         // 외적 계산 함수 호출

   
    printf("\n내적(Dot Product) = %.3lf\n", dotRes);
    printf("외적(Cross Product) = ( %.3lf , %.3lf , %.3lf )\n",    // 결과 출력
        crossRes[0], crossRes[1], crossRes[2]);

    return 0;  // 끝
}
