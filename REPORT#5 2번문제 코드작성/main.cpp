#include <stdio.h>
#include <math.h>

#define G 9.81  // 중력가속도 설정



void position(double* x, double* y, double* vx, double* vy, double dt) // 위치 저장할 배열을 포인터로 전달

{
   
    *vy = *vy - G * dt; // 속도  (중력 영향)

    *x = *x + (*vx) * dt; // 위치 
    *y = *y + (*vy) * dt;
}

int main()
{
    double x = 0.0, y = 0.0;       // 초기 위치
    double angle = 75.0;             // 발사각 (deg)
    double speed = 15.0;            // 초기속도
    double vx, vy;                  // 속도의 x,y 성분
    double dt = 0.01;                // 시간 간격
    double t = 0.0;                  // 시간 저장
    double max_h = 0.0;              // 최고 높이 저장

    double rad = angle * 3.141592 / 180.0;   // 각도를 라디안으로
   
    vx = speed * cos(rad);
    vy = speed * sin(rad);

    
    while (y >= 0.0) //(y가 떨어져서 땅에 닿을 때까지 반복)
    {
        position(&x, &y, &vx, &vy, dt);
   
        if (y > max_h)   // 최고 높이 체크
        max_h = y;

        t += dt;  // 시간 증가
    }

    
    printf("물로켓 체공시간 : %.2f 초\n", t);
    printf("최고 도달 높이 : %.2f m\n", max_h);
    printf("수평 사거리 : %.2f m\n", x);

    return 0;
}
