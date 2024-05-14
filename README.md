# Architectural Bug Detection and Analysis in ROS-based Mobile Manipulator Projects Using ROSDiscover

This repository contains the ros workspace to emulate usage of ```ROSDiscover```, a static analysis tool that builds upon ROS 1's core API and ACME style rule checking to detect ```architectural bugs``` in two C++ ROS 1 packages that builds upon various topics and messages commonly used in mobile manipulator projects. ```ROSDiscover``` depends upon [ROSWire](https://github.com/cmu-rss-lab/roswire) packaged to read and interact with ROS Systems packaged as a ***Docker image***

Script used for this experiment can be found here [csc7135_rosdiscover_exp](https://github.com/Mechazo11/csc7135_rosdiscover_exp.git)

A copy of ```ROSDiscover``` paper and our report writeup is available in the ```report_papers``` directory.

References to some useful commands are compiled in the ```COMMANDS.md``` file

## Setup

```ROSDiscover``` relies exclusively on ```Docker``` containers to evaluate a ROS package. Hence, the following

* Install ```pipenv``` if you don't have it yet

### ROSDiscover and ROSWire

* ```cd ~/Documents``` and git clone [rosdiscover](https://github.com/cmu-rss-lab/rosdiscover)
* cd into ```rosdiscover``` and then git clone ```roswire```
* cd back ino ```rosdiscover``` and activate the shell with ```pipenv shell```
* Install ```rosdiscover``` with ```pip install -e .```. This may cause failure with ```roswire```.
* Now cd into ```roswire``` and install it 

and then cd into ```roswire``` and install it. Oddly this procedure installs ```roswire``` correctly
* cd back to ```rosdiscover``` and 
* Test installation ```rosdiscover --help```
* Intall the following dependencies in the host machine
  * Java: ```sudo apt install default-jre```

## Experiment Setup

### Creating Docker images

In the workspace directory we have defined as ```Dockerfile``` that contains the instructions necessary for ```Docker```  to compose an image based  

### Running ROSDiscover
These ```simple``` projects is written to emulate architectural bugs in a Fetch robot based on the detection library available in ```ROSDiscover```

```FetchRobotController``` class emulates logical functions that may be used with to control locomotion and manipulation of the Fetch robot

```FetchSensor``` is a class that emulates the vision sensor and arm joint states.


* Packages and error dataset
  
  RGB-D cameras like Zed2i can also compute orientation of camera along with vision. This experiment is to show if camera orientation is not recorded then calculating arm position will be wrong since the transformation of object observed from camera will not be accurate w.r.t to body frame which is a crucial step to eye-to-hand coordination problem.
  
  * Pkg 1: ```FetchSensor``` means to send IMU data but erroneous sends ***wrong data format***. This causes causes a run-time crash
1
  * Pkg 2: Danling connector: The idea is user defines an object to be manupulated.
  ```FetchRobotController``` receives image data but does not send ```ACK``` to the ```FetchSensor```. Thus, ```FetchSensor``` keeps repeating the same data over and over again


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