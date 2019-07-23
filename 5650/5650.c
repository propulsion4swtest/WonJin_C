
// 5650.c
#include <stdio.h>

#define U 0
#define L 1
#define D 2
#define R 3

int board[100][100];
int N;
int dir[4][2] = {
	{-1, 0},	// Up
	{0, -1},	// Left
	{1, 0},		// Down
	{0, 1}		// Right
};

int main(void)	{
	int tc, T;
	int ans, tans;
	int start[10000][2];
	int s;
	int wormhole[10][2];
	int wormManage[5] = { 0, };

	int dr, dc;
	int curd;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		ans = 0;
		s = 0;
		scanf("%d", &N);

		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				scanf("%d", &board[i][j]);
				if (board[i][j] == 0)	{
					start[s][0] = i;
					start[s][1] = j;
					s++;
				}
				else if (board[i][j] > 5 && board[i][j] <= 10)	{
					if (wormManage[board[i][j] - 6] == 0)	{
						wormhole[board[i][j] - 6][0] = i;
						wormhole[board[i][j] - 6][1] = j;
					}
					else if (wormManage[board[i][j] - 6] == 1)	{
						wormhole[board[i][j] - 1][0] = i;
						wormhole[board[i][j] - 1][1] = j;
					}
					wormManage[board[i][j] - 6]++;
					if (wormManage[board[i][j] - 6] == 2)
						wormManage[board[i][j] - 6] = 0;
				}
			}
		}

#if PBOARD
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				printf("%d ", board[i][j]);
			}
			puts("");
		}
		puts("");
#endif
#if PWORMHOLE
		printf("WORMHOLE!!!\n");
		for (int i = 0; i < 10; i++)	{
			printf("%d %d\n", wormhole[i][0], wormhole[i][1]);
		}
		puts("");
#endif


		for (int i = 0; i < s; i++)	{
			for (int d = 0; d < 4; d++)	{
				tans = 0;
				curd = d;
				dr = start[i][0];
				dc = start[i][1];
				do	{
					dr = dr + dir[curd][0];
					dc = dc + dir[curd][1];

					if (dr < 0 || dc < 0 || dr >= N || dc >= N)	{
						if (curd == U)	curd = D;
						else if (curd == D) curd = U;
						else if (curd == R)	curd = L;
						else if (curd == L) curd = R;
						tans++;
					}

					else if (board[dr][dc] == 5) {
						if (curd == U)	curd = D;
						else if (curd == D) curd = U;
						else if (curd == R)	curd = L;
						else if (curd == L) curd = R;				
						tans++;
					}

					else if (board[dr][dc] == -1)	break;
					else if (board[dr][dc] == 0)	continue;

					else if (board[dr][dc] == 1)	{
						if (curd == U)	curd = D;
						else if (curd == D)	curd = R;
						else if (curd == R) curd = L;
						else if (curd == L) curd = U;
						tans++;
					}
					else if (board[dr][dc] == 2)	{
						if (curd == U)	curd = R;
						else if (curd == D)	curd = U;
						else if (curd == R) curd = L;
						else if (curd == L) curd = D;
						tans++;
					}
					else if (board[dr][dc] == 3)	{
						if (curd == U)	curd = L;
						else if (curd == D)	curd = U;
						else if (curd == R) curd = D;
						else if (curd == L) curd = R;
						tans++;
					}
					else if (board[dr][dc] == 4)	{
						if (curd == U)	curd = D;
						else if (curd == D)	curd = L;
						else if (curd == R) curd = U;
						else if (curd == L) curd = R;
						tans++;
					}

					else if (board[dr][dc] > 5 && board[dr][dc] <= 10)	{
						int tdr = dr;	int tdc = dc;
						if (dr == wormhole[board[dr][dc] - 6][0] && dc == wormhole[board[dr][dc] - 6][1])	{
							dr = wormhole[board[tdr][tdc] - 1][0];
							dc = wormhole[board[tdr][tdc] - 1][1];
						}
						else {
							dr = wormhole[board[tdr][tdc] - 6][0];
							dc = wormhole[board[tdr][tdc] - 6][1];
						}
					}

				}	while (!(dr == start[i][0] && dc == start[i][1]));
				ans = ans > tans ? ans : tans;
			}
		}

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
