#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>

float g(float y)
{
	return(pow(y,2.0)+(8.0*y)+15);
}

void main()
{
	int i,n;
	float a,b,r[20],y[20],sum,integral;
	clrscr();
	cout<<"Enter the number of points: ";
	cin>>n;
	cout<<"Enter the lower limit: ";
	cin>>a;
	cout<<"Enter the upper limit: ";
	cin>>b;

	for (i=1;i<=n ;i++ )
	{
		cout<<"Enter: ";
		cout<<"x["<<i<<"]";
		cin>>r[i];
	
		cout<<"Enter: ";
		cout<<"y["<<i<<"]";
		cin>>y[i];
	}

	sum=0;
	for (i=1;i<=n;i++)
	{
	   sum+=r[i]*g(y[i]);
	}

	integral=(((b-a)/2.0)*sum);
	cout.setf(ios::showpoint);
	cout<<"Value of the integral is = "<<integral<<endl;
	getch();
}