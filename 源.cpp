#include <stdio.h>
using namespace std;
int main()
{
	int N, N1, N2, N3;
	int yt[10][10];
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			yt[i][j] = 2147483647;
	scanf_s("%d", &N); scanf_s("%d", &N1); scanf_s("%d", &N2); scanf_s("%d", &N3);
	int h = 0, l = 0, temp = 0; //行 列
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf_s("%d", &a);
		if (a > -1)
		{
			yt[h][temp] = a;
			temp++;
		}
		else
		{
			if (h == 0) l = temp + 1;
			h++;
			temp = 0;
		}
	} //创建杨氏矩阵

	for (int i = 0; i < N1; i++)
	{
		int b, k, j;
		scanf_s("%d", &b);
		for (k = l - 1, j = 0; k > -1, j < h;)
		{
			if (yt[j][k] == b)
			{
				printf("%d %d", j, k);
				break;
			}
			else if (b < yt[j][k]) k--;
			else j++;
		}
		if (k == -1 || j == h) printf("-1 -1");
		if (i < N1 - 1) printf(" ");
		else printf("\n");
	} //查找

	for (int i = 0; i < N2; i++)
	{
		int c, k, j, temp;
		scanf_s("%d", &c);
		if (yt[h - 1][l - 1] < 2147483647)
		{
			l++;
			yt[0][l - 1] = c;
		}
		else
		{
			yt[h - 1][l - 1] = c;
			j = h - 1; k = l - 1;
			while (j > 0 && k > 0 && (yt[j][k] < yt[j - 1][k] || yt[j][k] < yt[j][k - 1]))
			{
				if (yt[j][k - 1] > yt[j - 1][k])
				{
					temp = yt[j][k];
					yt[j][k] = yt[j][k - 1];
					yt[j][k - 1] = temp;
					k--;
				}
				else
				{
					temp = yt[j][k];
					yt[j][k] = yt[j - 1][k];
					yt[j - 1][k] = temp;
					j--;
				}
			}
			if (j == 0)
			{
				while (k > 0 && yt[j][k] < yt[j][k - 1])
				{
					temp = yt[j][k];
					yt[j][k] = yt[j][k - 1];
					yt[j][k - 1] = temp;
					k--;
				}
			}
			else if (k == 0)
			{
				while (j > 0 && yt[j][k] < yt[j - 1][k])
				{
					temp = yt[j][k];
					yt[j][k] = yt[j - 1][k];
					yt[j - 1][k] = temp;
					j--;
				}
			}
		}
	}
	for (int i = 0, j = 0;;)
	{
		if (yt[i][j] < 2147483647)
		{
			printf("%d ", yt[i][j]);
			j++;
		}
		else
		{
			printf("-1");
			j = 0; i++;
			if (yt[i][j] < 2147483647) printf(" ");
			else { printf("\n"); break; }
		}
	} //插入

	for (int i = 0; i < N3; i++)
	{
		int b, k, j, temp;
		scanf_s("%d", &b);
		for (k = l - 1, j = 0; k > -1, j < h;)
		{
			if (yt[j][k] == b) break;
			else if (b < yt[j][k]) k--;
			else j++;
		}
		yt[j][k] = 2147483647;
		while (yt[j][k + 1] < yt[j][k] || yt[j + 1][k] < yt[j][k])
		{
			if (yt[j][k + 1] < yt[j + 1][k])
			{
				temp = yt[j][k];
				yt[j][k] = yt[j][k + 1];
				yt[j][k + 1] = temp;
				k++;
			}
			else if (yt[j][k + 1] > yt[j + 1][k])
			{
				temp = yt[j][k];
				yt[j][k] = yt[j + 1][k];
				yt[j + 1][k] = temp;
				j++;
			}
		}
	}
	for (int i = 0, j = 0;;)
	{
		if (yt[i][j] < 2147483647)
		{
			printf("%d ", yt[i][j]);
			j++;
		}
		else
		{
			printf("-1");
			j = 0; i++;
			if (yt[i][j] < 2147483647) printf(" ");
			else { printf("\n"); break; }
		}
	} //删除

	return 0;
}