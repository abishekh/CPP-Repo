#include<iostream.h>
#include<conio.h>

#define MAX 10

int A[10],i,Wt[10],B[10],Tt=0,temp,n,bt[10],q,tat[10];
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
   	cout<<"Enter the burst time for process P #"<<i<<": ";
    cin>>bt[i];
   }
   for(i=1;i<=n;i++)
   {
   	cout<<"Enter the arrival time for process P #"<<i<<": ";
      cin>>A[i];
   }
   cout<<"Enter the time quantum: ";
   cin>>q;
}

void calc()
{
	for(i=1;i<=n;i++)
	{
		B[i]=bt[i];
		Wt[i]=0;
		S[i]='T';
		Tt=Tt+B[i];
	}
   int tq=q;
	int t=0;
   temp=i=1;
	while(t<Tt)
	{
   	if(S[i]!='F' && A[i]<=t)
      {
   		q=tq;
   		if(temp!=i)
         {
            Wt[i]=t-(bt[i]-B[i]);
            temp=i;
         }
   		if((B[i]-q)<0)
             q=B[i];
         B[i]=B[i]-q;
			if(B[i]==0)
				S[i]='F';
			t=t+q;
         i++;
         if(i>n)
         	i=1;
      }
      else
      {
      	i++;
         if(i>n)
         	i=1;
      }

	}
}

void print()
{
	for(i=1;i<=n;i++)
   {
        cout<<"\n\nWaiting time for process P #"<<i<<": "<<(Wt[i]-A[i]);
        Twt+=(Wt[i]-A[i]);
		tat[i]=Wt[i]+bt[i];
		cout<<"\nThe turnaround time for each process is: "<<tat[i];
   }
   Awt=Twt/n;
   cout<<"\n\nThe average waiting time is: "<<Awt;
}


void main()
{
	
	getdata();
	calc();
	print();
    getch();
}