#include <iostream>
#include <fstream>
#include <iomanip>

#define ERRORLIMIT (1e-10)

using namespace std;


int newton(double(*fx)(double), double(*dfx)(double), double point, int k, ofstream* outputF);

