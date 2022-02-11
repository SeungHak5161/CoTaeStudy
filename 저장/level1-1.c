#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(char phone_number[]) {
	
	int len = strlen(phone_number);
	char* answer = (char*)malloc(len*sizeof(char));

	for (int i = 0; i < len - 4; i++)	answer[i] = "*";
	return answer;
}

int main() {
	/*int size = 0;
	scanf("%d", &size);
	char* test = (char*)malloc(size * sizeof(char));
	for (int i = 0; i < size; i++)	scanf(" %c", &test[i]);*/
	int size = 6;
	char test[6] = { '0', '1', '2', '3', '4', '5' };
	char* answer = (char*)malloc(size * sizeof(char)); 
	for(int i = 0; i < size ; i++)	printf("%c", test[i]);
	answer=solution(test);
	for (int i = 0; i < size; i++)	printf("%c", answer[i]);
}