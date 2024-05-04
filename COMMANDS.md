## commands.md

This file contains all the commands required to running this project

* Check what version of ubuntu you are running
```lsb_release -a```

* Check version of ROS running
```echo $ROS_DISTRO```

### Create C++ project with ```catkin create```

* in ws/src run this command: ```catkin create pkg your_package_name --catkin-deps roscpp```

* Go to the workspace/src directory: ```cd ~/csc7135_proj_sp24/src```
* Example of creating a package: ```catkin create pkg csc7135_pkg1 --catkin-deps roscpp std_msgs sensor_msgs```

#### Create and test docker image

* Navigate to the workspace: ```cd ~/csc7135_proj_sp24/```
* Build ```pkg1``` docker image: ```docker image build -t pkg1 .```
* Test run this image: ```docker run -it pkg1```

#### Experiment
* In a terminal move into the rosdiscover directory 
```cd ~/Documents/rosdiscover/``` 

* Activate the environment ```. /home/icore_base/.local/share/virtualenvs/rosdiscover-aYG4O-1F/bin/activate```

* Activate ROSDiscover enviornment in az_ubunut: ```. /home/az/.local/share/virtualenvs/rosdiscover-2-DhvFio/bin/activate```


* Test 1: Test ROSDiscover launch
```rosdiscover launch /home/icore_base/csc7135_project/rosdiscover_yml/fetch.yml```