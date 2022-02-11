#include <stdio.h>

int arr[31] = { 0 };

int main() {
	int n;
	arr[0] = 1;
	arr[2] = 3;
	for (int i = 4; i < 31; i++) {
		if (i % 2 == 0) {
			int tmp = 0;
			for (int j = 2; i - 2 * j >= 0; j++) {
				tmp += 2 * arr[i - 2 * j];
			}
			arr[i] = arr[i - 2] * 3 + tmp;
		}
	}
	scanf("%d", &n);
	printf("%d", arr[n]);
}
