# RoboND_Map_My_World
 
This the project of Udacity Robotics Software Development Nanodegree project of SLAM and Mapping. The packages used are [rtabmap_ros](http://wiki.ros.org/rtabmap_ros) and [ROS Teleop Package](https://github.com/ros-teleop/teleop_twist_keyboard).

**To review the rtabmap.db file, it is too big for github(271 MB), please use this OneDrive [link](https://uflorida-my.sharepoint.com/:u:/g/personal/wangyiqun_ufl_edu/EUbxcCs4OJBOrA978pFLavYBK5Rc41N_vap1-2NlUlknXw?e=80PlKr) to download it**



![result1](https://github.com/pat-CIMAR-UF/RoboND_Map_My_World/blob/master/img/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE(29).png)
![result2](https://github.com/pat-CIMAR-UF/RoboND_Map_My_World/blob/master/img/%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE(30).png)

On the left, you have your 2D grid map in all of its updated iterations and the path of your robot. In the middle you have different images from the mapping process. Here you can scrub through images to see all of the features from your detection algorithm. These features are in yellow. Then, what is the pink, you may ask? The pink indicates where two images have features in common and this information is being used to create neighboring links and loop closures! Finally, on the right you can see the constraint view. This is where you can identify where and how the neighboring links and loop closures were created.



# Installation

## rtabmap_ros package install:
```bash
$ sudo apt-get install ros-kinetic-rtabmap-ros
```

## ROS Teleop Package install:
```bash
$ cd (catkin_ws)/src
$ git clone https://github.com/ros-teleop/teleop_twist_keyboard.git
$ cd ..
$ catkin_make
```
Then, try to run it:
```bash
$ cd (catkin_ws)
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
If not working:
```bash
$ cd (catkin_ws)/src/teleop_twist_keyboard
$ chmod +x teleop_twist_keyboard.py
```
Then run it again.

## Project Package install:
```bash
$ cd (catkin_ws)/src
$ git clone https://github.com/pat-CIMAR-UF/RoboND_Map_My_World.git my_robot
$ cd ..
$ catkin_make
```

# To Run
To launch the robot and world package:
```bash
$ cd (caktin_ws)
$ source devel/setup.bash
$ roslaunch my_robot world.launch
```
To launch the teleop package to control the robot: Open a new terminal:
```bash
$ source devel/setup.bash
$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py
```
To launch the rtabmap_ros package:
```bash
$ source devel/setup.bash
$ roslaunch my_robot mapping.launch
```

# To check generated .db file:
**Download from [here](https://uflorida-my.sharepoint.com/:u:/g/personal/wangyiqun_ufl_edu/EUbxcCs4OJBOrA978pFLavYBK5Rc41N_vap1-2NlUlknXw?e=80PlKr)**

Copy the downloaded file to the under the folder of catkin_ws/src/my_robot/launch
Then run
```bash
$ cd (catkin_ws)
$ rtabmap-databaseViewer src/my_robot/launch/rtabmap.db
```
