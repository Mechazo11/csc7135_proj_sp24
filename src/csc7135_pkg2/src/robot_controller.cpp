/**
 * @file robot_controller.cpp
 * @brief Contains ```FetchRobotController``` class implementation
 * @author Azmyin M. Kamal
 * @date 2024-05-02
 * @version 0.1
*/

//* Includes
#include <robot_controller_pkg2.hpp>

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

    joint_state_sub = nh.subscribe("/fetch/joint_state", 10, 
                    &FetchRobotController::jointStateCallback, this);
    
    // Setup publishers
    joint_cmd_pub_ = nh.advertise<sensor_msgs::JointState>("/fetch/cmd_joint", 10); // Remapped to "/fetch/JointState"

    std::cout <<"FetchRobotController initialized\n"<<std::endl;
}

/**
 * @brief Updates state of controller
*/
void FetchRobotController::stateUpdate(){
    
    // Publish a joint command
    sensor_msgs::JointState joint_state_msg;
    
    // Fill in the JointState message with dummy data
    joint_state_msg.header.stamp = ros::Time::now();
    joint_state_msg.name = {"gripper_x", "gripper_y", "gripper_z"};
    joint_state_msg.position = {0.1, 0.2, 0.3};
    joint_state_msg.velocity = {0.01, 0.02, 0.03};
    joint_state_msg.effort = {1.0, 2.0, 3.0};
    joint_cmd_pub_.publish(joint_state_msg);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "FetchController: target object: " << target_obj << std::endl;
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
 * @brief Callback to receive JointState from FetchHardware
*/
void FetchRobotController::jointStateCallback(const sensor_msgs::JointState::ConstPtr& joint_msg){
    /**
     * Logic to use current JointStates to calculate collision or future states goes here
    */
    std::vector<std::string> joint_names = joint_msg->name;
    std::cout <<"FetchController: received joint state feedback"<<std::endl;
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