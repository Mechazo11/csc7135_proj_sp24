## commands.md

This file contains all the commands required to running this project

* Check what version of ubuntu you are running
```lsb_release -a```

* Check version of ROS running
```echo $ROS_DISTRO```

#### ROSDiscover commands
```cd ~/Documents/rosdiscover/``` 

Activate the environment ```. /home/icore_base/.local/share/virtualenvs/rosdiscover-aYG4O-1F/bin/activate```


#### Testing node in Fetch robot
* Launch the playground for pick-and-place simulation
```roslaunch fetch_gazebo pickplace_playground.launch```

* Launch the pick and place demo
```roslaunch fetch_gazebo_demo pick_place_demo.launch```

* Activate ROSDiscover env


* Test 1: Test ROSDiscover call signature
```rosdiscover launch example/csc_7135/fetch.yml```