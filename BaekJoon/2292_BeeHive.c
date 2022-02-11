#include <stdio.h>

int main() {
	int n;
	int i = 0;
	scanf("%d", &n);
	if (n == 1)
		printf("1");
	else {
		while (n-1 > 0) {
			n -= 6 * i;
			i++;
		}
		printf("%d", i);
	}
}