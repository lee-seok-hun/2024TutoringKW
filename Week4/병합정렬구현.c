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
    mergeSort(arr, 0, n - 1);    //�迭�� ��Ҹ� �����ϴ� �Լ�
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}
void merge(int* arr1, int first, int mid, int end) {  //�и��� �迭 ���� �� ���� �Լ� 
    int* tmp;
    tmp = (int*)malloc(sizeof(int) * end);      //��ȯ�� �ӽ� ����� �����Ҵ�
    int i = first;        //���� ����
    int j = mid + 1;    //������ ����
    int k = 0;          //�迭 b�� �ε��� ��

    while (i <= mid && j <= end) {
        if (arr1[i] <= arr1[j])        //�и��� ���� �迭�� ������ �迭 ��
            tmp[k++] = arr1[i++];
        else
            tmp[k++] = arr1[j++];
    }
    while (i <= mid) {            //������ ���� ���� �迭�� �ִٸ� �迭 b�� ���� ä���
        tmp[k++] = arr1[i++];
    }
    while (j <= end) {          //������ ���� ������ �迭�� �ִٸ� �迭 b�� ���� ä���
        tmp[k++] = arr1[j++];
    }
    k--;
    while (k >= 0) {              //�迭 b ������ �迭 a ���뿡 �����
        arr1[first + k] = tmp[k];
        k--;
    }
}
void mergeSort(int* arr2, int low, int hight) {   //�迭�� ��Ҹ� �����ϴ� �Լ�
    int mid;
    if (low < hight) {
        mid = (low + hight) / 2;
        mergeSort(arr2, low, mid);            //���� �迭�� ��� �и�
        mergeSort(arr2, mid + 1, hight);      //������ �迭�� ��� �и�
        merge(arr2, low, mid, hight);         //�и��� �迭 ���� �� ���� �Լ�
    }
}