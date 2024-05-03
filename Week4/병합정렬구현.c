#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <time.h>

void merge(int* arr1, int low, int mid, int hight);
void mergeSort(int* arr2, int low, int hight);
int main(void) {
    int* arr;
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, n - 1);    //배열의 요소를 분할하는 함수
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}
void merge(int* arr1, int first, int mid, int end) {  //분리된 배열 정렬 및 병합 함수 
    int* tmp;
    tmp = (int*)malloc(sizeof(int) * end);      //교환용 임시 행렬을 동적할당
    int i = first;        //왼쪽 시작
    int j = mid + 1;    //오른쪽 시작
    int k = 0;          //배열 b의 인덱스 값

    while (i <= mid && j <= end) {
        if (arr1[i] <= arr1[j])        //분리된 왼쪽 배열과 오른쪽 배열 비교
            tmp[k++] = arr1[i++];
        else
            tmp[k++] = arr1[j++];
    }
    while (i <= mid) {            //비교하지 않은 왼쪽 배열이 있다면 배열 b에 전부 채우기
        tmp[k++] = arr1[i++];
    }
    while (j <= end) {          //비교하지 않은 오른쪽 배열이 있다면 배열 b에 전부 채우기
        tmp[k++] = arr1[j++];
    }
    k--;
    while (k >= 0) {              //배열 b 내용을 배열 a 내용에 덮어쓰기
        arr1[first + k] = tmp[k];
        k--;
    }
}
void mergeSort(int* arr2, int low, int hight) {   //배열의 요소를 분할하는 함수
    int mid;
    if (low < hight) {
        mid = (low + hight) / 2;
        mergeSort(arr2, low, mid);            //왼쪽 배열의 요소 분리
        mergeSort(arr2, mid + 1, hight);      //오른쪽 배열의 요소 분리
        merge(arr2, low, mid, hight);         //분리된 배열 정렬 및 병합 함수
    }
}