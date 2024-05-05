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
* Delete all containers including its volume uses: ```docker rm -vf $(docker ps -aq)```
* Delete all images: ```docker rmi -f $(docker images -aq)```

* Test run this image: ```sudo docker run -it pkg1```

#### Experiment

* Move into the ```csc7135_rosdiscover_exp/scripts``` directory: ```cd ~/Documents/csc7135_rosdiscover_exp/scripts```

* Activate ROSDiscover enviornment in az_ubunutu: ```. /home/az/.local/share/virtualenvs/rosdiscover-2-DhvFio/bin/activate```

#### Experiment 1: Subscription to wrong data type

* Step 1: Derive groundtruth architecture: ```python3 observe-system.py pkg1```
* Step 2: Check the architecture against ACME rules: ```python3 check-architecture.py observed pkg1```

#### Experiment 2: Subscription to wrong data type

* Step 1: Derive groundtruth architecture: ```python3 observe-system.py pkg2```
* Step 2: Check the architecture against ACME rules: ```python3 check-architecture.py observed pkg2```

<!-- * Step 2: Run ROSDiscover to statically recover architecture: ```python3 recover-system.py recovery fetch_lsu``` -->

## Results and Observations

### Issues with the ROSDiscover

* We could not get the ```rosdiscover-cxx-recover``` does not work in Step 2 from replication_package.
* Hence, the experimental results only uses dynamic approach in recovering run time architecture
