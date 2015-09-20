#include "plant.h"
#include <cstdlib>

plant::plant()
{
    x= 0.0;
    t= 0.0;
    xd=0.0;
    deltaT = 0.05;
    u = 0.0;
    A = 0.1 ;
    B = 1;
}

/*****************************************************************************
    Function Name	: getState
    Date		: Sep. 2015
    Remarks: Used to get current state 'x' of the plant
******************************************************************************
    Input: none
    Output: double - The state/position
*****************************************************************************/
double plant::getState(){ return x;
                        }

/*****************************************************************************
    Function Name	: update
    Date		: Sep. 2015
    Remarks: Used to update the plant state based on the controls passes
******************************************************************************
    Input: double - Control term
    Output: double - State
*****************************************************************************/

double plant::update(double u ){
    double noise = (rand()%1000)/100;   //random noise injection
    // double noise=0;   //Debugging
    xd=A*x+B*u+noise;    //x_d =  Ax+Bu
    x=x+xd*deltaT;
    //t+=deltaT;

    return x;
}

/*****************************************************************************
    Function Name	: setA
    Date		: Sep. 2015
    Remarks: Used to set the position Gain in xd= Ax+Bu
******************************************************************************
    Input: double
    Output: none
*****************************************************************************/
void plant::setA(double val){
    this->A=val;

}

/*****************************************************************************
    Function Name	: setB
    Date		: Sep. 2015
    Remarks: Used to set control gain in xd=Ax+Bu
******************************************************************************
    Input: double
    Output: none
*****************************************************************************/
void plant::setB(double val){
    this->B=val;
}

