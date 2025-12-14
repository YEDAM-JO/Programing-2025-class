#include <stdio.h> 
#include <math.h>  // 함수 사용


int main() {
    
    double h_initial = 1600; // 초기 낙하 높이 h1 
    double h_final = 1100;   // 반발 후 최고 높이 h2 

    // 2. 결과 저장 변수 선언
    double e;            // 반발 계수 e
    double n_loss;       // 손실된 에너지의 비율 n

   
    
    double height = h_final / h_initial; // 높이 비율 변수에 저장 (h2 / h1)

   
    
    e = sqrt(height); // 반발계수 e = sqrt(h2 / h1)

   
   
    
    n_loss = 1.0 - height; // 손실 에너지비율 n = 1 - (h2 / h1)
  
    printf("테니스공 충돌 분석 결과 (문제 3/195)\n");
    printf("\n");
    printf("초기 낙하 높이 (h1): %.1f mm\n", h_initial);
    printf("반발 최고 높이 (h2): %.1f mm\n", h_final);
    printf("\n");

    
    printf("1. 반발 계수 (e) = %.4f\n", e);

     
    printf("2. 손실된 에너지의 비율 (n) = %.4f\n", n_loss);
    printf("\n");

    return 0; 
}