
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<conio.h>
	int gm = DETECT,gd;
	int gx,gy;
	char x_label[10],y_label[10];
int i,Wt[10],B[10],Tt=0,temp,n,Bu[10],q,x[10],p,buf;
char S[20],tem[20],tem2[20];
float Twt=0.0,Awt,y[10],k;
float calc (int q)
{
     int tq=q;
     int t=0;
     temp=i=1;
    
     while(t<Tt)
     {
	if(S[i]!='F' )
	{
		q=tq;
		if(temp!=i)
		{
			Wt[i]=t-(Bu[i]-B[i]);
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
			i++;
	}
     }
	for(i=1;i<=n;i++)
	     Twt+=Wt[i]+Bu[i];

	Awt=Twt/n;
        
	return(Awt*25);

}
void initialise()
{
	Tt=0;
	for(i=1;i<=n;i++)
        {
	        B[i]=Bu[i];
		Wt[i]=0;
		S[i]='T';
		Tt=Tt+B[i];
                Twt=0.0;
	}
}
void main()
{
	clrscr();
	printf("Enter the number of process ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the burst time for process P %d ",i);
		scanf("%d",&Bu[i]);
	}
	printf("Enter the number of time quantum");
        scanf("%d",&p);
	for(i=1;i<=p;i++)
	{
		printf("Enter the time quantum");
		scanf("%d",&x[i]);
	}
	initialise();
	for(k=1;k<=p;k++)
        {
		y[k]=calc(x[k]);
		initialise();
        }
	for(i=1;i<=p;i++)
	{
		x[i]=x[i]*50;
	}
	clrscr();
	initgraph(&gm,&gd,"c:\\tc");
	setbkcolor(BLACK);
	cleardevice();
	gx = getmaxx();
	gy = getmaxy() - 30;
	settextstyle(2,1,4);
	outtextxy(gx-627,gy - 185,"Avg Turn Around Time");
	settextstyle(DEFAULT_FONT,0,1);
	outtextxy(gx-250,gy+22,"Time Quantum");
	line(30,0,30,gy+30);
	line(0,gy,gx,gy);
	tem[0]=49;
	for(i=1;i<=12;i++)
	{
		outtextxy(25+(i*50),gy+1,"|");
		outtextxy(25+(i*50),gy+10,tem);
		buf=atoi(tem);
		buf+=1;
		itoa(buf,tem,10);
	}
        tem2[0]=48;
	for(i=1;i<=20;i++)
	{
		outtextxy(23,gy-5-(i*25),"-");
                buf=atoi(tem2);
		buf+=1;
                itoa(buf,tem2,10);
		if(buf<10)
			outtextxy(16,gy-5-(i*25),tem2);
		else
			outtextxy(7,gy-5-(i*25),tem2);
	}
	outtextxy(25+x[1],gy-5-y[1],"*");
	for(i=2;i<=p;i++)
	{
		outtextxy(25+x[i],gy-5-y[i],"*");

	}
	getch();
	closegraph();
}
	
	