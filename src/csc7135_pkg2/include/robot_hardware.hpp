/**
 * @file robot_sensor_pkg2.hpp
 * @brief Class definition for FetchHardware class for Experiment 2
 * @author Azmyin M Kamal
 * @date 05/05/24
*/

#ifndef ROBOT_HARDWARE_HPP
#define ROBOT_HARDWARE_HPP

// Includes
//* C/C++

//* ROS
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/JointState.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/Imu.h"
#define pass (void)0

/**
 * @brief Simulates the hardware i.e. camera and joint controller of a Fetch Robot
*/
class FetchHardware
{
    public:
        // Methods
        FetchHardware(); // Constructor
        ~FetchHardware();// Destructor
        
        // Simulates sending detected objects to FetchController
        void publishRGBDData(); 
        // Simulate sending target object data based on user's requirement
        void publishTargetObjData();
        
        // Variables
        ros::NodeHandle nh; 
        ros::Publisher rgbd_pub_;
        ros::Publisher target_obj_pub_;
        std::string target_obj = ""; // Set to another name by user
};

#endif