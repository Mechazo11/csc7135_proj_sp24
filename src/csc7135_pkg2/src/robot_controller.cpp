/**
 * @file robot_controller.cpp
 * @brief Contains ```FetchRobotController``` class implementation
 * @author Azmyin M. Kamal
 * @date 2024-05-02
 * @version 0.1
*/

//* Includes
#include <robot_controller.hpp>

/**
 * @brief Constructor
*/
FetchRobotController::FetchRobotController(){
    /**
     * Other relevant classes and arm controllers would be setup here
    */
    target_obj = "Blue"; // Set default
    // Setup subscribers
    target_obj_sub_ = nh.subscribe("/fetch/target_obj", 10, 
                    &FetchRobotController::targetObjCallback, this);
    rgbd_sub_ = nh.subscribe("/fetch/rgbd_data", 10, 
                    &FetchRobotController::rgbdCallback, this);
    // Setup publishers
    std::cout <<"FetchRobotController initialized\n"<<std::endl;
}

/**
 * @brief
*/
void FetchRobotController::stateFeedBack(){
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Timestamp: " << rgbd_timestamp 
              << " target object: " << target_obj << "\n" << std::endl;
    // ROS_INFO("Timestamp: %s target object: %s\n", rgbd_timestamp.c_str(), target_obj.c_str());
    // TODO collison warning
}

/**
 * @brief Callback to receive information on target object
 * @attention Get remapped to "/fetch/targets" instead of "/fetch/target_obj" 
*/
void FetchRobotController::targetObjCallback(const std_msgs::String::ConstPtr& msg){
    target_obj = msg->data.c_str();
    //ROS_INFO("Target object: [%s]", msg->data.c_str());
}

/**
 * @brief Callback to receive RGBD image message
*/
void FetchRobotController::rgbdCallback(const sensor_msgs::Image::ConstPtr& img_msg){
    std::ostringstream oss;
    oss << img_msg->header.stamp;
    rgbd_timestamp = oss.str(); // Record in global scope
}

/**
 * @brief Destructor
*/
FetchRobotController::~FetchRobotController(){
    /**
     * Other classes, controller shutdown code goes here
    */
    ros::shutdown(); // Ensures ROS shuts down correctly
}