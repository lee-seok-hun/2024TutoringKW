#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <malloc.h>
int main() {
    int row, column;   //��� ���� ��Ÿ���� ����
    srand(time(0)); //��ǻ�� �õ尪�� �ð����� �ʱ�ȭ
    scanf("%d %d", &row, &column); //����ڿ��� ��� ���� �Է¹���
    int** mat;  //���������� ����
    mat = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {
        mat[i] = (int*)malloc(sizeof(int) * column);
    }
    for (int i = 0; i < row; i++) {    //3x3 ��Ŀ��� �� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < column; j++) {    //3x3 ��Ŀ��� �� ũ�⸸ŭ �ݺ�
            mat[i][j] = rand() % 21 - 10;   //1��° ��Ŀ� -10~10������ ���� �ʱ�ȭ
        }
    }
    int** matT;  //���������� ����
    matT = (int**)malloc(sizeof(int*) * column);   //�����Ҵ����� �ุŭ �Ҵ���
    for (int i = 0; i < column; i++) {
        matT[i] = (int*)malloc(sizeof(int) * row);//�ึ�� ���� �ٽ� �Ҵ�����
    }
    for (int i = 0; i < column; i++) {    //�� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < row; j++) {    //�� ũ�⸸ŭ �ݺ�
            matT[i][j] = mat[j][i]; //Ʈ����������
        }
    }
    int** result;  //���������� ����
    result = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++) {   //
        result[i] = (int*)malloc(sizeof(int) * row);
    }
    for (int i = 0; i < row; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < column; j++) {   //����ŭ �ݺ�
            printf("%3d ", mat[i][j]); //��� 2���� �迭 ���
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < column; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < row; j++) {   //����ŭ �ݺ�
            printf("%3d ", matT[i][j]); //��� 2���� �迭 ���
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
    for (int i = 0; i < row; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < row; j++) {   //����ŭ �ݺ�
            printf("%4d ", result[i][j]); //��� 2���� �迭 ���
        }
        printf("\n");
    }
    printf("\n");
    int** result1;  //���������� ����
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
    for (int i = 0; i < column; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < column; j++) {   //����ŭ �ݺ�
            printf("%4d ", result1[i][j]); //��� 2���� �迭 ���
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