
// 7393.c
#include <stdio.h>

#define DIV 1000000000

int dp[110][10][1 << 10];
int num_s(int N, int cur_num, int bit)	{
	if (cur_num < 0 || cur_num > 9)	return 0;
	if (N == 1)	return (1 << cur_num | bit) == 1023;

	int prev_bit = bit;

	int num = dp[N][cur_num][bit];

	if (num != -1)	
		return num;

	bit |= (1 << cur_num);
	num = (num_s(N - 1, cur_num - 1, bit) + num_s(N - 1, cur_num + 1, bit)) % DIV;
	dp[N][cur_num][prev_bit] = num;
	return num;
}
int main(void)	{
	int test_case, T;
	int N;
	long long int ans;

	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;

		for (int i = 0; i < 110; i++)	{
			for (int j = 0; j < 10; j++)	{
				for (int k = 0; k < (1 << 10); k++)	{
					dp[i][j][k] = -1;
				}
			}
		}
		scanf("%d", &N);

		for (int i = 1; i < 10; i++)	{

			ans = (ans + num_s(N, i, 0)) % DIV;
		}
		printf("#%d %lld\n", test_case, ans);
	}
}
