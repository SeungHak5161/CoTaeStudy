//getchar에 while로 배열에 값 받다가 \n입력되면 반복문 종료하고 배열로 비교하면 더 깔끔할듯.
//210입력하면 105나와야되는데 104나옴. 거의맞으니까 귀찮은데 패스ㅎ

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
	printf("1000이하의 자연수를 입력하세요\n");
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
	printf("1000이하의 자연수를 입력하세요");
	scanf("%d", &input);

	for (int i = 1; i < input; i++) {
		ret=length(i);
		if (ret == 1)
			count++;
	}
	printf("%d보다 작거나 같은 한수의 개수는 %d개 입니다",input, count);
}
*/