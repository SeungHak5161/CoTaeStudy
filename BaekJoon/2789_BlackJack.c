//���õǰ� Ǯ�ٰ� ���ļ� ������ Ǯ����

#pragma warning(disable : 4996)
#include <stdio.h>

int Compare(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void main() {
	int n, m, b, i, j, k, p;
	int input[5];
	int o = 0;
	int sum[98][98][98];

	printf("n���� ī��� ī���� �� m�� ������� �Է����ּ���.\n(3 �� N �� 100), M(10 �� M �� 300,000)");
	scanf("%d %d", &n, &m);
	printf("n���� ī�� ������ ���ڸ� �����ּ���.\n");
	for (b = 0; b < n; b++) {
		scanf("%d", &input[b]);
	}

	int t = sizeof(input) / sizeof(int);
	int high = 0;

	for (i = 0; i < t; i++) {
		for (j = 0; j < t; j++) {
			for (k = 0; k < t; k++) {
				if (input[i] + input[j] + input[k] < m) {
					sum[i][j][k] = input[i] + input[j] + input[k];
					high = Compare(high, sum[i][j][k]);
				}
				else
					break;
			}
		}
	}
	printf("\n%d %d�� ���� �����մϴ�.", high, m);
}

/*
#pragma warning(disable : 4996)
#include <stdio.h>

int* a=NULL;

int AbsValue(int a) {
	if (a < 0)
		a *= -1;
	return a;
}

int Compare(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}

int* Save(int i, int j, int k, int sum, int o, int out, int m) {
	int save[3];
	int diff[] = { NULL };
	diff[o] = m - sum;

	if (Compare(out, AbsValue(diff[o])) == AbsValue(diff[o])) {
		save[0] = i;
		save[1] = j;
		save[2] = k;
	}
	return save;
}

void BlackJack() {
	int n, m, b, i, j, k, p;
	int input[] = { NULL };
	int o = 0;
	int sum[98][98][98];

	printf("n���� ī��� ī���� �� m�� ������� �Է����ּ���.\n(3 �� N �� 100), M(10 �� M �� 300,000)");
	scanf("%d %d", &n, &m);
	printf("n���� ī�� ������ ���ڸ� �����ּ���.\n");
	for (b = 0; b < n; b++) {
		scanf("%d", &input[b]);
	}

	int t = sizeof(input);
	int out = m;

	for (i = 0; i < t; i++) {
		for (j = 0; j < t; j++) {
			for (k = 0; k < t; k++) {
				if (input[i] + input[j] + input[k] == m) {
					printf("d,%d,%d�� ���� %d�Դϴ�.", i, j, k, m);
					break;
				}
				else if (input[i] + input[j] + input[k] < m) {
					sum[i][j][k] = input[i] + input[j] + input[k];
					o += o;
					a = Save(i, j, k, sum[i][j][k], o, out, m);
				}
				else
					break;
			}
		}
	}
	printf("\n%d,%d,%d�϶� %d�� %d�� ���� �����մϴ�.", a[0], a[1], a[2], a[0] + a[1] + a[2], m);
}

void main() {
	BlackJack();
}*/