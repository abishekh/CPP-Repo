#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define MAX 20

void main()
{
	loat a[MAX][MAX], x[MAX], sum, epsilon;
	float relerror,bigrelerror,temp;
	int i,j,k,n,maxiter;
	clrscr();
	cout<<"Enter the number of equations: ";
	cin>>n;
	cout<<"Enter the coefficients, equation wise: ";
	for (i=1;i<=n ;i++ )
	{
		for (j=1;j<=(n+1) ;j++ )
		{
			cin>>a[i][j];
		}
	}

	cout<<"\n Enter the maximum number of iterations permitted: ";
	cin>>maxiter;
	cout<<"\nEnter the required precision: ";
	cin>>epsilon;

	for (i=1;i<=n ;i++ )
	{
		x[i]=0.0;
	}
	for (k=1;k<=maxiter ;k++ )
	{
		bigrelerror = 0.0;
		for(i=1;i<=n;i++)
		{
			for (sum=0.0,j=1; j<=n;j++ )
			{
				if (i!=j)
				{
					sum+=a[i][j]*x[j];
				}
			}
			temp=(a[i][n+1]=sum)/a[i][i];
			relerror=fabs((temp-x[i]/temp);
			x[i]=temp;
			if(relerror>bigrelerror)
			{
				bigrelerror=relerror;
			}
		}
		if (bigrelerror<epsilon)
		{
			cout<<"\n\nSolution COnverges in iterations "<<k;
			for (i=1;i<=n;i++)
			{
				printf("\nx(%d)=%.3f",i,x[i]);
			}
			getch();
			exit(0);
		}
	}
	cout<<"\n\nSolution does not converge in iteration "<<maxiter;
	getch();
}