#define _CRT_SECURE_NO_WARNINGS

//�⺻���� ����� ���̺귯��
#include <stdio.h>

// ���� ������ ���� ���̺귯��
#include <stdlib.h>
#include <time.h>

// â ũ�� ������ ���� ���̺귯��
#include <Windows.h>

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
	// switch�� Ȱ��
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
	int temp, key, j;

	// arr[0]���� ������ �ʿ� ����
	for (int i = 1; i < 25; i++) {

		key = arr[i]; // ���� ���Ե� ������ i��° ������ key ������ ����

		for (j = i - 1; j >= 0 && arr[j] > key; j--) { // key�� �� ū ���� ������ 
			arr[j + 1] = arr[j]; // �� ĭ �ڷ� �̵� 
		}

		arr[j + 1] = key; // �˸��� ��ġ�� key ���� 

	}
}



// ���� ����
void bubble(int arr[25]) {
	int temp;
	// 25�� �ݺ�
	for (int i = 0; i < 25 - 1; i++)
	{
		// 25 - 1(ó����) - i(�̹� �Ѱ�)��ŭ �ݺ�
		for (int j = 0; j < 24 - i; j++)
		{
			// arr[j]�� arr[j+1]���� ū��?
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
void merge(int arr[25], int low, int mid, int high)
{
	int b[100] = { 0 };
	int k = 0;
	int i = low, j = mid + 1;

	while (i <= mid && j <= high) {
		if (arr[i] <= arr[j])
		{
			b[k++] = arr[i];
			i++;
		}
		else {
			b[k++] = arr[j];
			j++;
		}
	}
	while (i <= mid) {
		b[k++] = arr[i++];
	}
	while (j <= high) {
		b[k++] = arr[j++];
	}
	int p = low;
	for (int l = 0; l < k; l++) {
		arr[p++] = b[l];
	}
}
void mergesort(int arr[], int low, int high)
{
	if (high <= low)
		return;
	int mid;
	mid = (low + (high - low) / 2);

	mergesort(arr, low, mid);
	mergesort(arr, mid + 1, high);
	merge(arr, low, mid, high);
}

// �� ����
void heap(int arr[25]) {
	int x, root, t;
	for (int i = 0; i < 25; i++) {
		x = i;
		do {
			root = (x - 1) / 2;
			if (arr[root] < arr[x]) {
				t = arr[root];
				arr[root] = arr[x];
				arr[x] = t;
			}
			x = root;
		} while (x != 0);
	}

	for (int j = 24; j >= 0; j--) {
		t = arr[0];
		arr[0] = arr[j];
		arr[j] = t;
		root = 0;
		do {
			x = 2 * root + 1;
			if ((arr[x] < arr[x + 1]) && x < j - 1)
				x++;
			if (arr[root] < arr[x] && x < j) {
				t = arr[root];
				arr[root] = arr[x];
				arr[x] = t;
			}
			root = x;
		} while (x < j);
	}
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
		mergesort(arr, 0, 24);
		break;
	case 6:
		heap(arr);
		break;
	}
}

//�����Լ� ����
int main() {
	//�Է¹޴� ���� ���� ���� ����
	int number;

	// ������ ���� ������ �迭 arr ����
	int arr[25];

	// ���� ���� ���
	print_array();

	{ // ��ȣ �Է� �ޱ�
		do {

			//���� ���� �� �迭�� ����
			srand((unsigned)time(NULL));
			for (int i = 0; i < 25; i++) arr[i] = 1 + rand() % 100;

			printf("��ȣ �Է�\n"); scanf("%d", &number);

			// �Է¹��� ���ڰ� 7�϶�, �����ϱ�
			if (number == 7) break;

			// ������ ���� ���
			selected_array(number);

			// �����ϱ� �� �迭 ���
			for (int i = 0; i < 25; i++) printf("%d ", arr[i]); printf("\n");

			// �����ϱ�
			start_array(number, arr);

			// ������ �� �迭 ���
			for (int i = 0; i < 25; i++) printf("%d ", arr[i]); printf("\n");

		} while (number != 7);
	}

	printf("<����>");


}

