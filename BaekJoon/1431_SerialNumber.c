#include <stdio.h>

int n, m, count[10000];

void main() {

	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		count[m]++;
	}
	for (int i = 0; i < 10000; i++) {
		while (count[i] != 0) {
			printf("%d\n", i);
			count[i]--;
		}
	}
}