#include "HEAD.h"

int secant(double(*fx)(double), double point1, double point2, int k, ofstream* outputF)
{
	if (k == 0)
	{
		*outputF << "k = " << k << ',';
		*outputF << scientific << setprecision(12) << point1 << ',';
		*outputF << scientific << setprecision(12) << fx(point1) << endl;
	}
	*outputF << "k = " << k + 1 << ',';
	*outputF << scientific << setprecision(12) << point2 << ',';
	*outputF << scientific << setprecision(12) << fx(point2) << endl;

	if (abs(fx(point2)) < ERRORLIMIT)
	{
		cout << "Complete with k = " << k + 1 << endl;
		return 0;
	}

	if (fx(point1) == fx(point2))
	{
		cout << "ERROR: The secant is parallel to the x-axis." << endl;
		return 1;
	}

	double newPoint = fx(point2) * (point2 - point1);
	newPoint = newPoint / (fx(point2) - fx(point1));
	newPoint = point2 - newPoint;

	return secant(fx, point2, newPoint, k + 1, outputF);
}