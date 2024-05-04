### Notes on ROSDISCOVER working principle
RQ2 can be made to work for architectural bug detection by comparing the observed and recovered architecture
```
autorally,observed,"waypointFollower subscribes to an unpublished topic: '/pose_estimate'. But there is a publisher(s) {gazebo, ground_truth_republisher} that publishes a similar message type: nav_msgs/Odometry as {/ground_truth/state,/ground_truth/state_raw}. waypointFollower was launched by unknown
"
```
### Generating dataset
Two packages will be made, one tests bug 1 and the other tests a combination of all four (if possible) bugs. Each package has two launch file, one generating the ground-truth and the other generates the faulty architecture. All packages builds and throws no compiler error


### Steps to generating architectural bugs

- Step 1: Derive the ground truth by observing the running system {using the good system}
```pipenv run scripts/observe-system.py fetch_lsu```

- Step 2: 
