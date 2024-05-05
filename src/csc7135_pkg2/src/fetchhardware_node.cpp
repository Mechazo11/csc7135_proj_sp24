/***
 * @file fetchsensorhardware_node.cpp
 * @brief Simulates the faulty hardware node in a Fetch mobile manipulator
 * @author Azmyin M. Kamal
 * @date 05/05/2024
*/

// Includes
#include "robot_hardware.hpp"

/**
 * Main entry point to this node
*/
int main(int argc, char **argv){

    // Set up the ROS node.
    ros::init(argc, argv, "fetch_hardware"); // Initialize node with a name
    FetchHardware hardware; // Erroneous class
    ros::Rate rate(5); // 5 Hz update
    // Blocking
    while(ros::ok())
    {
        hardware.publishRGBDData(); // Sends RGBD data
        hardware.publishTargetObjData(); // Sends target to manipulate
        ros::spinOnce(); // Process callbacks
        rate.sleep();        
    }
} // end main()