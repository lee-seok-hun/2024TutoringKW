#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
int main() {
    while (1) { //���� �ݺ���
        char* input;        //�����Ҵ��� ������ ����
        int number;  //�����Ҵ��� ũ�⸦ �޴� ������ ����
        printf("���̸� �Է��ϼ���: ");
        scanf("%d", &number);       //����ڿ��� ������ ������ �Է¹���
        input = (char*)malloc(sizeof(char) * number);       //�Է¹��� ������ŭ �����Ҵ� ����
        printf("���� �ϳ��� �Է��ϼ���:");
        scanf("%s", input); // ���ڿ� �Է� �ޱ�
        sscanf(input, "%d", &number);  //�Է¹��� ���ڿ� �߿��� ������ �ɷ��� number������ �ʱ�ȭ
        printf("�Է��� ������: %d\n", number); //���
        if (number == 0)  break;      //number�� 0�̸� �ݺ��� Ż��
    }
    printf("���α׷��� �����մϴ�.\n");
    return 0;  //0��ȯ
}
