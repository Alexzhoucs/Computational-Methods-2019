#include "HEAD.h"

int main()
{
	double standardValue = STANDARDVALUE;
	double lastErrorValue;

	/*cout << standardValue << endl;
	cout << scientific << standardValue << endl;*/

	ofstream outputFile;
	outputFile.open("result.csv", ios::binary);

	outputFile << "trapzoid" << endl;
	outputFile << " ," << "»ý·ÖÖµ" << "," << "Îó²î" << "," << "Îó²î½×" << endl;
	for (int i = 0; i < SIZE + 1; i++)
	{
		cout << "k = " << i << " running." << endl;
		double result = trapezoid(&fx, STARTPOINT, ENDPOINT, i);
		int j = 0;
		double errorValue = standardValue - result;
		outputFile << "k=" << i << "," << result << ",";
		outputFile << scientific << errorValue << ",";
		if (i > 0)
		{
			double orderOfError = errorOrder(errorValue, lastErrorValue);
			outputFile << orderOfError;
		}
		outputFile << endl;
		lastErrorValue = errorValue;
	}
	
	outputFile.close();
	getchar();

	return 0;
}

double fx(double x)
{
	double value = FUNCTION;
	return value;
}

double errorOrder(double thisError, double lastError)
{
	double d;		//order of error
	d = log(thisError / lastError);
	d = d / log((double)2);
	d *= (-1);
	return d;	
}