# RoboND_Home_Service_Robot

This is a comprehensive repository of Udacity Robotics Software Engineer Nanodegree final project. In this project, we built a package which is capable from SLAM(Simultaneous Localization And Mapping), executing navigation goal and pick up/drop off objects. 

This repository is tested and successfully built under Ubuntu 16.04 and ROS Kinetic, with Gazebo 7.15 integration. 

<p align="center">
    <img src="image/demo2.gif" width="800px" alt=""/>
</p>

A better mp4 file could be downloaded [here](https://github.com/pat-CIMAR-UF/RoboND_Home_Service_Robot/blob/master/image/demo.mp4). It's smaller than this gif and clearer.
# Install

```bash
$ pip install catkin_pkg
$ pip install rospkg
$ sudo apt-get install python-rospkg
$ cd catkin_ws/src
$ catkin_init_workspace
$ git clone --recursive https://github.com/pat-CIMAR-UF/RoboND_Home_Service_Robot.git
$ cd ..
$ catkin_make
```

Official ROS pkgs:

[slam_gmapping](https://github.com/ros-perception/slam_gmapping.git)

[turtlebot](https://github.com/turtlebot/turtlebot.git)

[turtlebot_interactions](https://github.com/turtlebot/turtlebot_interactions.git)

[turtlebot_simulator](https://github.com/turtlebot/turtlebot_simulator.git)

# Test

### For SLAM testing:
```bash
$ cd catkin_ws/src/RoboND_Home_Service_Robot/scripts
$ chmod +x test_slam.sh
$ ./test_slam.sh
```
Then find the teleop terminal and control the robot as prompted.

### For Localization and Navigation Testing:
```bash
$ cd catkin_ws/src/RoboND_Home_Service_Robot/scripts
$ chmod +x test_navigation.sh
$ ./test_navigation.sh
```
Then select the "2D Nav Goal" tab from rviz to give the robot an goal location.

### For Pickup/Dropoff and Virtual Object Testing:
```bash
$ cd catkin_ws/src/RoboND_Home_Service_Robot/scripts
$ chmod +x home_service.sh
$ ./home_service.sh
```
**The first run of this shell code may not success, because the turtlebot_interaction package was recursively cloned from its own github, and it doesn't contain a marker topic in its rviz launch file.**

**It is simple to solve:**

+ Add a marker topic in rviz, leave the default "visualization_marker" topic as it is
+ Save Config
+ Close everything: rviz, gazebo, all the nodes initiated by the shell script
+ relaunch the shell script `./home_service.sh`

# Result

Comments about the gif above. 

When initiated, the red sparse particles are created by the [Adaptive Monte Carlo Localization](http://wiki.ros.org/amcl) package. The sparse distribution means the AMCL is very uncertain about the the exact location of the robot. 

The blue square is the virtual object the robot is supposed to pick up. As one can see, the red sparse particles didn't converge while the robot is moving towards the pick up location. The AMCL package cannot localize the robot well because of the lack of clear landmarks/features on the way.

When the robot reached the pick-up location, it rotated itself first for a better trajectory later. 

When robot moving to the drop-off location, the red AMCL particles converged, because of sufficient good landmarks/features.

The robot reached the planned pick-up and drop-off locations, the xterm terminal reported every step, and the virtual objects appeared and disappeared as planned, so this project could be concluded as a success.



