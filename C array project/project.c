#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main() {
	int temp;
	int arr[10], b;
	for (int i = 0; i < 10; i++) scanf("%d", &arr[i]);
	scanf("%d", &b);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("%d", arr[b]);

}