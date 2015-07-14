#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <math.h>

float f(float x)
{
	return exp(-.5*x);
}

void main()
{
	int i,n;
	float a,b,h,sum,integral;
	clrscr();
	cout<<"Enter the lower limit: ";
	cin>>a;
	cout<<"Enter the upper limit: ";
	cin>>b;
	cout<<"Enter the number of intervals: ";
	cin>>n;

	h=(b-a)/n;
	sum=(f(a)+f(b)/2.0);
	for(i=1;i<=(n-1);i++)
	{
		sum=sum+f(a+i*h);
	}
	integral=h*sum;
	cout.setf(ios::showpoint);
	cout<<setprecision(4)<<"Value of the integral is "<<integral<<endl;
	getch();
}