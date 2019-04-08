#include "HEAD.h"

double fx(double x)
{
	double result = 0;
	result += 2 * pow(x, 4);
	result += 24 * pow(x, 3);
	result += 61 * pow(x, 2);
	result -= 16 * x;
	result += 1;
	
	return result;
}


void main()
{
	cout << fx(0) << endl << fx(1);



	getchar();
}