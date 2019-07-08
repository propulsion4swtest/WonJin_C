
// 7964.c
#include <stdio.h>

int city[300010];
int D;
int main(void)	{
	int test_case, T;
	int ans;
	int n_city;
	int zero;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		zero = 0;

		scanf("%d %d", &n_city, &D);
		for (int i = 0; i < n_city; i++)	{
			scanf("%d", &city[i]);
		}

		for (int i = 0; i < n_city; i++)	{
			if (city[i] == 0)	{
				zero++;
			}
			else	{
				zero = 0;
			}
			if (zero >= D)	{
				ans++;
				zero = 0;
			}
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
