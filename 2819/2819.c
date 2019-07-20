
// 2819.c
#include <stdio.h>

#define LIM 10000000

int grid[4][4];
char arr[LIM];
int ans;
int dir[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

void dfs(int depth, int r, int c, int num)	{
	if (depth >= 6)	{
		if (arr[num] == 0)	{
			arr[num] = 1;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)	{
		int tr = r + dir[i][0];
		int tc = c + dir[i][1];

		if (tr < 4 && tc < 4 && tc >= 0 && tr >= 0)
			dfs(depth + 1, tr, tc, num * 10 + grid[tr][tc]);
	}
}
int main(void)	{
	int test_case, T;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		for (int i = 0; i < LIM; i++)	arr[i] = 0;

		for (int i = 0; i < 4; i++)	{
			for (int j = 0; j < 4; j++)	{
				scanf("%d", &grid[i][j]);
			}
		}


		for (int i = 0; i < 4; i++)	{
			for (int j = 0; j < 4; j++)	{
				dfs(0, i, j, grid[i][j]);
			}
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
