/**
 * @file robot_node.hpp
 * @author Azmyin M. Kamal
 * @brief Contains ```FetchRobotController``` class definitions
 * @version 0.1
 * @date 2024-05-02
 * 
 */
#ifndef ROBOT_CLASS_HPP
#define ROBOT_CLASS_HPP

//* C/C++

//* ROS
#include"ros/ros.h"
#include "std_msgs/String.h"
#define pass (void)0

class FetchRobotController
{
    public:
        FetchRobotController(); // Constructor
        ~FetchRobotController();// Destructor

    private:
    ros::NodeHandle nh;
    //ros::Publisher pub;
    //ros::Subscriber sub;
};

#endif