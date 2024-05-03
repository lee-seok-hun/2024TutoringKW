#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int func(int** mat1, int a, int b, int c, int d);  //N, 이차원 배열의 좌표, 1,-1을 결정하는 변수를 매개변수로 넣어줌
int main() {
	int** mat;
	int n, N;  //사용자에게 입력받을 n과 2의 제곱수로 변환해주는 N변수
	scanf("%d", &n);   //사용자에게 입력받음
	int sign = 1;
	N = 1;  //2를 n번 곱해줄것이기 때문에 1로 초기화
	for (int i = 0; i < n; i++) N = N * 2;  //반복문으로 입력받은 n을 2의 n제곱으로 바꿔줌
	mat = (int**)malloc(sizeof(int*) * N);	//행 동적할당
	for (int i = 0; i < N; i++) {
		mat[i] = (int*)malloc(sizeof(int) * N);		//열 동적할당
	}
	func(mat, N, 0, 0, sign);  // 재귀함수 사용
	for (int i = 0; i < N; i++) {  //반복문으로 행만큼 반복
		for (int j = 0; j < N; j++) { //반복문으로 열만큼 반복
			if (mat[i][j] == 1) printf("%2d ", 1);  //i행j열의 수가 1이면 1출력
			else printf("%2d ", -1);  //i행j열의 수가 -1이면 -1출력
		}
		printf("\n");  // 열이 넘어갈때마다 개행
	}
	for (int i = 0; i < N; i++) {		//동적할당 프리
		free(mat[i]);		//동적할당 프리
	}
	free(mat);
	return 0; //0 반환
}
int func(int** mat1, int a, int b, int c, int d) {
	if (a == 1) {  //a가 0이라면 이 재귀함수를 종료함
		mat1[b][c] = d;  //b행c열에 매개변수로 받은 d초기화
		return 0;	//0반환
	}
	else {  //a가 0가 아닐때 재귀함수를 다시 호출하는 부분
		func(mat1, a / 2, b, c, d);  //a를 2로 나눠주고 좌표는  b,c로 다시 호출. d는 그대로
		func(mat1, a / 2, b, c + (a / 2), d);	//a를 2로 나눠주고 좌표는  b,c+a/2로 다시 호출. d는 그대로
		func(mat1, a / 2, b + (a / 2), c, d);	//a를 2로 나눠주고 좌표는  b+a/2,c로 다시 호출. d는 그대로
		func(mat1, a / 2, b + (a / 2), c + (a / 2), -d);	//a를 2로 나눠주고 좌표는  b+a/2,c+a/2로 다시 호출. d는 부호 반대로
	}
}
