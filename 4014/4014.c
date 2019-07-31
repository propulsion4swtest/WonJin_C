
// 4014.c
#include <stdio.h>
#include <stdlib.h>

int ans, N, X;
int map[20][20];
int use[20][20];

int main(void)	{
	int tc, T;
	int flag;


	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++)	{
		ans = 0;
		scanf("%d %d", &N, &X);

		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				scanf("%d", &map[i][j]);
				use[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++)	{
			flag = 0;
			for (int j = 1; j < N; j++)	{
				if (abs(map[i][j - 1] - map[i][j]) > 1)	{
					flag = 1;
					break;
				}
				else if (!flag && (map[i][j] - map[i][j - 1]) == 1)	{
					for (int k = 0; k < X; k++)	{
						if ((j - 1 - k) < 0)	{
							flag = 1;
							break;
						}
						if (use[i][j - 1 - k] != 0)	{
							flag = 1;
							break;
						}
						if (map[i][j - 1 - k] != map[i][j - 1])	{
							flag = 1;
							break;
						}
						use[i][j - 1 - k] = 1;
					}
				}
				else if (!flag && (map[i][j - 1] - map[i][j]) == 1)	{
					for (int k = 0; k < X; k++)	{
						if (j + k >= N)	{
							flag = 1;
							break;
						}
						if (use[i][j + k] != 0)	{
							flag = 1;
							break;
						}
						else if (map[i][j + k] != map[i][j])	{
							flag = 1;
							break;
						}
						use[i][j + k] = 1;
					}
				}
				else if (flag)	break;
			}
			if (flag)	{
				continue;
			}
			else	{
				ans++;
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				use[i][j] = 0;

		for (int j = 0; j < N; j++)	{
			flag = 0;
			for (int i = 1; i < N; i++)	{
				if (abs(map[i - 1][j] - map[i][j]) > 1)	{
					flag = 1;
					break;
				}
				else if (!flag && (map[i][j] - map[i - 1][j]) == 1)	{
					for (int k = 0; k < X; k++)	{
						if ((i - 1 - k) < 0)	{
							flag = 1;
							break;
						}
						if (use[i - 1 - k][j] != 0)	{
							flag = 1;
							break;
						}
						if (map[i - 1 - k][j] != map[i - 1][j])	{
							flag = 1;
							break;
						}
						use[i - 1 - k][j] = 1;
					}
				}
				else if (!flag && (map[i - 1][j] - map[i][j]) == 1)	{
					for (int k = 0; k < X; k++)	{
						if (i + k >= N)	{
							flag = 1;
							break;
						}
						if (use[i + k][j] != 0)	{
							flag = 1;
							break;
						}
						else if (map[i + k][j] != map[i][j])	{
							flag = 1;
							break;
						}
						use[i + k][j] = 1;
					}
				}
				else if (flag)	break;
			}
			if (flag)	{
				continue;
			}
			else	{
				ans++;
			}
		}

		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
