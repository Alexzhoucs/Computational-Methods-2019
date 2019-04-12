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

double derivativeFx(double x)
{
	double result = 0;
	result += 8 * pow(x, 3);
	result += 72 * pow(x, 2);
	result += 122 * x;
	result -= 16;

	return result;
}


void main()
{
	/*cout << fx(0) << endl << fx(1) << endl << endl;
	cout << derivativeFx(0) << endl << derivativeFx(1) << endl << endl;
	double test = ERRORLIMIT;
	cout << "test = " << test << endl;
	cout << "sci = " << scientific << test << endl;
	cout << "sci5 = " << scientific << setprecision(5) << test << endl;
*/

	ofstream outputFile;
	outputFile.open("result.csv", ios::binary);

	outputFile << "Newton:" << ',' << "x = 0" << endl;
	outputFile << "迭代步数k" << ',' << "x_k" << ',' << "f(x_k)" << endl;

	int result = newton(fx, derivativeFx, 0, 0, &outputFile);
	if (result)
	{
		cout << "ERROR in newton: error code = " << result << endl;
		getchar();
		return;
	}


	outputFile << endl << endl << "Newton:" << ',' << "x = 1" << endl;
	outputFile << "迭代步数k" << ',' << "x_k" << ',' << "f(x_k)" << endl;

	result = newton(fx, derivativeFx, 1, 0, &outputFile);
	if (result)
	{
		cout << "ERROR in newton: error code = " << result << endl;
		getchar();
		return;
	}

	outputFile << endl << endl << "Secant:" << ',' << "X0 = 0" << ',' << "X1 = 0.1" << endl;
	outputFile << "迭代步数k" << ',' << "x_k" << ',' << "f(x_k)" << endl;
	result = secant(fx, 0, 0.1, 0, &outputFile);
	if (result)
	{
		cout << "ERROR in secant: error code = " << result << endl;
		getchar();
		return;
	}

	outputFile << endl << endl << "Secant:" << ',' << "X0 = 0.5" << ',' << "X1 = 1" << endl;
	outputFile << "迭代步数k" << ',' << "x_k" << ',' << "f(x_k)" << endl;
	result = secant(fx, 0.5, 1, 0, &outputFile);
	if (result)
	{
		cout << "ERROR in secant: error code = " << result << endl;
		getchar();
		return;
	}



	getchar();
}