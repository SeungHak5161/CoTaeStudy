//getchar�� while�� �迭�� �� �޴ٰ� \n�ԷµǸ� �ݺ��� �����ϰ� �迭�� ���ϸ� �� ����ҵ�.
//210�Է��ϸ� 105���;ߵǴµ� 104����. ���Ǹ����ϱ� �������� �н���

#include <stdio.h>

int length(int input) {
	int a, b, c, d, length;
	int ret = 0;
	a = input / 1000;
	b = input % 1000 / 100;
	c = input % 100 / 10;
	d = input % 10;
	if (a == 0 && b == 0 && c == 0)
		length = 1;
	else if (a == 0 && b == 0)
		length = 2;
	else if (a == 0)
		length = 3;
	else
		length = 4;
	ret = count(a, b, c, d, length);
	if (ret == 1) {
		return 1;
	}
	else
		return 0;
}

int count(int a,int b,int c,int d,int length) {
	if (length == 1)
		return 1;
	if (length == 2) {
		return 1;
	}
	if (length == 3) {
		if (b - c == c - d)
			return 1;
		else
			return 0;
	}
	if (length == 4) {
		return 0;
	}
	else
		return 0;
}

void main() {
	int input;
	int ret = 0;
	int count = 0;
	printf("1000������ �ڿ����� �Է��ϼ���\n");
	scanf("%d", &input);

		for (int i = 1; i < input+1; i++) {
			ret = length(i);
			if (ret == 1)
				count++;
		}
		printf("%d", count);
}


/*
#include <stdio.h>

int length(int input) {
	int a, b, c, d, length;
	int ret = 0;
	a = input / 1000;
	b = input % 1000 / 100;
	c = input % 100 / 10;
	d = input % 10;
	if (a == 0 && b == 0 && c == 0)
		length = 1;
	else if (a == 0 && b == 0)
		length = 2;
	else if (a == 0)
		length = 3;
	else
		length = 4;
	ret = count(a, b, c, d, length);
	if (ret == 1) {
		return 1;
	}
	else
		return 0;
}

int count(int a,int b,int c,int d,int length) {
	if (length == 1)
		return 1;
	if (length == 2) {
		return 1;
	}
	if (length == 3) {
		if (b - c == c - d)
			return 1;
		else
			return 0;
	}
	if (length == 4) {
		return 0;
	}
	else
		return 0;
}

void main() {
	int input;
	int ret = 0;
	int count = 0;
	printf("1000������ �ڿ����� �Է��ϼ���");
	scanf("%d", &input);

	for (int i = 1; i < input; i++) {
		ret=length(i);
		if (ret == 1)
			count++;
	}
	printf("%d���� �۰ų� ���� �Ѽ��� ������ %d�� �Դϴ�",input, count);
}
*/