#pragma warning(disable : 4996)
#include <stdio.h>

//M행N열의 status배열 안에 얼마나 수정할 값이 몇개인지 출력하는 함수
int number(int N, int M, char substitute[]) {
	int count = 0;
	if (substitute[0] == 'B') {
		for (int i = 0; i < 64; i++) {
			if ((i / 8) % 2 == 0) { //배열이 8열이기 때문에 8로 나누면 첫행부터 0,1,2,~이고 그 값을 2로 나눈 나머지로 홀수행인지 짝수행인지 판별가능
				if (i % 2 == 0) { // 짝수열일 때
					if (substitute[i] == 'W')
						count++;
				}
				else if (i % 2 == 1) {
					if (substitute[i] == 'B')
						count++;
				}
			}
			else {
				if (i % 2 == 0) {
					if (substitute[i] == 'B')
						count++;
				}
				else if (i % 2 == 1) {
					if (substitute[i] == 'W')
						count++;
				}
			}
		}
		return count;
	}
	else {
		for (int i = 0; i < 64; i++) {
			if ((i / 8) % 2 == 0) {
				if (i % 2 == 0) {
					if (substitute[i] == 'B')
						count++;
				}
				else if (i % 2 == 1) {
					if (substitute[i] == 'W')
						count++;
				}
			}
			else {
				if (i % 2 == 0) {
					if (substitute[i] == 'W')
						count++;
				}
				else if (i % 2 == 1) {
					if (substitute[i] == 'B')
						count++;
				}
			}
		}
		return count;
	}
}

int main() {
	int a = 0;
	int column = 0; // column, row는 8행8열의 배열이 이동하며 변화한 값을 저장하기 위한 변수
	int row = 0;
	int N, M, count;
	int result = 2500;
	char status[1000000];
	char substitute[64];
	scanf("%d %d %s", &N, &M, &status);

	for (int n = 0; n < N - 8 + 1; n++) {// n, m은 N행 M열의 배열에서 배열이 이동하는 횟수만큼 값을 저장하기 위한 변수
		for (int m = 0; m < M - 8 + 1; m++) {
			for (int i = 0; i < 8; i++)	// i, j는 8행8열의 배열을 저장하기 위한 변수
				for (int j = 0; j < 8; j++)
					substitute[j + 8 * i] = status[j + M * i + column + M * row];
			column++;
			count = number(N, M, substitute);
			a++;
			printf("%d : %d\n", a, count);
			if (count < result)
				result = count;
		}
		row++;
	}
	printf("최소값 : %d", result);
	getchar();
}