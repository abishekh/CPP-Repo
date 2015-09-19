#ifndef PLANT_H
#define PLANT_H

class plant
{
public:
    plant();

    double update(double u);
    void  setA(double val);
    void  setB(double val);
    double getState();
    double u,xd;

private:

    double x,t,deltaT,A,B;




};

#endif // PLANT_H
