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
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/Image.h"
#include <sensor_msgs/Imu.h>
#define pass (void)0

class FetchRobotController
{
    public:
    FetchRobotController(); // Constructor
    ~FetchRobotController();// Destructor
    void headImuCallback(const sensor_msgs::Imu::ConstPtr& msg);
    
    private:
    ros::NodeHandle nh;
    ros::Subscriber sub_head_imu_;
};

#endif