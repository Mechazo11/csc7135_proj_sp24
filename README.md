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
* Instructions on how to run such experiments are setup here

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