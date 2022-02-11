#include <stdio.h>
#include <string.h>

void main() {
	char num[10]; //1,000,000,000 이하 자연수
	gets(num);
	int temp, length = strlen(num);

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (num[i] > num[j]) {
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
	puts(num);
}
