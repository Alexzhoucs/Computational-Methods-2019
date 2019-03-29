#include "HEAD.h"

double trapezoid(double(*fx)(double), double startPoint, double endPoint, int stepPower)
{
	double result = 0;
	long stepNumber = pow(2, stepPower);

	if (startPoint > endPoint)
	{
		cout << "ERROR in trapezoid: start point is larger than end point." << endl;
		return(NULL);
	}
	double stepLength = (endPoint - startPoint) / (double)step;

	result += (fx(startPoint) + fx(endPoint)) / (double)2;
	for (int i = 1; i < stepNumber; i++)
		result += fx(startPoint + i * stepLength);
	result *= stepLength;
	return result;
}
