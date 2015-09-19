#include "pidcontrol.h"
#include <math.h>
//#include <ctime>
#include <limits>
#include<iostream>
#include <stdlib.h>



PIDControl::PIDControl()
{
    setKP(1.1);
    setKD(2);
    setKI(7);
    setFreq(10); //We set 10Hz minimum
    deltaT=0.1;
    // desired =1000;

    filtcount=0;
    anti_w=50;


    this->setLimit(-5000,5000);
    this->start = std::clock();
    Error=IError=std::numeric_limits<double>::max();
    //  this->filtered_error_deriv.at(0)=0;


}


void PIDControl::setKP(double Kp)
{

    this->KP=Kp;
}


void PIDControl::setKI(double Ki)
{

    this->KI=Ki;
}


void PIDControl::setKD(double Kd)
{
    this->KD=Kd;

}


double PIDControl::getNFB()
{

    return this->NFB;
}

void PIDControl::setNFB(double value)
{

    this->NFB=value;
}



void PIDControl::setAntiW(float value){

    this->anti_w=value;
}



void PIDControl::setDesired(double value)
{

    this->desired=value;

}
void PIDControl::calcError(double source, double response){

    Error=source-response;


    e2=e1;
    e1=e0;
    e0=Error;

    //DError=filtered_error_deriv0;

    IError+=Error*deltaT;


    // Apply anti-windup to limit the size of the integral term
    if ( IError > abs( anti_w ) )
    { IError = abs(anti_w);
    }
    if (IError < -abs( anti_w ) )
    {     IError = -abs(anti_w);
    }

}

void PIDControl::setFreq(int freq)
{

    this->Freq=freq;

}

int PIDControl::getFreq(){
    return this->Freq;
}

double  PIDControl::lpFilter(){

    //this filter code was adopted from a ROS package

    //float c=1/tan( (Freq*6.2832)*deltaT/2 );
    float c = 1.0;
    fe2 = fe1;
    fe1=fe0;
    fe0= (1/(1+c*c+1.414*c))*(e2+2*e1+e0-(2-1.414)*fe2);

    ed2=ed1;
    ed1=ed0;
    ed0=(e0-e1)/deltaT;



    filtered_error_deriv2= filtered_error_deriv1;
    filtered_error_deriv1= filtered_error_deriv0;


    if(this->filtcount >2)
    {

        filtered_error_deriv0=(1/(1+c*c+1.414*c))*(ed2+2*ed1+ed0-(2-1.414)*filtered_error_deriv2);

        filteredValue=filtered_error_deriv0;
    }

    else{

        filtcount++;
    }

    return filteredValue;
}


double PIDControl::getU()
{
    return this->U;

}


void PIDControl::setLimit(double min , double max){

    this-> lowLimit=min;
    this-> highLimit=max;
}

double PIDControl::spin(){


    //double ms =(std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);

    //deltaT=ms-previousT;

    deltaT=0.1;

    calcError(this->desired,this->getNFB());

    //Calculating Controls
    U = KP*(Error)+ KI*(IError)+KD*(lpFilter());


    //Clamping the Control

    if(U>highLimit)
    { this->U=highLimit;
    }
    if(U<lowLimit)
    {    this->U=lowLimit;

    }

//    previousT+=deltaT;

    return U;

}




