#ifndef PIDCONTROL_H
#define PIDCONTROL_H

#include <ctime>
#include <vector>
class PIDControl
{

public:
    PIDControl();

    double desired,Error,NFB,deltaT;
    double U,Y;
    int getFreq();
    void setLimit(double min , double max);
    void setFreq(int freq);
    void setKP(double Kp);
    void setKI(double Ki);
    void setKD(double Kd);
    double getU();
    double getNFB();
    double spin();
    void setNFB(double value);
    void setAntiW(float value);
    void setDesired(double value);



protected:

    double lpFilter();
    void calcError(double desired, double actual);



private:
    int filtcount;
    double KP,KI,KD,Freq,IError,DError,filteredValue;

    float anti_w; //Anti windup

    double previousT;
    double lowLimit,highLimit;

    double e0,e1,e2;
    double fe0,fe1,fe2;
    double ed0,ed1,ed2;
    double filtered_error_deriv0,filtered_error_deriv1,filtered_error_deriv2;

    //    std::vector<float> error();
    //    std::vector<float> filtered_error();
    //    std::vector<float> error_deriv();
    //    std::vector<float> filtered_error_deriv();

    clock_t start;





};

#endif // PIDCONTROL_H
