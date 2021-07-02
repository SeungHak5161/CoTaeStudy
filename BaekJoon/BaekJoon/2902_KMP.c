#pragma warning(disable : 4996)
#include<stdio.h>

int main() {
	char input[100];
	char output[100];
	scanf("%s", &input);
	for (int i = 0; i < 100; i++) {
		output[i] = NULL;
	}

	for (int i = 1; i < 100; i++) {
		if (input[i] == '-')
			output[i] = input[i+1];
	}
	printf("%c", input[0]);
	for (int i = 0; i < 100; i++) {
		if(output[i]!=NULL)
			printf("%c", output[i]);
	}

}