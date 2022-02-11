#include <stdio.h>
void main() {
	int arr[3];
	int temp, index;

	for (int i = 0; i < 3; i++)
		scanf("%d", &arr[i]);

	for (int j = 0; j < 3; j++) {
		temp = arr[j];
		for (int k = j; k < 3-j; k++) {
			if (arr[k] < temp) {
				temp = arr[k];
				index = k;
			}
		}
		if (temp != arr[j]) {
			arr[index] = arr[j];
			arr[j] = temp;
		}
	}

	for (int p = 0; p < 3; p++)
		printf("%d", arr[p]);
} 