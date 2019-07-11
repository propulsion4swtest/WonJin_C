
// 3234.c
#include <stdio.h>

int perm_sel[9];
int weight[9];
int N;
int sum;
int ans;

void perm(int depth, int left, int right)	{ 
	if (depth == N)	{
		if (left > right)	ans++;
		return;
	}
	if (left < right)	{
		return;
	}
	else if (left >= sum - left) {
		int temp = 1 << (N - depth);
		for (int i = N - depth; i > 0; i--)	{
			temp *= i;
		}
		ans += temp;
		return;
	}

	for (int i = 0; i < N; i++)	{
		if (perm_sel[i] == 0)	{
			perm_sel[i] = 1;

			perm(depth + 1, left + weight[i], right);

			perm(depth + 1, left, right + weight[i]);

			perm_sel[i] = 0;
		}
	}
}

int main(void)	{
	int test_case, T;

	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		sum = 0;
		for (int i = 0; i < 9; i++)	perm_sel[i] = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++)	{
			scanf("%d", &weight[i]);
			sum += weight[i];
		}

		perm(0, 0, 0);

		printf("#%d %d\n", test_case, ans);

	}
	return 0;
}
