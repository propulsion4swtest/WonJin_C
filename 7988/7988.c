
// 7988.c
#include <stdio.h>
#include <string.h>

int G[101][101];
char in_str[101][55];
int lStr;


void graphInsert(int s, int d)	{
	for (int i = 0; i < 101; i++)	{
		if (G[s][i] == 0)	{
			G[s][i] = d;
			break;
		}
	}

	for (int i = 0; i < 101; i++)	{
		if (G[d][i] == 0)	{
			G[d][i] = s;
			break;
		}
	}

}

int civilWar(int depth, int team[])	{
	if (depth == lStr)	return 1;

	int ret = 0;
	int tmp = 0;
	if (depth == 1)	{
		team[depth] = 1;
		ret += civilWar(depth + 1, team);

	}
	else	{
		for (int i = 0; i < 101; i++)	{
			if (G[depth][i] == 0)	{
				break;
			}
			else	{
				if (team[G[depth][i]] != 0)	{
					team[depth] = team[G[depth][i]] * -1;
					if (tmp != 0 && tmp == (team[depth] * -1))	{
						return 0;
					}
					tmp = team[depth];
				}
			}
		}
		if (team[depth] == 0)	{ 
			team[depth] = 1;
			ret += civilWar(depth + 1, team);

			team[depth] = -1;
			ret += civilWar(depth + 1, team);
		}
		else	{
			ret += civilWar(depth + 1, team);
		}
	}

	return ret;
	/*
	int tmp = 0;
	for (int s = start; s < lStr; s++)	{
		tmp = 0;
		if (s == 1)	{
			team[s] = 1;
		}
		else	{
			for (int i = 0; i < 101; i++)	{
				if (G[s][i] == 0)	{
					break;
				}
				else	{
					if (team[G[s][i]] != 0)	{
						team[s] = team[G[s][i]] * -1;
						if (tmp != 0 && tmp == (team[s] * -1))	{
							return 0;
						}
						tmp = team[s];
					}
				}
			}
			if (team[s] == 0)	{
				team[s] = 1;
			}
		}
	}
	return 1;
	*/
	
}
int main(void)	{
	int test_case, T;
	int K;
	char in1[55], in2[55];
	int team[101];
	int sFlag;
	int s1, s2;
	int ans;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)	{
		for (int i = 0; i < 101; i++)	{
			for (int j = 0; j < 101; j++)	{
				G[i][j] = 0;
			}
			team[i] = 0;
		}

		lStr = 1;
		sFlag = 0;
		scanf("%d", &K);
		for (int i = 0; i < K; i++)	{
			scanf("%s %s", in1, in2);

			for (int s = 1; s < lStr; s++)	{
				if (strcmp(in_str[s], in1) == 0)	{
					sFlag = 1;
					s1 = s;
					break;
				}
			}
			if (!sFlag)	{
				strcpy(in_str[lStr], in1);
				s1 = lStr;
				lStr++;
			}
			sFlag = 0;

			for (int s = 1; s < lStr; s++)	{
				if (strcmp(in_str[s], in2) == 0)	{
					sFlag = 1;
					s2 = s;
					break;
				}
			}
			if (!sFlag)	{
				strcpy(in_str[lStr], in2);
				s2 = lStr;
				lStr++;
			}

			graphInsert(s1, s2);
		}

		/*
		for (int s = 1; s < lStr; s++)	{
			printf("%d: ", s);
			for (int i = 0; i < 101; i++)	{
				if (G[s][i] == 0)	break;
				printf("%d ", G[s][i]);
			}
			printf("\n");
		}
		*/

		ans = civilWar(1, team);
		if (ans)	{
			printf("#%d Yes\n", test_case);
		}
		else	{
			printf("#%d No\n", test_case);
		}
	}
	return 0;
}
