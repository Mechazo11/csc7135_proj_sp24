## commands.md

This file contains all the commands required to running this project

* Check what version of ubuntu you are running
```lsb_release -a```

* Check version of ROS running
```echo $ROS_DISTRO```

### Create C++ project with ```catkin create```
* in ws/src run this command: ```catkin create pkg your_package_name --catkin-deps roscpp```

* ```cd ~/csc7135_project/src```
* ```catkin create pkg csc7135_pkg1 --catkin-deps roscpp std_msgs```

#### Testing the docker image
* Test run this image: ```docker run -it test1```

#### Testing Fetch robot
* Launch the playground for pick-and-place simulation
```roslaunch fetch_gazebo pickplace_playground.launch```

* Launch the pick and place demo
```roslaunch fetch_gazebo_demo pick_place_demo.launch```

* Launch the basic simualtion
```roslaunch fetch_gazebo simulation.launch``` 

#### Experiment
* In a terminal move into the rosdiscover directory 
```cd ~/Documents/rosdiscover/``` 

* Activate the environment ```. /home/icore_base/.local/share/virtualenvs/rosdiscover-aYG4O-1F/bin/activate```


* Test 1: Test ROSDiscover launch
```rosdiscover launch /home/icore_base/csc7135_project/rosdiscover_yml/fetch.yml```