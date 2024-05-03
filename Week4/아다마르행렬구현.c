#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int func(int** mat1, int a, int b, int c, int d);  //N, ������ �迭�� ��ǥ, 1,-1�� �����ϴ� ������ �Ű������� �־���
int main() {
	int** mat;
	int n, N;  //����ڿ��� �Է¹��� n�� 2�� �������� ��ȯ���ִ� N����
	scanf("%d", &n);   //����ڿ��� �Է¹���
	int sign = 1;
	N = 1;  //2�� n�� �����ٰ��̱� ������ 1�� �ʱ�ȭ
	for (int i = 0; i < n; i++) N = N * 2;  //�ݺ������� �Է¹��� n�� 2�� n�������� �ٲ���
	mat = (int**)malloc(sizeof(int*) * N);	//�� �����Ҵ�
	for (int i = 0; i < N; i++) {
		mat[i] = (int*)malloc(sizeof(int) * N);		//�� �����Ҵ�
	}
	func(mat, N, 0, 0, sign);  // ����Լ� ���
	for (int i = 0; i < N; i++) {  //�ݺ������� �ุŭ �ݺ�
		for (int j = 0; j < N; j++) { //�ݺ������� ����ŭ �ݺ�
			if (mat[i][j] == 1) printf("%2d ", 1);  //i��j���� ���� 1�̸� 1���
			else printf("%2d ", -1);  //i��j���� ���� -1�̸� -1���
		}
		printf("\n");  // ���� �Ѿ������ ����
	}
	for (int i = 0; i < N; i++) {		//�����Ҵ� ����
		free(mat[i]);		//�����Ҵ� ����
	}
	free(mat);
	return 0; //0 ��ȯ
}
int func(int** mat1, int a, int b, int c, int d) {
	if (a == 1) {  //a�� 0�̶�� �� ����Լ��� ������
		mat1[b][c] = d;  //b��c���� �Ű������� ���� d�ʱ�ȭ
		return 0;	//0��ȯ
	}
	else {  //a�� 0�� �ƴҶ� ����Լ��� �ٽ� ȣ���ϴ� �κ�
		func(mat1, a / 2, b, c, d);  //a�� 2�� �����ְ� ��ǥ��  b,c�� �ٽ� ȣ��. d�� �״��
		func(mat1, a / 2, b, c + (a / 2), d);	//a�� 2�� �����ְ� ��ǥ��  b,c+a/2�� �ٽ� ȣ��. d�� �״��
		func(mat1, a / 2, b + (a / 2), c, d);	//a�� 2�� �����ְ� ��ǥ��  b+a/2,c�� �ٽ� ȣ��. d�� �״��
		func(mat1, a / 2, b + (a / 2), c + (a / 2), -d);	//a�� 2�� �����ְ� ��ǥ��  b+a/2,c+a/2�� �ٽ� ȣ��. d�� ��ȣ �ݴ��
	}
}
