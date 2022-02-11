#include <stdio.h>

int b[31][31];

//[n][r]=[n-1][r]+[n-1][r-1]
int bridge(int n,int r) {
	if (n == r || r == 0)
		return 1;
	if (b[n][r])
		return b[n][r]; //dp
	else {
		b[n][r] = bridge(n - 1, r) + bridge(n - 1, r - 1);
		return b[n][r];
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	int *l = (int*)malloc(tc * sizeof(int));
	int *r = (int*)malloc(tc * sizeof(int));
	for (int i = 0; i < tc; i++)
		scanf("%d %d",&l[i],&r[i]);

	for (int i = 0; i < tc; i++) {
		int left = l[i];
		int right = r[i];
		int r = bridge(right, left);
		printf("%d\n", r);
	}
}
//int main() {
//	int a, b, count=0;
//	for (int i = 1; i <= 30; i++) {
//		for (int j = 1; j <= 30; j++) {
//			if (j >= i) {
//				printf("%d %d\n", i, j);
//				count++;
//			}
//		}
//	}
//		printf("%d", count);
//}