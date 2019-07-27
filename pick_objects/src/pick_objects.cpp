#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  /*   
  ros::NodeHandle n;
  ros::Publisher goal_pub = n.advertise<geometry_msgs::Pose>("/target", 20);
  */

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = 3.0;
  goal.target_pose.pose.orientation.w = 1.0;

  // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal for pick up location");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();



  goal.target_pose.pose.orientation.z = 1.57;
  ROS_INFO("Sending command to rotate");
  ac.sendGoal(goal);
  ac.waitForResult();
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Robot arrived pick up location and rotated!");
    ros::Duration(5.0).sleep();
  }
  else{
    ROS_INFO("Robot failed to go to pick up location and rotated");
    ros::Duration(5.0).sleep();
  }


  goal.target_pose.pose.position.x = 4.0;
  goal.target_pose.pose.position.y = 4.0;
  goal.target_pose.pose.orientation.w = 1.0;

  ROS_INFO("Sending goal for drop off location");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Hooray, robot went drop off location!");
    ros::Duration(5.0).sleep();
  }
  else{
    ROS_INFO("robot failed to move to drop off loaction");
    ros::Duration(5.0).sleep();
  }

  return 0;
}
