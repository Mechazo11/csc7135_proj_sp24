FROM osrf/ros:noetic-desktop-full

# Install additional dependencies
RUN apt-get update && apt-get install -y nano \ 
                                        python3-pip \ 
                                        python3-catkin-tools \
                                        python3-osrf-pycommon \
                                        ros-noetic-geometry2*\
                                        ros-noetic-navigation\
                                        ros-noetic-moveit\
                                        ros-noetic-simple-grasping\
                                        && rm -rf /var/lib/apt/lists/*

# Create the catkin workspace directory structure in the home directory
RUN mkdir -p /home/ros_ws/src

# Copy the src directory from host machine to image
COPY ./src /home/ros_ws/src

# Set the working diretory
WORKDIR /home/ros_ws

# Set up the workspace and build your ROS packages
RUN /bin/bash -c ". /opt/ros/noetic/setup.sh; catkin build"

# Source the setup files for ROS
RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc && \
    echo "source /home/ros_ws/devel/setup.bash" >> /root/.bashrc