#include "stdafx.h"

double firstf(double alfa)
{
	return (cos(alfa) + sin(alfa) + cos(3 * alfa) + sin(3 * alfa));
}
double secondf(double alfa)
{
	return (2 * M_SQRT2*cos(alfa)*sin(M_PI* 1/ 4 + 2 * alfa));
	

}
bool F(bool a, bool b, bool c)
{
	return !(!a && b) || !c;

}
bool G(bool a, bool b, bool c)
{
	return a || !b || !c;

}
double FUNCTION(double x)
{
	if (x < -10 || x>8)
		return 0;
	if ( x <= -8)
		return -3 ;
	if ( x <= -3)
		return 3. / 5* x + 3;
	if ( x <= 3)
		return -sqrt(9 - x *x);
	if ( x <= 5)
		return x-3;
	 return 3;
}
double inside(double x, double y, double R)
{
	if (x <= 0 && y >= 0 && y*y <= R*R-x*x)
		return 1;
	if (y>= -2* x && y >= -x*2 -R/2 && y<=0 && x>=0)
		return 1;
	return 0;
	
}