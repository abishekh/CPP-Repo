#include<iostream.h>
#include<iomanip.h>
#include<process.h>
#include<conio.h>
#include<math.h>

double g(double x)
{
	return(pow(double(2.0),double(x))-3);
}

void main()
{
	float x1,x2,epsilon,relativeerror;
	int i,n;
	clrscr();
	cout<<"Enter the initial approximation: ";
	cin>>x1;
	cout<<"Enter the numbers of iterations: ";
	cin>>n;
	cout<<"Enter the prescribed tolerance: ";
	cin>>epsilon;

	for(i=1;i<=n;i++)
	{
		x2=g(x1);
		relativeerror=fabs((x2-x1)/x2);
		x1=x2;
		if(relativeerror<=epsilon)
		{
			cout<<setprecision(4);
			cout<<"\nRoot converges in "<<i<<" iterations\n";
			cout<<"Approximate root= "<<x2;
			getch();
			exit(0);
		}
	}
	cout<<"\nSolution does not converge in "<<n<<" iterations"<<endl;
}