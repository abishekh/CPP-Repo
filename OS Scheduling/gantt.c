/*PROGRAM TO GENERATE GANTT CHART FOR PROCESS TIMING*/
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>

#define MAXNUMP 49
#define TOPDROP 200
#define TROUGHHEIGHT 50
#define TROUGHLENGTH 500

void initialize(void);
void drawganttchart(int [],int ,int ,float );
void restore(void);

int color=1;

void main()
{
	int i,n;
	int prtime[50],waittime[50];
	float totwaittime,avgtime;
	char choice,col;
	clrscr();
	cout<<endl<<"Gantt Chart Generation Program";
	cout<<endl<<endl<<"MENU";
	cout<<endl<<"1. Use Demo Data"<<endl<<"2. Enter Custom Data"<<endl<<"Enter your choice: ";
	for(choice=0;choice<'1'||choice>'2'; )
		choice=getch();
	cout<<choice;
	cout<<endl;
	switch(choice)
	{
		case '1':
			n=3;
			prtime[0]=10;
			prtime[1]=5;
			prtime[2]=2;
			cout<<endl<<"Number of processes: "<<n;
			cout<<endl<<endl<<"Time required for each process:";
			for(i=0;i<n;i++)
				cout<<endl<<"Process "<<i<<": "<<prtime[i];
			cout<<endl;
			break;
			case '2':
			cout<<endl<<"Enter the number of processes: ";
			for(n=0;n<=0||n>=50; )
			{
				cin>>n;
				if(n<=0||n>=MAXNUMP)
					cout<<"Value should be between 1 & "<<MAXNUMP<<". Enter again: ";
			}
			for(i=0;i<n;i++)
			{
				cout<<"Enter the time required for process "<<i<<": ";
				cin>>prtime[i];
			}
			break;
		default:
			break;
	}
	for(i=0,waittime[0]=0;i<n;i++)
		waittime[i+1]=waittime[i]+prtime[i];
	for(i=0,totwaittime=0;i<n;i++)
	{
		if(i%23==0&&i!=0)
		{
			cout<<endl<<"More...";
			getch();
			clrscr();
		}
		totwaittime=totwaittime+waittime[i];
	}
	cout<<endl<<"Waiting time for each process: ";
	for(i=0;i<n;i++)
		cout<<endl<<"Process "<<i<<": "<<waittime[i];
	cout<<endl<<endl<<"Total time required for all processes: "<<waittime[n];
	avgtime=totwaittime/n;
	cout<<endl<<"Average waiting for each process: "<<avgtime;
	cout<<endl<<endl<<"Draw the Gantt Chart in Color? Y/N: ";
	for(col='A';col!='Y'&&col!='N'&&col!='y'&&col!='n'; )
		col=getch();
	cout<<col;
	if(col=='Y'||col=='y')
		color=1;
	else
		color=0;
	initialize();
	drawganttchart(prtime,n,waittime[n],avgtime);
	restore();
	cout<<endl<<"Gantt Chart Generator Program"<<endl<<"Successful Run.";
}

void initialize(void)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
}

void drawganttchart(int prtime[],int n,int tot,float avgtime)
{
	int i,fillstyle,waittime;
	float perdis,blocklength,currstart,dragstart;
	int maxx=getmaxx(),maxy=getmaxy();
	char *title="Gantt Chart",*text="Average Waiting Time for the Processes",*presskey="Press CTRL+E or ESC to Exit...",p[25],q[25],c;
	gcvt(avgtime,5,p);
	if(color==1)
		setcolor(LIGHTRED);
	rectangle(0,0,maxx,maxy);
	rectangle(5,5,maxx-5,maxy-5);
	rectangle((maxx-TROUGHLENGTH)/2,TOPDROP,maxx-(maxx-TROUGHLENGTH)/2,TOPDROP+TROUGHHEIGHT);
	currstart=(maxx-TROUGHLENGTH)/2;
	if(color==1)
		setcolor(YELLOW);
	for(i=0,fillstyle=2,waittime=0;i<n;i++,fillstyle++,waittime=waittime+prtime[i-1])
	{
		dragstart=currstart;
		if(fillstyle>11)
			fillstyle=1;
		if(color==1)
			setfillstyle(fillstyle,i+1);
		else
			setfillstyle(fillstyle,WHITE);
		perdis=((float)prtime[i]/tot)*100;
		blocklength=(TROUGHLENGTH*perdis)/100;
		currstart=currstart+blocklength;
		bar(dragstart+1,TOPDROP+1,currstart+1,TOPDROP+TROUGHHEIGHT-1);
		line(currstart,TOPDROP,currstart,TOPDROP+TROUGHHEIGHT);
		itoa(waittime,q,10);
		if(currstart>(dragstart+textwidth(q)))
			outtextxy(dragstart,TOPDROP+TROUGHHEIGHT+5,q);
	}
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