
// 6806.c
#include <stdio.h>

#define _9FAC_ 362880

int visit[19];
int gyu[9];
int in[9];
int ans;

void dfs(int d, int score_in, int score_gyu)	{

	if (score_in > 85 || score_gyu > 85)	{
		int result = 1;
		for (int i = d; i < 9; i++)	{
			result *= 9 - i;
		}
		if (score_gyu > 85)
			ans += result;
		return;
	}

	else	{
		for (int i = 0; i < 9; i++)	{
			if (visit[in[i]] == 0)	{
				visit[in[i]] = 1;
				if (in[i] > gyu[d])
					dfs(d + 1,  score_in + in[i] + gyu[d], score_gyu);
				else
					dfs(d + 1,  score_in, score_gyu + in[i] + gyu[d]);
				visit[in[i]] = 0;
			}
		}
	}

}
int main(void)	{
	int T, test_case;

	int k;

	int score_in;
	int score_gyu;
	
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		for (int i = 0; i < 19; i++)	{
			visit[i] = 0;
		}
		for (int i = 0; i < 9; i++)	{
			scanf("%d", &gyu[i]);
			visit[gyu[i]] = 1;
		}

		k = 0;
		for (int i = 1; i < 19; i++)	{
			if (visit[i] == 0)	{
				in[k] = i;
				k++;
			}
		}
		score_in = 0;
		score_gyu = 0;

		dfs(0,  score_in, score_gyu);

		printf("#%d %d %d\n", test_case, ans, _9FAC_ - ans);
	}
	return 0;
}
