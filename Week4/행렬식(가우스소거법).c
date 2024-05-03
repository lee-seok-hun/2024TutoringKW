#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
int main() {
    int n;
    int result = 1;  //결과값에 주대각 성분을 곱할 것이기 때문에 1로 초기화
    int sign = 1;    //주대각 성분에 0이 있을때 그 행과 그 행보다 뒤에있는 행과 교환할 때 생기는 부호의 변환을 위해 1 출력
    long double tmp;   //분수 계산이 있기 때문에 정밀도가 가장 높은 long double 자료형으로 교환용 변수 선언
    scanf("%d", &n);  //nxn 행렬을 만들기 위해서 n을 입력 받음
    srand(time(NULL));
    long double** mat;   //동적할당을 위해서 이중포인터 선언, 분수 계산을 위해서 long double자료형 사용
    mat = (long double**)malloc(sizeof(long double*) * n);  //n행 역할 동적할당
    for (int i = 0; i < n; i++) {           //n번 반복
        mat[i] = (long double*)malloc(sizeof(long double) * n);      //n열 역할 동적 할당
    }
    for (int i = 0; i < n; i++) {    //nxn 행렬에서 행 크기만큼 반복
        for (int j = 0; j < n; j++) {    //nxn 행렬에서 행 크기만큼 반복
            mat[i][j] = rand() % 19 - 9;        //각 배열에 -9부터 9 사이의 난수를 초기화
        }
    }
    for (int i = 0; i < n; i++) {   //행만큼 반복
        for (int j = 0; j < n; j++) {   //열만큼 반복
            printf("%2d ", (int)mat[i][j]); //결과 2차원 배열 출력
        }
        printf("\n"); //개행
    }
    printf("\n");    //개행
    for (int i = 0; i < n - 1; i++) {    //n번 반복
        if (mat[i][i] == 0) {           //주대각 성분이 0이라는 조건 성립시에 코드 실행
            sign = -sign;               //두 행을 교환한 행렬식의 값은 -부호가 붙으므로 부호 변수값 부호 변화
            for (int k = i + 1; k < n; k++) {       //n-(0일때 주대각 성분의 행) 번 반복
                if (mat[k][i] != 0) {     //열값은 변화 없이 행 하나씩 낮추면서 0이 아닐때
                    for (int t = 0; t < n; t++) {  //두 행을 교환하는 과정
                        tmp = mat[i][t];    //두 행을 교환하는 과정
                        mat[i][t] = mat[k][t];      //두 행을 교환하는 과정
                        mat[k][t] = tmp;        //두 행을 교환하는 과정
                    }
                }
                break;   //넘어가면 반복문 탈출
            }
        }
    }
    for (int i = 0; i < n; i++) {   //행만큼 반복
        for (int j = 0; j < n; j++) {   //열만큼 반복
            printf("%2d ", (int)mat[i][j]); //결과 2차원 배열 출력
        }
        printf("\n"); //개행
    }
    printf("\n");       // 개행
    for (int i = 0; i < n - 1; i++) {   //n-1번 반복
        for (int t = i + 1; t < n; t++) {  //n-i-1번 반복
            long double Gauss1 = mat[i][i];     //기준 주대각 성분 지정
            long double Gauss2 = mat[t][i];     //0이 되게 하는 기준 인덱스
            for (int k = i; k < n; k++) {
                mat[t][k] = mat[t][k] - (mat[i][k] / Gauss1) * Gauss2;      //가우스 로직
            }
        }
    }
    for (int i = 0; i < n; i++) {   //행만큼 반복
        for (int j = 0; j < n; j++) {   //열만큼 반복
            printf("%Lf ", mat[i][j]); //결과 2차원 배열 출력
        }
        printf("\n"); //개행
    }
    for (int i = 0; i < n; i++) {  //n번 반복
        result = result * mat[i][i];    //주대각 성분 곱해줌
    }
    printf("%d", (int)result * sign);  //교환된 수 만큼 반영된 부호값과 결과값을 곱하고 출력
    for (int i = 0; i < n; i++) {
        free(mat[i]);  //동적할당 한 2차원 배열을 모두 사용했으므로 프리 걸어줌
    }
    free(mat);  //동적할당 한 2차원 배열을 모두 사용했으므로 프리 걸어줌
    return 0;   //0반환
}