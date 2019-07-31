
// 2382.c
#include <stdio.h>

int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

typedef struct {
	int r;	// row
	int c;	// col
	int d;
	int micro;
	int id;
} crowd;

int map[100][100];
crowd cList[1000];
int meet[1000][4];
int meetManage[1000];


int ans;
int N, M, K;

void pMap(void)	{
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			printf("[%4d, %2d] ", cList[map[i][j]].micro, map[i][j]);
		}
		puts("");
	}
}

crowd dummy(void)	{
	crowd c;
	c.r = c.c = c.id = c.micro = c.d = 0;
	return c;
}

int main(void)	{
	int tc, T;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		ans = 0;

		scanf("%d %d %d", &N, &M, &K);
		for (int i = 1; i <= K; i++)	{
			crowd c;
			scanf("%d %d %d %d", &c.r, &c.c, &c.micro, &c.d);
			c.id = i;
			c.d--;

			cList[i] = c;

			map[c.r][c.c] = i;
		//	printf("%d %d %d %d\n", c.r, c.c, c.micro, c.d);
		}
		for (int m = 0; m < M; m++)	{
		/*
			pMap();
			puts("");
			*/
			for (int k = 1; k <= K; k++)	{
				crowd tc = cList[k];

				if (tc.id == 0)	continue;

				// move
				map[tc.r][tc.c] = 0;
				tc.r += dir[tc.d][0];
				tc.c += dir[tc.d][1];

				if (tc.r == 0 || tc.r == N - 1 || tc.c == 0 || tc.c == N - 1)	{
					tc.micro /= 2;
					if (tc.micro == 0)	{
						cList[tc.id] = dummy();
						continue;
					}
					if (tc.d == 0 || tc.d == 2)	tc.d++;
					else tc.d--;

				}
				cList[tc.id] = tc;
			}

			int meeting = 0;
			for (int k = 1; k <= K; k++)	{
				crowd tc = cList[k];

				if (tc.id == 0) continue;

				if (map[tc.r][tc.c] != 0)	{
					if (meet[map[tc.r][tc.c]][0] == 0)	{
						meet[map[tc.r][tc.c]][0] = map[tc.r][tc.c];
						meet[map[tc.r][tc.c]][1] = tc.id;
						meetManage[meeting++] = map[tc.r][tc.c];
					}
					else	{
						if (meet[map[tc.r][tc.c]][2] == 0)	meet[map[tc.r][tc.c]][2] = tc.id;
						else if (meet[map[tc.r][tc.c]][3] == 0)	meet[map[tc.r][tc.c]][3] = tc.id;
					}
					continue;
				}

				/*
					crowd t = cList[map[tc.r][tc.c]];
					if (t.micro > tc.micro)	{
						t.micro += tc.micro;
						cList[tc.id] = dummy();
						cList[t.id] = t;
					}
					else	{
						tc.micro += t.micro;
						cList[t.id] = dummy();
						map[tc.r][tc.c] = tc.id;
						cList[tc.id] = tc;
					}
				}
				*/
				else	{
					map[tc.r][tc.c] = tc.id;
				}

			}

			for (int me = 0; me < meeting; me++)	{
				int id = 0;
				for (int i = 0; i < 4; i++)	{
					if (meet[meetManage[me]][i] == 0)	break;
					if (i == 0)	id = meet[meetManage[me]][0];
					else	{
						if (cList[id].micro < cList[meet[meetManage[me]][i]].micro)	{
							id = meet[meetManage[me]][i];
						}
					}
				}
				for (int i = 0; i < 4; i++)	{
					if (meet[meetManage[me]][i] == 0)	break;
					if (meet[meetManage[me]][i] == id)	continue;
					else	{
						cList[id].micro += cList[meet[meetManage[me]][i]].micro;
						cList[meet[meetManage[me]][i]] = dummy();
					}
				}
				map[cList[id].r][cList[id].c] = id;
				for (int i = 0; i < 4; i++)
					meet[meetManage[me]][i] = 0;
			}
		}

		for (int k = 1; k <= K; k++)
		{
			ans += cList[k].micro;
			map[cList[k].r][cList[k].c] = 0;
		}

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
