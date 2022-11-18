//기본적인 입출력 라이브러리
#include <stdio.h>

// 난수 생성을 위한 라이브러리 불러오기
#include <time.h>
#include <stdlib.h>

//메인함수 시작
int main() {

	//입력받는 숫자 받기
	int number;

	//난수 생성하기



	{ // 소스코드 동작 시작

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

	{ // 번호 입력 받기
		printf("번호 입력 : ");
		scanf("%d", &number);
	}

	{ // switch문을 이용한 정렬 실행
		switch (number) {

		}

	}
}