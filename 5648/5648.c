
// 5648.c
#include <stdio.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3


typedef struct {
	int x;
	int y;
	int dir;
	int K;		//energy
	int id;
} atom;

int dir[4][2] = {
	{-1, 0},
	{1, 0},
	{0, -1},
	{0, 1}
};

int map[4002][4002];
atom cirQ[1010];
int coord_q[1010];

int main(void)	{
	int test_case, T;
	int N_atom, disappCnt = 0;
	int ans;
	int f, r;
	int collision_f, collision_r;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)	{
		for (int i = 0; i < 4002; i++)	{
			for (int j = 0; j < 4002; j++)	{
				map[i][j] = 0;
			}
		}
		ans = 0;
		f = r  = 0;

		scanf("%d", &N_atom);
		for (int i = 1; i <= N_atom; i++)	{
			atom a;

			scanf("%d %d %d %d", &a.y, &a.x, &a.dir, &a.K);
			a.x *= -1;
			a.x += 1000;	a.y += 1000;
			a.x *= 2;			a.y *= 2;
			a.id = i;
			cirQ[r++] = a;
			map[a.x][a.y] = 1;
		}

		while (N_atom > 0)	{
			collision_f = collision_r = 0;
			disappCnt = 0;
			f = 0;
			r = 0;
			for (int i = 0; i < N_atom; i++)	{
				atom p = cirQ[i];

				map[p.x][p.y] = 0;
				p.x += dir[p.dir][0];
				p.y += dir[p.dir][1];
#if __DEBUG__
				printf("%d %d %d %d: %d: %d\n", p.x, p.y, p.dir, p.K, p.id, N_atom);
#endif

				if (p.x >= 0 && p.y >= 0 && p.x < 4002 && p.y < 4002)	{
					map[p.x][p.y] += 1;

					if (map[p.x][p.y] > 1)	{
						coord_q[collision_r++] = p.x;
						coord_q[collision_r++] = p.y;
					}
					cirQ[r++] = p;
				}
				else	disappCnt++;
			}
			N_atom -= disappCnt;
			disappCnt = 0;

			while (collision_f < collision_r)	{
				int colli_x = coord_q[collision_f++];
				int colli_y = coord_q[collision_f++];

				f = r = 0;
				if (map[colli_x][colli_y] != 0)	{
					for (f = 0; f < N_atom; f++)	{
						atom p = cirQ[f];
						if (p.x == colli_x && p.y == colli_y)	{
							ans += p.K;
							disappCnt++;
						}
						else	{
							cirQ[r++] = p;
						}
					}
				}
				map[colli_x][colli_y] = 0;
			}
			N_atom -= disappCnt;
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
