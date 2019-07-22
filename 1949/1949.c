
// 1949.c
#include <stdio.h>

int map[8][8];
int vis[8][8];
int N, K;
int ans;

int dir[4][2] = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1}
};

void printvis(void)	{
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			printf("%d ", vis[i][j]);
		}
		puts("");
	}
	puts("");
}

void printmap(void)	{
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	puts("");
}

void dfs(int depth, int r, int c, int k, int flag)	{
	int prev, tk;
	for (int i = 0; i < 4; i++)	{
		int tr = r + dir[i][0];
		int tc = c + dir[i][1];
		if (tr >= 0 && tc >= 0 && tc < N && tr < N)	{
			if (vis[tr][tc] == 0)	{
				vis[tr][tc] = 1;
				prev = map[tr][tc];
				tk = k;

				if (map[tr][tc] < map[r][c])
					dfs(depth + 1, tr, tc, tk, flag);

				if (flag == 0)	{
					while (tk > 0)	{
						tk--;
						map[tr][tc]--;
						if (map[tr][tc] < map[r][c])	{
							dfs(depth + 1, tr, tc, tk, 1);
						}
					}
				}
				map[tr][tc] = prev;
				vis[tr][tc] = 0;
			}
		}
	}
	ans = depth > ans ? depth : ans;
}

int main(void)	{
	int tc, T;
	int start[5][2];
	int s, max;
	
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		ans = 0;
		max = 0;
		s = 0;
		scanf("%d %d", &N, &K);

		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				scanf("%d", &map[i][j]);
				vis[i][j] = 0;
				if (max < map[i][j])	{
					max = map[i][j];
					s = 0;
					start[s][0] = i;
					start[s][1] = j;
					s++;
				}
				else if (max == map[i][j])	{
					start[s][0] = i;
					start[s][1] = j;
					s++;
				}
			}
		}

		for (int i = 0; i < s; i++)	{
			vis[start[i][0]][start[i][1]] = 1;
			dfs(1, start[i][0], start[i][1], K, 0);
			vis[start[i][0]][start[i][1]] = 0;
		}

		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
