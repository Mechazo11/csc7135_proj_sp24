# Architectural Bug Detection and Analysis in ROS-based Mobile Manipulator Projects Using ROSDiscover

This repository contains the ros workspace to emulate usage of ```ROSDiscover```, a static analysis tool that builds upon ROS 1's core API and ACME style rule checking to detect ```architectural bugs``` in two C++ ROS 1 packages that builds upon various topics and messages commonly used in mobile manipulator projects. ```ROSDiscover``` depends upon [ROSWire](https://github.com/cmu-rss-lab/roswire) packaged to read and interact with ROS Systems packaged as a ***Docker image***

Script used for this experiment can be found here [csc7135_rosdiscover_exp](https://github.com/Mechazo11/csc7135_rosdiscover_exp.git)

A copy of ```ROSDiscover``` paper and our report writeup is available in the ```report_papers``` directory.

References to some useful commands are compiled in the ```COMMANDS.md``` file

## Test equipment

* Ubuntu 20.04 and ROS Noetic full desktop
* Computer with Ryzen 5600X with 16Gb RAM

## Setup

* Install ```pipenv``` if you don't have it yet

### ROSDiscover and ROSWire

* ```cd ~/Documents``` and git clone [rosdiscover](https://github.com/cmu-rss-lab/rosdiscover)
* cd into ```rosdiscover``` and then git clone ```roswire```
* cd back ino ```rosdiscover``` and activate the shell with ```pipenv shell```
* Install ```rosdiscover``` with ```pip install -e .```. This may cause failure with ```roswire```.
* Now cd into ```roswire``` and install it ```pip install roswire```
* cd back to ```rosdiscover``` and test installation with ```rosdiscover --help```

* Intall the following dependencies in the host machine
  * Docker for [Ubuntu](https://docs.docker.com/engine/install/ubuntu/) and optionally complete [post-installation](https://docs.docker.com/engine/install/linux-postinstall/) steps
  * Catkin build tools: ```https://catkin-tools.readthedocs.io/en/latest/installing.html```
  * Java: ```sudo apt install default-jre```

## Dataset overview

Section 4 in the report details the experiment and dataset used. A brief summary of the two packages are as follows:

* Pkg 1 Subscription to wrong data type: ```FetchSensor``` means to send IMU data but erroneous sends ***wrong data format***. This causes causes a run-time crash.

* Pkg 2 Danling connectors: The idea is, an user defines an object to be manupulated.
```FetchRobotController``` receives image data and object detection data but does not send ```ACK``` to the ```FetchSensor```. Thus, ```FetchSensor``` keeps repeating the same data over and over again.

## Experimental Setup
Before setting up the experiment, git clone [csc7135_rosdiscover_exp](https://github.com/Mechazo11/csc7135_rosdiscover_exp.git) into the ```/Documents``` directory

### Step 1: Creating Docker image

* cd into csc7135_project ```cd ~```
* git clone this repository: ```git clone https://github.com/Mechazo11/csc7135_proj_sp24```
* cd into the directory: ```cd /csc7135_proj_sp24```
* Initialize workspace: ```catkin init```
* Run the convenience script to build and source the two test packages: ```./build_source_pkgs.sh```
* Now build the Docker image: ```sudo docker image build -t csc7135_proj .```
* Verify ```csc7135_proj``` image exsists: ```sudo docker image ls```

### Experiment 1: Subscription to wrong data type

* Move into the ```csc7135_rosdiscover_exp/scripts``` directory: ```cd ~/Documents/csc7135_rosdiscover_exp/scripts```

* Activate pipenv from ROSDiscover that you installed previously. An ***example*** command: ```. /home/az/.local/share/virtualenvs/rosdiscover-2-DhvFio/bin/activate``
`
* Step 1: Derive groundtruth architecture: ```python3 observe-system.py pkg1```
* Step 2: Check the architecture against ACME rules: ```python3 check-architecture.py observed pkg1```

#### Experiment 2: Dangling connectors

* Step 1: Derive groundtruth architecture: ```python3 observe-system.py pkg2```
* Step 2: Check the architecture against ACME rules: ```python3 check-architecture.py observed pkg2```

#### Limitations:

* We could not get the ```rosdiscover-cxx-recover``` to compile and run. 
Hence Steps from RQ2 in the ROSDiscover paper, as described in ```README_ROSDISCOVER.rst``` file in [csc7135_rosdiscover_exp](https://github.com/Mechazo11/csc7135_rosdiscover_exp.git) does to not work.

* Thus, the experimental results only uses dynamic approach in recovering run time architecture which may have some limitations.

* If you are able to solve the ```rosdiscover-cxx-recover``` issue, please open a ```pull-request```.


## Resources / References
1. Replication [package](https://zenodo.org/records/5834633)

2. Create ROS 1 C++ packages with [catkin tools](https://catkin-tools.readthedocs.io/en/latest/quick_start.html)

3. Create launch file [within the package](https://automaticaddison.com/how-to-create-a-launch-file-in-ros-noetic/) 

4. C++ ROS node design [notes](https://nu-msr.github.io/navigation_site/lectures/node_structure.html)

5. ROS [Services](https://www.youtube.com/watch?v=_EtsntSAVKE)

6. An example of a ROS C++ package conforming to [LARICS C++ standard](https://github.com/larics/example_ros_cpp)

7. Publisher and subscriber in one [cpp class](https://answers.ros.org/question/59725/publishing-to-a-topic-via-subscriber-callback-function/?answer=59738?answer=59738#post-id-59738)

8. Using Class Methods as [callbacks](https://wiki.ros.org/roscpp_tutorials/Tutorials/UsingClassMethodsAsCallbacks)

9. Usefulness of [Docker](https://medium.com/@sepideh.92sh/how-docker-revolutionizes-application-development-a-comprehensive-guide-for-beginners-fc2d3e53eb31)

10. Remapping topic names in [ROS 1](https://roboticsbackend.com/ros-topic-remap-example/)