
#include <stdio.h>
#include <math.h>

#define G 9.8  // 중력가속도 



void position(double* x, double* y, double* vx, double* vy, double timein) // 위치 저장할 배열을 포인터로 지정

{

    *vy = *vy - G * timein; // 속도  

    *x = *x + (*vx) * timein; // 위치 
    *y = *y + (*vy) * timein;
}

int main()
{
    double x = 0.0, y = 0.0;       // 초기 위치
    double angle = 75.0;             // 발사각 
    double speed = 15.0;            // 초기속도
    double vx, vy;                  // 속도의 x,y
    double timein = 0.01;                // 시간 간격 (time interval)
    double t = 0.0;                  // 시간 저장
    double maxh = 0.0;              // 최고 높이 저장

    double rad = angle * 3.141592 / 180.0;   // 각도를 라디안으로 바꿔서 계산
    vx = speed * cos(rad);
    vy = speed * sin(rad);


    while (y >= 0.0) //(y가 떨어져서 땅에 닿을 때까지 반복)
    {
        position(&x, &y, &vx, &vy, timein);

        if (y > maxh)   // 최고 높이 체크
            maxh = y;

        t += timein;  // 시간 증가
    }


    printf("물로켓 체공시간 : %.1f 초\n", t);
    printf("최고 도달 높이 : %.1f m\n", maxh);
    printf("수평 사거리 : %.1f m\n", x);

    return 0;
}
