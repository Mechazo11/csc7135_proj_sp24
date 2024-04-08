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

## Experiment Setup
* Instructions on how to run such experiments are setup here

## TODO
* Add them here
