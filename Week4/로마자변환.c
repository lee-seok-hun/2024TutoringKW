#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main() {
    int N, n;       //로마자로 변환할 숫자를 받는 변수, 그 변수를 저장하는 변수 선언
    int ten = 1;    //자리수 별로 나눠서 출력하기 위해 사용할 변수 선언
    int index = 0;  //동적할당할 크기를 나타내는 변수
    int score[4] = { 0 };   //각각의 자리 수를 저장할 정수형 배열
    char nine[5] = "IXCM";  //반복문 안에서 문자를 편하게 쓰기 위한 로마자 배열
    char save[7] = "DCLXVI";       //반복문 안에서 문자를 편하게 쓰기위한 로마자 배열
    int len;    //다음 로마자를 이어 붙일 때 그 붙이는 위치의 인덱스를 저장하는 정수형 변수
    char* result;       //변환된 결과 로마자를 담는 포인터형 변수
    result = (char*)malloc(sizeof(char) * index);     //인덱스 크기만큼 문자열 동적할당
    printf("변환 수 입력 : ");  
    scanf("%d", &N);        //변환할 수 사용자에게 입력받음
    n = N;      //N을 저장하기위해 n에 초기화
    for (int i = 3; i >= 0; i--) {  //4번 반복
        score[i] = N % 10;  //10으로 나누면서 저장하면 입력한 수의 자릿수가 반대로 저장되므로 i가 3부터 시작
        N = N / 10; //다음 자릿수 저장을 위해 직접 나눔
    }
    printf("%d=", n);      //각각 자리수를 출력하는 과정
    for (int i = 0; i < 4; i++) {   //각각 자리수를 출력하는 과정
        for (int j = i; j < 3; j++) ten = ten * 10;     //각각 자리수를 출력하는 과정
        printf("%d", score[i] * ten);       //각각 자리수를 출력하는 과정
        ten = 1;    //각각 자리수를 출력하는 과정
        if (i < 3) printf("+"); //각각 자리수를 출력하는 과정
        if (i == 3) printf("=");        //각각 자리수를 출력하는 과정
        len = index;        //길이를 인덱스로 초기화
    }
    if (score[0] == 1) {    //첫째자리 수가 1일때==입력받은 수가 1000일때
        index += 1;         //문자열 크기 1증가
        result = (char*)realloc(result, sizeof(char) * index); //인덱스만큼 다시 동적할당
        result[0] = 'M';    //인덱스 0번째에 M초기화
        len = index;    //문자열 길이에 인덱스 초기화
    }
    for (int t = 0; t < 3; t++) {       //남은 뒤에 3자리수를 변환하기 위해 3번 반복
        if (score[t + 1] == 9) {    //t+1번자리수가 9라면 문자열 크기를 2더하고 재 동적할당 후 각 문자 초기화
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = nine[2 - t];
            result[len + 1] = nine[3 - t];
            len = index;    //문자열 길이에 인덱스 초기화
        }
        else if (score[t + 1] < 9 && score[t + 1] >= 5) {   //t+1번자리수가 5이상 8이하 라면 문자열 크기를 core[t + 1] - 4 더하고 재 동적할당 후 각 문자 초기화
            index += score[t + 1] - 4;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[2 * t];
            for (int i = 0; i < score[t + 1] - 5; i++) result[len + i + 1] = save[(2 * t) + 1];
            len = index;    //문자열 길이에 인덱스 초기화
        }
        else if (score[t + 1] == 4) {   //t+1번자리수가 4라면 문자열 크기를 2더하고 재 동적할당 후 각 문자 초기화
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[(2 * t) + 1];
            result[len + 1] = save[2 * t];
            len = index;    //문자열 길이에 인덱스 초기화
        }
        else if (score[t + 1] < 4 && score[t + 1] >= 1) {   //t+1번자리수가 1이상 3이하 라면 문자열 크기를 score[t + 1] 더하고 재 동적할당 후 각 문자 초기화
            index += score[t + 1];
            result = (char*)realloc(result, sizeof(char) * index);
            for (int i = 0; i < score[t + 1]; i++) result[len + i] = save[(2 * t) + 1];
            len = index;    //문자열 길이에 인덱스 초기화
        }
    }
    for (int i = 0; i < len; i++) printf("%c", result[i]);  //문자열 출력
    return 0;       // 0 반환
}
