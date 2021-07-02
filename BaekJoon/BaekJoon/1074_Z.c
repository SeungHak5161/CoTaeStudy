#include <stdio.h>
#include <math.h>

int algo(int N, int r, int c) {
	int num = 0;
	int n = pow(2, N) / 2;
	do {
		if (r > pow(2, N) / 2) {
			num += pow(4, N - 1) * 2;
			r -= (pow(2, N) / 2);
		}
		if (c > pow(2, N) / 2) {
			num += pow(4, N - 1);
			c -= (pow(2, N) / 2);
		}
		N--;
	} while (r + c > 4);

	if (r == 1 && c == 1)
		return num;
	else if (r == 1 && c == 2)
		return num + 1;
	else if (r == 2 && c == 1)
		return num + 2;
	else if (r == 2 && c == 2)
		return num + 3;
}

void main() {
		int N, r, c;
		scanf("%d %d %d", &N, &r, &c);
		int num = algo(N, r + 1, c + 1);
		printf("%d", num);
}

//현정
/*
#include <stdio.h>

#include <math.h>

int N, r, c;



int main() {

   scanf_s("%d %d %d", &N, &r, &c);

   int range = (int)pow(2, N - 1);

   int a = r, b = c;

   int res = 0;

   for (int i = N; i > 0; --i) {

	  int x, y;

	  x = a / range;

	  y = b / range;

	  //printf("x : %d, y : %d\n", x, y);

	  if (x == 0 && y == 0) {

		 res += 0;

	  }

	  else if (x == 0 && y == 1) {

		 res += (range*range) * 1;

	  }

	  else if (x == 1 && y == 0) {

		 res += (range*range) * 2;

	  }

	  else if (x == 1 && y == 1) {

		 res += (range*range) * 3;

	  }

	  a %= range;

	  b %= range;

	  range /= 2;

   }

   printf("%d", res);

}*/

//현성
/*
#include <stdio.h>
#include <math.h>
int find(int N, int* r, int* c);
int main() {
	int N, r, c, count = 0;
	scanf("%d %d %d", &N, &r, &c);
	for(int i = N; i > 0; i--){
		count += find(i, &r, &c);
	}
	printf("%d\n", count);
}
int find(int N, int* r, int* c) {
	if (*r < pow(2, N) / 2) {
		if (*c < pow(2, N) / 2) {
			return 0;
		}
		else {
			*c -= pow(2, N) / 2;
			return pow(4, N-1);
		}
	}
	else {
		if (*c < pow(2, N) / 2) {
			*r -= pow(2, N) / 2;
			return pow(4, N - 1)*2;
		}
		else {
			*r -= pow(2, N) / 2;
			*c -= pow(2, N) / 2;
			return pow(4, N - 1)*3;
		}
	}
}
*/