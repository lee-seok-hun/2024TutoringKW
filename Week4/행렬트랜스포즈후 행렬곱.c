#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <malloc.h>
int main() {
    int row, column;   //행과 열을 나타내는 변수
    srand(time(0)); //컴퓨터 시드값을 시간으로 초기화
    scanf("%d %d", &row, &column); //사용자에게 행과 열을 입력받음
    int** mat;  //이중포인터 선언
    mat = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        mat[i] = (int*)malloc(sizeof(int) * column);
    }
    for (int i = 0; i < row; i++) {    //3x3 행렬에서 행 크기만큼 반복
        for (int j = 0; j < column; j++) {    //3x3 행렬에서 열 크기만큼 반복
            mat[i][j] = rand() % 21 - 10;   //1번째 행렬에 -10~10까지의 난수 초기화
        }
    }
    int** matT;  //이중포인터 선언
    matT = (int**)malloc(sizeof(int*) * column);   //동적할당으로 행만큼 할당함
    for (int i = 0; i < column; i++) {
        matT[i] = (int*)malloc(sizeof(int) * row);//행마다 열을 다시 할당해줌
    }
    for (int i = 0; i < column; i++) {    //행 크기만큼 반복
        for (int j = 0; j < row; j++) {    //열 크기만큼 반복
            matT[i][j] = mat[j][i]; //트랜스포지션
        }
    }
    int** result;  //이중포인터 선언
    result = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {   //
        result[i] = (int*)malloc(sizeof(int) * row);
    }
    for (int i = 0; i < row; i++) {   //행만큼 반복
        for (int j = 0; j < column; j++) {   //열만큼 반복
            printf("%3d ", mat[i][j]); //결과 2차원 배열 출력
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < column; i++) {   //행만큼 반복
        for (int j = 0; j < row; j++) {   //열만큼 반복
            printf("%3d ", matT[i][j]); //결과 2차원 배열 출력
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            result[i][j] = 0;
        }
    }
    for (int a = 0; a < row; a++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                result[a][i] += mat[i][j] * matT[j][a];
            }
        }
    }
    for (int i = 0; i < row; i++) {   //행만큼 반복
        for (int j = 0; j < row; j++) {   //열만큼 반복
            printf("%4d ", result[i][j]); //결과 2차원 배열 출력
        }
        printf("\n");
    }
    printf("\n");
    int** result1;  //이중포인터 선언
    result1 = (int**)malloc(sizeof(int*) * column);
    for (int i = 0; i < column; i++) {   //
        result1[i] = (int*)malloc(sizeof(int) * column);
    }
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < column; j++) {
            result1[i][j] = 0;
        }
    }
    for (int a = 0; a < column; a++) {
        for (int i = 0; i < column; i++) {
            for (int j = 0; j < row; j++) {
                result1[a][i] += mat[j][i] * matT[a][j];
            }
        }
    }
    for (int i = 0; i < column; i++) {   //행만큼 반복
        for (int j = 0; j < column; j++) {   //열만큼 반복
            printf("%4d ", result1[i][j]); //결과 2차원 배열 출력
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < row; i++) {
        free(mat[i]);
    }
    free(mat);
    for (int i = 0; i < column; i++) {
        free(matT[i]);
    }
    free(matT);
    for (int i = 0; i < row; i++) {
        free(result[i]);
    }
    free(result);
    for (int i = 0; i < column; i++) {
        free(result1[i]);
    }
    free(result1);
    return 0;
}