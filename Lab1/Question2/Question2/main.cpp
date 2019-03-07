#include<iostream>
#include<stdio.h>

using namespace std;

void main()
{
	double a1[] = { 4040.045551380452,  -2759471.276702747 , -31.64291531266504 ,2755462.874010974,0.0000557052996742893 };
	double a2[] = { 2755462.874010974, 4040.045551380452, 0.0000557052996742893 };
	double a3[] = { -2759471.276702747 , -31.64291531266504 };

	double result1 = 0;
	for (int i = 0; i < 5; i++)
	{
		result1 += a1[i];
	}

	double result2 = 0;
	for (int i = 4; i >= 0; i--)
	{
		result2 += a1[i];
	}

	double result3 = 0;
	for (int i = 0; i < 3; i++)
	{
		result3 += a2[i];
	}

	double temp = a3[0] + a3[1];
	result3 += temp;

	printf("%0.7e", result1);
	cout << endl;
	printf("%0.7e", result2);
	cout << endl;
	printf("%0.7e", result3);

	getchar();
}