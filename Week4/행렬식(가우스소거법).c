#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
int main() {
    int n;
    int result = 1;  //������� �ִ밢 ������ ���� ���̱� ������ 1�� �ʱ�ȭ
    int sign = 1;    //�ִ밢 ���п� 0�� ������ �� ��� �� �ຸ�� �ڿ��ִ� ��� ��ȯ�� �� ����� ��ȣ�� ��ȯ�� ���� 1 ���
    long double tmp;   //�м� ����� �ֱ� ������ ���е��� ���� ���� long double �ڷ������� ��ȯ�� ���� ����
    scanf("%d", &n);  //nxn ����� ����� ���ؼ� n�� �Է� ����
    srand(time(NULL));
    long double** mat;   //�����Ҵ��� ���ؼ� ���������� ����, �м� ����� ���ؼ� long double�ڷ��� ���
    mat = (long double**)malloc(sizeof(long double*) * n);  //n�� ���� �����Ҵ�
    for (int i = 0; i < n; i++) {           //n�� �ݺ�
        mat[i] = (long double*)malloc(sizeof(long double) * n);      //n�� ���� ���� �Ҵ�
    }
    for (int i = 0; i < n; i++) {    //nxn ��Ŀ��� �� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < n; j++) {    //nxn ��Ŀ��� �� ũ�⸸ŭ �ݺ�
            mat[i][j] = rand() % 19 - 9;        //�� �迭�� -9���� 9 ������ ������ �ʱ�ȭ
        }
    }
    for (int i = 0; i < n; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < n; j++) {   //����ŭ �ݺ�
            printf("%2d ", (int)mat[i][j]); //��� 2���� �迭 ���
        }
        printf("\n"); //����
    }
    printf("\n");    //����
    for (int i = 0; i < n - 1; i++) {    //n�� �ݺ�
        if (mat[i][i] == 0) {           //�ִ밢 ������ 0�̶�� ���� �����ÿ� �ڵ� ����
            sign = -sign;               //�� ���� ��ȯ�� ��Ľ��� ���� -��ȣ�� �����Ƿ� ��ȣ ������ ��ȣ ��ȭ
            for (int k = i + 1; k < n; k++) {       //n-(0�϶� �ִ밢 ������ ��) �� �ݺ�
                if (mat[k][i] != 0) {     //������ ��ȭ ���� �� �ϳ��� ���߸鼭 0�� �ƴҶ�
                    for (int t = 0; t < n; t++) {  //�� ���� ��ȯ�ϴ� ����
                        tmp = mat[i][t];    //�� ���� ��ȯ�ϴ� ����
                        mat[i][t] = mat[k][t];      //�� ���� ��ȯ�ϴ� ����
                        mat[k][t] = tmp;        //�� ���� ��ȯ�ϴ� ����
                    }
                }
                break;   //�Ѿ�� �ݺ��� Ż��
            }
        }
    }
    for (int i = 0; i < n; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < n; j++) {   //����ŭ �ݺ�
            printf("%2d ", (int)mat[i][j]); //��� 2���� �迭 ���
        }
        printf("\n"); //����
    }
    printf("\n");       // ����
    for (int i = 0; i < n - 1; i++) {   //n-1�� �ݺ�
        for (int t = i + 1; t < n; t++) {  //n-i-1�� �ݺ�
            long double Gauss1 = mat[i][i];     //���� �ִ밢 ���� ����
            long double Gauss2 = mat[t][i];     //0�� �ǰ� �ϴ� ���� �ε���
            for (int k = i; k < n; k++) {
                mat[t][k] = mat[t][k] - (mat[i][k] / Gauss1) * Gauss2;      //���콺 ����
            }
        }
    }
    for (int i = 0; i < n; i++) {   //�ุŭ �ݺ�
        for (int j = 0; j < n; j++) {   //����ŭ �ݺ�
            printf("%Lf ", mat[i][j]); //��� 2���� �迭 ���
        }
        printf("\n"); //����
    }
    for (int i = 0; i < n; i++) {  //n�� �ݺ�
        result = result * mat[i][i];    //�ִ밢 ���� ������
    }
    printf("%d", (int)result * sign);  //��ȯ�� �� ��ŭ �ݿ��� ��ȣ���� ������� ���ϰ� ���
    for (int i = 0; i < n; i++) {
        free(mat[i]);  //�����Ҵ� �� 2���� �迭�� ��� ��������Ƿ� ���� �ɾ���
    }
    free(mat);  //�����Ҵ� �� 2���� �迭�� ��� ��������Ƿ� ���� �ɾ���
    return 0;   //0��ȯ
}