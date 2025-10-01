#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <stdio.h>

int main(void)
{
    char name[20];
    char studentID[20];
    double height;
    double weight;
    double bmi;

    printf("Name, StudentID, Height(cm), weight(kg) \n\n");
    scanf_s("%s %s %lf %lf", name, (unsigned)sizeof(name), studentID, (unsigned)sizeof(studentID), &height, &weight);

    bmi = weight / ((height / 100.0) * (height / 100.0));


    printf("Name : %s\n\n", name);
    printf("StudentID : %s\n\n", studentID);
    printf("Height(cm) : %.1lf cm\n\n", height);
    printf("weight(kg) : %.1lf kg\n\n", weight);

 
    printf("BMI: %.2lf\n", bmi);

    return 0;
}