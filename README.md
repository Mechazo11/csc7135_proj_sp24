### Project Readme

## Changes from ROS Melodic build
* Changed all relevevant .py script's top-level shebang to ```#!/usr/bin/env python3```

## Tutorials/Useful references
* [Fetch official tutorial for gazebo](https://docs.fetchrobotics.com/gazebo.html)

## Preamble

### Solve the issue with ```PYTHONPATH``` and ```setuptools ```

Follow these steps
* Open a File exlorer, go to ```Home```
* Hit ```Ctrl+H``` to allow viewing hidden files
* Open ```.bashrc```
* Scroll down to the very bottom and copy these lines
```
export PYTHONPATH="/usr/lib/python3/dist-packages:$PYTHONPATH"
export SETUPTOOLS_USE_DISTUTILS=stdlib
```

### Install dependencies before building catkin

* Intall geometry2 module ```sudo apt install ros-noetic-geometry2*```

* Intall navigation module ```sudo apt install ros-noetic-navigation```

* Install moveit module ```sudo apt install ros-noetic-moveit```

* Install simple_grasping module ```sudo apt install ros-noetic-simple-grasping```

* Install teleop-twist-keyboard ```sudo apt-get install ros-noetic-teleop-twist-keyboard```

* Install rgbd_launch ```sudo apt-get install ros-noetic-rgbd_launch```

* Ensure ```numpy``` is installed in the enviornment (pipenv or conda)

## Setting up ROSDiscover and ROSWire
* git clone ROSDiscover
* cd into ```rosdiscover``` and then git clone ```roswire```
* Install ```rosdiscover``` and then cd into ```roswire``` and install it
* Test installation ```rosdiscover --help```

## Creating a Docker image of the workspace
* Navigate to the workspace: ```cd ~/csc735_project/```
* Build ```test1``` docker image: ```docker image build -t test1 .```

* Remove a docker image: ```TODO```

* Useful links
    - https://medium.com/@sepideh.92sh/how-docker-revolutionizes-application-development-a-comprehensive-guide-for-beginners-fc2d3e53eb31


## Experiment Setup

These ```simple``` projects is written to emulate architectural bugs in a Fetch robot based on the detection library available in ```ROSDiscover```

```FetchRobotController``` class emulates logical functions that may be used with to control locomotion and manipulation of the Fetch robot

```FetchSensor``` is a class that emulates the vision sensor and arm joint states.

* Packages and error dataset
  * Pkg 1: ```FetchSensor``` sends IMU data but ```FetchRobotController``` subscribes to with wrong data format. RGB-D cameras like Zed2i can also compute orientation of camera along with vision. This experiment is to show if camera orientation is not recorded then calculating arm position will be wrong since the transformation of object observed from camera will not be accurate w.r.t to body frame which is a crucial step to eye-to-hand coordination problem.

  
  * Pkg 2: Danling connector, ```FetchRobotController``` never starts selecting block even though it receives vision data.
  * Pkg 3: Combination of both causing ```FetchRobotController``` to hit itself with its arm

## TODO

- [ ] Complete csc7135_pkg1 with a C++ node and a launch file

- [ ] Write down the steps to replicate ```RQ2``` in ROSDiscover paper

- [ ] Create and test the experiments.yml file for ```fetch_lsu```

- [x] Correctly install ```ROSDiscover``` and ```ROSWire```

- [x] Port ```fetch-gazebo``` and ```fetch``` into ROS Noetic

- [x] Learn how to convert a catkin_ws to Docker image

- [x] Test if ```rosdiscover``` launch works with the created Docker

- [x] Check if we can understand the pipeline to get architecture read using rosdiscover

- [x] Figure out how to launch Fetch with just is arm and no head. Not possible.s


## Resources / References
1. Replication [package](https://zenodo.org/records/5834633)

2. Create ROS 1 C++ packages with [catkin tools](https://catkin-tools.readthedocs.io/en/latest/quick_start.html)

3. Create launch file [within the package](https://automaticaddison.com/how-to-create-a-launch-file-in-ros-noetic/) 

4. C++ ROS node design [notes](https://nu-msr.github.io/navigation_site/lectures/node_structure.html)

5. ROS [Services](https://www.youtube.com/watch?v=_EtsntSAVKE)

6. An example of a ROS C++ package conforming to [LARICS C++ standard](https://github.com/larics/example_ros_cpp)

7. Publisher and subscriber in one [cpp class](https://answers.ros.org/question/59725/publishing-to-a-topic-via-subscriber-callback-function/?answer=59738?answer=59738#post-id-59738)

8. Using Class Methods as [callbacks](https://wiki.ros.org/roscpp_tutorials/Tutorials/UsingClassMethodsAsCallbacks)