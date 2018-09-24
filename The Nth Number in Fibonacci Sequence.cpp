#include <stdio.h>
int main()
{
	int n, i;
	scanf_s("%d", &n);
	int *a = new int[n];
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	int res[4];
	int main[4];
	for (i = 0; i < n; i++)
	{
		res[0] = 1, res[1] = 0, res[2] = 0, res[3] = 1;
		main[0] = 1, main[1] = 1, main[2] = 1, main[3] = 0;
		a[i] -= 2;
		if (a[i] == -1) printf("1\n");
		if (a[i] == 0) printf("1\n");
		while (a[i] >= 1)
		{
			int temp[4];
			if (a[i] % 2)
			{
				temp[0] = main[0] * res[0] + main[1] * res[2];
				temp[1] = main[0] * res[1] + main[1] * res[3];
				temp[2] = main[2] * res[0] + main[3] * res[2];
				temp[3] = main[2] * res[1] + main[3] * res[3];
				res[0] = temp[0]%9973; 
				res[1] = temp[1]%9973; 
				res[2] = temp[2]%9973; 
				res[3] = temp[3]%9973;
			}
			temp[0] = main[0] * main[0] + main[1] * main[2];
			temp[1] = main[0] * main[1] + main[1] * main[3];
			temp[2] = main[2] * main[0] + main[3] * main[2];
			temp[3] = main[2] * main[1] + main[3] * main[3];
			main[0] = temp[0]%9973; 
			main[1] = temp[1]%9973; 
			main[2] = temp[2]%9973; 
			main[3] = temp[3]%9973;
			a[i] = a[i] / 2;
		}
		printf("%d\n", (res[0]+res[1]) % 9973);
	}
	delete[]a;
	return 0;
}
