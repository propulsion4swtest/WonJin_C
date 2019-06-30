
// 1244.c
#include <stdio.h>
#include <math.h>

int num[6];
int visit[1000000][11];
int ans;

int makeNum(void)	{
	int arg;
	int sum = 0;
	for (int i = 0; i < 6; i++)	{
		arg = pow(10.0, (double)(5 - i));
		sum += (arg * num[i]);
		//printf("%d ", num[i]);
	}
	//puts("");
	return sum;

}
void dfs(int d, int cnt, int len)	{
	if (d == cnt)	{
		int sum = makeNum();
		ans = sum > ans ? sum : ans;
		return;
	}

	int tmp;
	for (int i = 5; i >= len; i--)	{
		for (int j = 5; j >= len; j--)	{
			if (i == j)	continue;
			else	{
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;

				int temp = makeNum();
				if (visit[temp][d + 1] == 0)	{
					visit[temp][d + 1] = 1;

					dfs(d + 1, cnt, len);
				}

				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}
}
int main(void)	{
	int test_case, T;
	int number, count;
	int arg;
	int len;

	
	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		len = 0;

		for (int i = 0; i < 6; i++)	{
			num[i] = 0;
		}
		for (int i = 0; i < 1000000; i++)	{
			for (int j = 0; j < 11; j++)	{
				visit[i][j] = 0;
			}
		}

		scanf("%d %d", &number, &count);
		for (int i = 0; i < 6; i++)	{
			arg = pow(10.0, (double)(5 - i));
			num[i] = number / arg;
			number %= arg;
		}

		visit[number][0] = 1;
		for (int i = 0; i < 6; i++)	{
			if (num[i] != 0)	{
				len = i;
				break;
			}
		}

		dfs(0, count, len);
		printf("#%d %d\n", test_case, ans);


	}

	return 0;
}
