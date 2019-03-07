#include "HEAD.h"

void main()
{
	FILE *f;
	fopen_s(&f, "resule.txt", "w");
	float x = 1;
	//cout << sizeof(float);
	/*cout << "f(x) = " << fx(x) << endl;
	cout << "g(x) = " << gx(x) << endl;
	printf("%.12e \n", fx(x));
	printf("%.12e \n", gx(x));
*/
	for (int i = 0; i < 10; i++)
	{
		x = pow(8, -i - 1);
		cout << endl << endl << "000" << i << endl;
		printf("%.11e \n", x);
		fprintf_s(f, "%.11e \t", x);
		printf("%.11e \n", fx(x));
		fprintf_s(f, "%.11e \t", fx(x));
		printf("%.11e \n", gx(x));
		fprintf_s(f, "%.11e \n\n", gx(x));
	}

	fclose(f);
	getchar();
}

float fx(float x)
{
	float result;
	result = sqrt(pow(x, 2) + 4) - 2;
	return result;
}

float gx(float x)
{
	float result;
	result = sqrt(pow(x, 2) + 4) + 2;
	result = pow(x, 2) / result;
	return result;
}