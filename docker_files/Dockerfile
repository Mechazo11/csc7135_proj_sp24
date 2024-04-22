FROM osrf/ros:noetic-desktop-full

# Install additional dependencies
RUN apt-get update && apt-get install -y nano \ 
                                        python3-pip \ 
                                        && rm -rf /var/lib/apt/lists/*

# Copy your catkin workspace into the Docker container
# COPY /home/icore_base/csc7135_project /root/catkin_ws

# # Set up the workspace and build your ROS packages
# RUN /bin/bash -c "source /opt/ros/noetic/setup.bash && cd /root/catkin_ws && catkin build"

# # Set up environment variables
# ENV CATKIN_WS /root/catkin_ws

# # Source the setup files for ROS
# RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc && \
#     echo "source /root/catkin_ws/devel/setup.bash" >> /root/.bashrc