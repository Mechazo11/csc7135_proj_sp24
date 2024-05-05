### Project Readme

TODO

All commands used in this project is compiled in the ```COMMANDS.md``` text file

Script files to use ```ROSDiscover``` based on experiment parameters are provided in the [csc7135_rosdiscover_exp](https://github.com/Mechazo11/csc7135_rosdiscover_exp.git) repository

## Contributions

* The Fetch gazebo package modified to work in ROS Noetic will be released as an open source project on May 5th. While ultimately not required to due to complexity and time constraint, it is still a worthwhile contribution that came out of this project.

* Demonstrated usage of ROSDiscover`s capabilities on easy-to-use ROS systems to do a feasilibity analysis for it to be used for mobile manipulator systems.


## Tutorials/Useful references
* [Fetch official tutorial for gazebo](https://docs.fetchrobotics.com/gazebo.html)


## Setting up ROSDiscover and ROSWire
* git clone ROSDiscover
* cd into ```rosdiscover``` and then git clone ```roswire```
* Install ```rosdiscover``` and then cd into ```roswire``` and install it
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

  * Pkg 2: Danling connector: The idea is user defines an object to be manupulated.
  ```FetchRobotController``` receives image data but does not send ```ACK``` to the ```FetchSensor```. Thus, ```FetchSensor``` keeps repeating the same data over and over again

## TODO

* [x] Look into the pick_place launcher to see if we can generate a ```red``` and a ```green``` object

* [x] Create ```pkg1```, ```pkg2``` image(s) if time permits

* [ ] Finish all experiments and compile results

* [ ] Finish draft of report

* [ ] Finish and submit final report

* [ ] Write instructions on how to download the two repositories and how to setup ROSDiscover

* [ ] Make ```csc7135_proj_sp24```, ```csc7135_rosdiscover_exp``` and ```fetch_gazebo_noetic_ws``` repositories ***public***

* [x] Complete csc7135_pkg1 with a C++ node and a launch file

* [x] Write down the steps to replicate ```RQ2``` in ROSDiscover paper

* [x] Correctly install ```ROSDiscover``` and ```ROSWire```

* [x] Port ```fetch-gazebo``` and ```fetch``` into ROS Noetic

* [x] Learn how to convert a catkin_ws to Docker image

* [x] Test if ```rosdiscover``` launch works with the created Docker

* [x] Check if we can understand the pipeline to get architecture read using rosdiscover

* [x] Figure out how to launch Fetch with just is arm and no head. Not possible.s


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