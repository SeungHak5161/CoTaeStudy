#include <stdio.h>

int count(int c, int n)
{
	if (n == 1)
		c++;

	else
	{
		c=count(c, n - 1);
		c++;
		c=count(c, n - 1);
	}
	return c;
}

void hanoi(int n, int start, int work, int target)
{
	if (n == 1)
		printf("%c %c\n", start, target);

	else
	{
		hanoi(n - 1, start, target, work);
		printf("%c %c\n", start, target);
		hanoi(n - 1, work, start, target);
	}
}

int main() {
	int c = 0;
	int num;
	scanf("%d", &num);

	c=count(c, num);
	printf("%d\n", c);
	hanoi(num, '1', '2', '3');
}