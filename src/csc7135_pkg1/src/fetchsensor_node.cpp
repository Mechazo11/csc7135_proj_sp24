/***
 * @file fetchsensor_node.cpp
 * @brief TODO
 * @author Azmyin M. Kamal
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
    
    //* TODO initialize a FetchRobot object
    //* TODO initalize a FetchSensor object
    
    //ros::Rate loop_rate(10); // Set update rate for this node
    
    /**
     * All functionalities are handleded in callback functions
    */
    // ros::spin(); // Blocking loop

} // end main()