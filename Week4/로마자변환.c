#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
int main() {
    int N, n;       //�θ��ڷ� ��ȯ�� ���ڸ� �޴� ����, �� ������ �����ϴ� ���� ����
    int ten = 1;    //�ڸ��� ���� ������ ����ϱ� ���� ����� ���� ����
    int index = 0;  //�����Ҵ��� ũ�⸦ ��Ÿ���� ����
    int score[4] = { 0 };   //������ �ڸ� ���� ������ ������ �迭
    char nine[5] = "IXCM";  //�ݺ��� �ȿ��� ���ڸ� ���ϰ� ���� ���� �θ��� �迭
    char save[7] = "DCLXVI";       //�ݺ��� �ȿ��� ���ڸ� ���ϰ� �������� �θ��� �迭
    int len;    //���� �θ��ڸ� �̾� ���� �� �� ���̴� ��ġ�� �ε����� �����ϴ� ������ ����
    char* result;       //��ȯ�� ��� �θ��ڸ� ��� �������� ����
    result = (char*)malloc(sizeof(char) * index);     //�ε��� ũ�⸸ŭ ���ڿ� �����Ҵ�
    printf("��ȯ �� �Է� : ");  
    scanf("%d", &N);        //��ȯ�� �� ����ڿ��� �Է¹���
    n = N;      //N�� �����ϱ����� n�� �ʱ�ȭ
    for (int i = 3; i >= 0; i--) {  //4�� �ݺ�
        score[i] = N % 10;  //10���� �����鼭 �����ϸ� �Է��� ���� �ڸ����� �ݴ�� ����ǹǷ� i�� 3���� ����
        N = N / 10; //���� �ڸ��� ������ ���� ���� ����
    }
    printf("%d=", n);      //���� �ڸ����� ����ϴ� ����
    for (int i = 0; i < 4; i++) {   //���� �ڸ����� ����ϴ� ����
        for (int j = i; j < 3; j++) ten = ten * 10;     //���� �ڸ����� ����ϴ� ����
        printf("%d", score[i] * ten);       //���� �ڸ����� ����ϴ� ����
        ten = 1;    //���� �ڸ����� ����ϴ� ����
        if (i < 3) printf("+"); //���� �ڸ����� ����ϴ� ����
        if (i == 3) printf("=");        //���� �ڸ����� ����ϴ� ����
        len = index;        //���̸� �ε����� �ʱ�ȭ
    }
    if (score[0] == 1) {    //ù°�ڸ� ���� 1�϶�==�Է¹��� ���� 1000�϶�
        index += 1;         //���ڿ� ũ�� 1����
        result = (char*)realloc(result, sizeof(char) * index); //�ε�����ŭ �ٽ� �����Ҵ�
        result[0] = 'M';    //�ε��� 0��°�� M�ʱ�ȭ
        len = index;    //���ڿ� ���̿� �ε��� �ʱ�ȭ
    }
    for (int t = 0; t < 3; t++) {       //���� �ڿ� 3�ڸ����� ��ȯ�ϱ� ���� 3�� �ݺ�
        if (score[t + 1] == 9) {    //t+1���ڸ����� 9��� ���ڿ� ũ�⸦ 2���ϰ� �� �����Ҵ� �� �� ���� �ʱ�ȭ
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = nine[2 - t];
            result[len + 1] = nine[3 - t];
            len = index;    //���ڿ� ���̿� �ε��� �ʱ�ȭ
        }
        else if (score[t + 1] < 9 && score[t + 1] >= 5) {   //t+1���ڸ����� 5�̻� 8���� ��� ���ڿ� ũ�⸦ core[t + 1] - 4 ���ϰ� �� �����Ҵ� �� �� ���� �ʱ�ȭ
            index += score[t + 1] - 4;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[2 * t];
            for (int i = 0; i < score[t + 1] - 5; i++) result[len + i + 1] = save[(2 * t) + 1];
            len = index;    //���ڿ� ���̿� �ε��� �ʱ�ȭ
        }
        else if (score[t + 1] == 4) {   //t+1���ڸ����� 4��� ���ڿ� ũ�⸦ 2���ϰ� �� �����Ҵ� �� �� ���� �ʱ�ȭ
            index += 2;
            result = (char*)realloc(result, sizeof(char) * index);
            result[len] = save[(2 * t) + 1];
            result[len + 1] = save[2 * t];
            len = index;    //���ڿ� ���̿� �ε��� �ʱ�ȭ
        }
        else if (score[t + 1] < 4 && score[t + 1] >= 1) {   //t+1���ڸ����� 1�̻� 3���� ��� ���ڿ� ũ�⸦ score[t + 1] ���ϰ� �� �����Ҵ� �� �� ���� �ʱ�ȭ
            index += score[t + 1];
            result = (char*)realloc(result, sizeof(char) * index);
            for (int i = 0; i < score[t + 1]; i++) result[len + i] = save[(2 * t) + 1];
            len = index;    //���ڿ� ���̿� �ε��� �ʱ�ȭ
        }
    }
    for (int i = 0; i < len; i++) printf("%c", result[i]);  //���ڿ� ���
    return 0;       // 0 ��ȯ
}
