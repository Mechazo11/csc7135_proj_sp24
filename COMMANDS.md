## commands.md

This file contains all the commands required to running this project

* Check what version of ubuntu you are running
```lsb_release -a```

* Check version of ROS running
```echo $ROS_DISTRO```

* Launch the playground for pick-and-place simulation
```roslaunch fetch_gazebo pickplace_playground.launch```

* Launch the pick and place demo
```roslaunch fetch_gazebo_demo pick_place_demo.launch```

* Activate ROSDiscover env
```source ~/.local/share/virtualenvs/rosdiscover-UVK9ASYE/bin/activate```

* Test 1: Test ROSDiscover call signature
```rosdiscover launch example/csc_7135/fetch.yml```