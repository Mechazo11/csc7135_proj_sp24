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

## Setting up ROSDiscover and ROSWire
* git clone ROSDiscover
* cd into ```rosdiscover``` and then git clone ```roswire```
* Install ```rosdiscover``` and then cd into ```roswire``` and install it
* Test installation ```rosdiscover --help```

## Creating a Docker image of the workspace
* Navigate to the workspace: ```cd ~/csc735_project/```
* Build ```test1``` docker image: ```docker image build -t test1 .```

* Remove a docker image: ```TODO```

* Test run this image: ```docker run -it test1```

* Useful links
    - https://medium.com/@sepideh.92sh/how-docker-revolutionizes-application-development-a-comprehensive-guide-for-beginners-fc2d3e53eb31


## Experiment Setup
* Instructions on how to run such experiments are setup here

## TODO

- [x] Correctly install ```ROSDiscover``` and ```ROSWire```

- [x] Port ```fetch-gazebo``` and ```fetch``` into ROS Noetic

- [x] Learn how to convert a catkin_ws to Docker image

- [ ] Test if ```rosdiscover``` launch works with the created Docker

- [ ] Check if arm hits itself, moveit can send collision node

- [ ] Create a python package that will move the arm through a motion to hit itself


## Resources
* Replication package: ```https://zenodo.org/records/5834633```
