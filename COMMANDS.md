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

* Build this package: ```catkin build csc7135_pkg1 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON```

#### Create and test docker image

* Navigate to the workspace: ```cd ~/csc7135_proj_sp24/```
* Build ```pkg1``` docker image: ```sudo docker image build -t pkg1 .```
* List Docker images: ```sudo docker image ls```
* Delete unwarranted image: ```TODO```
* Test run this image: ```sudo docker run -it pkg1```

#### Experiment

* Move into the ```csc7135_rosdiscover_exp/scripts``` directory: ```cd ~/Documents/csc7135_rosdiscover_exp/scripts```

* Activate ROSDiscover enviornment in az_ubunut: ```. /home/az/.local/share/virtualenvs/rosdiscover-2-DhvFio/bin/activate```

#### Experiment 1: Subscription to wrong data type

* Step 1: Derive groundtruth architecture: ```python3 observe-system.py fetch_lsu```
* Step 2: Run ROSDiscover to statically recover architecture: ```python3 recover-system.py recovery fetch_lsu```