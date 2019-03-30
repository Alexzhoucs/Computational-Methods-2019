#include "HEAD.h"

double simpson(double(*fx)(double), double startPoint, double endPoint, int stepPower)
{
	double result = 0;
	long stepNumber = pow(2, stepPower);
	long m = stepNumber / 2;

	if (startPoint > endPoint)
	{
		cout << "ERROR in Simpson: start point is larger than end point." << endl;
		return(NULL);
	}

	double stepLength = (endPoint - startPoint) / (double)stepNumber;

	result += (fx(startPoint) + fx(endPoint));
 	for (int i = 0; i < m; i++)
		result += 4 * fx(startPoint + stepLength * (2 * i + 1));
	for (int i = 1; i < m; i++)
		result += fx(startPoint + 2 * stepLength) * 2;
	result = result * (stepLength / (double)3);
	return result;
}