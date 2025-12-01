#include <stdio.h>   
#include <stdlib.h>  
#include <time.h>    


int Determinant(int a[3][3]) { //행렬식 구하는 공식 
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1])   // 첫 번째 항
        - a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0])   // 두 번째 항
        + a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);  // 세 번째 항
}

void calcIM(double r[3][3], int a[3][3], int d) { 
    int i, j, p, q, x, y;    // 반복문용 변수 
    int m[2][2];             // 2x2 작은 행렬 
    double cofactor;                // cofactor(여인수) 값

    for (i = 0; i < 3; i++) {         // i는 행
        for (j = 0; j < 3; j++) {     // j는 열
            x = 0;                    

  for (p = 0; p < 3; p++) {       
     if (p == i) continue;       
     y = 0;                         

   for (q = 0; q < 3; q++) { 
    if (q == j) continue; 

          m[x][y++] = a[p][q];  // 값 채우기
                }
                x++; // 작은 행렬 다음 행
            }

            
  cofactor = m[0][0] * m[1][1] - m[0][1] * m[1][0];   //2×2 작은 행렬의 행렬식을 계산

          

           
           r[j][i] = cofactor / d;  //i행j열의 여인수값을 j행 i열에 넣어서 행,열 서로 바꾸기
      }
  }
}

int main() {
    int A[3][3], B[3][3], C[3][3];  // 3x3 행렬 3개 선언 A,B,C
    double R[3][3];                
    int i, j, k, s;                 
    int DetA, DetB;                     // det(A), det(B) 저장할 변수지정

    srand(time(NULL)); // 시간으로 랜덤 설정

    
    for (i = 0; i < 3; i++) {
       for (j = 0; j < 3; j++) {
           A[i][j] = rand() % 10;  // 0~9 범위의 랜덤숫자

           B[i][j] = rand() % 10;  // 0~9 범위 랜덤 숫자

     }
    }
    s = rand() % 10;  // 0~9 범위 랜덤숫ㄱ자

    printf("A:\n");  // A 출력
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }

    
    printf("\nB:\n");  //B출력
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%d ", B[i][j]);
        printf("\n");
    }

  
    printf("\nscalar=%d\n", s);     // 스칼라 출력
   
    printf("\nA+B:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    

   
    printf("\nA-B:\n");              // A-B
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] - B[i][j]; // 뺄셈
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
    printf("\nA*s:\n");          // 스칼라 * A
    for (i = 0; i < 3; i++) { 
        for (j = 0; j < 3; j++) {
            C[i][j] = A[i][j] * s; // 원소마다 스칼라 곱
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
    printf("\nA*B:\n");   // A*B (행렬 곱)                   
    for (i = 0; i < 3; i++) {       // A의 행
        for (j = 0; j < 3; j++) {   // B의 열
            int t = 0;              // 누적합 변수
            for (k = 0; k < 3; k++) // 곱셈 + 더하기 연산
                t += A[i][k] * B[k][j];

            C[i][j] = t;           // 계산 결과 저장
            printf("%d", C[i][j]);
        }
        printf("\n");
    }
    DetA = Determinant(A);   // det(A) 계산
    printf("\ndet(A)=%d  ", DetA);

    if (DetA != 0) {                 // 0이면 역행렬 없음
        printf("역행렬 계산 가능\n");
        calcIM(R, A, DetA);             // 역행렬 계산

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++)
                printf("%f", R[i][j]); // 소수점 포함해서 출력
            printf("\n");
        }
    }
    else printf("역행렬 계산 실패\n");

    DetB = Determinant(B);      // det(B) 계산
    printf("\ndet(B)=%d  ", DetB);

    if (DetB != 0) {
        printf("역행렬 계산 가능\n");
        calcIM(R, B, DetB);

        for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
           printf("%f", R[i][j]);
            printf("\n");
        }
    }
    else printf("역행렬 계산 실패\n");

    return 0; // 프로그램 종료
}
