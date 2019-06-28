
// 4013.c
#include <stdio.h>
#include <math.h>

typedef unsigned char uchar;
uchar saw[5];


// saw1 is left, saw2 is right
int isPolar(char saw1, char saw2)	{
	if ( ((saw1 >> 5) & 0x01) != ((saw2 >> 1) & 0x01) )
		return 1;
	else return 0;
}

// ror: ROtation Right
uchar ror(uchar saw1)	{
	uchar temp_saw = (saw1) >> 1;
	temp_saw |= ((saw1) << 7);
	return temp_saw;
}

// rol: ROtation Left
uchar rol(uchar saw1)	{
	uchar temp_saw = (saw1) << 1;
	temp_saw |= ((saw1) >> 7);
	return temp_saw;
}

int main(void)	{
	int T, test_case;
	int K;

	int input;
	int whatSaw;
	int ans;

	char rot[5];
	freopen("data.txt", "r", stdin);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; test_case++)	{
		ans = 0;
		scanf("%d", &K);
		for (int i = 0; i < 5; i++)	{
			saw[i] = 0;
			rot[i] = 0;
		}

		for (int i = 1; i < 5; i++)	{
			for (int j = 0; j < 8; j++)	{
				scanf("%d", &input);
				saw[i] |= (input << (7 - j));
			}
		}


		for (int i = 0; i < K; i++)	{
			scanf("%d %d", &whatSaw, &input);

			for (int i = 0; i < 5; i++)	{
				rot[i] = 0;
			}
			rot[whatSaw] = input;

			// LEFT SIDE
			for (int i = whatSaw; i > 1; i--)	{
				if (isPolar(saw[i - 1], saw[i]))	{
					rot[i - 1] = rot[i] * (-1);
				}
			}
			// RIGHT SIDE
			for (int i = whatSaw; i < 4; i++)	{
				if (isPolar(saw[i], saw[i + 1]))	{
					rot[i + 1] = rot[i] * (-1);
				}
			}

			for (int i = 1; i < 5; i++)	{
				if (rot[i] == 1)	{
					saw[i] = ror(saw[i]);
				}
				if (rot[i] == -1)	{
					saw[i] = rol(saw[i]);
				}
			}

		}

		for (int i = 1; i < 5; i++)	{
			ans += (int)(saw[i] >> 7) * pow(2.0, (double)i - 1);
		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}
