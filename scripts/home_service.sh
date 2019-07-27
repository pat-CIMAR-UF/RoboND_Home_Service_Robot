#!/bin/sh
xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/yq/catkin_ws/src/RoboND_Home_Service_Robot/world/my_world.world " &
sleep 5
xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/yq/catkin_ws/src/RoboND_Home_Service_Robot/world/mymap.yaml " &
sleep 5
xterm -e " rosrun rviz rviz -d /home/yq/catkin_ws/src/RoboND_Home_Service_Robot/rvizConfig/navigation.rviz " &
sleep 3
xterm -e "rosrun add_markers add_markers " &
sleep 5
xterm -e "rosrun pick_objects pick_objects"
