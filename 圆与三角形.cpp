
#include stdio.h

int main()
{
	int n, i;
	bool inter(float r, float x0, float y0, float x[3], float y[3]);
	scanf("%d", &n);

	for (i = 0; i < n; i++) //��������
	{
		float r=0, x0=0, y0=0;
		float x[3], y[3];
		scanf("%f", &r); scanf("%f", &x0); scanf("%f", &y0); scanf("%f", &x[0]);
		scanf("%f", &y[0]); scanf("%f", &x[1]); scanf("%f", &y[1]); scanf("%f", &x[2]); scanf("%f", &y[2]);
		bool result = 0;
		for (int j = 0; j < 3; j++)
		{
			int k = (j + 1) % 3;
			float a = (x[k] - x[j])*(x[k] - x[j]) + (y[k] - y[j])*(y[k] - y[j]);
			float b = 2 * (x[j] - x0)*(x[k] - x[j]) + 2 * (y[j] - y0)*(y[k] - y[j]);
			float c = (x[j] - x0)*(x[j] - x0) + (y[j] - y0)*(y[j] - y0) - r * r;
			if ((b*b - 4 * a*c) >= 0)
			{
				if (c >= 0 && (a + b + c) >= 0 && b <= 0 && b >= -2 * a) {
					result = 1; break;
				}
				else if (c*(a + b + c) <= 0) {
					result = 1; break;
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
}