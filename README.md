### Project Readme

## Changes from ROS Melodic build
* Changed all relevevant .py script's top-level shebang to ```#!/usr/bin/env python3```

## Tutorials/Useful references
* [Fetch official tutorial for gazebo](https://docs.fetchrobotics.com/gazebo.html)

## Preamble

* Ensure ```PYTHONPATH``` is set to the location where all packages are installed for Python 3.8 (default in Ubuntu 20.04) and address the bug from ```setuptools ```

* Add these line to your .bashrc file
```export PYTHONPATH="/usr/lib/python3/dist-packages:$PYTHONPATH"```

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

* Test run this image: ```docker run -it test1```

* Useful links
    - https://medium.com/@sepideh.92sh/how-docker-revolutionizes-application-development-a-comprehensive-guide-for-beginners-fc2d3e53eb31


## Experiment Setup
* Instructions on how to run such experiments are setup here

## TODO

- [x] Correctly install ```ROSDiscover``` and ```ROSWire```

- [x] Port ```fetch-gazebo``` and ```fetch``` into ROS Noetic

- [ ] Learn how to convert a catkin_ws to Docker image

- [ ] Test if ```rosdiscover``` launch works with the created Docker

- [ ] Check if arm hits itself, moveit can send collision node

- [ ] Create a python package that will move the arm through a motion to hit itself


## Resources
* Replication package: ```https://zenodo.org/records/5834633```