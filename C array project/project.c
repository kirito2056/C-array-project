#define _CRT_SECURE_NO_WARNINGS

//�⺻���� ����� ���̺귯��
#include <stdio.h>

// ���� ������ ���� ���̺귯��
#include <stdlib.h>
#include <time.h>

// â ũ�� ������ ���� ���̺귯��
#include <Windows.h>

// ���� ���� ���Ƽ� �ϴ� swap �Լ�ȭ
void swap(int a, int b) {
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

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

// ������ ���� ���
void selected_array(int number) {
	switch (number) {
		case 1:
			printf("<���� ����>\n");
			break;
		case 2:
			printf("<���� ����>\n");
			break;
		case 3:
			printf("<���� ����>\n");
			break;
		case 4:
			printf("<�� ����>\n");
			break;
		case 5:
			printf("<�պ� ����>\n");
			break;
		case 6:
			printf("<�� ����>\n");
			break;
		case 7:
			printf("<����>");
	}
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
void insertion(int arr[]) {
	int temp;
	for (int i = 0; i < 25; i++) {
		for (int j = i; j > 0; j--) {
			if ( arr[j-1] > arr[j]) {
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			
			}
		}
	}
}

// ���� ����
void bubble(int arr[25]) {
	int temp;
	for (int i = 0; i < 25 - 1; i++)
	{
		for (int j = 0; j < 25 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// �� ����
void quick(int arr[25], int L, int R) {
	int left = L, right = R;
	int center = arr[(L + R) / 2];    // center ���� (���) 
	int temp;
	// �ݺ��ض�
	do
	{
		while (arr[left] < center)    // left�� center���� ū ���� ���� || center ���� ������ 
			left++;
		while (arr[right] > center)    // right�� center���� ���� ���� ���� || center ���� ������ 
			right--;
		if (left <= right)    // left�� right���� ���ʿ� �ִ°�?
		{
			// arr[left], arr[right] ��ȯ
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			/*left ���������� ��ĭ, right �������� ��ĭ �̵�*/
			left++;
			right--;
		}
	} while (left <= right);    // left�� right ���� �����ʿ� ���� ������

  /* recursion */
	if (L < right)
		quick(arr, L, right);    // ���� �迭 �ݺ� 

	if (left < R)
		quick(arr, left, R);    // ������ �迭 �ݺ� 
}


// �պ� ����
void merge(int arr[25]) {

}

// �� ����
void heap(int arr[25]) {

}

void array_print(int number) {
	
}

// switch���� �̿��� ���� ����
void start_array(int number, int arr[]) {
switch (number) {
	default:
		printf("<��ȣ ����>\n");
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
		quick(arr, 0, 24);
		break;
	case 5:
		merge(arr);
		break;
	case 6:
		heap(arr);
		break;
	case 7:
		exit(0);
	}
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

	// ������ ���� ���
	selected_array(number);

	// �����ϱ� �� �迭 ���
	for (int i = 0; i < 25; i++) printf("%d ", arr[i]);
	printf("\n");

	// �����ϱ�
	start_array(number, arr);

	// ������ �� �迭 ���
	for (int i = 0; i < 25; i++) printf("%d ", arr[i]);

}

