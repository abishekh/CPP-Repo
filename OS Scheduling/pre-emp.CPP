/*PROGRAM TO GENERATE GANTT CHART FOR PROCESS TIMING*/
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>

#define MAX 10				// Maximum number of processes
#define TOPDROP 200
#define TROUGHHEIGHT 50
#define TROUGHLENGTH 500

void initialize(void);
void drawganttchart(int [],int ,int ,float );
void restore(void);

int color=1,tot;

void main()
{
	int i,j,n;
	int bt[10],wt[10],at[10];
	float totwt,avgtime;
	char choice,col;
	clrscr();
	cout<<"\nGantt Chart Generation Program";
	cout<<"\n\nMENU";
	cout<<"\n1. FCFS with same arrival time"<<"\n2. FCFS with different arrival time"<<"\nEnter your choice: ";
	for(choice=0;choice<'1'||choice>'2'; )
		choice=getch();
	cout<<choice;
	cout<<endl;
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
				cout<<"Enter the Burst time(time reqd. for execution) and Arrival time for the following processes:\n(0 for the first process)\n";
				wt[0]=0;
				for(i=0;i<n;i++)
				{
					cout<<"Process  #"<<i+1<<": ";
					cin>>bt[i]>>at[i];
				}
				cout<<"\nThe waiting time for each process is: \n";
				for(i=1;i<=n;i++)
				{
					wt[i]=wt[i-1]-at[i-1];
					cout<<"Process  #"<<i<<": "<<wt[i]<<endl;
					for(int j=0;j<n;j++)
					{
						wt[j]=wt[j]+bt[j];
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
	tot=totwt;
	cout<<"\nTotal time required for all processes: "<<wt[n];
	avgtime=totwt/n;
	cout<<"\nAverage waiting for each process: "<<avgtime;
	cout<<"\n\nDraw the Gantt Chart in Color? Y/N: ";
	for(col='A';col!='Y'&&col!='N'&&col!='y'&&col!='n'; )
		col=getch();
	cout<<col;
	if(col=='Y'||col=='y')
		color=1;
	else
		color=0;
	initialize();
	drawganttchart(bt,n,wt[n],avgtime);
	restore();
	cout<<endl<<"Gantt Chart Generator Program"<<endl<<"Successful Run.";
	getch();
}//end of main

void initialize(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"j:\\tc-300\\bgi");
}

void drawganttchart(int bt[],int n,int tot,float avgtime)
{
	int i,fillstyle,wt;
	float perdis,blocklength,currstart,dragstart;
	int maxx=getmaxx(),maxy=getmaxy();
	char *title="Gantt Chart",*text="Average Waiting Time for the Processes",*presskey="Press CTRL+E or ESC to Exit...",p[25],q[25],t[25],c;
	gcvt(avgtime,5,p);
	if(color==1)
		setcolor(LIGHTRED);
	rectangle(0,0,maxx,maxy);
	rectangle(5,5,maxx-5,maxy-5);
	rectangle((maxx-TROUGHLENGTH)/2,TOPDROP,maxx-(maxx-TROUGHLENGTH)/2,TOPDROP+TROUGHHEIGHT);
	currstart=(maxx-TROUGHLENGTH)/2;
	if(color==1)
		setcolor(YELLOW);
	for(i=0,fillstyle=2,wt=0;i<n;i++,fillstyle++,wt=wt+bt[i-1])
	{
		dragstart=currstart;
		if(fillstyle>11)
			fillstyle=1;
		if(color==1)
			setfillstyle(fillstyle,i+1);
		else
			setfillstyle(fillstyle,WHITE);
		perdis=((float)bt[i]/tot)*100;
		blocklength=(TROUGHLENGTH*perdis)/100;
		currstart=currstart+blocklength;
		bar(dragstart+1,TOPDROP+1,currstart+1,TOPDROP+TROUGHHEIGHT-1);
		line(currstart,TOPDROP,currstart,TOPDROP+TROUGHHEIGHT);
		itoa(wt,q,10);
		if(currstart>(dragstart+textwidth(q)))
		{
			outtextxy(dragstart,TOPDROP+TROUGHHEIGHT+5,q);
			//outtextxy(dragstart,TOPDROP+TROUGHHEIGHT+5,q);
		}
	}
	itoa(tot,t,10);
	outtextxy((maxx-(maxx-TROUGHLENGTH)/2)-8,TOPDROP+TROUGHHEIGHT+5,t);
	rectangle((maxx-TROUGHLENGTH)/2,TOPDROP,maxx-(maxx-TROUGHLENGTH)/2,TOPDROP+TROUGHHEIGHT);
	if(currstart<maxx-(maxx-TROUGHLENGTH)/2)
		bar(dragstart+1,TOPDROP+1,maxx-(maxx-TROUGHLENGTH)/2-1,TOPDROP+TROUGHHEIGHT-1);
	outtextxy(((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)-(textwidth(title)/2),TOPDROP+TROUGHHEIGHT-200,title);
	outtextxy(((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)-(textwidth(text)/2),TOPDROP+TROUGHHEIGHT+80,text);
	outtextxy(((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)-(textwidth(p)/2),TOPDROP+TROUGHHEIGHT+120,p);
	rectangle(((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)-(textwidth(p)/2)-10,TOPDROP+TROUGHHEIGHT+120-10,((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)+(textwidth(p)/2)+10,TOPDROP+TROUGHHEIGHT+120+textheight(p)+10);
	if(color==1)
		setcolor(GREEN);
	outtextxy(((maxx-TROUGHLENGTH)/2)+(TROUGHLENGTH/2)-(textwidth(presskey)/2),TOPDROP+TROUGHHEIGHT+190,presskey);
	for(c='A';c!=5&&c!=27;c=getch());
}

void restore(void)
{
	closegraph();
	restorecrtmode();
}