#include "pidcontrol.h"
#include "plant.h"
#include<iostream>
#include<fstream>
#include<math.h>



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
    std::cout<<"Set Duration(seconds)of simulation.\n"<<std::endl;

    std::cin>>duration;
    std::cout<<std::endl;
    // duration*=1000; //convert to milis



    std::ofstream output("output.csv");

    output<<" Error "<<" , "<<"   Control   "<<"  ,  "<<"   Feedback   "<<std::endl;

    while(count<duration)
    {

        // float npoints=((count)/(duration/count));

        mycontroller.setDesired(10* sin(2* 3.14 * count) );  //setting the desired wave

        //Do simulation
        //  mycontroller.spin();

        mycontroller.Y= robertplant.update(mycontroller.spin());
        mycontroller.setNFB(mycontroller.Y);



        // DEBUGGING
        //std::cout<<mycontroller.desired<<"  "<< robertplant.getState() <<std::endl;

        //Write to file
        output<<mycontroller.Error<<"  ,  "<<mycontroller.getU()<<"  ,  "<<mycontroller.getNFB()<<std::endl;

        count+=mycontroller.deltaT;
    }

    output.close();

    std::cout<<"Finished Simulation"<<std::endl;
    return 0;

}




