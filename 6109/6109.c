
// 6109.c
#include <stdio.h>

int board[20][20];
int N;

void printBoard(void)	{
	for (int r = 0; r < N; r++)	{
		for (int c = 0; c < N; c++)	{
			printf("%d ", board[r][c]);
		}
		puts("");
	}
}

void move(char d)	{
	int prev;
	int prev_pos;
	int tBoard_pos;


	//up
	if (d == 'u')	{
		for (int c = 0; c < N; c++)	{
			prev = -1;
			prev_pos = -1;
			for (int r = 0; r < N; r++)	{
				if (board[r][c] == 0)	continue;
				else	{
					if (r == 0 || prev == -1)	{
						prev = board[r][c];
						prev_pos = r;
						continue;
					}
					else	{
						if (prev == board[r][c])	{
							prev <<= 1;
							board[r][c] = 0;
							board[prev_pos][c] = prev;
							prev = -1;
						}
						else	{
							prev = board[r][c];
							prev_pos = r;
						}
					}
				}
			}
			tBoard_pos = 0;
			for (int r = 0; r < N; r++)	{
				if (board[r][c] == 0)	continue;
				else	{
					board[tBoard_pos][c] = board[r][c];
					if (tBoard_pos != r)
						board[r][c] = 0;

					tBoard_pos++;
				}
			}
		}

	}


	//down
	else if (d == 'd') {
		for (int c = 0; c < N; c++)	{
			prev = -1;
			prev_pos = -1;
			for (int r = N - 1; r >= 0; r--)	{
				if (board[r][c] == 0)	continue;
				else	{
					if (r == N - 1 || prev == -1)	{
						prev = board[r][c];
						prev_pos = r;
						continue;
					}
					else	{
						if (prev == board[r][c])	{
							prev <<= 1;
							board[r][c] = 0;
							board[prev_pos][c] = prev;
							prev = -1;
						}
						else	{
							prev = board[r][c];
							prev_pos = r;
						}
					}
				}
			}
			tBoard_pos = N - 1;
			for (int r = N - 1; r >= 0; r--)	{
				if (board[r][c] == 0)	continue;
				else	{
					board[tBoard_pos][c] = board[r][c];
					if (tBoard_pos != r)
						board[r][c] = 0;

					tBoard_pos--;
				}
			}
		}
	}

	else if (d == 'l')	{
		for (int r = 0; r < N; r++)	{
			prev = -1;
			prev_pos = -1;
			for (int c = 0; c < N; c++)	{
				if (board[r][c] == 0) continue;
				else	{
					if (c == 0 || prev == -1)	{
						prev = board[r][c];
						prev_pos = c;
						continue;
					}
					else	{
						if (prev == board[r][c])	{
							prev <<= 1;
							board[r][c] = 0;
							board[r][prev_pos] = prev;
							prev = -1;
						}
						else	{
							prev = board[r][c];
							prev_pos = c;
						}
					}
				}
			}
			tBoard_pos = 0;
			for (int c = 0; c < N; c++)	{
				if (board[r][c] == 0)	continue;
				else	{
					board[r][tBoard_pos] = board[r][c];
					if (tBoard_pos != c)
						board[r][c] = 0;

					tBoard_pos++;
				}
			}
		}
	}

	else if (d == 'r')	{
		for (int r = 0; r < N; r++)	{
			prev = -1;
			prev_pos = -1;
			for (int c = N - 1; c >= 0; c--)	{
				if (board[r][c] == 0)	continue;
				else	{
					if (c == N - 1 || prev == -1)	{
						prev = board[r][c];
						prev_pos = c;
						continue;
					}
					else	{
						if (prev == board[r][c])	{
							prev <<= 1;
							board[r][c] = 0;
							board[r][prev_pos] = prev;
							prev = -1;
						}
						else	{
							prev = board[r][c];
							prev_pos = c;
						}
					}
				}
			}
			tBoard_pos = N - 1;
			for (int c = N - 1; c >= 0; c--)	{
				if (board[r][c] == 0)	continue;
				else	{
					board[r][tBoard_pos] = board[r][c];
					if (tBoard_pos != c)
						board[r][c] = 0;

					tBoard_pos--;
				}
			}
		}

	}

}

int main(void)	{
	int tc, T;
	char sDir[5];

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)	{
		scanf("%d %s", &N, sDir);

		for (int r = 0; r < N; r++)	{
			for (int c = 0; c < N; c++)	{
				scanf("%d", &board[r][c]);
			}
		}

		move(sDir[0]);

		printf("#%d\n", tc);
		printBoard();
	}
	return 0;
}
