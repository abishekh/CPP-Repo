#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

float sq(float x, float a, int n)
{
	return(pow(x,n)-a;
}
float dfsq(float x, float n)
{
	return((n*pow(x,(n-1)));
}

void main()
{
	int i,n,m;
	float a,x0,x1,epsilon,delta,relativeerror;
	clrscr();
	cout<<"Enter any number: ";
	cin>>a;
	cout<<"Enter the value of n: ";
	cin>>m;
	cout<<"Enter the initial approximation: ";
	cin>>x0;
	cout<<"Enter the number of iterations: ";
	cin>>epsilon;
	cout<<"Enter the lower boundary: ";
	cin>>delta;

	for(i=1;i<n;i++)
	{
		if(fabs(dfsq(x0,m))<=delta)
		{
			cout<<"Slope too small!!\n";
			exit(0);
		}
	}
	x1=(float)(x0-(sq(x0,a,m)/dfsq(x0,m)));
	relativeerror=fabs((x1-x0)/x1);
	x0=x1;

	if(relativeerror>=epsilon)
	{
		cout<<"Root of the given number is: "<<setpricision(6)<<x1;
		exit(0);
	}
	cout<<"Solution does not converge in "<<n<<" iterations"<<endl;
	getch();
}