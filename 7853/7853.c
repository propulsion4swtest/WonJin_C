
// 7853.c
#include <stdio.h>
#include <string.h>

#define MOD 1000000007

typedef long long int lli;
char str[1010];

int main(void)	{
	int test_case, T;
	int len;
	lli ans;
	
	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 1;
		scanf("%s", str);
		len = strlen(str);

		if (str[0] != str[1])	ans *= 2;
		if (str[len - 1] != str[len - 2]) ans *= 2;
		for (int i = 1; i < len - 1; i++)	{
			if (str[i - 1] != str[i] && str[i] != str[i + 1] && str[i - 1] != str[i + 1])	ans *= 3;
			else if (str[i - 1] == str[i] && str[i] == str[i + 1] && str[i - 1] == str[i + 1]) ans *= 1;
			else	ans *= 2;

			ans %= MOD;
		}


		printf("#%d %lld\n", test_case, (ans % MOD));

	}
	return 0;
}
