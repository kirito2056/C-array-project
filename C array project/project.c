//�⺻���� ����� ���̺귯��
#include <stdio.h>

// ���� ������ ���� ���̺귯�� �ҷ�����
#include <time.h>
#include <stdlib.h>

// ���� ����
void selection(int arr[25]) {
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


//�����Լ� ����
int main() {

	//�Է¹޴� ���� �ޱ�
	int number;

	//���� �����ϱ�
	int arr[25];




	{ // �ҽ��ڵ� ���� ����

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

	{ // ��ȣ �Է� �ޱ�
		printf("��ȣ �Է� : ");
		scanf("%d", &number);
	}

	{ // switch���� �̿��� ���� ����
		switch (number) {
			case 1:
				selection(arr);
			}

	}
}