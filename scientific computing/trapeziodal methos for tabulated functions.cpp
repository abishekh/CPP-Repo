#include <iostream.h>
#include <conio.h>

void main()
{
	int i,n;
	float x[20],y[20],h,sum,integral;
	clrscr();
	h=sum=integral=0;
	cout<<"Enter the value of n: ";
	cin>>n;
	cout<<"Enter the value of h: ";
	cin>>h;

	for (i=1;i<=(n+1) ;i++ )
	{
		cout<<"Enter: the values:\n";
		cout<<"x["<<i<<"] & y["<<i<<"]\t";
		cin>>x[i]>>y[i];
	}

	sum=(y[1]+y[n+1])/2;

	for(i=2;i<n;i++)
	{
		sum+=y[i];
	}
	integral = h*sum;
	cout<<"Value of the integral is: "<<integral;
}