/*PROGRAM TO GENERATE GANTT CHART FOR FCFS*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10				// Maximum number of processes

void main()
{
	int i,j,n;
	int bt[10],wt[10],at[10],tat[10],q;
	float totwt,avgtime;
   char choice;
	clrscr();
	cout<<"\nProgram for FCFS CPU Scheduling alogrithm";
	cout<<"\n\nMENU";
	cout<<"\n1. FCFS with same arrival time";
	cout<<"\n2. FCFS with different arrival time";
	cout<<"\nEnter your choice: ";
	for(choice=0;choice<'1'||choice>'2'; )
		choice=getch();
	switch(choice)
	{
		case '1':
				clrscr();
				cout<<"Enter the number of processes: ";
				for(n=0;n<=0||n>=50; )
				{
					cin>>n;
					if(n<=0||n>=MAX)
						cout<<"Value should be between 1 & "<<MAX<<". Enter again: ";
				}
				cout<<"Enter the burst time(time reqd. for execution) for the following processes:\n";
				wt[0]=0;
				for(i=0;i<n;i++)
				{
					cout<<"Process  #"<<i+1<<": ";
					cin>>bt[i];
				}
				cout<<"\nThe waiting time for each process is: \n";
				for(i=0;i<n;i++)
				{
					wt[i+1]=wt[i]+bt[i];
					cout<<"Process  #"<<i+1<<": "<<wt[i]<<endl;
		
				}
            q=1;
				cout<<endl;
				break;
		case '2':
				clrscr();
				cout<<"Enter the number of processes: ";
				for(n=0;n<=0||n>=50; )
				{
					cin>>n;
					if(n<=0||n>=MAX)
						cout<<"Value should be between 1 & "<<MAX<<". Enter again: ";
				}
				cout<<"Enter the Burst time and Arrival time for the following processes:\n(0 for the first process)\n";
				wt[0]=0;
				for(i=0;i<n;i++)
				{
					cout<<"Process  #"<<i+1<<": ";
					cin>>bt[i]>>at[i];
				}
				cout<<"\nThe waiting time, turn around time for each process is: \n";
				for(i=0;i<n;i++)
				{
					wt[i]=wt[i]-at[i];
					tat[i]=wt[i]+bt[i];
					cout<<"Process  #"<<i<<": "<<wt[i]<<"\t"<<tat[i]<<endl;
					for(int j=0;j<n;j++)
					{
						wt[j+1]=wt[j]+bt[j];
					}
		
				}
				
				cout<<endl;
				break;
		default: cout<<"Please enter the correct choice...";
				 break;
	}//end of switch


	for(i=0,totwt=0;i<n;i++)
	{
		totwt=totwt+wt[i];
	}

	cout<<"\nTotal time required for all processes: "<<wt[n];
	avgtime=totwt/n;
	cout<<"\nAverage waiting for each process: "<<avgtime;
	cout<<"\n\nGANTT CHART";
	cout<<"\n-----------------------------------------------------------------\n";
	for(i=1;i<=n;i++)
		cout<<"|\tpr"<<i<<"\t";
	cout<<"|\t\n";
	cout<<"\n-----------------------------------------------------------------\n";
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<wt[i]<<"\t\t";
   if(q=1)
   	cout<<wt[n];
   else
   	cout<<wt[n]+bt[n];
	cout<<"\n-----------------------------------------------------------------\n";
	getch();
}//end of main