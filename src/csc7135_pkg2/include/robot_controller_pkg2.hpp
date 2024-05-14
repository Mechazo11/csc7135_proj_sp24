/**
 * @file robot_controller.hpp
 * @brief Class definition for FetchController class for Experiment 2
 * @author Azmyin M. Kamal
 * @date 05/05/2024
 * 
 */
#ifndef ROBOT_CONTROLLER_PKG2_HPP
#define ROBOT_CONTROLLER_PKG2_HPP

//* C/C++
# include <iostream>
# include <iomanip>

//* ROS
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/Image.h"
#include <sensor_msgs/Imu.h>
#define pass (void)0

/**
 * @brief Simulates a Fetch main controller class
*/
class FetchRobotController
{
    public:
        // Methods
        FetchRobotController(); // Constructor
        ~FetchRobotController();// Destructor
        void stateUpdate(); // TODO

        void targetObjCallback(const std_msgs::String::ConstPtr& msg);  // Depricated
        void rgbdCallback(const sensor_msgs::Image::ConstPtr& img_msg);
        void jointStateCallback(const sensor_msgs::JointState::ConstPtr& joint_msg);

        // Variables
        ros::NodeHandle nh;
        // ros::Rate r;
        ros::Subscriber target_obj_sub_;
        ros::Subscriber rgbd_sub_;
        ros::Subscriber joint_state_sub;
        ros::Publisher joint_cmd_pub_;
        std::string target_obj = "";
        std::string rgbd_timestamp = "";
};

#endif