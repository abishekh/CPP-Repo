#include<iostream.h>
#include<conio.h>

#define MAX 10

int i,Wt[10],bt[10],Tt=0,n,A[10],Pr[10],j,max=0;
char S[20];
float Twt=0.0,Awt;
   

void getdata()
{
	cout<<"Enter the number of processes: ";
	for(n=0;n<=0||n>=10; )
	{
		cin>>n;
		if(n<=0||n>=MAX)
			cout<<"Value should be between 1 & "<<MAX<<". Enter again: ";
	}
   for(i=1;i<=n;i++)
   {
   	cout<<"\nEnter the burst time for process P #"<<i<<": ";
      cin>>bt[i];
   }
	for(i=1;i<=n;i++)
	{
		Wt[i]=0;
		S[i]='T';
		Tt=Tt+bt[i];
      cout<<"\nEnter the arrival time for process P #"<<i<<": ";
      cin>>A[i];
      if(max<A[i])
      	max=A[i];
	}
	for(i=1;i<=n;i++)
   {
   	cout<<"\nEnter the priority for process P #"<<i<<": ";
      cin>>Pr[i];
   }
}

void calc()
{
	int t=0,w=bt[1];
   Wt[1]=0;
   t=w;
   S[1]='F';
   j=1;
	while(j<max)
	{
      i=2;
   	while(i<=n)
      {
        	if(A[i]<t && Pr[i]==j && S[i]!='F')
       	{
       		Wt[i]=w;
            w=bt[i]+Wt[i];
            t=w;
       		S[i]='F';
       	}
         i++;
       }
       j++;
	}
}

void print()
{
	for(i=1;i<=n;i++)
   {
        cout<<"\nWaiting time for process P #"<<i<<": "<<(Wt[i]-A[i]);
        Twt+=(Wt[i]-A[i]);
   }
   Awt=Twt/n;
   cout<<"\n\n\nThe average waiting time is: "<<Awt;
}

void main()
{
	getdata();
	calc();
	print();
	getch();
}