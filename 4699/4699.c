
// 4699.c
#include <stdio.h>

int dp[2010][2010];
int cost[30];
int main(void)	{
	int T, test_case;
	int L, K;
	char in[2010];


	int c_ins, c_del;

	int cost_i, cost_j;
	int tmp_i, tmp_j;

	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{

		for (int i = 0; i < 2010; i++)	{
			for (int j = 0; j < 2010; j++)	{
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < 30; i++)	{
			cost[i] = 0;
		}
		
		scanf("%d %d", &L, &K);

		scanf("%s", in);

		for (int i = 0; i < K; i++)	{
			scanf("%d %d", &c_ins, &c_del);
			cost[i] = c_ins < c_del ? c_ins : c_del;
		}

		for (int i = L - 1; i >= 0; i--)	{
			for (int j = i; j < L; j++)	{
				if (in[i] == in[j])
					dp[i][j] = dp[i + 1][j - 1];
				else	{
					cost_i = cost[in[i] - 'a'];
					cost_j = cost[in[j] - 'a'];

					tmp_i = dp[i + 1][j] + cost_i;
					tmp_j = dp[i][j - 1] + cost_j;
					dp[i][j] = tmp_i > tmp_j ? tmp_j : tmp_i;
					
				}
			}
		}

		printf("#%d %d\n", test_case, dp[0][L - 1]);
	}

	return 0;
}
