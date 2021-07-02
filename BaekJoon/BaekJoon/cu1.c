#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(void) {
	int n = 2458, answer = 0, val = 0, length = 0;
	char str[10000] = { 0 };
	sprintf(str, "%d", n);
	length = strlen(str);
	for (int i = 0; i < length; i++)
		val = str[i] - '0';
		//answer += val;
		printf("%d", val);
}