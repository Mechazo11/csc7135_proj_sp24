FROM osrf/ros:noetic-desktop-full

# Install additional dependencies
RUN apt-get update && apt-get install -y nano \ 
                                        python3-pip \ 
                                        python3-catkin-tools \
                                        python3-osrf-pycommon \
                                        && rm -rf /var/lib/apt/lists/*

# Copy your catkin workspace into the Docker container
# COPY ~/csc7135_project/src /home/catkin_ws/src

# # Set up the workspace and build your ROS packages
# RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && cd /home/catkin_ws && catkin build"

# # Set up environment variables
# ENV CATKIN_WS /root/catkin_ws

# # Source the setup files for ROS
# RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc && \
#     echo "source /root/catkin_ws/devel/setup.bash" >> /root/.bashrc