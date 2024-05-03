/**
 * @file robot_node.cpp
 * @author Azmyin M. Kamal
 * @brief Contains ```RobotNode``` class implementation
 * @version 0.1
 * @date 2024-05-02
*/

//* Includes
#include "robot_node.hpp"

/**
 * Main entry point to this node
*/
int main(int argc, char **argv){

    // Set up the ROS node.
    ros::init(argc, argv, "fetch_robot1"); // Initialize node with a name
    ros::NodeHandle n; // Main access point to communications with ROS system
    //* TODO initialize a RobotNode object
    
    ros::Rate loop_rate(10); // Set update rate for this node
    
    while (ros::ok()){
        pass;
    }

} // end main()