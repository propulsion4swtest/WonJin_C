
// 4615.c
#include <stdio.h>

#define BLACK 1 
#define WHITE -1 

#define _DEBUG_ 0


int board[9][9];
int N;

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

static inline int Bdry(int x, int y)	{
	if (x <= N && y <= N && x > 0 && y > 0)	return 1;
	else	return 0;
}

void printBoard(void)	{
	for (int i = 1; i <= N; i++)	{
		for (int j = 1; j <= N; j++)	{
			if (board[i][j] == WHITE)	{
				printf(" [W] ");
			}
			else if (board[i][j] == BLACK)	{
				printf(" [B] ");
			}
			else if (board[i][j] == 0)	{
				printf(" [ ] ");
			}
		}
		puts("");
	}
	puts("");
}

void countNum(int *numB, int *numW)	{
	for (int i = 1; i <= N; i++)	{
		for (int j = 1; j <= N; j++)	{
			if (board[i][j] == WHITE)
				(*numW)++;
			else	(*numB)++;

		}
	}
}

void flip(int x, int y, int dol)	{
	int tmpx, tmpy;
	for (int i = 0; i < 8; i++)	{
		tmpx = x + dir[i][0];
		tmpy = y + dir[i][1];


		while (Bdry(tmpx, tmpy) && board[tmpx][tmpy] != dol && board[tmpx][tmpy] != 0)	{
			board[tmpx][tmpy] = board[tmpx][tmpy] * (-1);
			tmpx = tmpx + dir[i][0];
			tmpy = tmpy + dir[i][1];
		}


		if (!Bdry(tmpx, tmpy) || board[tmpx][tmpy] == 0)	{
			while (!(tmpx == x && tmpy == y))	{
				board[tmpx][tmpy] = board[tmpx][tmpy] * (-1);
				tmpx = tmpx - dir[i][0];
				tmpy = tmpy - dir[i][1];
			}

		}
	}
#if _DEBUG_
	printBoard();
#endif

}
int main(void)	{
	int test_case, T;
	int M;

	int numB, numW;
	int x, y, dol;

	freopen("data.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 1; test_case <= T; test_case++)	{
		numB = numW = 0;
		for (int i = 0; i < 9; i++)	{
			for (int j = 0; j < 9; j++)	{
				board[i][j] = 0;
			}
		}
		scanf("%d %d", &N, &M);

		board[N / 2][N / 2] = board[N / 2 + 1][N / 2 + 1] = WHITE;
		board[N / 2 + 1][N / 2] = board[N / 2][N / 2 + 1] = BLACK;

#if _DEBUG_
		printBoard();
#endif

		for (int i = 0; i < M; i++)	{
			scanf("%d %d %d", &x, &y, &dol);
			if (dol == 1)	{
				board[x][y] = BLACK;
#if _DEBUG_
				printf("BEFORE::\n");
				printBoard();
				printf("AFTER::\n");
#endif
				flip(x, y, BLACK);
#if _DEBUG_
				printf("\n");
#endif
			}
			else	{
				board[x][y] = WHITE;
#if _DEBUG_
				printf("BEFORE::\n");
				printBoard();
				printf("AFTER::\n");
#endif
				flip(x, y, WHITE);
#if _DEBUG_
				printf("\n");
#endif
			}
		}

		countNum(&numB, &numW);
		printf("#%d %d %d\n", test_case, numB, numW);

	}

	return 0;
}
