FROM osrf/ros:noetic-desktop-full

# Install additional dependencies with VNC server
# vnc4server was replaced by tiger-vnc-standalone-server
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && export DEBIAN_FRONTEND=noninteractive \ 
    && apt-get install -y \
                        nano \ 
                        python3-pip \ 
                        python3-catkin-tools \
                        python3-osrf-pycommon \
                        supervisor \
                        xfce4 \
                        xfce4-goodies \
                        xfce4-terminal \
                        tigervnc-standalone-server \
                        xserver-xorg-core \
                        xterm \
                        xvfb \
                        x11vnc \
    && apt-get clean \
    && apt-get update \
    && apt-get install -y zlib1g-dev \
    && apt-get install -y default-jre \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir ~/.vnc \
    && /bin/bash -c "echo -e 'password\npassword\nn' | vncpasswd"
ENV TINI_VERSION v0.9.0
ADD https://github.com/krallin/tini/releases/download/${TINI_VERSION}/tini /bin/tini
RUN chmod +x /bin/tini

# Create the catkin workspace directory structure in the home directory
RUN mkdir -p /home/ros_ws/src

# Copy the src directory from host machine to image
COPY ./src /home/ros_ws/src

# Copy /startup-vnc.sh
COPY startup-vnc.sh /

# Set the working diretory
WORKDIR /home/ros_ws

# Set up the workspace and build your ROS packages
RUN /bin/bash -c ". /opt/ros/noetic/setup.sh; catkin build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"

# Source the setup files for ROS
RUN echo "source /opt/ros/noetic/setup.bash" >> /root/.bashrc && \
    echo "source /home/ros_ws/devel/setup.bash" >> /root/.bashrc