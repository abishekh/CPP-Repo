#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>

float f(float x)
{
	return(pow(x,3.0)-(2.0*x)-5);
}

void main()
{
	float x1,x2,epsilon,x3,x3m,delta,f1,f2,f3;
	clrscr();
	cout<<"Enter the first point of the search interval\n";
	cin>>x1;
	cout<<"Enter the second point of the search interval\n";
	cin>>x2;
	cout<<"Enter the prescribed tolerance\n";
	cin>>epsilon;
	cout<<"Enter the permissible lower limit on slope\n";
	cin>>delta;
	f1=f(x1);
	f2=f(x2);

	if((f1*f2)>0)
	{
		cout<<"\nInitial approximations are unstable\n";
		exit(0);
	}
	do
	{
		if(fabs(f2-f1)<=delta)
		{
			cout<<"Slope of the function becomes too small\n";
			exit(0);
		}
		x3m=x3;
		x3=((x1*f2)-(x2.f1)/(f2-f1);
		f3=f(x3);
		if((f1*f3)<0)
		{
			x2=x3;
			f2=f3;
		}
		else
			x1=x3;
			f1=f3;
	}
	while (fabs(double((x3-x3m)/x3)>epsilon));
	cout<<"Approximation root is = "<<x3<<endl;
	getch();
}