#include "pidcontrol.h"
#include "plant.h"
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int main(){
    PIDControl mycontroller;
    plant robertplant;

    //Using default Gains
    mycontroller.setKP(10);
    mycontroller.setKD(13);
    mycontroller.setKI(2.23);
    double duration;
    double count=0.0;
    // mycontroller.setLimit(-10000,10000);
    cout<<"Set Duration(seconds)of simulation.\n"<<endl;
    cin>>duration;
    cout<<endl;
    // duration*=1000; //convert to milis
    ofstream output("output.csv");

    output<<" Error "<<" , "<<"   Control   "<<"  ,  "<<"   Feedback   "<<endl;

    while(count<duration)
    {
     // float npoints=((count)/(duration/count));
        mycontroller.setDesired(10* sin(2* 3.14 * count) );  //setting the desired wave

        //Do simulation
        mycontroller.Y= robertplant.update(mycontroller.spin());
        mycontroller.setNFB(mycontroller.Y);

         // DEBUGGING
        //std::cout<<mycontroller.desired<<"  "<< robertplant.getState() <<std::endl;

        //Write to file
        output<<mycontroller.Error<<"  ,  "<<mycontroller.getU()<<"  ,  "<<mycontroller.getNFB()<<endl;
        count+=mycontroller.deltaT;
    }

    output.close();
    cout<<"Finished Simulation"<<endl;
    return 0;

}




