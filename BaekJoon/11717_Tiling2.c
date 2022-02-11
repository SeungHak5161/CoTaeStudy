#include <stdio.h>

int main() {
	int n;
	int tmp = 0;
	int last = 1;
	int cur = 3;
	scanf("%d", &n);
	if (n == 1)
		printf("1");
	else if (n == 2)
		printf("3");
	else {
		for (int i = 0; i < n - 2; i++) {
			tmp = (cur + 2 * last) % 10007;
			last = cur;
			cur = tmp;
		}
		printf("%d", tmp);
	}
}