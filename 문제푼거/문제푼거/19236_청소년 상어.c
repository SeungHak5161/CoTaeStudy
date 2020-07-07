#include<stdio.h>
int fishArray[4][4];
int directionArray[4][4];

/*
fishArray에서 상어는 -1, 빈곳은 0으로 설정
directionArray에서 12시방향 1, 반시계방향 45도 회전마다 1씩 증가
*/

typedef struct xy {
	int x;
	int y;
}xy;

//물고기는 번호가 작은 물고기부터 이동함
xy findOrder(int preOrder) {
	int i = 0, j = 0;
	xy p;
	int min = 17;
	while (j < 4) {
		while (i < 4) {
			if (min > fishArray[i][j] && fishArray[i][j] >= 1 && preOrder < fishArray[i][j]) {
				min = fishArray[i][j];	p.x = i;	p.y = j;
			}
		}
	}
	return p;
}

 // direction에 따른 이동
void moveFish() {
	xy p;
	int temp[1][1];
	int cnt, d, preOrder = 0;

	while (cnt < 16) {
		p = findOrder(fishArray, preOrder);
		d = directionArray[p.x][p.y];
		preOrder = fishArray[p.x][p.y];

		switch (d) {
		case 1:
			if (p.y == 0 || fishArray[p.x][p.y - 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x][p.y - 1];
				fishArray[p.x][p.y - 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 2:
			if (p.x == 0 || p.y == 0 || fishArray[p.x - 1][p.y - 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x - 1][p.y - 1];
				fishArray[p.x - 1][p.y - 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 3:
			if (p.x == 0 || fishArray[p.x - 1][p.y] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x - 1][p.y];
				fishArray[p.x - 1][p.y] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 4:
			if (p.x == 0 || p.y == 3 || fishArray[p.x - 1][p.y + 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x - 1][p.y + 1];
				fishArray[p.x - 1][p.y + 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 5:
			if (p.y == 3 || fishArray[p.x][p.y + 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x][p.y + 1];
				fishArray[p.x][p.y + 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 6:
			if (p.x == 3 || p.y == 3 || fishArray[p.x + 1][p.y + 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x + 1][p.y + 1];
				fishArray[p.x + 1][p.y + 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 7:
			if (p.x == 3 || fishArray[p.x + 1][p.y] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x + 1][p.y];
				fishArray[p.x + 1][p.y] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		case 8:
			if (p.x == 3 || p.y == 0 || fishArray[p.x + 1][p.y - 1] <= 0) {
				directionArray[p.x][p.y]++;
				moveFish();
			}
			else {
				temp[1][1] = fishArray[p.x + 1][p.y - 1];
				fishArray[p.x + 1][p.y - 1] = fishArray[p.x][p.y];
				fishArray[p.x][p.y] = temp[1][1];
			}
			break;
		}
		cnt++;
	}
}


int moveShark(xy shark) {
	int exp;
	int d = directionArray[shark.x][shark.y];
	
	
}

int main() {
	int i=0, j=0;
	//상어가 먹은 물고기들의 번호 합
	int exp;
	//입력받기
	while (j < 4) {
		while (i < 4) {
			scanf("%d", fishArray[i][j]);
			scanf("%d", directionArray[i][j]);
			i++;
		}
		i = 0;
		j++;
	}
	// 0,0에서 시작
	exp += fishArray[0][0];
	fishArray[0][0] = -1;
	moveFish();
}