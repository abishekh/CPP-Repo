#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream.h>
//GLOBAL VARIABLES - DECLARATION
int Twt,Ttt,A[20],Wt[20],n,Bu[20];
float Att,Awt;
char pname[20][20],q[20][20];
//FUNCTION DECLARATIONS
void Getdata();
void Gantt_chart();
void Sjf();
//GETTING THE NUMBER OF PROCESSES AND TH
//     E BURST TIME AND ARRIVAL TIME FOR EACH P
//     ROCESS
void Getdata()


    {
    	int i;
      cout<<"Enter the number of the processes: ";
      cin>>n;
    	for(i=1;i<=n;i++)


        	{
        		//fflush(stdin);
        		cout<<"\n\nEnter the process name: ";
        		cin>>pname[i];
        		cout<<"\n Enter The BurstTime for Process	"<<pname[i]<<": ";
        		cin>>Bu[i];
        		cout<<"\n Enter the Arrival Time for Process "<<pname[i]<<": ";
        		cin>>A[i];
        	}
    }

    //DISPLAYING THE GANTT CHART
    void Gantt_chart()


        {
        	int i;
        	cout<<"\n\nGANTT CHART";
        	cout<<"\n--------------------------------------------------------------------\n";
        	for(i=1;i<=n;i++)
        		cout<<"|\t\t"<<pname[i];
        	cout<<"|\t\n";
        	cout<<"\n-----------------------------------------------------------\n";
        	cout<<"\n";
        	for(i=1;i<=n;i++)
        		cout<<"\t\t"<<Wt[i];
        	cout<<Wt[n]+Bu[n];
        	cout<<"\n--------------------------------------------------------------------\n";
        	cout<<"\n\n\n";
         for(i=1;i<=n;i++)
        		cout<<"|\t\t"<<q[i];
    }

    //Shortest job First Algorithm with NonP
    //     reemption
    void Sjf()


        {
        	int w,t,i,B[10],Tt=0,temp,j;
        	char S[10],c[20][20];
        	int temp1;
        	cout<<"\n\n SHORTEST JOB FIRST SCHEDULING ALGORITHM \n\n";
        	Twt=Ttt=0;
        	w=0;
        	for(i=1;i<=n;i++)


            	{
            		B[i]=Bu[i];
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
                        				temp1=A[j-1];
                        				B[j-1]=B[j];
                        				A[j-1]=A[j];
                        				B[j]=temp;
                        				A[j]=temp1;
                        				strcpy(c[j-1],pname[j-1]);
                        				strcpy(pname[j-1],pname[j]);
                        				strcpy(pname[j],c[j-1]);
                                    strcpy(q[j],pname[j]);
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
                                			if(S[i]=='T'&&A[i]<=t)


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
                                    	//CALCULATING AVERAGE WAITING TIME AND AVERAGE TURN AROUND TIME
                                    	for(i=1;i<=n;i++)


                                        	{
                                        		Twt=Twt+(Wt[i]-A[i]);
                                        		Ttt=Ttt+((Wt[i]+Bu[i])-A[i]);
                                        	}
                                        	Att=(float)Ttt/n;
                                        	Awt=(float)Twt/n;
                                        	cout<<"\n\n Average Turn around time=%3.2f ms "<<Att;
                                        	cout<<"\n\n AverageWaiting Time=%3.2f ms"<<Awt;
                                        	Gantt_chart();
                                    }

                                    void main()


                                        {
                                        	clrscr();
                                        	Getdata();
                                        	Sjf();
                                        	getch();
                                    }
