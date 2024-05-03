/***
 * @file exp1_node.cpp
 * @brief Driver file for Experiment 1
 * @author TODO
 * @date 05/03/2024
*/

// Includes
#include "robot_class.hpp"

/**
 * Main entry point to this node
*/
int main(int argc, char **argv){

    // Set up the ROS node.
    ros::init(argc, argv, "fetch_robot1"); // Initialize node with a name
    
    //* TODO initialize a RobotNode that uses Node composition
    
    //ros::Rate loop_rate(10); // Set update rate for this node
    
    /**
     * All functionalities are handleded in callback functions
    */
    // ros::spin(); // Blocking loop

} // end main()