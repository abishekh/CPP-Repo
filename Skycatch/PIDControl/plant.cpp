#include "plant.h"
#include <cstdlib>

plant::plant()
{
    x= 0.0;
    t= 0.0;
    xd=0.0;
    deltaT = 0.01;
    u = 0.0;
    A = 0.1 ;
    B = 1;


}


double plant::getState(){

    return x;
}


double plant::update(double u ){



   //double noise = (rand()%200)/10;   //random noise injection
    double noise=0;

    xd=A*x+B*u+noise;    //x_d =  Ax+Bu
    x=x+xd*deltaT;
    //t+=deltaT;


    return x;
}


void plant::setA(double val){
    this->A=val;

}

void plant::setB(double val){
    this->B=val;
}

