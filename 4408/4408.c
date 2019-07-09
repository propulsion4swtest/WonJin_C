
// 4408.c
#include <stdio.h>
#include <stdlib.h>		// qsort

#define abs(a, b) (a - b < 0 ? b - a : a - b)
int checkWhoUse[401];

typedef struct {
	int src;
	int dst;
} badguy;

badguy listOfBadGuy[401];

int sortForShortDist(const void *badguy_a, const void *badguy_b)	{
	badguy a = *(badguy *)badguy_a;
	badguy b = *(badguy *)badguy_b;
	int dist_a = abs(a.src, a.dst);
	int dist_b = abs(b.src, b.dst);

	if (dist_a != dist_b)	return dist_a - dist_b;
	else	return a.src - b.src;
}

int main(void)	{
	int test_case, T;
	int N;
	int src, dst;
	int ans;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{

		// Initialize
		ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < 401; i++)	{
			checkWhoUse[i] = 0;
		}		// Initialize checking array which check who use corridor.

		for (int i = 0; i < N; i++)	{
			scanf("%d %d", &listOfBadGuy[i].src, &listOfBadGuy[i].dst);
		}		// Input phase

		// Use quick sort shortest path order.
		qsort(listOfBadGuy, N, sizeof(badguy), sortForShortDist);	

		for (int i = 0; i < N; i++)	{
			src = listOfBadGuy[i].src;
			dst = listOfBadGuy[i].dst;
			if (src < dst)	{
				for (int j = src; j <= (dst % 2 == 1 ? dst + 1 : dst); j++)	{
					checkWhoUse[j] += 1;
				}
			}
			else	{
				for (int j = src; j >= (dst % 2 == 0 ? dst - 1 : dst); j--)	{
					checkWhoUse[j] += 1;
				}
			}
		}

		for (int i = 0; i < 401; i++)	{
			ans = ans > checkWhoUse[i] ? ans : checkWhoUse[i];
		}
		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
