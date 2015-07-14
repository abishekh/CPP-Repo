#include<iostream.h>
#include<conio.h>

#define MAX 10

int i,j,Wt[10],B[10],A[10],Tt=0,temp,n,bt[10],Pr[10],flag=0,t=0;
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
   cout<<endl;
   for(i=1;i<=n;i++)
   {
   		cout<<"Enter the burst time for process P #"<<i<<": ";
		cin>>bt[i];
   }
   cout<<endl;
	for(i=1;i<=n;i++)
	{
		B[i]=bt[i];
		Wt[i]=0;
		S[i]='T';
		Tt=Tt+B[i];
		cout<<"Enter the Arrival Time for process P #"<<i<<": ";
		cin>>A[i];
	}
   cout<<endl<<endl;
   for(i=1;i<=n;i++)
   {
		cout<<"Enter the priority for process P #"<<i<<": ";
		cin>>Pr[i];
   }
}

void calc()
{
	temp=i=1;
	while(t<Tt)
	{
   		//cout<<"\n"<<B[i]<<"\t"<<i;
   		if(temp!=i)
         {
            Wt[i]=t-(bt[i]-B[i]);
            temp=i;
         }
   		B[i]=B[i]-1;
		if(B[i]==0)
			S[i]='F';
		t=t+1;
        if(S[i]!='F')
        {
        	j=1;
         	while(j<=n)
         	{
        	 	if(S[j]!='F' && A[j]<=t && i!=j && Pr[j]==i )
         		{
					i=j;
         		}
         		else
         			j++;
         	}
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
	cout<<endl;
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