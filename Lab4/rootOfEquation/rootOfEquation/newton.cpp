#include "HEAD.h"

int newton(double(*fx)(double), double(*dfx)(double), double point, int k, ofstream* outputF)
{
	*outputF << "k = " << k << ',';
	*outputF << scientific << setprecision(12) << point << ',';
	*outputF << scientific << setprecision(12) << fx(point) << endl;

	if (abs(fx(point)) < ERRORLIMIT)
	{
		cout << "Complete with k = " << k << endl;
		return 0;
	}

	if (dfx(point) == 0)
	{
		cout << "ERROR: The value of the derivative function equals 0." << endl;
		return 1;
	}

	double newPoint = fx(point) / dfx(point);
	newPoint = point - newPoint;

	return newton(fx, dfx, newPoint, k + 1, outputF);
}