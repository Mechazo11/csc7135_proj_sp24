## TODO depricate this text file

### Notes on ROSDISCOVER working principle
RQ2 can be made to work for architectural bug detection by comparing the observed and recovered architecture
```
autorally,observed,"waypointFollower subscribes to an unpublished topic: '/pose_estimate'. But there is a publisher(s) {gazebo, ground_truth_republisher} that publishes a similar message type: nav_msgs/Odometry as {/ground_truth/state,/ground_truth/state_raw}. waypointFollower was launched by unknown
"
```
