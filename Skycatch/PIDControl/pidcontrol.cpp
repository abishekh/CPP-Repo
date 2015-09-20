#include "pidcontrol.h"
#include <math.h>
//#include <ctime>
#include <limits>
#include<iostream>
#include <stdlib.h>



PIDControl::PIDControl()
{
    setKP(1.13442);
    setKD(2.4533);
    setKI(1.3234566);
    setFreq(10); //We set 10Hz minimum
    deltaT=0.1;
    // desired =1000;
    filtcount=0;
    anti_w=50;
    this->setLimit(-5000,5000);
    //this->start = std::clock(); //In case we want to use system clock
    Error=IError=std::numeric_limits<double>::max();
    //  this->filtered_error_deriv.at(0)=0;
}

/*****************************************************************************
    Function Name	: setKP
    Date		: Sep. 2015
    Remarks: Used to set Proportional Gain Kp
******************************************************************************
    Input: double
    Output: double
*****************************************************************************/

void PIDControl::setKP(double Kp)
{
    this->KP=Kp;
}

/*****************************************************************************
    Function Name	: setKI
    Date		: Sep. 2015
    Remarks: Used to set Integral Gain Ki
******************************************************************************
    Input: double
    Output: double
*****************************************************************************/

void PIDControl::setKI(double Ki)
{
    this->KI=Ki;
}

/*****************************************************************************
    Function Name	: setKD
    Date		: Sep. 2015
    Remarks: Used to set Derivative Gain Kd
******************************************************************************
    Input: double
    Output: double
*****************************************************************************/

void PIDControl::setKD(double Kd)
{
    this->KD=Kd;
}

/*****************************************************************************
    Function Name	: getNFB
    Date		: Sep. 2015
    Remarks: Used to get the Negative feedback signal.
******************************************************************************
    Input: none
    Output: double
*****************************************************************************/
double PIDControl::getNFB()
{
    return this->NFB;
}

/*****************************************************************************
    Function Name	: setNFB
    Date		: Sep. 2015
    Remarks: Used to set the Negative Feedback signal from the plant.
******************************************************************************
    Input: double
    Output: none
**************************************************************************/
void PIDControl::setNFB(double value)
{
    this->NFB=value;
}

/*****************************************************************************
    Function Name	: setAntiW
    Date		: Sep. 2015
    Remarks: Used to set the anti wind up term for the integral control part.
******************************************************************************
    Input: float
    Output: none
*****************************************************************************/
void PIDControl::setAntiW(float value){
    this->anti_w=value;
}

/*****************************************************************************
    Function Name	: setDesired
    Date		: Sep. 2015
    Remarks: Used to set the desired signal response.
******************************************************************************
    Input: double
    Output: none
*****************************************************************************/
void PIDControl::setDesired(double value)
{
    this->desired=value;
}


/*****************************************************************************
    Function Name	: calcError
    Date		: Sep. 2015
    Remarks: Used to calculate the Proportional and Integral error terms
******************************************************************************
    Input: double, double - the desired signal and the actual response
    Output: none
*****************************************************************************/

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

/*****************************************************************************
    Function Name	: setFreq
    Date		: Sep. 2015
    Remarks: Used to set the cutoff frequency. Default is 10Hz
******************************************************************************
    Input: int
    Output: none
*****************************************************************************/

void PIDControl::setFreq(int freq)
{ this->Freq=freq;
}

int PIDControl::getFreq(){
    return this->Freq;
}

/*****************************************************************************
    Function Name	: lpFilter
    Date		: Sep. 2015
    Remarks: Used to calculate the low pass Filter value for the Derivate control
******************************************************************************
    Input: none
    Output: double - return the filtered value - requires 2 cycles of accumulated values
*****************************************************************************/


double  PIDControl::lpFilter(){

    //this filter code was adopted from a ROS package

    float c=1/tan( (Freq*6.2832)*deltaT/2 );
    //float c = 1.0;
    fe2 = fe1;
    fe1=fe0;
    fe0= (1/(1+c*c+1.414*c))*(e2+2*e1+e0-(2-1.414)*fe2);
    ed2=ed1;
    ed1=ed0;
    ed0=(e0-e1)/deltaT;
    filtered_error_deriv2= filtered_error_deriv1;
    filtered_error_deriv1= filtered_error_deriv0;

    if(this->filtcount >2){
        filtered_error_deriv0=(1/(1+c*c+1.414*c))*(ed2+2*ed1+ed0-(2-1.414)*filtered_error_deriv2);
        filteredValue=filtered_error_deriv0;
    }

    else{
        filtcount++;
    }

    return filteredValue;
}

/*****************************************************************************
    Function Name	: getU
    Date		: Sep. 2015
    Remarks: Used to get the control term U form the controller
*****************************************************************************
    Input: none
    Output: double
*****************************************************************************/
double PIDControl::getU()
{return this->U;
}

/*****************************************************************************
    Function Name	: setLimit
    Date		: Sep. 2015
    Remarks: Used to set the control limits
******************************************************************************
    Input: double, double - the miminum and maximum values for the controls
    Output: none
*****************************************************************************/

void PIDControl::setLimit(double min , double max){
    this-> lowLimit=min;
    this-> highLimit=max;
}

/*****************************************************************************
    Function Name	: spin
    Date		: Sep. 2015
    Remarks: Used to run a control cycle
******************************************************************************
    Input: none
    Output: double - returns the calculated controls
*****************************************************************************/
double PIDControl::spin(){
    //double ms =(std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000);
    //deltaT=ms-previousT;
    deltaT=0.1;
    calcError(this->desired,this->getNFB());

    //Calculating Controls
    U = KP*(Error)+ KI*(IError)+KD*(lpFilter());

    //Clamping the Control
    if(U>highLimit){
        this->U=highLimit;
    }
    if(U<lowLimit){
        this->U=lowLimit;
    }

    //    previousT+=deltaT;  //for Debugging
    return U;

}




