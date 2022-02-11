#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>

//M��N���� status�迭 �ȿ� �󸶳� ������ ���� ����� ����ϴ� �Լ�
int number(int N, int M, char substitute[]) {
	int count = 0;
	if (substitute[0] == 'B') {
		for (int i = 0; i < 64; i++) {
			if ((i / 8) % 2 == 0) { //�迭�� 8���̱� ������ 8�� ������ ù����� 0,1,2,~�̰� �� ���� 2�� ���� �������� Ȧ�������� ¦�������� �Ǻ�����
				if (i % 2 == 0) { // ¦������ ��
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
	int column = 0; // column, row�� 8��8���� �迭�� �̵��ϸ� ��ȭ�� ���� �����ϱ� ���� ����
	int row = 0;
	int N, M, count;
	int result = 2500;
	char status[2501];
	char substitute[64];
	int length=0;

	scanf("%d %d", &N, &M);
	scanf("%s", &status);
	char arr[50];
	for (int i = 1; i < N; i++) {
		scanf("%s", &arr);
		while (status[length] != NULL) {
			length++;
		}
		for (int k = 0; arr[k] != NULL; k++) {
			status[length + k] = arr[k];
			status[length + k + 1] = NULL;
		}
		length = 0;
	}
	

	for (int n = 0; n < N - 8 + 1; n++) {// n, m�� N�� M���� �迭���� �迭�� �̵��ϴ� Ƚ����ŭ ���� �����ϱ� ���� ����
		for (int m = 0; m < M - 8 + 1; m++) {
			for (int i = 0; i < 8; i++)	// i, j�� 8��8���� �迭�� �����ϱ� ���� ����
				for (int j = 0; j < 8; j++)
					substitute[j + 8 * i] = status[j + M * i + column + M * row];
			column++;
			count = number(N, M, substitute);
			a++;
			if (count < result)
				result = count;
		}
		row++;
	}
	printf("%d", result);
	getchar();
}