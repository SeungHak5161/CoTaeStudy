#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>

#define MAX 900
#define INF 987654321

using namespace std;

int c[MAX][MAX]; // capacity :: i->j로 가는 간선 용량
int f[MAX][MAX]; // flow :: i->j로 현재 흐르고 있는 유량
bool adj[MAX][MAX];

int main()
{
	int n, p;

	for (int i = 3; i <= 400; i++)
	{
		c[i][i + 400] = 1;

		adj[i][i + 400] = 1;
		adj[400 + i][i] = 1;
	}

	// 입력
	scanf("%d %d", &n, &p);
	for (int i = 0; i < p; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);

		c[from + 400][to] = 1;
		c[to + 400][from] = 1;

		adj[from + 400][to] = 1;
		adj[to][from + 400] = 1;
		adj[to + 400][from] = 1;
		adj[from][to + 400] = 1; // 역방향 간선 추가
	}


	int totalFlow = 0, S = 401, T = 2; // S :: source, T :: sink

	while (1)
	{
		int prev[MAX];
		memset(prev, -1, sizeof(prev));

		queue<int> q;
		q.push(S);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			//cout << "!!!!!!!! cur !!!!!!!!!! " << cur  << endl;
			for (int i = 1; i < MAX; i++)
			{
				if (adj[cur][i] == 0)
					continue;

				int next = i;

				//cout << "next :: " << next << endl;
				if (prev[next] != -1)
					continue;

				//cout << "c[" << cur << "][" << next << "]" << c[cur][next] << " " << "f[" << cur <<"][" << next << "]" << f[cur][next] << endl;
				if (c[cur][next] - f[cur][next] > 0)
				{
					q.push(next);

					prev[next] = cur;

					if (next == T)
						break;
				}
			}
		}


		if (prev[T] == -1)
			break;

		int flow = INF;

		for (int i = T; i != S; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);

		for (int i = T; i != S; i = prev[i])
		{
			//cout << " i : " << i << endl;
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}

		totalFlow += flow;
	}

	printf("%d\n", totalFlow);

	return 0;
}