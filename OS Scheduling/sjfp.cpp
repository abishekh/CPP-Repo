#include<iostream.h>
#include<conio.h>

#define MAX 10

int i,j,Wt[10],B[10],A[10],Tt=0,temp,n,bt[10],flg=0,t=0;
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
		Tt+=B[i];
		cout<<"Enter the Arrival Time for Process P #"<<i<<": ";
		cin>>A[i];
	}
}

void calc()
{
	temp=i=1;
	while(t<Tt)
	{
   		if(temp!=i)
         {
            Wt[i]=t-(bt[i]-B[i]);
            temp=i;
         }
   		B[i]-=1;
			if(B[i]==0)
				S[i]='F';
			t+=1;
         if(S[i]!='F')
         {
        	 	j=1;
         	while(j<=n)
         	{
        	 		if(S[j]!='F' && B[i]>B[j] && A[j]<=t && i!=j )
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
            if(i>n )
            {
            	i=1;
            }
            while(B[i]==0)
            	i++;
             j=1;flg=0;
             while(A[j]<=t &&j<=n && flg!=1 )
             {
					 if(B[i]>=B[j] && S[j]!='F')
                {
                  if(B[i]==B[j] && i!=j)
                  {
                  	flg=1;
                 	   i=j;
                  }
                  i=j;
                }
                j++;
             }
         }
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
   cout<<"\n\n\nThe average waiting time is "<<Awt;
}


void main()
{
	getdata();
	calc();
	print();
	getch();
}