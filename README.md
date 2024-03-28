### Project Readme

## Changes from ROS Melodic build
* Changed all relevevant .py script's top-level shebang to ```#!/usr/bin/env python3```

## Preamble

* Ensure ```PYTHONPATH``` is set to the location where all packages are installed for Python 3.8 (default in Ubuntu 20.04)

* Circumvent the issue with ```setuptools > 50```

* Add these line to your .bashrc file
```export PYTHONPATH="/usr/lib/python3/dist-packages:$PYTHONPATH"```

* Intall geometry2 module ```sudo apt install ros-noetic-geometry2*```

* Intall navigation module ```sudo apt install ros-noetic-navigation```

* Install moveit module ```sudo apt install ros-noetic-moveit```

## TODO
* Add them here