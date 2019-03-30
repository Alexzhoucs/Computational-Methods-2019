#include <iostream>
#include <fstream>
#include <math.h>

#define SIZE		12					// ¥”2^0 À„µΩ2^SIZE
#define STARTPOINT	1
#define ENDPOINT	6
#define FUNCTION	(sin(x))
#define STANDARDVALUE	(cos(1) - cos(6))

using namespace std;

double fx(double x);
double trapezoid(double(*fx)(double), double startPoint, double endPoint, int stepPower);
double errorOrder(double thisError, double lastError);
double simpson(double(*fx)(double), double startPoint, double endPoint, int stepPower);

#pragma once

