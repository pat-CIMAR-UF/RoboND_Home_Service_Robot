#!/bin/sh
xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/yq/catkin_ws/src/RoboND_Home_Service_Robot/world/my_world.world " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/yq/catkin_ws/src/RoboND_Home_Service_Robot/world/mymap.yaml " &
sleep 5
xterm  -e  " roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e "rosrun add_markers add_markers"
