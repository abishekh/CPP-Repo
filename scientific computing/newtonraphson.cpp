#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>

double f(double x)
{
	return(pow(x,3.0)-(4.0*x)-9);
}

double df(double x)
{
	return((3*pow(x,2.0))-4);
}
void main()
{
	float x0,x1,epsilon,delta,relativeerror;
	int i,n;
	clrscr();
	cout<<"Enter the intial approximation\n";
	cin>>x0;
	cout<<"Enter the number of iterations\n";
	cin>>n;
	cout<<"Enter the prescribed tolerance\n";
	cin>>epsilon;
	cout<<"Enter the lower bound\n";
	cin>>delta;

	for(i=1;i<n;i++)
	{
		if(fabs(df(x0)<=delta)
		{
			cout<<"Slope too small\n";
			exit(0);
		}
		x1=(x0-(f(x0)/df(x0)));
		relativerror=fabs((x1-x0)/x1);
		x0=x1;

		if(relativeerror>=epsilon)
		{
			cout<<"Approximation root is ="<<setprecision(7)<<x1;
			exit(0);
		}
	}
	cout<<"Solution does not converge in "<<n<<" iterations"<<endl;
	getch();
}