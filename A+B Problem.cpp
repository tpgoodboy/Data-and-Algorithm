//先将输入的数据按字符数组保存每一位，再从低位到高位一次相加

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[1000], b[1000], temp[1000];
	int i, up, sum[1000], al, bl;
	cin >> a >> b;
	al = strlen(a); bl = strlen(b);
	if (al > bl)
	{
		strcpy(temp, a);
		strcpy(a, b);
		strcpy(b, temp);
		al = strlen(a); bl = strlen(b);
	}
	for (i = bl - 1; i > -1; i--)
	{
		int j = i - bl + al;
		if (j > -1) sum[i] = (int)a[j] + (int)b[i] - 96;
		else sum[i] = (int)b[i] - 48;
	}
	up = 0;
	for (i = bl - 1; i > -1; i--)
	{
		sum[i] += up;
		if (sum[i] > 9) up = 1;
		else up = 0;
		sum[i] %= 10;
	}
	if (up == 1) cout << up;
	for (i = 0; i < bl; i++)
		cout << sum[i];
	return 0;
}
