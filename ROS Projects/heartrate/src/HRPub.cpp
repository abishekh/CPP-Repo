/*
 * Author : Abishek Hariharan
 * email: ahariharan@me.com
 *
 * Info : This program reads pre calculatd BPM
 *        from a serail port (coming from an Arduino)
 *        and passes it to a custom ROS message.
 *
 */


//this is for the custom message

#include "ros/ros.h"
#include <heartrate/heartrate.h>
#include <ros/console.h>
#include <exception>
#include <stdexcept>
#include <string>
#include "serial/serial.h"
#include "std_msgs/Time.h"

int main(int argc, char **argv)
{

    ros::init(argc,argv,"Serial_to_ROSHeartrate");

    ros::NodeHandle nh;
    ros::Publisher pulse=nh.advertise<heartrate::heartrate>("Pulse",1000);
    ros::Rate loop_rate(1000);
    ros::Duration d(1);

    bool firsttime=true;

    //Pass a ROS param
    std::string address="/dev/ttyACM0";
    unsigned long baud =115200;

        ROS_INFO("Trying to Establish Connection...");
        serial::Serial conn(address,baud,serial::Timeout::simpleTimeout(1000));
        ros::Time::init();
      if(!conn.isOpen())
    {
        ROS_ERROR("Connection Failed. Serial not open\n");
    }

    while (ros::ok() && conn.isOpen())
    {

        heartrate::heartrate hr_msg;

        if(firsttime==true)
        {
            ROS_INFO("Connection successful!");
            ROS_INFO("Using Device Address %s",address.c_str());
            ROS_INFO("Using Baud Rate %lu",baud);
            firsttime=false;

        }



            std::string data=conn.readline(1000,"\n").c_str();

           hr_msg.BPM=atoi(data.c_str());

            hr_msg.header.stamp=ros::Time::now();
            hr_msg.header.frame_id="/world";
            hr_msg.elapsed=d;

            pulse.publish(hr_msg);

            ros::spinOnce();

            loop_rate.sleep();


    }
    return 0;
}

