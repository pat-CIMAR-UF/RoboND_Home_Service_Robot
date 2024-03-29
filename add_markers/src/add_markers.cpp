#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

double pickX = 3.0;
double pickY = 0.0;
double dropX = 4.0;
double dropY = 4.0;

bool itemPickedUp = false;
bool itemDroppedOff = false;

void odomCallBack(const nav_msgs::Odometry::ConstPtr& msg){
  double robotX = msg->pose.pose.position.x;
  double roboty = msg->pose.pose.position.y;

  double distanceToPickUp = sqrt(pow(robotX - pickX, 2) + pow(roboty - pickY, 2));
  double distanceToDropOff = sqrt(pow(robotX - dropX, 2) + pow(roboty - dropY, 2));

  if (distanceToPickUp < 0.3)
    itemPickedUp = true;
  
  if (distanceToDropOff < 0.3)
    itemDroppedOff = true;
}


int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("odom", 10, odomCallBack);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  visualization_msgs::Marker marker;

  // Set the frame ID and timestamp.  See the TF tutorials for information on these.
   marker.header.frame_id = "map";
  marker.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker.  This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  marker.ns = "cube";
  marker.id = 0;

  // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
  marker.type = shape;

  // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
  marker.pose.position.x = pickX;
  marker.pose.position.y = pickY;
  marker.pose.position.z = 0;
  marker.pose.orientation.x = 0.0;
  marker.pose.orientation.y = 0.0;
  marker.pose.orientation.z = 0.0;
  marker.pose.orientation.w = 1.0;

  // Set the scale of the marker -- 1x1x1 here means 1m on a side
  marker.scale.x = 0.2;
  marker.scale.y = 0.2;
  marker.scale.z = 0.2;

  // Set the color -- be sure to set alpha to something non-zero!
  marker.color.r = 0.0f;
  marker.color.g = 0.0f;
  marker.color.b = 1.0f;
  marker.color.a = 1.0;

  marker.lifetime = ros::Duration();

  while(ros::ok()){

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    if (!itemPickedUp){
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
    }
    else if (!itemDroppedOff){
      marker.action = visualization_msgs::Marker::DELETE;
      marker_pub.publish(marker);
    }
    else{
      marker.pose.position.x = dropX;
      marker.pose.position.y = dropY;
      marker.action = visualization_msgs::Marker::ADD;
      marker_pub.publish(marker);
    }
    ros::spinOnce();
  }
}