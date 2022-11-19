#define _CRT_SECURE_NO_WARNINGS

//기본적인 입출력 라이브러리
#include <stdio.h>

// 난수 생성을 위한 라이브러리 불러오기
#include <stdlib.h>
#include <time.h>

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
void insertion(int arr[25]) {

}

// 버블 정렬
void bubble(int arr[25]) {

}

// 퀵 정렬
void quick(int arr[25]) {

}

// 합병 정렬
void merge(int arr[25]) {

}

// 힙 정렬
void heap(int arr[25]) {

}

void array_print(int number) {
	
}

//메인함수 시작
int main() {

	//입력받는 숫자 받기
	int number;

	//난수 생성하기
	int arr[25];

	//난수 생성 및 배열에 저장
	srand((unsigned)time(NULL));
	for (int i = 0; i < 25; i++) arr[i] = 1 + rand() % 100;

	// 정렬 종류 출력
	print_array();

	{ // 번호 입력 받기
		printf("번호 입력 : ");
		scanf("%d", &number);
	}

	{ // switch문을 이용한 정렬 실행
		switch (number) {
			default :
				printf("<번호 오류>");
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
				printf("<종료>");
				exit(0);


		}

	}

	{// 결과값 출력
		printf("%d\n", number);

		for (int i = 0; i < 25; i++) printf("%d ", arr[i]);
	}
}

