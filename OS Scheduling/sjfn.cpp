/*PROGRAM TO GENERATE GANTT CHART FOR PROCESS TIMING*/
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define MAX 10				// Maximum number of processes

int Twt,Ttt,Wt[10],n,i,wt[10];
float Att,Awt;
char pname[20][20],d[20][20];

void main()
{
	int w,t,B[10],Tt=0;
    char S[10];
    int temp1,temp,i,j,q;
	int bt[10],at[10],b[10];

	char choice;
	clrscr();
	printf("\nProgram to generate Gantt Chart for SJF Non-Preemptive CPU Scheduling");
	printf("\n\nMENU");
	printf("\n1. SJF non premptive with same arrival time");
	printf("\n2. SJF non premptive with different arrival time");
	printf("\nEnter your choice: ");
	for(choice=0;choice<'1'||choice>'2'; )
		choice=getch();
	switch(choice)
	{
		case '1':
				clrscr();
				printf("\nEnter the number of processes: ");
				for(n=0;n<=0||n>=50; )
				{
					scanf("%d",&n);
					if(n<=0||n>=MAX)
					  {	printf("Value should be between 1 & ");
                  printf("%d",MAX);
                  printf(". Enter again: ");
                  }
            }
					for(i=1;i<=n;i++)
					{
						fflush(stdin);
						printf("\n\nEnter the process name: ");
						scanf("%s",&pname[i]);
						printf("\nEnter The BurstTime for Process %s :	",pname[i]);
						scanf("%d",&bt[i]);

				}
				wt[0]=0;
				Twt=0;
				for(i=1;i<=n;i++)
				{
					B[i]=bt[i];
					printf("Burst time for process p",i,":	");
					printf("%d",B[i]);
				}
				for(i=n;i>=1;i--)
				{
					for(j=1;j<=n;j++)
					{
						if(B[j-1]>B[j])
						{
							temp=B[j-1];
							B[j-1]=B[j];
							B[j]=temp;
							strcpy(d[j-1],pname[j-1]);
							strcpy(pname[j-1],pname[j]);
							strcpy(pname[j],d[j-1]);
						}
					}
				}

				Wt[1]=0;
				for(i=2;i<=n;i++)
				{
					Wt[i]=B[i-1]+Wt[i-1];
				}
				//calculating Average Weighting Time
				for(i=1;i<=n;i++)
				{
					Twt=Twt+Wt[i];
				}
				printf("\nTotal Waiting time: ",Twt);
				Awt=(float)Twt/n;
			    printf("\n\nAverageWaiting Time=%3.2f ms",Awt);
             q=1;
			 	break;
		case '2':
				clrscr();
				printf("\nEnter the number of processes: ");
				for(n=0;n<=0||n>=50; )
				{
					scanf("%d",&n);
					if(n<=0||n>=MAX)
					  {	printf("Value should be between 1 & ");
                  printf("%d",MAX);
                  printf(". Enter again: ");
                  }
            }

				for(i=1;i<=n;i++)
				{
					fflush(stdin);
					printf("\n\nEnter the process name: ");
					scanf("%s",&pname[i]);
					printf("\nEnter The BurstTime for Process %s :	",pname[i]);
					scanf("%d",&bt[i]);
					printf("\nEnter the Arrival Time for Process %s :	",pname[i]);
					scanf("%d",&at[i]);
				}
				Twt=Ttt=0;
				w=0;
				for(i=1;i<=n;i++)
				{
					B[i]=bt[i];
					S[i]='T';
					Tt=Tt+B[i];
				}
				for(i=1;i<=n;i++)
				{
					for(j=3;j<=n;j++)
					{
						if(B[j-1]>B[j])
						{
							temp=B[j-1];
							temp1=at[j-1];
							B[j-1]=B[j];
							at[j-1]=at[j];
							B[j]=temp;
							at[j]=temp1;
							strcpy(d[j-1],pname[j-1]);
							strcpy(pname[j-1],pname[j]);
							strcpy(pname[j],d[j-1]);
						}
				     }
				}
				  //For the 1st process
				Wt[1]=0;
				w=w+B[1];
				t=w;
				S[1]='F';
				while(w<Tt)
				{
					i=2;
					while(i<=n)
					{
						if(S[i]=='T'&&at[i]<=t)
						{
							Wt[i]=w;
							S[i]='F';
							w=w+B[i];
							t=w;
							i=2;
						}
						else
						i++;
					}
				}
				for(i=1;i<=n;i++)
				{
					Twt=Twt+(Wt[i]-at[i]);
					Ttt=Ttt+((Wt[i]+bt[i])-at[i]);
				}
				printf("\nTotal Waiting time: ",Twt);
				Att=(float)Ttt/n;
			    Awt=(float)Twt/n;
			    printf("\n\nAverage Turn around time=%3.2f ms ",Att);
			    printf("\n\nAverageWaiting Time=%3.2f ms",Awt);
				break;
		default: printf("Please enter the correct choice...");
				 break;
	}//end of switch
	
	printf("\n\nGANTT CHART");
	printf("\n--------------------------------------------------------------------\n");
	for(i=1;i<=n;i++)
		printf("|\t%s\t",pname[i]);
	printf("|\t\n");
	printf("\n--------------------------------------------------------------------\n");
	printf("\n");
	for(i=1;i<=n;i++)
		printf("%d\t\t",Wt[i]);
      if(q=1)
       printf("%d",Wt[n]);
      else
	printf("%d",Wt[n]+bt[n]);
	printf("\n--------------------------------------------------------------------\n");
	getch();
}//end of main