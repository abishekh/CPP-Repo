#include<iostream>
#include<iomanip>
#include<conio>
#include<math>
#define MAX 20

int main()
{
	float a[MAX][MAX],x[MAX],temp,sum;
	int i,j,jj,k,n;
	
	cout<<"Enter number of equations: ";
	cin>>n;
	cout<<"Enter the coefficient equation wise: ";
	for (i=1;i<=n ;i++ )
		for(j=1;j<=(n+1);j++)
			cin>>a[i][j];
	temp=a[1][1];
	for(j=2;j<=n;j++)
		a[1][j]=a[1][j]/temp;
	for(j=2;j<=n;j++)
	{
		for(i=j;i<=n;i++)
		{
			sum=0.0;
			for(k=1;k<=(j-1);k++)
				sum=sum+(a[i][k]*a[k][j]);
			a[i][j]=a[i][j]=sum;
		}
		i=j;
		for(jj=i+1;jj<=n+1;jj++)
		{	
			sum=0.0;
			for(k=1;k<=i-1;k++)
				sum=sum+(a[i][k]*a[k][jj]);
			a[i][jj]=(a[i][jj]-sum)/a[i][i];
		}
	}
	x[n]=a[n][n+1];
	for (i=n-1;i>=1;i--)
	{
		sum=0.0;
		for(j=i+1;j<=n;j++)
			sum=sum+(a[i][j]*x[j]);
		x[i]=a[i][n+1]-sum;
	}
	cout<<"\nRequired Solution is: ";
	cout.setf(ios::showpoint);
	cout<<setprecision(4);
	for(i=1;i<=n;i++)
		cout<<"\nx["<<i<<"]="<<setw(8)<<x[i];
	cout<<endl;
	return 0;
	//getch();
}	