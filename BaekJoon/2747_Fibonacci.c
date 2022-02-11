#include <stdio.h>

int arr[1000];

int fibo(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (arr[n] != 0)
		return arr[n];
	else
		return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int n;
	scanf("%d", &n);
	n = fibo(n);
	printf("%d", n);
}

/*
int main() {
	int n,tmp;
	int cur = 1;
	int last = 0;
	scanf("%d", &n);
	if (n == 0)
		printf("0");
	else if (n == 1)
		printf("1");
	else {
		for (int i = 0; i < n - 1; i++) {
			tmp = cur + last;
			last = cur;
			cur = tmp;
		}
		printf("%d", tmp);
	}
}
*/