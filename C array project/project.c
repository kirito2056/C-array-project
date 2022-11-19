#define _CRT_SECURE_NO_WARNINGS

//�⺻���� ����� ���̺귯��
#include <stdio.h>

// ���� ������ ���� ���̺귯�� �ҷ�����
#include <stdlib.h>
#include <time.h>

// ���� ���� ���
void print_array() {

	//* ���
	for (int i = 0; i < 35; i++) printf("*");
	printf("\n");

	//���� ���� �� ��ȣ �ȳ�
	printf("*** �������� ���� ���α׷� ���� ***\n");
	printf("***                             ***\n");
	printf("*** 1. ����(selection) ����     ***\n");
	printf("*** 2. ����(insertion) ����     ***\n");
	printf("*** 3. ����(bubble) ����        ***\n");
	printf("*** 4. ��(quick) ����           ***\n");
	printf("*** 5. �պ�(merge) ����         ***\n");
	printf("*** 6. ��(heap) ����            ***\n");
	printf("*** 7. ����(quit) ����          ***\n");

	//* ���
	for (int i = 0; i < 35; i++) printf("*");
	printf("\n");

}

// ���� ����
void selection(int arr[]) {
	int min;
	int temp;

	for (int i = 0; i < 25; i++) {
		min = i;
		
		//    ���ĵ��� ���� ����            ���� ������ ����   min�� ����
		for (int j = i + 1; j < 25; j++) if (arr[min] > arr[j]) min = j;

		// i��° ���� ���� ������ ��ȯ
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;

	}
}

// ���� ����
void insertion(int arr[25]) {

}

// ���� ����
void bubble(int arr[25]) {

}

// �� ����
void quick(int arr[25]) {

}

// �պ� ����
void merge(int arr[25]) {

}

// �� ����
void heap(int arr[25]) {

}

void array_print(int number) {
	
}

//�����Լ� ����
int main() {

	//�Է¹޴� ���� �ޱ�
	int number;

	//���� �����ϱ�
	int arr[25];

	//���� ���� �� �迭�� ����
	srand((unsigned)time(NULL));
	for (int i = 0; i < 25; i++) arr[i] = 1 + rand() % 100;

	// ���� ���� ���
	print_array();

	{ // ��ȣ �Է� �ޱ�
		printf("��ȣ �Է� : ");
		scanf("%d", &number);
	}

	{ // switch���� �̿��� ���� ����
		switch (number) {
			default :
				printf("<��ȣ ����>");
				break;
			case 1:
				selection(arr);
				break;
			case 2:
				insertion(arr);
				break;
			case 3:
				bubble(arr);
				break;
			case 4:
				quick(arr);
				break;
			case 5:
				merge(arr);
				break;
			case 6:
				heap(arr);
				break;
			case 7:
				printf("<����>");
				exit(0);


		}

	}

	{// ����� ���
		printf("%d\n", number);

		for (int i = 0; i < 25; i++) printf("%d ", arr[i]);
	}
}

