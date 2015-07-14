#include<iostream.h>
#include<conio.h>
void main()
{
	float result,hr,rt,tt,hm;
	cout<<"Enter the hit ratio: ";
	cin>>hr;
	hm=1-hr;
	cout<<"Enter the Main Memory access time(in nano seconds): ";
	cin>>rt;
	cout<<"Enter the TLB access time(in nano seconds): ";
	cin>>tt;
	result=(hr*(tt+rt))+(hm*((2*rt)+tt));
	cout<<"The effective access time is: "<<result<<" ns";
	getch();
}

