
// 1824.c
#include <stdio.h>

#define RIGHT 0 
#define DOWN 1 
#define LEFT 2 
#define UP 3 


char map[25][25];
int vis[25][25][5][20];
int mem;
int R, C;

int dir[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

int dfs(int r, int c, int d)	{
	int ret = 0;
	if (map[r][c] == '@')	 return 1;
	else	{
		vis[r][c][d][mem] = 1;
		// Store a number into the mem
		if (map[r][c] >= '0' && map[r][c] <= '9')	mem = map[r][c] - '0';

		// Change the direction
		else if (map[r][c] == '>')	d = RIGHT;
		else if (map[r][c] == '^')	d = UP;
		else if (map[r][c] == '<')	d = LEFT;
		else if (map[r][c] == 'v')	d = DOWN;

		// Change the direction by mem
		else if (map[r][c] == '_') {
			if (mem == 0)	d = RIGHT;
			else					d = LEFT;
		}
		else if (map[r][c] == '|')	{
			if (mem == 0)	d = DOWN;
			else					d = UP;
		}

		// mem plus++minus--
		else if (map[r][c] == '+')	{
			if (mem == 15)	mem = 0;
			else						mem++;
		}
		else if (map[r][c] == '-')	{
			if (mem == 0)		mem = 15;
			else						mem--;
		}

		// Change the direction randomly
		else if (map[r][c] == '?')	{
			for (int i = 0; i < 4; i++)	{
				int tmpr = r + dir[i][0];
				int tmpc = c + dir[i][1];

				if (tmpr >= R)	tmpr = 0;
				else if (tmpr < 0)	tmpr = R - 1;
				if (tmpc >= C)	tmpc = 0;
				else if (tmpc < 0)	tmpc = C - 1;

				if (vis[tmpr][tmpc][i][mem] == 0)	{
					ret += dfs(tmpr, tmpc, i); 
				}
			}
		}

		r += dir[d][0];
		c += dir[d][1];

		if (r >= R)	r = 0;
		else if (r < 0)	r = R - 1;
		if (c >= C)	c = 0;
		else if (c < 0)	c = C - 1;

		if (vis[r][c][d][mem] == 0)	{
			ret += dfs(r, c, d);
		}
	}

	return ret;
}

int main(void)	{
	int test_case, T;
	int d;
	int ret;
	

	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{

		scanf("%d %d", &R, &C);
		mem = 0;
		d = RIGHT;

		for (int r = 0; r < R; r++)	{
			for (int c = 0; c < C; c++)	{
				scanf(" %c", &map[r][c]);
			}
		}
		for (int i = 0; i < 25; i++)	{
			for (int j = 0; j < 25; j++)	{
				for (int r = 0; r < 5; r++)	{
					for (int c = 0; c < 20; c++)	{
						vis[i][j][r][c] = 0;
					}
				}
			}
		}

		ret = dfs(0, 0, d);

		if (ret)	{
			printf("#%d YES\n", test_case);
		}
		else	{
			printf("#%d NO\n", test_case);
		}
	}


	return 0;

}
