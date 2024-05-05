/**
 * @file robot_hardware.cpp
 * @brief Implementation for ```FetchHardware``` class
 * @author Azmyin M Kamal
 * @date 05/05/24
*/

// Includes
#include "robot_hardware.hpp"

/**
 * @brief Constructor
*/
FetchHardware::FetchHardware(){
    /**
     * Here other classe would be called and sensors initialized
    */
   // Get target name assigned by user
   std::string target_param_;
   
   // Retrieve the string parameter from the parameter server
    if (!nh.getParam("target_obj_", target_param_)) {
        ROS_ERROR("Failed to retrieve parameter 'target_obj_'");
    }
   target_obj = target_param_;
   //nh.getParam("target_obj_", target_param_);
   
   // Setup publishers
   rgbd_pub_ = nh.advertise<sensor_msgs::Image>("/fetch/rgbd_data", 10);
   target_obj_pub_ = nh.advertise<std_msgs::String>("/fetch/target_obj", 10); // Remmaped to "/fetch/targets"
   joint_state_pub_ = nh.advertise<sensor_msgs::JointState>("/fetch/joint_state", 10); 

   // Setup subscribers
   cmd_joint_sub_ = nh.subscribe("/fetch/cmd_joint", 10, 
                    &FetchHardware::jointCallback, this);
   
   std::cout<<"FetchHardware initalized"<<std::endl;
}

/**
 * @brief Callback to process JointState command sent by FetchController and send back feedback
*/
void FetchHardware::jointCallback(const sensor_msgs::JointState::ConstPtr& joint_msg){
    /**
     * Logic to convert joint commands to actuation on motors would have gone here
    */
    std::vector<std::string> joint_names = joint_msg->name;
    std::cout << "------------------------------------------" << std::endl;
    std::cout <<"FetchHardware: received joint command data" << std::endl;
    std::cout << "------------------------------------------"<<std::endl;
    /**
     * Calls another class that interfaces with physical hardware
    */
    sensor_msgs::JointState joint_feedback_msg;
    joint_feedback_msg.header.stamp = ros::Time::now();
    joint_state_pub_.publish(joint_feedback_msg);
}

/**
 * @brief Simulate sending RGBD image data
*/
void FetchHardware::publishRGBDData(){
    sensor_msgs::Image img_msg;
    img_msg.header.stamp = ros::Time::now();  // populate header stamp
    /**
     * Logic to process RGBD image
    */
    rgbd_pub_.publish(img_msg);
}

/**
 * @brief Simulate sending target object data based on user's requirement
*/
void FetchHardware::publishTargetObjData(){
    std_msgs::String target_obj_msg;
    /**
     * Logic to process and pack information on target object
    */
    target_obj_msg.data = target_obj;
    target_obj_pub_.publish(target_obj_msg);
}

/**
 * @brief Destructor
*/
FetchHardware::~FetchHardware(){
    /**
     * Other sensor shutdown code goes here
    */
    ros::shutdown(); // Ensures ROS shuts down correctly
}

// ----------------------------------------------------------------
