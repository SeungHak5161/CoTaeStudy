#include<stdio.h>
int fishArray[4][4];
int liveFish = 16;
int maxExp = 0;
int preOrder = 0;
int cnt = 0;
int dirX[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dirY[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

typedef struct fish {
	int x;
	int y;
	int num;
	int dir;
	int isLive; //살면 1, 죽으면 0
}Fish;

Fish fish[16];

/*
fishArray에서 상어는 -1, 빈곳은 0으로 설정
directionArray에서 12시방향 1, 반시계방향 45도 회전마다 1씩 증가
*/

void print() {
	int num, flag = 0;
	printf("\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				for (int p = 0; p < 4; p++) {
					if (fish[4 * k + p].x == j) {
						if (fish[4 * k + p].y == i) {
							num = 4 * k + p;
							flag = 1;
							break;
						}
					}
				}
				if (flag == 1) break;
			}
			flag = 0;
			printf("%2d %2d | ", fishArray[j][i], fish[num].dir);
		}
		printf("\n");
	}
	printf("\n");
}

void copyState(int copyArray[][4], int fishArray[][4], Fish copyFish[], Fish fish[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copyArray[i][j] = fishArray[i][j];
		}
	}
	for (int i = 1; i < 16; i++) copyFish[i] = fish[i];
}

void resetState(int copyArray[][4], int fishArray[][4], Fish copyFish[], Fish fish[]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fishArray[i][j] = copyArray[i][j];
		}
	}
	for (int i = 1; i < 16; i++) fish[i] = copyFish[i];
}

void swapFish(int x, int y, int nx, int ny, int fishNum) {
	int swapNum, flag = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			if (fish[4 * i + j].x == nx)
				if (fish[4 * i + j].y == ny) {
					swapNum = 4 * i + j;
					flag = 1;
					break;
				}
		if (flag == 1) break;
	}
	fish[swapNum].x = x;
	fish[swapNum].y = y;
	fishArray[x][y] = fishArray[nx][ny];
	fish[fishNum].x = nx;
	fish[fishNum].y = ny;
	fishArray[nx][ny] = fish[fishNum].num;
}

//물고기는 번호가 작은 물고기부터 이동함
int findOrder(int preOrder) {
	int order = 17;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (fishArray[j][i] > preOrder) {
				if (fishArray[j][i] < order)	order = fishArray[j][i];
			}
		}
	}
	return order;
}

 // direction에 따른 이동
void moveFish() {
	int order, nx, ny, fishNum;
	while (cnt < liveFish) {
		order = findOrder(preOrder);
		for (int i = 0; i < 16; i++)
			if (fish[i].num == order) {
				fishNum = i;
				break;
			}
		nx = fish[fishNum].x + dirX[fish[fishNum].dir];
		ny = fish[fishNum].y + dirY[fish[fishNum].dir];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && fishArray[nx][ny] != -1) {
			swapFish(fish[fishNum].x, fish[fishNum].y, nx, ny, fishNum);
			preOrder = order;
			cnt++;
		}
		else {
			fish[fishNum].dir += 1;
			if (fish[fishNum].dir > 8)	fish[fishNum].dir -= 8;
			moveFish();
		}
	}
	preOrder = 0;
}

void eat(int x, int y, int nx, int ny) {
	int fishNum = fishArray[nx][ny];
	for (int i = 0; i < liveFish; i++)
		if (fishNum == fish[i].num) {
			fishNum = i;
			break;
		}
	fishArray[x][y] = 0;
	fishArray[nx][ny] = -1;
	fish[fishNum].isLive = 0;
	liveFish--;
}

void vomit(int x, int y, int nx, int ny) {
	int fishNum = fishArray[nx][ny];
	for (int i = 0; i < liveFish; i++)
		if (fishNum == fish[i].num) {
			fishNum = i;
			break;
		}
	fishArray[x][y] = -1;
	fishArray[nx][ny] = fish[fishNum].num;
	fish[fishNum].isLive = 1;
	liveFish++;
}

void DFS(int x, int y, int dir, int exp) {
	int copyArray[4][4];
	Fish copyFish[16];

	if (maxExp < exp) maxExp = exp;

	copyState(copyFish, fishArray, fish, copyFish);
	moveFish();
	print();
	cnt = 0;
	for (int i = 1; i <= 3; i++) {
		int nx = x + dirX[dir]*i;
		int ny = y + dirY[dir]*i;
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			if (fishArray[nx][ny] == 0) continue;
				exp += fishArray[nx][ny];
				eat(x, y, nx, ny);
				print();
				for (int i = 0; i < 4; i++)
					for (int j = 0; j < 4; j++)
						if (fish[4 * i + j].x == nx)
							if (fish[4 * i + j].y == ny)
								dir = fish[4 * i + j].dir;
				DFS(nx, ny, dir, exp);
				vomit(x, y, nx, ny);
				exp -= fishArray[nx][ny];
				print();
		}
		else break;
	}
	resetState(copyFish, fishArray, fish, copyFish);
	print();
}

void solve() {
	// 0,0에서 시작
	fish[0].isLive = 0;
	fishArray[0][0] = -1;
	liveFish--;
	print();
	DFS(0, 0, fish[0].dir, fish[0].num);
}

//각 fish[]에 정보 입력
void numbering() {
	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			fishArray[j][i] = fish[k].num;
			fish[k].x = j;
			fish[k].y = i;
			fish[k].isLive = 1;
			k++;
		}
	}
}

int main() {
	int k=0, xy, dir;
	//입력받기
	for (int i = 0; i < 4; i++)	scanf("%d %d %d %d %d %d %d %d", &fish[4 * i].num, &fish[4 * i].dir, 
																 &fish[4 * i + 1].num, &fish[4 * i + 1].dir,
																 &fish[4 * i + 2].num, &fish[4 * i + 2].dir,
																 &fish[4 * i + 3].num, &fish[4 * i + 3].dir);
	numbering();
	print();
	solve();
	printf("%d", maxExp);
	getch();
}