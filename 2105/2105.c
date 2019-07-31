
// 2105.c
#include <stdio.h>
#include <math.h>

int map[20][20];
int use[101];
int ans, N;

int dir[4][2] = {
	{1, -1},
	{1, 1},
	{-1, 1},
	{-1, -1}
};

void pUse(void)	{
	int t;
	printf("\t");
	for (int j = 0; j < 10; j++)	{
		printf("%d ", j);
	}
	puts("");
	for (int i = 0; i < 10; i++)	{
		printf("[%d]\t", i);
		for (int j = 0; j < 10; j++)	{
			t = i * 10 + j;
			printf("%d ", use[t]);
		}
		puts("");
	}
}
void dfs(int d, int w, int h, int r, int c, int cnt)	{
	if (w != 0 && h != 0)	{
		if (2*(w + h) < ans)	return;
	}
	if (d == 4)	{
		/*
		printf("%d %d\n", r, c);
		pUse();
		*/
		ans = cnt > ans ? cnt : ans;
		return;
	}
	int tw, th;
	int tr, tc;
	tr = r;	tc = c;
	tw = th = 0;

	while (tr >= 0 && tc >= 0 && tr < N && tc < N)	{
		tr = tr + dir[d][0];
		tc = tc + dir[d][1];
		use[map[tr][tc]]++;
		if (use[map[tr][tc]] > 1)	break;

		cnt++;

		if (!(tr >= 0 && tc >= 0 && tr < N && tc < N))	break;

		if (d == 0)	{
			w++;
			dfs(d + 1, w, h, tr, tc, cnt);
		}
		else if (d == 1)	{
			h++;
			dfs(d + 1, w, h, tr, tc, cnt);
		}
		else if (d == 2)	{
			tw++;
			if (tw == w)	{
				dfs(d + 1, w, h, tr, tc, cnt);
				break;
			}
		}
		else if (d == 3)	{
			th++;
			if (th == h)	{
				dfs(d + 1, w, h, tr, tc, cnt);
				break;
			}
		}
	}
	while (!(tr == r && tc == c))	{
		use[map[tr][tc]]--;
		tr = tr - dir[d][0];
		tc = tc - dir[d][1];
	}
}
int main(void)	{
	int tc, T;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		ans = -1;
		for (int i = 0; i < 101; i++)	use[101] = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				scanf("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < round((double)N / 2.0); i++)	{
			for (int j = 0; j < N; j++)	{
				dfs(0, 0, 0, i, j, 0);
			}
		}

		
		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
