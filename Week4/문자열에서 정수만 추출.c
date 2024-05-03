#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main() {
    while (1) { //무한 반복문
        char* input;        //동적할당할 포인터 변수
        int number;  //동적할당할 크기를 받는 정수형 변수
        printf("길이를 입력하세요: ");
        scanf("%d", &number);       //사용자에게 정수형 변수를 입력받음
        input = (char*)malloc(sizeof(char) * number);       //입력받은 정수만큼 동적할당 해줌
        printf("정수 하나를 입력하세요:");
        scanf("%s", input); // 문자열 입력 받기
        sscanf(input, "%d", &number);  //입력받은 문자열 중에서 정수만 걸러서 number변수에 초기화
        printf("입력한 정수는: %d\n", number); //출력
        if (number == 0)  break;      //number가 0이면 반복문 탈출
    }
    printf("프로그램을 종료합니다.\n");
    return 0;  //0반환
}
