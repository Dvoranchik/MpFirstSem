double Fallibility(double(*F)(double), double a, double b, double eps);
double F(double x)
{
	return x*x*x - 2*x + 4;
}

double C(double x)
{
	return x*x*x-4;
}


double Fallibility(double(*F)(double), double a, double b, double eps, double sqr);
double Digit(const char*arr);
int Lenghtplus(char* arr);
double Summ(const char *str1,const char *str2,const char *str3);
int Summ(int a, int b);