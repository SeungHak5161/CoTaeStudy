#include <stdio.h>
#include <string.h>

void main() {
	char num[10]; //1,000,000,000 이하 자연수
	//scanf("%c", &num);
	gets(num);
	int length = strlen(num),temp;

	for (int i = 0; i < length; i++) {
		for (int j = 1; j < length - 1; j++) {
			if (num[i] < num[j]) {
				temp = num[j];
				num[j] = num[i];
				num[i] = temp;
			}
		}
	}
	//for (int i = 0; i < length; i++)
	//	printf("%c", num[i]);
	puts(num);
}
