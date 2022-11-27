#define _CRT_SECURE_NO_WARNINGS

//기본적인 입출력 라이브러리
#include <stdio.h>

// 난수 생성을 위한 라이브러리
#include <stdlib.h>
#include <time.h>

// 창 크기 조절을 위한 라이브러리
#include <Windows.h>

// 정렬 종류 출력
void print_array() {

	//* 출력
	for (int i = 0; i < 35; i++) printf("*");
	printf("\n");

	//정렬 구분 및 번호 안내
	printf("*** 여러가지 정렬 프로그램 구현 ***\n");
	printf("***                             ***\n");
	printf("*** 1. 선택(selection) 정렬     ***\n");
	printf("*** 2. 삽입(insertion) 정렬     ***\n");
	printf("*** 3. 버블(bubble) 정렬        ***\n");
	printf("*** 4. 퀵(quick) 정렬           ***\n");
	printf("*** 5. 합병(merge) 정렬         ***\n");
	printf("*** 6. 힙(heap) 정렬            ***\n");
	printf("*** 7. 종료(quit) 정렬          ***\n");

	//* 출력
	for (int i = 0; i < 35; i++) printf("*");
	printf("\n");
}

// 선택한 정렬 출력
void selected_array(int number) {
	// switch문 활용
	switch (number) {
		case 1:
			printf("<선택 정렬>\n");
			break;
		case 2:
			printf("<삽입 정렬>\n");
			break;
		case 3:
			printf("<버블 정렬>\n");
			break;
		case 4:
			printf("<퀵 정렬>\n");
			break;
		case 5:
			printf("<합병 정렬>\n");
			break;
		case 6:
			printf("<힙 정렬>\n");
			break;
	}
}

// 선택 정렬
void selection(int arr[]) {
	int min;
	int temp;

	for (int i = 0; i < 25; i++) {
		min = i;
		
		//    정렬되지 않은 값중            가장 작은값 선택   min에 저장
		for (int j = i + 1; j < 25; j++) if (arr[min] > arr[j]) min = j;

		// i번째 값과 가장 작은값 교환
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

// 삽입 정렬
void insertion(int arr[]) {
	int temp, key, j;

	// arr[0]값은 정렬할 필요 없음
	for (int i = 1; i < 25; i++) {

		key = arr[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사

		for (j = i - 1; j >= 0 && arr[j] > key; j--) { // key가 더 큰 값일 때까지 
			arr[j + 1] = arr[j]; // 한 칸 뒤로 이동 
		}

		arr[j + 1] = key; // 알맞은 위치에 key 삽입 

	}
}



// 버블 정렬
void bubble(int arr[25]) {
	int temp;
	// 25번 반복
	for (int i = 0; i < 25 - 1; i++)
	{
		// 25 - 1(처음거) - i(이미 한거)만큼 반복
		for (int j = 0; j < 24 - i; j++)
		{
			// arr[j]가 arr[j+1]보다 큰가?
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 퀵 정렬
void quick(int arr[25], int L, int R) {
	int left = L, right = R;
	int center = arr[(L + R) / 2];    // center 설정 (가운데) 
	int temp;
	// 반복해라
	do
	{
		while (arr[left] < center)    // left가 center보다 큰 값을 만남 || center 만날 때까지 
			left++;
		while (arr[right] > center)    // right가 center보다 작은 값을 만남 || center 만날 때까지 
			right--;
		if (left <= right)    // left가 right보다 왼쪽에 있는가?
		{
			// arr[left], arr[right] 교환
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			/*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
			left++;
			right--;
		}
	} while (left <= right);    // left가 right 보다 오른쪽에 있을 때까지

  /* recursion */
	if (L < right)
		quick(arr, L, right);    // 왼쪽 배열 반복 

	if (left < R)
		quick(arr, left, R);    // 오른쪽 배열 반복 
}


// 합병 정렬
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

// 힙 정렬
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

// switch문을 이용한 정렬 실행
void start_array(int number, int arr[]) {
	switch (number) {
	default:
		printf("<번호 오류>\n");
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

//메인함수 시작
int main() {
	//입력받는 숫자 받을 변수 생성
	int number;

	// 생성된 난수 저장할 배열 arr 생성
	int arr[25];

	// 정렬 종류 출력
	print_array();

	{ // 번호 입력 받기
		do {

			//난수 생성 및 배열에 저장
			srand((unsigned)time(NULL));
			for (int i = 0; i < 25; i++) arr[i] = 1 + rand() % 100;

			printf("번호 입력\n"); scanf("%d", &number);

			// 입력받은 숫자가 7일때, 종료하기
			if (number == 7) break;

			// 선택한 정렬 출력
			selected_array(number);

			// 정렬하기 전 배열 출력
			for (int i = 0; i < 25; i++) printf("%d ", arr[i]); printf("\n");

			// 정렬하기
			start_array(number, arr);

			// 정렬한 후 배열 출력
			for (int i = 0; i < 25; i++) printf("%d ", arr[i]); printf("\n");

		} while (number != 7);
	}

	printf("<종료>");


}

