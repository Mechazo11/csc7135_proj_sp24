/**
 * @file fetchcontroller_node.cpp
 * @brief Simulates the primary controller node in a Fetch mobile manipulator
 * @author Azmyin M. Kamal
 * @date 05/05/2024
*/

// Includes
#include "robot_controller.hpp"

/**
 * Main entry point to this node
*/
int main(int argc, char **argv){

    // Set up the ROS node.
    ros::init(argc, argv, "fetch_robot"); // Initialize node with a name
    FetchRobotController fetch_controller;
    ros::Rate rate(5); // 5 Hz update
    
    // Blocking
    while(ros::ok())
    {  
        fetch_controller.stateFeedBack(); // Prints state of robot
        ros::spinOnce(); // Process callbacks
        rate.sleep();        
    }
} // end main()