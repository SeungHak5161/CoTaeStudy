#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>

void main() {
	char buffer[100];
	int count = 0;
	int length;

	for (int i = 0; i < 100; i++) {
		buffer[i] = NULL;
	}

	scanf("%s", &buffer);

	for (int i = 0; i < 100; i++) {
		switch (buffer[i]) {
			case 'c': {
				if (buffer[i + 1] == '=' || buffer[i + 1] == '-') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			case 'd': {
				if (buffer[i + 1] == 'z' && buffer[i + 2] == '=') {
					count++;
					i += 2;
					break;
				}
				else if (buffer[i + 1] == '-') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			case 'l': {
				if (buffer[i + 1] == 'j') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			case 'n': {
				if (buffer[i + 1] == 'j') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			case 's': {
				if (buffer[i + 1] == '=') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			case 'z': {
				if (buffer[i + 1] == '=') {
					count++;
					i++;
					break;
				}
				else
					count++;
				break;
			}
			default :
				if (buffer[i] != NULL)
					count++;
		}
	}
	printf("%d", count);
	getchar();
}