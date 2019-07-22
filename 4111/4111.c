
// 4111.c
#include <stdio.h>
#include <stdlib.h>

#define cMax 10000+1
#define reMax 2000000+10

int comp(const void *a, const void *b)	{
	int ia = *(int *)a;
	int ib = *(int *)b;
	return ia - ib;
}
int coord[cMax];
int subdist[cMax];
char coord_re[reMax];
int ans;
int N, K;

int main(void)	{
	int tc, T;
	int c, t, re;
	int total;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		ans = 0;
		for (int n = 0; n < reMax; n++)	coord_re[n] = 0;
		scanf("%d %d", &N, &K);

		total = N;
		t = 0;
		for (int n = 0; n < N; n++)	{
			scanf("%d", &c);
			re = c + 1000000;
			if (coord_re[re] == 0)	{
				coord_re[re] = 1;
				coord[t] = c;
				t++;
			}
			else	total--;
		}

		qsort(coord, total, sizeof(int), comp);

		for (int n = 0; n < total - 1; n++)
			subdist[n] = coord[n + 1] - coord[n];

		qsort(subdist, total - 1, sizeof(int), comp);
		for (int n = 0; n < total - K; n++)	{
			ans += subdist[n];
		}
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
