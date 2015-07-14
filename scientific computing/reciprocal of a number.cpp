#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

float sq(float x,float a)
{
	return(x-(1/a));
}

float dfsq(float x)
{
	return(1.0);
}

void main()
{
	int i,n;
	float a,x0,x1,epsilon,delta,relativeerror;
	clrscr();
	cout<<"Enter any number: ";
	cin>>a;
	cout<<"Enter the initial approximation: ";
	cin>>x0;
	cout<<"Enter the number of iterations: ";
	cin>>n;
	cout<<"Enter the prescribed tolerance: ";
	cin>>epsilon;
	cout<<"Enter the lower bound: ";
	cin>>delta;

	for(i=1;i<n;i++)
	{
		if(fabs(dfsq(x0))<=delta)
		{
			cout<<"Slope too small!!\n";
			getch();
			exit(0);
		}
	}
	x1=(float)(x0-(sq(x0,a)/dfsq(x0)));
	relativeerror=fabs((x1-x0)/x1);
	x0=x1;

	if(relativeerror>=epsilon)
	{
		cout<<"Reciprocal of the given number found is: "<<setprecision(5)<<x1;
		getch();
		exit(0);
	}
	cout<<"Solution does not converge in "<<n<<" iterations"<<endl;
	getch();
}