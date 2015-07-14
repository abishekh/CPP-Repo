#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
#include<stdio.h>

inline float f(float x)
{
	return(pow(x,5.0)+(5.0*x)+1);
}

void main()
{
	float x1,x2,epsilon,x3;
	clrscr();
   cout<<"This program is calculating the root of the following Equation using  Bisection method. \n";
   cout<<"x^5 + 5x + 1 = 0\n\n"; 
	cout<<"Enter the first point of the search interval: ";
	cin>>x1;
	cout<<"Enter the second point of the search interval: ";
	cin>>x2;
	cout<<"Enter the prescribed tolerance: ";
	cin>>epsilon;

	do
	{
		x3=(x1+x2)/2;
		if(f(x1)*f(x2)<0)
			x2=x3;
		else
			x1=x3;
	}
	while (fabs(double(x1-x2)>epsilon));
	cout<<"Approximation root is = "<<setprecision(4)<<x3<<endl;
	getch();
}