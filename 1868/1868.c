
// 1868.c
#include <stdio.h>

#define MAX 310
typedef struct {
	int x;
	int y;
} coord_t;

int dir[8][2] = {
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1}
};

char map[MAX][MAX];
coord_t q[MAX * MAX];
int f, r;
int N;

static inline int valid(coord_t t)  {
	if (t.x >= 0 && t.x < N && t.y >= 0 && t.y < N) return 1;
	else return 0;
}

int main(void)  {
	int test_case, T;
	int ans;
	int flag;
	int mine_cnt;

	int zero_cnt;
	coord_t cur;
	coord_t co;
	coord_t co_tmp;

	freopen("data.txt", "r", stdin);

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)  {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				map[i][j] = 0;
			}
		}
		f = r = 0;
		ans = 0;

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf(" %c", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] != '.') continue;
				else  {
					f = r = 0;
					cur.x = i;
					cur.y = j;
					q[r++] = cur;

					while (f < r) {
						co = q[f++];
						if (map[co.x][co.y] != '.')	continue;
						ans++;
						//printf("%d %d increase!!\n", co.x, co.y);

						zero_cnt = 0;
						mine_cnt = 0;
						flag = 0;
						for (int k = 0; k < 8; k++) {
							co_tmp.x = co.x + dir[k][0];
							co_tmp.y = co.y + dir[k][1];
							if (valid(co_tmp)) {
								if (map[co_tmp.x][co_tmp.y] == '*') {
									flag = 1;
									mine_cnt++;
								}
								if (map[co_tmp.x][co_tmp.y] == '0' && !zero_cnt)	{
									ans--;
									zero_cnt = 1;
								}
							}
						}
						if (flag) map[co.x][co.y] = '9'/*mine_cnt + '0'*/;
						else 	map[co.x][co.y] = '0';

						if (map[co.x][co.y] == '9' && zero_cnt)	{
							map[co.x][co.y] = '8';
						}

						for (int k = 0; k < 8; k++) {
							co_tmp.x = co.x + dir[k][0];
							co_tmp.y = co.y + dir[k][1];
							if (valid(co_tmp))  {
								if (map[co_tmp.x][co_tmp.y] == '.')	{
									q[r++] = co_tmp;
								}
								if (map[co.x][co.y] == '0')	{
									if (map[co_tmp.x][co_tmp.y] == '9')	{
										ans--;
										map[co_tmp.x][co_tmp.y]--;

										//printf("%d %d decrease!!\n", co_tmp.x, co_tmp.y);
									}
								}
							}
						}
					}
				}
			}
		}
		/*
			 for (int i = 0; i < N; i++) {
			 for (int j = 0; j < N; j++) {
			 printf(" %c ", map[i][j]);
			 }
			 puts("");
			 }
		 */



		printf("#%d %d\n", test_case, ans);
	}

	return 0;
}

